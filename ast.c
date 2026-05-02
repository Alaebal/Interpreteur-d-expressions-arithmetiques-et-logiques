#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

int nb_erreurs  = 0;
int nb_warnings = 0;

void erreur(const char *type, const char *msg) {
    nb_erreurs++;
    fprintf(stderr, "[ERREUR] %s : %s\n", type, msg);
}

void warning(const char *type, const char *msg) {
    nb_warnings++;
    fprintf(stderr, "[WARNING] %s : %s\n", type, msg);
}

/* ===========================================================
   TABLE DES SYMBOLES — stocke des Valeur (int ou float)
   =========================================================== */
typedef struct {
    char   nom[64];
    Valeur valeur;
    int    initialise;
} Symbole;

static Symbole table[256];
static int nb_symboles = 0;

Valeur chercher_variable(const char *nom) {
    int i;
    for (i = 0; i < nb_symboles; i++) {
        if (strcmp(table[i].nom, nom) == 0) {
            if (!table[i].initialise) {
                char msg[128];
                sprintf(msg, "variable '%s' utilisee avant initialisation", nom);
                warning("Variable", msg);
            }
            return table[i].valeur;
        }
    }
    char msg[128];
    sprintf(msg, "variable '%s' non declaree (valeur = 0)", nom);
    erreur("Variable", msg);
    return val_int(0);
}

void definir_variable(const char *nom, Valeur valeur) {
    int i;
    for (i = 0; i < nb_symboles; i++) {
        if (strcmp(table[i].nom, nom) == 0) {
            table[i].valeur     = valeur;
            table[i].initialise = 1;
            return;
        }
    }
    strncpy(table[nb_symboles].nom, nom, 63);
    table[nb_symboles].valeur     = valeur;
    table[nb_symboles].initialise = 1;
    nb_symboles++;
}

/* ===========================================================
   UTILITAIRES POUR TYPES MIXTES
   =========================================================== */

/* Convertit une Valeur en double pour les calculs */
static double to_double(Valeur v) {
    return (v.type == TYPE_INT) ? (double)v.v.entier : v.v.reel;
}

/* Si les deux sont int → résultat int, sinon float */
static Valeur arith(OpBin op, Valeur g, Valeur d) {
    int   both_int = (g.type == TYPE_INT && d.type == TYPE_INT);
    double gd = to_double(g);
    double dd = to_double(d);
    double res;

    switch (op) {
        case OP_ADD: res = gd + dd; break;
        case OP_SUB: res = gd - dd; break;
        case OP_MUL: res = gd * dd; break;
        case OP_DIV:
            if (dd == 0.0) {
                erreur("Arithmetique", "division par zero");
                return val_int(0);
            }
            /* division entière si les deux sont int et divisible */
            if (both_int && ((int)gd % (int)dd == 0))
                return val_int((int)gd / (int)dd);
            return val_flt(gd / dd);
        default: res = 0;
    }

    if (both_int) return val_int((int)res);
    return val_flt(res);
}

/* Comparaison → toujours int (0 ou 1) */
static Valeur comparer(OpBin op, Valeur g, Valeur d) {
    double gd = to_double(g);
    double dd = to_double(d);
    int res;
    switch (op) {
        case OP_EQ:  res = (gd == dd); break;
        case OP_NEQ: res = (gd != dd); break;
        case OP_LT:  res = (gd <  dd); break;
        case OP_GT:  res = (gd >  dd); break;
        case OP_LE:  res = (gd <= dd); break;
        case OP_GE:  res = (gd >= dd); break;
        case OP_AND: res = (gd && dd); break;
        case OP_OR:  res = (gd || dd); break;
        default:     res = 0;
    }
    return val_int(res);
}

/* Affiche une Valeur proprement */
static void afficher_valeur(Valeur v) {
    if (v.type == TYPE_INT)
        printf("%d\n", v.v.entier);
    else
        printf("%g\n", v.v.reel);
}

static void afficher_affect(const char *nom, Valeur v) {
    if (v.type == TYPE_INT)
        printf("> %s = %d\n", nom, v.v.entier);
    else
        printf("> %s = %g\n", nom, v.v.reel);
}

/* ===========================================================
   CONSTRUCTEURS
   =========================================================== */
static Node *new_node(NodeType type) {
    Node *n = (Node*)calloc(1, sizeof(Node));
    if (!n) { fprintf(stderr, "[ERREUR FATALE] memoire insuffisante\n"); exit(1); }
    n->type = type;
    return n;
}

Node *new_nombre(int v)       { Node *n = new_node(N_NOMBRE);   n->u.nombre = v;   return n; }
Node *new_reel(double v)      { Node *n = new_node(N_REEL);     n->u.reel   = v;   return n; }
Node *new_variable(char *nom) { Node *n = new_node(N_VARIABLE); n->u.nom = strdup(nom); return n; }
Node *new_unop(Node *op)      { Node *n = new_node(N_UNOP);     n->u.unop.operande = op; return n; }
Node *new_print(Node *expr)   { Node *n = new_node(N_PRINT);    n->u.print.expr = expr; return n; }

Node *new_binop(OpBin op, Node *g, Node *d) {
    Node *n = new_node(N_BINOP);
    n->u.binop.op = op; n->u.binop.gauche = g; n->u.binop.droite = d;
    return n;
}
Node *new_affect(char *var, Node *expr) {
    Node *n = new_node(N_AFFECT);
    n->u.affect.var = strdup(var); n->u.affect.expr = expr;
    return n;
}
Node *new_si(Node *cond, Node *alors, Node *sinon) {
    Node *n = new_node(N_SI);
    n->u.si.cond = cond; n->u.si.alors = alors; n->u.si.sinon = sinon;
    return n;
}
Node *new_tantque(Node *cond, Node *corps) {
    Node *n = new_node(N_TANTQUE);
    n->u.tantque.cond = cond; n->u.tantque.corps = corps;
    return n;
}
Node *new_repeter(Node *corps, Node *cond) {
    Node *n = new_node(N_REPETER);
    n->u.repeter.corps = corps; n->u.repeter.cond = cond;
    return n;
}
Node *new_bloc(Node *instr, Node *suite) {
    Node *n = new_node(N_BLOC);
    n->u.bloc.instr = instr; n->u.bloc.suite = suite;
    return n;
}

/* ===========================================================
   EVALUATEUR
   =========================================================== */
#define MAX_ITER 100000

Valeur evaluer(Node *n) {
    if (!n) return val_int(0);

    switch (n->type) {

        case N_NOMBRE:   return val_int(n->u.nombre);
        case N_REEL:     return val_flt(n->u.reel);
        case N_VARIABLE: return chercher_variable(n->u.nom);

        case N_BINOP: {
            Valeur g = evaluer(n->u.binop.gauche);
            Valeur d = evaluer(n->u.binop.droite);
            switch (n->u.binop.op) {
                case OP_ADD:
                case OP_SUB:
                case OP_MUL:
                case OP_DIV:  return arith(n->u.binop.op, g, d);
                default:      return comparer(n->u.binop.op, g, d);
            }
        }

        case N_UNOP: {
            Valeur v = evaluer(n->u.unop.operande);
            return val_int(!to_double(v));
        }

        case N_AFFECT: {
            Valeur val = evaluer(n->u.affect.expr);
            definir_variable(n->u.affect.var, val);
            afficher_affect(n->u.affect.var, val);
            return val;
        }

        case N_PRINT: {
            Valeur val = evaluer(n->u.print.expr);
            afficher_valeur(val);
            return val;
        }

        case N_SI: {
            Valeur cond = evaluer(n->u.si.cond);
            if (to_double(cond)) evaluer(n->u.si.alors);
            else if (n->u.si.sinon) evaluer(n->u.si.sinon);
            return val_int(0);
        }

        case N_TANTQUE: {
            int iter = 0;
            while (to_double(evaluer(n->u.tantque.cond))) {
                if (++iter > MAX_ITER) {
                    erreur("BoucleInfinie", "boucle tantque depasse 100000 iterations");
                    break;
                }
                evaluer(n->u.tantque.corps);
            }
            return val_int(0);
        }

        case N_REPETER: {
            int iter = 0;
            do {
                if (++iter > MAX_ITER) {
                    erreur("BoucleInfinie", "boucle repeter depasse 100000 iterations");
                    break;
                }
                evaluer(n->u.repeter.corps);
            } while (!to_double(evaluer(n->u.repeter.cond)));
            return val_int(0);
        }

        case N_BLOC:
            evaluer(n->u.bloc.instr);
            evaluer(n->u.bloc.suite);
            return val_int(0);
    }
    return val_int(0);
}

/* ===========================================================
   RAPPORT FINAL
   =========================================================== */
void afficher_rapport(void) {
    fprintf(stderr, "\n===== Rapport d'execution =====\n");
    if (nb_erreurs == 0 && nb_warnings == 0)
        fprintf(stderr, "OK - Aucune erreur detectee.\n");
    else {
        if (nb_erreurs  > 0) fprintf(stderr, "%d erreur(s) detectee(s)\n", nb_erreurs);
        if (nb_warnings > 0) fprintf(stderr, "%d warning(s) detecte(s)\n", nb_warnings);
    }
    fprintf(stderr, "================================\n");
}

/* ===========================================================
   LIBERATION MEMOIRE
   =========================================================== */
void liberer(Node *n) {
    if (!n) return;
    switch (n->type) {
        case N_VARIABLE: free(n->u.nom); break;
        case N_BINOP:    liberer(n->u.binop.gauche); liberer(n->u.binop.droite); break;
        case N_UNOP:     liberer(n->u.unop.operande); break;
        case N_AFFECT:   free(n->u.affect.var); liberer(n->u.affect.expr); break;
        case N_PRINT:    liberer(n->u.print.expr); break;
        case N_SI:       liberer(n->u.si.cond); liberer(n->u.si.alors); liberer(n->u.si.sinon); break;
        case N_TANTQUE:  liberer(n->u.tantque.cond); liberer(n->u.tantque.corps); break;
        case N_REPETER:  liberer(n->u.repeter.corps); liberer(n->u.repeter.cond); break;
        case N_BLOC:     liberer(n->u.bloc.instr); liberer(n->u.bloc.suite); break;
        default: break;
    }
    free(n);
}
