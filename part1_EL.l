%{
#include<stdio.h>
#include "part1_EL.tab.h"
#include <string.h>
#include <stdlib.h>
extern YYSTYPE yylval;
int yywrap(void) { return 1; }
%}

%option yylineno

%%

bool                     { return BOOL; }
char                     { return CHAR; }
int                      { return INT; }
real                     { return REAL; }
string                   { return STRING; }
"int*"                   { return INTPTR; }
"char*"                  { return CHARPTR; }
"real*"                  { return REALPTR; }
type                     { return TYPE; }

if                       { return IF; }
elif                     { return ELIF; }
else                     { return ELSE; }
while                    { return WHILE; }
for                      { return FOR; }
var                      { return VARIABLE; }
par[0-9]+                { return PAR; }

return                   { return RETURN;}
returns                  { return RETURNS;}
null                     { return NULLL; }
do                       { return DO;    }
begin                    { return T_BEGIN;}
end                      { return END;  }
def                      { return DEF;   }
call                     { return CALL;  }
and                      { return AND;   }
not                      { return NOT;   }
or                       { return OR;    }

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

";"                      { return ';'; }
":"                      { return ':'; }
","                      { return ','; }
"("                      { return '('; }
")"                      { return ')' ; }
"["                      { return '[';}
"]"                      { return ']';}

"TRUE"                    { return TRUE;  }
"FALSE"                    { return FALSE;  }

0[xX][0-9A-Fa-f]+        { yylval.intVal = (int)strtol(yytext, NULL, 16); return INT_LIT;  }

[1-9][0-9]*|0            { yylval.intVal = atoi(yytext); return INT_LIT; }

[+-]?[0-9]*\.[0-9]+([eE][+-]?[0-9]+)? | [+-]?[0-9]+[eE][+-]?[0-9]+{ yylval.realVal = atof(yytext); return REAL_LIT; }

\'[\\]?[ -~]\'    { yylval.stringVal = strdup(yytext); return CHAR_LIT; }



"\""[^"\n]*"\"" { yylval.stringVal = strdup(yytext); return STRING_LIT; }

[a-zA-Z][a-zA-Z0-9_]* { yylval.stringVal = strdup(yytext); return IDENT; }

#->([^<]|<[^-]|<-+[^#])*<-#    {}

[ \t\n\r]+         { /* Skip whitespace */ }

.                        { fprintf(stderr,"Unknown char %c \n", *yytext); return yytext[0]; }


%%