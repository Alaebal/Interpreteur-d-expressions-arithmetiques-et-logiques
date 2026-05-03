%{
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
%}

%union {
    int    entier;
    double reel;
    char  *chaine;
    Node  *noeud;
    Param *param;
    Arg   *arg;
}

%token <entier> NOMBRE
%token <reel>   NOMBRE_REEL
%token <chaine> VARIABLE
%token AFFECTATION
%token SI ALORS SINON FIN
%token AFFICHER
%token FIN_INSTRUCTION
%token OUVRE_PARENTHESE FERME_PARENTHESE
%token OUVRE_CROCHET FERME_CROCHET
%token VIRGULE
%token PLUS MOINS FOIS DIVISE
%token EGAL DIFF INF SUP INFEG SUPEG
%token ET OU NON
%token TANTQUE REPETER JUSQUA
%token FONCTION FAIRE RETOURNER

%type <noeud>  instructions instruction
%type <noeud>  affectation affichage conditionnelle
%type <noeud>  boucle_tantque boucle_repeter
%type <noeud>  def_fonction
%type <noeud>  expression appel_fonction
%type <param>  liste_params liste_params_opt
%type <arg>    liste_args liste_args_opt

%left OU
%left ET
%right NON
%left EGAL DIFF
%left INF SUP INFEG SUPEG
%left PLUS MOINS
%left FOIS DIVISE

%start programme

%%

programme:
    instructions {
        evaluer($1);
        liberer($1);
        afficher_rapport();
    }
    ;

instructions:
      /* vide */                    { $$ = NULL; }
    | instructions instruction      {
        if ($1 == NULL) $$ = $2;
        else            $$ = new_bloc($1, $2);
    }
    | instructions error FIN_INSTRUCTION {
        fprintf(stderr, "[RECUPERATION] instruction ignoree ligne %d\n", yylineno);
        $$ = $1;
    }
    ;

instruction:
      affectation   FIN_INSTRUCTION  { $$ = $1; }
    | affichage     FIN_INSTRUCTION  { $$ = $1; }
    | conditionnelle                 { $$ = $1; }
    | boucle_tantque                 { $$ = $1; }
    | boucle_repeter                 { $$ = $1; }
    | def_fonction                   { $$ = $1; }

    /* retourner expr; */
    | RETOURNER expression FIN_INSTRUCTION {
        $$ = new_retourner($2);
    }

    /* appel de fonction comme instruction : f(a, b); */
    | appel_fonction FIN_INSTRUCTION { $$ = $1; }

    /* Declaration tableau : tab[5]; */
    | VARIABLE OUVRE_CROCHET NOMBRE FERME_CROCHET FIN_INSTRUCTION {
        $$ = new_decl_tab($1, $3); free($1);
    }

    /* Affectation tableau : tab[i] = expr; */
    | VARIABLE OUVRE_CROCHET expression FERME_CROCHET AFFECTATION expression FIN_INSTRUCTION {
        $$ = new_affect_tab($1, $3, $6); free($1);
    }
    ;

/* ===========================================================
   DEFINITION DE FONCTION
   fonction nom(p1, p2, ...) faire
       instructions
   fin
   =========================================================== */
def_fonction:
    FONCTION VARIABLE OUVRE_PARENTHESE liste_params_opt FERME_PARENTHESE FAIRE
    instructions
    FIN {
        $$ = new_def_fonc($2, $4, $7);
        free($2);
    }
    ;

/* Liste de paramètres formels */
liste_params_opt:
    /* vide */    { $$ = NULL; }
    | liste_params { $$ = $1; }
    ;

liste_params:
      VARIABLE                       { $$ = new_param($1, NULL); free($1); }
    | VARIABLE VIRGULE liste_params  { $$ = new_param($1, $3);   free($1); }
    ;

/* ===========================================================
   APPEL DE FONCTION (dans une expression ou instruction)
   =========================================================== */
appel_fonction:
    VARIABLE OUVRE_PARENTHESE liste_args_opt FERME_PARENTHESE {
        $$ = new_appel_fonc($1, $3); free($1);
    }
    ;

liste_args_opt:
    /* vide */  { $$ = NULL; }
    | liste_args { $$ = $1; }
    ;

liste_args:
      expression                     { $$ = new_arg($1, NULL); }
    | expression VIRGULE liste_args  { $$ = new_arg($1, $3);   }
    ;

affectation:
    VARIABLE AFFECTATION expression {
        $$ = new_affect($1, $3); free($1);
    }
    ;

affichage:
    AFFICHER OUVRE_PARENTHESE expression FERME_PARENTHESE {
        $$ = new_print($3);
    }
    ;

conditionnelle:
      SI expression ALORS instructions FIN {
          $$ = new_si($2, $4, NULL);
      }
    | SI expression ALORS instructions SINON instructions FIN {
          $$ = new_si($2, $4, $6);
      }
    ;

boucle_tantque:
    TANTQUE OUVRE_PARENTHESE expression FERME_PARENTHESE ALORS
    instructions FIN {
        $$ = new_tantque($3, $6);
    }
    ;

boucle_repeter:
    REPETER instructions
    JUSQUA OUVRE_PARENTHESE expression FERME_PARENTHESE {
        $$ = new_repeter($2, $5);
    }
    ;

expression:
      NOMBRE        { $$ = new_nombre($1); }
    | NOMBRE_REEL   { $$ = new_reel($1);   }
    | VARIABLE      { $$ = new_variable($1); free($1); }
    | appel_fonction { $$ = $1; }
    | VARIABLE OUVRE_CROCHET expression FERME_CROCHET {
        $$ = new_acces_tab($1, $3); free($1);
    }
    | expression PLUS    expression  { $$ = new_binop(OP_ADD, $1, $3); }
    | expression MOINS   expression  { $$ = new_binop(OP_SUB, $1, $3); }
    | expression FOIS    expression  { $$ = new_binop(OP_MUL, $1, $3); }
    | expression DIVISE  expression  { $$ = new_binop(OP_DIV, $1, $3); }
    | expression EGAL    expression  { $$ = new_binop(OP_EQ,  $1, $3); }
    | expression DIFF    expression  { $$ = new_binop(OP_NEQ, $1, $3); }
    | expression INF     expression  { $$ = new_binop(OP_LT,  $1, $3); }
    | expression SUP     expression  { $$ = new_binop(OP_GT,  $1, $3); }
    | expression INFEG   expression  { $$ = new_binop(OP_LE,  $1, $3); }
    | expression SUPEG   expression  { $$ = new_binop(OP_GE,  $1, $3); }
    | expression ET      expression  { $$ = new_binop(OP_AND, $1, $3); }
    | expression OU      expression  { $$ = new_binop(OP_OR,  $1, $3); }
    | NON expression                 { $$ = new_unop($2); }
    | OUVRE_PARENTHESE expression FERME_PARENTHESE { $$ = $2; }
    ;

%%
