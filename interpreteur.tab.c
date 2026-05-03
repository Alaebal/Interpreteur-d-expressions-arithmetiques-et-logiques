/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "interpreteur.y"

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

int yylex(void);
extern int yylineno;

void yyerror(const char *s) {
    nb_erreurs++;
    fprintf(stderr, "[ERREUR SYNTAXE] ligne %d : %s\n", yylineno, s);
}

/* Line 371 of yacc.c  */
#line 84 "interpreteur.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "interpreteur.tab.h".  */
#ifndef YY_YY_INTERPRETEUR_TAB_H_INCLUDED
# define YY_YY_INTERPRETEUR_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NOMBRE = 258,
     NOMBRE_REEL = 259,
     VARIABLE = 260,
     AFFECTATION = 261,
     SI = 262,
     ALORS = 263,
     SINON = 264,
     FIN = 265,
     AFFICHER = 266,
     FIN_INSTRUCTION = 267,
     OUVRE_PARENTHESE = 268,
     FERME_PARENTHESE = 269,
     OUVRE_CROCHET = 270,
     FERME_CROCHET = 271,
     VIRGULE = 272,
     PLUS = 273,
     MOINS = 274,
     FOIS = 275,
     DIVISE = 276,
     EGAL = 277,
     DIFF = 278,
     INF = 279,
     SUP = 280,
     INFEG = 281,
     SUPEG = 282,
     ET = 283,
     OU = 284,
     NON = 285,
     TANTQUE = 286,
     REPETER = 287,
     JUSQUA = 288,
     FONCTION = 289,
     FAIRE = 290,
     RETOURNER = 291
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 17 "interpreteur.y"

    int    entier;
    double reel;
    char  *chaine;
    Node  *noeud;
    Param *param;
    Arg   *arg;


/* Line 387 of yacc.c  */
#line 173 "interpreteur.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_INTERPRETEUR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 201 "interpreteur.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   357

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNRULES -- Number of states.  */
#define YYNSTATES  112

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    13,    16,    19,    21,
      23,    25,    27,    31,    34,    40,    48,    57,    58,    60,
      62,    66,    71,    72,    74,    76,    80,    84,    89,    95,
     103,   111,   118,   120,   122,   124,   126,   131,   135,   139,
     143,   147,   151,   155,   159,   163,   167,   171,   175,   179,
     182
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      38,     0,    -1,    39,    -1,    -1,    39,    40,    -1,    39,
       1,    12,    -1,    47,    12,    -1,    48,    12,    -1,    49,
      -1,    50,    -1,    51,    -1,    41,    -1,    36,    52,    12,
      -1,    44,    12,    -1,     5,    15,     3,    16,    12,    -1,
       5,    15,    52,    16,     6,    52,    12,    -1,    34,     5,
      13,    42,    14,    35,    39,    10,    -1,    -1,    43,    -1,
       5,    -1,     5,    17,    43,    -1,     5,    13,    45,    14,
      -1,    -1,    46,    -1,    52,    -1,    52,    17,    46,    -1,
       5,     6,    52,    -1,    11,    13,    52,    14,    -1,     7,
      52,     8,    39,    10,    -1,     7,    52,     8,    39,     9,
      39,    10,    -1,    31,    13,    52,    14,     8,    39,    10,
      -1,    32,    39,    33,    13,    52,    14,    -1,     3,    -1,
       4,    -1,     5,    -1,    44,    -1,     5,    15,    52,    16,
      -1,    52,    18,    52,    -1,    52,    19,    52,    -1,    52,
      20,    52,    -1,    52,    21,    52,    -1,    52,    22,    52,
      -1,    52,    23,    52,    -1,    52,    24,    52,    -1,    52,
      25,    52,    -1,    52,    26,    52,    -1,    52,    27,    52,
      -1,    52,    28,    52,    -1,    52,    29,    52,    -1,    30,
      52,    -1,    13,    52,    14,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    63,    63,    71,    72,    76,    83,    84,    85,    86,
      87,    88,    91,    96,    99,   104,   116,   126,   127,   131,
     132,   139,   145,   146,   150,   151,   155,   161,   167,   170,
     176,   183,   190,   191,   192,   193,   194,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NOMBRE", "NOMBRE_REEL", "VARIABLE",
  "AFFECTATION", "SI", "ALORS", "SINON", "FIN", "AFFICHER",
  "FIN_INSTRUCTION", "OUVRE_PARENTHESE", "FERME_PARENTHESE",
  "OUVRE_CROCHET", "FERME_CROCHET", "VIRGULE", "PLUS", "MOINS", "FOIS",
  "DIVISE", "EGAL", "DIFF", "INF", "SUP", "INFEG", "SUPEG", "ET", "OU",
  "NON", "TANTQUE", "REPETER", "JUSQUA", "FONCTION", "FAIRE", "RETOURNER",
  "$accept", "programme", "instructions", "instruction", "def_fonction",
  "liste_params_opt", "liste_params", "appel_fonction", "liste_args_opt",
  "liste_args", "affectation", "affichage", "conditionnelle",
  "boucle_tantque", "boucle_repeter", "expression", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    39,    39,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    41,    42,    42,    43,
      43,    44,    45,    45,    46,    46,    47,    48,    49,    49,
      50,    51,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     2,     2,     1,     1,
       1,     1,     3,     2,     5,     7,     8,     0,     1,     1,
       3,     4,     0,     1,     1,     3,     3,     4,     5,     7,
       7,     6,     1,     1,     1,     1,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,     0,     0,     0,     3,
       0,     0,     4,    11,     0,     0,     0,     8,     9,    10,
       5,     0,    22,     0,    32,    33,    34,     0,     0,    35,
       0,     0,     0,     0,     0,     0,    13,     6,     7,    26,
       0,    23,    24,    32,     0,     0,     0,    49,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    12,    21,     0,     0,     0,
       0,    50,     0,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    27,     0,     0,    19,     0,
      18,    25,    14,     0,    36,     3,    28,     3,     0,     0,
       0,     0,     0,     0,    31,    20,     3,    15,    29,    30,
       0,    16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    12,    13,    89,    90,    29,    40,    41,
      15,    16,    17,    18,    19,    42
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -34
static const yytype_int16 yypact[] =
{
     -34,     4,     5,   -34,    -5,    -4,    30,     6,    10,   -34,
       9,    30,   -34,   -34,    14,    15,    18,   -34,   -34,   -34,
     -34,    30,    30,   129,   -34,   -34,     0,    30,    30,   -34,
     144,    30,    30,    60,    19,   162,   -34,   -34,   -34,   297,
       3,   -34,   285,    22,   258,    30,   196,   320,   -34,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    30,
      30,   212,   228,    31,    40,   -34,   -34,    30,    46,    53,
     272,   -34,    71,     1,     1,   -34,   -34,   330,   330,   157,
     157,   157,   157,   320,   309,   -34,    54,    30,    47,    49,
     -34,   -34,   -34,    30,   -34,   -34,   -34,   -34,   244,    40,
      33,   180,   105,   112,   -34,   -34,   -34,   -34,   -34,   -34,
     119,   -34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -34,   -34,    -8,   -34,   -34,   -34,   -33,    -2,   -34,     2,
     -34,   -34,   -34,   -34,   -34,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -3
static const yytype_int8 yytable[] =
{
      14,    33,    21,    30,     3,    -2,     4,    20,    35,    22,
       5,    23,     6,    22,    34,    45,     7,    66,    39,    31,
      44,    51,    52,    32,    46,    47,    36,    37,    61,    62,
      38,    14,    64,    24,    25,    26,     8,     9,    68,    10,
      72,    11,    70,    27,    87,    88,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    92,    93,
      28,     4,    97,   100,    99,     5,   105,     6,   106,    91,
      14,     7,     4,     0,     0,     0,     5,     0,     6,     0,
      95,    96,     7,     0,    98,     0,     0,   102,     0,   103,
     101,     8,     9,    63,    10,     0,    11,     0,   110,     0,
      14,    14,     8,     9,     0,    10,     4,    11,    14,     0,
       5,     0,     6,     4,     0,   108,     7,     5,     0,     6,
       4,     0,   109,     7,     5,     0,     6,     0,     0,   111,
       7,     0,    43,    25,    26,     0,     8,     9,     0,    10,
       0,    11,    27,     8,     9,     0,    10,     0,    11,     0,
       8,     9,    48,    10,     0,    11,     0,     0,     0,    28,
       0,     0,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    65,    49,    50,    51,    52,     0,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,   107,     0,     0,     0,     0,     0,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      71,     0,     0,     0,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    85,     0,     0,     0,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    86,     0,     0,     0,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,   104,     0,
       0,     0,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    69,     0,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    94,     0,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    67,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    49,    50,
      51,    52,     0,     0,    55,    56,    57,    58
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-34)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
       2,     9,     6,     6,     0,     0,     1,    12,    11,    13,
       5,    15,     7,    13,     5,    15,    11,    14,    21,    13,
      23,    20,    21,    13,    27,    28,    12,    12,    31,    32,
      12,    33,    13,     3,     4,     5,    31,    32,    16,    34,
      48,    36,    45,    13,    13,     5,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    12,     6,
      30,     1,     8,    14,    17,     5,    99,     7,    35,    67,
      72,    11,     1,    -1,    -1,    -1,     5,    -1,     7,    -1,
       9,    10,    11,    -1,    87,    -1,    -1,    95,    -1,    97,
      93,    31,    32,    33,    34,    -1,    36,    -1,   106,    -1,
     102,   103,    31,    32,    -1,    34,     1,    36,   110,    -1,
       5,    -1,     7,     1,    -1,    10,    11,     5,    -1,     7,
       1,    -1,    10,    11,     5,    -1,     7,    -1,    -1,    10,
      11,    -1,     3,     4,     5,    -1,    31,    32,    -1,    34,
      -1,    36,    13,    31,    32,    -1,    34,    -1,    36,    -1,
      31,    32,     8,    34,    -1,    36,    -1,    -1,    -1,    30,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    12,    18,    19,    20,    21,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    12,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      14,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    14,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    14,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    14,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    18,    19,
      20,    21,    -1,    -1,    24,    25,    26,    27
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    38,    39,     0,     1,     5,     7,    11,    31,    32,
      34,    36,    40,    41,    44,    47,    48,    49,    50,    51,
      12,     6,    13,    15,     3,     4,     5,    13,    30,    44,
      52,    13,    13,    39,     5,    52,    12,    12,    12,    52,
      45,    46,    52,     3,    52,    15,    52,    52,     8,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    52,    52,    33,    13,    12,    14,    17,    16,    16,
      52,    14,    39,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    14,    14,    13,     5,    42,
      43,    46,    12,     6,    16,     9,    10,     8,    52,    17,
      14,    52,    39,    39,    14,    43,    35,    12,    10,    10,
      39,    10
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 63 "interpreteur.y"
    {
        evaluer((yyvsp[(1) - (1)].noeud));
        liberer((yyvsp[(1) - (1)].noeud));
        afficher_rapport();
    }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 71 "interpreteur.y"
    { (yyval.noeud) = NULL; }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 72 "interpreteur.y"
    {
        if ((yyvsp[(1) - (2)].noeud) == NULL) (yyval.noeud) = (yyvsp[(2) - (2)].noeud);
        else            (yyval.noeud) = new_bloc((yyvsp[(1) - (2)].noeud), (yyvsp[(2) - (2)].noeud));
    }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 76 "interpreteur.y"
    {
        fprintf(stderr, "[RECUPERATION] instruction ignoree ligne %d\n", yylineno);
        (yyval.noeud) = (yyvsp[(1) - (3)].noeud);
    }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 83 "interpreteur.y"
    { (yyval.noeud) = (yyvsp[(1) - (2)].noeud); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 84 "interpreteur.y"
    { (yyval.noeud) = (yyvsp[(1) - (2)].noeud); }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 85 "interpreteur.y"
    { (yyval.noeud) = (yyvsp[(1) - (1)].noeud); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 86 "interpreteur.y"
    { (yyval.noeud) = (yyvsp[(1) - (1)].noeud); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 87 "interpreteur.y"
    { (yyval.noeud) = (yyvsp[(1) - (1)].noeud); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 88 "interpreteur.y"
    { (yyval.noeud) = (yyvsp[(1) - (1)].noeud); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 91 "interpreteur.y"
    {
        (yyval.noeud) = new_retourner((yyvsp[(2) - (3)].noeud));
    }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 96 "interpreteur.y"
    { (yyval.noeud) = (yyvsp[(1) - (2)].noeud); }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 99 "interpreteur.y"
    {
        (yyval.noeud) = new_decl_tab((yyvsp[(1) - (5)].chaine), (yyvsp[(3) - (5)].entier)); free((yyvsp[(1) - (5)].chaine));
    }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 104 "interpreteur.y"
    {
        (yyval.noeud) = new_affect_tab((yyvsp[(1) - (7)].chaine), (yyvsp[(3) - (7)].noeud), (yyvsp[(6) - (7)].noeud)); free((yyvsp[(1) - (7)].chaine));
    }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 118 "interpreteur.y"
    {
        (yyval.noeud) = new_def_fonc((yyvsp[(2) - (8)].chaine), (yyvsp[(4) - (8)].param), (yyvsp[(7) - (8)].noeud));
        free((yyvsp[(2) - (8)].chaine));
    }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 126 "interpreteur.y"
    { (yyval.param) = NULL; }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 127 "interpreteur.y"
    { (yyval.param) = (yyvsp[(1) - (1)].param); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 131 "interpreteur.y"
    { (yyval.param) = new_param((yyvsp[(1) - (1)].chaine), NULL); free((yyvsp[(1) - (1)].chaine)); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 132 "interpreteur.y"
    { (yyval.param) = new_param((yyvsp[(1) - (3)].chaine), (yyvsp[(3) - (3)].param));   free((yyvsp[(1) - (3)].chaine)); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 139 "interpreteur.y"
    {
        (yyval.noeud) = new_appel_fonc((yyvsp[(1) - (4)].chaine), (yyvsp[(3) - (4)].arg)); free((yyvsp[(1) - (4)].chaine));
    }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 145 "interpreteur.y"
    { (yyval.arg) = NULL; }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 146 "interpreteur.y"
    { (yyval.arg) = (yyvsp[(1) - (1)].arg); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 150 "interpreteur.y"
    { (yyval.arg) = new_arg((yyvsp[(1) - (1)].noeud), NULL); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 151 "interpreteur.y"
    { (yyval.arg) = new_arg((yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].arg));   }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 155 "interpreteur.y"
    {
        (yyval.noeud) = new_affect((yyvsp[(1) - (3)].chaine), (yyvsp[(3) - (3)].noeud)); free((yyvsp[(1) - (3)].chaine));
    }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 161 "interpreteur.y"
    {
        (yyval.noeud) = new_print((yyvsp[(3) - (4)].noeud));
    }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 167 "interpreteur.y"
    {
          (yyval.noeud) = new_si((yyvsp[(2) - (5)].noeud), (yyvsp[(4) - (5)].noeud), NULL);
      }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 170 "interpreteur.y"
    {
          (yyval.noeud) = new_si((yyvsp[(2) - (7)].noeud), (yyvsp[(4) - (7)].noeud), (yyvsp[(6) - (7)].noeud));
      }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 177 "interpreteur.y"
    {
        (yyval.noeud) = new_tantque((yyvsp[(3) - (7)].noeud), (yyvsp[(6) - (7)].noeud));
    }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 184 "interpreteur.y"
    {
        (yyval.noeud) = new_repeter((yyvsp[(2) - (6)].noeud), (yyvsp[(5) - (6)].noeud));
    }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 190 "interpreteur.y"
    { (yyval.noeud) = new_nombre((yyvsp[(1) - (1)].entier)); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 191 "interpreteur.y"
    { (yyval.noeud) = new_reel((yyvsp[(1) - (1)].reel));   }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 192 "interpreteur.y"
    { (yyval.noeud) = new_variable((yyvsp[(1) - (1)].chaine)); free((yyvsp[(1) - (1)].chaine)); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 193 "interpreteur.y"
    { (yyval.noeud) = (yyvsp[(1) - (1)].noeud); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 194 "interpreteur.y"
    {
        (yyval.noeud) = new_acces_tab((yyvsp[(1) - (4)].chaine), (yyvsp[(3) - (4)].noeud)); free((yyvsp[(1) - (4)].chaine));
    }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 197 "interpreteur.y"
    { (yyval.noeud) = new_binop(OP_ADD, (yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 198 "interpreteur.y"
    { (yyval.noeud) = new_binop(OP_SUB, (yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 199 "interpreteur.y"
    { (yyval.noeud) = new_binop(OP_MUL, (yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 200 "interpreteur.y"
    { (yyval.noeud) = new_binop(OP_DIV, (yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 201 "interpreteur.y"
    { (yyval.noeud) = new_binop(OP_EQ,  (yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 202 "interpreteur.y"
    { (yyval.noeud) = new_binop(OP_NEQ, (yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 203 "interpreteur.y"
    { (yyval.noeud) = new_binop(OP_LT,  (yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 204 "interpreteur.y"
    { (yyval.noeud) = new_binop(OP_GT,  (yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 205 "interpreteur.y"
    { (yyval.noeud) = new_binop(OP_LE,  (yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 206 "interpreteur.y"
    { (yyval.noeud) = new_binop(OP_GE,  (yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 207 "interpreteur.y"
    { (yyval.noeud) = new_binop(OP_AND, (yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 208 "interpreteur.y"
    { (yyval.noeud) = new_binop(OP_OR,  (yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 209 "interpreteur.y"
    { (yyval.noeud) = new_unop((yyvsp[(2) - (2)].noeud)); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 210 "interpreteur.y"
    { (yyval.noeud) = (yyvsp[(2) - (3)].noeud); }
    break;


/* Line 1792 of yacc.c  */
#line 1863 "interpreteur.tab.c"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 213 "interpreteur.y"

