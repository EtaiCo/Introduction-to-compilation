
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #define MAX_PARAMS 10

    int yylex();
    int yyerror(const char *s);
    extern int yylineno;  
    extern char* yytext; 

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

    int mainDeclared = 0;
    int scopeDepth = 0;


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
%token IF ELIF ELSE WHILE FOR DO VARIABLE PAR
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

%type <nodePtr> code functions function params param_list
%type <nodePtr> param var dec_list dec type literal  idents 
%type <nodePtr> statements state assign_state
%type <nodePtr> if_state while_state do_while_state
%type <nodePtr> for_state for_h advance_exp condition
%type <nodePtr> bl_state rt_state func_call_state
%type <nodePtr> func_call exp_list expression


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
scope_marker: { pushScope(); };

function :
    DEF IDENT '(' params ')' ':' RETURNS type var scope_marker T_BEGIN statements END
    {
        popScope();
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
                if (single && strcmp(single->token, "PARAM") == 0 && single->left) 
                {
                    char* rawType = single->left->token;
                    char* lowered = strdup(rawType);
                    for (char* p = lowered; *p; p++) *p = tolower(*p);
                    paramTypes[paramCount++] = lowered;
                }
                curParam = curParam->right;
            } else if (strcmp(curParam->token, "PARAM") == 0) {
                paramTypes[paramCount++] = curParam->left->token;
                break;
            } else {
                break;
            }
        }

        char* returnType = strdup($8->token);
        for (char* p = returnType; *p; p++) *p = tolower(*p);
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
        $$ = mknode("FUNCTION", idN, mknode("FUNC_IN", paramsN, defBodyN));
    }

  | DEF IDENT '(' params ')' ':' var scope_marker T_BEGIN statements END
    {
        popScope();
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
                if (single && strcmp(single->token, "PARAM") == 0 && single->left) 
                {
                    char* rawType = curParam->left->token;
                    char* lowered = strdup(rawType);
                    for (char* p = lowered; *p; p++) *p = tolower(*p);
                    paramTypes[paramCount++] = lowered;

                }
                curParam = curParam->right;
            } else if (strcmp(curParam->token, "PARAM") == 0) {
                paramTypes[paramCount++] = curParam->left->token;
                break;
            } else {
                break;
            }
        }

        if (insertSymbol($2, FUNC, "void", paramCount, "global", paramTypes)) 
        {
            yyerror("Semantic Error: Function already declared in the same scope.");
            YYABORT;
        }

        node* idN = mknode($2, NULL, NULL);
        node* paramsN = mknode("PARAMS", $4, NULL);
        node* bodyN = mknode("BODY", $7, $10);  // $7 = var, $10 = statements
        $$ = mknode("PROC", idN, mknode("PROC_IN", paramsN, bodyN));
    }
;



/* --------------------- param declarations ---------------------------*/
params :                                 
    { $$ = NULL; }
    | param_list                      { $$ = $1;   }
    ;

param_list :
    param                           { $$ = $1; }
    | param ';' param_list        { $$ = mknode("PARAMS",$1,$3); }
    ;

param : 
            PAR type ':' IDENT {$$=mknode("PARAM",$2,mknode($4,NULL,NULL));}
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

/* -------------------  id‑list  ------------------*/
idents : 
      IDENT ':' literal 
        { $$ = mknode("VAR_ASSIGN", mknode("IDENT", mknode($1,NULL,NULL), NULL), $3); }

    | IDENT 
        { $$ = mknode("VAR_DECL", mknode("IDENT", mknode($1, NULL, NULL), NULL), NULL); }

    | IDENT '[' INT_LIT ']' 
        { char sz[32]; sprintf(sz,"%d",$3);
         $$ = mknode("ARRAY_DECL", mknode("IDENT", mknode($1, NULL, NULL), NULL), mknode(sz, NULL, NULL)); }

    | IDENT '[' INT_LIT ']' ':' STRING_LIT 
    {
    char sizeStr[32];
    sprintf(sizeStr, "%d", $3); // Convert INT_LIT to string

    $$ = mknode("ARRAY_INIT",
                mknode("ARRAY_DECL", mknode("IDENT", mknode($1, NULL, NULL), NULL), mknode(sizeStr, NULL, NULL)),
                mknode($6, NULL, NULL)); 
    }

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
    TYPE type ':' idents ';' 
    {
        node* declList = $4;
        char* typeStr = $2->token;

        while (declList) {
            if (strcmp(declList->token, "VAR_DECL") == 0 || strcmp(declList->token, "VAR_ASSIGN") == 0) {
                node* idNode = declList->left;
                if (idNode && strcmp(idNode->token, "IDENT") == 0 && idNode->left) {
                    char* varName = idNode->left->token;
                    if (insertSymbol(varName, VAR, typeStr, 0, "block", NULL))
                    {                       
                        yyerror("Semantic Error: Variable already declared in this scope.");
                        YYABORT;
                    }
                }
            }
            declList = declList->right;
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
        ;
/* ------------------------- Assignment variants --------------------------*/
assign_state :
    /* x = expr; */
     | IDENT ASSIGN expression ';' {
    if (!isVarDeclaredInScope($1)) {
        char msg[128];
        sprintf(msg, "Semantic Error: Variable '%s' used before declaration.", $1);
        yyerror(msg);
        YYABORT;
    }
    $$ = mknode("assign", mknode($1,NULL,NULL), $3);
}


    /* arr[index] = 'c'; */
    | IDENT '[' expression ']' ASSIGN CHAR_LIT ';' {
          char cbuf[2]={$6,'\0'};
          $$ = mknode("array_assign",
                      mknode($1,$3,NULL),
                      mknode(cbuf,NULL,NULL)); }

    /* *p = expr;  (dereferenced pointer) */
    | MULTI IDENT ASSIGN expression ';' {
          $$ = mknode("pointer_assign",
                      mknode($2,NULL,NULL), $4); }

    /* x = &y;  (reference assign) */
    | IDENT ASSIGN ADDRESS IDENT ';' {
          $$ = mknode("adder_assign",
                      mknode($1,NULL,NULL),
                      mknode($4,NULL,NULL)); }

    /* x = null; */
    | IDENT ASSIGN NULLL ';' {
          $$ = mknode("null_assign",
                      mknode($1,NULL,NULL),
                      mknode("null",NULL,NULL)); }

    /* arr[i] = <int> */
    | IDENT '[' expression ']' ASSIGN INT_LIT ';' {
          char buf[32]; sprintf(buf,"%d",$6);
          $$ = mknode("array_assign",
                      mknode($1,$3,NULL),
                      mknode(buf,NULL,NULL)); }

    /* arr[i] = "str" */
    | IDENT '[' expression ']' ASSIGN STRING_LIT ';' {
          $$ = mknode("array_assign",
                      mknode($1,$3,NULL),
                      mknode($6,NULL,NULL)); }

    /* arr[i] = expr */
    | IDENT '[' expression ']' ASSIGN expression ';' {
          $$ = mknode("array_assign",
                      mknode($1,$3,NULL), $6); }
    ;

/* -----------------------------  IF / ELIF / ELSE ------------------------*/
if_state :
      IF expression ':' bl_state
        { $$ = mknode("if", $2, $4); }

    | IF expression ':' bl_state ELSE ':' bl_state
        { $$ = mknode("if_else", $2, mknode("then", $4, mknode("else", $7, NULL))); }

    | IF expression ':' bl_state ELIF expression ':' bl_state
        { $$ = mknode("if_elif", $2, mknode("then", $4, mknode("elif", $6, $8))); }

    | IF expression ':' bl_state ELIF expression ':' bl_state ELSE ':' bl_state
        { $$ = mknode("if_elif-else", $2, mknode("then", $4, mknode("elif", $6, mknode("elif-then", $8, mknode("else", $11, NULL))))); }
    ;

/* -----------------------------  WHILE loop ------------------------------*/
while_state :
      WHILE expression ':' bl_state {
          $$ = mknode("while",$2,$4); }
    ;

/* ---------------------------  DO‑WHILE loop -----------------------------*/
do_while_state :
      DO ':' bl_state WHILE expression ';' {
          $$ = mknode("do_while",$3,
                      mknode("condition",$5,NULL)); }
    ;

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
          advance_exp ')'                           {
          $$ = mknode("for_header",
                      mknode("init",mknode($2,NULL,NULL),$4),
                      mknode("loop",$6,$8)); }
    ;

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
;

/* --------------------------  Expression list ----------------------------*/
exp_list :
      expression                                   { $$ = $1; }
    | expression ',' exp_list                     { $$ = mknode("exp_list",$1,$3); }
    ;

/* ---------------------------  Expressions  ------------------------------*/
expression :
    /* ---- primary ----*/
     INT_LIT       { char buf[32]; sprintf(buf,"%d",$1);
                      $$ = mknode(buf,NULL,NULL); }

    | REAL_LIT          { char buf[64]; sprintf(buf,"%f",$1);
                      $$ = mknode(buf,NULL,NULL); }

    | STRING_LIT { $$ = mknode($1,NULL,NULL); }

    | CHAR_LIT  { char buf[2]={$1,'\0'};
                      $$ = mknode(buf,NULL,NULL); }

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
    | ADDRESS expression          { $$ = mknode("&",$2,NULL); }
    | MULTI      IDENT          { $$ = mknode("deref",mknode($2,NULL,NULL),NULL); }
    | MULTI      expression          { $$ = mknode("unary*", $2,NULL); }

    /* ---- grouping ----*/
    | '(' expression ')'            { $$ = $2; }

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
            sprintf(msg, "Semantic Error: Array '%s' used before declaration.", $1);
            yyerror(msg);
            YYABORT;
        }
        $$ = mknode("index", mknode($1, NULL, NULL), $3);
    }

    /* ---- logical ----*/
    | expression AND expression     { $$ = mknode("and",$1,$3); }
    | expression OR  expression     { $$ = mknode("or",$1,$3); }

    /* ---- nested call ----*/
    | func_call                 { $$ = $1; }
    ;
%%  /* ===================  C‑code section ================================*/

#include "lex.yy.c"

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
char* inferExprType(node* expr) {
    if (!expr || !expr->token) return "unknown";

    if (strcmp(expr->token, "INT") == 0 || isdigit(expr->token[0])) return "int";
    if (strchr(expr->token, '.')) return "real";
    if (strcmp(expr->token, "true") == 0 || strcmp(expr->token, "false") == 0) return "bool";
    if (expr->token[0] == '\'' && strlen(expr->token) == 3) return "char"; // e.g., 'c'
    if (expr->token[0] == '"') return "string";

    Symbol* sym = lookupSymbol(expr->token);
    if (sym && sym->type == VAR && sym->returnType) return sym->returnType;

    return "unknown";
}
