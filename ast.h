#ifndef AST_H
#define AST_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ===========================================================
   TYPES DE VALEURS
   =========================================================== */
typedef enum { TYPE_INT, TYPE_FLOAT } ValType;

typedef struct {
    ValType type;
    union { int entier; double reel; } v;
} Valeur;

static inline Valeur val_int(int i)    { Valeur v; v.type=TYPE_INT;   v.v.entier=i; return v; }
static inline Valeur val_flt(double d) { Valeur v; v.type=TYPE_FLOAT; v.v.reel=d;   return v; }

/* ===========================================================
   LISTE DE PARAMETRES / ARGUMENTS
   =========================================================== */
typedef struct Param {
    char        *nom;
    struct Param *suivant;
} Param;

typedef struct Arg {
    struct Node *expr;
    struct Arg  *suivant;
} Arg;

Param *new_param(char *nom, Param *suivant);
Arg   *new_arg(struct Node *expr, Arg *suivant);

/* ===========================================================
   TYPES DE NOEUDS AST
   =========================================================== */
typedef enum {
    N_NOMBRE, N_REEL, N_VARIABLE,
    N_BINOP, N_UNOP,
    N_AFFECT, N_PRINT,
    N_SI, N_TANTQUE, N_REPETER, N_BLOC,
    N_DECL_TAB, N_AFFECT_TAB, N_ACCES_TAB,
    N_DEF_FONC,   /* definition  : fonction f(p1,p2) faire ... fin */
    N_APPEL_FONC, /* appel       : f(a1, a2)                       */
    N_RETOURNER   /* retourner expr;                               */
} NodeType;

typedef enum {
    OP_ADD, OP_SUB, OP_MUL, OP_DIV,
    OP_EQ, OP_NEQ, OP_LT, OP_GT, OP_LE, OP_GE,
    OP_AND, OP_OR
} OpBin;

typedef struct Node {
    NodeType type;
    union {
        int    nombre;
        double reel;
        char  *nom;
        struct { OpBin op; struct Node *gauche; struct Node *droite; } binop;
        struct { struct Node *operande; }                              unop;
        struct { char *var;  struct Node *expr; }                     affect;
        struct { struct Node *expr; }                                  print;
        struct { struct Node *cond; struct Node *alors; struct Node *sinon; } si;
        struct { struct Node *cond; struct Node *corps; }             tantque;
        struct { struct Node *corps; struct Node *cond; }             repeter;
        struct { struct Node *instr; struct Node *suite; }            bloc;
        struct { char *nom; int taille; }                             decl_tab;
        struct { char *nom; struct Node *index; struct Node *expr; }  affect_tab;
        struct { char *nom; struct Node *index; }                     acces_tab;
        struct { char *nom; Param *params; struct Node *corps; }      def_fonc;
        struct { char *nom; Arg   *args; }                            appel_fonc;
        struct { struct Node *expr; }                                  retourner;
    } u;
} Node;

/* Constructeurs scalaires */
Node *new_nombre(int v);
Node *new_reel(double v);
Node *new_variable(char *nom);
Node *new_binop(OpBin op, Node *g, Node *d);
Node *new_unop(Node *operande);
Node *new_affect(char *var, Node *expr);
Node *new_print(Node *expr);
Node *new_si(Node *cond, Node *alors, Node *sinon);
Node *new_tantque(Node *cond, Node *corps);
Node *new_repeter(Node *corps, Node *cond);
Node *new_bloc(Node *instr, Node *suite);

/* Constructeurs tableaux */
Node *new_decl_tab(char *nom, int taille);
Node *new_affect_tab(char *nom, Node *index, Node *expr);
Node *new_acces_tab(char *nom, Node *index);

/* Constructeurs fonctions */
Node *new_def_fonc(char *nom, Param *params, Node *corps);
Node *new_appel_fonc(char *nom, Arg *args);
Node *new_retourner(Node *expr);

/* Evaluateur */
Valeur evaluer(Node *n);
void   liberer(Node *n);
void   afficher_rapport(void);

extern int nb_erreurs;
extern int nb_warnings;

/* Exception retour de fonction */
extern int    retour_actif;
extern Valeur retour_valeur;

#endif
