/*Scanner-lex*/
%{
#include<stdio.h>
#include "y.tab.h"
#include <string.h>
#include <stdlib.h>
int yylineno = 1; 

%}
%x COMMENT  // State used when inside a multi-line comment

%%

"#->"                { BEGIN(COMMENT); yylval.string = strdup(yytext); return COMMENT; }
// When '#->' is found, enter COMMENT mode, save the opening marker, and return COMMENT token

<COMMENT>"<-#"       { BEGIN(INITIAL); }
// When '<-#' is found, exit COMMENT mode and return to INITIAL state

<COMMENT>[^\n]+      ;
// Ignore all characters inside the comment except newlines

<COMMENT>\n          { yylineno++; }
// Increment line number for each newline inside the comment

/*---------- Types Lexemes ----------*/
bool                     { return BOOL; }
char                     { return CHAR; }
int                      { return INT; }
real                     { return REAL; }
string                   { return STRING; }
"int*"                   { return INTPTR; }
"char*"                  { return CHARPTR; }
"real*"                  { return REALPTR; }

/*---------- Statement and Loops Lexemes ----------*/
if                       { return IF; }
elif                     { return ELIF; }
else                     { return ELSE; }
while                    { return WHILE; }
for                      { return FOR; }
var                      { return VARIABLE; }
par[0-9]+                { yylval.ival = atoi(yytext+3); return PAR; }

return                   { return RETURN;}
returns                  { return RETURNS;}
null                     { return NULLL; }
do                       { return DO;    }
begin                    { return BEGIN;}
end                      { return END;  }
def                      { return DEF;   }
call                     { return CALL;  }
and                      { return AND;   }
not                      { return NOT;   }
or                       { return OR;    }

/* ---- operators ---- */
"=="                     { return EQL;      }
"!="                     { return NOTEQL;   }
">="                     { return GREATEREQL; }
"<="                     { return LESSEQL;   }
">"                      { return GREATER;   }
"<"                      { return LESS;      }
"="                      { return ASSIGN;    }
"+"                      { return PLUS;      }
"-"                      { return MINUS;     }
"*"                      { return MULTI;     }
"/"                      { return DIV;       }
"&"                      { return ADDRESS;   }
"|"                      { return LENGTH;    }

/* ---- punctuation ---- */
";"                      { return SEMICOLON; }
":"                      { return COLON;      }
","                      { return COMMA;      }
"("                      { return LPAREN;     }
")"                      { return RPAREN;     }
"["                      { return LBRACKET;   }
"]"                      { return RBRACKET;   }


/* ---- literals ---- */

/* Matches the keyword 'true', sets yylval.boolean to 1 (true), and returns BOOL_LIT */
true                     { yylval.boolean = 1; return BOOL_LIT;  }

/* Matches the keyword 'FALSE', sets yylval.boolean to 0 (false), and returns BOOL_LIT */
false                    { yylval.boolean = 0; return BOOL_LIT;  }

/* Matches hexadecimal literals, stores them as a string, returns HEX_LIT */
0[xX][0-9A-Fa-f]+        { yylval.string = strdup(yytext); return HEX_LIT; }

/* Matches integer literals, stores them as a string, returns INT_LIT */
[1-9][0-9]*|0            { yylval.string = strdup(yytext); return INT_LIT; }

/* Matches real numbers, returns REAL_LIT */
[+-]?[0-9]*\.[0-9]+([eE][+-]?[0-9]+)? | [+-]?[0-9]+[eE][+-]?[0-9]+ 
                            { yylval.string = strdup(yytext); return REAL_LIT; }

/* Matches a character literal (e.g. 'a', '\n'), stores it as string, returns CHAR_LIT */
\'[\\]?[ -~]\'           { yylval.string = strdup(yytext); return CHAR_LIT; } //?

/* Matches a string literal surrounded by double quotes on the same line (e.g. "hello"), returns STRING_LTL */
"\""[^"\n]*"\""          { yylval.string = strdup(yytext); return STRING_LTL; }


/* ---- identifiers ---- */

/* Matches identifiers: names that start with a letter followed by letters, digits, or underscores */
[a-zA-Z][a-zA-Z0-9_]*    { yylval.string = strdup(yytext); return IDENT; }


/* Catches any character not matched above, prints error with line number, and returns the character */
.                        { fprintf(stderr,"Unknown char %c at line %d\n", *yytext, yylineno); return yytext[0]; }

%%