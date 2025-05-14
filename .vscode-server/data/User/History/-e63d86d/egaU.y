
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int yylex();
    int yyerror(const char *s);
    extern int   yylineno;  
    extern char* yytext; 
    /* AST node */
    typedef struct node {
        char* token;  
        struct node* left;   
        struct node* right; 
    } node;

     node *mknode(char* token, node* left, node* right);
     void printTree(node* tree, int level);
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
%type <nodePtr> param var dec_list dec type literal idents idents_list
%type <nodePtr> statements state assign_state
%type <nodePtr> if_state while_state do_while_state
%type <nodePtr> for_state for_h advance_exp condition
%type <nodePtr> bl_state rt_state func_call_state
%type <nodePtr> func_call exp_list expression

%%
/* ----------------------------  Root Rule  -------------------------------*/
code :
    functions {node *root = mknode("CODE", $1, NULL); printTree(root, 0);}          
;

/* --------------------------- Functions list -----------------------------*/
functions :
      function functions                   { $$ = mknode("FUNCS",$1,$2); }
    |  function                              { $$ = $1; }
    ;

/* ------------------------ Single function rule -------------------------*/
function : 
    DEF IDENT '(' params ')' ':' RETURNS type var T_BEGIN statements END
    {
        node* idN = mknode($2, NULL, NULL);
        node* paramsN = mknode("PARAMS", $4, NULL);
        node* returnsN = mknode("RETURNS", $8, NULL);
        node* bodyN = mknode("BODY", $9, $11);
        node* defBodyN = mknode("DEF_BODY", returnsN, bodyN);
        $$ = mknode("FUNCTION", idN, mknode("FUNC_IN", paramsN, defBodyN));
    }

  | DEF IDENT '(' params ')' ':' var T_BEGIN statements END
    {
        node* idN = mknode($2, NULL, NULL);
        node* paramsN = mknode("PARAMS", $4, NULL);
        node* bodyN = mknode("BODY", $7, $9);
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
ident_entry :
      IDENT ':' literal            { $$ = mknode("VAR_ASSIGN", mknode("IDENT", mknode($1,NULL,NULL), NULL), $3); }
    | IDENT                        { $$ = mknode("VAR_DECL", mknode("IDENT", mknode($1,NULL,NULL), NULL), NULL); }
;

idents_list :
      idents                          { $$ = $1; }
    | idents ',' idents_list         { $$ = mknode("ID_LIST", $1, $3); }
;

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
            $$ = mknode("ARRAY_INIT",
                        mknode("ARRAY_DECL", mknode("IDENT", mknode($1, NULL, NULL), NULL), mknode($3, NULL, NULL)),
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
    TYPE type ':' idents_list ';'      { $$ = mknode("DECL", $2, $4); }
;



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
     IDENT ASSIGN expression ';'      
        { $$ = mknode("assign",
                      mknode($1,NULL,NULL), $3); }

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
    T_BEGIN statements END                   { $$ = mknode("block",$2,NULL); }
    | var T_BEGIN statements END               { $$ = mknode("block",$3,$1); }
    ;



/* -------------------------  Function‑call stmt --------------------------*/
func_call_state :
     func_call ';'                            { $$ = $1; }
    | IDENT ASSIGN func_call ';'          {
          $$ = mknode("assign",
                      mknode($1,NULL,NULL),$3); }
    ;

/* -------------------------  Function call expr --------------------------*/
func_call :
      CALL IDENT '(' ')'                      {
          $$ = mknode("call",mknode($2,NULL,NULL),NULL); }
    | CALL IDENT '(' exp_list ')'            {
          $$ = mknode("call",mknode($2,NULL,NULL),$4); }
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

    | IDENT    { $$ = mknode($1,NULL,NULL); }

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
    | IDENT '[' expression ']' { $$ = mknode("index",mknode($1,NULL,NULL),$3); }

    /* ---- logical ----*/
    | expression AND expression     { $$ = mknode("and",$1,$3); }
    | expression OR  expression     { $$ = mknode("or",$1,$3); }

    | TRUE                          { $$ = mknode("BOOL", mknode("TRUE", NULL, NULL), NULL); }
    | FALSE                         { $$ = mknode("BOOL", mknode("FALSE", NULL, NULL), NULL); }

    /* ---- nested call ----*/
    | func_call                 { $$ = $1; }
    ;
%%  /* ===================  C‑code section ================================*/

#include "lex.yy.c"

/* ----------------------------  main  ------------------------------------*/
int main(void)
{
    yyparse();
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

