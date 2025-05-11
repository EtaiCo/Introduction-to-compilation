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
    #define MAX_PARAMS 10

    int yylex();
    int yyerror(const char *s);
    extern int yylineno;  
    extern char* yytext; 

    /* AST node */
    typedef struct node {
        char* token;  
        struct node* left;   
        struct node* right; 
    } node;

    node* ASTRoot = NULL;
    node *mknode(char* token, node* left, node* right);
    void printTree(node* tree, int level);

    typedef enum { FUNC, VAR } SymbolType;

    typedef struct Symbol {
        char* name;
        SymbolType type;
        char* returnType;
        int paramCount;
        char* scope;
        int scopeDepth; 
        char* paramTypes[MAX_PARAMS];
        struct Symbol* next;
    } Symbol;

    Symbol* symbolTable = NULL;

    int insertSymbol(char* name, SymbolType type, char* returnType, int paramCount, const char* scope, char* paramTypes[]);
    Symbol* lookupSymbol(char* name);
    void freeSymbolTable();
    int getParamCount(node* paramList);
    int moreThanOneMain(char* name);
    int isMainExists();
    int isVarDeclaredInScope(const char* name);
    void pushScope();
    void popScope();
    char* inferExprType(node* expr);
    int validateReturnType(node* body, const char* expectedType);


    int mainDeclared = 0;
    int scopeDepth = 0;



#line 127 "part1_EL.tab.c"

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
  YYSYMBOL_scope_marker = 60,              /* scope_marker  */
  YYSYMBOL_function = 61,                  /* function  */
  YYSYMBOL_params = 62,                    /* params  */
  YYSYMBOL_param_list = 63,                /* param_list  */
  YYSYMBOL_param = 64,                     /* param  */
  YYSYMBOL_type = 65,                      /* type  */
  YYSYMBOL_idents = 66,                    /* idents  */
  YYSYMBOL_literal = 67,                   /* literal  */
  YYSYMBOL_var = 68,                       /* var  */
  YYSYMBOL_dec_list = 69,                  /* dec_list  */
  YYSYMBOL_dec = 70,                       /* dec  */
  YYSYMBOL_statements = 71,                /* statements  */
  YYSYMBOL_state = 72,                     /* state  */
  YYSYMBOL_assign_state = 73,              /* assign_state  */
  YYSYMBOL_if_state = 74,                  /* if_state  */
  YYSYMBOL_while_state = 75,               /* while_state  */
  YYSYMBOL_do_while_state = 76,            /* do_while_state  */
  YYSYMBOL_for_state = 77,                 /* for_state  */
  YYSYMBOL_for_h = 78,                     /* for_h  */
  YYSYMBOL_advance_exp = 79,               /* advance_exp  */
  YYSYMBOL_rt_state = 80,                  /* rt_state  */
  YYSYMBOL_bl_state = 81,                  /* bl_state  */
  YYSYMBOL_82_1 = 82,                      /* $@1  */
  YYSYMBOL_83_2 = 83,                      /* $@2  */
  YYSYMBOL_func_call_state = 84,           /* func_call_state  */
  YYSYMBOL_func_call = 85,                 /* func_call  */
  YYSYMBOL_exp_list = 86,                  /* exp_list  */
  YYSYMBOL_expression = 87                 /* expression  */
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
#define YYLAST   588

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

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
       0,   103,   103,   111,   112,   116,   119,   189,   243,   244,
     248,   249,   253,   259,   260,   261,   262,   263,   264,   265,
     266,   271,   274,   277,   281,   294,   295,   296,   297,   298,
     299,   301,   306,   307,   311,   312,   316,   342,   343,   344,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     363,   365,   377,   384,   389,   395,   401,   408,   414,   421,
     430,   439,   448,   459,   469,   480,   482,   488,   503,   519,
     524,   524,   525,   525,   532,   533,   540,   549,   597,   598,
     602,   604,   607,   610,   613,   617,   628,   629,   630,   631,
     634,   635,   636,   637,   640,   643,   644,   645,   646,   647,
     648,   652,   678,   679,   682
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
  "scope_marker", "function", "params", "param_list", "param", "type",
  "idents", "literal", "var", "dec_list", "dec", "statements", "state",
  "assign_state", "if_state", "while_state", "do_while_state", "for_state",
  "for_h", "advance_exp", "rt_state", "bl_state", "$@1", "$@2",
  "func_call_state", "func_call", "exp_list", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-80)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-38)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -15,    63,    24,   -80,   -15,   -18,   -80,   -80,    23,    25,
      22,   -80,    36,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,    38,    39,    23,    90,    41,   -80,   -80,    85,    25,
     -80,    25,   -80,    85,    77,    80,    62,   -80,   -80,   144,
     109,    93,   -80,   -80,   -80,   -80,   -38,   178,   178,    73,
      65,   178,   -80,   117,   178,   198,   178,   178,   -80,    97,
      99,   144,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
      78,   288,    -6,    81,   144,   149,   178,    72,   207,   -80,
     448,   467,   130,    86,   -11,   308,   144,    91,    35,   -35,
     -80,   -80,   505,   -80,   -80,   -80,   -80,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   -80,
      17,   139,   -80,   114,    92,   212,   104,   328,   260,   178,
      72,   -11,   -11,   103,   -11,   138,   -80,   131,    89,   178,
     -80,   144,   534,    67,   543,   543,    33,    33,    33,    33,
      35,    35,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   107,   -80,   -80,    32,   -80,   -80,   118,   274,
      69,   -80,   178,     2,   -80,   178,   -80,   -80,   119,   245,
     348,   142,   116,   -80,   228,   -80,   178,   125,   368,   -80,
     -80,   388,   -80,   178,   -80,   -80,   172,   126,   133,   136,
     408,   486,   -11,   178,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -11,   -80,   428,   177,   184,   145,   157,   155,   -11,
     178,   -80,   -80,   523
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     1,     3,     8,     0,
       0,     9,    10,    15,    14,    13,    17,    16,    19,    18,
      20,     0,     0,     0,     0,    32,    11,    12,     0,     0,
       5,     0,    33,    34,    32,     0,     0,    35,     5,    50,
       0,     0,    81,    82,    83,    84,    85,    80,    80,     0,
       0,    80,    70,     0,    80,    80,    80,    80,    40,     0,
       0,    50,    41,    42,    43,    45,    44,    47,    46,    48,
     104,     0,    22,     0,    50,    80,    80,    85,    80,   104,
       0,     0,     0,     0,     0,     0,    50,     0,    90,    85,
      93,    91,     0,    72,     7,    39,    74,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    49,
       0,     0,    36,     0,     0,    80,   104,     0,     0,    80,
      85,     0,     0,     0,     0,     0,    69,     0,    80,    80,
      94,    50,   102,   103,    95,    96,    97,    98,    99,   100,
      86,    87,    88,    89,    25,    30,    28,    29,    31,    26,
      27,    21,     0,     6,    55,    85,    75,    51,   101,     0,
      59,    63,    80,     0,    65,    80,    71,    76,     0,    78,
       0,     0,    23,    54,    80,   101,    80,     0,     0,    70,
      66,     0,    77,    80,    53,    73,     0,    81,    83,    84,
       0,     0,     0,    80,    64,    79,    24,    56,    52,    57,
      58,     0,    60,     0,    61,     0,     0,     0,     0,     0,
      80,    67,    62,    68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   196,   169,    14,   -80,   185,   -80,    40,   -80,
     -80,   -23,   187,   -80,   -48,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -79,   -80,   -80,   -80,   -12,    42,
     -47
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    35,    58,    10,    11,    12,    21,    73,
     151,    59,    32,    33,    60,    61,    62,    63,    64,    65,
      66,    83,   208,    67,    68,    86,   131,    69,    79,   168,
      71
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      80,    81,    30,    75,    85,   125,   129,    88,    90,    91,
      92,    38,    28,    95,     4,     1,    76,    52,     4,   119,
     144,   145,   146,   147,     6,    28,   113,    70,   117,   118,
     179,    90,     8,    13,    14,    15,    16,    17,   127,    18,
      19,    20,   160,   161,   148,   164,   110,     9,   111,    70,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    70,   116,    28,   149,   150,    29,    91,    34,
       5,    36,   159,    22,    70,   105,   106,   107,   108,   107,
     108,   169,   170,   171,   180,   173,   119,   176,   177,    23,
      24,    25,    42,    43,    44,    45,    77,    27,    31,    97,
      28,   163,    99,   100,   101,   102,   103,   104,    39,   105,
     106,   107,   108,   202,    40,   178,    72,    84,   181,    70,
      53,    74,   204,    82,    87,    93,   119,   190,    94,   191,
     212,    96,    54,    78,   112,    56,   169,   123,   124,    57,
     167,   128,   152,   153,   162,   154,   203,    42,    43,    44,
      45,    46,    42,    43,    44,    45,    77,   156,   165,   174,
     166,    47,   172,   213,    48,    49,    50,    28,   186,    51,
     182,   185,    52,   -37,     1,    53,   114,   192,   196,   197,
      53,    42,    43,    44,    45,    77,   198,    54,    55,   199,
      56,   207,    54,    78,    57,   115,   206,   209,   210,    57,
       7,    42,    43,    44,    45,    89,   211,    41,    26,    53,
      42,    43,    44,    45,   120,    42,    43,    44,    45,   155,
      37,    54,    78,     0,    56,   195,     0,     0,    57,    53,
       0,   187,    43,   188,   189,    77,     0,     0,    53,     0,
       0,    54,    78,    53,    56,     0,     0,     0,    57,     0,
      54,    78,     0,    56,     0,    54,    78,    57,    56,    53,
       0,     0,    57,     0,     0,     0,     0,     0,     0,     0,
       0,    54,    78,     0,    56,     0,     0,    97,    57,    98,
      99,   100,   101,   102,   103,   104,     0,   105,   106,   107,
     108,     0,    97,     0,    98,    99,   100,   101,   102,   103,
     104,   183,   105,   106,   107,   108,    97,     0,    98,    99,
     100,   101,   102,   103,   104,   158,   105,   106,   107,   108,
      97,     0,    98,    99,   100,   101,   102,   103,   104,   175,
     105,   106,   107,   108,     0,     0,     0,     0,     0,     0,
      97,   109,    98,    99,   100,   101,   102,   103,   104,     0,
     105,   106,   107,   108,     0,     0,     0,     0,     0,     0,
      97,   126,    98,    99,   100,   101,   102,   103,   104,     0,
     105,   106,   107,   108,     0,     0,     0,     0,     0,     0,
      97,   157,    98,    99,   100,   101,   102,   103,   104,     0,
     105,   106,   107,   108,     0,     0,     0,     0,     0,     0,
      97,   184,    98,    99,   100,   101,   102,   103,   104,     0,
     105,   106,   107,   108,     0,     0,     0,     0,     0,     0,
      97,   193,    98,    99,   100,   101,   102,   103,   104,     0,
     105,   106,   107,   108,     0,     0,     0,     0,     0,     0,
      97,   194,    98,    99,   100,   101,   102,   103,   104,     0,
     105,   106,   107,   108,     0,     0,     0,     0,     0,     0,
      97,   200,    98,    99,   100,   101,   102,   103,   104,     0,
     105,   106,   107,   108,     0,     0,     0,     0,     0,     0,
      97,   205,    98,    99,   100,   101,   102,   103,   104,     0,
     105,   106,   107,   108,     0,     0,     0,     0,     0,    97,
     121,    98,    99,   100,   101,   102,   103,   104,     0,   105,
     106,   107,   108,     0,     0,     0,     0,     0,    97,   122,
      98,    99,   100,   101,   102,   103,   104,     0,   105,   106,
     107,   108,     0,     0,     0,     0,     0,    97,   201,    98,
      99,   100,   101,   102,   103,   104,     0,   105,   106,   107,
     108,     0,     0,     0,     0,    97,   130,    98,    99,   100,
     101,   102,   103,   104,     0,   105,   106,   107,   108,    99,
     100,   101,   102,   103,   104,     0,   105,   106,   107,   108,
     101,   102,   103,   104,     0,   105,   106,   107,   108
};

static const yytype_int16 yycheck[] =
{
      47,    48,    25,    41,    51,    84,    41,    54,    55,    56,
      57,    34,    23,    61,     0,    30,    54,    28,     4,    54,
       3,     4,     5,     6,     0,    23,    74,    39,    75,    76,
      28,    78,    50,     8,     9,    10,    11,    12,    86,    14,
      15,    16,   121,   122,    27,   124,    52,    24,    54,    61,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    74,    75,    23,    48,    49,    26,   115,    29,
       7,    31,   119,    51,    86,    42,    43,    44,    45,    44,
      45,   128,   129,   131,   163,    53,    54,    18,    19,    53,
      52,    52,     3,     4,     5,     6,     7,     7,    13,    32,
      23,   124,    35,    36,    37,    38,    39,    40,    28,    42,
      43,    44,    45,   192,    52,   162,     7,    52,   165,   131,
      31,    28,   201,    50,     7,    28,    54,   174,    29,   176,
     209,    53,    43,    44,    53,    46,   183,     7,    52,    50,
      51,    50,     3,    29,    41,    53,   193,     3,     4,     5,
       6,     7,     3,     4,     5,     6,     7,    53,    20,    41,
      29,    17,    55,   210,    20,    21,    22,    23,    52,    25,
      51,    29,    28,    29,    30,    31,    27,    52,     6,    53,
      31,     3,     4,     5,     6,     7,    53,    43,    44,    53,
      46,     7,    43,    44,    50,    46,    19,    52,    41,    50,
       4,     3,     4,     5,     6,     7,    51,    38,    23,    31,
       3,     4,     5,     6,     7,     3,     4,     5,     6,     7,
      33,    43,    44,    -1,    46,   183,    -1,    -1,    50,    31,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    31,    -1,
      -1,    43,    44,    31,    46,    -1,    -1,    -1,    50,    -1,
      43,    44,    -1,    46,    -1,    43,    44,    50,    46,    31,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    -1,    46,    -1,    -1,    32,    50,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    43,    44,
      45,    -1,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    56,    42,    43,    44,    45,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    55,    42,    43,    44,    45,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    55,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    53,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    53,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    53,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    53,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    53,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    53,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    53,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    53,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    32,
      52,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      43,    44,    45,    -1,    -1,    -1,    -1,    -1,    32,    52,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    32,    52,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    32,    51,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    44,    45,    35,
      36,    37,    38,    39,    40,    -1,    42,    43,    44,    45,
      37,    38,    39,    40,    -1,    42,    43,    44,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,    58,    59,    61,     7,     0,    59,    50,    24,
      62,    63,    64,     8,     9,    10,    11,    12,    14,    15,
      16,    65,    51,    53,    52,    52,    63,     7,    23,    26,
      68,    13,    69,    70,    65,    60,    65,    69,    68,    28,
      52,    60,     3,     4,     5,     6,     7,    17,    20,    21,
      22,    25,    28,    31,    43,    44,    46,    50,    61,    68,
      71,    72,    73,    74,    75,    76,    77,    80,    81,    84,
      85,    87,     7,    66,    28,    41,    54,     7,    44,    85,
      87,    87,    50,    78,    52,    87,    82,     7,    87,     7,
      87,    87,    87,    28,    29,    71,    53,    32,    34,    35,
      36,    37,    38,    39,    40,    42,    43,    44,    45,    53,
      52,    54,    53,    71,    27,    46,    85,    87,    87,    54,
       7,    52,    52,     7,    52,    81,    53,    71,    50,    41,
      51,    83,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,     3,     4,     5,     6,    27,    48,
      49,    67,     3,    29,    53,     7,    53,    53,    55,    87,
      81,    81,    41,    68,    81,    20,    29,    51,    86,    87,
      87,    71,    55,    53,    41,    55,    18,    19,    87,    28,
      81,    87,    51,    56,    53,    29,    52,     3,     5,     6,
      87,    87,    52,    53,    53,    86,     6,    53,    53,    53,
      53,    52,    81,    87,    81,    53,    19,     7,    79,    52,
      41,    51,    81,    87
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    61,    61,    62,    62,
      63,    63,    64,    65,    65,    65,    65,    65,    65,    65,
      65,    66,    66,    66,    66,    67,    67,    67,    67,    67,
      67,    67,    68,    68,    69,    69,    70,    71,    71,    71,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    74,
      74,    74,    74,    75,    76,    77,    77,    78,    79,    80,
      82,    81,    83,    81,    84,    84,    85,    85,    86,    86,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     0,    13,    11,     0,     1,
       1,     3,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     4,     6,     1,     1,     1,     1,     1,
       1,     1,     0,     2,     1,     2,     5,     0,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     4,     7,     5,     5,     4,     7,     7,     7,     4,
       7,     8,    11,     4,     6,     4,     5,     9,     3,     3,
       0,     4,     0,     5,     2,     4,     4,     5,     1,     3,
       0,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     4,     3,     3,     1
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
#line 103 "part1_EL.y"
              {
        ASTRoot = mknode("CODE", (yyvsp[0].nodePtr), NULL);
    }
#line 1420 "part1_EL.tab.c"
    break;

  case 3: /* functions: function functions  */
#line 111 "part1_EL.y"
                                           { (yyval.nodePtr) = mknode("FUNCS",(yyvsp[-1].nodePtr),(yyvsp[0].nodePtr)); }
#line 1426 "part1_EL.tab.c"
    break;

  case 4: /* functions: function  */
#line 112 "part1_EL.y"
                                             { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1432 "part1_EL.tab.c"
    break;

  case 5: /* scope_marker: %empty  */
#line 116 "part1_EL.y"
              { pushScope(); }
#line 1438 "part1_EL.tab.c"
    break;

  case 6: /* function: DEF IDENT '(' params ')' ':' RETURNS type var scope_marker T_BEGIN statements END  */
#line 120 "part1_EL.y"
    {
        popScope();
        if (moreThanOneMain((yyvsp[-11].stringVal))) YYABORT;

        if (strcmp((yyvsp[-11].stringVal), "_main_") == 0) {
            if ((yyvsp[-9].nodePtr) != NULL) {
                yyerror("Semantic Error: '_main_' function must not take parameters.");
                YYABORT;
            }
            if (strcmp((yyvsp[-5].nodePtr)->token, "void") != 0) {
                yyerror("Semantic Error: '_main_' function must not return a value.");
                YYABORT;
            }
        }

        char* paramTypes[MAX_PARAMS];
        int paramCount = 0;
        node* curParam = (yyvsp[-9].nodePtr);

        while (curParam && paramCount < MAX_PARAMS) {
            if (strcmp(curParam->token, "PARAMS") == 0) {
                node* single = curParam->left;
                if (single && strcmp(single->token, "PARAM") == 0 && single->left) {
                    char* rawType = single->left->token;
                    char* lowered = strdup(rawType);
                    for (char* p = lowered; *p; p++) *p = tolower(*p);
                    paramTypes[paramCount++] = lowered;
                }
                curParam = curParam->right;
            } else if (strcmp(curParam->token, "PARAM") == 0) {
                char* rawType = curParam->left->token;
                char* lowered = strdup(rawType);
                for (char* p = lowered; *p; p++) *p = tolower(*p);
                paramTypes[paramCount++] = lowered;
                break;
            } else {
                break;
            }
        }

        char* returnType = strdup((yyvsp[-5].nodePtr)->token);
        for (char* p = returnType; *p; p++) *p = tolower(*p);

        if (strcmp(returnType, "string") == 0) 
        {
        yyerror("Semantic Error: Functions cannot return type 'string'.");
        YYABORT;
        }

        // Rule 9 check: return statements must match declared return type
        if (!validateReturnType((yyvsp[-1].nodePtr), returnType)) 
        {
        YYABORT;
        }

        if (insertSymbol((yyvsp[-11].stringVal), FUNC, returnType, paramCount, "global", paramTypes)) 
        {
            yyerror("Semantic Error: Function already declared in the same scope.");
            YYABORT;
        }

        node* idN = mknode((yyvsp[-11].stringVal), NULL, NULL);
        node* paramsN = mknode("PARAMS", (yyvsp[-9].nodePtr), NULL);
        node* returnsN = mknode("RETURNS", (yyvsp[-5].nodePtr), NULL);
        node* bodyN = mknode("BODY", (yyvsp[-4].nodePtr), (yyvsp[-1].nodePtr));  // $9 = var, $12 = statements
        node* defBodyN = mknode("DEF_BODY", returnsN, bodyN);
        (yyval.nodePtr) = mknode("FUNCTION", idN, mknode("FUNC_IN", paramsN, defBodyN));
    }
#line 1511 "part1_EL.tab.c"
    break;

  case 7: /* function: DEF IDENT '(' params ')' ':' var scope_marker T_BEGIN statements END  */
#line 190 "part1_EL.y"
    {
        popScope();
        if (moreThanOneMain((yyvsp[-9].stringVal))) YYABORT;

        if (strcmp((yyvsp[-9].stringVal), "_main_") == 0) {
            if ((yyvsp[-7].nodePtr) != NULL) {
                yyerror("Semantic Error: '_main_' function must not take parameters.");
                YYABORT;
            }
        }

        char* paramTypes[MAX_PARAMS];
        int paramCount = 0;
        node* curParam = (yyvsp[-7].nodePtr);

        while (curParam && paramCount < MAX_PARAMS) {
            if (strcmp(curParam->token, "PARAMS") == 0) {
                node* single = curParam->left;
                if (single && strcmp(single->token, "PARAM") == 0 && single->left) {
                    char* rawType = single->left->token;
                    char* lowered = strdup(rawType);
                    for (char* p = lowered; *p; p++) *p = tolower(*p);
                    paramTypes[paramCount++] = lowered;
                }
                curParam = curParam->right;
            } else if (strcmp(curParam->token, "PARAM") == 0) {
                char* rawType = curParam->left->token;
                char* lowered = strdup(rawType);
                for (char* p = lowered; *p; p++) *p = tolower(*p);
                paramTypes[paramCount++] = lowered;
                break;
            } else {
                break;
            }
        }

        char* returnType = strdup("void");

        if (insertSymbol((yyvsp[-9].stringVal), FUNC, returnType, paramCount, "global", paramTypes)) {
            yyerror("Semantic Error: Function already declared in the same scope.");
            YYABORT;
        }

        node* idN = mknode((yyvsp[-9].stringVal), NULL, NULL);
        node* paramsN = mknode("PARAMS", (yyvsp[-7].nodePtr), NULL);
        node* bodyN = mknode("BODY", (yyvsp[-4].nodePtr), (yyvsp[-1].nodePtr));  // $7 = var, $10 = statements
        (yyval.nodePtr) = mknode("PROC", idN, mknode("PROC_IN", paramsN, bodyN));
    }
#line 1564 "part1_EL.tab.c"
    break;

  case 8: /* params: %empty  */
#line 243 "part1_EL.y"
    { (yyval.nodePtr) = NULL; }
#line 1570 "part1_EL.tab.c"
    break;

  case 9: /* params: param_list  */
#line 244 "part1_EL.y"
                                      { (yyval.nodePtr) = (yyvsp[0].nodePtr);   }
#line 1576 "part1_EL.tab.c"
    break;

  case 10: /* param_list: param  */
#line 248 "part1_EL.y"
                                    { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1582 "part1_EL.tab.c"
    break;

  case 11: /* param_list: param ';' param_list  */
#line 249 "part1_EL.y"
                                  { (yyval.nodePtr) = mknode("PARAMS",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1588 "part1_EL.tab.c"
    break;

  case 12: /* param: PAR type ':' IDENT  */
#line 253 "part1_EL.y"
                               {(yyval.nodePtr)=mknode("PARAM",(yyvsp[-2].nodePtr),mknode((yyvsp[0].stringVal),NULL,NULL));}
#line 1594 "part1_EL.tab.c"
    break;

  case 13: /* type: INT  */
#line 259 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("INT",NULL,NULL);  }
#line 1600 "part1_EL.tab.c"
    break;

  case 14: /* type: CHAR  */
#line 260 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("CHAR",NULL,NULL); }
#line 1606 "part1_EL.tab.c"
    break;

  case 15: /* type: BOOL  */
#line 261 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("BOOL",NULL,NULL); }
#line 1612 "part1_EL.tab.c"
    break;

  case 16: /* type: STRING  */
#line 262 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("STRING",NULL,NULL);}
#line 1618 "part1_EL.tab.c"
    break;

  case 17: /* type: REAL  */
#line 263 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("REAL",NULL,NULL); }
#line 1624 "part1_EL.tab.c"
    break;

  case 18: /* type: CHARPTR  */
#line 264 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("CHARPTR",NULL,NULL);}
#line 1630 "part1_EL.tab.c"
    break;

  case 19: /* type: INTPTR  */
#line 265 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("INTPTR",NULL,NULL);}
#line 1636 "part1_EL.tab.c"
    break;

  case 20: /* type: REALPTR  */
#line 266 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("REALPTR",NULL,NULL);}
#line 1642 "part1_EL.tab.c"
    break;

  case 21: /* idents: IDENT ':' literal  */
#line 272 "part1_EL.y"
        { (yyval.nodePtr) = mknode("VAR_ASSIGN", mknode("IDENT", mknode((yyvsp[-2].stringVal),NULL,NULL), NULL), (yyvsp[0].nodePtr)); }
#line 1648 "part1_EL.tab.c"
    break;

  case 22: /* idents: IDENT  */
#line 275 "part1_EL.y"
        { (yyval.nodePtr) = mknode("VAR_DECL", mknode("IDENT", mknode((yyvsp[0].stringVal), NULL, NULL), NULL), NULL); }
#line 1654 "part1_EL.tab.c"
    break;

  case 23: /* idents: IDENT '[' INT_LIT ']'  */
#line 278 "part1_EL.y"
        { char sz[32]; sprintf(sz,"%d",(yyvsp[-1].intVal));
         (yyval.nodePtr) = mknode("ARRAY_DECL", mknode("IDENT", mknode((yyvsp[-3].stringVal), NULL, NULL), NULL), mknode(sz, NULL, NULL)); }
#line 1661 "part1_EL.tab.c"
    break;

  case 24: /* idents: IDENT '[' INT_LIT ']' ':' STRING_LIT  */
#line 282 "part1_EL.y"
    {
    char sizeStr[32];
    sprintf(sizeStr, "%d", (yyvsp[-3].intVal)); // Convert INT_LIT to string

    (yyval.nodePtr) = mknode("ARRAY_INIT",
                mknode("ARRAY_DECL", mknode("IDENT", mknode((yyvsp[-5].stringVal), NULL, NULL), NULL), mknode(sizeStr, NULL, NULL)),
                mknode((yyvsp[0].stringVal), NULL, NULL)); 
    }
#line 1674 "part1_EL.tab.c"
    break;

  case 25: /* literal: INT_LIT  */
#line 294 "part1_EL.y"
                       { char ibuf[32]; sprintf(ibuf,"%d",(yyvsp[0].intVal)); (yyval.nodePtr) = mknode("INT", mknode(ibuf,NULL,NULL), NULL); }
#line 1680 "part1_EL.tab.c"
    break;

  case 26: /* literal: TRUE  */
#line 295 "part1_EL.y"
                       { (yyval.nodePtr) = mknode("BOOL", mknode("true", NULL, NULL), NULL); }
#line 1686 "part1_EL.tab.c"
    break;

  case 27: /* literal: FALSE  */
#line 296 "part1_EL.y"
                       { (yyval.nodePtr) = mknode("BOOL", mknode("false", NULL, NULL), NULL); }
#line 1692 "part1_EL.tab.c"
    break;

  case 28: /* literal: CHAR_LIT  */
#line 297 "part1_EL.y"
                       { char cbuf[2] = {(yyvsp[0].charVal),'\0'}; (yyval.nodePtr) = mknode("CHAR", mknode(cbuf,NULL,NULL), NULL); }
#line 1698 "part1_EL.tab.c"
    break;

  case 29: /* literal: STRING_LIT  */
#line 298 "part1_EL.y"
                       { (yyval.nodePtr) = mknode("STRING", mknode((yyvsp[0].stringVal), NULL, NULL), NULL); }
#line 1704 "part1_EL.tab.c"
    break;

  case 30: /* literal: REAL_LIT  */
#line 299 "part1_EL.y"
                       { char r[64]; sprintf(r,"%f",(yyvsp[0].realVal));
                        (yyval.nodePtr) = mknode("REAL", mknode(r,NULL,NULL), NULL); }
#line 1711 "part1_EL.tab.c"
    break;

  case 31: /* literal: NULLL  */
#line 301 "part1_EL.y"
                       { (yyval.nodePtr) = mknode("NULL", NULL, NULL); }
#line 1717 "part1_EL.tab.c"
    break;

  case 32: /* var: %empty  */
#line 306 "part1_EL.y"
    { (yyval.nodePtr) = NULL; }
#line 1723 "part1_EL.tab.c"
    break;

  case 33: /* var: VARIABLE dec_list  */
#line 307 "part1_EL.y"
                                       { (yyval.nodePtr) = mknode("VAR",(yyvsp[0].nodePtr),NULL); }
#line 1729 "part1_EL.tab.c"
    break;

  case 34: /* dec_list: dec  */
#line 311 "part1_EL.y"
                               { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1735 "part1_EL.tab.c"
    break;

  case 35: /* dec_list: dec dec_list  */
#line 312 "part1_EL.y"
                          { (yyval.nodePtr) = mknode("DECS",(yyvsp[-1].nodePtr),(yyvsp[0].nodePtr)); }
#line 1741 "part1_EL.tab.c"
    break;

  case 36: /* dec: TYPE type ':' idents ';'  */
#line 317 "part1_EL.y"
    {
        node* declList = (yyvsp[-1].nodePtr);
        char* typeStr = (yyvsp[-3].nodePtr)->token;

        while (declList) {
            if (strcmp(declList->token, "VAR_DECL") == 0 || strcmp(declList->token, "VAR_ASSIGN") == 0) {
                node* idNode = declList->left;
                if (idNode && strcmp(idNode->token, "IDENT") == 0 && idNode->left) {
                    char* varName = idNode->left->token;
                    if (insertSymbol(varName, VAR, typeStr, 0, "block", NULL))
                    {                       
                        yyerror("Semantic Error: Variable already declared in this scope.");
                        YYABORT;
                    }
                }
            }
            declList = declList->right;
        }

        (yyval.nodePtr) = mknode("DECL", (yyvsp[-3].nodePtr), (yyvsp[-1].nodePtr));
    }
#line 1767 "part1_EL.tab.c"
    break;

  case 37: /* statements: %empty  */
#line 342 "part1_EL.y"
     {(yyval.nodePtr) = mknode("", NULL,NULL);}
#line 1773 "part1_EL.tab.c"
    break;

  case 38: /* statements: state  */
#line 343 "part1_EL.y"
                    {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1779 "part1_EL.tab.c"
    break;

  case 39: /* statements: state statements  */
#line 344 "part1_EL.y"
                               {(yyval.nodePtr) = mknode("statements", (yyvsp[-1].nodePtr), (yyvsp[0].nodePtr));}
#line 1785 "part1_EL.tab.c"
    break;

  case 40: /* state: function  */
#line 350 "part1_EL.y"
                     {(yyval.nodePtr)=(yyvsp[0].nodePtr);}
#line 1791 "part1_EL.tab.c"
    break;

  case 41: /* state: assign_state  */
#line 351 "part1_EL.y"
                           {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1797 "part1_EL.tab.c"
    break;

  case 42: /* state: if_state  */
#line 352 "part1_EL.y"
                       {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1803 "part1_EL.tab.c"
    break;

  case 43: /* state: while_state  */
#line 353 "part1_EL.y"
                          {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1809 "part1_EL.tab.c"
    break;

  case 44: /* state: for_state  */
#line 354 "part1_EL.y"
                        {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1815 "part1_EL.tab.c"
    break;

  case 45: /* state: do_while_state  */
#line 355 "part1_EL.y"
                             {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1821 "part1_EL.tab.c"
    break;

  case 46: /* state: bl_state  */
#line 356 "part1_EL.y"
                       {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1827 "part1_EL.tab.c"
    break;

  case 47: /* state: rt_state  */
#line 357 "part1_EL.y"
                       {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1833 "part1_EL.tab.c"
    break;

  case 48: /* state: func_call_state  */
#line 358 "part1_EL.y"
                              {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1839 "part1_EL.tab.c"
    break;

  case 49: /* state: expression ';'  */
#line 359 "part1_EL.y"
                             { (yyval.nodePtr) = (yyvsp[-1].nodePtr); }
#line 1845 "part1_EL.tab.c"
    break;

  case 51: /* assign_state: IDENT ASSIGN expression ';'  */
#line 365 "part1_EL.y"
                                   {
    if (!isVarDeclaredInScope((yyvsp[-3].stringVal))) {
        char msg[128];
        sprintf(msg, "Semantic Error: Variable '%s' used before declaration.", (yyvsp[-3].stringVal));
        yyerror(msg);
        YYABORT;
    }
    (yyval.nodePtr) = mknode("assign", mknode((yyvsp[-3].stringVal),NULL,NULL), (yyvsp[-1].nodePtr));
}
#line 1859 "part1_EL.tab.c"
    break;

  case 52: /* assign_state: IDENT '[' expression ']' ASSIGN CHAR_LIT ';'  */
#line 377 "part1_EL.y"
                                                   {
          char cbuf[2]={(yyvsp[-1].charVal),'\0'};
          (yyval.nodePtr) = mknode("array_assign",
                      mknode((yyvsp[-6].stringVal),(yyvsp[-4].nodePtr),NULL),
                      mknode(cbuf,NULL,NULL)); }
#line 1869 "part1_EL.tab.c"
    break;

  case 53: /* assign_state: MULTI IDENT ASSIGN expression ';'  */
#line 384 "part1_EL.y"
                                        {
          (yyval.nodePtr) = mknode("pointer_assign",
                      mknode((yyvsp[-3].stringVal),NULL,NULL), (yyvsp[-1].nodePtr)); }
#line 1877 "part1_EL.tab.c"
    break;

  case 54: /* assign_state: IDENT ASSIGN ADDRESS IDENT ';'  */
#line 389 "part1_EL.y"
                                     {
          (yyval.nodePtr) = mknode("adder_assign",
                      mknode((yyvsp[-4].stringVal),NULL,NULL),
                      mknode((yyvsp[-1].stringVal),NULL,NULL)); }
#line 1886 "part1_EL.tab.c"
    break;

  case 55: /* assign_state: IDENT ASSIGN NULLL ';'  */
#line 395 "part1_EL.y"
                             {
          (yyval.nodePtr) = mknode("null_assign",
                      mknode((yyvsp[-3].stringVal),NULL,NULL),
                      mknode("null",NULL,NULL)); }
#line 1895 "part1_EL.tab.c"
    break;

  case 56: /* assign_state: IDENT '[' expression ']' ASSIGN INT_LIT ';'  */
#line 401 "part1_EL.y"
                                                  {
          char buf[32]; sprintf(buf,"%d",(yyvsp[-1].intVal));
          (yyval.nodePtr) = mknode("array_assign",
                      mknode((yyvsp[-6].stringVal),(yyvsp[-4].nodePtr),NULL),
                      mknode(buf,NULL,NULL)); }
#line 1905 "part1_EL.tab.c"
    break;

  case 57: /* assign_state: IDENT '[' expression ']' ASSIGN STRING_LIT ';'  */
#line 408 "part1_EL.y"
                                                     {
          (yyval.nodePtr) = mknode("array_assign",
                      mknode((yyvsp[-6].stringVal),(yyvsp[-4].nodePtr),NULL),
                      mknode((yyvsp[-1].stringVal),NULL,NULL)); }
#line 1914 "part1_EL.tab.c"
    break;

  case 58: /* assign_state: IDENT '[' expression ']' ASSIGN expression ';'  */
#line 414 "part1_EL.y"
                                                     {
          (yyval.nodePtr) = mknode("array_assign",
                      mknode((yyvsp[-6].stringVal),(yyvsp[-4].nodePtr),NULL), (yyvsp[-1].nodePtr)); }
#line 1922 "part1_EL.tab.c"
    break;

  case 59: /* if_state: IF expression ':' bl_state  */
#line 422 "part1_EL.y"
    {
        if (strcmp(inferExprType((yyvsp[-2].nodePtr)), "bool") != 0) {
            yyerror("Semantic Error: IF condition must be of type 'bool'.");
            YYABORT;
        }
        (yyval.nodePtr) = mknode("if", (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr));
    }
#line 1934 "part1_EL.tab.c"
    break;

  case 60: /* if_state: IF expression ':' bl_state ELSE ':' bl_state  */
#line 431 "part1_EL.y"
    {
        if (strcmp(inferExprType((yyvsp[-5].nodePtr)), "bool") != 0) {
            yyerror("Semantic Error: IF condition must be of type 'bool'.");
            YYABORT;
        }
        (yyval.nodePtr) = mknode("if_else", (yyvsp[-5].nodePtr), mknode("then", (yyvsp[-3].nodePtr), mknode("else", (yyvsp[0].nodePtr), NULL)));
    }
#line 1946 "part1_EL.tab.c"
    break;

  case 61: /* if_state: IF expression ':' bl_state ELIF expression ':' bl_state  */
#line 440 "part1_EL.y"
    {
        if (strcmp(inferExprType((yyvsp[-6].nodePtr)), "bool") != 0 || strcmp(inferExprType((yyvsp[-2].nodePtr)), "bool") != 0) {
            yyerror("Semantic Error: IF and ELIF conditions must be of type 'bool'.");
            YYABORT;
        }
        (yyval.nodePtr) = mknode("if_elif", (yyvsp[-6].nodePtr), mknode("then", (yyvsp[-4].nodePtr), mknode("elif", (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr))));
    }
#line 1958 "part1_EL.tab.c"
    break;

  case 62: /* if_state: IF expression ':' bl_state ELIF expression ':' bl_state ELSE ':' bl_state  */
#line 449 "part1_EL.y"
    {
        if (strcmp(inferExprType((yyvsp[-9].nodePtr)), "bool") != 0 || strcmp(inferExprType((yyvsp[-5].nodePtr)), "bool") != 0) {
            yyerror("Semantic Error: IF and ELIF conditions must be of type 'bool'.");
            YYABORT;
        }
        (yyval.nodePtr) = mknode("if_elif-else", (yyvsp[-9].nodePtr), mknode("then", (yyvsp[-7].nodePtr), mknode("elif", (yyvsp[-5].nodePtr), mknode("elif-then", (yyvsp[-3].nodePtr), mknode("else", (yyvsp[0].nodePtr), NULL)))));
    }
#line 1970 "part1_EL.tab.c"
    break;

  case 63: /* while_state: WHILE expression ':' bl_state  */
#line 460 "part1_EL.y"
    {
        if (strcmp(inferExprType((yyvsp[-2].nodePtr)), "bool") != 0) {
            yyerror("Semantic Error: WHILE condition must be of type 'bool'.");
            YYABORT;
        }
        (yyval.nodePtr) = mknode("while", (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr));
    }
#line 1982 "part1_EL.tab.c"
    break;

  case 64: /* do_while_state: DO ':' bl_state WHILE expression ';'  */
#line 470 "part1_EL.y"
    {
        if (strcmp(inferExprType((yyvsp[-1].nodePtr)), "bool") != 0) {
            yyerror("Semantic Error: DO-WHILE condition must be of type 'bool'.");
            YYABORT;
        }
        (yyval.nodePtr) = mknode("do_while", (yyvsp[-3].nodePtr), mknode("condition", (yyvsp[-1].nodePtr), NULL));
    }
#line 1994 "part1_EL.tab.c"
    break;

  case 65: /* for_state: FOR for_h ':' bl_state  */
#line 480 "part1_EL.y"
                                       {
          (yyval.nodePtr) = mknode("for",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2001 "part1_EL.tab.c"
    break;

  case 66: /* for_state: FOR for_h ':' var bl_state  */
#line 482 "part1_EL.y"
                                        {
          (yyval.nodePtr) = mknode("for",(yyvsp[-3].nodePtr),
                      mknode("block",(yyvsp[0].nodePtr),(yyvsp[-1].nodePtr))); }
#line 2009 "part1_EL.tab.c"
    break;

  case 67: /* for_h: '(' IDENT ASSIGN expression ';' expression ';' advance_exp ')'  */
#line 491 "part1_EL.y"
    {
        if (strcmp(inferExprType((yyvsp[-3].nodePtr)), "bool") != 0) {
            yyerror("Semantic Error: FOR condition must be of type 'bool'.");
            YYABORT;
        }
        (yyval.nodePtr) = mknode("for_header",
                    mknode("init", mknode((yyvsp[-7].stringVal), NULL, NULL), (yyvsp[-5].nodePtr)),
                    mknode("loop", (yyvsp[-3].nodePtr), (yyvsp[-1].nodePtr)));
    }
#line 2023 "part1_EL.tab.c"
    break;

  case 68: /* advance_exp: IDENT ASSIGN expression  */
#line 503 "part1_EL.y"
                                             {
          (yyval.nodePtr) = mknode("update",
                      mknode((yyvsp[-2].stringVal),NULL,NULL),(yyvsp[0].nodePtr)); }
#line 2031 "part1_EL.tab.c"
    break;

  case 69: /* rt_state: RETURN expression ';'  */
#line 519 "part1_EL.y"
                                                 { (yyval.nodePtr) = mknode("return",(yyvsp[-1].nodePtr),NULL); }
#line 2037 "part1_EL.tab.c"
    break;

  case 70: /* $@1: %empty  */
#line 524 "part1_EL.y"
            { pushScope(); }
#line 2043 "part1_EL.tab.c"
    break;

  case 71: /* bl_state: T_BEGIN $@1 statements END  */
#line 524 "part1_EL.y"
                                            { popScope(); (yyval.nodePtr) = mknode("block", (yyvsp[-1].nodePtr), NULL); }
#line 2049 "part1_EL.tab.c"
    break;

  case 72: /* $@2: %empty  */
#line 525 "part1_EL.y"
                { pushScope(); }
#line 2055 "part1_EL.tab.c"
    break;

  case 73: /* bl_state: var T_BEGIN $@2 statements END  */
#line 525 "part1_EL.y"
                                                { popScope(); (yyval.nodePtr) = mknode("block", (yyvsp[-1].nodePtr), (yyvsp[-4].nodePtr)); }
#line 2061 "part1_EL.tab.c"
    break;

  case 74: /* func_call_state: func_call ';'  */
#line 532 "part1_EL.y"
                                              { (yyval.nodePtr) = (yyvsp[-1].nodePtr); }
#line 2067 "part1_EL.tab.c"
    break;

  case 75: /* func_call_state: IDENT ASSIGN func_call ';'  */
#line 533 "part1_EL.y"
                                          {
          (yyval.nodePtr) = mknode("assign",
                      mknode((yyvsp[-3].stringVal),NULL,NULL),(yyvsp[-1].nodePtr)); }
#line 2075 "part1_EL.tab.c"
    break;

  case 76: /* func_call: CALL IDENT '(' ')'  */
#line 540 "part1_EL.y"
                         {
          Symbol* f = lookupSymbol((yyvsp[-2].stringVal));
          if (!f || f->type != FUNC) {
              yyerror("Semantic Error: Function called before definition.");
              YYABORT;
          }
          (yyval.nodePtr) = mknode("call", mknode((yyvsp[-2].stringVal),NULL,NULL), NULL);
      }
#line 2088 "part1_EL.tab.c"
    break;

  case 77: /* func_call: CALL IDENT '(' exp_list ')'  */
#line 549 "part1_EL.y"
                                  {
    Symbol* f = lookupSymbol((yyvsp[-3].stringVal));
    if (!f || f->type != FUNC) {
        yyerror("Semantic Error: Function called before definition.");
        YYABORT;
    }

    // Count actual parameters
    int actualCount = 1;
    node* temp = (yyvsp[-1].nodePtr);
    while (temp && strcmp(temp->token, "exp_list") == 0) {
        actualCount++;
        temp = temp->right;
    }

    if (actualCount != f->paramCount) {
        char msg[128];
        sprintf(msg, "Semantic Error: Function '%s' expects %d arguments but got %d.", f->name, f->paramCount, actualCount);
        yyerror(msg);
        YYABORT;
    }

    // Rule 8: Type check each parameter
    temp = (yyvsp[-1].nodePtr);
    int index = 0;
    while (temp && index < f->paramCount) {
        node* exprNode = (strcmp(temp->token, "exp_list") == 0) ? temp->left : temp;
        char* actualType = inferExprType(exprNode);
        char* expectedType = f->paramTypes[index];

        if (strcmp(actualType, expectedType) != 0) {
            char msg[256];
            sprintf(msg, "Semantic Error: Argument %d in call to '%s' has type '%s' but expected '%s'.",
                    index + 1, f->name, actualType, expectedType);
            yyerror(msg);
            YYABORT;
        }

        temp = (strcmp(temp->token, "exp_list") == 0) ? temp->right : NULL;
        index++;
    }

    (yyval.nodePtr) = mknode("call", mknode((yyvsp[-3].stringVal),NULL,NULL), (yyvsp[-1].nodePtr));
}
#line 2137 "part1_EL.tab.c"
    break;

  case 78: /* exp_list: expression  */
#line 597 "part1_EL.y"
                                                   { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 2143 "part1_EL.tab.c"
    break;

  case 79: /* exp_list: expression ',' exp_list  */
#line 598 "part1_EL.y"
                                                  { (yyval.nodePtr) = mknode("exp_list",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2149 "part1_EL.tab.c"
    break;

  case 81: /* expression: INT_LIT  */
#line 604 "part1_EL.y"
              {
    (yyval.nodePtr) = mknode(strdup("INT"), NULL, NULL);
    }
#line 2157 "part1_EL.tab.c"
    break;

  case 82: /* expression: REAL_LIT  */
#line 607 "part1_EL.y"
               {
        (yyval.nodePtr) = mknode(strdup("REAL"), NULL, NULL);
    }
#line 2165 "part1_EL.tab.c"
    break;

  case 83: /* expression: CHAR_LIT  */
#line 610 "part1_EL.y"
               {
        (yyval.nodePtr) = mknode(strdup("CHAR"), NULL, NULL);
    }
#line 2173 "part1_EL.tab.c"
    break;

  case 84: /* expression: STRING_LIT  */
#line 613 "part1_EL.y"
                 {
        (yyval.nodePtr) = mknode(strdup("STRING"), NULL, NULL);
    }
#line 2181 "part1_EL.tab.c"
    break;

  case 85: /* expression: IDENT  */
#line 617 "part1_EL.y"
            {
        if (!isVarDeclaredInScope((yyvsp[0].stringVal))) {
            char msg[128];
            sprintf(msg, "Semantic Error: Variable '%s' used before declaration.", (yyvsp[0].stringVal));
            yyerror(msg);
            YYABORT;
        }
        (yyval.nodePtr) = mknode((yyvsp[0].stringVal),NULL,NULL);
    }
#line 2195 "part1_EL.tab.c"
    break;

  case 86: /* expression: expression PLUS expression  */
#line 628 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("+",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2201 "part1_EL.tab.c"
    break;

  case 87: /* expression: expression MINUS expression  */
#line 629 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("-",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2207 "part1_EL.tab.c"
    break;

  case 88: /* expression: expression MULTI expression  */
#line 630 "part1_EL.y"
                                     { (yyval.nodePtr) = mknode("*",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2213 "part1_EL.tab.c"
    break;

  case 89: /* expression: expression DIV expression  */
#line 631 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("/",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2219 "part1_EL.tab.c"
    break;

  case 90: /* expression: MINUS expression  */
#line 634 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("unary-",(yyvsp[0].nodePtr),NULL); }
#line 2225 "part1_EL.tab.c"
    break;

  case 91: /* expression: ADDRESS expression  */
#line 635 "part1_EL.y"
                                  { (yyval.nodePtr) = mknode("&",(yyvsp[0].nodePtr),NULL); }
#line 2231 "part1_EL.tab.c"
    break;

  case 92: /* expression: MULTI IDENT  */
#line 636 "part1_EL.y"
                                { (yyval.nodePtr) = mknode("deref",mknode((yyvsp[0].stringVal),NULL,NULL),NULL); }
#line 2237 "part1_EL.tab.c"
    break;

  case 93: /* expression: MULTI expression  */
#line 637 "part1_EL.y"
                                     { (yyval.nodePtr) = mknode("unary*", (yyvsp[0].nodePtr),NULL); }
#line 2243 "part1_EL.tab.c"
    break;

  case 94: /* expression: '(' expression ')'  */
#line 640 "part1_EL.y"
                                    { (yyval.nodePtr) = (yyvsp[-1].nodePtr); }
#line 2249 "part1_EL.tab.c"
    break;

  case 95: /* expression: expression EQL expression  */
#line 643 "part1_EL.y"
                                     { (yyval.nodePtr) = mknode("==",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2255 "part1_EL.tab.c"
    break;

  case 96: /* expression: expression NOTEQL expression  */
#line 644 "part1_EL.y"
                                        { (yyval.nodePtr) = mknode("!=",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2261 "part1_EL.tab.c"
    break;

  case 97: /* expression: expression GREATEREQL expression  */
#line 645 "part1_EL.y"
                                            { (yyval.nodePtr) = mknode(">=",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2267 "part1_EL.tab.c"
    break;

  case 98: /* expression: expression LESSEQL expression  */
#line 646 "part1_EL.y"
                                         { (yyval.nodePtr) = mknode("<=",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2273 "part1_EL.tab.c"
    break;

  case 99: /* expression: expression GREATER expression  */
#line 647 "part1_EL.y"
                                         { (yyval.nodePtr) = mknode(">", (yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2279 "part1_EL.tab.c"
    break;

  case 100: /* expression: expression LESS expression  */
#line 648 "part1_EL.y"
                                      { (yyval.nodePtr) = mknode("<", (yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2285 "part1_EL.tab.c"
    break;

  case 101: /* expression: IDENT '[' expression ']'  */
#line 652 "part1_EL.y"
                               {
    if (!isVarDeclaredInScope((yyvsp[-3].stringVal))) {
        char msg[128];
        sprintf(msg, "Semantic Error: Variable '%s' used before declaration.", (yyvsp[-3].stringVal));
        yyerror(msg);
        YYABORT;
    }

    // Rule 12: index must be of type int
    char* indexType = inferExprType((yyvsp[-1].nodePtr));
    if (strcmp(indexType, "int") != 0) {
        yyerror("Semantic Error: Index expression must be of type 'int'.");
        YYABORT;
    }

    // Rule 13: only string can be indexed
    Symbol* varSym = lookupSymbol((yyvsp[-3].stringVal));
    if (!varSym || varSym->type != VAR || strcasecmp(varSym->returnType, "string") != 0) {
        yyerror("Semantic Error: Only variables of type 'string' can be indexed using '[]'.");
        YYABORT;
    }

    (yyval.nodePtr) = mknode("index", mknode((yyvsp[-3].stringVal), NULL, NULL), (yyvsp[-1].nodePtr));
}
#line 2314 "part1_EL.tab.c"
    break;

  case 102: /* expression: expression AND expression  */
#line 678 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("and",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2320 "part1_EL.tab.c"
    break;

  case 103: /* expression: expression OR expression  */
#line 679 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("or",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2326 "part1_EL.tab.c"
    break;

  case 104: /* expression: func_call  */
#line 682 "part1_EL.y"
                                { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 2332 "part1_EL.tab.c"
    break;


#line 2336 "part1_EL.tab.c"

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

#line 684 "part1_EL.y"
  /* ===================  C‑code section ================================*/

#include "lex.yy.c"

/* ----------------------------  main  ------------------------------------*/
int main(void)
{
    yyparse();

    if (isMainExists()) return 1; 

    printTree(ASTRoot, 0);  

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


/* -------------------------  Sybol Table Funcntions -------------------------------*/

int insertSymbol(char* name, SymbolType type, char* returnType, int paramCount, const char* scope, char* paramTypes[]) {
    Symbol* current = symbolTable;
    while (current != NULL) {
        // Only disallow redefinition in the same scope depth
        if (strcmp(current->name, name) == 0 && current->scopeDepth == scopeDepth) {
            return 1;
        }
        current = current->next;
    }

    Symbol* newSym = (Symbol*)malloc(sizeof(Symbol));
    newSym->name = strdup(name);
    newSym->type = type;
    newSym->returnType = returnType ? strdup(returnType) : NULL;
    newSym->paramCount = paramCount;
     for (int i = 0; i < paramCount; i++) {
        newSym->paramTypes[i] = strdup(paramTypes[i]);
    }
    newSym->scope = strdup(scope);
    newSym->scopeDepth = scopeDepth;
    newSym->next = symbolTable;
    symbolTable = newSym;

    return 0;
}

Symbol* lookupSymbol(char* name) {
    Symbol* current = symbolTable;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void freeSymbolTable() {
    Symbol* current = symbolTable;
    while (current != NULL) {
        Symbol* temp = current;
        current = current->next;
        free(temp->name);
        if (temp->returnType) free(temp->returnType);
        free(temp);
    }
    symbolTable = NULL;
}

int getParamCount(node* paramList) {
    int count = 0;
    node* current = paramList;
    while (current) {
        count++;
        current = current->right;
    }
    return count;
}


/* -------------------------  Semantic funcntions -------------------------------*/

int moreThanOneMain(char* name) {
    if (strcmp(name, "_main_") == 0) {
        if (mainDeclared) {
            yyerror("Semantic Error: Multiple declarations of '_main_' function.");
            return 1;  // signal failure
        } else {
            mainDeclared = 1;
        }
    }
    return 0;  // success
}


int isMainExists() {
    if (!mainDeclared) {
        fprintf(stderr, "Semantic Error: Missing '_main_' function.\n");
        return 1;
    }
    return 0;
}

void pushScope() {
    scopeDepth++;
}

void popScope() {
    Symbol** current = &symbolTable;
    while (*current != NULL) {
        if ((*current)->scopeDepth == scopeDepth) {
            Symbol* toDelete = *current;
            *current = (*current)->next;
            free(toDelete->name);
            if (toDelete->returnType) free(toDelete->returnType);
            free(toDelete);
        } else {
            current = &((*current)->next);
        }
    }
    scopeDepth--;
}

int isVarDeclaredInScope(const char* name) {
    Symbol* current = symbolTable;
    while (current != NULL) {
        if (current->type == VAR && strcmp(current->name, name) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

char* inferExprType(node* expr) 
{
    if (!expr) {
        printf("inferExprType: ERROR - received NULL expr\n");
        return "unknown";
    }

    if (!expr->token) {
        printf("inferExprType: ERROR - expr has NULL token\n");
        return "unknown";
    }

    // Direct literal types based on AST node labels
    if (strcmp(expr->token, "INT") == 0) return "int";
    if (strcmp(expr->token, "REAL") == 0) return "real";
    if (strcmp(expr->token, "CHAR") == 0) return "char";
    if (strcmp(expr->token, "STRING") == 0) return "string";
    if (strcmp(expr->token, "BOOL") == 0) return "bool";
    if (strcmp(expr->token, "NULL") == 0) return "null";

    // Detect from token string format (e.g., 3.14 or 42)
    if (isdigit(expr->token[0])) {
        if (strchr(expr->token, '.')) return "real";
        return "int";
    }

    // Identifiers: lookup in symbol table
    Symbol* sym = lookupSymbol(expr->token);
    if (sym && sym->type == VAR && sym->returnType) 
    {
    char* norm = strdup(sym->returnType);
    for (char* p = norm; *p; ++p) *p = tolower(*p);
    return norm;
    }
    printf("inferExprType: WARNING - could not determine type of token '%s'\n", expr->token);
    return "unknown";
}

int validateReturnType(node* body, const char* expectedType) {
    if (!body) return 1;

    if (strcmp(body->token, "return") == 0) {
        char* actualType = inferExprType(body->left);
        if (strcmp(actualType, expectedType) != 0) {
            char msg[256];
            sprintf(msg, "Semantic Error: Return type is '%s' but expected '%s'.", actualType, expectedType);
            yyerror(msg);
            return 0;
        }
    }

    // Recurse through the AST
    if (!validateReturnType(body->left, expectedType)) return 0;
    if (!validateReturnType(body->right, expectedType)) return 0;

    return 1;
}
