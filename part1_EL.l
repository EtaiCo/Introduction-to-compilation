%{
#include<stdio.h>
#include "y.tab.h"
#include <string.h>
#include <stdlib.h>

%}
%%
bool                     { return BOOL; }
char                     { return CHAR; }
int                      { return INT; }
real                     { return REAL; }
string                   { return STRING; }
"int*"                   { return INTPTR; }
"char*"                  { return CHARPTR; }
"real*"                  { return REALPTR; }

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
begin                    { return BEGIN;}
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

";"                      { return SEMICOLON; }
":"                      { return COLON;      }
","                      { return COMMA;      }
"("                      { return LPAREN;     }
")"                      { return RPAREN;     }
"["                      { return LBRACKET;   }
"]"                      { return RBRACKET;   }

true                     { yylval.boolean = 1; return BOOL_LIT;  }

false                    { yylval.boolean = 0; return BOOL_LIT;  }

0[xX][0-9A-Fa-f]+        { yylval.string = strdup(yytext); return HEX_LIT; }

[1-9][0-9]*|0            { yylval.string = strdup(yytext); return INT_LIT; }

[+-]?[0-9]*\.[0-9]+([eE][+-]?[0-9]+)? | [+-]?[0-9]+[eE][+-]?[0-9]+{ yylval.string = strdup(yytext); return REAL_LIT; }

\'[\\]?[ -~]\'           { yylval.string = strdup(yytext); return CHAR_LIT; } 

"\""[^"\n]*"\""          { yylval.string = strdup(yytext); return STRING_LTL; }

[a-zA-Z][a-zA-Z0-9_]*    { yylval.string = strdup(yytext); return IDENT; }

#->([^<]|<[^-]|<-+[^#])*<-#    {}

.                        { fprintf(stderr,"Unknown char %c \n", *yytext); return yytext[0]; }

%%