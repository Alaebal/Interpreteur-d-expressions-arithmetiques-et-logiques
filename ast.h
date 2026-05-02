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
    union {
        int    entier;
        double reel;
    } v;
} Valeur;

/* Constructeurs de valeurs */
static inline Valeur val_int(int i)   { Valeur v; v.type = TYPE_INT;   v.v.entier = i; return v; }
static inline Valeur val_flt(double d){ Valeur v; v.type = TYPE_FLOAT; v.v.reel   = d; return v; }

/* ===========================================================
   TYPES DE NOEUDS AST
   =========================================================== */
typedef enum {
    N_NOMBRE,
    N_REEL,
    N_VARIABLE,
    N_BINOP,
    N_UNOP,
    N_AFFECT,
    N_PRINT,
    N_SI,
    N_TANTQUE,
    N_REPETER,
    N_BLOC
} NodeType;

typedef enum {
    OP_ADD, OP_SUB, OP_MUL, OP_DIV,
    OP_EQ,  OP_NEQ,
    OP_LT,  OP_GT, OP_LE, OP_GE,
    OP_AND, OP_OR
} OpBin;

typedef struct Node {
    NodeType type;
    union {
        int    nombre;
        double reel;
        char  *nom;
        struct { OpBin op; struct Node *gauche; struct Node *droite; } binop;
        struct { struct Node *operande; } unop;
        struct { char *var;  struct Node *expr;  } affect;
        struct { struct Node *expr; } print;
        struct { struct Node *cond; struct Node *alors; struct Node *sinon; } si;
        struct { struct Node *cond; struct Node *corps; } tantque;
        struct { struct Node *corps; struct Node *cond; } repeter;
        struct { struct Node *instr; struct Node *suite; } bloc;
    } u;
} Node;

/* Constructeurs */
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

/* Evaluateur — retourne une Valeur (int ou float) */
Valeur evaluer(Node *n);
void   liberer(Node *n);
void   afficher_rapport(void);

extern int nb_erreurs;
extern int nb_warnings;

#endif
