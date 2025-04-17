/* ----------  part1_EL.y  ---------- *
 *     Parser + AST builder           */

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "lex.yy.c"          /* yylex(), yytext, yylineno */

    /* ---------- AST node ---------- */
    typedef struct ast_node {
        char             tok;    / label / operator */
        struct ast_node  l;      / first  child     */
        struct ast_node  r;      / second child     */
    } *node;

    /* helpers */
    static node mknode(char *t,node l,node r){
        node n = (node)malloc(sizeof(struct ast_node));
        n->tok = strdup(t);
        n->l   = l;
        n->r   = r;
        return n;
    }
    static void printTabs(int n){ while(n-- >0) putchar(' '); }
    static void printTree(node t,int ind){
        if(!t) return;
        printTabs(ind);
        if(strcmp(t->tok,"")) printf("(%s",t->tok);

        if(t->l){ putchar('\n'); printTree(t->l,ind+3); }
        if(t->r){ putchar('\n'); printTree(t->r,ind+3); }

        if(strcmp(t->tok,"")) printf(")");
        if(!ind) putchar('\n');
    }
    int yyerror(char *s){
        fprintf(stderr,"Error: %s at line %d near '%s'\n",s,yylineno,yytext);
        return 0;
    }
%}

/* ---------- Bison value types ---------- */
%union{
    node  n;        /* AST node                      */
    char str;      / IDENT / literal raw text      */
    int   boolean;  /* TRUE / FALSE                  */
}

/* ---------- terminals from the lexer ---------- */
%token <str> BOOL CHAR INT REAL STRING INTPTR CHARPTR REALPTR
%token <str> IF ELIF ELSE WHILE FOR DO VARIABLE PAR RETURN RETURNS
%token <str> NULLL BEGIN END DEF CALL
%token <str> AND OR NOT
%token <str> BOOL_LIT HEX_LIT INT_LIT REAL_LIT CHAR_LIT STRING_LTL
%token <str> IDENT

/* ops & punctuation */
%token <str> EQL NOTEQL GREATEREQL LESSEQL GREATER LESS
%token <str> ASSIGN PLUS MINUS MULTI DIV ADDRESS LENGTH
%token <str> LPAREN RPAREN LBRACKET RBRACKET SEMICOLON COLON COMMA

/* precedence (כמו ‑C) */
%left  OR
%left  AND
%left  EQL NOTEQL LESS LESSEQL GREATER GREATEREQL
%left  PLUS MINUS
%left  MULTI DIV
%right ADDRESS NOT
%right ASSIGN                     /* lowest */

/* ---------- non‑terminal types ---------- */
%type <n> program units unit
%type <n> func_hdr proc_hdr params param_list ret_type
%type <n> decls decl decl_ids type_spec
%type <n> stmts stmt block opt_stmts opt_else
%type <n> assign lhs call_stmt arg_list
%type <n> expr unary primary literal

%%  /* ================= grammar ================= */

/* program root */
program      : units                           { printTree($1,0); YYACCEPT; } ;

/* sequence of units (funcs / procs) */
units        : units unit                      { $$ = mknode("",$1,$2); }
             | /* ε */                         { $$ = NULL; } ;

unit         : func_hdr block                  { $$ = mknode("FUNC",$1,$2); }
             | proc_hdr block                  { $$ = mknode("PROC",$1,$2); } ;

/* ---------- headers ---------- */
func_hdr     : DEF IDENT LPAREN params RPAREN COLON RETURNS ret_type
                   { $$ = mknode($2,
                                  mknode("PARAMS",$4,NULL),
                                  mknode("RET",$8,NULL)); } ;

proc_hdr     : DEF IDENT LPAREN params RPAREN
                   { $$ = mknode($2,
                                  mknode("PARAMS",$4,NULL),
                                  NULL); } ;

ret_type     : BOOL     { $$ = mknode("bool"  ,NULL,NULL); }
             | CHAR     { $$ = mknode("char"  ,NULL,NULL); }
             | INT      { $$ = mknode("int"   ,NULL,NULL); }
             | REAL     { $$ = mknode("real"  ,NULL,NULL); }
             | STRING   { $$ = mknode("string",NULL,NULL); }
             | INTPTR   { $$ = mknode("int*"  ,NULL,NULL); }
             | CHARPTR  { $$ = mknode("char*" ,NULL,NULL); }
             | REALPTR  { $$ = mknode("real*" ,NULL,NULL); } ;

params       : param_list                       { $$ = $1; }
             | /* ε */                          { $$ = NULL; } ;

param_list   : param_list SEMICOLON param_list  { $$ = mknode("",$1,$3); }
             | PAR INT_LIT type_spec COLON IDENT
                   { $$ = mknode("PAR",
                                  mknode($3->tok,NULL,NULL),
                                  mknode($5,NULL,NULL)); } ;

/* ---------- block ---------- */
block        : VARIABLE decls BEGIN opt_stmts END
                   { $$ = mknode("BLOCK",
                                  mknode("DECLS",$2,NULL),
                                  $4); }
             | BEGIN opt_stmts END              { $$ = mknode("BLOCK",$2,NULL); } ;

opt_stmts    : stmts | /* ε */                  { $$ = NULL; } ;

/* ---------- declarations ---------- */
decls        : decls decl                       { $$ = mknode("",$1,$2); }
             | decl                             { $$ = $1; } ;

decl         : type_spec COLON decl_ids SEMICOLON
                   { $$ = mknode("VAR",
                                  mknode($1->tok,NULL,NULL),
                                  $3); } ;

type_spec    : BOOL     { $$ = mknode("bool" ,NULL,NULL); }
             | CHAR     { $$ = mknode("char" ,NULL,NULL); }
             | INT      { $$ = mknode("int"  ,NULL,NULL); }
             | REAL     { $$ = mknode("real" ,NULL,NULL); }
             | STRING   { $$ = mknode("string",NULL,NULL); }
             | INTPTR   { $$ = mknode("int*" ,NULL,NULL); }
             | CHARPTR  { $$ = mknode("char*",NULL,NULL); }
             | REALPTR  { $$ = mknode("real*",NULL,NULL); } ;

decl_ids     : decl_ids COMMA decl_ids          { $$ = mknode("",$1,$3); }
             | IDENT                            { $$ = mknode($1,NULL,NULL); } ;

/* ---------- statements ---------- */
stmts        : stmts stmt                       { $$ = mknode("",$1,$2); }
             | stmt                             { $$ = $1; } ;

stmt         : assign SEMICOLON                 { $$ = $1; }
             | call_stmt SEMICOLON              { $$ = $1; }
             | IF expr COLON block opt_else
                   { $$ = mknode("IF",$2,mknode("",$4,$5)); }
             | WHILE expr COLON block           { $$ = mknode("WHILE",$2,$4); }
             | DO COLON block WHILE COLON expr SEMICOLON
                   { $$ = mknode("DO",$3,$6); }
             | FOR LPAREN assign SEMICOLON expr SEMICOLON assign RPAREN COLON block
                   { node hdr=mknode("FOR",$3,mknode("",$5,$7));
                     $$ = mknode("FOR",hdr,$10); }
             | RETURN expr SEMICOLON            { $$ = mknode("RET",$2,NULL); }
             | RETURN literal SEMICOLON         { $$ = mknode("RET",$2,NULL); }
             | block                            { $$ = $1; } ;

opt_else     : ELSE COLON block                 { $$ = $3; }
             | /* ε */                          { $$ = NULL; } ;

/* ---------- assignment & call ---------- */
assign       : lhs ASSIGN expr                  { $$ = mknode("=", $1,$3); } ;

lhs          : IDENT                            { $$ = mknode($1,NULL,NULL); }
             | IDENT LBRACKET expr RBRACKET     { $$ = mknode("[]",mknode($1,NULL,NULL),$3); }
             | MULTI IDENT                      { $$ = mknode("*",mknode($2,NULL,NULL),NULL); } ;

call_stmt    : CALL IDENT LPAREN arg_list RPAREN
                   { $$ = mknode("CALL",
                                  mknode($2,NULL,NULL),
                                  mknode("ARGS",$4,NULL)); } ;

arg_list     : arg_list COMMA expr              { $$ = mknode("",$1,$3); }
             | expr                             { $$ = $1; }
             | /* ε */                          { $$ = NULL; } ;

/* ---------- expressions ---------- */
expr         : expr OR      expr                { $$ = mknode("||",$1,$3); }
             | expr AND     expr                { $$ = mknode("&&",$1,$3); }
             | expr EQL     expr                { $$ = mknode("==",$1,$3); }
             | expr NOTEQL  expr                { $$ = mknode("!=",$1,$3); }
             | expr GREATER expr                { $$ = mknode(">", $1,$3); }
             | expr GREATEREQL expr             { $$ = mknode(">=",$1,$3); }
             | expr LESS    expr                { $$ = mknode("<", $1,$3); }
             | expr LESSEQL expr                { $$ = mknode("<=",$1,$3); }
             | expr PLUS    expr                { $$ = mknode("+", $1,$3); }
             | expr MINUS   expr                { $$ = mknode("-", $1,$3); }
             | expr MULTI   expr                { $$ = mknode("*", $1,$3); }
             | expr DIV     expr                { $$ = mknode("/", $1,$3); }
             | unary                               { $$ = $1; } ;

unary        : NOT unary                        { $$ = mknode("!",$2,NULL); }
             | ADDRESS lhs                      { $$ = mknode("&",$2,NULL); }
             | MULTI unary                      { $$ = mknode("",$2,NULL); } / deref */
             | primary                          { $$ = $1; } ;

primary      : LPAREN expr RPAREN               { $$ = $2; }
             | lhs                              { $$ = $1; }
             | literal                          { $$ = $1; }
             | NULLL                            { $$ = mknode("null",NULL,NULL); } ;

literal      : BOOL_LIT   { $$ = mknode(yytext,NULL,NULL); }
             | INT_LIT    { $$ = mknode(yytext,NULL,NULL); }
             | HEX_LIT    { $$ = mknode(yytext,NULL,NULL); }
             | REAL_LIT   { $$ = mknode(yytext,NULL,NULL); }
             | CHAR_LIT   { $$ = mknode(yytext,NULL,NULL); }
             | STRING_LTL { $$ = mknode(yytext,NULL,NULL); } ;

%% /* ================= C‑code ================= */

int main(){ return yyparse(); }