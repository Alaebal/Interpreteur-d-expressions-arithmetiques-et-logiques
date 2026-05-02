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
}

%token <entier> NOMBRE
%token <reel>   NOMBRE_REEL
%token <chaine> VARIABLE
%token AFFECTATION
%token SI ALORS SINON FIN
%token AFFICHER
%token FIN_INSTRUCTION
%token OUVRE_PARENTHESE FERME_PARENTHESE
%token PLUS MOINS FOIS DIVISE
%token EGAL DIFF INF SUP INFEG SUPEG
%token ET OU NON
%token TANTQUE REPETER JUSQUA

%type <noeud> instructions
%type <noeud> instruction
%type <noeud> affectation
%type <noeud> affichage
%type <noeud> conditionnelle
%type <noeud> boucle_tantque
%type <noeud> boucle_repeter
%type <noeud> expression

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
    ;

affectation:
    VARIABLE AFFECTATION expression {
        $$ = new_affect($1, $3);
        free($1);
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
    instructions
    FIN {
        $$ = new_tantque($3, $6);
    }
    ;

boucle_repeter:
    REPETER
    instructions
    JUSQUA OUVRE_PARENTHESE expression FERME_PARENTHESE {
        $$ = new_repeter($2, $5);
    }
    ;

expression:
      NOMBRE        { $$ = new_nombre($1); }
    | NOMBRE_REEL   { $$ = new_reel($1);   }
    | VARIABLE      { $$ = new_variable($1); free($1); }
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
