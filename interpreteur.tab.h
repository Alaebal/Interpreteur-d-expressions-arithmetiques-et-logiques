/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
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
/* Line 2058 of yacc.c  */
#line 17 "interpreteur.y"

    int    entier;
    double reel;
    char  *chaine;
    Node  *noeud;
    Param *param;
    Arg   *arg;


/* Line 2058 of yacc.c  */
#line 103 "interpreteur.tab.h"
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
