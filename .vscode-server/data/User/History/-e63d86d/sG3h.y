
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h> 
    #define MAX_PARAMS 10

    
    int yylex();
    int yyerror(const char *s);
    extern int yylineno;  
    extern char* yytext; 
    /* === helpers for type checking (added) === */
    int  isInt   (const char* t);
    int  isReal  (const char* t);
    int  isBool  (const char* t);
    int  isChar  (const char* t);
    int  isStr   (const char* t);
    int  isNumeric(const char* t);
    int  samePtrType(const char* a,const char* b);
    int paramOrderIdx = 0;   
    
    /* AST node */
    typedef struct node {
        char* token;  
        struct node* left;   
        struct node* right; 
    } node;

    node* ASTRoot = NULL;
    node *mknode(char* token, node* left, node* right);
    void printTree(node* tree, int level);

    typedef enum { FUNC, VAR } SymbolType;

    typedef struct Symbol {
        char* name;
        SymbolType type;
        char* returnType;
        int paramCount;
        char* scope;
        int scopeDepth; 
        char* paramTypes[MAX_PARAMS];
        struct Symbol* next;
    } Symbol;

    Symbol* symbolTable = NULL;

    int insertSymbol(char* name, SymbolType type, char* returnType, int paramCount, const char* scope, char* paramTypes[]);
    Symbol* lookupSymbol(char* name);
    void freeSymbolTable();
    int getParamCount(node* paramList);
    int moreThanOneMain(char* name);
    int isMainExists();
    int isVarDeclaredInScope(const char* name);
    void pushScope();
    void popScope();
    char* inferExprType(node* expr);
    int validateReturnType(node* body, const char* expectedType);
    int isPointerType(const char* type);
    int registerParams(node* plist);
    
    int mainDeclared = 0;
    int scopeDepth = 0;
    node* g_lastParamList = NULL;   /* used by scope_marker */


%}

%union {
    int  intVal;
    float realVal;
    char  charVal;
    char* stringVal;
    struct node* nodePtr;
}

%token <intVal> INT_LIT
%token <realVal> REAL_LIT
%token <charVal> CHAR_LIT
%token <stringVal> STRING_LIT IDENT

%token BOOL CHAR INT REAL STRING TYPE
%token INTPTR CHARPTR REALPTR  
%token IF ELIF ELSE WHILE FOR DO VARIABLE
%token <intVal> PAR
%token RETURN RETURNS NULLL
%token T_BEGIN END
%token DEF CALL
%token AND NOT OR
%token EQL NOTEQL GREATEREQL LESSEQL GREATER LESS
%token ASSIGN PLUS MINUS MULTI DIV ADDRESS LENGTH
%token TRUE FALSE

%left  OR
%left  AND
%left  EQL NOTEQL
%left  GREATEREQL LESSEQL GREATER LESS
%left  PLUS MINUS
%left  MULTI DIV
%right NOT
%right ADDRESS
%nonassoc LENGTH_ABS

%type <nodePtr> code functions function params param_list params_reset
%type <nodePtr> param var dec_list dec type literal
%type <nodePtr> ident_entry idents_list
%type <nodePtr> statements state assign_state
%type <nodePtr> if_state while_state do_while_state
%type <nodePtr> for_state for_h advance_exp condition
%type <nodePtr> bl_state rt_state func_call_state
%type <nodePtr> func_call exp_list expression
%type <nodePtr> params_saved


%%
/* ----------------------------  Root Rule  -------------------------------*/
code :
    functions {
        ASTRoot = mknode("CODE", $1, NULL);
    }
;


/* --------------------------- Functions list -----------------------------*/
functions :
      function functions                   { $$ = mknode("FUNCS",$1,$2); }
    |  function                              { $$ = $1; }
    ;

/* ------------------------ Single function rule -------------------------*/
scope_marker :
      { pushScope();
        if (registerParams(g_lastParamList)) YYABORT;
      };
params_saved : params                
      {
        g_lastParamList = $1;   /* side-effect */
        $$ = $1;               /* so callers still get the list */
      }
    ;
function :
    DEF IDENT '(' params_saved ')' ':' RETURNS type var scope_marker T_BEGIN statements END
    {
        if (moreThanOneMain($2)) YYABORT;

        if (strcmp($2, "_main_") == 0) {
            if ($4 != NULL) {
                yyerror("Semantic Error: '_main_' function must not take parameters.");
                YYABORT;
            }
            if (strcmp($8->token, "void") != 0) {
                yyerror("Semantic Error: '_main_' function must not return a value.");
                YYABORT;
            }
        }

        char* paramTypes[MAX_PARAMS];
        int paramCount = 0;
        node* curParam = $4;

        while (curParam && paramCount < MAX_PARAMS) {
            if (strcmp(curParam->token, "PARAMS") == 0) {
                node* single = curParam->left;
                if (single && strcmp(single->token, "PARAM") == 0 && single->left) {
                    char* rawType = single->left->token;
                    char* lowered = strdup(rawType);
                    for (char* p = lowered; *p; p++) *p = tolower(*p);
                    paramTypes[paramCount++] = lowered;
                }
                curParam = curParam->right;
            } else if (strcmp(curParam->token, "PARAM") == 0) {
                char* rawType = curParam->left->token;
                char* lowered = strdup(rawType);
                for (char* p = lowered; *p; p++) *p = tolower(*p);
                paramTypes[paramCount++] = lowered;
                break;
            } else {
                break;
            }
        }

        char* returnType = strdup($8->token);
        for (char* p = returnType; *p; p++) *p = tolower(*p);

        if (strcmp(returnType, "string") == 0) 
        {
        yyerror("Semantic Error: Functions cannot return type 'string'.");
        YYABORT;
        }

        // Rule 9 check: return statements must match declared return type
        if (!validateReturnType($12, returnType)) 
        {
            YYABORT;
        }

        if (insertSymbol($2, FUNC, returnType, paramCount, "global", paramTypes)) 
        {
            yyerror("Semantic Error: Function already declared in the same scope.");
            YYABORT;
        }

        node* idN = mknode($2, NULL, NULL);
        node* paramsN = mknode("PARAMS", $4, NULL);
        node* returnsN = mknode("RETURNS", $8, NULL);
        node* bodyN = mknode("BODY", $9, $12);  // $9 = var, $12 = statements
        node* defBodyN = mknode("DEF_BODY", returnsN, bodyN);
        popScope();
        $$ = mknode("FUNCTION", idN, mknode("FUNC_IN", paramsN, defBodyN));
    }

  | DEF IDENT '(' params_saved ')' ':' var scope_marker T_BEGIN statements END
    {
        if (moreThanOneMain($2)) YYABORT;

        if (strcmp($2, "_main_") == 0) {
            if ($4 != NULL) {
                yyerror("Semantic Error: '_main_' function must not take parameters.");
                YYABORT;
            }
        }

        char* paramTypes[MAX_PARAMS];
        int paramCount = 0;
        node* curParam = $4;

        while (curParam && paramCount < MAX_PARAMS) {
            if (strcmp(curParam->token, "PARAMS") == 0) {
                node* single = curParam->left;
                if (single && strcmp(single->token, "PARAM") == 0 && single->left) {
                    char* rawType = single->left->token;
                    char* lowered = strdup(rawType);
                    for (char* p = lowered; *p; p++) *p = tolower(*p);
                    paramTypes[paramCount++] = lowered;
                }
                curParam = curParam->right;
            } else if (strcmp(curParam->token, "PARAM") == 0) {
                char* rawType = curParam->left->token;
                char* lowered = strdup(rawType);
                for (char* p = lowered; *p; p++) *p = tolower(*p);
                paramTypes[paramCount++] = lowered;
                break;
            } else {
                break;
            }
        }

        char* returnType = strdup("void");

        if (insertSymbol($2, FUNC, returnType, paramCount, "global", paramTypes)) {
            yyerror("Semantic Error: Function already declared in the same scope.");
            YYABORT;
        }

        node* idN = mknode($2, NULL, NULL);
        node* paramsN = mknode("PARAMS", $4, NULL);
        node* bodyN = mknode("BODY", $7, $10);  // $7 = var, $10 = statements
        popScope();
        $$ = mknode("PROC", idN, mknode("PROC_IN", paramsN, bodyN));
    }
;


/* --------------------- param declarations ---------------------------*/
/* --------------------------------------------------
   params_reset  – אפס את המונה לפני שמתחילים לספור
---------------------------------------------------*/
params_reset
    : /* empty */           { paramOrderIdx = 0; }
    ;

/* -----------------------------------------------
   params        – רשימת פרמטרים (או ריק)
-----------------------------------------------*/
params
    : /* אין פרמטרים */     { $$ = NULL; }            /* def foo() … */
    | params_reset param_list { $$ = $2; }             /* def foo(par1 …) */
    ;

param_list :
    param                           { $$ = $1; }
    | param ';' param_list        { $$ = mknode("PARAMS",$1,$3); }
    ;

param :
        PAR type ':' IDENT
        {
            /* ---- בדיקת סדר par ---- */
            if ($1 != paramOrderIdx + 1) {
                yyerror("Semantic Error: parameters must be in sequential order (par1, par2, …).");
                YYABORT;
            }
            paramOrderIdx = $1;

            $$ = mknode("PARAM", $2, mknode($4, NULL, NULL));
        }
;


/* -----------------------  type (atomic) ---------------------------------*/
type : 
      INT         { $$ = mknode("INT",NULL,NULL);  }
    | CHAR        { $$ = mknode("CHAR",NULL,NULL); }
    | BOOL        { $$ = mknode("BOOL",NULL,NULL); }
    | STRING      { $$ = mknode("STRING",NULL,NULL);}
    | REAL        { $$ = mknode("REAL",NULL,NULL); }
    | CHARPTR     { $$ = mknode("CHARPTR",NULL,NULL);}
    | INTPTR      { $$ = mknode("INTPTR",NULL,NULL);}
    | REALPTR     { $$ = mknode("REALPTR",NULL,NULL);}
    ;

/* ------------ id-list helpers -------------------------------------*/
ident_entry
    : IDENT ':' literal
        { $$ = mknode("VAR_ASSIGN",
                      mknode("IDENT", mknode($1,NULL,NULL), NULL),
                      $3); }
    | IDENT
        { $$ = mknode("VAR_DECL",
                      mknode("IDENT", mknode($1,NULL,NULL), NULL),
                      NULL); }
    | IDENT '[' INT_LIT ']'
        { char buf[32]; sprintf(buf, "%d", $3);
          $$ = mknode("ARRAY_DECL",
                      mknode("IDENT", mknode($1,NULL,NULL), NULL),
                      mknode(buf, NULL, NULL)); }
    | IDENT '[' INT_LIT ']' ':' STRING_LIT
        { char buf[32]; sprintf(buf, "%d", $3);
          $$ = mknode("ARRAY_INIT",
                      mknode("ARRAY_DECL",
                             mknode("IDENT", mknode($1,NULL,NULL), NULL),
                             mknode(buf, NULL, NULL)),
                      mknode($6, NULL, NULL)); }
    ;

idents_list
    : ident_entry
        { $$ = $1; }
    | ident_entry ',' idents_list
        { $$ = mknode("ID_LIST", $1, $3); }
    ;


literal :
          INT_LIT      { char ibuf[32]; sprintf(ibuf,"%d",$1); $$ = mknode("INT", mknode(ibuf,NULL,NULL), NULL); }
        | TRUE         { $$ = mknode("BOOL", mknode("true", NULL, NULL), NULL); }
        | FALSE        { $$ = mknode("BOOL", mknode("false", NULL, NULL), NULL); }
        | CHAR_LIT     { char cbuf[2] = {$1,'\0'}; $$ = mknode("CHAR", mknode(cbuf,NULL,NULL), NULL); }
        | STRING_LIT   { $$ = mknode("STRING", mknode($1, NULL, NULL), NULL); }
        | REAL_LIT     { char r[64]; sprintf(r,"%f",$1);
                        $$ = mknode("REAL", mknode(r,NULL,NULL), NULL); }
        | NULLL        { $$ = mknode("NULL", NULL, NULL); }
        ;

/* -------------------  Local‑var block  ----------------------------------*/
var :                                     
    { $$ = NULL; }
    | VARIABLE dec_list                { $$ = mknode("VAR",$2,NULL); }
    ;

dec_list : 
    dec                        { $$ = $1; }
    | dec dec_list        { $$ = mknode("DECS",$1,$2); }
    ;


dec :
     TYPE type ':' idents_list ';'
       {  /* ----- identical semantic loop, but walk ID_LIST chain ----- */
           node* decl = $4;
           while (decl) {
               node* single = (strcmp(decl->token,"ID_LIST")==0)
                              ? decl->left : decl;

               if (single && (strcmp(single->token,"VAR_DECL"  )==0 ||
                              strcmp(single->token,"VAR_ASSIGN")==0 ||
                              strcmp(single->token,"ARRAY_DECL")==0 ||
                              strcmp(single->token,"ARRAY_INIT")==0))
               {
                   node* idNode = single->left;
                   if (idNode && strcmp(idNode->token,"IDENT")==0 && idNode->left) {
                       char* vname = idNode->left->token;
                       if (insertSymbol(vname, VAR, $2->token, 0, "block", NULL)) {
                           yyerror("Semantic Error: Variable already declared in this scope.");
                           YYABORT;
                       }
                   }
               }
               decl = (strcmp(decl->token,"ID_LIST")==0) ? decl->right : NULL;
           }
           $$ = mknode("DECL", $2, $4);
       }


/* ------------------------- Statements seq. ------------------------------*/
statements :
     {$$ = mknode("", NULL,NULL);}
            | state {$$ = $1;}
            | state statements {$$ = mknode("statements", $1, $2);}
            ;


/* --------------------------- Single statement ---------------------------*/
state :
            function {$$=$1;}
            | assign_state {$$ = $1;}
            | if_state {$$ = $1;}
            | while_state {$$ = $1;}
            | for_state {$$ = $1;}
            | do_while_state {$$ = $1;}
            | bl_state {$$ = $1;}
            | rt_state {$$ = $1;}
            | func_call_state {$$ = $1;}
            | expression ';' { $$ = $1; }

        ;
/* ------------------------- Assignment variants --------------------------*/
assign_state
    /* 14‑A  —  x = expr ;  (types must match) */
  : IDENT ASSIGN expression ';'
    {
        Symbol* lvar = lookupSymbol($1);          /* LHS variable */
        if (!lvar) {
            char msg[128];
            sprintf(msg,
                    "Semantic Error: Variable '%s' used before declaration.", $1);
            yyerror(msg);
            YYABORT;
        }

        char* lhsType = strdup(lvar->returnType); // normalize lhs type too
        for (char* p = lhsType; *p; ++p) *p = tolower(*p);
        char* rhsTypeA = inferExprType($3);

        if (strcmp(lhsType, rhsTypeA) != 0) {
            char msg[256];
            sprintf(msg,
                    "Semantic Error: Cannot assign type '%s' to variable '%s' of type '%s'.",
                    rhsTypeA, $1, lhsType);
            yyerror(msg);
            YYABORT;
        }

        $$ = mknode("assign", mknode($1, NULL, NULL), $3);
    }

    /* 14‑B  —  s[i] = char‑literal or expression‑of‑type‑char */
  | IDENT '[' expression ']' ASSIGN CHAR_LIT ';'
    {
        Symbol* var = lookupSymbol($1);
        if (!var || strcasecmp(var->returnType, "string") != 0) {
            yyerror("Semantic Error: Only string variables support indexing with [].");
            YYABORT;
        }
        char buf[2] = { $6 , '\0'};
        $$ = mknode("array_assign",
                    mknode($1, $3, NULL),
                    mknode("CHAR", mknode(buf,NULL,NULL), NULL));
    }

  | IDENT '[' expression ']' ASSIGN expression ';'
    {
        Symbol* var = lookupSymbol($1);
        if (!var || strcasecmp(var->returnType, "string") != 0) {
            yyerror("Semantic Error: Only string variables support indexing with [].");
            YYABORT;
        }
        char* rhsTypeB = inferExprType($6);
        if (strcmp(rhsTypeB, "char") != 0) {
            yyerror("Semantic Error: String cells can only hold characters.");
            YYABORT;
        }
        $$ = mknode("array_assign", mknode($1, $3, NULL), $6);
    }

    /* 14‑C  —  x = null ;   (LHS must be a pointer) */
    | IDENT ASSIGN NULLL ';'
    {
        Symbol* var = lookupSymbol($1);
        if (!var) {
    yyerror("Semantic Error: Variable used before declaration.");
    YYABORT;
    }

    char* lhsType = strdup(var->returnType);
    for (char* p = lhsType; *p; ++p) *p = tolower(*p);

    if (!isPointerType(lhsType)) 
    {
        yyerror("Semantic Error: Only pointer variables can be assigned null.");
        YYABORT;
    }
        $$ = mknode("null_assign",
                    mknode($1, NULL, NULL),
                    mknode("NULL", NULL, NULL));
    }
    ;


/* -----------------------------  IF / ELIF / ELSE ------------------------*/
if_state :
    IF expression ':' bl_state
    {
        if (strcmp(inferExprType($2), "bool") != 0) {
            yyerror("Semantic Error: IF condition must be of type 'bool'.");
            YYABORT;
        }
        $$ = mknode("if", $2, $4);
    }

  | IF expression ':' bl_state ELSE ':' bl_state
    {
        if (strcmp(inferExprType($2), "bool") != 0) {
            yyerror("Semantic Error: IF condition must be of type 'bool'.");
            YYABORT;
        }
        $$ = mknode("if_else", $2, mknode("then", $4, mknode("else", $7, NULL)));
    }

  | IF expression ':' bl_state ELIF expression ':' bl_state
    {
        if (strcmp(inferExprType($2), "bool") != 0 || strcmp(inferExprType($6), "bool") != 0) {
            yyerror("Semantic Error: IF and ELIF conditions must be of type 'bool'.");
            YYABORT;
        }
        $$ = mknode("if_elif", $2, mknode("then", $4, mknode("elif", $6, $8)));
    }

  | IF expression ':' bl_state ELIF expression ':' bl_state ELSE ':' bl_state
    {
        if (strcmp(inferExprType($2), "bool") != 0 || strcmp(inferExprType($6), "bool") != 0) {
            yyerror("Semantic Error: IF and ELIF conditions must be of type 'bool'.");
            YYABORT;
        }
        $$ = mknode("if_elif-else", $2, mknode("then", $4, mknode("elif", $6, mknode("elif-then", $8, mknode("else", $11, NULL)))));
    };

/* -----------------------------  WHILE loop ------------------------------*/
while_state :
    WHILE expression ':' bl_state
    {
        if (strcmp(inferExprType($2), "bool") != 0) {
            yyerror("Semantic Error: WHILE condition must be of type 'bool'.");
            YYABORT;
        }
        $$ = mknode("while", $2, $4);
    };
/* ---------------------------  DO‑WHILE loop -----------------------------*/
do_while_state :
    DO ':' bl_state WHILE expression ';'
    {
        if (strcmp(inferExprType($5), "bool") != 0) {
            yyerror("Semantic Error: DO-WHILE condition must be of type 'bool'.");
            YYABORT;
        }
        $$ = mknode("do_while", $3, mknode("condition", $5, NULL));
    };

/* -----------------------------  FOR loop --------------------------------*/
for_state :
     FOR for_h ':' bl_state            {
          $$ = mknode("for",$2,$4); }
    | FOR for_h ':' var bl_state        {
          $$ = mknode("for",$2,
                      mknode("block",$5,$4)); }
    ;

for_h :
    '(' IDENT ASSIGN expression ';'
         expression ';'
         advance_exp ')'
    {
        if (strcmp(inferExprType($6), "bool") != 0) {
            yyerror("Semantic Error: FOR condition must be of type 'bool'.");
            YYABORT;
        }
        $$ = mknode("for_header",
                    mknode("init", mknode($2, NULL, NULL), $4),
                    mknode("loop", $6, $8));
    };


advance_exp :
     IDENT ASSIGN expression                 {
          $$ = mknode("update",
                      mknode($1,NULL,NULL),$3); }
    ;

/* -----------------------  Boolean condition helper ----------------------*/
condition :
     expression                                   { $$ = $1; }
    | NOT condition                                { $$ = mknode("not",$2,NULL); }
    | '(' condition ')'                            { $$ = $2; }
    | TRUE                                         { $$ = mknode("true",NULL,NULL); }
    | FALSE                                        { $$ = mknode("false",NULL,NULL); }
    ;

/* -----------------------------  Return  ---------------------------------*/
rt_state :
    RETURN expression ';'                        { $$ = mknode("return",$2,NULL); }
    ;

/* --------------------  BEGIN … END compound‑statement -------------------*/
bl_state :
    T_BEGIN { pushScope(); } statements END { popScope(); $$ = mknode("block", $3, NULL); }
  | var T_BEGIN { pushScope(); } statements END { popScope(); $$ = mknode("block", $4, $1); }




/* -------------------------  Function‑call stmt --------------------------*/
func_call_state :
     func_call ';'                            { $$ = $1; }
    | IDENT ASSIGN func_call ';'          {
          $$ = mknode("assign",
                      mknode($1,NULL,NULL),$3); }
    ;

/* -------------------------  Function call expr --------------------------*/
func_call :
      CALL IDENT '(' ')' {
          Symbol* f = lookupSymbol($2);
          if (!f || f->type != FUNC) {
              yyerror("Semantic Error: Function called before definition.");
              YYABORT;
          }
          $$ = mknode("call", mknode($2,NULL,NULL), NULL);
      }

    | CALL IDENT '(' exp_list ')' {
    Symbol* f = lookupSymbol($2);
    if (!f || f->type != FUNC) {
        yyerror("Semantic Error: Function called before definition.");
        YYABORT;
    }

    // Count actual parameters
    int actualCount = 1;
    node* temp = $4;
    while (temp && strcmp(temp->token, "exp_list") == 0) {
        actualCount++;
        temp = temp->right;
    }

    if (actualCount != f->paramCount) {
        char msg[128];
        sprintf(msg, "Semantic Error: Function '%s' expects %d arguments but got %d.", f->name, f->paramCount, actualCount);
        yyerror(msg);
        YYABORT;
    }

    // Rule 8: Type check each parameter
    temp = $4;
    int index = 0;
    while (temp && index < f->paramCount) {
        node* exprNode = (strcmp(temp->token, "exp_list") == 0) ? temp->left : temp;
        char* actualType = inferExprType(exprNode);
        char* expectedType = f->paramTypes[index];

        if (strcmp(actualType, expectedType) != 0) {
            char msg[256];
            sprintf(msg, "Semantic Error: Argument %d in call to '%s' has type '%s' but expected '%s'.",
                    index + 1, f->name, actualType, expectedType);
            yyerror(msg);
            YYABORT;
        }

        temp = (strcmp(temp->token, "exp_list") == 0) ? temp->right : NULL;
        index++;
    }

    $$ = mknode("call", mknode($2,NULL,NULL), $4);
}


/* --------------------------  Expression list ----------------------------*/
exp_list :
      expression                                   { $$ = $1; }
    | expression ',' exp_list                     { $$ = mknode("exp_list",$1,$3); }
    ;

/* ---------------------------  Expressions  ------------------------------*/
expression :
    /* ---- primary ----*/
    INT_LIT {
    $$ = mknode(strdup("INT"), NULL, NULL);
    }
    | REAL_LIT {
        $$ = mknode(strdup("REAL"), NULL, NULL);
    }
    | CHAR_LIT {
        $$ = mknode(strdup("CHAR"), NULL, NULL);
    }
    | STRING_LIT {
        $$ = mknode(strdup("STRING"), NULL, NULL);
    }

    | IDENT {
        if (!isVarDeclaredInScope($1)) {
            char msg[128];
            sprintf(msg, "Semantic Error: Variable '%s' used before declaration.", $1);
            yyerror(msg);
            YYABORT;
        }
        $$ = mknode($1,NULL,NULL);
    }

    /* ---- arithmetic / logical binary ----*/
    | expression PLUS   expression  { $$ = mknode("+",$1,$3); }
    | expression MINUS  expression  { $$ = mknode("-",$1,$3); }
    | expression MULTI   expression  { $$ = mknode("*",$1,$3); }
    | expression DIV    expression  { $$ = mknode("/",$1,$3); }

    /* ---- unary ----*/
    | MINUS     expression          { $$ = mknode("unary-",$2,NULL); }
    | ADDRESS expression
    {
        /* בדיקת חוק ה-& בזמן הבנייה */
        char* baseType = inferExprType($2);

        if (isInt(baseType))      { /* מותר – int -> intptr   */ }
        else if (isReal(baseType)){ /* מותר – real -> realptr */ }
        else if (isChar(baseType)){ /* מותר – char -> charptr */ }
        else {
            yyerror("Semantic Error: '&' operator allowed only on int, real, char or string[i].");
            YYABORT;
        }

        /* אם הגענו לכאן – מותר, בנה את הצומת רגיל */
        $$ = mknode("&", $2, NULL);
    }    | NOT expression              { $$ = mknode("not", $2, NULL); }
    /* --- *IDENT  ----------------------------------------*/
    | MULTI IDENT
    {
        Symbol* v = lookupSymbol($2);
        if (!v){
            yyerror("Semantic Error: Variable used before declaration.");
            YYABORT;
        }
        char* t = v->returnType;
        for(char*p=t;*p;++p)*p=tolower(*p);

        if (!isPointerType(t)){
            yyerror("Semantic Error: '*' operator can only be applied to pointers.");
            YYABORT;
        }
        $$ = mknode("deref", mknode($2,NULL,NULL), NULL);
    }

    /* --- *expr  -----------------------------------------*/
    | MULTI expression
    {
        char* t = inferExprType($2);

        if (!isPointerType(t)){
            yyerror("Semantic Error: '*' operator can only be applied to pointers.");
            YYABORT;
        }
        $$ = mknode("unary*", $2, NULL);
    }


    /* ---- grouping ----*/
    | '(' expression ')'            { $$ = $2; }
    | LENGTH expression LENGTH    %prec LENGTH_ABS
                                  { $$ = mknode("|", $2, NULL); }


    /* ---- comparison ----*/
    | expression EQL expression      { $$ = mknode("==",$1,$3); }
    | expression NOTEQL expression      { $$ = mknode("!=",$1,$3); }
    | expression GREATEREQL expression      { $$ = mknode(">=",$1,$3); }
    | expression LESSEQL expression      { $$ = mknode("<=",$1,$3); }
    | expression GREATER expression      { $$ = mknode(">", $1,$3); }
    | expression LESS expression      { $$ = mknode("<", $1,$3); }

     /* ---- array index ----*/

    | IDENT '[' expression ']' {
    if (!isVarDeclaredInScope($1)) {
        char msg[128];
        sprintf(msg, "Semantic Error: Variable '%s' used before declaration.", $1);
        yyerror(msg);
        YYABORT;
    }

    // Rule 12: index must be of type int
    char* indexType = inferExprType($3);
    if (strcmp(indexType, "int") != 0) {
        yyerror("Semantic Error: Index expression must be of type 'int'.");
        YYABORT;
    }

    // Rule 13: only string can be indexed
    Symbol* varSym = lookupSymbol($1);
    if (!varSym || varSym->type != VAR || strcasecmp(varSym->returnType, "string") != 0) {
        yyerror("Semantic Error: Only variables of type 'string' can be indexed using '[]'.");
        YYABORT;
    }

    $$ = mknode("index", mknode($1, NULL, NULL), $3);
}

    /* ---- logical ----*/
    | expression AND expression     { $$ = mknode("and",$1,$3); }
    | expression OR  expression     { $$ = mknode("or",$1,$3); }

    | TRUE               { $$ = mknode("BOOL", mknode("TRUE", NULL, NULL), NULL); }
    | FALSE              { $$ = mknode("BOOL", mknode("FALSE", NULL, NULL), NULL); }
    | LENGTH IDENT LENGTH  %prec LENGTH_ABS
                         { $$ = mknode("length", mknode($2,NULL,NULL), NULL); }

    /* ---- nested call ----*/
    | func_call                 { $$ = $1; }
    ;
%%  /* ===================  C‑code section ================================*/

#include "lex.yy.c"

/* ---------- helpers for type checking (added) ---------- */
int  isInt   (const char* t){ return strcasecmp(t,"int"  )==0; }
int  isReal  (const char* t){ return strcasecmp(t,"real" )==0; }
int  isBool  (const char* t){ return strcasecmp(t,"bool" )==0; }
int  isChar  (const char* t){ return strcasecmp(t,"char" )==0; }
int  isStr   (const char* t){ return strcasecmp(t,"string")==0; }

int  isNumeric(const char* t){ return isInt(t)||isReal(t); }

int  samePtrType(const char* a,const char* b){
    /* שם-טיפוס מצביע אצלך הוא תמיד xxxptr */
    return (isPointerType(a)&&isPointerType(b)&&strcasecmp(a,b)==0);
}

/* ----------------------------  main  ------------------------------------*/
int main(void)
{
    yyparse();

    if (isMainExists()) return 1; 

    printTree(ASTRoot, 0);  

    return 0;
}


/* ----------------------  AST helper functions ---------------------------*/
 node *mknode(char *token, node *left, node *right)
{
    node *n = (node*)malloc(sizeof(node));
    if (!n) { fprintf(stderr,"alloc node failed\n"); exit(1); }

    n->token = strdup(token);  /* deep‑copy string */
    n->left  = left;
    n->right = right;
    return n;
}

 void printTabs(int indent) {
    for (int i = 0; i < indent; i++) {
        printf("  ");
    }
}


void printTree(node *t, int indent) {
    if (!t) return;

    const char *tok = t->token;
    if (strcmp(tok, "FUNCTION") == 0 || strcmp(tok, "PROC") == 0) tok = "FUNC";
    else if (strcmp(tok, "RETURNS") == 0) tok = "RET";
    else if (strcmp(tok, "RETURN") == 0) tok = "RETURN";

    printTabs(indent);
    printf("(%s", tok);

    for (node *c = t->left; c; c = c->right) {
        printf("\n");
        printTree(c, indent + 1);
    }

    printf(")\n");
}
/* -------------------------  error handler -------------------------------*/
int yyerror(const char *s)
{
    fprintf(stderr,"Error: %s at line %d near '%s'\n",
            s, yylineno, yytext);
    return 0;
}


/* -------------------------  Sybol Table Funcntions -------------------------------*/

int insertSymbol(char* name, SymbolType type, char* returnType, int paramCount, const char* scope, char* paramTypes[]) {
    Symbol* current = symbolTable;
    while (current != NULL) {
        // Only disallow redefinition in the same scope depth
        if (strcmp(current->name, name) == 0 && current->scopeDepth == scopeDepth) {
            return 1;
        }
        current = current->next;
    }

    Symbol* newSym = (Symbol*)malloc(sizeof(Symbol));
    newSym->name = strdup(name);
    newSym->type = type;
    newSym->returnType = returnType ? strdup(returnType) : NULL;
    newSym->paramCount = paramCount;
     for (int i = 0; i < paramCount; i++) {
        newSym->paramTypes[i] = strdup(paramTypes[i]);
    }
    newSym->scope = strdup(scope);
    newSym->scopeDepth = scopeDepth;
    newSym->next = symbolTable;
    symbolTable = newSym;

    return 0;
}

Symbol* lookupSymbol(char* name) {
    Symbol* current = symbolTable;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void freeSymbolTable() {
    Symbol* current = symbolTable;
    while (current != NULL) {
        Symbol* temp = current;
        current = current->next;
        free(temp->name);
        if (temp->returnType) free(temp->returnType);
        free(temp);
    }
    symbolTable = NULL;
}

int getParamCount(node* paramList) {
    int count = 0;
    node* current = paramList;
    while (current) {
        count++;
        current = current->right;
    }
    return count;
}


/* -------------------------  Semantic funcntions -------------------------------*/

int moreThanOneMain(char* name) {
    if (strcmp(name, "_main_") == 0) {
        if (mainDeclared) {
            yyerror("Semantic Error: Multiple declarations of '_main_' function.");
            return 1;  // signal failure
        } else {
            mainDeclared = 1;
        }
    }
    return 0;  // success
}


int isMainExists() {
    if (!mainDeclared) {
        fprintf(stderr, "Semantic Error: Missing '_main_' function.\n");
        return 1;
    }
    return 0;
}

void pushScope() {
    scopeDepth++;
}

void popScope() {
    Symbol** current = &symbolTable;
    while (*current != NULL) {
        if ((*current)->scopeDepth == scopeDepth) {
            Symbol* toDelete = *current;
            *current = (*current)->next;
            free(toDelete->name);
            if (toDelete->returnType) free(toDelete->returnType);
            free(toDelete);
        } else {
            current = &((*current)->next);
        }
    }
    scopeDepth--;
}

int isVarDeclaredInScope(const char* name) {
    Symbol* current = symbolTable;
    while (current != NULL) {
        if (current->type == VAR && strcmp(current->name, name) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

char* inferExprType(node* expr) 
{
    if (!expr) {
        printf("inferExprType: ERROR - received NULL expr\n");
        return "unknown";
    }

    if (!expr->token) {
        printf("inferExprType: ERROR - expr has NULL token\n");
        return "unknown";
    }

    // Direct literal types based on AST node labels
    if (strcmp(expr->token,"INT"   )==0) return "int";
    if (strcmp(expr->token,"REAL"  )==0) return "real";
    if (strcmp(expr->token,"CHAR"  )==0) return "char";
    if (strcmp(expr->token,"STRING")==0) return "string";
    if (strcmp(expr->token,"BOOL"  )==0) return "bool";
    if (strcmp(expr->token,"NULL"  )==0) return "null";
    if (strcmp(expr->token,"TRUE")==0 || strcmp(expr->token,"FALSE")==0)
    return "bool";

    Symbol* sym = lookupSymbol(expr->token);
    if (sym && sym->type==VAR && sym->returnType){
        char* norm=strdup(sym->returnType);
        for(char*p=norm;*p;++p)*p=tolower(*p);
        return norm;
    }

    /* ------------ אופרטורים בינאריים / יונריים ------------- */
    char* lt = expr->left  ? inferExprType(expr->left ) : NULL;
    char* rt = expr->right ? inferExprType(expr->right) : NULL;

    /* + - * / */
    if (strcmp(expr->token,"+")==0||
        strcmp(expr->token,"-")==0||
        strcmp(expr->token,"*")==0||
        strcmp(expr->token,"/")==0){
        if (!isNumeric(lt)||!isNumeric(rt)){
            yyerror("Semantic Error: arithmetic operators require int/real.");
            return "unknown";
        }
        return (isInt(lt)&&isInt(rt)) ? "int" : "real";
    }

    /* && || */
    if (strcmp(expr->token,"and")==0||strcmp(expr->token,"or")==0){
        if (!isBool(lt)||!isBool(rt)){
            yyerror("Semantic Error: logical operators require bool.");
            return "unknown";
        }
        return "bool";
    }

    /* > < >= <= */
    if (strcmp(expr->token,">")==0||strcmp(expr->token,"<")==0||
        strcmp(expr->token,">=")==0||strcmp(expr->token,"<=")==0){
        if (!isNumeric(lt)||!isNumeric(rt)){
            yyerror("Semantic Error: comparison requires int/real.");
            return "unknown";
        }
        return "bool";
    }

    /* == != */
    if (strcmp(expr->token,"==")==0||strcmp(expr->token,"!=")==0){
        int ok =
            (isInt(lt)&&isInt(rt))   ||
            (isReal(lt)&&isReal(rt)) ||
            (isBool(lt)&&isBool(rt)) ||
            (isChar(lt)&&isChar(rt)) ||
            samePtrType(lt,rt);
        if (!ok){
            yyerror("Semantic Error: illegal types for equality operator.");
            return "unknown";
        }
        return "bool";
    }

    /* |expr| */
    if (strcmp(expr->token,"|")==0){
        if (!isStr(lt)){
            yyerror("Semantic Error: | | expects string.");
            return "unknown";
        }
        return "int";
    }

    /* !expr */
    /* not / !  (unary NOT) */
    if (strcmp(expr->token,"not")==0 || strcmp(expr->token,"!")==0){
    if (!isBool(lt)){
        yyerror("Semantic Error: !/not expects bool.");
        return "unknown";
    }
    return "bool";
    }


        /* &expr  — Address-of */
    if (strcmp(expr->token,"&")==0){
        char* opType = lt;   /* type of operand */

        if (isInt(opType))      return "intptr";
        if (isReal(opType))     return "realptr";
        if (isChar(opType))     return "charptr";
        yyerror("Semantic Error: '&' operator allowed only on int, real, char or string[i].");
        return "unknown";
    }
     /* *expr  -----------------------------------------------------*/
    if (strcmp(expr->token,"deref")==0 || strcmp(expr->token,"unary*")==0){
        char* ptrT = inferExprType(expr->left ? expr->left : expr->right);
        if (!isPointerType(ptrT)){
            yyerror("Semantic Error: '*' operator can only be applied to pointers.");
            return "unknown";
        }
        if (strcasecmp(ptrT,"intptr" )==0) return "int";
        if (strcasecmp(ptrT,"realptr")==0) return "real";
        if (strcasecmp(ptrT,"charptr")==0) return "char";
        return "unknown";   /* pointer אבל לטיפוס אחר – לא אמור לקרות */
    }

    printf("inferExprType: WARNING – unknown token %s\n",expr->token);
    return "unknown";
}

int validateReturnType(node* body, const char* expectedType) {
    if (!body) return 1;

    if (strcmp(body->token, "return") == 0) {
        char* actualType = inferExprType(body->left);
        if (strcmp(actualType, expectedType) != 0) {
            char msg[256];
            sprintf(msg, "Semantic Error: Return type is '%s' but expected '%s'.", actualType, expectedType);
            yyerror(msg);
            return 0;
        }
    }

    // Recurse through the AST
    if (!validateReturnType(body->left, expectedType)) return 0;
    if (!validateReturnType(body->right, expectedType)) return 0;

    return 1;
}
int isPointerType(const char* type) {
    return strcmp(type, "intptr") == 0 ||
           strcmp(type, "charptr") == 0 ||
           strcmp(type, "realptr") == 0;
}

int registerParams(node *plist)
{
    node *p = plist;
    while (p) {
        node *single = (strcmp(p->token,"PARAMS")==0) ? p->left : p;
        if (single && strcmp(single->token,"PARAM")==0) {
            char *id  = single->right->token;   /* parameter name  */
            char *typ = single->left ->token;   /* INT / REAL …    */

            if (insertSymbol(id, VAR, typ, 0, "param", NULL)) {
                yyerror("Semantic Error: Duplicate parameter name.");
                return 1;          /* signal failure */
            }
        }
        p = (strcmp(p->token,"PARAMS")==0) ? p->right : NULL;
    }
    return 0;                      /* success */
}