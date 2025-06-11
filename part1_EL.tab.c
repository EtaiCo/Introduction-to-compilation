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
    int containsReturn(node* body);  
    void generateCode(node *root);
    void dumpCode(FILE *out);


    int mainDeclared = 0;
    int scopeDepth = 0;
    static node *g_lastParamList = NULL;



#line 145 "part1_EL.tab.c"

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
  YYSYMBOL_UMINUS = 51,                    /* UMINUS  */
  YYSYMBOL_DEREF = 52,                     /* DEREF  */
  YYSYMBOL_ELSELESS = 53,                  /* ELSELESS  */
  YYSYMBOL_54_ = 54,                       /* '('  */
  YYSYMBOL_55_ = 55,                       /* ')'  */
  YYSYMBOL_56_ = 56,                       /* ':'  */
  YYSYMBOL_57_ = 57,                       /* ';'  */
  YYSYMBOL_58_ = 58,                       /* '['  */
  YYSYMBOL_59_ = 59,                       /* ']'  */
  YYSYMBOL_60_ = 60,                       /* ','  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_code = 62,                      /* code  */
  YYSYMBOL_functions = 63,                 /* functions  */
  YYSYMBOL_func_scope_start = 64,          /* func_scope_start  */
  YYSYMBOL_function = 65,                  /* function  */
  YYSYMBOL_params_reset = 66,              /* params_reset  */
  YYSYMBOL_params = 67,                    /* params  */
  YYSYMBOL_param_list = 68,                /* param_list  */
  YYSYMBOL_param = 69,                     /* param  */
  YYSYMBOL_type = 70,                      /* type  */
  YYSYMBOL_ident_entry = 71,               /* ident_entry  */
  YYSYMBOL_idents_list = 72,               /* idents_list  */
  YYSYMBOL_literal = 73,                   /* literal  */
  YYSYMBOL_var = 74,                       /* var  */
  YYSYMBOL_dec_list = 75,                  /* dec_list  */
  YYSYMBOL_dec = 76,                       /* dec  */
  YYSYMBOL_statements = 77,                /* statements  */
  YYSYMBOL_state = 78,                     /* state  */
  YYSYMBOL_assign_state = 79,              /* assign_state  */
  YYSYMBOL_stmt_or_block = 80,             /* stmt_or_block  */
  YYSYMBOL_if_state = 81,                  /* if_state  */
  YYSYMBOL_while_state = 82,               /* while_state  */
  YYSYMBOL_do_while_state = 83,            /* do_while_state  */
  YYSYMBOL_for_state = 84,                 /* for_state  */
  YYSYMBOL_for_h = 85,                     /* for_h  */
  YYSYMBOL_advance_exp = 86,               /* advance_exp  */
  YYSYMBOL_rt_state = 87,                  /* rt_state  */
  YYSYMBOL_block_scope_start = 88,         /* block_scope_start  */
  YYSYMBOL_bl_state = 89,                  /* bl_state  */
  YYSYMBOL_func_call = 90,                 /* func_call  */
  YYSYMBOL_exp_list = 91,                  /* exp_list  */
  YYSYMBOL_expression = 92                 /* expression  */
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
#define YYLAST   688

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  218

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   308


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
      54,    55,     2,     2,    60,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,    57,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   129,   129,   137,   138,   143,   153,   231,   290,   294,
     295,   300,   301,   305,   320,   321,   322,   323,   324,   325,
     326,   327,   332,   336,   340,   345,   355,   357,   363,   364,
     365,   366,   367,   368,   370,   374,   376,   380,   381,   386,
     419,   421,   422,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   443,   486,   499,   515,   537,   560,   561,
     565,   575,   588,   603,   625,   635,   646,   648,   654,   669,
     677,   682,   687,   692,   701,   710,   769,   770,   777,   781,
     785,   789,   792,   803,   804,   805,   806,   809,   810,   832,
     834,   852,   865,   866,   871,   872,   873,   874,   875,   876,
     880,   906,   907,   909,   910,   911,   916
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
  "UMINUS", "DEREF", "ELSELESS", "'('", "')'", "':'", "';'", "'['", "']'",
  "','", "$accept", "code", "functions", "func_scope_start", "function",
  "params_reset", "params", "param_list", "param", "type", "ident_entry",
  "idents_list", "literal", "var", "dec_list", "dec", "statements",
  "state", "assign_state", "stmt_or_block", "if_state", "while_state",
  "do_while_state", "for_state", "for_h", "advance_exp", "rt_state",
  "block_scope_start", "bl_state", "func_call", "exp_list", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-182)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-107)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -21,    24,    28,  -182,   -21,    -7,  -182,  -182,    -4,    25,
       1,   153,  -182,    -9,    13,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,    14,    25,    46,    66,  -182,   153,    51,
    -182,  -182,    71,    60,    51,   153,  -182,    71,   196,    61,
      34,  -182,  -182,  -182,  -182,  -182,   -23,   293,   293,    37,
      38,   293,  -182,    88,   293,   293,   315,   293,   324,  -182,
    -182,   293,  -182,    67,   196,  -182,  -182,  -182,  -182,  -182,
    -182,    76,  -182,   529,   403,   196,    93,   262,   293,    43,
     315,  -182,   545,   560,    96,    62,    91,   419,   196,    68,
    -182,  -182,    43,    80,  -182,   -28,   604,   590,  -182,  -182,
      71,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,  -182,    94,   -34,    65,    69,    72,   435,
     367,   293,  -182,   231,    91,    86,    17,   108,  -182,   102,
     143,   293,  -182,  -182,  -182,   106,   643,   632,   140,   140,
      36,    36,    36,    36,    -6,    -6,  -182,  -182,  -182,    49,
     132,    93,  -182,  -182,  -182,    95,   385,  -182,    23,  -182,
    -182,   293,    91,  -182,   293,  -182,  -182,    83,    70,   451,
     196,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,    81,
    -182,   346,  -182,   293,    85,   467,  -182,   483,  -182,   293,
    -182,   113,    87,    97,   499,   575,   231,   293,  -182,  -182,
    -182,   138,  -182,  -182,   231,  -182,   515,  -182,   133,   144,
      99,   115,   104,   231,   293,  -182,  -182,   618
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     1,     3,     8,     0,
       0,     0,    10,    11,     0,    16,    15,    14,    18,    17,
      20,    19,    21,     0,     0,     5,     0,    12,     0,    35,
      13,     5,     0,     0,    35,     0,    36,    37,    40,     0,
       0,    38,    78,    79,    80,    81,    82,     0,     0,     0,
       0,     0,    71,     0,     0,     0,     0,     0,     0,   103,
     104,     0,    43,     0,    40,    44,    45,    46,    48,    47,
      50,     0,    49,    51,     0,    40,     0,     0,     0,    82,
       0,   106,     0,     0,     0,     0,    71,     0,    40,     0,
      89,    87,    82,    91,    88,    82,     0,     0,     7,    42,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,     0,    23,    26,     0,     0,     0,
       0,     0,    91,    71,    71,     0,     0,     0,    70,     0,
       0,     0,   105,    93,    92,     0,   101,   102,    94,    95,
      96,    97,    98,    99,    83,    84,    85,    86,     6,     0,
       0,     0,    39,    56,    53,   100,     0,    58,    60,    49,
      64,     0,    71,    66,     0,    72,    74,     0,    76,     0,
      40,    28,    33,    31,    32,    34,    29,    30,    22,     0,
      27,     0,   100,     0,     0,     0,    67,     0,    75,     0,
      57,     0,    24,    80,     0,     0,    71,     0,    65,    77,
      73,     0,    54,    55,    71,    61,     0,    25,    62,     0,
       0,     0,     0,    71,     0,    68,    63,    69
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -182,  -182,   156,   126,    21,  -182,  -182,   147,  -182,    -8,
    -182,    22,  -182,   -33,   -29,  -182,   -59,  -121,  -182,  -181,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,   120,   -80,   -38,
      -1,   -44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    29,    62,     9,    10,    12,    13,    23,
     116,   117,   178,    33,    36,    37,    63,    64,    65,   158,
      66,    67,    68,    69,    85,   212,    70,    71,    72,    81,
     167,    74
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,    39,   157,    82,    83,    99,   127,    87,    41,     1,
      90,    91,    93,    94,    96,   205,   114,    97,    77,   132,
      31,     4,   149,   208,   150,     4,    73,    40,     6,   129,
     121,     5,   216,   119,   120,    78,   122,    73,   111,   112,
      32,   183,   184,   159,   160,    52,   163,     8,    24,    11,
      73,    -9,   171,   172,   173,   174,    14,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,    25,
      26,   135,    28,    30,    32,   157,   175,   156,   109,   110,
     111,   112,   186,   157,    35,    73,   168,   169,    38,    75,
      76,    84,   157,   162,    86,    89,    98,   176,   177,   100,
     115,   121,   101,   125,   102,   103,   104,   105,   106,   107,
     108,   191,   109,   110,   111,   112,   159,   185,   126,    52,
     187,   131,   130,   148,   159,   151,   152,   161,   164,   153,
     189,   165,    73,   159,   170,   179,   181,   194,   188,   195,
     192,   196,   200,   201,   207,   168,    42,    43,    44,    45,
      79,   211,   210,   206,   202,   213,   214,    34,    73,   215,
       7,    15,    16,    17,    18,    19,    73,    20,    21,    22,
     217,    27,    88,   180,    53,    73,    54,   105,   106,   107,
     108,     0,   109,   110,   111,   112,    55,    80,   199,    57,
      58,    59,    60,     0,     0,     0,     0,    61,   166,    42,
      43,    44,    45,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     0,     0,    48,    49,    50,   -71,
       0,    51,     0,     0,    52,     0,     1,    53,     0,    54,
       0,     0,     0,     0,    42,    43,    44,    45,    46,    55,
      56,     0,    57,    58,    59,    60,     0,     0,    47,     0,
      61,    48,    49,    50,     0,     0,    51,     0,     0,    52,
       0,     1,    53,     0,    54,    42,    43,    44,    45,    79,
       0,     0,     0,     0,    55,    56,     0,    57,    58,    59,
      60,     0,     0,     0,     0,    61,     0,     0,     0,   118,
       0,     0,     0,    53,     0,    54,    42,    43,    44,    45,
      79,     0,     0,     0,     0,    55,    80,     0,    57,    58,
      59,    60,     0,     0,     0,     0,    61,     0,    42,    43,
      44,    45,    92,     0,    53,     0,    54,    42,    43,    44,
      45,    95,     0,     0,     0,     0,    55,    80,     0,    57,
      58,    59,    60,     0,     0,     0,    53,    61,    54,    42,
      43,   193,    45,    79,     0,    53,     0,    54,    55,    80,
       0,    57,    58,    59,    60,     0,     0,    55,    80,    61,
      57,    58,    59,    60,     0,     0,     0,    53,    61,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      80,     0,    57,    58,    59,    60,     0,     0,     0,   101,
      61,   102,   103,   104,   105,   106,   107,   108,     0,   109,
     110,   111,   112,     0,     0,     0,     0,   101,     0,   102,
     103,   104,   105,   106,   107,   108,   155,   109,   110,   111,
     112,     0,     0,     0,     0,   101,     0,   102,   103,   104,
     105,   106,   107,   108,   182,   109,   110,   111,   112,     0,
       0,   101,     0,   102,   103,   104,   105,   106,   107,   108,
     113,   109,   110,   111,   112,     0,     0,   101,     0,   102,
     103,   104,   105,   106,   107,   108,   128,   109,   110,   111,
     112,     0,     0,   101,     0,   102,   103,   104,   105,   106,
     107,   108,   154,   109,   110,   111,   112,     0,     0,   101,
       0,   102,   103,   104,   105,   106,   107,   108,   190,   109,
     110,   111,   112,     0,     0,   101,     0,   102,   103,   104,
     105,   106,   107,   108,   197,   109,   110,   111,   112,     0,
       0,   101,     0,   102,   103,   104,   105,   106,   107,   108,
     198,   109,   110,   111,   112,     0,     0,   101,     0,   102,
     103,   104,   105,   106,   107,   108,   203,   109,   110,   111,
     112,  -106,     0,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
       0,  -106,   209,     0,  -106,     0,     0,   101,     0,   102,
     103,   104,   105,   106,   107,   108,  -106,   109,   110,   111,
     112,     0,   101,     0,   102,   103,   104,   105,   106,   107,
     108,   123,   109,   110,   111,   112,     0,   101,     0,   102,
     103,   104,   105,   106,   107,   108,   124,   109,   110,   111,
     112,     0,   101,     0,   102,   103,   104,   105,   106,   107,
     108,   204,   109,   110,   111,   112,   101,     0,   102,   103,
     104,   105,   106,   107,   108,   134,   109,   110,   111,   112,
     101,   133,   102,   103,   104,   105,   106,   107,   108,     0,
     109,   110,   111,   112,   101,     0,     0,   103,   104,   105,
     106,   107,   108,     0,   109,   110,   111,   112,   103,   104,
     105,   106,   107,   108,     0,   109,   110,   111,   112
};

static const yytype_int16 yycheck[] =
{
      38,    34,   123,    47,    48,    64,    86,    51,    37,    30,
      54,    55,    56,    57,    58,   196,    75,    61,    41,    47,
      28,     0,    56,   204,    58,     4,    64,    35,     0,    88,
      58,     7,   213,    77,    78,    58,    80,    75,    44,    45,
      23,    18,    19,   123,   124,    28,   126,    54,    57,    24,
      88,    55,     3,     4,     5,     6,    55,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,    56,
      56,   100,    26,     7,    23,   196,    27,   121,    42,    43,
      44,    45,   162,   204,    13,   123,   130,   131,    28,    28,
      56,    54,   213,   126,    56,     7,    29,    48,    49,    23,
       7,    58,    32,     7,    34,    35,    36,    37,    38,    39,
      40,   170,    42,    43,    44,    45,   196,   161,    56,    28,
     164,    41,    54,    29,   204,    60,    57,    41,    20,    57,
      60,    29,   170,   213,    28,     3,    41,   181,    55,   183,
      59,    56,    29,    56,     6,   189,     3,     4,     5,     6,
       7,     7,    19,   197,    57,    56,    41,    31,   196,    55,
       4,     8,     9,    10,    11,    12,   204,    14,    15,    16,
     214,    24,    52,   151,    31,   213,    33,    37,    38,    39,
      40,    -1,    42,    43,    44,    45,    43,    44,   189,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    54,    55,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    20,    21,    22,    23,
      -1,    25,    -1,    -1,    28,    -1,    30,    31,    -1,    33,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,    43,
      44,    -1,    46,    47,    48,    49,    -1,    -1,    17,    -1,
      54,    20,    21,    22,    -1,    -1,    25,    -1,    -1,    28,
      -1,    30,    31,    -1,    33,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    43,    44,    -1,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    31,    -1,    33,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    43,    44,    -1,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    54,    -1,     3,     4,
       5,     6,     7,    -1,    31,    -1,    33,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    43,    44,    -1,    46,
      47,    48,    49,    -1,    -1,    -1,    31,    54,    33,     3,
       4,     5,     6,     7,    -1,    31,    -1,    33,    43,    44,
      -1,    46,    47,    48,    49,    -1,    -1,    43,    44,    54,
      46,    47,    48,    49,    -1,    -1,    -1,    31,    54,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    -1,    46,    47,    48,    49,    -1,    -1,    -1,    32,
      54,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      43,    44,    45,    -1,    -1,    -1,    -1,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    59,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    59,    42,    43,    44,    45,    -1,
      -1,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      57,    42,    43,    44,    45,    -1,    -1,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    57,    42,    43,    44,
      45,    -1,    -1,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    57,    42,    43,    44,    45,    -1,    -1,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    57,    42,
      43,    44,    45,    -1,    -1,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    57,    42,    43,    44,    45,    -1,
      -1,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      57,    42,    43,    44,    45,    -1,    -1,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    57,    42,    43,    44,
      45,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    57,    -1,    45,    -1,    -1,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    57,    42,    43,    44,
      45,    -1,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    56,    42,    43,    44,    45,    -1,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    56,    42,    43,    44,
      45,    -1,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    56,    42,    43,    44,    45,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    55,    42,    43,    44,    45,
      32,    47,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    43,    44,    45,    32,    -1,    -1,    35,    36,    37,
      38,    39,    40,    -1,    42,    43,    44,    45,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    44,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,    62,    63,    65,     7,     0,    63,    54,    66,
      67,    24,    68,    69,    55,     8,     9,    10,    11,    12,
      14,    15,    16,    70,    57,    56,    56,    68,    26,    64,
       7,    70,    23,    74,    64,    13,    75,    76,    28,    74,
      70,    75,     3,     4,     5,     6,     7,    17,    20,    21,
      22,    25,    28,    31,    33,    43,    44,    46,    47,    48,
      49,    54,    65,    77,    78,    79,    81,    82,    83,    84,
      87,    88,    89,    90,    92,    28,    56,    41,    58,     7,
      44,    90,    92,    92,    54,    85,    56,    92,    88,     7,
      92,    92,     7,    92,    92,     7,    92,    92,    29,    77,
      23,    32,    34,    35,    36,    37,    38,    39,    40,    42,
      43,    44,    45,    57,    77,     7,    71,    72,    27,    92,
      92,    58,    92,    56,    56,     7,    56,    89,    57,    77,
      54,    41,    47,    47,    55,    75,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    29,    56,
      58,    60,    57,    57,    57,    59,    92,    78,    80,    89,
      89,    41,    74,    89,    20,    29,    55,    91,    92,    92,
      28,     3,     4,     5,     6,    27,    48,    49,    73,     3,
      72,    41,    59,    18,    19,    92,    89,    92,    55,    60,
      57,    77,    59,     5,    92,    92,    56,    57,    57,    91,
      29,    56,    57,    57,    56,    80,    92,     6,    80,    57,
      19,     7,    86,    56,    41,    55,    80,    92
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    63,    63,    64,    65,    65,    66,    67,
      67,    68,    68,    69,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    71,    71,    71,    72,    72,    73,    73,
      73,    73,    73,    73,    73,    74,    74,    75,    75,    76,
      77,    77,    77,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    79,    79,    79,    79,    79,    80,    80,
      81,    81,    81,    81,    82,    83,    84,    84,    85,    86,
      87,    88,    89,    89,    90,    90,    91,    91,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     0,    13,    11,     0,     0,
       2,     1,     3,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     4,     6,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     0,     2,     1,     2,     5,
       0,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     7,     7,     4,     5,     1,     1,
       4,     7,     8,    11,     4,     6,     4,     5,     9,     3,
       3,     0,     4,     6,     4,     5,     1,     3,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     3,     3,     1,     1,     3,     1
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
#line 129 "part1_EL.y"
              {
        ASTRoot = mknode("CODE", (yyvsp[0].nodePtr), NULL);
    }
#line 1464 "part1_EL.tab.c"
    break;

  case 3: /* functions: function functions  */
#line 137 "part1_EL.y"
                                           { (yyval.nodePtr) = mknode("FUNCS",(yyvsp[-1].nodePtr),(yyvsp[0].nodePtr)); }
#line 1470 "part1_EL.tab.c"
    break;

  case 4: /* functions: function  */
#line 138 "part1_EL.y"
                                             { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1476 "part1_EL.tab.c"
    break;

  case 5: /* func_scope_start: %empty  */
#line 143 "part1_EL.y"
             {
        pushScope();
        if (g_lastParamList && registerParams(g_lastParamList)) {
            yyerror("Semantic Error: Duplicate parameter name.");
            YYABORT;
        }
    }
#line 1488 "part1_EL.tab.c"
    break;

  case 6: /* function: DEF IDENT '(' params ')' ':' RETURNS type func_scope_start var T_BEGIN statements END  */
#line 155 "part1_EL.y"
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

        // Rule 9: Function must return correct type and must return at all
        if (!containsReturn((yyvsp[-1].nodePtr))) {
            yyerror("Semantic Error: Function must contain a return statement.");
            YYABORT;
        }

        if (!validateReturnType((yyvsp[-1].nodePtr), returnType)) {
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
        node* bodyN = mknode("BODY", (yyvsp[-3].nodePtr), (yyvsp[-1].nodePtr));  // $9 = var, $12 = statements
        node* defBodyN = mknode("DEF_BODY", returnsN, bodyN);
        (yyval.nodePtr) = mknode("FUNCTION", idN, mknode("FUNC_IN", paramsN, defBodyN));
        popScope();

    }
#line 1568 "part1_EL.tab.c"
    break;

  case 7: /* function: DEF IDENT '(' params ')' ':' func_scope_start var T_BEGIN statements END  */
#line 232 "part1_EL.y"
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
    
        if (containsReturn((yyvsp[-1].nodePtr))) {
            yyerror("Semantic Error: Procedure must not contain return statements.");
            YYABORT;
        }
        node* idN = mknode((yyvsp[-9].stringVal), NULL, NULL);
        node* paramsN = mknode("PARAMS", (yyvsp[-7].nodePtr), NULL);
        node* bodyN = mknode("BODY", (yyvsp[-3].nodePtr), (yyvsp[-1].nodePtr));  // $7 = var, $10 = statements
        (yyval.nodePtr) = mknode("PROC", idN, mknode("PROC_IN", paramsN, bodyN));
        popScope();

    }
#line 1625 "part1_EL.tab.c"
    break;

  case 8: /* params_reset: %empty  */
#line 290 "part1_EL.y"
                                  { paramOrderIdx = 0; }
#line 1631 "part1_EL.tab.c"
    break;

  case 9: /* params: %empty  */
#line 294 "part1_EL.y"
                                        { (yyval.nodePtr) = NULL;            g_lastParamList = NULL; }
#line 1637 "part1_EL.tab.c"
    break;

  case 10: /* params: params_reset param_list  */
#line 295 "part1_EL.y"
                                        { (yyval.nodePtr) = (yyvsp[0].nodePtr);              g_lastParamList = (yyvsp[0].nodePtr);   }
#line 1643 "part1_EL.tab.c"
    break;

  case 11: /* param_list: param  */
#line 300 "part1_EL.y"
                                    { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1649 "part1_EL.tab.c"
    break;

  case 12: /* param_list: param ';' param_list  */
#line 301 "part1_EL.y"
                                  { (yyval.nodePtr) = mknode("PARAMS",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 1655 "part1_EL.tab.c"
    break;

  case 13: /* param: PAR type ':' IDENT  */
#line 306 "part1_EL.y"
        {
            if ((yyvsp[-3].intVal) != paramOrderIdx + 1) {
                yyerror("Semantic Error: parameters must be in sequential order (par1, par2, …).");
                YYABORT;
            }
            paramOrderIdx = (yyvsp[-3].intVal);

            (yyval.nodePtr) = mknode("PARAM", (yyvsp[-2].nodePtr), mknode((yyvsp[0].stringVal), NULL, NULL));
        }
#line 1669 "part1_EL.tab.c"
    break;

  case 14: /* type: INT  */
#line 320 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("INT",NULL,NULL);  }
#line 1675 "part1_EL.tab.c"
    break;

  case 15: /* type: CHAR  */
#line 321 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("CHAR",NULL,NULL); }
#line 1681 "part1_EL.tab.c"
    break;

  case 16: /* type: BOOL  */
#line 322 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("BOOL",NULL,NULL); }
#line 1687 "part1_EL.tab.c"
    break;

  case 17: /* type: STRING  */
#line 323 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("STRING",NULL,NULL);}
#line 1693 "part1_EL.tab.c"
    break;

  case 18: /* type: REAL  */
#line 324 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("REAL",NULL,NULL); }
#line 1699 "part1_EL.tab.c"
    break;

  case 19: /* type: CHARPTR  */
#line 325 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("CHARPTR",NULL,NULL);}
#line 1705 "part1_EL.tab.c"
    break;

  case 20: /* type: INTPTR  */
#line 326 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("INTPTR",NULL,NULL);}
#line 1711 "part1_EL.tab.c"
    break;

  case 21: /* type: REALPTR  */
#line 327 "part1_EL.y"
                  { (yyval.nodePtr) = mknode("REALPTR",NULL,NULL);}
#line 1717 "part1_EL.tab.c"
    break;

  case 22: /* ident_entry: IDENT ':' literal  */
#line 333 "part1_EL.y"
        { (yyval.nodePtr) = mknode("VAR_ASSIGN",
                      mknode("IDENT", mknode((yyvsp[-2].stringVal),NULL,NULL), NULL),
                      (yyvsp[0].nodePtr)); }
#line 1725 "part1_EL.tab.c"
    break;

  case 23: /* ident_entry: IDENT  */
#line 337 "part1_EL.y"
        { (yyval.nodePtr) = mknode("VAR_DECL",
                      mknode("IDENT", mknode((yyvsp[0].stringVal),NULL,NULL), NULL),
                      NULL); }
#line 1733 "part1_EL.tab.c"
    break;

  case 24: /* ident_entry: IDENT '[' INT_LIT ']'  */
#line 341 "part1_EL.y"
        { char buf[32]; sprintf(buf, "%d", (yyvsp[-1].intVal));
          (yyval.nodePtr) = mknode("ARRAY_DECL",
                      mknode("IDENT", mknode((yyvsp[-3].stringVal),NULL,NULL), NULL),
                      mknode(buf, NULL, NULL)); }
#line 1742 "part1_EL.tab.c"
    break;

  case 25: /* ident_entry: IDENT '[' INT_LIT ']' ':' STRING_LIT  */
#line 346 "part1_EL.y"
        { char buf[32]; sprintf(buf, "%d", (yyvsp[-3].intVal));
          (yyval.nodePtr) = mknode("ARRAY_INIT",
                      mknode("ARRAY_DECL",
                             mknode("IDENT", mknode((yyvsp[-5].stringVal),NULL,NULL), NULL),
                             mknode(buf, NULL, NULL)),
                      mknode((yyvsp[0].stringVal), NULL, NULL)); }
#line 1753 "part1_EL.tab.c"
    break;

  case 26: /* idents_list: ident_entry  */
#line 356 "part1_EL.y"
        { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1759 "part1_EL.tab.c"
    break;

  case 27: /* idents_list: ident_entry ',' idents_list  */
#line 358 "part1_EL.y"
        { (yyval.nodePtr) = mknode("ID_LIST", (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr)); }
#line 1765 "part1_EL.tab.c"
    break;

  case 28: /* literal: INT_LIT  */
#line 363 "part1_EL.y"
                       { char ibuf[32]; sprintf(ibuf,"%d",(yyvsp[0].intVal)); (yyval.nodePtr) = mknode("INT", mknode(ibuf,NULL,NULL), NULL); }
#line 1771 "part1_EL.tab.c"
    break;

  case 29: /* literal: TRUE  */
#line 364 "part1_EL.y"
                       { (yyval.nodePtr) = mknode("BOOL", mknode("true", NULL, NULL), NULL); }
#line 1777 "part1_EL.tab.c"
    break;

  case 30: /* literal: FALSE  */
#line 365 "part1_EL.y"
                       { (yyval.nodePtr) = mknode("BOOL", mknode("false", NULL, NULL), NULL); }
#line 1783 "part1_EL.tab.c"
    break;

  case 31: /* literal: CHAR_LIT  */
#line 366 "part1_EL.y"
                       { char cbuf[2] = {(yyvsp[0].charVal),'\0'}; (yyval.nodePtr) = mknode("CHAR", mknode(cbuf,NULL,NULL), NULL); }
#line 1789 "part1_EL.tab.c"
    break;

  case 32: /* literal: STRING_LIT  */
#line 367 "part1_EL.y"
                       { (yyval.nodePtr) = mknode("STRING", mknode((yyvsp[0].stringVal), NULL, NULL), NULL); }
#line 1795 "part1_EL.tab.c"
    break;

  case 33: /* literal: REAL_LIT  */
#line 368 "part1_EL.y"
                       { char r[64]; sprintf(r,"%f",(yyvsp[0].realVal));
                        (yyval.nodePtr) = mknode("REAL", mknode(r,NULL,NULL), NULL); }
#line 1802 "part1_EL.tab.c"
    break;

  case 34: /* literal: NULLL  */
#line 370 "part1_EL.y"
                       { (yyval.nodePtr) = mknode("NULL", NULL, NULL); }
#line 1808 "part1_EL.tab.c"
    break;

  case 35: /* var: %empty  */
#line 375 "part1_EL.y"
    { (yyval.nodePtr) = NULL; }
#line 1814 "part1_EL.tab.c"
    break;

  case 36: /* var: VARIABLE dec_list  */
#line 376 "part1_EL.y"
                                       { (yyval.nodePtr) = mknode("VAR",(yyvsp[0].nodePtr),NULL); }
#line 1820 "part1_EL.tab.c"
    break;

  case 37: /* dec_list: dec  */
#line 380 "part1_EL.y"
                               { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1826 "part1_EL.tab.c"
    break;

  case 38: /* dec_list: dec dec_list  */
#line 381 "part1_EL.y"
                          { (yyval.nodePtr) = mknode("DECS",(yyvsp[-1].nodePtr),(yyvsp[0].nodePtr)); }
#line 1832 "part1_EL.tab.c"
    break;

  case 39: /* dec: TYPE type ':' idents_list ';'  */
#line 387 "part1_EL.y"
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
#line 1866 "part1_EL.tab.c"
    break;

  case 40: /* statements: %empty  */
#line 420 "part1_EL.y"
     {(yyval.nodePtr) = mknode("", NULL,NULL);}
#line 1872 "part1_EL.tab.c"
    break;

  case 41: /* statements: state  */
#line 421 "part1_EL.y"
                    {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1878 "part1_EL.tab.c"
    break;

  case 42: /* statements: state statements  */
#line 422 "part1_EL.y"
                               {(yyval.nodePtr) = mknode("statements", (yyvsp[-1].nodePtr), (yyvsp[0].nodePtr));}
#line 1884 "part1_EL.tab.c"
    break;

  case 43: /* state: function  */
#line 428 "part1_EL.y"
                     {(yyval.nodePtr)=(yyvsp[0].nodePtr);}
#line 1890 "part1_EL.tab.c"
    break;

  case 44: /* state: assign_state  */
#line 429 "part1_EL.y"
                           {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1896 "part1_EL.tab.c"
    break;

  case 45: /* state: if_state  */
#line 430 "part1_EL.y"
                       {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1902 "part1_EL.tab.c"
    break;

  case 46: /* state: while_state  */
#line 431 "part1_EL.y"
                          {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1908 "part1_EL.tab.c"
    break;

  case 47: /* state: for_state  */
#line 432 "part1_EL.y"
                        {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1914 "part1_EL.tab.c"
    break;

  case 48: /* state: do_while_state  */
#line 433 "part1_EL.y"
                             {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1920 "part1_EL.tab.c"
    break;

  case 49: /* state: bl_state  */
#line 434 "part1_EL.y"
                       {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1926 "part1_EL.tab.c"
    break;

  case 50: /* state: rt_state  */
#line 435 "part1_EL.y"
                       {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1932 "part1_EL.tab.c"
    break;

  case 51: /* state: func_call  */
#line 436 "part1_EL.y"
                        {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1938 "part1_EL.tab.c"
    break;

  case 52: /* state: expression ';'  */
#line 437 "part1_EL.y"
                             { (yyval.nodePtr) = (yyvsp[-1].nodePtr); }
#line 1944 "part1_EL.tab.c"
    break;

  case 53: /* assign_state: IDENT ASSIGN expression ';'  */
#line 444 "part1_EL.y"
    {
        /* LHS – חובה שיהיה מוכר  */
        Symbol *lvar = lookupSymbol((yyvsp[-3].stringVal));
        if (!lvar) {
            char msg[128];
            sprintf(msg,
                    "Semantic Error: Variable '%s' used before declaration.", (yyvsp[-3].stringVal));
            yyerror(msg);
            YYABORT;
        }

        /* טיפוסי ימין-ושמאל */
        char *lhsType = strdup(lvar->returnType);
        for (char *p = lhsType; *p; ++p) *p = tolower(*p);

        char *rhsType = inferExprType((yyvsp[-1].nodePtr));

        /* ❶ “unknown” → נניח שזה בעצם הטיפוס של הצד השמאלי
               (נפטר מהשגיאה כשהטיפוס יתברר סופית)                   */
        if (!strcmp(rhsType, "unknown"))
            rhsType = lhsType;

        /* ❷ מותר int→bool */
        if (!strcmp(lhsType, "bool") && !strcmp(rhsType, "int"))
            rhsType = lhsType;

        /* ❸ אם עדיין לא זהים – שגיאה */
        if (strcmp(lhsType, rhsType) != 0) {
            char msg[256];
            sprintf(msg,
                    "Semantic Error: Cannot assign type '%s' to variable '%s' of type '%s'.",
                    rhsType, (yyvsp[-3].stringVal), lhsType);
            yyerror(msg);
            YYABORT;
        }

        (yyval.nodePtr) = mknode("assign",
                    mknode((yyvsp[-3].stringVal), NULL, NULL),
                    (yyvsp[-1].nodePtr));
    }
#line 1989 "part1_EL.tab.c"
    break;

  case 54: /* assign_state: IDENT '[' expression ']' ASSIGN CHAR_LIT ';'  */
#line 487 "part1_EL.y"
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
#line 2005 "part1_EL.tab.c"
    break;

  case 55: /* assign_state: IDENT '[' expression ']' ASSIGN expression ';'  */
#line 500 "part1_EL.y"
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
#line 2023 "part1_EL.tab.c"
    break;

  case 56: /* assign_state: IDENT ASSIGN NULLL ';'  */
#line 516 "part1_EL.y"
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
#line 2047 "part1_EL.tab.c"
    break;

  case 57: /* assign_state: MULTI expression ASSIGN expression ';'  */
#line 538 "part1_EL.y"
    {
        char* lhsType = inferExprType((yyvsp[-3].nodePtr));  // the pointer
        char* rhsType = inferExprType((yyvsp[-1].nodePtr));  // the value to assign

        if (!isPointerType(lhsType)) {
            yyerror("Semantic Error: Left-hand side must be a pointer.");
            YYABORT;
        }

        if ((strcasecmp(lhsType, "intptr") == 0 && !isInt(rhsType)) ||
            (strcasecmp(lhsType, "realptr") == 0 && !isReal(rhsType)) ||
            (strcasecmp(lhsType, "charptr") == 0 && !isChar(rhsType))) {
            yyerror("Semantic Error: Dereferenced pointer type mismatch.");
            YYABORT;
        }

        (yyval.nodePtr) = mknode("deref_assign", (yyvsp[-3].nodePtr), (yyvsp[-1].nodePtr));  // $2 is expression for pointer, not just IDENT
    }
#line 2070 "part1_EL.tab.c"
    break;

  case 60: /* if_state: IF expression ':' stmt_or_block  */
#line 566 "part1_EL.y"
      {
          char *t = inferExprType((yyvsp[-2].nodePtr));
          if (strcmp(t, "bool") != 0 && strcmp(t, "unknown") != 0) {
              yyerror("Semantic Error: IF condition must be of type 'bool'.");
              YYABORT;
          }
          (yyval.nodePtr) = mknode("if", (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr));
      }
#line 2083 "part1_EL.tab.c"
    break;

  case 61: /* if_state: IF expression ':' stmt_or_block ELSE ':' stmt_or_block  */
#line 576 "part1_EL.y"
      {
          char *t = inferExprType((yyvsp[-5].nodePtr));
          if (strcmp(t, "bool") != 0 && strcmp(t, "unknown") != 0) {
              yyerror("Semantic Error: IF condition must be of type 'bool'.");
              YYABORT;
          }
          (yyval.nodePtr) = mknode("if_else",
                       (yyvsp[-5].nodePtr),
                       mknode("then", (yyvsp[-3].nodePtr),
                              mknode("else", (yyvsp[0].nodePtr), NULL)));
      }
#line 2099 "part1_EL.tab.c"
    break;

  case 62: /* if_state: IF expression ':' stmt_or_block ELIF expression ':' stmt_or_block  */
#line 589 "part1_EL.y"
      {
          char *t1 = inferExprType((yyvsp[-6].nodePtr));
          char *t2 = inferExprType((yyvsp[-2].nodePtr));
          if ( (strcmp(t1, "bool") != 0 && strcmp(t1, "unknown") != 0) ||
               (strcmp(t2, "bool") != 0 && strcmp(t2, "unknown") != 0) ) {
              yyerror("Semantic Error: IF and ELIF conditions must be of type 'bool'.");
              YYABORT;
          }
          (yyval.nodePtr) = mknode("if_elif",
                       (yyvsp[-6].nodePtr),
                       mknode("then", (yyvsp[-4].nodePtr),
                              mknode("elif", (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr))));
      }
#line 2117 "part1_EL.tab.c"
    break;

  case 63: /* if_state: IF expression ':' stmt_or_block ELIF expression ':' stmt_or_block ELSE ':' stmt_or_block  */
#line 606 "part1_EL.y"
      {
          char *t1 = inferExprType((yyvsp[-9].nodePtr));
          char *t2 = inferExprType((yyvsp[-5].nodePtr));
          if ( (strcmp(t1, "bool") != 0 && strcmp(t1, "unknown") != 0) ||
               (strcmp(t2, "bool") != 0 && strcmp(t2, "unknown") != 0) ) {
              yyerror("Semantic Error: IF and ELIF conditions must be of type 'bool'.");
              YYABORT;
          }
          (yyval.nodePtr) = mknode("if_elif-else",
                       (yyvsp[-9].nodePtr),
                       mknode("then", (yyvsp[-7].nodePtr),
                              mknode("elif", (yyvsp[-5].nodePtr),
                                     mknode("elif-then", (yyvsp[-3].nodePtr),
                                            mknode("else", (yyvsp[0].nodePtr), NULL)))));
      }
#line 2137 "part1_EL.tab.c"
    break;

  case 64: /* while_state: WHILE expression ':' bl_state  */
#line 626 "part1_EL.y"
    {
        if (strcmp(inferExprType((yyvsp[-2].nodePtr)), "bool") != 0) {
            yyerror("Semantic Error: WHILE condition must be of type 'bool'.");
            YYABORT;
        }
        (yyval.nodePtr) = mknode("while", (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr));
    }
#line 2149 "part1_EL.tab.c"
    break;

  case 65: /* do_while_state: DO ':' bl_state WHILE expression ';'  */
#line 636 "part1_EL.y"
    {
        if (strcmp(inferExprType((yyvsp[-1].nodePtr)), "bool") != 0) {
            yyerror("Semantic Error: DO-WHILE condition must be of type 'bool'.");
            YYABORT;
        }
        (yyval.nodePtr) = mknode("do_while", (yyvsp[-3].nodePtr), mknode("condition", (yyvsp[-1].nodePtr), NULL));
    }
#line 2161 "part1_EL.tab.c"
    break;

  case 66: /* for_state: FOR for_h ':' bl_state  */
#line 646 "part1_EL.y"
                                       {
          (yyval.nodePtr) = mknode("for",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2168 "part1_EL.tab.c"
    break;

  case 67: /* for_state: FOR for_h ':' var bl_state  */
#line 648 "part1_EL.y"
                                        {
          (yyval.nodePtr) = mknode("for",(yyvsp[-3].nodePtr),
                      mknode("block",(yyvsp[0].nodePtr),(yyvsp[-1].nodePtr))); }
#line 2176 "part1_EL.tab.c"
    break;

  case 68: /* for_h: '(' IDENT ASSIGN expression ';' expression ';' advance_exp ')'  */
#line 657 "part1_EL.y"
    {
        if (strcmp(inferExprType((yyvsp[-3].nodePtr)), "bool") != 0) {
            yyerror("Semantic Error: FOR condition must be of type 'bool'.");
            YYABORT;
        }
        (yyval.nodePtr) = mknode("for_header",
                    mknode("init", mknode((yyvsp[-7].stringVal), NULL, NULL), (yyvsp[-5].nodePtr)),
                    mknode("loop", (yyvsp[-3].nodePtr), (yyvsp[-1].nodePtr)));
    }
#line 2190 "part1_EL.tab.c"
    break;

  case 69: /* advance_exp: IDENT ASSIGN expression  */
#line 669 "part1_EL.y"
                                             {
          (yyval.nodePtr) = mknode("update",
                      mknode((yyvsp[-2].stringVal),NULL,NULL),(yyvsp[0].nodePtr)); }
#line 2198 "part1_EL.tab.c"
    break;

  case 70: /* rt_state: RETURN expression ';'  */
#line 677 "part1_EL.y"
                                                 { (yyval.nodePtr) = mknode("return",(yyvsp[-1].nodePtr),NULL); }
#line 2204 "part1_EL.tab.c"
    break;

  case 71: /* block_scope_start: %empty  */
#line 682 "part1_EL.y"
             { pushScope(); }
#line 2210 "part1_EL.tab.c"
    break;

  case 72: /* bl_state: T_BEGIN block_scope_start statements END  */
#line 688 "part1_EL.y"
      { popScope();  (yyval.nodePtr) = mknode("block", (yyvsp[-1].nodePtr), NULL); }
#line 2216 "part1_EL.tab.c"
    break;

  case 73: /* bl_state: block_scope_start VARIABLE dec_list T_BEGIN statements END  */
#line 693 "part1_EL.y"
      { popScope();
        /* $3 = dec_list, $5 = statements                     */
        (yyval.nodePtr) = mknode("block", (yyvsp[-1].nodePtr), mknode("VAR", (yyvsp[-3].nodePtr), NULL)); }
#line 2224 "part1_EL.tab.c"
    break;

  case 74: /* func_call: CALL IDENT '(' ')'  */
#line 701 "part1_EL.y"
                         {
          Symbol* f = lookupSymbol((yyvsp[-2].stringVal));
          if (!f || f->type != FUNC) {
              yyerror("Semantic Error: Function called before definition.");
              YYABORT;
          }
          (yyval.nodePtr) = mknode("call", mknode((yyvsp[-2].stringVal),NULL,NULL), NULL);
      }
#line 2237 "part1_EL.tab.c"
    break;

  case 75: /* func_call: CALL IDENT '(' exp_list ')'  */
#line 710 "part1_EL.y"
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
    node *exprNode = (strcmp(temp->token, "exp_list") == 0)
                     ? temp->left          /* צומת הביטוי */
                     : temp;

    char *actualType   = inferExprType(exprNode);
    char *expectedType = f->paramTypes[index];

    /* קידומי-טיפוס מותרים */
    int ok = 0;
    if (!strcmp(actualType, expectedType))                 ok = 1; /* זהה */
    else if (!strcmp(actualType, "char") &&
             !strcmp(expectedType, "int"))                 ok = 1; /* char→int */
    else if (!strcmp(actualType, "unknown"))               ok = 1; /* עדיין לא ידוע */

    if (!ok) {
        char msg[256];
        sprintf(msg,
                "Semantic Error: Argument %d in call to '%s' has type '%s' but expected '%s'.",
                index + 1, f->name, actualType, expectedType);
        yyerror(msg);
        YYABORT;
    }

    temp  = (strcmp(temp->token, "exp_list") == 0) ? temp->right : NULL;
    index++;
}

    (yyval.nodePtr) = mknode("call", mknode((yyvsp[-3].stringVal),NULL,NULL), (yyvsp[-1].nodePtr));
}
#line 2297 "part1_EL.tab.c"
    break;

  case 76: /* exp_list: expression  */
#line 769 "part1_EL.y"
                                                   { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 2303 "part1_EL.tab.c"
    break;

  case 77: /* exp_list: expression ',' exp_list  */
#line 770 "part1_EL.y"
                                                  { (yyval.nodePtr) = mknode("exp_list",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2309 "part1_EL.tab.c"
    break;

  case 78: /* expression: INT_LIT  */
#line 778 "part1_EL.y"
        { char ibuf[32]; sprintf(ibuf,"%d",(yyvsp[0].intVal));
        (yyval.nodePtr) = mknode("INT", mknode(strdup(ibuf),NULL,NULL), NULL); }
#line 2316 "part1_EL.tab.c"
    break;

  case 79: /* expression: REAL_LIT  */
#line 782 "part1_EL.y"
        { char rbuf[64]; sprintf(rbuf,"%f",(yyvsp[0].realVal));
        (yyval.nodePtr) = mknode("REAL", mknode(strdup(rbuf),NULL,NULL), NULL); }
#line 2323 "part1_EL.tab.c"
    break;

  case 80: /* expression: CHAR_LIT  */
#line 786 "part1_EL.y"
        { char cbuf[2] = { (char)(yyvsp[0].charVal), '\0' };
        (yyval.nodePtr) = mknode("CHAR", mknode(strdup(cbuf),NULL,NULL), NULL); }
#line 2330 "part1_EL.tab.c"
    break;

  case 81: /* expression: STRING_LIT  */
#line 790 "part1_EL.y"
        { (yyval.nodePtr) = mknode("STRING", mknode(strdup((yyvsp[0].stringVal)),NULL,NULL), NULL); }
#line 2336 "part1_EL.tab.c"
    break;

  case 82: /* expression: IDENT  */
#line 792 "part1_EL.y"
            {
        if (!isVarDeclaredInScope((yyvsp[0].stringVal))) {
            char msg[128];
            sprintf(msg, "Semantic Error: Variable '%s' used before declaration.", (yyvsp[0].stringVal));
            yyerror(msg);
            YYABORT;
        }
        (yyval.nodePtr) = mknode((yyvsp[0].stringVal),NULL,NULL);
    }
#line 2350 "part1_EL.tab.c"
    break;

  case 83: /* expression: expression PLUS expression  */
#line 803 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("+",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2356 "part1_EL.tab.c"
    break;

  case 84: /* expression: expression MINUS expression  */
#line 804 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("-",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2362 "part1_EL.tab.c"
    break;

  case 85: /* expression: expression MULTI expression  */
#line 805 "part1_EL.y"
                                     { (yyval.nodePtr) = mknode("*",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2368 "part1_EL.tab.c"
    break;

  case 86: /* expression: expression DIV expression  */
#line 806 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("/",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2374 "part1_EL.tab.c"
    break;

  case 87: /* expression: MINUS expression  */
#line 809 "part1_EL.y"
                                         { (yyval.nodePtr) = mknode("unary-",(yyvsp[0].nodePtr),NULL); }
#line 2380 "part1_EL.tab.c"
    break;

  case 88: /* expression: ADDRESS expression  */
#line 811 "part1_EL.y"
    {
        char* baseType = inferExprType((yyvsp[0].nodePtr));

        if (isInt(baseType)) {
            (yyval.nodePtr) = mknode("&", (yyvsp[0].nodePtr), NULL);
        }
        else if (isReal(baseType)) {
            (yyval.nodePtr) = mknode("&", (yyvsp[0].nodePtr), NULL);
            (yyval.nodePtr)->token = strdup("realptr");
        }
        else if (isChar(baseType)) {
            (yyval.nodePtr) = mknode("&", (yyvsp[0].nodePtr), NULL);
            (yyval.nodePtr)->token = strdup("charptr");
        }
        else {
            yyerror("Semantic Error: '&' operator allowed only on int, real, char or string[i].");
            YYABORT;
        }
    }
#line 2404 "part1_EL.tab.c"
    break;

  case 89: /* expression: NOT expression  */
#line 832 "part1_EL.y"
                                  { (yyval.nodePtr) = mknode("not", (yyvsp[0].nodePtr), NULL); }
#line 2410 "part1_EL.tab.c"
    break;

  case 90: /* expression: MULTI IDENT  */
#line 835 "part1_EL.y"
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
#line 2430 "part1_EL.tab.c"
    break;

  case 91: /* expression: MULTI expression  */
#line 853 "part1_EL.y"
    {
        char* t = inferExprType((yyvsp[0].nodePtr));

        if (!isPointerType(t)){
            yyerror("Semantic Error: '*' operator can only be applied to pointers.");
            YYABORT;
        }
        (yyval.nodePtr) = mknode("unary*", (yyvsp[0].nodePtr), NULL);
    }
#line 2444 "part1_EL.tab.c"
    break;

  case 92: /* expression: '(' expression ')'  */
#line 865 "part1_EL.y"
                                    { (yyval.nodePtr) = (yyvsp[-1].nodePtr); }
#line 2450 "part1_EL.tab.c"
    break;

  case 93: /* expression: LENGTH expression LENGTH  */
#line 867 "part1_EL.y"
                                  { (yyval.nodePtr) = mknode("|", (yyvsp[-1].nodePtr), NULL); }
#line 2456 "part1_EL.tab.c"
    break;

  case 94: /* expression: expression EQL expression  */
#line 871 "part1_EL.y"
                                     { (yyval.nodePtr) = mknode("==",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2462 "part1_EL.tab.c"
    break;

  case 95: /* expression: expression NOTEQL expression  */
#line 872 "part1_EL.y"
                                        { (yyval.nodePtr) = mknode("!=",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2468 "part1_EL.tab.c"
    break;

  case 96: /* expression: expression GREATEREQL expression  */
#line 873 "part1_EL.y"
                                            { (yyval.nodePtr) = mknode(">=",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2474 "part1_EL.tab.c"
    break;

  case 97: /* expression: expression LESSEQL expression  */
#line 874 "part1_EL.y"
                                         { (yyval.nodePtr) = mknode("<=",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2480 "part1_EL.tab.c"
    break;

  case 98: /* expression: expression GREATER expression  */
#line 875 "part1_EL.y"
                                         { (yyval.nodePtr) = mknode(">", (yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2486 "part1_EL.tab.c"
    break;

  case 99: /* expression: expression LESS expression  */
#line 876 "part1_EL.y"
                                      { (yyval.nodePtr) = mknode("<", (yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2492 "part1_EL.tab.c"
    break;

  case 100: /* expression: IDENT '[' expression ']'  */
#line 880 "part1_EL.y"
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
#line 2521 "part1_EL.tab.c"
    break;

  case 101: /* expression: expression AND expression  */
#line 906 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("and",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2527 "part1_EL.tab.c"
    break;

  case 102: /* expression: expression OR expression  */
#line 907 "part1_EL.y"
                                    { (yyval.nodePtr) = mknode("or",(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr)); }
#line 2533 "part1_EL.tab.c"
    break;

  case 103: /* expression: TRUE  */
#line 909 "part1_EL.y"
                         { (yyval.nodePtr) = mknode("BOOL", mknode("TRUE", NULL, NULL), NULL); }
#line 2539 "part1_EL.tab.c"
    break;

  case 104: /* expression: FALSE  */
#line 910 "part1_EL.y"
                         { (yyval.nodePtr) = mknode("BOOL", mknode("FALSE", NULL, NULL), NULL); }
#line 2545 "part1_EL.tab.c"
    break;

  case 105: /* expression: LENGTH IDENT LENGTH  */
#line 912 "part1_EL.y"
      { (yyval.nodePtr) = mknode("|", mknode((yyvsp[-1].stringVal),NULL,NULL), NULL); }
#line 2551 "part1_EL.tab.c"
    break;

  case 106: /* expression: func_call  */
#line 916 "part1_EL.y"
                                { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 2557 "part1_EL.tab.c"
    break;


#line 2561 "part1_EL.tab.c"

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

#line 918 "part1_EL.y"
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
    return (isPointerType(a)&&isPointerType(b)&&strcasecmp(a,b)==0);
}

/* ----------------------------  main  ------------------------------------*/
int main(void)
{
    yyparse();

    if (isMainExists()) return 1;

    generateCode(ASTRoot);     
    
    dumpCode(stdout); 

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

       if (s->scopeDepth == scopeDepth && s->type == VAR) {
            *current = s->next;
            free(s->name);
            if (s->returnType) free(s->returnType);
            free(s);
            continue;                 
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

    if (sym && sym->type == FUNC && sym->returnType) {
    char *lt = strdup(sym->returnType);
    for (char *p = lt; *p; ++p) *p = tolower(*p);
    return lt;
}
    if (sym && sym->type == VAR && sym->returnType) {
    char *norm = strdup(sym->returnType);   /* deep-copy + lowercase */
    for (char *p = norm; *p; ++p) *p = tolower(*p);
    return norm;
}

if (isalpha((unsigned char)expr->token[0])) {
    return "unknown";      /* נשאר לא ידוע עד שהמזהה מוכר */
}

    char* lt = expr->left  ? inferExprType(expr->left ) : NULL;
    char* rt = expr->right ? inferExprType(expr->right) : NULL;

    /* +  -  *  /  ----------------------------------------------------------- */
if (!strcmp(expr->token,"+") ||
    !strcmp(expr->token,"-") ||
    !strcmp(expr->token,"*") ||
    !strcmp(expr->token,"/"))
{
    int lOK = isNumeric(lt) || !strcmp(lt,"unknown");
    int rOK = isNumeric(rt) || !strcmp(rt,"unknown");

    if (!lOK || !rOK) {
        yyerror("Semantic Error: arithmetic operators require int/real.");
        return "unknown";
    }

    /* אם שניהם int – התוצאה int; אחרת (או אם לא ידוע) → real/unknown */
    if (!strcmp(lt,"int") && !strcmp(rt,"int")) return "int";
    if (!strcmp(lt,"unknown") || !strcmp(rt,"unknown")) return "unknown";
    return "real";
}

/* >  <  >=  <=  --------------------------------------------------------- */
if (!strcmp(expr->token,">")  || !strcmp(expr->token,"<")  ||
    !strcmp(expr->token,">=") || !strcmp(expr->token,"<="))
{
    int lOK = isNumeric(lt) || !strcmp(lt,"unknown");
    int rOK = isNumeric(rt) || !strcmp(rt,"unknown");

    if (!lOK || !rOK) {
        yyerror("Semantic Error: comparison requires int/real.");
        return "unknown";
    }
    return "bool";
}

/* ==  !=  --------------------------------------------------------------- */
if (!strcmp(expr->token,"==") || !strcmp(expr->token,"!="))
{
    int legal =
        (isInt(lt)&&isInt(rt))     || (isReal(lt)&&isReal(rt)) ||
        (isBool(lt)&&isBool(rt))   || (isChar(lt)&&isChar(rt)) ||
        samePtrType(lt,rt)         ||
        !strcmp(lt,"unknown")      || !strcmp(rt,"unknown");

    if (!legal) {
        yyerror("Semantic Error: illegal types for equality operator.");
        return "unknown";
    }
    return "bool";
}

/* | expr |  ------------------------------------------------------------- */
if (!strcmp(expr->token,"|"))
{
    if (!isStr(lt) && strcmp(lt,"unknown")!=0) {
        yyerror("Semantic Error: | | expects string.");
        return "unknown";
    }
    return "int";
}

    /* string[i] */
    if (strcmp(expr->token, "index") == 0) 
    {
    char* baseName = expr->left->token;  // s in s[2]
    Symbol* sym = lookupSymbol(baseName);
    if (sym && sym->type == VAR && strcasecmp(sym->returnType, "string") == 0) {
        return "char";  // string[i] yields a char
    }
    return "unknown";
    }

    /* !expr */
    /* not / !  (unary NOT) */



   if (strcmp(expr->token,"&")==0){
    char* operandType = inferExprType(expr->left); 

    if (isInt(operandType))      return "intptr";
    if (isReal(operandType))     return "realptr";
    if (isChar(operandType))     return "charptr";
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
        return "unknown";   
    }
    // Function call inference
    if (strcmp(expr->token, "call") == 0) {
        if (!expr->left || !expr->left->token) {
            return "unknown";
        }
        char* fname = expr->left->token;
        Symbol* f = lookupSymbol(fname);
        if (f && f->type == FUNC && f->returnType) {
            char* lowered = strdup(f->returnType);
            for (char* p = lowered; *p; ++p) *p = tolower(*p);
            return lowered;
        }
        return "unknown";
    }
    if (strcmp(expr->token,"exp_list")==0)
    return "unknown";
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

int containsReturn(node *body)
{
    if (!body) return 0;

    if (strcmp(body->token,"FUNCTION")==0 || strcmp(body->token,"PROC")==0)
        return 0;

    if (strcmp(body->token,"return")==0)
        return 1;              

    if (containsReturn(body->left )) return 1;
    if (containsReturn(body->right)) return 1;

    return 0;
}

/* =========================  3-ADDRESS-CODE GENERATOR  =========================
   ⬇  Paste this whole module *after* your existing C-code section (before the
      final closing brace).  Nothing in Parts 1-2 is changed.                */
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

/* ---------- instruction list infrastructure ---------- */
typedef struct Instr {
    char *text;
    struct Instr *next;
} Instr;

static Instr *codeHead = NULL, *codeTail = NULL;
static int    tempCnt  = 0;
static int    labelCnt = 1;

static char *newTemp () { char b[32]; sprintf(b,"t%d", tempCnt++);  return strdup(b); }
static char *newLabel() { char b[32]; sprintf(b,"L%d", labelCnt++); return strdup(b); }

static void emit(const char *fmt, ...)
{
    va_list ap; char buf[128];
    va_start(ap, fmt); vsnprintf(buf, sizeof(buf), fmt, ap); va_end(ap);

    Instr *n = (Instr *)malloc(sizeof(Instr));
    n->text = strdup(buf); n->next = NULL;
    if (!codeHead) codeHead = codeTail = n;
    else           codeTail = codeTail->next = n;
}

void dumpCode(FILE *out)
{
    const char *IND = "    ";                 /* 4-spaces indentation */

    for (Instr *p = codeHead; p; p = p->next) {
        const char *txt = p->text;
        size_t      len = strlen(txt);

        /* LABEL או כותרת פונקציה - משאירים צמוד לשמאל */
        if (len > 0 && txt[len - 1] == ':')
            fprintf(out, "%s\n", txt);
        else
            fprintf(out, "%s%s\n", IND, txt); /* שאר ההוראות מוזחות */
    }
}

/* ---------- helpers --------------------------------------------------------- */
static int isLiteral(const char *tok)
{
    return !strcmp(tok,"INT")   || !strcmp(tok,"REAL") ||
           !strcmp(tok,"CHAR")  || !strcmp(tok,"STRING") ||
           !strcmp(tok,"BOOL");
}

/* AST stores literal value in lit->left->token */
static const char *literalValue(node *lit)
{
    return (lit->left && lit->left->token) ? lit->left->token : "0";
}

/* fast sizeof for frame calculation (4-byte default) */
static int sizeofType(const char *t)
{
    if (!t) return 4;
    if (!strcasecmp(t,"real")   || !strcasecmp(t,"realptr"))   return 8;
    if (!strcasecmp(t,"string"))                               return 8;
    return 4;   /* int, char, bool, intptr, charptr … */
}
/* ===== TEMP-SIZE TRACKING =========================================== */
static int tempBytesInFunc = 0;          /* reset at each genFunction */

/* byte size of the value produced by expression e */
static int resultSize(node *e)
{
    const char *t = inferExprType(e);    /* "int", "realptr", …        */
    if (!t) return 4;
    if (!strcasecmp(t,"real") || !strcasecmp(t,"realptr")
                              || !strcasecmp(t,"string"))
        return 8;                       /* 8-byte values              */
    return 4;                           /* everything else            */
}

/* allocate a temp for expression e and remember its size */
static char *makeTempFor(node *e)
{
    tempBytesInFunc += resultSize(e);
    char buf[32]; sprintf(buf,"t%d", tempCnt++);
    return strdup(buf);
}


/* modify “BeginFunc 0” with real byte count */
static void patchBeginSize(Instr *beginLine, int bytes)
{
    char buf[16]; sprintf(buf, "%d", bytes);
    /* "BeginFunc " is 10 chars, overwrite from there */
    strcpy(beginLine->text + 10, buf);
}

/* ---------- forward decls for mutually recursive generators --------------- */
static char *genExpr(node *e);
static void  genStmt(node *s);

/* ---------- expression → 3AC (returns temp / var name) -------------------- */
/* ===== helpers for conditions ===== */
static int isCmpOp(const char *t)
{
    return !strcmp(t,"==") || !strcmp(t,"!=") ||
           !strcmp(t,"<")  || !strcmp(t,">")  ||
           !strcmp(t,"<=") || !strcmp(t,">=");
}

/* מחזיר אופֵרנד – אם זה ליטרל מחזיר את הערך עצמו, אחרת קורא ל-genExpr */
static char *genOperand(node *e)
{
    if (isLiteral(e->token))           /* מספר/תֵו/מחרוזת/TRUE/FALSE/NULL */
        return strdup(literalValue(e));/* לא יוצר טמפוררי */
    return genExpr(e);                 /* כל השאר – כרגיל */
}
static char *genExpr(node *e)
{
    if (!e) return strdup("0");

    /* 1. terminals ---------------------------------------------------- */
    if (isLiteral(e->token)) {
        char *t =makeTempFor(e);
        emit("%s = %s", t, literalValue(e));
        return t;
    }
    if (!strcmp(e->token,"TRUE") || !strcmp(e->token,"FALSE")) {
        char *t =makeTempFor(e);
        emit("%s = %s", t, !strcmp(e->token,"TRUE") ? "1" : "0");
        return t;
    }
    if (!strcmp(e->token,"NULL")) {
        char *t =makeTempFor(e);
        emit("%s = 0", t);
        return t;
    }
    if (lookupSymbol(e->token)) {          /* variable / param */
        return strdup(e->token);           /* already stored */
    }
    if (isalpha((unsigned char)e->token[0])) {
    return strdup(e->token);           /* treat as plain variable */
    }

    /* 2. unary -------------------------------------------------------- */
    if (!strcmp(e->token,"unary-")) {
        char *v = genExpr(e->left);
        char *t =makeTempFor(e); emit("%s = - %s", t, v); return t;
    }
    if (!strcmp(e->token,"not")) {
        char *v = genExpr(e->left);
        char *t =makeTempFor(e); emit("%s = ! %s", t, v); return t;
    }
    if (!strcmp(e->token,"&")) {
        char *v = genExpr(e->left);
        char *t =makeTempFor(e); emit("%s = & %s", t, v); return t;
    }
    if (!strcmp(e->token,"deref") || !strcmp(e->token,"unary*")) {
        char *p = genExpr(e->left ? e->left : e->right);
        char *t =makeTempFor(e); emit("%s = * %s", t, p); return t;
    }

    /* 3. binary arithmetic / logic ----------------------------------- */
    const char *binOps[] = {"+","-","*","/","and","or",
                            "==","!=","<",">","<=",">="};
    for (size_t i = 0; i < sizeof(binOps)/sizeof(binOps[0]); ++i) {
        if (!strcmp(e->token, binOps[i])) {
            char *l = genExpr(e->left);
            char *r = genExpr(e->right);
            char *t =makeTempFor(e);
            emit("%s = %s %s %s", t, l, binOps[i], r);
            return t;
        }
    }

    /* 4. array indexing ---------------------------------------------- */
    if (!strcmp(e->token,"index")) {
        char *base = genExpr(e->left);   /* IDENT gives name */
        char *idx  = genExpr(e->right);
        char *t    =makeTempFor(e);
        emit("%s = %s [ %s ]", t, base, idx);
        return t;
    }

    /* 5. function call ----------------------------------------------- */
    if (!strcmp(e->token,"call")) {
        const char *fname = e->left->token;

        /* gather params into stack[] for reverse push                  */
        node *stack[32]; int top = 0;
        for (node *p = e->right; p; p = (!strcmp(p->token,"exp_list")) ? p->right : NULL)
            stack[top++] = (!strcmp(p->token,"exp_list")) ? p->left : p;

        int bytes = 0;
        for (int i = top - 1; i >= 0; --i) {
            char *val = genExpr(stack[i]);
            emit("PushParam %s", val);
            bytes += sizeofType(inferExprType(stack[i]));
        }

        char *ret =makeTempFor(e);
        emit("%s = LCall %s", ret, fname);
        if (bytes) emit("PopParams %d", bytes);
        return ret;
    }

    fprintf(stderr,"[CodeGen] unhandled expr token %s\n", e->token);
    return strdup("0");
}

/* ---------- statement generator ---------------------------------------- */
static void genStmt(node *s)
{
    if (!s || !s->token) return;

    /* list of statements */
    if (!strcmp(s->token,"statements")) { genStmt(s->left); genStmt(s->right); return; }

    /* assignments ----------------------------------------------------- */
    if (!strcmp(s->token,"assign")) {
        char *rhs = genExpr(s->right);
        emit("%s = %s", s->left->token, rhs);
        return;
    }
    if (!strcmp(s->token,"deref_assign")) {
        char *lhs = genExpr(s->left);
        char *rhs = genExpr(s->right);
        emit("* %s = %s", lhs, rhs);
        return;
    }
    if (!strcmp(s->token,"array_assign")) {
        char *idx = genExpr(s->left->left);
        char *rhs = genExpr(s->right);
        emit("%s [ %s ] = %s", s->left->token, idx, rhs);
        return;
    }
    if (!strcmp(s->token,"null_assign")) { emit("%s = 0", s->left->token); return; }

    /* return ---------------------------------------------------------- */
    if (!strcmp(s->token,"return")) { emit("Return %s", genExpr(s->left)); return; }

    /* block ----------------------------------------------------------- */
    if (!strcmp(s->token,"block")) { genStmt(s->left); return; }

    /* IF -------------------------------------------------------------- */
    if (!strcmp(s->token,"if")) {
    node *c = s->left;                             /* תנאי */
    char *Ltrue = newLabel(), *Lend = newLabel();

    if (isCmpOp(c->token)) {                       /* תנאי מסוג a < 5 וכו׳ */
        char *lhs = genOperand(c->left);
        char *rhs = genOperand(c->right);
        emit("if %s %s %s goto %s", lhs, c->token, rhs, Ltrue);
        emit("goto %s", Lend);
    } else {                                       /* תנאי כללי */
        char *t = genExpr(c);
        emit("if %s == 0 goto %s", t, Lend);
        emit("goto %s", Ltrue);
    }

    emit("%s:", Ltrue);
    genStmt(s->right);
    emit("%s:", Lend); return;
}

if (!strcmp(s->token,"if_else")) {
    node *c = s->left;
    char *Lthen = newLabel(), *Lelse = newLabel(), *Lend = newLabel();

    if (isCmpOp(c->token)) {
        char *lhs = genOperand(c->left);
        char *rhs = genOperand(c->right);
        emit("if %s %s %s goto %s", lhs, c->token, rhs, Lthen);
        emit("goto %s", Lelse);
    } else {
        char *t = genExpr(c);
        emit("if %s != 0 goto %s", t, Lthen);
        emit("goto %s", Lelse);
    }

    emit("%s:", Lthen);  genStmt(s->right->left);  emit("goto %s", Lend);
    emit("%s:", Lelse);  genStmt(s->right->right->left); 
    emit("%s:", Lend);   return;
}


    /* WHILE ----------------------------------------------------------- */
if (!strcmp(s->token,"while")) {
    char *Lcond = newLabel(), *Lbody = newLabel(), *Lend = newLabel();
    emit("%s:", Lcond);

    node *c = s->left;
    if (isCmpOp(c->token)) {
        char *lhs = genOperand(c->left);
        char *rhs = genOperand(c->right);
        emit("if %s %s %s goto %s", lhs, c->token, rhs, Lbody);
        emit("goto %s", Lend);
    } else {
        char *t = genExpr(c);
        emit("if %s != 0 goto %s", t, Lbody);
        emit("goto %s", Lend);
    }

    emit("%s:", Lbody);  genStmt(s->right);   emit("goto %s", Lcond);
    emit("%s:", Lend);   return;
}


    /* DO-WHILE -------------------------------------------------------- */
    if (!strcmp(s->token,"do_while")) {
        char *Ls = newLabel();
        emit("%s:", Ls); genStmt(s->left);
        emit("if %s != 0 goto %s", genExpr(s->right->left), Ls); return;
    }

    /* FOR ------------------------------------------------------------- */
    if (!strcmp(s->token,"for")) {
        node *h = s->left;
        node *initVar   = h->left->left;     /* IDENT */
        node *initExpr  = h->left->right;
        node *condExpr  = h->right->left;
        node *updateExp = h->right->right;

        char *Lc = newLabel(), *Le = newLabel();

        emit("%s = %s", initVar->token, genExpr(initExpr));
        emit("%s:", Lc);
        emit("if %s == 0 goto %s", genExpr(condExpr), Le);
        genStmt(s->right);
        emit("%s = %s", updateExp->left->token, genExpr(updateExp->right));
        emit("goto %s", Lc);
        emit("%s:", Le); return;
    }
}

/* ---------- per-function + global traversal ---------------------------- */
static void genFunction(node *f)
{
    const char *fname = f->left->token;          /* IDENT */
    emit("\n%s:", fname);
    emit("BeginFunc 0");                         /* placeholder */
    Instr *beginLine = codeTail;
    tempBytesInFunc  = 0;          /* start counting for this func */
    int  isFunc = !strcmp(f->token, "FUNCTION");
    node *body  = isFunc ? f->right->right->right   /* FUNCTION */
                         : f->right->right;         /* PROC     */

    /* statements נמצאים תמיד ב-body->right */
    node *stmts = body->right;

    genStmt(stmts);

    /* frame size = locals + total temp bytes we just counted */
    int tempsBytes = tempBytesInFunc;

    /* count local decls in BODY->left (var) */
    int localsBytes = 0;
    node *declChain = body->left;     /* VAR or NULL */
    if (declChain && !strcmp(declChain->token,"VAR")) {
        node *d = declChain->left;    /* first DECL / DECS */
         while (d) {
            node *single = (!strcmp(d->token,"DECS")) ? d->left : d;
            const char *typ = single->left->token;     /* ★ היה כאן localsBytes += sizeofType(typ); */

            /* ★★★ בלוק חדש – סופר כמה מזהים יש בהכרזה ★★★ */
            int nvars = 0;
            node *ids = single->right;                 /* רשימת המזהים */
            while (ids) {
                nvars++;
                ids = (!strcmp(ids->token,"ID_LIST")) ? ids->right : NULL;
            }
            if (nvars == 0) nvars = 1;                 /* VAR_DECL יחיד */

            localsBytes += nvars * sizeofType(typ);    /* ★ השורה החדשה */

            d = (!strcmp(d->token,"DECS")) ? d->right : NULL;
        }
    }
    patchBeginSize(beginLine, tempsBytes + localsBytes);

    emit("EndFunc");
}

static void genGlobal(node *n)
{
    if (!n) return;
    if (!strcmp(n->token,"FUNCS")) { genGlobal(n->left); genGlobal(n->right); }
    else if (!strcmp(n->token,"FUNCTION") || !strcmp(n->token,"PROC")) genFunction(n);
}

void generateCode(node *root)
{
    if (root && !strcmp(root->token,"CODE")) genGlobal(root->left);
}

