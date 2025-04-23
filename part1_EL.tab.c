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
  YYSYMBOL_idents = 65,                    /* idents  */
  YYSYMBOL_literal = 66,                   /* literal  */
  YYSYMBOL_var = 67,                       /* var  */
  YYSYMBOL_dec_list = 68,                  /* dec_list  */
  YYSYMBOL_dec = 69,                       /* dec  */
  YYSYMBOL_statements = 70,                /* statements  */
  YYSYMBOL_state = 71,                     /* state  */
  YYSYMBOL_assign_state = 72,              /* assign_state  */
  YYSYMBOL_if_state = 73,                  /* if_state  */
  YYSYMBOL_while_state = 74,               /* while_state  */
  YYSYMBOL_do_while_state = 75,            /* do_while_state  */
  YYSYMBOL_for_state = 76,                 /* for_state  */
  YYSYMBOL_for_h = 77,                     /* for_h  */
  YYSYMBOL_advance_exp = 78,               /* advance_exp  */
  YYSYMBOL_rt_state = 79,                  /* rt_state  */
  YYSYMBOL_bl_state = 80,                  /* bl_state  */
  YYSYMBOL_func_call_state = 81,           /* func_call_state  */
  YYSYMBOL_func_call = 82,                 /* func_call  */
  YYSYMBOL_exp_list = 83,                  /* exp_list  */
  YYSYMBOL_expression = 84                 /* expression  */
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
#define YYLAST   548

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  210

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
     127,   130,   133,   137,   146,   147,   148,   149,   150,   151,
     153,   158,   159,   163,   164,   168,   173,   174,   175,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   194,   199,
     206,   211,   217,   223,   230,   236,   243,   246,   249,   252,
     258,   264,   271,   273,   279,   288,   304,   309,   310,   317,
     318,   325,   327,   333,   334,   340,   343,   346,   348,   351,
     354,   355,   356,   357,   360,   361,   362,   363,   366,   369,
     370,   371,   372,   373,   374,   377,   380,   381,   384
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
  "function", "params", "param_list", "param", "type", "idents", "literal",
  "var", "dec_list", "dec", "statements", "state", "assign_state",
  "if_state", "while_state", "do_while_state", "for_state", "for_h",
  "advance_exp", "rt_state", "bl_state", "func_call_state", "func_call",
  "exp_list", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-75)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -24,    21,    32,   -75,   -24,    -8,   -75,   -75,    24,   523,
       8,   -75,     7,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,     9,    22,    24,    68,     3,   -75,   -75,    64,   523,
      51,   523,   -75,    64,    57,   199,    31,   -75,    56,   -34,
     112,   112,    35,    34,   112,   199,    80,    81,   -75,    61,
      63,   199,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
      42,    89,   199,    98,   112,   -75,   -75,   -75,   -75,    45,
     112,   129,   112,   112,   -75,   385,   404,    93,    54,   -20,
     245,    78,    58,    69,   199,   -75,   -75,   -75,   -39,    60,
      85,    67,   146,    70,   265,   217,   112,   -10,    45,   -75,
     -75,   442,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   -20,   -20,    83,   -20,   102,   -75,
     -75,    47,   112,    97,   177,   124,   -75,   -75,   -75,   -32,
     -75,   -75,    99,   231,   -75,   485,   474,   503,   503,     2,
       2,     2,     2,   -10,   -10,   -75,   -75,    20,   -75,   112,
     -11,   -75,   112,   -75,    88,   202,   285,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,    90,   -75,   164,   -75,
     112,   105,   305,   199,   -75,   325,   -75,   112,   -75,   107,
     101,   108,   110,   345,   423,   -20,   112,   135,   -75,   -75,
     159,   -75,   -75,   -75,   -75,   -20,   -75,   365,   -75,   -75,
     155,   169,   126,   143,   134,   -20,   112,   -75,   -75,   460
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     1,     3,     7,     0,
       0,     8,     9,    14,    13,    12,    16,    15,    18,    17,
      19,     0,     0,     0,     0,    31,    10,    11,     0,     0,
       0,     0,    32,    33,    31,    36,     0,    34,     0,     0,
       0,     0,     0,     0,     0,    36,     0,     0,    39,     0,
       0,    36,    40,    41,    42,    44,    43,    46,    45,    47,
       0,     0,    36,     0,     0,    75,    76,    78,    77,    79,
       0,     0,     0,     0,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36,     6,    38,    69,    21,     0,
       0,     0,     0,    98,     0,     0,     0,    84,    79,    87,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    66,
      67,     0,     0,     0,     0,     0,    35,     5,    52,    79,
      70,    48,     0,     0,    88,    96,    97,    89,    90,    91,
      92,    93,    94,    80,    81,    82,    83,    56,    60,     0,
       0,    62,     0,    71,     0,    73,     0,    68,    24,    29,
      27,    28,    30,    25,    26,    20,     0,    51,     0,    95,
       0,     0,     0,    36,    63,     0,    72,     0,    50,    22,
      75,    78,    77,     0,     0,     0,     0,     0,    61,    74,
       0,    53,    49,    54,    55,     0,    57,     0,    67,    23,
      58,     0,     0,     0,     0,     0,     0,    64,    59,    65
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   -75,   182,    14,   -75,   165,   -75,    26,   -75,   -75,
     -23,   154,   -75,   -35,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,   -74,   -75,   -26,    16,   -40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    48,    10,    11,    12,    21,    89,   165,
      49,    32,    33,    50,    51,    52,    53,    54,    55,    56,
      78,   204,    57,    58,    59,    74,   154,   100
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      75,    76,    30,    28,    80,   118,     1,    63,    45,    60,
      81,    38,    28,   124,     4,   125,    86,   173,     4,    60,
      64,   167,    96,    94,    95,    60,    28,    90,     5,    29,
      97,    99,     6,   101,   112,   113,    60,    93,   170,   171,
     147,   148,     8,   151,   110,   111,   112,   113,     9,   123,
      65,    66,    67,    68,    69,    34,   133,    36,    60,    22,
      23,    24,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,    25,    27,   174,    31,    46,    35,
      28,   155,   156,    61,    62,    77,    79,    82,    83,    84,
      70,    71,    85,    72,   150,    87,    88,    73,   153,    96,
     116,    65,    66,    67,    68,    69,   117,   120,   121,   172,
     122,   196,   175,   126,   127,    65,    66,    67,    68,    69,
     128,   200,   152,   130,   149,    91,   157,   166,   183,    46,
     184,   208,    65,    66,    67,    68,    98,   155,   187,   176,
     168,    70,    71,    46,    92,   179,   197,    60,    73,    65,
      66,    67,    68,   129,   191,    70,    71,   185,    72,   190,
      46,   192,    73,   193,   198,   199,   209,   180,    66,   181,
     182,    69,    70,    71,   202,    72,   203,    46,   205,    73,
     158,   159,   160,   161,   206,   207,     7,    37,    26,    70,
      71,     0,    72,   189,     0,    46,    73,     0,     0,     0,
       0,     0,     0,     0,   162,     0,    39,    70,    71,     0,
      72,     0,     0,     0,    73,     0,    40,     0,     0,    41,
      42,    43,    28,     0,    44,   163,   164,    45,     0,     1,
      46,     0,     0,     0,   102,     0,   103,   104,   105,   106,
     107,   108,   109,    47,   110,   111,   112,   113,     0,   102,
       0,   103,   104,   105,   106,   107,   108,   109,   177,   110,
     111,   112,   113,   102,     0,   103,   104,   105,   106,   107,
     108,   109,   132,   110,   111,   112,   113,   102,     0,   103,
     104,   105,   106,   107,   108,   109,   169,   110,   111,   112,
     113,     0,     0,     0,     0,     0,     0,   102,   119,   103,
     104,   105,   106,   107,   108,   109,     0,   110,   111,   112,
     113,     0,     0,     0,     0,     0,     0,   102,   131,   103,
     104,   105,   106,   107,   108,   109,     0,   110,   111,   112,
     113,     0,     0,     0,     0,     0,     0,   102,   178,   103,
     104,   105,   106,   107,   108,   109,     0,   110,   111,   112,
     113,     0,     0,     0,     0,     0,     0,   102,   186,   103,
     104,   105,   106,   107,   108,   109,     0,   110,   111,   112,
     113,     0,     0,     0,     0,     0,     0,   102,   188,   103,
     104,   105,   106,   107,   108,   109,     0,   110,   111,   112,
     113,     0,     0,     0,     0,     0,     0,   102,   194,   103,
     104,   105,   106,   107,   108,   109,     0,   110,   111,   112,
     113,     0,     0,     0,     0,     0,     0,   102,   201,   103,
     104,   105,   106,   107,   108,   109,     0,   110,   111,   112,
     113,     0,     0,     0,     0,     0,   102,   114,   103,   104,
     105,   106,   107,   108,   109,     0,   110,   111,   112,   113,
       0,     0,     0,     0,     0,   102,   115,   103,   104,   105,
     106,   107,   108,   109,     0,   110,   111,   112,   113,     0,
       0,     0,     0,     0,   102,   195,   103,   104,   105,   106,
     107,   108,   109,     0,   110,   111,   112,   113,     0,     0,
       0,     0,   102,   134,   103,   104,   105,   106,   107,   108,
     109,     0,   110,   111,   112,   113,   102,     0,     0,   104,
     105,   106,   107,   108,   109,     0,   110,   111,   112,   113,
     104,   105,   106,   107,   108,   109,     0,   110,   111,   112,
     113,    13,    14,    15,    16,    17,     0,    18,    19,    20,
     106,   107,   108,   109,     0,   110,   111,   112,   113
};

static const yytype_int16 yycheck[] =
{
      40,    41,    25,    23,    44,    79,    30,    41,    28,    35,
      45,    34,    23,    52,     0,    54,    51,    28,     4,    45,
      54,    53,    54,    63,    64,    51,    23,    62,     7,    26,
      70,    71,     0,    73,    44,    45,    62,    63,    18,    19,
     114,   115,    50,   117,    42,    43,    44,    45,    24,    84,
       3,     4,     5,     6,     7,    29,    96,    31,    84,    51,
      53,    52,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    52,     7,   150,    13,    31,    28,
      23,   121,   122,    52,    28,    50,    52,     7,     7,    28,
      43,    44,    29,    46,   117,    53,     7,    50,    51,    54,
       7,     3,     4,     5,     6,     7,    52,    29,    50,   149,
      41,   185,   152,    53,    29,     3,     4,     5,     6,     7,
      53,   195,    20,    53,    41,    27,    29,     3,   168,    31,
     170,   205,     3,     4,     5,     6,     7,   177,   173,    51,
      41,    43,    44,    31,    46,    55,   186,   173,    50,     3,
       4,     5,     6,     7,    53,    43,    44,    52,    46,    52,
      31,    53,    50,    53,    29,     6,   206,     3,     4,     5,
       6,     7,    43,    44,    19,    46,     7,    31,    52,    50,
       3,     4,     5,     6,    41,    51,     4,    33,    23,    43,
      44,    -1,    46,   177,    -1,    31,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    -1,     7,    43,    44,    -1,
      46,    -1,    -1,    -1,    50,    -1,    17,    -1,    -1,    20,
      21,    22,    23,    -1,    25,    48,    49,    28,    -1,    30,
      31,    -1,    -1,    -1,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    44,    42,    43,    44,    45,    -1,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    56,    42,
      43,    44,    45,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    55,    42,    43,    44,    45,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    55,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    32,    53,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    32,    53,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    32,    53,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    32,    53,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    32,    53,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    32,    53,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    32,    53,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    32,    52,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    32,    52,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    32,    52,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    32,    51,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    43,    44,    45,    32,    -1,    -1,    35,
      36,    37,    38,    39,    40,    -1,    42,    43,    44,    45,
      35,    36,    37,    38,    39,    40,    -1,    42,    43,    44,
      45,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      37,    38,    39,    40,    -1,    42,    43,    44,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,    58,    59,    60,     7,     0,    59,    50,    24,
      61,    62,    63,     8,     9,    10,    11,    12,    14,    15,
      16,    64,    51,    53,    52,    52,    62,     7,    23,    26,
      67,    13,    68,    69,    64,    28,    64,    68,    67,     7,
      17,    20,    21,    22,    25,    28,    31,    44,    60,    67,
      70,    71,    72,    73,    74,    75,    76,    79,    80,    81,
      82,    52,    28,    41,    54,     3,     4,     5,     6,     7,
      43,    44,    46,    50,    82,    84,    84,    50,    77,    52,
      84,    70,     7,     7,    28,    29,    70,    53,     7,    65,
      70,    27,    46,    82,    84,    84,    54,    84,     7,    84,
      84,    84,    32,    34,    35,    36,    37,    38,    39,    40,
      42,    43,    44,    45,    52,    52,     7,    52,    80,    53,
      29,    50,    41,    70,    52,    54,    53,    29,    53,     7,
      53,    53,    55,    84,    51,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    80,    80,    41,
      67,    80,    20,    51,    83,    84,    84,    29,     3,     4,
       5,     6,    27,    48,    49,    66,     3,    53,    41,    55,
      18,    19,    84,    28,    80,    84,    51,    56,    53,    55,
       3,     5,     6,    84,    84,    52,    53,    70,    53,    83,
      52,    53,    53,    53,    53,    52,    80,    84,    29,     6,
      80,    53,    19,     7,    78,    52,    41,    51,    80,    84
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    63,    64,    64,    64,    64,    64,    64,    64,    64,
      65,    65,    65,    65,    66,    66,    66,    66,    66,    66,
      66,    67,    67,    68,    68,    69,    70,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    72,    72,
      72,    72,    72,    72,    72,    72,    73,    73,    73,    73,
      74,    75,    76,    76,    77,    78,    79,    80,    80,    81,
      81,    82,    82,    83,    83,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,    12,    10,     0,     1,     1,
       3,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     4,     6,     1,     1,     1,     1,     1,     1,
       1,     0,     2,     1,     2,     5,     0,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     7,
       5,     5,     4,     7,     7,     7,     4,     7,     8,    11,
       4,     6,     4,     5,     9,     3,     3,     3,     4,     2,
       4,     4,     5,     1,     3,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     2,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     4,     3,     3,     1
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
#line 1363 "part1_EL.tab.c"
    break;

  case 3: /* functions: function functions  */
#line 71 "part1_EL.y"
                                           { (yyval.nodePtr) = mknode("FUNCS",(yyvsp[-1].nodePtr),(yyvsp[0].nodePtr)); }
#line 1369 "part1_EL.tab.c"
    break;

  case 4: /* functions: function  */
#line 72 "part1_EL.y"
                                             { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1375 "part1_EL.tab.c"
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
#line 1388 "part1_EL.tab.c"
    break;

  case 6: /* function: DEF IDENT '(' params ')' ':' var T_BEGIN statements END  */
#line 88 "part1_EL.y"
    {
        node* idN = mknode((yyvsp[-8].stringVal), NULL, NULL);
        node* paramsN = mknode("PARAMS", (yyvsp[-6].nodePtr), NULL);
        node* bodyN = mknode("BODY", (yyvsp[-3].nodePtr), (yyvsp[-1].nodePtr));
        (yyval.nodePtr) = mknode("PROC", idN, mknode("PROC_IN", paramsN, bodyN));
    }
#line 1399 "part1_EL.tab.c"
    break;

  case 7: /* params: %empty  */
#line 99 "part1_EL.y"
    { (yyval.nodePtr) = NULL; }
#line 1405 "part1_EL.tab.c"
    break;

  case 8: /* params: param_list  */
#line 100 "part1_EL.y"
                                      { (yyval.nodePtr) = (yyvsp[0].nodePtr);   }
#line 1411 "part1_EL.tab.c"
    break;

  case 9: /* param_list: param  */
#line 104 "part1_EL.y"
                                    { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1417 "part1_EL.tab.c"
    break;

  case 10: /* param_list: param ';' param_list  */
#line 105 "part1_EL.y"
                                  { (yyval.nodePtr) = mknode("PARAMS",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1423 "part1_EL.tab.c"
    break;

  case 11: /* param: PAR type ':' IDENT  */
#line 109 "part1_EL.y"
                               {(yyval.nodePtr)=mknode("PARAM",(yyvsp[-2].nodePtr),mknode((yyvsp[0].stringVal),NULL,NULL));}
#line 1429 "part1_EL.tab.c"
    break;

  case 12: /* type: INT  */
#line 115 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("INT",NULL,NULL);  }
#line 1435 "part1_EL.tab.c"
    break;

  case 13: /* type: CHAR  */
#line 116 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("CHAR",NULL,NULL); }
#line 1441 "part1_EL.tab.c"
    break;

  case 14: /* type: BOOL  */
#line 117 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("BOOL",NULL,NULL); }
#line 1447 "part1_EL.tab.c"
    break;

  case 15: /* type: STRING  */
#line 118 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("STRING",NULL,NULL);}
#line 1453 "part1_EL.tab.c"
    break;

  case 16: /* type: REAL  */
#line 119 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("REAL",NULL,NULL); }
#line 1459 "part1_EL.tab.c"
    break;

  case 17: /* type: CHARPTR  */
#line 120 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("CHARPTR",NULL,NULL);}
#line 1465 "part1_EL.tab.c"
    break;

  case 18: /* type: INTPTR  */
#line 121 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("INTPTR",NULL,NULL);}
#line 1471 "part1_EL.tab.c"
    break;

  case 19: /* type: REALPTR  */
#line 122 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("REALPTR",NULL,NULL);}
#line 1477 "part1_EL.tab.c"
    break;

  case 20: /* idents: IDENT ':' literal  */
#line 128 "part1_EL.y"
        { (yyval.nodePtr) = mknode("VAR_ASSIGN", mknode("IDENT", mknode((yyvsp[-2].stringVal),NULL,NULL), NULL), (yyvsp[0].nodePtr)); }
#line 1483 "part1_EL.tab.c"
    break;

  case 21: /* idents: IDENT  */
#line 131 "part1_EL.y"
        { (yyval.nodePtr) = mknode("VAR_DECL", mknode("IDENT", mknode((yyvsp[0].stringVal), NULL, NULL), NULL), NULL); }
#line 1489 "part1_EL.tab.c"
    break;

  case 22: /* idents: IDENT '[' INT_LIT ']'  */
#line 134 "part1_EL.y"
        { char sz[32]; sprintf(sz,"%d",(yyvsp[-1].intVal));
         (yyval.nodePtr) = mknode("ARRAY_DECL", mknode("IDENT", mknode((yyvsp[-3].stringVal), NULL, NULL), NULL), mknode(sz, NULL, NULL)); }
#line 1496 "part1_EL.tab.c"
    break;

  case 23: /* idents: IDENT '[' INT_LIT ']' ':' STRING_LIT  */
#line 138 "part1_EL.y"
        { 
            (yyval.nodePtr) = mknode("ARRAY_INIT",
                        mknode("ARRAY_DECL", mknode("IDENT", mknode((yyvsp[-5].stringVal), NULL, NULL), NULL), mknode((yyvsp[-3].intVal), NULL, NULL)),
                        mknode((yyvsp[0].stringVal), NULL, NULL)); 
        }
#line 1506 "part1_EL.tab.c"
    break;

  case 24: /* literal: INT_LIT  */
#line 146 "part1_EL.y"
                       { char ibuf[32]; sprintf(ibuf,"%d",(yyvsp[0].intVal)); (yyval.nodePtr) = mknode("INT", mknode(ibuf,NULL,NULL), NULL); }
#line 1512 "part1_EL.tab.c"
    break;

  case 25: /* literal: TRUE  */
#line 147 "part1_EL.y"
                       { (yyval.nodePtr) = mknode("BOOL", mknode("true", NULL, NULL), NULL); }
#line 1518 "part1_EL.tab.c"
    break;

  case 26: /* literal: FALSE  */
#line 148 "part1_EL.y"
                       { (yyval.nodePtr) = mknode("BOOL", mknode("false", NULL, NULL), NULL); }
#line 1524 "part1_EL.tab.c"
    break;

  case 27: /* literal: CHAR_LIT  */
#line 149 "part1_EL.y"
                       { char cbuf[2] = {(yyvsp[0].charVal),'\0'}; (yyval.nodePtr) = mknode("CHAR", mknode(cbuf,NULL,NULL), NULL); }
#line 1530 "part1_EL.tab.c"
    break;

  case 28: /* literal: STRING_LIT  */
#line 150 "part1_EL.y"
                       { (yyval.nodePtr) = mknode("STRING", mknode((yyvsp[0].stringVal), NULL, NULL), NULL); }
#line 1536 "part1_EL.tab.c"
    break;

  case 29: /* literal: REAL_LIT  */
#line 151 "part1_EL.y"
                       { char r[64]; sprintf(r,"%f",(yyvsp[0].realVal));
                        (yyval.nodePtr) = mknode("REAL", mknode(r,NULL,NULL), NULL); }
#line 1543 "part1_EL.tab.c"
    break;

  case 30: /* literal: NULLL  */
#line 153 "part1_EL.y"
                       { (yyval.nodePtr) = mknode("NULL", NULL, NULL); }
#line 1549 "part1_EL.tab.c"
    break;

  case 31: /* var: %empty  */
#line 158 "part1_EL.y"
    { (yyval.nodePtr) = NULL; }
#line 1555 "part1_EL.tab.c"
    break;

  case 32: /* var: VARIABLE dec_list  */
#line 159 "part1_EL.y"
                                       { (yyval.nodePtr) = mknode("VAR",(yyvsp[0].nodePtr),NULL); }
#line 1561 "part1_EL.tab.c"
    break;

  case 33: /* dec_list: dec  */
#line 163 "part1_EL.y"
                               { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1567 "part1_EL.tab.c"
    break;

  case 34: /* dec_list: dec dec_list  */
#line 164 "part1_EL.y"
                          { (yyval.nodePtr) = mknode("DECS",(yyvsp[-1].nodePtr),(yyvsp[0].nodePtr)); }
#line 1573 "part1_EL.tab.c"
    break;

  case 35: /* dec: TYPE type ':' idents ';'  */
#line 168 "part1_EL.y"
                                       { (yyval.nodePtr) = mknode("DECL",(yyvsp[-3].nodePtr),(yyvsp[-1].nodePtr)); }
#line 1579 "part1_EL.tab.c"
    break;

  case 36: /* statements: %empty  */
#line 173 "part1_EL.y"
     {(yyval.nodePtr) = mknode("", NULL,NULL);}
#line 1585 "part1_EL.tab.c"
    break;

  case 37: /* statements: state  */
#line 174 "part1_EL.y"
                    {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1591 "part1_EL.tab.c"
    break;

  case 38: /* statements: state statements  */
#line 175 "part1_EL.y"
                               {(yyval.nodePtr) = mknode("statements", (yyvsp[-1].nodePtr), (yyvsp[0].nodePtr));}
#line 1597 "part1_EL.tab.c"
    break;

  case 39: /* state: function  */
#line 181 "part1_EL.y"
                     {(yyval.nodePtr)=(yyvsp[0].nodePtr);}
#line 1603 "part1_EL.tab.c"
    break;

  case 40: /* state: assign_state  */
#line 182 "part1_EL.y"
                           {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1609 "part1_EL.tab.c"
    break;

  case 41: /* state: if_state  */
#line 183 "part1_EL.y"
                       {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1615 "part1_EL.tab.c"
    break;

  case 42: /* state: while_state  */
#line 184 "part1_EL.y"
                          {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1621 "part1_EL.tab.c"
    break;

  case 43: /* state: for_state  */
#line 185 "part1_EL.y"
                        {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1627 "part1_EL.tab.c"
    break;

  case 44: /* state: do_while_state  */
#line 186 "part1_EL.y"
                             {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1633 "part1_EL.tab.c"
    break;

  case 45: /* state: bl_state  */
#line 187 "part1_EL.y"
                       {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1639 "part1_EL.tab.c"
    break;

  case 46: /* state: rt_state  */
#line 188 "part1_EL.y"
                       {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1645 "part1_EL.tab.c"
    break;

  case 47: /* state: func_call_state  */
#line 189 "part1_EL.y"
                              {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1651 "part1_EL.tab.c"
    break;

  case 48: /* assign_state: IDENT ASSIGN expression ';'  */
#line 195 "part1_EL.y"
        { (yyval.nodePtr) = mknode("assign",
                      mknode((yyvsp[-3].stringVal),NULL,NULL), (yyvsp[-1].nodePtr)); }
#line 1658 "part1_EL.tab.c"
    break;

  case 49: /* assign_state: IDENT '[' expression ']' ASSIGN CHAR_LIT ';'  */
#line 199 "part1_EL.y"
                                                   {
          char cbuf[2]={(yyvsp[-1].charVal),'\0'};
          (yyval.nodePtr) = mknode("array_assign",
                      mknode((yyvsp[-6].stringVal),(yyvsp[-4].nodePtr),NULL),
                      mknode(cbuf,NULL,NULL)); }
#line 1668 "part1_EL.tab.c"
    break;

  case 50: /* assign_state: MULTI IDENT ASSIGN expression ';'  */
#line 206 "part1_EL.y"
                                        {
          (yyval.nodePtr) = mknode("pointer_assign",
                      mknode((yyvsp[-3].stringVal),NULL,NULL), (yyvsp[-1].nodePtr)); }
#line 1676 "part1_EL.tab.c"
    break;

  case 51: /* assign_state: IDENT ASSIGN ADDRESS IDENT ';'  */
#line 211 "part1_EL.y"
                                     {
          (yyval.nodePtr) = mknode("adder_assign",
                      mknode((yyvsp[-4].stringVal),NULL,NULL),
                      mknode((yyvsp[-1].stringVal),NULL,NULL)); }
#line 1685 "part1_EL.tab.c"
    break;

  case 52: /* assign_state: IDENT ASSIGN NULLL ';'  */
#line 217 "part1_EL.y"
                             {
          (yyval.nodePtr) = mknode("null_assign",
                      mknode((yyvsp[-3].stringVal),NULL,NULL),
                      mknode("null",NULL,NULL)); }
#line 1694 "part1_EL.tab.c"
    break;

  case 53: /* assign_state: IDENT '[' expression ']' ASSIGN INT_LIT ';'  */
#line 223 "part1_EL.y"
                                                  {
          char buf[32]; sprintf(buf,"%d",(yyvsp[-1].intVal));
          (yyval.nodePtr) = mknode("array_assign",
                      mknode((yyvsp[-6].stringVal),(yyvsp[-4].nodePtr),NULL),
                      mknode(buf,NULL,NULL)); }
#line 1704 "part1_EL.tab.c"
    break;

  case 54: /* assign_state: IDENT '[' expression ']' ASSIGN STRING_LIT ';'  */
#line 230 "part1_EL.y"
                                                     {
          (yyval.nodePtr) = mknode("array_assign",
                      mknode((yyvsp[-6].stringVal),(yyvsp[-4].nodePtr),NULL),
                      mknode((yyvsp[-1].stringVal),NULL,NULL)); }
#line 1713 "part1_EL.tab.c"
    break;

  case 55: /* assign_state: IDENT '[' expression ']' ASSIGN expression ';'  */
#line 236 "part1_EL.y"
                                                     {
          (yyval.nodePtr) = mknode("array_assign",
                      mknode((yyvsp[-6].stringVal),(yyvsp[-4].nodePtr),NULL), (yyvsp[-1].nodePtr)); }
#line 1721 "part1_EL.tab.c"
    break;

  case 56: /* if_state: IF expression ':' bl_state  */
#line 244 "part1_EL.y"
        { (yyval.nodePtr) = mknode("if", (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr)); }
#line 1727 "part1_EL.tab.c"
    break;

  case 57: /* if_state: IF expression ':' bl_state ELSE ':' bl_state  */
#line 247 "part1_EL.y"
        { (yyval.nodePtr) = mknode("if_else", (yyvsp[-5].nodePtr), mknode("then", (yyvsp[-3].nodePtr), mknode("else", (yyvsp[0].nodePtr), NULL))); }
#line 1733 "part1_EL.tab.c"
    break;

  case 58: /* if_state: IF expression ':' bl_state ELIF expression ':' bl_state  */
#line 250 "part1_EL.y"
        { (yyval.nodePtr) = mknode("if_elif", (yyvsp[-6].nodePtr), mknode("then", (yyvsp[-4].nodePtr), mknode("elif", (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr)))); }
#line 1739 "part1_EL.tab.c"
    break;

  case 59: /* if_state: IF expression ':' bl_state ELIF expression ':' bl_state ELSE ':' bl_state  */
#line 253 "part1_EL.y"
        { (yyval.nodePtr) = mknode("if_elif-else", (yyvsp[-9].nodePtr), mknode("then", (yyvsp[-7].nodePtr), mknode("elif", (yyvsp[-5].nodePtr), mknode("elif-then", (yyvsp[-3].nodePtr), mknode("else", (yyvsp[0].nodePtr), NULL))))); }
#line 1745 "part1_EL.tab.c"
    break;

  case 60: /* while_state: WHILE expression ':' bl_state  */
#line 258 "part1_EL.y"
                                    {
          (yyval.nodePtr) = mknode("while",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1752 "part1_EL.tab.c"
    break;

  case 61: /* do_while_state: DO ':' bl_state WHILE expression ';'  */
#line 264 "part1_EL.y"
                                           {
          (yyval.nodePtr) = mknode("do_while",(yyvsp[-3].nodePtr),
                      mknode("condition",(yyvsp[-1].nodePtr),NULL)); }
#line 1760 "part1_EL.tab.c"
    break;

  case 62: /* for_state: FOR for_h ':' bl_state  */
#line 271 "part1_EL.y"
                                       {
          (yyval.nodePtr) = mknode("for",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1767 "part1_EL.tab.c"
    break;

  case 63: /* for_state: FOR for_h ':' var bl_state  */
#line 273 "part1_EL.y"
                                        {
          (yyval.nodePtr) = mknode("for",(yyvsp[-3].nodePtr),
                      mknode("block",(yyvsp[0].nodePtr),(yyvsp[-1].nodePtr))); }
#line 1775 "part1_EL.tab.c"
    break;

  case 64: /* for_h: '(' IDENT ASSIGN expression ';' expression ';' advance_exp ')'  */
#line 281 "part1_EL.y"
                                                    {
          (yyval.nodePtr) = mknode("for_header",
                      mknode("init",mknode((yyvsp[-7].stringVal),NULL,NULL),(yyvsp[-5].nodePtr)),
                      mknode("loop",(yyvsp[-3].nodePtr),(yyvsp[-1].nodePtr))); }
#line 1784 "part1_EL.tab.c"
    break;

  case 65: /* advance_exp: IDENT ASSIGN expression  */
#line 288 "part1_EL.y"
                                             {
          (yyval.nodePtr) = mknode("update",
                      mknode((yyvsp[-2].stringVal),NULL,NULL),(yyvsp[0].nodePtr)); }
#line 1792 "part1_EL.tab.c"
    break;

  case 66: /* rt_state: RETURN expression ';'  */
#line 304 "part1_EL.y"
                                                 { (yyval.nodePtr) = mknode("return",(yyvsp[-1].nodePtr),NULL); }
#line 1798 "part1_EL.tab.c"
    break;

  case 67: /* bl_state: T_BEGIN statements END  */
#line 309 "part1_EL.y"
                                             { (yyval.nodePtr) = mknode("block",(yyvsp[-1].nodePtr),NULL); }
#line 1804 "part1_EL.tab.c"
    break;

  case 68: /* bl_state: var T_BEGIN statements END  */
#line 310 "part1_EL.y"
                                               { (yyval.nodePtr) = mknode("block",(yyvsp[-1].nodePtr),(yyvsp[-3].nodePtr)); }
#line 1810 "part1_EL.tab.c"
    break;

  case 69: /* func_call_state: func_call ';'  */
#line 317 "part1_EL.y"
                                              { (yyval.nodePtr) = (yyvsp[-1].nodePtr); }
#line 1816 "part1_EL.tab.c"
    break;

  case 70: /* func_call_state: IDENT ASSIGN func_call ';'  */
#line 318 "part1_EL.y"
                                          {
          (yyval.nodePtr) = mknode("assign",
                      mknode((yyvsp[-3].stringVal),NULL,NULL),(yyvsp[-1].nodePtr)); }
#line 1824 "part1_EL.tab.c"
    break;

  case 71: /* func_call: CALL IDENT '(' ')'  */
#line 325 "part1_EL.y"
                                              {
          (yyval.nodePtr) = mknode("call",mknode((yyvsp[-2].stringVal),NULL,NULL),NULL); }
#line 1831 "part1_EL.tab.c"
    break;

  case 72: /* func_call: CALL IDENT '(' exp_list ')'  */
#line 327 "part1_EL.y"
                                             {
          (yyval.nodePtr) = mknode("call",mknode((yyvsp[-3].stringVal),NULL,NULL),(yyvsp[-1].nodePtr)); }
#line 1838 "part1_EL.tab.c"
    break;

  case 73: /* exp_list: expression  */
#line 333 "part1_EL.y"
                                                   { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1844 "part1_EL.tab.c"
    break;

  case 74: /* exp_list: expression ',' exp_list  */
#line 334 "part1_EL.y"
                                                  { (yyval.nodePtr) = mknode("exp_list",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1850 "part1_EL.tab.c"
    break;

  case 75: /* expression: INT_LIT  */
#line 340 "part1_EL.y"
                   { char buf[32]; sprintf(buf,"%d",(yyvsp[0].intVal));
                      (yyval.nodePtr) = mknode(buf,NULL,NULL); }
#line 1857 "part1_EL.tab.c"
    break;

  case 76: /* expression: REAL_LIT  */
#line 343 "part1_EL.y"
                        { char buf[64]; sprintf(buf,"%f",(yyvsp[0].realVal));
                      (yyval.nodePtr) = mknode(buf,NULL,NULL); }
#line 1864 "part1_EL.tab.c"
    break;

  case 77: /* expression: STRING_LIT  */
#line 346 "part1_EL.y"
                 { (yyval.nodePtr) = mknode((yyvsp[0].stringVal),NULL,NULL); }
#line 1870 "part1_EL.tab.c"
    break;

  case 78: /* expression: CHAR_LIT  */
#line 348 "part1_EL.y"
                { char buf[2]={(yyvsp[0].charVal),'\0'};
                      (yyval.nodePtr) = mknode(buf,NULL,NULL); }
#line 1877 "part1_EL.tab.c"
    break;

  case 79: /* expression: IDENT  */
#line 351 "part1_EL.y"
               { (yyval.nodePtr) = mknode((yyvsp[0].stringVal),NULL,NULL); }
#line 1883 "part1_EL.tab.c"
    break;

  case 80: /* expression: expression PLUS expression  */
#line 354 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("+",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1889 "part1_EL.tab.c"
    break;

  case 81: /* expression: expression MINUS expression  */
#line 355 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("-",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1895 "part1_EL.tab.c"
    break;

  case 82: /* expression: expression MULTI expression  */
#line 356 "part1_EL.y"
                                     { (yyval.nodePtr) = mknode("*",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1901 "part1_EL.tab.c"
    break;

  case 83: /* expression: expression DIV expression  */
#line 357 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("/",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1907 "part1_EL.tab.c"
    break;

  case 84: /* expression: MINUS expression  */
#line 360 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("unary-",(yyvsp[0].nodePtr),NULL); }
#line 1913 "part1_EL.tab.c"
    break;

  case 85: /* expression: ADDRESS expression  */
#line 361 "part1_EL.y"
                                  { (yyval.nodePtr) = mknode("&",(yyvsp[0].nodePtr),NULL); }
#line 1919 "part1_EL.tab.c"
    break;

  case 86: /* expression: MULTI IDENT  */
#line 362 "part1_EL.y"
                                { (yyval.nodePtr) = mknode("deref",mknode((yyvsp[0].stringVal),NULL,NULL),NULL); }
#line 1925 "part1_EL.tab.c"
    break;

  case 87: /* expression: MULTI expression  */
#line 363 "part1_EL.y"
                                     { (yyval.nodePtr) = mknode("unary*", (yyvsp[0].nodePtr),NULL); }
#line 1931 "part1_EL.tab.c"
    break;

  case 88: /* expression: '(' expression ')'  */
#line 366 "part1_EL.y"
                                    { (yyval.nodePtr) = (yyvsp[-1].nodePtr); }
#line 1937 "part1_EL.tab.c"
    break;

  case 89: /* expression: expression EQL expression  */
#line 369 "part1_EL.y"
                                     { (yyval.nodePtr) = mknode("==",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1943 "part1_EL.tab.c"
    break;

  case 90: /* expression: expression NOTEQL expression  */
#line 370 "part1_EL.y"
                                        { (yyval.nodePtr) = mknode("!=",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1949 "part1_EL.tab.c"
    break;

  case 91: /* expression: expression GREATEREQL expression  */
#line 371 "part1_EL.y"
                                            { (yyval.nodePtr) = mknode(">=",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1955 "part1_EL.tab.c"
    break;

  case 92: /* expression: expression LESSEQL expression  */
#line 372 "part1_EL.y"
                                         { (yyval.nodePtr) = mknode("<=",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1961 "part1_EL.tab.c"
    break;

  case 93: /* expression: expression GREATER expression  */
#line 373 "part1_EL.y"
                                         { (yyval.nodePtr) = mknode(">", (yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1967 "part1_EL.tab.c"
    break;

  case 94: /* expression: expression LESS expression  */
#line 374 "part1_EL.y"
                                      { (yyval.nodePtr) = mknode("<", (yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1973 "part1_EL.tab.c"
    break;

  case 95: /* expression: IDENT '[' expression ']'  */
#line 377 "part1_EL.y"
                               { (yyval.nodePtr) = mknode("index",mknode((yyvsp[-3].stringVal),NULL,NULL),(yyvsp[-1].nodePtr)); }
#line 1979 "part1_EL.tab.c"
    break;

  case 96: /* expression: expression AND expression  */
#line 380 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("and",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1985 "part1_EL.tab.c"
    break;

  case 97: /* expression: expression OR expression  */
#line 381 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("or",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1991 "part1_EL.tab.c"
    break;

  case 98: /* expression: func_call  */
#line 384 "part1_EL.y"
                                { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1997 "part1_EL.tab.c"
    break;


#line 2001 "part1_EL.tab.c"

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

#line 386 "part1_EL.y"
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

