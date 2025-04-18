/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PART1_EL_TAB_H_INCLUDED
# define YY_YY_PART1_EL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 12 "part1_EL.y"

    typedef struct ast_node *node;

#line 53 "part1_EL.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    BOOL = 258,                    /* BOOL  */
    CHAR = 259,                    /* CHAR  */
    INT = 260,                     /* INT  */
    REAL = 261,                    /* REAL  */
    STRING = 262,                  /* STRING  */
    INTPTR = 263,                  /* INTPTR  */
    CHARPTR = 264,                 /* CHARPTR  */
    REALPTR = 265,                 /* REALPTR  */
    IF = 266,                      /* IF  */
    ELIF = 267,                    /* ELIF  */
    ELSE = 268,                    /* ELSE  */
    WHILE = 269,                   /* WHILE  */
    FOR = 270,                     /* FOR  */
    DO = 271,                      /* DO  */
    VARIABLE = 272,                /* VARIABLE  */
    PAR = 273,                     /* PAR  */
    RETURN = 274,                  /* RETURN  */
    RETURNS = 275,                 /* RETURNS  */
    NULLL = 276,                   /* NULLL  */
    KW_BEGIN = 277,                /* KW_BEGIN  */
    END = 278,                     /* END  */
    DEF = 279,                     /* DEF  */
    CALL = 280,                    /* CALL  */
    AND = 281,                     /* AND  */
    OR = 282,                      /* OR  */
    NOT = 283,                     /* NOT  */
    BOOL_LIT = 284,                /* BOOL_LIT  */
    HEX_LIT = 285,                 /* HEX_LIT  */
    INT_LIT = 286,                 /* INT_LIT  */
    REAL_LIT = 287,                /* REAL_LIT  */
    CHAR_LIT = 288,                /* CHAR_LIT  */
    STRING_LTL = 289,              /* STRING_LTL  */
    IDENT = 290,                   /* IDENT  */
    EQL = 291,                     /* EQL  */
    NOTEQL = 292,                  /* NOTEQL  */
    GREATEREQL = 293,              /* GREATEREQL  */
    LESSEQL = 294,                 /* LESSEQL  */
    GREATER = 295,                 /* GREATER  */
    LESS = 296,                    /* LESS  */
    ASSIGN = 297,                  /* ASSIGN  */
    PLUS = 298,                    /* PLUS  */
    MINUS = 299,                   /* MINUS  */
    MULTI = 300,                   /* MULTI  */
    DIV = 301,                     /* DIV  */
    ADDRESS = 302,                 /* ADDRESS  */
    LENGTH = 303,                  /* LENGTH  */
    LPAREN = 304,                  /* LPAREN  */
    RPAREN = 305,                  /* RPAREN  */
    LBRACKET = 306,                /* LBRACKET  */
    RBRACKET = 307,                /* RBRACKET  */
    SEMICOLON = 308,               /* SEMICOLON  */
    COLON = 309,                   /* COLON  */
    COMMA = 310                    /* COMMA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 49 "part1_EL.y"

    node n;
    char *str;
    int   boolean;

#line 131 "part1_EL.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PART1_EL_TAB_H_INCLUDED  */
