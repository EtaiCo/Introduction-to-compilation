/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "part1_EL.y"

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

#line 91 "part1_EL.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "part1_EL.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT_LIT = 3,                    /* INT_LIT  */
  YYSYMBOL_REAL_LIT = 4,                   /* REAL_LIT  */
  YYSYMBOL_CHAR_LIT = 5,                   /* CHAR_LIT  */
  YYSYMBOL_STRING_LIT = 6,                 /* STRING_LIT  */
  YYSYMBOL_IDENT = 7,                      /* IDENT  */
  YYSYMBOL_BOOL = 8,                       /* BOOL  */
  YYSYMBOL_CHAR = 9,                       /* CHAR  */
  YYSYMBOL_INT = 10,                       /* INT  */
  YYSYMBOL_REAL = 11,                      /* REAL  */
  YYSYMBOL_STRING = 12,                    /* STRING  */
  YYSYMBOL_TYPE = 13,                      /* TYPE  */
  YYSYMBOL_INTPTR = 14,                    /* INTPTR  */
  YYSYMBOL_CHARPTR = 15,                   /* CHARPTR  */
  YYSYMBOL_REALPTR = 16,                   /* REALPTR  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_ELIF = 18,                      /* ELIF  */
  YYSYMBOL_ELSE = 19,                      /* ELSE  */
  YYSYMBOL_WHILE = 20,                     /* WHILE  */
  YYSYMBOL_FOR = 21,                       /* FOR  */
  YYSYMBOL_DO = 22,                        /* DO  */
  YYSYMBOL_VARIABLE = 23,                  /* VARIABLE  */
  YYSYMBOL_PAR = 24,                       /* PAR  */
  YYSYMBOL_RETURN = 25,                    /* RETURN  */
  YYSYMBOL_RETURNS = 26,                   /* RETURNS  */
  YYSYMBOL_NULLL = 27,                     /* NULLL  */
  YYSYMBOL_T_BEGIN = 28,                   /* T_BEGIN  */
  YYSYMBOL_END = 29,                       /* END  */
  YYSYMBOL_DEF = 30,                       /* DEF  */
  YYSYMBOL_CALL = 31,                      /* CALL  */
  YYSYMBOL_AND = 32,                       /* AND  */
  YYSYMBOL_NOT = 33,                       /* NOT  */
  YYSYMBOL_OR = 34,                        /* OR  */
  YYSYMBOL_EQL = 35,                       /* EQL  */
  YYSYMBOL_NOTEQL = 36,                    /* NOTEQL  */
  YYSYMBOL_GREATEREQL = 37,                /* GREATEREQL  */
  YYSYMBOL_LESSEQL = 38,                   /* LESSEQL  */
  YYSYMBOL_GREATER = 39,                   /* GREATER  */
  YYSYMBOL_LESS = 40,                      /* LESS  */
  YYSYMBOL_ASSIGN = 41,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 42,                      /* PLUS  */
  YYSYMBOL_MINUS = 43,                     /* MINUS  */
  YYSYMBOL_MULTI = 44,                     /* MULTI  */
  YYSYMBOL_DIV = 45,                       /* DIV  */
  YYSYMBOL_ADDRESS = 46,                   /* ADDRESS  */
  YYSYMBOL_LENGTH = 47,                    /* LENGTH  */
  YYSYMBOL_TRUE = 48,                      /* TRUE  */
  YYSYMBOL_FALSE = 49,                     /* FALSE  */
  YYSYMBOL_50_ = 50,                       /* '('  */
  YYSYMBOL_51_ = 51,                       /* ')'  */
  YYSYMBOL_52_ = 52,                       /* ':'  */
  YYSYMBOL_53_ = 53,                       /* ';'  */
  YYSYMBOL_54_ = 54,                       /* '['  */
  YYSYMBOL_55_ = 55,                       /* ']'  */
  YYSYMBOL_56_ = 56,                       /* ','  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_code = 58,                      /* code  */
  YYSYMBOL_functions = 59,                 /* functions  */
  YYSYMBOL_function = 60,                  /* function  */
  YYSYMBOL_params = 61,                    /* params  */
  YYSYMBOL_param_list = 62,                /* param_list  */
  YYSYMBOL_param = 63,                     /* param  */
  YYSYMBOL_type = 64,                      /* type  */
  YYSYMBOL_ident_entry = 65,               /* ident_entry  */
  YYSYMBOL_idents_list = 66,               /* idents_list  */
  YYSYMBOL_literal = 67,                   /* literal  */
  YYSYMBOL_var = 68,                       /* var  */
  YYSYMBOL_dec_list = 69,                  /* dec_list  */
  YYSYMBOL_dec = 70,                       /* dec  */
  YYSYMBOL_statements = 71,                /* statements  */
  YYSYMBOL_state = 72,                     /* state  */
  YYSYMBOL_assign_state = 73,              /* assign_state  */
  YYSYMBOL_alt_body = 74,                  /* alt_body  */
  YYSYMBOL_if_state = 75,                  /* if_state  */
  YYSYMBOL_elif_list_opt = 76,             /* elif_list_opt  */
  YYSYMBOL_elif_list = 77,                 /* elif_list  */
  YYSYMBOL_else_opt = 78,                  /* else_opt  */
  YYSYMBOL_while_state = 79,               /* while_state  */
  YYSYMBOL_do_while_state = 80,            /* do_while_state  */
  YYSYMBOL_for_state = 81,                 /* for_state  */
  YYSYMBOL_for_h = 82,                     /* for_h  */
  YYSYMBOL_advance_exp = 83,               /* advance_exp  */
  YYSYMBOL_rt_state = 84,                  /* rt_state  */
  YYSYMBOL_bl_state = 85,                  /* bl_state  */
  YYSYMBOL_func_call_state = 86,           /* func_call_state  */
  YYSYMBOL_func_call = 87,                 /* func_call  */
  YYSYMBOL_exp_list = 88,                  /* exp_list  */
  YYSYMBOL_expression = 89                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   608

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  223

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      50,    51,     2,     2,    56,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,    53,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    66,    66,    71,    72,    77,    87,    99,   100,   104,
     105,   109,   115,   116,   117,   118,   119,   120,   121,   122,
     127,   128,   129,   133,   143,   144,   151,   152,   153,   154,
     155,   156,   158,   163,   164,   168,   169,   173,   180,   181,
     182,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     201,   206,   213,   218,   224,   230,   237,   243,   253,   254,
     260,   270,   271,   275,   279,   286,   287,   292,   298,   306,
     308,   314,   323,   339,   344,   345,   352,   353,   360,   362,
     368,   369,   375,   378,   381,   383,   386,   389,   390,   391,
     392,   395,   396,   397,   398,   399,   402,   405,   406,   407,
     408,   409,   410,   413,   416,   417,   419,   420,   421,   424
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT_LIT", "REAL_LIT",
  "CHAR_LIT", "STRING_LIT", "IDENT", "BOOL", "CHAR", "INT", "REAL",
  "STRING", "TYPE", "INTPTR", "CHARPTR", "REALPTR", "IF", "ELIF", "ELSE",
  "WHILE", "FOR", "DO", "VARIABLE", "PAR", "RETURN", "RETURNS", "NULLL",
  "T_BEGIN", "END", "DEF", "CALL", "AND", "NOT", "OR", "EQL", "NOTEQL",
  "GREATEREQL", "LESSEQL", "GREATER", "LESS", "ASSIGN", "PLUS", "MINUS",
  "MULTI", "DIV", "ADDRESS", "LENGTH", "TRUE", "FALSE", "'('", "')'",
  "':'", "';'", "'['", "']'", "','", "$accept", "code", "functions",
  "function", "params", "param_list", "param", "type", "ident_entry",
  "idents_list", "literal", "var", "dec_list", "dec", "statements",
  "state", "assign_state", "alt_body", "if_state", "elif_list_opt",
  "elif_list", "else_opt", "while_state", "do_while_state", "for_state",
  "for_h", "advance_exp", "rt_state", "bl_state", "func_call_state",
  "func_call", "exp_list", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-115)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,    28,    44,  -115,    12,    -5,  -115,  -115,    24,    42,
      11,  -115,    10,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,    35,    36,    24,    82,    -1,  -115,  -115,    79,    42,
      65,    42,  -115,    79,    71,   249,    47,  -115,    73,   -35,
     160,   160,    52,    51,   160,   249,    98,    99,  -115,    80,
      81,   249,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
      54,   110,   249,   128,   160,  -115,  -115,  -115,  -115,    62,
     160,   160,   191,   160,   111,  -115,  -115,   160,  -115,   463,
     482,   112,    86,   249,   323,   101,    89,   100,   249,  -115,
    -115,  -115,   -26,    87,    92,   117,    94,   211,    95,   343,
     295,   160,  -115,   -29,    62,  -115,  -115,   102,   520,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   249,   249,   113,   249,  -115,   131,  -115,  -115,  -115,
      78,   160,   123,   109,   153,   110,  -115,  -115,  -115,   -13,
    -115,  -115,   127,   309,  -115,  -115,   563,   552,   188,   188,
      23,    23,    23,    23,   -29,   -29,  -115,  -115,   151,  -115,
     160,   277,  -115,   160,  -115,   119,   280,   363,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,   118,  -115,  -115,
     242,  -115,   160,   162,  -115,   383,   249,  -115,   403,  -115,
     160,  -115,   130,   126,   134,   135,   423,   501,   137,  -115,
     160,   154,  -115,  -115,   184,  -115,  -115,  -115,  -115,   249,
     249,   443,  -115,  -115,   151,  -115,   185,  -115,   158,   149,
     160,  -115,   538
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     1,     3,     7,     0,
       0,     8,     9,    14,    13,    12,    16,    15,    18,    17,
      19,     0,     0,     0,     0,    33,    10,    11,     0,     0,
       0,     0,    34,    35,    33,    38,     0,    36,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,    41,     0,
       0,    38,    42,    43,    44,    46,    45,    48,    47,    49,
       0,     0,    38,     0,     0,    82,    83,    85,    84,    86,
       0,     0,     0,     0,     0,   106,   107,     0,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     6,
      40,    76,    21,    24,     0,     0,     0,     0,   109,     0,
       0,     0,    95,    91,    86,    94,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    58,     0,    47,    73,    74,
       0,     0,     0,     0,     0,     0,    37,     5,    54,    86,
      77,    50,     0,     0,   108,    96,   104,   105,    97,    98,
      99,   100,   101,   102,    87,    88,    89,    90,    61,    67,
       0,     0,    69,     0,    78,     0,    80,     0,    75,    26,
      31,    29,    30,    32,    27,    28,    20,     0,    25,    53,
       0,   103,     0,    65,    62,     0,    38,    70,     0,    79,
       0,    52,    22,    82,    85,    84,     0,     0,     0,    60,
       0,     0,    68,    81,     0,    55,    51,    56,    57,     0,
       0,     0,    74,    23,    63,    66,     0,    64,     0,     0,
       0,    71,    72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,   197,    13,  -115,   179,  -115,     5,  -115,    70,
    -115,   -20,   178,  -115,   -42,   -33,  -115,  -114,  -115,  -115,
       6,  -115,  -115,  -115,  -115,  -115,  -115,  -115,    -2,  -115,
     -24,    22,   -40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    48,    10,    11,    12,    21,    93,    94,
     176,    49,    32,    33,    50,   125,    52,   126,    53,   183,
     184,   199,    54,    55,    56,    82,   219,    57,   127,    59,
      78,   165,   106
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      79,    80,    51,    85,    84,    30,    63,   158,   159,    90,
     162,    60,    51,     4,    38,   119,   120,     4,    51,    64,
      95,    60,    28,    99,   100,    29,   133,    60,   134,    51,
     102,   103,   105,    58,    34,     5,    36,   108,    60,    98,
     179,   101,     1,    58,     6,     8,   132,   187,     9,    58,
      13,    14,    15,    16,    17,    51,    18,    19,    20,    60,
      58,   143,    22,    23,    60,   117,   118,   119,   120,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,    65,    66,    67,    68,    69,    58,    24,    25,    27,
     166,   167,    31,    35,    28,   214,   215,    60,    60,    61,
      60,    62,    81,    83,   161,    86,    87,    91,    88,    46,
      89,    70,   169,   170,   171,   172,   101,    92,   107,   123,
     185,    71,    72,   188,    73,    74,    75,    76,    77,   164,
     129,    65,    66,    67,    68,    69,   173,    60,   124,   130,
     196,   131,   197,   135,   201,   136,   137,   138,   140,   144,
     166,   163,   168,    51,   160,    96,   177,   174,   175,    46,
     211,    70,    60,    65,    66,    67,    68,    69,   180,   182,
     189,    71,    72,   192,    97,    74,    75,    76,    77,   205,
     222,   198,   204,   212,    58,    60,    60,   206,   207,   210,
     213,    46,   218,    70,    65,    66,    67,    68,   104,   220,
     221,     7,    26,    71,    72,   178,    73,    74,    75,    76,
      77,    37,   203,     0,    65,    66,    67,    68,   139,     0,
     217,     0,    46,     0,    70,   113,   114,   115,   116,     0,
     117,   118,   119,   120,    71,    72,     0,    73,    74,    75,
      76,    77,    46,     0,    70,   193,    66,   194,   195,    69,
       0,     0,     0,     0,    71,    72,    39,    73,    74,    75,
      76,    77,     0,     0,     0,     0,    40,     0,     0,    41,
      42,    43,    28,    46,    44,    70,     0,    45,     0,     1,
      46,     0,     0,     0,    39,    71,    72,     0,    73,    74,
      75,    76,    77,    47,    40,     0,     0,    41,    42,    43,
      28,     0,    44,     0,     0,   186,     0,     1,    46,     0,
       0,     0,   109,     0,   110,   111,   112,   113,   114,   115,
     116,    47,   117,   118,   119,   120,     0,   109,     0,   110,
     111,   112,   113,   114,   115,   116,   190,   117,   118,   119,
     120,   109,     0,   110,   111,   112,   113,   114,   115,   116,
     142,   117,   118,   119,   120,   109,     0,   110,   111,   112,
     113,   114,   115,   116,   181,   117,   118,   119,   120,     0,
       0,     0,     0,     0,     0,   109,   128,   110,   111,   112,
     113,   114,   115,   116,     0,   117,   118,   119,   120,     0,
       0,     0,     0,     0,     0,   109,   141,   110,   111,   112,
     113,   114,   115,   116,     0,   117,   118,   119,   120,     0,
       0,     0,     0,     0,     0,   109,   191,   110,   111,   112,
     113,   114,   115,   116,     0,   117,   118,   119,   120,     0,
       0,     0,     0,     0,     0,   109,   200,   110,   111,   112,
     113,   114,   115,   116,     0,   117,   118,   119,   120,     0,
       0,     0,     0,     0,     0,   109,   202,   110,   111,   112,
     113,   114,   115,   116,     0,   117,   118,   119,   120,     0,
       0,     0,     0,     0,     0,   109,   208,   110,   111,   112,
     113,   114,   115,   116,     0,   117,   118,   119,   120,     0,
       0,     0,     0,     0,     0,   109,   216,   110,   111,   112,
     113,   114,   115,   116,     0,   117,   118,   119,   120,     0,
       0,     0,     0,     0,   109,   121,   110,   111,   112,   113,
     114,   115,   116,     0,   117,   118,   119,   120,     0,     0,
       0,     0,     0,   109,   122,   110,   111,   112,   113,   114,
     115,   116,     0,   117,   118,   119,   120,     0,     0,     0,
       0,     0,   109,   209,   110,   111,   112,   113,   114,   115,
     116,     0,   117,   118,   119,   120,     0,     0,     0,     0,
     109,   145,   110,   111,   112,   113,   114,   115,   116,     0,
     117,   118,   119,   120,   109,     0,     0,   111,   112,   113,
     114,   115,   116,     0,   117,   118,   119,   120,   111,   112,
     113,   114,   115,   116,     0,   117,   118,   119,   120
};

static const yytype_int16 yycheck[] =
{
      40,    41,    35,    45,    44,    25,    41,   121,   122,    51,
     124,    35,    45,     0,    34,    44,    45,     4,    51,    54,
      62,    45,    23,    63,    64,    26,    52,    51,    54,    62,
      70,    71,    72,    35,    29,     7,    31,    77,    62,    63,
      53,    54,    30,    45,     0,    50,    88,   161,    24,    51,
       8,     9,    10,    11,    12,    88,    14,    15,    16,    83,
      62,   101,    51,    53,    88,    42,    43,    44,    45,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,     3,     4,     5,     6,     7,    88,    52,    52,     7,
     130,   131,    13,    28,    23,   209,   210,   121,   122,    52,
     124,    28,    50,    52,   124,     7,     7,    53,    28,    31,
      29,    33,     3,     4,     5,     6,    54,     7,     7,     7,
     160,    43,    44,   163,    46,    47,    48,    49,    50,    51,
      29,     3,     4,     5,     6,     7,    27,   161,    52,    50,
     180,    41,   182,    56,   186,    53,    29,    53,    53,    47,
     190,    20,    29,   186,    41,    27,     3,    48,    49,    31,
     200,    33,   186,     3,     4,     5,     6,     7,    41,    18,
      51,    43,    44,    55,    46,    47,    48,    49,    50,    53,
     220,    19,    52,    29,   186,   209,   210,    53,    53,    52,
       6,    31,     7,    33,     3,     4,     5,     6,     7,    41,
      51,     4,    23,    43,    44,   135,    46,    47,    48,    49,
      50,    33,   190,    -1,     3,     4,     5,     6,     7,    -1,
     214,    -1,    31,    -1,    33,    37,    38,    39,    40,    -1,
      42,    43,    44,    45,    43,    44,    -1,    46,    47,    48,
      49,    50,    31,    -1,    33,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    43,    44,     7,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    -1,    17,    -1,    -1,    20,
      21,    22,    23,    31,    25,    33,    -1,    28,    -1,    30,
      31,    -1,    -1,    -1,     7,    43,    44,    -1,    46,    47,
      48,    49,    50,    44,    17,    -1,    -1,    20,    21,    22,
      23,    -1,    25,    -1,    -1,    28,    -1,    30,    31,    -1,
      -1,    -1,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    44,    42,    43,    44,    45,    -1,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    56,    42,    43,    44,
      45,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      55,    42,    43,    44,    45,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    55,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    53,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    53,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    53,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    53,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    53,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    53,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    53,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    32,    52,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    32,    52,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    43,    44,    45,    -1,    -1,    -1,
      -1,    -1,    32,    52,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    43,    44,    45,    -1,    -1,    -1,    -1,
      32,    51,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    43,    44,    45,    32,    -1,    -1,    35,    36,    37,
      38,    39,    40,    -1,    42,    43,    44,    45,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    44,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,    58,    59,    60,     7,     0,    59,    50,    24,
      61,    62,    63,     8,     9,    10,    11,    12,    14,    15,
      16,    64,    51,    53,    52,    52,    62,     7,    23,    26,
      68,    13,    69,    70,    64,    28,    64,    69,    68,     7,
      17,    20,    21,    22,    25,    28,    31,    44,    60,    68,
      71,    72,    73,    75,    79,    80,    81,    84,    85,    86,
      87,    52,    28,    41,    54,     3,     4,     5,     6,     7,
      33,    43,    44,    46,    47,    48,    49,    50,    87,    89,
      89,    50,    82,    52,    89,    71,     7,     7,    28,    29,
      71,    53,     7,    65,    66,    71,    27,    46,    87,    89,
      89,    54,    89,    89,     7,    89,    89,     7,    89,    32,
      34,    35,    36,    37,    38,    39,    40,    42,    43,    44,
      45,    52,    52,     7,    52,    72,    74,    85,    53,    29,
      50,    41,    71,    52,    54,    56,    53,    29,    53,     7,
      53,    53,    55,    89,    47,    51,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    74,    74,
      41,    68,    74,    20,    51,    88,    89,    89,    29,     3,
       4,     5,     6,    27,    48,    49,    67,     3,    66,    53,
      41,    55,    18,    76,    77,    89,    28,    74,    89,    51,
      56,    53,    55,     3,     5,     6,    89,    89,    19,    78,
      53,    71,    53,    88,    52,    53,    53,    53,    53,    52,
      52,    89,    29,     6,    74,    74,    53,    77,     7,    83,
      41,    51,    89
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    63,    64,    64,    64,    64,    64,    64,    64,    64,
      65,    65,    65,    65,    66,    66,    67,    67,    67,    67,
      67,    67,    67,    68,    68,    69,    69,    70,    71,    71,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    73,    73,    73,    73,    73,    73,    74,    74,
      75,    76,    76,    77,    77,    78,    78,    79,    80,    81,
      81,    82,    83,    84,    85,    85,    86,    86,    87,    87,
      88,    88,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,    12,    10,     0,     1,     1,
       3,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     4,     6,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     0,     2,     1,     2,     5,     0,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     7,     5,     5,     4,     7,     7,     7,     1,     1,
       6,     0,     1,     4,     5,     0,     3,     4,     6,     4,
       5,     9,     3,     3,     3,     4,     2,     4,     4,     5,
       1,     3,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     2,     2,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     4,     3,     3,     1,     1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* code: functions  */
#line 66 "part1_EL.y"
              {node *root = mknode("CODE", (yyvsp[0].nodePtr), NULL); printTree(root, 0);}
#line 1392 "part1_EL.tab.c"
    break;

  case 3: /* functions: function functions  */
#line 71 "part1_EL.y"
                                           { (yyval.nodePtr) = mknode("FUNCS",(yyvsp[-1].nodePtr),(yyvsp[0].nodePtr)); }
#line 1398 "part1_EL.tab.c"
    break;

  case 4: /* functions: function  */
#line 72 "part1_EL.y"
                                             { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1404 "part1_EL.tab.c"
    break;

  case 5: /* function: DEF IDENT '(' params ')' ':' RETURNS type var T_BEGIN statements END  */
#line 78 "part1_EL.y"
    {
        node* idN = mknode((yyvsp[-10].stringVal), NULL, NULL);
        node* paramsN = mknode("PARAMS", (yyvsp[-8].nodePtr), NULL);
        node* returnsN = mknode("RETURNS", (yyvsp[-4].nodePtr), NULL);
        node* bodyN = mknode("BODY", (yyvsp[-3].nodePtr), (yyvsp[-1].nodePtr));
        node* defBodyN = mknode("DEF_BODY", returnsN, bodyN);
        (yyval.nodePtr) = mknode("FUNCTION", idN, mknode("FUNC_IN", paramsN, defBodyN));
    }
#line 1417 "part1_EL.tab.c"
    break;

  case 6: /* function: DEF IDENT '(' params ')' ':' var T_BEGIN statements END  */
#line 88 "part1_EL.y"
    {
        node* idN = mknode((yyvsp[-8].stringVal), NULL, NULL);
        node* paramsN = mknode("PARAMS", (yyvsp[-6].nodePtr), NULL);
        node* bodyN = mknode("BODY", (yyvsp[-3].nodePtr), (yyvsp[-1].nodePtr));
        (yyval.nodePtr) = mknode("PROC", idN, mknode("PROC_IN", paramsN, bodyN));
    }
#line 1428 "part1_EL.tab.c"
    break;

  case 7: /* params: %empty  */
#line 99 "part1_EL.y"
    { (yyval.nodePtr) = NULL; }
#line 1434 "part1_EL.tab.c"
    break;

  case 8: /* params: param_list  */
#line 100 "part1_EL.y"
                                      { (yyval.nodePtr) = (yyvsp[0].nodePtr);   }
#line 1440 "part1_EL.tab.c"
    break;

  case 9: /* param_list: param  */
#line 104 "part1_EL.y"
                                    { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1446 "part1_EL.tab.c"
    break;

  case 10: /* param_list: param ';' param_list  */
#line 105 "part1_EL.y"
                                  { (yyval.nodePtr) = mknode("PARAMS",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1452 "part1_EL.tab.c"
    break;

  case 11: /* param: PAR type ':' IDENT  */
#line 109 "part1_EL.y"
                               {(yyval.nodePtr)=mknode("PARAM",(yyvsp[-2].nodePtr),mknode((yyvsp[0].stringVal),NULL,NULL));}
#line 1458 "part1_EL.tab.c"
    break;

  case 12: /* type: INT  */
#line 115 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("INT",NULL,NULL);  }
#line 1464 "part1_EL.tab.c"
    break;

  case 13: /* type: CHAR  */
#line 116 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("CHAR",NULL,NULL); }
#line 1470 "part1_EL.tab.c"
    break;

  case 14: /* type: BOOL  */
#line 117 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("BOOL",NULL,NULL); }
#line 1476 "part1_EL.tab.c"
    break;

  case 15: /* type: STRING  */
#line 118 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("STRING",NULL,NULL);}
#line 1482 "part1_EL.tab.c"
    break;

  case 16: /* type: REAL  */
#line 119 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("REAL",NULL,NULL); }
#line 1488 "part1_EL.tab.c"
    break;

  case 17: /* type: CHARPTR  */
#line 120 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("CHARPTR",NULL,NULL);}
#line 1494 "part1_EL.tab.c"
    break;

  case 18: /* type: INTPTR  */
#line 121 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("INTPTR",NULL,NULL);}
#line 1500 "part1_EL.tab.c"
    break;

  case 19: /* type: REALPTR  */
#line 122 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("REALPTR",NULL,NULL);}
#line 1506 "part1_EL.tab.c"
    break;

  case 20: /* ident_entry: IDENT ':' literal  */
#line 127 "part1_EL.y"
                                   { (yyval.nodePtr) = mknode("VAR_ASSIGN", mknode("IDENT", mknode((yyvsp[-2].stringVal),NULL,NULL), NULL), (yyvsp[0].nodePtr)); }
#line 1512 "part1_EL.tab.c"
    break;

  case 21: /* ident_entry: IDENT  */
#line 128 "part1_EL.y"
                                   { (yyval.nodePtr) = mknode("VAR_DECL", mknode("IDENT", mknode((yyvsp[0].stringVal),NULL,NULL), NULL), NULL); }
#line 1518 "part1_EL.tab.c"
    break;

  case 22: /* ident_entry: IDENT '[' INT_LIT ']'  */
#line 129 "part1_EL.y"
                                   { 
        char buf[32]; sprintf(buf, "%d", (yyvsp[-1].intVal));
        (yyval.nodePtr) = mknode("ARRAY_DECL", mknode("IDENT", mknode((yyvsp[-3].stringVal), NULL, NULL), NULL), mknode(buf, NULL, NULL)); 
    }
#line 1527 "part1_EL.tab.c"
    break;

  case 23: /* ident_entry: IDENT '[' INT_LIT ']' ':' STRING_LIT  */
#line 133 "part1_EL.y"
                                           {
        char buf[32]; sprintf(buf, "%d", (yyvsp[-3].intVal));
        (yyval.nodePtr) = mknode("ARRAY_INIT", 
            mknode("ARRAY_DECL", mknode("IDENT", mknode((yyvsp[-5].stringVal), NULL, NULL), NULL), mknode(buf, NULL, NULL)), 
            mknode((yyvsp[0].stringVal), NULL, NULL));
    }
#line 1538 "part1_EL.tab.c"
    break;

  case 24: /* idents_list: ident_entry  */
#line 143 "part1_EL.y"
                                          { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1544 "part1_EL.tab.c"
    break;

  case 25: /* idents_list: ident_entry ',' idents_list  */
#line 144 "part1_EL.y"
                                          { (yyval.nodePtr) = mknode("ID_LIST",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1550 "part1_EL.tab.c"
    break;

  case 26: /* literal: INT_LIT  */
#line 151 "part1_EL.y"
                       { char ibuf[32]; sprintf(ibuf,"%d",(yyvsp[0].intVal)); (yyval.nodePtr) = mknode("INT", mknode(ibuf,NULL,NULL), NULL); }
#line 1556 "part1_EL.tab.c"
    break;

  case 27: /* literal: TRUE  */
#line 152 "part1_EL.y"
                       { (yyval.nodePtr) = mknode("BOOL", mknode("true", NULL, NULL), NULL); }
#line 1562 "part1_EL.tab.c"
    break;

  case 28: /* literal: FALSE  */
#line 153 "part1_EL.y"
                       { (yyval.nodePtr) = mknode("BOOL", mknode("false", NULL, NULL), NULL); }
#line 1568 "part1_EL.tab.c"
    break;

  case 29: /* literal: CHAR_LIT  */
#line 154 "part1_EL.y"
                       { char cbuf[2] = {(yyvsp[0].charVal),'\0'}; (yyval.nodePtr) = mknode("CHAR", mknode(cbuf,NULL,NULL), NULL); }
#line 1574 "part1_EL.tab.c"
    break;

  case 30: /* literal: STRING_LIT  */
#line 155 "part1_EL.y"
                       { (yyval.nodePtr) = mknode("STRING", mknode((yyvsp[0].stringVal), NULL, NULL), NULL); }
#line 1580 "part1_EL.tab.c"
    break;

  case 31: /* literal: REAL_LIT  */
#line 156 "part1_EL.y"
                       { char r[64]; sprintf(r,"%f",(yyvsp[0].realVal));
                        (yyval.nodePtr) = mknode("REAL", mknode(r,NULL,NULL), NULL); }
#line 1587 "part1_EL.tab.c"
    break;

  case 32: /* literal: NULLL  */
#line 158 "part1_EL.y"
                       { (yyval.nodePtr) = mknode("NULL", NULL, NULL); }
#line 1593 "part1_EL.tab.c"
    break;

  case 33: /* var: %empty  */
#line 163 "part1_EL.y"
    { (yyval.nodePtr) = NULL; }
#line 1599 "part1_EL.tab.c"
    break;

  case 34: /* var: VARIABLE dec_list  */
#line 164 "part1_EL.y"
                                       { (yyval.nodePtr) = mknode("VAR",(yyvsp[0].nodePtr),NULL); }
#line 1605 "part1_EL.tab.c"
    break;

  case 35: /* dec_list: dec  */
#line 168 "part1_EL.y"
                               { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1611 "part1_EL.tab.c"
    break;

  case 36: /* dec_list: dec dec_list  */
#line 169 "part1_EL.y"
                          { (yyval.nodePtr) = mknode("DECS",(yyvsp[-1].nodePtr),(yyvsp[0].nodePtr)); }
#line 1617 "part1_EL.tab.c"
    break;

  case 37: /* dec: TYPE type ':' idents_list ';'  */
#line 173 "part1_EL.y"
                                       { (yyval.nodePtr) = mknode("DECL", (yyvsp[-3].nodePtr), (yyvsp[-1].nodePtr)); }
#line 1623 "part1_EL.tab.c"
    break;

  case 38: /* statements: %empty  */
#line 180 "part1_EL.y"
     {(yyval.nodePtr) = mknode("", NULL,NULL);}
#line 1629 "part1_EL.tab.c"
    break;

  case 39: /* statements: state  */
#line 181 "part1_EL.y"
                    {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1635 "part1_EL.tab.c"
    break;

  case 40: /* statements: state statements  */
#line 182 "part1_EL.y"
                               {(yyval.nodePtr) = mknode("statements", (yyvsp[-1].nodePtr), (yyvsp[0].nodePtr));}
#line 1641 "part1_EL.tab.c"
    break;

  case 41: /* state: function  */
#line 188 "part1_EL.y"
                     {(yyval.nodePtr)=(yyvsp[0].nodePtr);}
#line 1647 "part1_EL.tab.c"
    break;

  case 42: /* state: assign_state  */
#line 189 "part1_EL.y"
                           {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1653 "part1_EL.tab.c"
    break;

  case 43: /* state: if_state  */
#line 190 "part1_EL.y"
                       {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1659 "part1_EL.tab.c"
    break;

  case 44: /* state: while_state  */
#line 191 "part1_EL.y"
                          {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1665 "part1_EL.tab.c"
    break;

  case 45: /* state: for_state  */
#line 192 "part1_EL.y"
                        {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1671 "part1_EL.tab.c"
    break;

  case 46: /* state: do_while_state  */
#line 193 "part1_EL.y"
                             {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1677 "part1_EL.tab.c"
    break;

  case 47: /* state: bl_state  */
#line 194 "part1_EL.y"
                       {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1683 "part1_EL.tab.c"
    break;

  case 48: /* state: rt_state  */
#line 195 "part1_EL.y"
                       {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1689 "part1_EL.tab.c"
    break;

  case 49: /* state: func_call_state  */
#line 196 "part1_EL.y"
                              {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1695 "part1_EL.tab.c"
    break;

  case 50: /* assign_state: IDENT ASSIGN expression ';'  */
#line 202 "part1_EL.y"
        { (yyval.nodePtr) = mknode("assign",
                      mknode((yyvsp[-3].stringVal),NULL,NULL), (yyvsp[-1].nodePtr)); }
#line 1702 "part1_EL.tab.c"
    break;

  case 51: /* assign_state: IDENT '[' expression ']' ASSIGN CHAR_LIT ';'  */
#line 206 "part1_EL.y"
                                                   {
          char cbuf[2]={(yyvsp[-1].charVal),'\0'};
          (yyval.nodePtr) = mknode("array_assign",
                      mknode((yyvsp[-6].stringVal),(yyvsp[-4].nodePtr),NULL),
                      mknode(cbuf,NULL,NULL)); }
#line 1712 "part1_EL.tab.c"
    break;

  case 52: /* assign_state: MULTI IDENT ASSIGN expression ';'  */
#line 213 "part1_EL.y"
                                        {
          (yyval.nodePtr) = mknode("pointer_assign",
                      mknode((yyvsp[-3].stringVal),NULL,NULL), (yyvsp[-1].nodePtr)); }
#line 1720 "part1_EL.tab.c"
    break;

  case 53: /* assign_state: IDENT ASSIGN ADDRESS IDENT ';'  */
#line 218 "part1_EL.y"
                                     {
          (yyval.nodePtr) = mknode("adder_assign",
                      mknode((yyvsp[-4].stringVal),NULL,NULL),
                      mknode((yyvsp[-1].stringVal),NULL,NULL)); }
#line 1729 "part1_EL.tab.c"
    break;

  case 54: /* assign_state: IDENT ASSIGN NULLL ';'  */
#line 224 "part1_EL.y"
                             {
          (yyval.nodePtr) = mknode("null_assign",
                      mknode((yyvsp[-3].stringVal),NULL,NULL),
                      mknode("null",NULL,NULL)); }
#line 1738 "part1_EL.tab.c"
    break;

  case 55: /* assign_state: IDENT '[' expression ']' ASSIGN INT_LIT ';'  */
#line 230 "part1_EL.y"
                                                  {
          char buf[32]; sprintf(buf,"%d",(yyvsp[-1].intVal));
          (yyval.nodePtr) = mknode("array_assign",
                      mknode((yyvsp[-6].stringVal),(yyvsp[-4].nodePtr),NULL),
                      mknode(buf,NULL,NULL)); }
#line 1748 "part1_EL.tab.c"
    break;

  case 56: /* assign_state: IDENT '[' expression ']' ASSIGN STRING_LIT ';'  */
#line 237 "part1_EL.y"
                                                     {
          (yyval.nodePtr) = mknode("array_assign",
                      mknode((yyvsp[-6].stringVal),(yyvsp[-4].nodePtr),NULL),
                      mknode((yyvsp[-1].stringVal),NULL,NULL)); }
#line 1757 "part1_EL.tab.c"
    break;

  case 57: /* assign_state: IDENT '[' expression ']' ASSIGN expression ';'  */
#line 243 "part1_EL.y"
                                                     {
          (yyval.nodePtr) = mknode("array_assign",
                      mknode((yyvsp[-6].stringVal),(yyvsp[-4].nodePtr),NULL), (yyvsp[-1].nodePtr)); }
#line 1765 "part1_EL.tab.c"
    break;

  case 58: /* alt_body: state  */
#line 253 "part1_EL.y"
                         { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1771 "part1_EL.tab.c"
    break;

  case 59: /* alt_body: bl_state  */
#line 254 "part1_EL.y"
                         { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1777 "part1_EL.tab.c"
    break;

  case 60: /* if_state: IF expression ':' alt_body elif_list_opt else_opt  */
#line 262 "part1_EL.y"
              { (yyval.nodePtr) = mknode("if_full",
                           mknode("cond" ,(yyvsp[-4].nodePtr) , NULL),
                           mknode("then" ,(yyvsp[-2].nodePtr) ,
                           mknode("elifs",(yyvsp[-1].nodePtr) ,
                           mknode("else" ,(yyvsp[0].nodePtr) ,NULL)))); }
#line 1787 "part1_EL.tab.c"
    break;

  case 61: /* elif_list_opt: %empty  */
#line 270 "part1_EL.y"
                                { (yyval.nodePtr) = NULL; }
#line 1793 "part1_EL.tab.c"
    break;

  case 62: /* elif_list_opt: elif_list  */
#line 271 "part1_EL.y"
                                { (yyval.nodePtr) = (yyvsp[0].nodePtr);   }
#line 1799 "part1_EL.tab.c"
    break;

  case 63: /* elif_list: ELIF expression ':' alt_body  */
#line 276 "part1_EL.y"
              { (yyval.nodePtr) = mknode("elif",
                           mknode("cond",(yyvsp[-2].nodePtr),NULL),
                           mknode("then",(yyvsp[0].nodePtr),NULL)); }
#line 1807 "part1_EL.tab.c"
    break;

  case 64: /* elif_list: ELIF expression ':' alt_body elif_list  */
#line 280 "part1_EL.y"
              { (yyval.nodePtr) = mknode("elif",
                           mknode("cond",(yyvsp[-3].nodePtr),NULL),
                           mknode("then",(yyvsp[-1].nodePtr),(yyvsp[0].nodePtr))); }
#line 1815 "part1_EL.tab.c"
    break;

  case 65: /* else_opt: %empty  */
#line 286 "part1_EL.y"
                                { (yyval.nodePtr) = NULL; }
#line 1821 "part1_EL.tab.c"
    break;

  case 66: /* else_opt: ELSE ':' alt_body  */
#line 287 "part1_EL.y"
                                { (yyval.nodePtr) = (yyvsp[0].nodePtr);   }
#line 1827 "part1_EL.tab.c"
    break;

  case 67: /* while_state: WHILE expression ':' alt_body  */
#line 293 "part1_EL.y"
              { (yyval.nodePtr) = mknode("while",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1833 "part1_EL.tab.c"
    break;

  case 68: /* do_while_state: DO ':' alt_body WHILE expression ';'  */
#line 299 "part1_EL.y"
              { (yyval.nodePtr) = mknode("do_while",(yyvsp[-3].nodePtr),
                           mknode("condition",(yyvsp[-1].nodePtr),NULL)); }
#line 1840 "part1_EL.tab.c"
    break;

  case 69: /* for_state: FOR for_h ':' alt_body  */
#line 307 "part1_EL.y"
              { (yyval.nodePtr) = mknode("for",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1846 "part1_EL.tab.c"
    break;

  case 70: /* for_state: FOR for_h ':' var alt_body  */
#line 309 "part1_EL.y"
              { (yyval.nodePtr) = mknode("for",(yyvsp[-3].nodePtr),
                           mknode("block",(yyvsp[0].nodePtr),(yyvsp[-1].nodePtr))); }
#line 1853 "part1_EL.tab.c"
    break;

  case 71: /* for_h: '(' IDENT ASSIGN expression ';' expression ';' advance_exp ')'  */
#line 316 "part1_EL.y"
                                                    {
          (yyval.nodePtr) = mknode("for_header",
                      mknode("init",mknode((yyvsp[-7].stringVal),NULL,NULL),(yyvsp[-5].nodePtr)),
                      mknode("loop",(yyvsp[-3].nodePtr),(yyvsp[-1].nodePtr))); }
#line 1862 "part1_EL.tab.c"
    break;

  case 72: /* advance_exp: IDENT ASSIGN expression  */
#line 323 "part1_EL.y"
                                             {
          (yyval.nodePtr) = mknode("update",
                      mknode((yyvsp[-2].stringVal),NULL,NULL),(yyvsp[0].nodePtr)); }
#line 1870 "part1_EL.tab.c"
    break;

  case 73: /* rt_state: RETURN expression ';'  */
#line 339 "part1_EL.y"
                                                 { (yyval.nodePtr) = mknode("return",(yyvsp[-1].nodePtr),NULL); }
#line 1876 "part1_EL.tab.c"
    break;

  case 74: /* bl_state: T_BEGIN statements END  */
#line 344 "part1_EL.y"
                                             { (yyval.nodePtr) = mknode("block",(yyvsp[-1].nodePtr),NULL); }
#line 1882 "part1_EL.tab.c"
    break;

  case 75: /* bl_state: var T_BEGIN statements END  */
#line 345 "part1_EL.y"
                                               { (yyval.nodePtr) = mknode("block",(yyvsp[-1].nodePtr),(yyvsp[-3].nodePtr)); }
#line 1888 "part1_EL.tab.c"
    break;

  case 76: /* func_call_state: func_call ';'  */
#line 352 "part1_EL.y"
                                              { (yyval.nodePtr) = (yyvsp[-1].nodePtr); }
#line 1894 "part1_EL.tab.c"
    break;

  case 77: /* func_call_state: IDENT ASSIGN func_call ';'  */
#line 353 "part1_EL.y"
                                          {
          (yyval.nodePtr) = mknode("assign",
                      mknode((yyvsp[-3].stringVal),NULL,NULL),(yyvsp[-1].nodePtr)); }
#line 1902 "part1_EL.tab.c"
    break;

  case 78: /* func_call: CALL IDENT '(' ')'  */
#line 360 "part1_EL.y"
                                              {
          (yyval.nodePtr) = mknode("call",mknode((yyvsp[-2].stringVal),NULL,NULL),NULL); }
#line 1909 "part1_EL.tab.c"
    break;

  case 79: /* func_call: CALL IDENT '(' exp_list ')'  */
#line 362 "part1_EL.y"
                                             {
          (yyval.nodePtr) = mknode("call",mknode((yyvsp[-3].stringVal),NULL,NULL),(yyvsp[-1].nodePtr)); }
#line 1916 "part1_EL.tab.c"
    break;

  case 80: /* exp_list: expression  */
#line 368 "part1_EL.y"
                                                   { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1922 "part1_EL.tab.c"
    break;

  case 81: /* exp_list: expression ',' exp_list  */
#line 369 "part1_EL.y"
                                                  { (yyval.nodePtr) = mknode("exp_list",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1928 "part1_EL.tab.c"
    break;

  case 82: /* expression: INT_LIT  */
#line 375 "part1_EL.y"
                   { char buf[32]; sprintf(buf,"%d",(yyvsp[0].intVal));
                      (yyval.nodePtr) = mknode(buf,NULL,NULL); }
#line 1935 "part1_EL.tab.c"
    break;

  case 83: /* expression: REAL_LIT  */
#line 378 "part1_EL.y"
                        { char buf[64]; sprintf(buf,"%f",(yyvsp[0].realVal));
                      (yyval.nodePtr) = mknode(buf,NULL,NULL); }
#line 1942 "part1_EL.tab.c"
    break;

  case 84: /* expression: STRING_LIT  */
#line 381 "part1_EL.y"
                 { (yyval.nodePtr) = mknode((yyvsp[0].stringVal),NULL,NULL); }
#line 1948 "part1_EL.tab.c"
    break;

  case 85: /* expression: CHAR_LIT  */
#line 383 "part1_EL.y"
                { char buf[2]={(yyvsp[0].charVal),'\0'};
                      (yyval.nodePtr) = mknode(buf,NULL,NULL); }
#line 1955 "part1_EL.tab.c"
    break;

  case 86: /* expression: IDENT  */
#line 386 "part1_EL.y"
               { (yyval.nodePtr) = mknode((yyvsp[0].stringVal),NULL,NULL); }
#line 1961 "part1_EL.tab.c"
    break;

  case 87: /* expression: expression PLUS expression  */
#line 389 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("+",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1967 "part1_EL.tab.c"
    break;

  case 88: /* expression: expression MINUS expression  */
#line 390 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("-",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1973 "part1_EL.tab.c"
    break;

  case 89: /* expression: expression MULTI expression  */
#line 391 "part1_EL.y"
                                     { (yyval.nodePtr) = mknode("*",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1979 "part1_EL.tab.c"
    break;

  case 90: /* expression: expression DIV expression  */
#line 392 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("/",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1985 "part1_EL.tab.c"
    break;

  case 91: /* expression: MINUS expression  */
#line 395 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("unary-",(yyvsp[0].nodePtr),NULL); }
#line 1991 "part1_EL.tab.c"
    break;

  case 92: /* expression: ADDRESS expression  */
#line 396 "part1_EL.y"
                                  { (yyval.nodePtr) = mknode("&",(yyvsp[0].nodePtr),NULL); }
#line 1997 "part1_EL.tab.c"
    break;

  case 93: /* expression: MULTI IDENT  */
#line 397 "part1_EL.y"
                                { (yyval.nodePtr) = mknode("deref",mknode((yyvsp[0].stringVal),NULL,NULL),NULL); }
#line 2003 "part1_EL.tab.c"
    break;

  case 94: /* expression: MULTI expression  */
#line 398 "part1_EL.y"
                                     { (yyval.nodePtr) = mknode("unary*", (yyvsp[0].nodePtr),NULL); }
#line 2009 "part1_EL.tab.c"
    break;

  case 95: /* expression: NOT expression  */
#line 399 "part1_EL.y"
                                  { (yyval.nodePtr) = mknode("not", (yyvsp[0].nodePtr), NULL); }
#line 2015 "part1_EL.tab.c"
    break;

  case 96: /* expression: '(' expression ')'  */
#line 402 "part1_EL.y"
                                    { (yyval.nodePtr) = (yyvsp[-1].nodePtr); }
#line 2021 "part1_EL.tab.c"
    break;

  case 97: /* expression: expression EQL expression  */
#line 405 "part1_EL.y"
                                     { (yyval.nodePtr) = mknode("==",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2027 "part1_EL.tab.c"
    break;

  case 98: /* expression: expression NOTEQL expression  */
#line 406 "part1_EL.y"
                                        { (yyval.nodePtr) = mknode("!=",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2033 "part1_EL.tab.c"
    break;

  case 99: /* expression: expression GREATEREQL expression  */
#line 407 "part1_EL.y"
                                            { (yyval.nodePtr) = mknode(">=",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2039 "part1_EL.tab.c"
    break;

  case 100: /* expression: expression LESSEQL expression  */
#line 408 "part1_EL.y"
                                         { (yyval.nodePtr) = mknode("<=",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2045 "part1_EL.tab.c"
    break;

  case 101: /* expression: expression GREATER expression  */
#line 409 "part1_EL.y"
                                         { (yyval.nodePtr) = mknode(">", (yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2051 "part1_EL.tab.c"
    break;

  case 102: /* expression: expression LESS expression  */
#line 410 "part1_EL.y"
                                      { (yyval.nodePtr) = mknode("<", (yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2057 "part1_EL.tab.c"
    break;

  case 103: /* expression: IDENT '[' expression ']'  */
#line 413 "part1_EL.y"
                               { (yyval.nodePtr) = mknode("index",mknode((yyvsp[-3].stringVal),NULL,NULL),(yyvsp[-1].nodePtr)); }
#line 2063 "part1_EL.tab.c"
    break;

  case 104: /* expression: expression AND expression  */
#line 416 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("and",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2069 "part1_EL.tab.c"
    break;

  case 105: /* expression: expression OR expression  */
#line 417 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("or",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2075 "part1_EL.tab.c"
    break;

  case 106: /* expression: TRUE  */
#line 419 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("BOOL", mknode("TRUE", NULL, NULL), NULL); }
#line 2081 "part1_EL.tab.c"
    break;

  case 107: /* expression: FALSE  */
#line 420 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("BOOL", mknode("FALSE", NULL, NULL), NULL); }
#line 2087 "part1_EL.tab.c"
    break;

  case 108: /* expression: LENGTH IDENT LENGTH  */
#line 421 "part1_EL.y"
                                 { (yyval.nodePtr) = mknode("length", mknode((yyvsp[-1].stringVal), NULL, NULL), NULL); }
#line 2093 "part1_EL.tab.c"
    break;

  case 109: /* expression: func_call  */
#line 424 "part1_EL.y"
                                { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 2099 "part1_EL.tab.c"
    break;


#line 2103 "part1_EL.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 426 "part1_EL.y"
  /* ===================  C‑code section ================================*/

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

