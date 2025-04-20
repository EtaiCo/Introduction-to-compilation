
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
     void visualize_ast(node* root,const char* branch_prefix,int is_left_branch); /*לתקן */
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
%token SEMICOLON COLON COMMA LPAREN RPAREN LBRACKET RBRACKET 
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
%type <nodePtr> param var dec_list dec type 
%type <nodePtr> statements statement assign_state
%type <nodePtr> if_state while_state do_while_state
%type <nodePtr> for_state for_h update_exp condition
%type <nodePtr> bl_stat rt_state func_call_state
%type <nodePtr> func_call exp_list expression

%%
/* ----------------------------  Root Rule  -------------------------------*/
code :
    functions { $$ = $1; printTree($$,0)}          
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
        node* returnsN = mknode("RETURNS", $7, NULL);
        node* bodyN = mknode("BODY", $8, $10);
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
            PAR type COLON ID {$$=mkNode("PARAM",$2,mkNode($4,NULL,NULL));}
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
        { $$ = mkNode("VAR_ASSIGN", mkNode("IDENT", mkNode($1, NULL, NULL), NULL), $3); }

    | IDENT 
        { $$ = mkNode("VAR_DECL", mkNode("IDENT", mkNode($1, NULL, NULL), NULL), NULL); }

    | IDENT '[' INT_LIT ']' 
        { $$ = mkNode("ARRAY_DECL", mkNode("IDENT", mkNode($1, NULL, NULL), NULL), mkNode($3, NULL, NULL)); }

    | IDENT '[' INT_LIT ']' ':' STRING_LIT 
        { 
            $$ = mkNode("ARRAY_INIT",
                        mkNode("ARRAY_DECL", mkNode("IDENT", mkNode($1, NULL, NULL), NULL), mkNode($3, NULL, NULL)),
                        mkNode($6, NULL, NULL)); 
        }
    ;

literal :
          INT_LIT      { $$ = mkNode("INT", mkNode($1, NULL, NULL), NULL); }
        | TRUE         { $$ = mkNode("BOOL", mkNode("true", NULL, NULL), NULL); }
        | FALSE        { $$ = mkNode("BOOL", mkNode("false", NULL, NULL), NULL); }
        | CHAR_LIT     { $$ = mkNode("CHAR", mkNode($1, NULL, NULL), NULL); }
        | STRING_LIT   { $$ = mkNode("STRING", mkNode($1, NULL, NULL), NULL); }
        | REAL_LIT     { $$ = mkNode("REAL", mkNode($1, NULL, NULL), NULL); }
        | NULLL        { $$ = mkNode("NULL", NULL, NULL); }
        ;

/* -------------------  Local‑var block  ----------------------------------*/
var :                                     
    { $$ = NULL; }
    | VAR dec_list                { $$ = mknode("VAR",$2,NULL); }
    ;

dec_list : 
    dec                        { $$ = $1; }
    | declaration dec_list        { $$ = mknode("DECS",$1,$2); }
    ;

dec
    : TYPE type ':' id_list ';'           { $$ = mknode("DECL",$2,$4); }
    ;

/* ------------------------- Statements seq. ------------------------------*/
statements :
     {$$ = mkNode("empty_list", NULL,NULL);}
            | statement {$$ = $1;}
            | stat stat_list {$$ = mkNode("statements", $1, $2);}
            ;


/* --------------------------- Single statement ---------------------------*/
stat:
            function {$$=$1;}
            | assignment_stat {$$ = $1;}
            | if_stat {$$ = $1;}
            | while_stat {$$ = $1;}
            | for_stat {$$ = $1;}
            | do_while_stat {$$ = $1;}
            | block_stat {$$ = $1;}
            | return_stat {$$ = $1;}
            | call_stat {$$ = $1;}
        ;
////////////////////// הגענו עד לפה /* ------------------------- Assignment variants --------------------------*/
assignment_statement
    : IDENT ASSIGN expression ';'      /* x = expr; */
        { $$ = mknode("assign",
                      mknode($1,NULL,NULL), $3); }

    /* arr[index] = 'c'; */
    | IDENT '[' expression ']' ASSIGN CHAR_LITERAL ';' {
          char cbuf[2]={$6,'\0'};
          $$ = mknode("array_assign",
                      mknode($1,$3,NULL),
                      mknode(cbuf,NULL,NULL)); }

    /* *p = expr;  (dereferenced pointer) */
    | MULT IDENT ASSIGN expression ';' {
          $$ = mknode("pointer_assign",
                      mknode($2,NULL,NULL), $4); }

    /* x = &y;  (reference assign) */
    | IDENT ASSIGN AMPERSAND IDENT ';' {
          $$ = mknode("ref_assign",
                      mknode($1,NULL,NULL),
                      mknode($4,NULL,NULL)); }

    /* x = null; */
    | IDENT ASSIGN NULL_TOKEN ';' {
          $$ = mknode("null_assign",
                      mknode($1,NULL,NULL),
                      mknode("null",NULL,NULL)); }

    /* arr[i] = <int> */
    | IDENT '[' expression ']' ASSIGN INTEGER ';' {
          char buf[32]; sprintf(buf,"%d",$6);
          $$ = mknode("array_assign",
                      mknode($1,$3,NULL),
                      mknode(buf,NULL,NULL)); }

    /* arr[i] = "str" */
    | IDENT '[' expression ']' ASSIGN STRING_LITERAL ';' {
          $$ = mknode("array_assign",
                      mknode($1,$3,NULL),
                      mknode($6,NULL,NULL)); }

    /* arr[i] = expr */
    | IDENT '[' expression ']' ASSIGN expression ';' {
          $$ = mknode("array_assign",
                      mknode($1,$3,NULL), $6); }
    ;

/* -----------------------------  IF / ELIF / ELSE ------------------------*/
if_statement
    : IF expression ':' block_statement                {
          $$ = mknode("if",$2,$4); }

    | IF expression ':' block_statement
      ELSE ':' block_statement                         {
          $$ = mknode("if-else",$2,
                      mknode("then",$4,
                             mknode("else",$7,NULL))); }

    | IF expression ':' block_statement
      ELIF expression ':' block_statement              {
          $$ = mknode("if-elif",$2,
                      mknode("then",$4,
                             mknode("elif-cond",$6,$8))); }

    | IF expression ':' block_statement
      ELIF expression ':' block_statement
      ELSE ':' block_statement                         {
          $$ = mknode("if-elif-else",$2,
                      mknode("then",$4,
                             mknode("elif-cond",$6,
                                    mknode("elif-then",$8,
                                           mknode("else",$11,NULL))))); }
    ;

/* -----------------------------  WHILE loop ------------------------------*/
while_statement
    : WHILE expression ':' block_statement {
          $$ = mknode("while",$2,$4); }
    ;

/* ---------------------------  DO‑WHILE loop -----------------------------*/
do_while_statement
    : DO ':' block_statement WHILE expression ';' {
          $$ = mknode("do-while",$3,
                      mknode("cond",$5,NULL)); }
    ;

/* -----------------------------  FOR loop --------------------------------*/
for_statement
    : FOR for_header ':' block_statement            {
          $$ = mknode("for",$2,$4); }
    | FOR for_header ':' var block_statement        {
          $$ = mknode("for",$2,
                      mknode("block",$5,$4)); }
    ;

for_header
    : '(' IDENT ASSIGN expression ';'
          expression ';'
          update_exp ')'                           {
          $$ = mknode("for-header",
                      mknode("init",mknode($2,NULL,NULL),$4),
                      mknode("loop",$6,$8)); }
    ;

update_exp
    : IDENT ASSIGN expression                 {
          $$ = mknode("update",
                      mknode($1,NULL,NULL),$3); }
    ;

/* -----------------------  Boolean condition helper ----------------------*/
condition
    : expression                                   { $$ = $1; }
    | NOT condition                                { $$ = mknode("not",$2,NULL); }
    | '(' condition ')'                            { $$ = $2; }
    | TRUE                                         { $$ = mknode("true",NULL,NULL); }
    | FALSE                                        { $$ = mknode("false",NULL,NULL); }
    ;

/* --------------------  BEGIN … END compound‑statement -------------------*/
block_statement
    : T_BEGIN statements END                   { $$ = mknode("block",$2,NULL); }
    | var T_BEGIN statements END               { $$ = mknode("block",$3,$1); }
    ;

/* -----------------------------  Return  ---------------------------------*/
return_statement
    : RETURN expression ';'                        { $$ = mknode("return",$2,NULL); }
    ;

/* -------------------------  Function‑call stmt --------------------------*/
function_call_statement
    : function_call ';'                            { $$ = $1; }
    | IDENT ASSIGN function_call ';'          {
          $$ = mknode("assign",
                      mknode($1,NULL,NULL),$3); }
    ;

/* -------------------------  Function call expr --------------------------*/
function_call
    : CALL IDENT '(' ')'                      {
          $$ = mknode("call",mknode($2,NULL,NULL),NULL); }
    | CALL IDENT '(' expr_list ')'            {
          $$ = mknode("call",mknode($2,NULL,NULL),$4); }
    ;

/* --------------------------  Expression list ----------------------------*/
expr_list
    : expression                                   { $$ = $1; }
    | expression ',' expr_list                     { $$ = mknode("expr_list",$1,$3); }
    ;

/* ---------------------------  Expressions  ------------------------------*/
expression
    /* ---- primary ----*/
    : INTEGER       { char buf[32]; sprintf(buf,"%d",$1);
                      $$ = mknode(buf,NULL,NULL); }

    | REAL          { char buf[64]; sprintf(buf,"%f",$1);
                      $$ = mknode(buf,NULL,NULL); }

    | STRING_LITERAL { $$ = mknode($1,NULL,NULL); }

    | CHAR_LITERAL  { char buf[2]={$1,'\0'};
                      $$ = mknode(buf,NULL,NULL); }

    | IDENT    { $$ = mknode($1,NULL,NULL); }

    /* ---- arithmetic / logical binary ----*/
    | expression PLUS   expression  { $$ = mknode("+",$1,$3); }
    | expression MINUS  expression  { $$ = mknode("-",$1,$3); }
    | expression MULT   expression  { $$ = mknode("*",$1,$3); }
    | expression DIV    expression  { $$ = mknode("/",$1,$3); }
    | expression MODULO expression  { $$ = mknode("%",$1,$3); }

    /* ---- unary ----*/
    | MINUS     expression          { $$ = mknode("unary-",$2,NULL); }
    | AMPERSAND expression          { $$ = mknode("&",$2,NULL); }
    | MULT      IDENT          { $$ = mknode("deref",mknode($2,NULL,NULL),NULL); }
    | MULT      expression          { $$ = mknode("unary*", $2,NULL); }

    /* ---- grouping ----*/
    | '(' expression ')'            { $$ = $2; }

    /* ---- comparison ----*/
    | expression EQ expression      { $$ = mknode("==",$1,$3); }
    | expression NE expression      { $$ = mknode("!=",$1,$3); }
    | expression GE expression      { $$ = mknode(">=",$1,$3); }
    | expression LE expression      { $$ = mknode("<=",$1,$3); }
    | expression GT expression      { $$ = mknode(">", $1,$3); }
    | expression LT expression      { $$ = mknode("<", $1,$3); }

    /* ---- logical ----*/
    | expression AND expression     { $$ = mknode("and",$1,$3); }
    | expression OR  expression     { $$ = mknode("or",$1,$3); }

    /* ---- array index ----*/
    | IDENT '[' expression ']' { $$ = mknode("index",mknode($1,NULL,NULL),$3); }

    /* ---- nested call ----*/
    | function_call                 { $$ = $1; }
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
static node *mknode(char *token, node *left, node *right)
{
    node *n = (node*)malloc(sizeof(node));
    if (!n) { fprintf(stderr,"alloc node failed\n"); exit(1); }

    n->token = strdup(token);  /* deep‑copy string */
    n->left  = left;
    n->right = right;
    return n;
}

static void printTabs(int k){ while(k--) printf("  "); }

static void printTree(node *t, int lvl)
{
    if(!t) return;
    printTabs(lvl);
    printf("%s\n",t->token);
    printTree(t->left ,lvl+1);
    printTree(t->right,lvl+1);
}

/* --------  ascii‑art visualization (like tree‑command)  ---------------*/
static void visualize_ast(node *root,
                          const char *prefix,
                          int is_left)
{
    if(!root) return;

    printf("%s%s── %s\n", prefix,
           is_left ? "├" : "└", root->token);

    char next[512];
    snprintf(next,sizeof(next), "%s%s   ",
             prefix, is_left ? "│" : " ");

    if(root->left || root->right)
    {
        visualize_ast(root->left , next, 1);
        visualize_ast(root->right, next, 0);
    }
}

/* -------------------------  error handler -------------------------------*/
int yyerror(const char *s)
{
    fprintf(stderr,"Error: %s at line %d near '%s'\n",
            s, yylineno, yytext);
    return 0;
}

