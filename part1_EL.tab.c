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
    #include <ctype.h> 
    #define MAX_PARAMS 10

    
    int yylex();
    int yyerror(const char *s);
    extern int yylineno;  
    extern char* yytext; 
    /* === helpers for type checking (added) === */
    int  isInt   (const char* t);
    int  isReal  (const char* t);
    int  isBool  (const char* t);
    int  isChar  (const char* t);
    int  isStr   (const char* t);
    int  isNumeric(const char* t);
    int  samePtrType(const char* a,const char* b);
    int paramOrderIdx = 0;   
    int semanticErrSeen = 0;   /* =1 after the first semantic error */

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
    int isPointerType(const char* type);
    int registerParams(node* plist);

    int mainDeclared = 0;
    int scopeDepth = 0;
    static node *g_lastParamList = NULL;



#line 141 "part1_EL.tab.c"

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
  YYSYMBOL_LENGTH_ABS = 50,                /* LENGTH_ABS  */
  YYSYMBOL_51_ = 51,                       /* '('  */
  YYSYMBOL_52_ = 52,                       /* ')'  */
  YYSYMBOL_53_ = 53,                       /* ':'  */
  YYSYMBOL_54_ = 54,                       /* ';'  */
  YYSYMBOL_55_ = 55,                       /* '['  */
  YYSYMBOL_56_ = 56,                       /* ']'  */
  YYSYMBOL_57_ = 57,                       /* ','  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_code = 59,                      /* code  */
  YYSYMBOL_functions = 60,                 /* functions  */
  YYSYMBOL_scope_marker = 61,              /* scope_marker  */
  YYSYMBOL_function = 62,                  /* function  */
  YYSYMBOL_params_reset = 63,              /* params_reset  */
  YYSYMBOL_params = 64,                    /* params  */
  YYSYMBOL_param_list = 65,                /* param_list  */
  YYSYMBOL_param = 66,                     /* param  */
  YYSYMBOL_type = 67,                      /* type  */
  YYSYMBOL_ident_entry = 68,               /* ident_entry  */
  YYSYMBOL_idents_list = 69,               /* idents_list  */
  YYSYMBOL_literal = 70,                   /* literal  */
  YYSYMBOL_var = 71,                       /* var  */
  YYSYMBOL_dec_list = 72,                  /* dec_list  */
  YYSYMBOL_dec = 73,                       /* dec  */
  YYSYMBOL_statements = 74,                /* statements  */
  YYSYMBOL_state = 75,                     /* state  */
  YYSYMBOL_assign_state = 76,              /* assign_state  */
  YYSYMBOL_if_state = 77,                  /* if_state  */
  YYSYMBOL_while_state = 78,               /* while_state  */
  YYSYMBOL_do_while_state = 79,            /* do_while_state  */
  YYSYMBOL_for_state = 80,                 /* for_state  */
  YYSYMBOL_for_h = 81,                     /* for_h  */
  YYSYMBOL_advance_exp = 82,               /* advance_exp  */
  YYSYMBOL_rt_state = 83,                  /* rt_state  */
  YYSYMBOL_bl_state = 84,                  /* bl_state  */
  YYSYMBOL_85_1 = 85,                      /* $@1  */
  YYSYMBOL_86_2 = 86,                      /* $@2  */
  YYSYMBOL_func_call_state = 87,           /* func_call_state  */
  YYSYMBOL_func_call = 88,                 /* func_call  */
  YYSYMBOL_exp_list = 89,                  /* exp_list  */
  YYSYMBOL_expression = 90                 /* expression  */
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
#define YYLAST   597

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  215

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


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
      51,    52,     2,     2,    57,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,    54,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   121,   121,   129,   130,   135,   147,   220,   275,   279,
     280,   285,   286,   290,   306,   307,   308,   309,   310,   311,
     312,   313,   318,   322,   326,   331,   341,   343,   349,   350,
     351,   352,   353,   354,   356,   361,   362,   366,   367,   372,
     406,   407,   408,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   429,   457,   470,   486,   511,   520,   529,
     538,   549,   559,   570,   572,   578,   593,   609,   614,   614,
     615,   615,   622,   623,   630,   639,   687,   688,   692,   694,
     697,   700,   703,   707,   718,   719,   720,   721,   724,   725,
     740,   742,   760,   773,   774,   779,   780,   781,   782,   783,
     784,   788,   814,   815,   817,   818,   819,   824
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
  "MULTI", "DIV", "ADDRESS", "LENGTH", "TRUE", "FALSE", "LENGTH_ABS",
  "'('", "')'", "':'", "';'", "'['", "']'", "','", "$accept", "code",
  "functions", "scope_marker", "function", "params_reset", "params",
  "param_list", "param", "type", "ident_entry", "idents_list", "literal",
  "var", "dec_list", "dec", "statements", "state", "assign_state",
  "if_state", "while_state", "do_while_state", "for_state", "for_h",
  "advance_exp", "rt_state", "bl_state", "$@1", "$@2", "func_call_state",
  "func_call", "exp_list", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-88)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-41)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -24,    31,    81,   -88,   -24,    -4,   -88,   -88,     2,    62,
      17,    91,   -88,    44,    37,   -88,   -88,   -88,   -88,   -88,
     -88,   -88,   -88,    71,    62,    57,   103,   -88,   113,    91,
     -88,   -88,    91,   -88,   113,   104,   100,    76,   -88,   -88,
     139,   123,   105,   -88,   -88,   -88,   -88,   -23,   197,   197,
      80,    82,   197,   -88,   129,   197,   197,   206,   197,   228,
     -88,   -88,   197,   -88,   109,   110,   139,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,    84,   -15,     0,    83,    93,
     139,   148,   197,    94,   -88,   434,   454,   143,   112,    47,
     308,   139,   106,   -88,   -29,    94,   -88,   -88,   -12,   513,
     494,   -88,   -88,   -88,   -88,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   -88,    68,   155,
     123,   -88,   137,   117,   119,   329,   182,   197,    47,    47,
     133,    47,   156,   -88,   149,    45,   -88,   -88,   -88,   139,
     552,   541,   243,   243,    69,    69,    69,    69,   -29,   -29,
     -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
     121,   -88,   -88,   -88,   -88,   -88,   152,   293,   101,   -88,
     197,    54,   -88,   197,   -88,   -88,   128,   277,   160,   131,
     259,   -88,   197,   145,   350,   -88,   -88,   371,   -88,   197,
     -88,   199,   153,   392,   474,    47,   197,   -88,   -88,   -88,
     -88,   -88,    47,   -88,   413,   187,   201,   162,   188,   171,
      47,   197,   -88,   -88,   527
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     1,     3,     8,     0,
       0,     0,    10,    11,     0,    16,    15,    14,    18,    17,
      20,    19,    21,     0,     0,    35,     0,    12,     0,     0,
       5,    13,     0,    36,    37,    35,     0,     0,    38,     5,
      78,     0,     0,    79,    80,    81,    82,    83,    78,    78,
       0,     0,    78,    68,     0,    78,    78,    78,    78,    78,
     104,   105,    78,    43,     0,     0,    78,    44,    45,    46,
      48,    47,    50,    49,    51,   107,     0,    23,    26,     0,
      78,    78,    78,    83,   107,     0,     0,     0,     0,     0,
       0,    78,     0,    90,    88,    83,    92,    89,    83,     0,
       0,    70,     7,    42,    72,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    52,     0,     0,
       0,    39,     0,     0,   107,     0,     0,    78,     0,     0,
       0,     0,     0,    67,     0,    78,   106,    94,    93,    78,
     102,   103,    95,    96,    97,    98,    99,   100,    84,    85,
      86,    87,    28,    33,    31,    32,    34,    29,    30,    22,
       0,    27,     6,    56,    73,    53,   101,     0,    57,    61,
      78,     0,    63,    78,    69,    74,     0,    76,     0,    24,
      78,   101,    78,     0,     0,    68,    64,     0,    75,    78,
      71,     0,    81,     0,     0,     0,    78,    62,    77,    25,
      54,    55,     0,    58,     0,    59,     0,     0,     0,     0,
       0,    78,    65,    60,    66
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -88,   -88,   232,   203,    36,   -88,   -88,   223,   -88,    89,
     -88,   136,   -88,   -22,   217,   -88,   -54,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,   -87,   -88,   -88,   -88,
     -35,    78,   -48
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    36,    63,     9,    10,    12,    13,    23,
      78,    79,   159,    64,    33,    34,    65,    66,    67,    68,
      69,    70,    71,    88,   209,    72,    73,    91,   139,    74,
      84,   176,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      85,    86,   132,    30,    90,    75,     1,    93,    94,    96,
      97,    99,   103,    39,   100,   115,   116,   105,    81,   106,
     107,   108,   109,   110,   111,   112,   122,   113,   114,   115,
     116,    75,    82,   125,   126,   136,     4,   134,     5,   117,
       4,   168,   169,   127,   172,    75,   124,     8,    43,    44,
      45,    46,    83,   118,    -9,   119,    75,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    14,
      28,   152,   153,   154,   155,    53,    54,    28,    55,   167,
      28,     6,   185,    29,   186,   178,    11,   177,    56,    57,
      25,    58,    59,    60,    61,   156,    62,   175,    24,    15,
      16,    17,    18,    19,    75,    20,    21,    22,   203,   171,
      31,   113,   114,   115,   116,   205,   157,   158,    35,   182,
     183,    37,   184,   213,    26,   187,    32,    28,    40,    41,
      77,    87,   193,    80,   194,    89,    92,   101,   104,   102,
     120,   177,    43,    44,    45,    46,    47,   121,   204,   127,
     130,    43,    44,    45,    46,    83,    48,   135,   160,    49,
      50,    51,    28,   214,    52,   131,   162,    53,   -40,     1,
      54,   163,    55,   164,   170,   123,   173,   179,   174,    54,
     188,    55,    56,    57,   191,    58,    59,    60,    61,   190,
      62,    56,    57,   180,    58,    59,    60,    61,   195,    62,
      43,    44,    45,    46,    83,   199,   207,   200,   208,    43,
      44,    45,    46,    95,   105,   210,   106,   107,   108,   109,
     110,   111,   112,   212,   113,   114,   115,   116,    54,   211,
      55,    43,    44,    45,    46,    98,     7,    54,   166,    55,
      56,    57,    42,    58,    59,    60,    61,    27,    62,    56,
      57,    38,    58,    59,    60,    61,   161,    62,     0,    54,
       0,    55,    43,    44,   192,    46,    83,   198,     0,     0,
       0,    56,    57,     0,    58,    59,    60,    61,     0,    62,
     109,   110,   111,   112,     0,   113,   114,   115,   116,     0,
      54,     0,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    56,    57,     0,    58,    59,    60,    61,   105,
      62,   106,   107,   108,   109,   110,   111,   112,     0,   113,
     114,   115,   116,     0,     0,   105,     0,   106,   107,   108,
     109,   110,   111,   112,   189,   113,   114,   115,   116,     0,
     105,     0,   106,   107,   108,   109,   110,   111,   112,   181,
     113,   114,   115,   116,     0,     0,     0,     0,     0,     0,
       0,   105,   133,   106,   107,   108,   109,   110,   111,   112,
       0,   113,   114,   115,   116,     0,     0,     0,     0,     0,
       0,     0,   105,   165,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   115,   116,     0,     0,     0,     0,
       0,     0,     0,   105,   196,   106,   107,   108,   109,   110,
     111,   112,     0,   113,   114,   115,   116,     0,     0,     0,
       0,     0,     0,     0,   105,   197,   106,   107,   108,   109,
     110,   111,   112,     0,   113,   114,   115,   116,     0,     0,
       0,     0,     0,     0,     0,   105,   201,   106,   107,   108,
     109,   110,   111,   112,     0,   113,   114,   115,   116,     0,
       0,     0,     0,     0,     0,     0,   105,   206,   106,   107,
     108,   109,   110,   111,   112,     0,   113,   114,   115,   116,
       0,     0,     0,     0,     0,     0,   105,   128,   106,   107,
     108,   109,   110,   111,   112,     0,   113,   114,   115,   116,
       0,     0,     0,     0,     0,     0,   105,   129,   106,   107,
     108,   109,   110,   111,   112,     0,   113,   114,   115,   116,
       0,     0,     0,     0,     0,     0,   105,   202,   106,   107,
     108,   109,   110,   111,   112,     0,   113,   114,   115,   116,
       0,     0,     0,     0,     0,   105,   138,   106,   107,   108,
     109,   110,   111,   112,     0,   113,   114,   115,   116,   105,
     137,   106,   107,   108,   109,   110,   111,   112,     0,   113,
     114,   115,   116,   105,     0,     0,   107,   108,   109,   110,
     111,   112,     0,   113,   114,   115,   116,   107,   108,   109,
     110,   111,   112,     0,   113,   114,   115,   116
};

static const yytype_int16 yycheck[] =
{
      48,    49,    89,    25,    52,    40,    30,    55,    56,    57,
      58,    59,    66,    35,    62,    44,    45,    32,    41,    34,
      35,    36,    37,    38,    39,    40,    80,    42,    43,    44,
      45,    66,    55,    81,    82,    47,     0,    91,     7,    54,
       4,   128,   129,    55,   131,    80,    81,    51,     3,     4,
       5,     6,     7,    53,    52,    55,    91,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,    52,
      23,     3,     4,     5,     6,    28,    31,    23,    33,   127,
      23,     0,    28,    26,   171,   139,    24,   135,    43,    44,
      53,    46,    47,    48,    49,    27,    51,    52,    54,     8,
       9,    10,    11,    12,   139,    14,    15,    16,   195,   131,
       7,    42,    43,    44,    45,   202,    48,    49,    29,    18,
      19,    32,   170,   210,    53,   173,    13,    23,    28,    53,
       7,    51,   180,    28,   182,    53,     7,    28,    54,    29,
      57,   189,     3,     4,     5,     6,     7,    54,   196,    55,
       7,     3,     4,     5,     6,     7,    17,    51,     3,    20,
      21,    22,    23,   211,    25,    53,    29,    28,    29,    30,
      31,    54,    33,    54,    41,    27,    20,    56,    29,    31,
      52,    33,    43,    44,    53,    46,    47,    48,    49,    29,
      51,    43,    44,    41,    46,    47,    48,    49,    53,    51,
       3,     4,     5,     6,     7,     6,    19,    54,     7,     3,
       4,     5,     6,     7,    32,    53,    34,    35,    36,    37,
      38,    39,    40,    52,    42,    43,    44,    45,    31,    41,
      33,     3,     4,     5,     6,     7,     4,    31,    56,    33,
      43,    44,    39,    46,    47,    48,    49,    24,    51,    43,
      44,    34,    46,    47,    48,    49,   120,    51,    -1,    31,
      -1,    33,     3,     4,     5,     6,     7,   189,    -1,    -1,
      -1,    43,    44,    -1,    46,    47,    48,    49,    -1,    51,
      37,    38,    39,    40,    -1,    42,    43,    44,    45,    -1,
      31,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    46,    47,    48,    49,    32,
      51,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      43,    44,    45,    -1,    -1,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    57,    42,    43,    44,    45,    -1,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    56,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    54,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    54,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    54,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    43,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    54,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    54,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    54,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    53,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    53,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    53,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    32,    52,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    44,    45,    32,
      47,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      43,    44,    45,    32,    -1,    -1,    35,    36,    37,    38,
      39,    40,    -1,    42,    43,    44,    45,    35,    36,    37,
      38,    39,    40,    -1,    42,    43,    44,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,    59,    60,    62,     7,     0,    60,    51,    63,
      64,    24,    65,    66,    52,     8,     9,    10,    11,    12,
      14,    15,    16,    67,    54,    53,    53,    65,    23,    26,
      71,     7,    13,    72,    73,    67,    61,    67,    72,    71,
      28,    53,    61,     3,     4,     5,     6,     7,    17,    20,
      21,    22,    25,    28,    31,    33,    43,    44,    46,    47,
      48,    49,    51,    62,    71,    74,    75,    76,    77,    78,
      79,    80,    83,    84,    87,    88,    90,     7,    68,    69,
      28,    41,    55,     7,    88,    90,    90,    51,    81,    53,
      90,    85,     7,    90,    90,     7,    90,    90,     7,    90,
      90,    28,    29,    74,    54,    32,    34,    35,    36,    37,
      38,    39,    40,    42,    43,    44,    45,    54,    53,    55,
      57,    54,    74,    27,    88,    90,    90,    55,    53,    53,
       7,    53,    84,    54,    74,    51,    47,    47,    52,    86,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,     3,     4,     5,     6,    27,    48,    49,    70,
       3,    69,    29,    54,    54,    54,    56,    90,    84,    84,
      41,    71,    84,    20,    29,    52,    89,    90,    74,    56,
      41,    56,    18,    19,    90,    28,    84,    90,    52,    57,
      29,    53,     5,    90,    90,    53,    54,    54,    89,     6,
      54,    54,    53,    84,    90,    84,    54,    19,     7,    82,
      53,    41,    52,    84,    90
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    60,    60,    61,    62,    62,    63,    64,
      64,    65,    65,    66,    67,    67,    67,    67,    67,    67,
      67,    67,    68,    68,    68,    68,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    71,    71,    72,    72,    73,
      74,    74,    74,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    76,    76,    76,    76,    77,    77,    77,
      77,    78,    79,    80,    80,    81,    82,    83,    85,    84,
      86,    84,    87,    87,    88,    88,    89,    89,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     0,    13,    11,     0,     0,
       2,     1,     3,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     4,     6,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     0,     2,     1,     2,     5,
       0,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     7,     7,     4,     4,     7,     8,
      11,     4,     6,     4,     5,     9,     3,     3,     0,     4,
       0,     5,     2,     4,     4,     5,     1,     3,     0,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     2,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     3,     3,     1,     1,     3,     1
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
#line 121 "part1_EL.y"
              {
        ASTRoot = mknode("CODE", (yyvsp[0].nodePtr), NULL);
    }
#line 1440 "part1_EL.tab.c"
    break;

  case 3: /* functions: function functions  */
#line 129 "part1_EL.y"
                                           { (yyval.nodePtr) = mknode("FUNCS",(yyvsp[-1].nodePtr),(yyvsp[0].nodePtr)); }
#line 1446 "part1_EL.tab.c"
    break;

  case 4: /* functions: function  */
#line 130 "part1_EL.y"
                                             { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1452 "part1_EL.tab.c"
    break;

  case 5: /* scope_marker: %empty  */
#line 135 "part1_EL.y"
      {                                          /* begin action */
          pushScope();

          /* ---------- register the parameters ---------- */
          if (g_lastParamList && registerParams(g_lastParamList)) {
              yyerror("Semantic Error: Duplicate parameter name.");
              YYABORT;
          }
      }
#line 1466 "part1_EL.tab.c"
    break;

  case 6: /* function: DEF IDENT '(' params ')' ':' RETURNS type var scope_marker T_BEGIN statements END  */
#line 149 "part1_EL.y"
    {
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
        popScope();

    }
#line 1541 "part1_EL.tab.c"
    break;

  case 7: /* function: DEF IDENT '(' params ')' ':' var scope_marker T_BEGIN statements END  */
#line 221 "part1_EL.y"
    {
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
        popScope();

    }
#line 1594 "part1_EL.tab.c"
    break;

  case 8: /* params_reset: %empty  */
#line 275 "part1_EL.y"
                            { paramOrderIdx = 0; }
#line 1600 "part1_EL.tab.c"
    break;

  case 9: /* params: %empty  */
#line 279 "part1_EL.y"
                                        { (yyval.nodePtr) = NULL;            g_lastParamList = NULL; }
#line 1606 "part1_EL.tab.c"
    break;

  case 10: /* params: params_reset param_list  */
#line 280 "part1_EL.y"
                                        { (yyval.nodePtr) = (yyvsp[0].nodePtr);              g_lastParamList = (yyvsp[0].nodePtr);   }
#line 1612 "part1_EL.tab.c"
    break;

  case 11: /* param_list: param  */
#line 285 "part1_EL.y"
                                    { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1618 "part1_EL.tab.c"
    break;

  case 12: /* param_list: param ';' param_list  */
#line 286 "part1_EL.y"
                                  { (yyval.nodePtr) = mknode("PARAMS",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1624 "part1_EL.tab.c"
    break;

  case 13: /* param: PAR type ':' IDENT  */
#line 291 "part1_EL.y"
        {
            /* ---- בדיקת סדר par ---- */
            if ((yyvsp[-3].intVal) != paramOrderIdx + 1) {
                yyerror("Semantic Error: parameters must be in sequential order (par1, par2, …).");
                YYABORT;
            }
            paramOrderIdx = (yyvsp[-3].intVal);

            (yyval.nodePtr) = mknode("PARAM", (yyvsp[-2].nodePtr), mknode((yyvsp[0].stringVal), NULL, NULL));
        }
#line 1639 "part1_EL.tab.c"
    break;

  case 14: /* type: INT  */
#line 306 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("INT",NULL,NULL);  }
#line 1645 "part1_EL.tab.c"
    break;

  case 15: /* type: CHAR  */
#line 307 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("CHAR",NULL,NULL); }
#line 1651 "part1_EL.tab.c"
    break;

  case 16: /* type: BOOL  */
#line 308 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("BOOL",NULL,NULL); }
#line 1657 "part1_EL.tab.c"
    break;

  case 17: /* type: STRING  */
#line 309 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("STRING",NULL,NULL);}
#line 1663 "part1_EL.tab.c"
    break;

  case 18: /* type: REAL  */
#line 310 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("REAL",NULL,NULL); }
#line 1669 "part1_EL.tab.c"
    break;

  case 19: /* type: CHARPTR  */
#line 311 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("CHARPTR",NULL,NULL);}
#line 1675 "part1_EL.tab.c"
    break;

  case 20: /* type: INTPTR  */
#line 312 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("INTPTR",NULL,NULL);}
#line 1681 "part1_EL.tab.c"
    break;

  case 21: /* type: REALPTR  */
#line 313 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("REALPTR",NULL,NULL);}
#line 1687 "part1_EL.tab.c"
    break;

  case 22: /* ident_entry: IDENT ':' literal  */
#line 319 "part1_EL.y"
        { (yyval.nodePtr) = mknode("VAR_ASSIGN",
                      mknode("IDENT", mknode((yyvsp[-2].stringVal),NULL,NULL), NULL),
                      (yyvsp[0].nodePtr)); }
#line 1695 "part1_EL.tab.c"
    break;

  case 23: /* ident_entry: IDENT  */
#line 323 "part1_EL.y"
        { (yyval.nodePtr) = mknode("VAR_DECL",
                      mknode("IDENT", mknode((yyvsp[0].stringVal),NULL,NULL), NULL),
                      NULL); }
#line 1703 "part1_EL.tab.c"
    break;

  case 24: /* ident_entry: IDENT '[' INT_LIT ']'  */
#line 327 "part1_EL.y"
        { char buf[32]; sprintf(buf, "%d", (yyvsp[-1].intVal));
          (yyval.nodePtr) = mknode("ARRAY_DECL",
                      mknode("IDENT", mknode((yyvsp[-3].stringVal),NULL,NULL), NULL),
                      mknode(buf, NULL, NULL)); }
#line 1712 "part1_EL.tab.c"
    break;

  case 25: /* ident_entry: IDENT '[' INT_LIT ']' ':' STRING_LIT  */
#line 332 "part1_EL.y"
        { char buf[32]; sprintf(buf, "%d", (yyvsp[-3].intVal));
          (yyval.nodePtr) = mknode("ARRAY_INIT",
                      mknode("ARRAY_DECL",
                             mknode("IDENT", mknode((yyvsp[-5].stringVal),NULL,NULL), NULL),
                             mknode(buf, NULL, NULL)),
                      mknode((yyvsp[0].stringVal), NULL, NULL)); }
#line 1723 "part1_EL.tab.c"
    break;

  case 26: /* idents_list: ident_entry  */
#line 342 "part1_EL.y"
        { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1729 "part1_EL.tab.c"
    break;

  case 27: /* idents_list: ident_entry ',' idents_list  */
#line 344 "part1_EL.y"
        { (yyval.nodePtr) = mknode("ID_LIST", (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr)); }
#line 1735 "part1_EL.tab.c"
    break;

  case 28: /* literal: INT_LIT  */
#line 349 "part1_EL.y"
                       { char ibuf[32]; sprintf(ibuf,"%d",(yyvsp[0].intVal)); (yyval.nodePtr) = mknode("INT", mknode(ibuf,NULL,NULL), NULL); }
#line 1741 "part1_EL.tab.c"
    break;

  case 29: /* literal: TRUE  */
#line 350 "part1_EL.y"
                       { (yyval.nodePtr) = mknode("BOOL", mknode("true", NULL, NULL), NULL); }
#line 1747 "part1_EL.tab.c"
    break;

  case 30: /* literal: FALSE  */
#line 351 "part1_EL.y"
                       { (yyval.nodePtr) = mknode("BOOL", mknode("false", NULL, NULL), NULL); }
#line 1753 "part1_EL.tab.c"
    break;

  case 31: /* literal: CHAR_LIT  */
#line 352 "part1_EL.y"
                       { char cbuf[2] = {(yyvsp[0].charVal),'\0'}; (yyval.nodePtr) = mknode("CHAR", mknode(cbuf,NULL,NULL), NULL); }
#line 1759 "part1_EL.tab.c"
    break;

  case 32: /* literal: STRING_LIT  */
#line 353 "part1_EL.y"
                       { (yyval.nodePtr) = mknode("STRING", mknode((yyvsp[0].stringVal), NULL, NULL), NULL); }
#line 1765 "part1_EL.tab.c"
    break;

  case 33: /* literal: REAL_LIT  */
#line 354 "part1_EL.y"
                       { char r[64]; sprintf(r,"%f",(yyvsp[0].realVal));
                        (yyval.nodePtr) = mknode("REAL", mknode(r,NULL,NULL), NULL); }
#line 1772 "part1_EL.tab.c"
    break;

  case 34: /* literal: NULLL  */
#line 356 "part1_EL.y"
                       { (yyval.nodePtr) = mknode("NULL", NULL, NULL); }
#line 1778 "part1_EL.tab.c"
    break;

  case 35: /* var: %empty  */
#line 361 "part1_EL.y"
    { (yyval.nodePtr) = NULL; }
#line 1784 "part1_EL.tab.c"
    break;

  case 36: /* var: VARIABLE dec_list  */
#line 362 "part1_EL.y"
                                       { (yyval.nodePtr) = mknode("VAR",(yyvsp[0].nodePtr),NULL); }
#line 1790 "part1_EL.tab.c"
    break;

  case 37: /* dec_list: dec  */
#line 366 "part1_EL.y"
                               { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1796 "part1_EL.tab.c"
    break;

  case 38: /* dec_list: dec dec_list  */
#line 367 "part1_EL.y"
                          { (yyval.nodePtr) = mknode("DECS",(yyvsp[-1].nodePtr),(yyvsp[0].nodePtr)); }
#line 1802 "part1_EL.tab.c"
    break;

  case 39: /* dec: TYPE type ':' idents_list ';'  */
#line 373 "part1_EL.y"
       {  /* ----- identical semantic loop, but walk ID_LIST chain ----- */
           node* decl = (yyvsp[-1].nodePtr);
           while (decl) {
               node* single = (strcmp(decl->token,"ID_LIST")==0)
                              ? decl->left : decl;

               if (single && (strcmp(single->token,"VAR_DECL"  )==0 ||
                              strcmp(single->token,"VAR_ASSIGN")==0 ||
                              strcmp(single->token,"ARRAY_DECL")==0 ||
                              strcmp(single->token,"ARRAY_INIT")==0))
               {
                node* idNode = NULL;

                if (strcmp(single->token,"ARRAY_INIT")==0)
                        idNode = single->left->left;   /* IDENT is two hops down  */
                else idNode = single->left;         /* IDENT is one hop down   */

                   if (idNode && strcmp(idNode->token,"IDENT")==0 && idNode->left) {
                       char* vname = idNode->left->token;
                       if (insertSymbol(vname, VAR, (yyvsp[-3].nodePtr)->token, 0, "block", NULL)) {
                           yyerror("Semantic Error: Variable already declared in this scope.");
                           YYABORT;
                       }
                   }
               }
               decl = (strcmp(decl->token,"ID_LIST")==0) ? decl->right : NULL;
           }
           (yyval.nodePtr) = mknode("DECL", (yyvsp[-3].nodePtr), (yyvsp[-1].nodePtr));
       }
#line 1836 "part1_EL.tab.c"
    break;

  case 40: /* statements: %empty  */
#line 406 "part1_EL.y"
     {(yyval.nodePtr) = mknode("", NULL,NULL);}
#line 1842 "part1_EL.tab.c"
    break;

  case 41: /* statements: state  */
#line 407 "part1_EL.y"
                    {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1848 "part1_EL.tab.c"
    break;

  case 42: /* statements: state statements  */
#line 408 "part1_EL.y"
                               {(yyval.nodePtr) = mknode("statements", (yyvsp[-1].nodePtr), (yyvsp[0].nodePtr));}
#line 1854 "part1_EL.tab.c"
    break;

  case 43: /* state: function  */
#line 414 "part1_EL.y"
                     {(yyval.nodePtr)=(yyvsp[0].nodePtr);}
#line 1860 "part1_EL.tab.c"
    break;

  case 44: /* state: assign_state  */
#line 415 "part1_EL.y"
                           {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1866 "part1_EL.tab.c"
    break;

  case 45: /* state: if_state  */
#line 416 "part1_EL.y"
                       {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1872 "part1_EL.tab.c"
    break;

  case 46: /* state: while_state  */
#line 417 "part1_EL.y"
                          {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1878 "part1_EL.tab.c"
    break;

  case 47: /* state: for_state  */
#line 418 "part1_EL.y"
                        {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1884 "part1_EL.tab.c"
    break;

  case 48: /* state: do_while_state  */
#line 419 "part1_EL.y"
                             {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1890 "part1_EL.tab.c"
    break;

  case 49: /* state: bl_state  */
#line 420 "part1_EL.y"
                       {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1896 "part1_EL.tab.c"
    break;

  case 50: /* state: rt_state  */
#line 421 "part1_EL.y"
                       {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1902 "part1_EL.tab.c"
    break;

  case 51: /* state: func_call_state  */
#line 422 "part1_EL.y"
                              {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1908 "part1_EL.tab.c"
    break;

  case 52: /* state: expression ';'  */
#line 423 "part1_EL.y"
                             { (yyval.nodePtr) = (yyvsp[-1].nodePtr); }
#line 1914 "part1_EL.tab.c"
    break;

  case 53: /* assign_state: IDENT ASSIGN expression ';'  */
#line 430 "part1_EL.y"
    {
        Symbol* lvar = lookupSymbol((yyvsp[-3].stringVal));          /* LHS variable */
        if (!lvar) {
            char msg[128];
            sprintf(msg,
                    "Semantic Error: Variable '%s' used before declaration.", (yyvsp[-3].stringVal));
            yyerror(msg);
            YYABORT;
        }

        char* lhsType = strdup(lvar->returnType); // normalize lhs type too
        for (char* p = lhsType; *p; ++p) *p = tolower(*p);
        char* rhsTypeA = inferExprType((yyvsp[-1].nodePtr));

        if (strcmp(lhsType, rhsTypeA) != 0) {
            char msg[256];
            sprintf(msg,
                    "Semantic Error: Cannot assign type '%s' to variable '%s' of type '%s'.",
                    rhsTypeA, (yyvsp[-3].stringVal), lhsType);
            yyerror(msg);
            YYABORT;
        }

        (yyval.nodePtr) = mknode("assign", mknode((yyvsp[-3].stringVal), NULL, NULL), (yyvsp[-1].nodePtr));
    }
#line 1944 "part1_EL.tab.c"
    break;

  case 54: /* assign_state: IDENT '[' expression ']' ASSIGN CHAR_LIT ';'  */
#line 458 "part1_EL.y"
    {
        Symbol* var = lookupSymbol((yyvsp[-6].stringVal));
        if (!var || strcasecmp(var->returnType, "string") != 0) {
            yyerror("Semantic Error: Only string variables support indexing with [].");
            YYABORT;
        }
        char buf[2] = { (yyvsp[-1].charVal) , '\0'};
        (yyval.nodePtr) = mknode("array_assign",
                    mknode((yyvsp[-6].stringVal), (yyvsp[-4].nodePtr), NULL),
                    mknode("CHAR", mknode(buf,NULL,NULL), NULL));
    }
#line 1960 "part1_EL.tab.c"
    break;

  case 55: /* assign_state: IDENT '[' expression ']' ASSIGN expression ';'  */
#line 471 "part1_EL.y"
    {
        Symbol* var = lookupSymbol((yyvsp[-6].stringVal));
        if (!var || strcasecmp(var->returnType, "string") != 0) {
            yyerror("Semantic Error: Only string variables support indexing with [].");
            YYABORT;
        }
        char* rhsTypeB = inferExprType((yyvsp[-1].nodePtr));
        if (strcmp(rhsTypeB, "char") != 0) {
            yyerror("Semantic Error: String cells can only hold characters.");
            YYABORT;
        }
        (yyval.nodePtr) = mknode("array_assign", mknode((yyvsp[-6].stringVal), (yyvsp[-4].nodePtr), NULL), (yyvsp[-1].nodePtr));
    }
#line 1978 "part1_EL.tab.c"
    break;

  case 56: /* assign_state: IDENT ASSIGN NULLL ';'  */
#line 487 "part1_EL.y"
    {
        Symbol* var = lookupSymbol((yyvsp[-3].stringVal));
        if (!var) {
    yyerror("Semantic Error: Variable used before declaration.");
    YYABORT;
    }

    char* lhsType = strdup(var->returnType);
    for (char* p = lhsType; *p; ++p) *p = tolower(*p);

    if (!isPointerType(lhsType)) 
    {
        yyerror("Semantic Error: Only pointer variables can be assigned null.");
        YYABORT;
    }
        (yyval.nodePtr) = mknode("null_assign",
                    mknode((yyvsp[-3].stringVal), NULL, NULL),
                    mknode("NULL", NULL, NULL));
    }
#line 2002 "part1_EL.tab.c"
    break;

  case 57: /* if_state: IF expression ':' bl_state  */
#line 512 "part1_EL.y"
    {
        if (strcmp(inferExprType((yyvsp[-2].nodePtr)), "bool") != 0) {
            yyerror("Semantic Error: IF condition must be of type 'bool'.");
            YYABORT;
        }
        (yyval.nodePtr) = mknode("if", (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr));
    }
#line 2014 "part1_EL.tab.c"
    break;

  case 58: /* if_state: IF expression ':' bl_state ELSE ':' bl_state  */
#line 521 "part1_EL.y"
    {
        if (strcmp(inferExprType((yyvsp[-5].nodePtr)), "bool") != 0) {
            yyerror("Semantic Error: IF condition must be of type 'bool'.");
            YYABORT;
        }
        (yyval.nodePtr) = mknode("if_else", (yyvsp[-5].nodePtr), mknode("then", (yyvsp[-3].nodePtr), mknode("else", (yyvsp[0].nodePtr), NULL)));
    }
#line 2026 "part1_EL.tab.c"
    break;

  case 59: /* if_state: IF expression ':' bl_state ELIF expression ':' bl_state  */
#line 530 "part1_EL.y"
    {
        if (strcmp(inferExprType((yyvsp[-6].nodePtr)), "bool") != 0 || strcmp(inferExprType((yyvsp[-2].nodePtr)), "bool") != 0) {
            yyerror("Semantic Error: IF and ELIF conditions must be of type 'bool'.");
            YYABORT;
        }
        (yyval.nodePtr) = mknode("if_elif", (yyvsp[-6].nodePtr), mknode("then", (yyvsp[-4].nodePtr), mknode("elif", (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr))));
    }
#line 2038 "part1_EL.tab.c"
    break;

  case 60: /* if_state: IF expression ':' bl_state ELIF expression ':' bl_state ELSE ':' bl_state  */
#line 539 "part1_EL.y"
    {
        if (strcmp(inferExprType((yyvsp[-9].nodePtr)), "bool") != 0 || strcmp(inferExprType((yyvsp[-5].nodePtr)), "bool") != 0) {
            yyerror("Semantic Error: IF and ELIF conditions must be of type 'bool'.");
            YYABORT;
        }
        (yyval.nodePtr) = mknode("if_elif-else", (yyvsp[-9].nodePtr), mknode("then", (yyvsp[-7].nodePtr), mknode("elif", (yyvsp[-5].nodePtr), mknode("elif-then", (yyvsp[-3].nodePtr), mknode("else", (yyvsp[0].nodePtr), NULL)))));
    }
#line 2050 "part1_EL.tab.c"
    break;

  case 61: /* while_state: WHILE expression ':' bl_state  */
#line 550 "part1_EL.y"
    {
        if (strcmp(inferExprType((yyvsp[-2].nodePtr)), "bool") != 0) {
            yyerror("Semantic Error: WHILE condition must be of type 'bool'.");
            YYABORT;
        }
        (yyval.nodePtr) = mknode("while", (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr));
    }
#line 2062 "part1_EL.tab.c"
    break;

  case 62: /* do_while_state: DO ':' bl_state WHILE expression ';'  */
#line 560 "part1_EL.y"
    {
        if (strcmp(inferExprType((yyvsp[-1].nodePtr)), "bool") != 0) {
            yyerror("Semantic Error: DO-WHILE condition must be of type 'bool'.");
            YYABORT;
        }
        (yyval.nodePtr) = mknode("do_while", (yyvsp[-3].nodePtr), mknode("condition", (yyvsp[-1].nodePtr), NULL));
    }
#line 2074 "part1_EL.tab.c"
    break;

  case 63: /* for_state: FOR for_h ':' bl_state  */
#line 570 "part1_EL.y"
                                       {
          (yyval.nodePtr) = mknode("for",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2081 "part1_EL.tab.c"
    break;

  case 64: /* for_state: FOR for_h ':' var bl_state  */
#line 572 "part1_EL.y"
                                        {
          (yyval.nodePtr) = mknode("for",(yyvsp[-3].nodePtr),
                      mknode("block",(yyvsp[0].nodePtr),(yyvsp[-1].nodePtr))); }
#line 2089 "part1_EL.tab.c"
    break;

  case 65: /* for_h: '(' IDENT ASSIGN expression ';' expression ';' advance_exp ')'  */
#line 581 "part1_EL.y"
    {
        if (strcmp(inferExprType((yyvsp[-3].nodePtr)), "bool") != 0) {
            yyerror("Semantic Error: FOR condition must be of type 'bool'.");
            YYABORT;
        }
        (yyval.nodePtr) = mknode("for_header",
                    mknode("init", mknode((yyvsp[-7].stringVal), NULL, NULL), (yyvsp[-5].nodePtr)),
                    mknode("loop", (yyvsp[-3].nodePtr), (yyvsp[-1].nodePtr)));
    }
#line 2103 "part1_EL.tab.c"
    break;

  case 66: /* advance_exp: IDENT ASSIGN expression  */
#line 593 "part1_EL.y"
                                             {
          (yyval.nodePtr) = mknode("update",
                      mknode((yyvsp[-2].stringVal),NULL,NULL),(yyvsp[0].nodePtr)); }
#line 2111 "part1_EL.tab.c"
    break;

  case 67: /* rt_state: RETURN expression ';'  */
#line 609 "part1_EL.y"
                                                 { (yyval.nodePtr) = mknode("return",(yyvsp[-1].nodePtr),NULL); }
#line 2117 "part1_EL.tab.c"
    break;

  case 68: /* $@1: %empty  */
#line 614 "part1_EL.y"
            { pushScope(); }
#line 2123 "part1_EL.tab.c"
    break;

  case 69: /* bl_state: T_BEGIN $@1 statements END  */
#line 614 "part1_EL.y"
                                            { popScope(); (yyval.nodePtr) = mknode("block", (yyvsp[-1].nodePtr), NULL); }
#line 2129 "part1_EL.tab.c"
    break;

  case 70: /* $@2: %empty  */
#line 615 "part1_EL.y"
                { pushScope(); }
#line 2135 "part1_EL.tab.c"
    break;

  case 71: /* bl_state: var T_BEGIN $@2 statements END  */
#line 615 "part1_EL.y"
                                                { popScope(); (yyval.nodePtr) = mknode("block", (yyvsp[-1].nodePtr), (yyvsp[-4].nodePtr)); }
#line 2141 "part1_EL.tab.c"
    break;

  case 72: /* func_call_state: func_call ';'  */
#line 622 "part1_EL.y"
                                              { (yyval.nodePtr) = (yyvsp[-1].nodePtr); }
#line 2147 "part1_EL.tab.c"
    break;

  case 73: /* func_call_state: IDENT ASSIGN func_call ';'  */
#line 623 "part1_EL.y"
                                          {
          (yyval.nodePtr) = mknode("assign",
                      mknode((yyvsp[-3].stringVal),NULL,NULL),(yyvsp[-1].nodePtr)); }
#line 2155 "part1_EL.tab.c"
    break;

  case 74: /* func_call: CALL IDENT '(' ')'  */
#line 630 "part1_EL.y"
                         {
          Symbol* f = lookupSymbol((yyvsp[-2].stringVal));
          if (!f || f->type != FUNC) {
              yyerror("Semantic Error: Function called before definition.");
              YYABORT;
          }
          (yyval.nodePtr) = mknode("call", mknode((yyvsp[-2].stringVal),NULL,NULL), NULL);
      }
#line 2168 "part1_EL.tab.c"
    break;

  case 75: /* func_call: CALL IDENT '(' exp_list ')'  */
#line 639 "part1_EL.y"
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
#line 2217 "part1_EL.tab.c"
    break;

  case 76: /* exp_list: expression  */
#line 687 "part1_EL.y"
                                                   { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 2223 "part1_EL.tab.c"
    break;

  case 77: /* exp_list: expression ',' exp_list  */
#line 688 "part1_EL.y"
                                                  { (yyval.nodePtr) = mknode("exp_list",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2229 "part1_EL.tab.c"
    break;

  case 79: /* expression: INT_LIT  */
#line 694 "part1_EL.y"
              {
    (yyval.nodePtr) = mknode(strdup("INT"), NULL, NULL);
    }
#line 2237 "part1_EL.tab.c"
    break;

  case 80: /* expression: REAL_LIT  */
#line 697 "part1_EL.y"
               {
        (yyval.nodePtr) = mknode(strdup("REAL"), NULL, NULL);
    }
#line 2245 "part1_EL.tab.c"
    break;

  case 81: /* expression: CHAR_LIT  */
#line 700 "part1_EL.y"
               {
        (yyval.nodePtr) = mknode(strdup("CHAR"), NULL, NULL);
    }
#line 2253 "part1_EL.tab.c"
    break;

  case 82: /* expression: STRING_LIT  */
#line 703 "part1_EL.y"
                 {
        (yyval.nodePtr) = mknode(strdup("STRING"), NULL, NULL);
    }
#line 2261 "part1_EL.tab.c"
    break;

  case 83: /* expression: IDENT  */
#line 707 "part1_EL.y"
            {
        if (!isVarDeclaredInScope((yyvsp[0].stringVal))) {
            char msg[128];
            sprintf(msg, "Semantic Error: Variable '%s' used before declaration.", (yyvsp[0].stringVal));
            yyerror(msg);
            YYABORT;
        }
        (yyval.nodePtr) = mknode((yyvsp[0].stringVal),NULL,NULL);
    }
#line 2275 "part1_EL.tab.c"
    break;

  case 84: /* expression: expression PLUS expression  */
#line 718 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("+",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2281 "part1_EL.tab.c"
    break;

  case 85: /* expression: expression MINUS expression  */
#line 719 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("-",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2287 "part1_EL.tab.c"
    break;

  case 86: /* expression: expression MULTI expression  */
#line 720 "part1_EL.y"
                                     { (yyval.nodePtr) = mknode("*",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2293 "part1_EL.tab.c"
    break;

  case 87: /* expression: expression DIV expression  */
#line 721 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("/",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2299 "part1_EL.tab.c"
    break;

  case 88: /* expression: MINUS expression  */
#line 724 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("unary-",(yyvsp[0].nodePtr),NULL); }
#line 2305 "part1_EL.tab.c"
    break;

  case 89: /* expression: ADDRESS expression  */
#line 726 "part1_EL.y"
    {
        /* בדיקת חוק ה-& בזמן הבנייה */
        char* baseType = inferExprType((yyvsp[0].nodePtr));

        if (isInt(baseType))      { /* מותר – int -> intptr   */ }
        else if (isReal(baseType)){ /* מותר – real -> realptr */ }
        else if (isChar(baseType)){ /* מותר – char -> charptr */ }
        else {
            yyerror("Semantic Error: '&' operator allowed only on int, real, char or string[i].");
            YYABORT;
        }

        /* אם הגענו לכאן – מותר, בנה את הצומת רגיל */
        (yyval.nodePtr) = mknode("&", (yyvsp[0].nodePtr), NULL);
    }
#line 2325 "part1_EL.tab.c"
    break;

  case 90: /* expression: NOT expression  */
#line 740 "part1_EL.y"
                                       { (yyval.nodePtr) = mknode("not", (yyvsp[0].nodePtr), NULL); }
#line 2331 "part1_EL.tab.c"
    break;

  case 91: /* expression: MULTI IDENT  */
#line 743 "part1_EL.y"
    {
        Symbol* v = lookupSymbol((yyvsp[0].stringVal));
        if (!v){
            yyerror("Semantic Error: Variable used before declaration.");
            YYABORT;
        }
        char* t = v->returnType;
        for(char*p=t;*p;++p)*p=tolower(*p);

        if (!isPointerType(t)){
            yyerror("Semantic Error: '*' operator can only be applied to pointers.");
            YYABORT;
        }
        (yyval.nodePtr) = mknode("deref", mknode((yyvsp[0].stringVal),NULL,NULL), NULL);
    }
#line 2351 "part1_EL.tab.c"
    break;

  case 92: /* expression: MULTI expression  */
#line 761 "part1_EL.y"
    {
        char* t = inferExprType((yyvsp[0].nodePtr));

        if (!isPointerType(t)){
            yyerror("Semantic Error: '*' operator can only be applied to pointers.");
            YYABORT;
        }
        (yyval.nodePtr) = mknode("unary*", (yyvsp[0].nodePtr), NULL);
    }
#line 2365 "part1_EL.tab.c"
    break;

  case 93: /* expression: '(' expression ')'  */
#line 773 "part1_EL.y"
                                    { (yyval.nodePtr) = (yyvsp[-1].nodePtr); }
#line 2371 "part1_EL.tab.c"
    break;

  case 94: /* expression: LENGTH expression LENGTH  */
#line 775 "part1_EL.y"
                                  { (yyval.nodePtr) = mknode("|", (yyvsp[-1].nodePtr), NULL); }
#line 2377 "part1_EL.tab.c"
    break;

  case 95: /* expression: expression EQL expression  */
#line 779 "part1_EL.y"
                                     { (yyval.nodePtr) = mknode("==",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2383 "part1_EL.tab.c"
    break;

  case 96: /* expression: expression NOTEQL expression  */
#line 780 "part1_EL.y"
                                        { (yyval.nodePtr) = mknode("!=",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2389 "part1_EL.tab.c"
    break;

  case 97: /* expression: expression GREATEREQL expression  */
#line 781 "part1_EL.y"
                                            { (yyval.nodePtr) = mknode(">=",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2395 "part1_EL.tab.c"
    break;

  case 98: /* expression: expression LESSEQL expression  */
#line 782 "part1_EL.y"
                                         { (yyval.nodePtr) = mknode("<=",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2401 "part1_EL.tab.c"
    break;

  case 99: /* expression: expression GREATER expression  */
#line 783 "part1_EL.y"
                                         { (yyval.nodePtr) = mknode(">", (yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2407 "part1_EL.tab.c"
    break;

  case 100: /* expression: expression LESS expression  */
#line 784 "part1_EL.y"
                                      { (yyval.nodePtr) = mknode("<", (yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2413 "part1_EL.tab.c"
    break;

  case 101: /* expression: IDENT '[' expression ']'  */
#line 788 "part1_EL.y"
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
#line 2442 "part1_EL.tab.c"
    break;

  case 102: /* expression: expression AND expression  */
#line 814 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("and",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2448 "part1_EL.tab.c"
    break;

  case 103: /* expression: expression OR expression  */
#line 815 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("or",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2454 "part1_EL.tab.c"
    break;

  case 104: /* expression: TRUE  */
#line 817 "part1_EL.y"
                         { (yyval.nodePtr) = mknode("BOOL", mknode("TRUE", NULL, NULL), NULL); }
#line 2460 "part1_EL.tab.c"
    break;

  case 105: /* expression: FALSE  */
#line 818 "part1_EL.y"
                         { (yyval.nodePtr) = mknode("BOOL", mknode("FALSE", NULL, NULL), NULL); }
#line 2466 "part1_EL.tab.c"
    break;

  case 106: /* expression: LENGTH IDENT LENGTH  */
#line 820 "part1_EL.y"
      { (yyval.nodePtr) = mknode("|", mknode((yyvsp[-1].stringVal),NULL,NULL), NULL); }
#line 2472 "part1_EL.tab.c"
    break;

  case 107: /* expression: func_call  */
#line 824 "part1_EL.y"
                                { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 2478 "part1_EL.tab.c"
    break;


#line 2482 "part1_EL.tab.c"

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

#line 826 "part1_EL.y"
  /* ===================  C‑code section ================================*/

#include "lex.yy.c"

/* ---------- helpers for type checking (added) ---------- */
int  isInt   (const char* t){ return strcasecmp(t,"int"  )==0; }
int  isReal  (const char* t){ return strcasecmp(t,"real" )==0; }
int  isBool  (const char* t){ return strcasecmp(t,"bool" )==0; }
int  isChar  (const char* t){ return strcasecmp(t,"char" )==0; }
int  isStr   (const char* t){ return strcasecmp(t,"string")==0; }

int  isNumeric(const char* t){ return isInt(t)||isReal(t); }

int  samePtrType(const char* a,const char* b){
    /* שם-טיפוס מצביע אצלך הוא תמיד xxxptr */
    return (isPointerType(a)&&isPointerType(b)&&strcasecmp(a,b)==0);
}

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
            semanticErrSeen = 1;
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


int isMainExists()
{
    if (semanticErrSeen)          
        return 0;                 

    if (!mainDeclared) {
        fprintf(stderr,
                "Semantic Error: Missing '_main_' function.\n");
        return 1;
    }
    return 0;
}


void pushScope() {
    scopeDepth++;
}

/* ------------  popScope --------------- */
void popScope()
{
    Symbol **current = &symbolTable;
    while (*current) 
    {
        Symbol *s = *current;

        /* remove only VAR symbols belonging to the scope being popped */
       if (s->scopeDepth == scopeDepth && s->type == VAR) {
            *current = s->next;
            free(s->name);
            if (s->returnType) free(s->returnType);
            free(s);
            continue;                 /* stay at same *current */
        }
        current = &s->next;
    }
    scopeDepth--;
}

int isVarDeclaredInScope(const char* name) {
    Symbol* current = symbolTable;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0 && current->type == VAR) {
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
    if (strcmp(expr->token,"INT"   )==0) return "int";
    if (strcmp(expr->token,"REAL"  )==0) return "real";
    if (strcmp(expr->token,"CHAR"  )==0) return "char";
    if (strcmp(expr->token,"STRING")==0) return "string";
    if (strcmp(expr->token,"BOOL"  )==0) return "bool";
    if (strcmp(expr->token,"NULL"  )==0) return "null";
    if (strcmp(expr->token,"TRUE")==0 || strcmp(expr->token,"FALSE")==0)
    return "bool";

    Symbol* sym = lookupSymbol(expr->token);
    if (sym && sym->type==VAR && sym->returnType){
        char* norm=strdup(sym->returnType);
        for(char*p=norm;*p;++p)*p=tolower(*p);
        return norm;
    }

    /* ------------ אופרטורים בינאריים / יונריים ------------- */
    char* lt = expr->left  ? inferExprType(expr->left ) : NULL;
    char* rt = expr->right ? inferExprType(expr->right) : NULL;

    /* + - * / */
    if (strcmp(expr->token,"+")==0||
        strcmp(expr->token,"-")==0||
        strcmp(expr->token,"*")==0||
        strcmp(expr->token,"/")==0){
        if (!isNumeric(lt)||!isNumeric(rt)){
            yyerror("Semantic Error: arithmetic operators require int/real.");
            return "unknown";
        }
        return (isInt(lt)&&isInt(rt)) ? "int" : "real";
    }

    /* && || */
    if (strcmp(expr->token,"and")==0||strcmp(expr->token,"or")==0){
        if (!isBool(lt)||!isBool(rt)){
            yyerror("Semantic Error: logical operators require bool.");
            return "unknown";
        }
        return "bool";
    }

    /* > < >= <= */
    if (strcmp(expr->token,">")==0||strcmp(expr->token,"<")==0||
        strcmp(expr->token,">=")==0||strcmp(expr->token,"<=")==0){
        if (!isNumeric(lt)||!isNumeric(rt)){
            yyerror("Semantic Error: comparison requires int/real.");
            return "unknown";
        }
        return "bool";
    }

    /* == != */
    if (strcmp(expr->token,"==")==0||strcmp(expr->token,"!=")==0){
        int ok =
            (isInt(lt)&&isInt(rt))   ||
            (isReal(lt)&&isReal(rt)) ||
            (isBool(lt)&&isBool(rt)) ||
            (isChar(lt)&&isChar(rt)) ||
            samePtrType(lt,rt);
        if (!ok){
            yyerror("Semantic Error: illegal types for equality operator.");
            return "unknown";
        }
        return "bool";
    }

    /* |expr| */
    if (strcmp(expr->token,"|")==0){
        if (!isStr(lt)){
            yyerror("Semantic Error: | | expects string.");
            return "unknown";
        }
        return "int";
    }

    /* !expr */
    /* not / !  (unary NOT) */
    if (strcmp(expr->token,"not")==0 || strcmp(expr->token,"!")==0){
    if (!isBool(lt)){
        yyerror("Semantic Error: !/not expects bool.");
        return "unknown";
    }
    return "bool";
    }


        /* &expr  — Address-of */
    if (strcmp(expr->token,"&")==0){
        char* opType = lt;   /* type of operand */

        if (isInt(opType))      return "intptr";
        if (isReal(opType))     return "realptr";
        if (isChar(opType))     return "charptr";
        yyerror("Semantic Error: '&' operator allowed only on int, real, char or string[i].");
        return "unknown";
    }
     /* *expr  -----------------------------------------------------*/
    if (strcmp(expr->token,"deref")==0 || strcmp(expr->token,"unary*")==0){
        char* ptrT = inferExprType(expr->left ? expr->left : expr->right);
        if (!isPointerType(ptrT)){
            yyerror("Semantic Error: '*' operator can only be applied to pointers.");
            return "unknown";
        }
        if (strcasecmp(ptrT,"intptr" )==0) return "int";
        if (strcasecmp(ptrT,"realptr")==0) return "real";
        if (strcasecmp(ptrT,"charptr")==0) return "char";
        return "unknown";   /* pointer אבל לטיפוס אחר – לא אמור לקרות */
    }

    printf("inferExprType: WARNING – unknown token %s\n",expr->token);
    return "unknown";
}

int validateReturnType(node *body, const char *expectedType)
{
    if (!body) return 1;

    if (strcmp(body->token, "FUNCTION") == 0 ||
        strcmp(body->token, "PROC")     == 0) {
        return 1;   /* do NOT look inside – it will be validated later */
    }

    if (strcmp(body->token, "return") == 0) {
        char *actualType = inferExprType(body->left);
        if (strcmp(actualType, expectedType) != 0) {
            char msg[256];
            sprintf(msg,
                "Semantic Error: Return type is '%s' but expected '%s'.",
                actualType, expectedType);
            yyerror(msg);
            return 0;
        }
    }

    if (!validateReturnType(body->left , expectedType)) return 0;
    if (!validateReturnType(body->right, expectedType)) return 0;

    return 1;
}

int isPointerType(const char* type) {
    return strcmp(type, "intptr") == 0 ||
           strcmp(type, "charptr") == 0 ||
           strcmp(type, "realptr") == 0;
}

int registerParams(node* plist) {
    node* p = plist;
    while (p) {
        node* single = (strcmp(p->token, "PARAMS") == 0) ? p->left : p;
        if (single && strcmp(single->token, "PARAM") == 0) {
            char* id  = single->right->token;  // parameter name
            char* typ = single->left->token;   // e.g. INT / REAL

            if (insertSymbol(id, VAR, typ, 0, "param", NULL)) {
                return 1;
            }
        }
        p = (strcmp(p->token, "PARAMS") == 0) ? p->right : NULL;
    }
    return 0;  // success
}

