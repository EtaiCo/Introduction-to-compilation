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

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT_LIT = 258,                 /* INT_LIT  */
    REAL_LIT = 259,                /* REAL_LIT  */
    CHAR_LIT = 260,                /* CHAR_LIT  */
    STRING_LIT = 261,              /* STRING_LIT  */
    IDENT = 262,                   /* IDENT  */
    BOOL = 263,                    /* BOOL  */
    CHAR = 264,                    /* CHAR  */
    INT = 265,                     /* INT  */
    REAL = 266,                    /* REAL  */
    STRING = 267,                  /* STRING  */
    TYPE = 268,                    /* TYPE  */
    INTPTR = 269,                  /* INTPTR  */
    CHARPTR = 270,                 /* CHARPTR  */
    REALPTR = 271,                 /* REALPTR  */
    IF = 272,                      /* IF  */
    ELIF = 273,                    /* ELIF  */
    ELSE = 274,                    /* ELSE  */
    WHILE = 275,                   /* WHILE  */
    FOR = 276,                     /* FOR  */
    DO = 277,                      /* DO  */
    VARIABLE = 278,                /* VARIABLE  */
    PAR = 279,                     /* PAR  */
    RETURN = 280,                  /* RETURN  */
    RETURNS = 281,                 /* RETURNS  */
    NULLL = 282,                   /* NULLL  */
    T_BEGIN = 283,                 /* T_BEGIN  */
    END = 284,                     /* END  */
    DEF = 285,                     /* DEF  */
    CALL = 286,                    /* CALL  */
    AND = 287,                     /* AND  */
    NOT = 288,                     /* NOT  */
    OR = 289,                      /* OR  */
    EQL = 290,                     /* EQL  */
    NOTEQL = 291,                  /* NOTEQL  */
    GREATEREQL = 292,              /* GREATEREQL  */
    LESSEQL = 293,                 /* LESSEQL  */
    GREATER = 294,                 /* GREATER  */
    LESS = 295,                    /* LESS  */
    ASSIGN = 296,                  /* ASSIGN  */
    PLUS = 297,                    /* PLUS  */
    MINUS = 298,                   /* MINUS  */
    MULTI = 299,                   /* MULTI  */
    DIV = 300,                     /* DIV  */
    ADDRESS = 301,                 /* ADDRESS  */
    LENGTH = 302,                  /* LENGTH  */
    TRUE = 303,                    /* TRUE  */
    FALSE = 304                    /* FALSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "part1_EL.y"

    int  intVal;
    float realVal;
    char  charVal;
    char* stringVal;
    struct node* nodePtr;

#line 121 "part1_EL.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PART1_EL_TAB_H_INCLUDED  */
