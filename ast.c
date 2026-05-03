#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

/* ===========================================================
   ERREURS & WARNINGS
   =========================================================== */
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
   MECANISME DE RETOUR DE FONCTION
   retour_actif : mis a 1 quand on rencontre "retourner"
   retour_valeur : la valeur retournee
   =========================================================== */
int    retour_actif = 0;
Valeur retour_valeur;

/* ===========================================================
   TABLE DES SYMBOLES SCALAIRES
   =========================================================== */
#define MAX_SYMBOLES 512
#define MAX_PROFONDEUR 64

typedef struct {
    char   nom[64];
    Valeur valeur;
    int    initialise;
    int    profondeur;  /* niveau d'imbrication (0=global, 1=fonction...) */
} Symbole;

static Symbole table[MAX_SYMBOLES];
static int nb_symboles  = 0;
static int profondeur   = 0;  /* profondeur courante */

/* Entre dans un nouveau contexte (appel de fonction) */
void entrer_contexte(void) { profondeur++; }

/* Sort du contexte courant : supprime les variables locales */
void sortir_contexte(void) {
    int i;
    for (i = nb_symboles - 1; i >= 0; i--) {
        if (table[i].profondeur == profondeur) {
            /* Decale le tableau vers la gauche */
            int j;
            for (j = i; j < nb_symboles - 1; j++)
                table[j] = table[j+1];
            nb_symboles--;
        }
    }
    profondeur--;
}

Valeur chercher_variable(const char *nom) {
    int i;
    /* Cherche d'abord dans le contexte local, puis global */
    for (i = nb_symboles - 1; i >= 0; i--) {
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
    /* Mise a jour si existe dans le contexte courant */
    for (i = nb_symboles - 1; i >= 0; i--) {
        if (strcmp(table[i].nom, nom) == 0 && table[i].profondeur == profondeur) {
            table[i].valeur     = valeur;
            table[i].initialise = 1;
            return;
        }
    }
    if (nb_symboles >= MAX_SYMBOLES) {
        erreur("Memoire", "table des symboles pleine");
        return;
    }
    strncpy(table[nb_symboles].nom, nom, 63);
    table[nb_symboles].valeur     = valeur;
    table[nb_symboles].initialise = 1;
    table[nb_symboles].profondeur = profondeur;
    nb_symboles++;
}

/* ===========================================================
   TABLE DES TABLEAUX
   =========================================================== */
#define MAX_TABLEAUX 64
#define MAX_TAILLE   256

typedef struct {
    char   nom[64];
    Valeur elements[MAX_TAILLE];
    int    taille;
} Tableau;

static Tableau tableaux[MAX_TABLEAUX];
static int nb_tableaux = 0;

static int trouver_tableau(const char *nom) {
    int i;
    for (i = 0; i < nb_tableaux; i++)
        if (strcmp(tableaux[i].nom, nom) == 0) return i;
    return -1;
}

void declarer_tableau(const char *nom, int taille) {
    int i;
    if (trouver_tableau(nom) >= 0) {
        char msg[128]; sprintf(msg, "tableau '%s' deja declare", nom);
        warning("Tableau", msg); return;
    }
    if (nb_tableaux >= MAX_TABLEAUX) { erreur("Tableau", "trop de tableaux"); return; }
    if (taille <= 0 || taille > MAX_TAILLE) {
        char msg[128]; sprintf(msg, "taille invalide pour '%s'", nom);
        erreur("Tableau", msg); return;
    }
    strncpy(tableaux[nb_tableaux].nom, nom, 63);
    tableaux[nb_tableaux].taille = taille;
    for (i = 0; i < taille; i++) tableaux[nb_tableaux].elements[i] = val_int(0);
    printf("> tableau '%s' declare avec %d elements\n", nom, taille);
    nb_tableaux++;
}

void affecter_tableau(const char *nom, int idx, Valeur val) {
    int t = trouver_tableau(nom);
    if (t < 0) { char msg[128]; sprintf(msg, "tableau '%s' non declare", nom); erreur("Tableau", msg); return; }
    if (idx < 0 || idx >= tableaux[t].taille) {
        char msg[128]; sprintf(msg, "indice %d hors limites pour '%s'", idx, nom);
        erreur("Tableau", msg); return;
    }
    tableaux[t].elements[idx] = val;
    if (val.type==TYPE_INT) printf("> %s[%d] = %d\n", nom, idx, val.v.entier);
    else                    printf("> %s[%d] = %g\n", nom, idx, val.v.reel);
}

Valeur lire_tableau(const char *nom, int idx) {
    int t = trouver_tableau(nom);
    if (t < 0) { char msg[128]; sprintf(msg, "tableau '%s' non declare", nom); erreur("Tableau", msg); return val_int(0); }
    if (idx < 0 || idx >= tableaux[t].taille) {
        char msg[128]; sprintf(msg, "indice %d hors limites pour '%s'", idx, nom);
        erreur("Tableau", msg); return val_int(0);
    }
    return tableaux[t].elements[idx];
}

/* ===========================================================
   TABLE DES FONCTIONS
   =========================================================== */
#define MAX_FONCTIONS 64

typedef struct {
    char   nom[64];
    Param *params;
    Node  *corps;
} FonctionDef;

static FonctionDef fonctions[MAX_FONCTIONS];
static int nb_fonctions = 0;

void enregistrer_fonction(const char *nom, Param *params, Node *corps) {
    int i;
    for (i = 0; i < nb_fonctions; i++) {
        if (strcmp(fonctions[i].nom, nom) == 0) {
            fonctions[i].params = params;
            fonctions[i].corps  = corps;
            printf("> fonction '%s' redéfinie\n", nom);
            return;
        }
    }
    if (nb_fonctions >= MAX_FONCTIONS) { erreur("Fonction", "trop de fonctions definies"); return; }
    strncpy(fonctions[nb_fonctions].nom, nom, 63);
    fonctions[nb_fonctions].params = params;
    fonctions[nb_fonctions].corps  = corps;
    printf("> fonction '%s' definie\n", nom);
    nb_fonctions++;
}

FonctionDef *trouver_fonction(const char *nom) {
    int i;
    for (i = 0; i < nb_fonctions; i++)
        if (strcmp(fonctions[i].nom, nom) == 0) return &fonctions[i];
    return NULL;
}

/* ===========================================================
   CONSTRUCTEURS LISTES
   =========================================================== */
Param *new_param(char *nom, Param *suivant) {
    Param *p = (Param*)malloc(sizeof(Param));
    p->nom     = strdup(nom);
    p->suivant = suivant;
    return p;
}

Arg *new_arg(Node *expr, Arg *suivant) {
    Arg *a = (Arg*)malloc(sizeof(Arg));
    a->expr    = expr;
    a->suivant = suivant;
    return a;
}

/* ===========================================================
   UTILITAIRES TYPES MIXTES
   =========================================================== */
static double to_double(Valeur v) {
    return (v.type == TYPE_INT) ? (double)v.v.entier : v.v.reel;
}

static Valeur arith(OpBin op, Valeur g, Valeur d) {
    int    bi = (g.type==TYPE_INT && d.type==TYPE_INT);
    double gd = to_double(g), dd = to_double(d), res;
    switch (op) {
        case OP_ADD: res = gd+dd; break;
        case OP_SUB: res = gd-dd; break;
        case OP_MUL: res = gd*dd; break;
        case OP_DIV:
            if (dd==0.0) { erreur("Arithmetique","division par zero"); return val_int(0); }
            if (bi && (int)gd%(int)dd==0) return val_int((int)gd/(int)dd);
            return val_flt(gd/dd);
        default: res=0;
    }
    return bi ? val_int((int)res) : val_flt(res);
}

static Valeur comparer(OpBin op, Valeur g, Valeur d) {
    double gd=to_double(g), dd=to_double(d); int res;
    switch(op) {
        case OP_EQ:  res=(gd==dd); break; case OP_NEQ: res=(gd!=dd); break;
        case OP_LT:  res=(gd<dd);  break; case OP_GT:  res=(gd>dd);  break;
        case OP_LE:  res=(gd<=dd); break; case OP_GE:  res=(gd>=dd); break;
        case OP_AND: res=(gd&&dd); break; case OP_OR:  res=(gd||dd); break;
        default: res=0;
    }
    return val_int(res);
}

/* ===========================================================
   CONSTRUCTEURS NOEUDS
   =========================================================== */
static Node *new_node(NodeType type) {
    Node *n = (Node*)calloc(1, sizeof(Node));
    if (!n) { fprintf(stderr,"[ERREUR FATALE] memoire\n"); exit(1); }
    n->type = type; return n;
}

Node *new_nombre(int v)       { Node *n=new_node(N_NOMBRE);   n->u.nombre=v; return n; }
Node *new_reel(double v)      { Node *n=new_node(N_REEL);     n->u.reel=v;   return n; }
Node *new_variable(char *nom) { Node *n=new_node(N_VARIABLE); n->u.nom=strdup(nom); return n; }
Node *new_unop(Node *op)      { Node *n=new_node(N_UNOP);     n->u.unop.operande=op; return n; }
Node *new_print(Node *expr)   { Node *n=new_node(N_PRINT);    n->u.print.expr=expr; return n; }
Node *new_retourner(Node *e)  { Node *n=new_node(N_RETOURNER);n->u.retourner.expr=e; return n; }

Node *new_binop(OpBin op, Node *g, Node *d) {
    Node *n=new_node(N_BINOP); n->u.binop.op=op; n->u.binop.gauche=g; n->u.binop.droite=d; return n;
}
Node *new_affect(char *var, Node *expr) {
    Node *n=new_node(N_AFFECT); n->u.affect.var=strdup(var); n->u.affect.expr=expr; return n;
}
Node *new_si(Node *cond, Node *alors, Node *sinon) {
    Node *n=new_node(N_SI); n->u.si.cond=cond; n->u.si.alors=alors; n->u.si.sinon=sinon; return n;
}
Node *new_tantque(Node *cond, Node *corps) {
    Node *n=new_node(N_TANTQUE); n->u.tantque.cond=cond; n->u.tantque.corps=corps; return n;
}
Node *new_repeter(Node *corps, Node *cond) {
    Node *n=new_node(N_REPETER); n->u.repeter.corps=corps; n->u.repeter.cond=cond; return n;
}
Node *new_bloc(Node *instr, Node *suite) {
    Node *n=new_node(N_BLOC); n->u.bloc.instr=instr; n->u.bloc.suite=suite; return n;
}
Node *new_decl_tab(char *nom, int taille) {
    Node *n=new_node(N_DECL_TAB); n->u.decl_tab.nom=strdup(nom); n->u.decl_tab.taille=taille; return n;
}
Node *new_affect_tab(char *nom, Node *index, Node *expr) {
    Node *n=new_node(N_AFFECT_TAB); n->u.affect_tab.nom=strdup(nom);
    n->u.affect_tab.index=index; n->u.affect_tab.expr=expr; return n;
}
Node *new_acces_tab(char *nom, Node *index) {
    Node *n=new_node(N_ACCES_TAB); n->u.acces_tab.nom=strdup(nom); n->u.acces_tab.index=index; return n;
}
Node *new_def_fonc(char *nom, Param *params, Node *corps) {
    Node *n=new_node(N_DEF_FONC); n->u.def_fonc.nom=strdup(nom);
    n->u.def_fonc.params=params; n->u.def_fonc.corps=corps; return n;
}
Node *new_appel_fonc(char *nom, Arg *args) {
    Node *n=new_node(N_APPEL_FONC); n->u.appel_fonc.nom=strdup(nom); n->u.appel_fonc.args=args; return n;
}

/* ===========================================================
   EVALUATEUR
   =========================================================== */
#define MAX_ITER 100000

Valeur evaluer(Node *n) {
    if (!n) return val_int(0);
    if (retour_actif) return val_int(0); /* propagation du retour */

    switch (n->type) {

        case N_NOMBRE:   return val_int(n->u.nombre);
        case N_REEL:     return val_flt(n->u.reel);
        case N_VARIABLE: return chercher_variable(n->u.nom);

        case N_BINOP: {
            Valeur g=evaluer(n->u.binop.gauche), d=evaluer(n->u.binop.droite);
            switch(n->u.binop.op) {
                case OP_ADD: case OP_SUB: case OP_MUL: case OP_DIV: return arith(n->u.binop.op,g,d);
                default: return comparer(n->u.binop.op,g,d);
            }
        }

        case N_UNOP: return val_int(!to_double(evaluer(n->u.unop.operande)));

        case N_AFFECT: {
            Valeur val=evaluer(n->u.affect.expr);
            definir_variable(n->u.affect.var, val);
            if(val.type==TYPE_INT) printf("> %s = %d\n", n->u.affect.var, val.v.entier);
            else                   printf("> %s = %g\n", n->u.affect.var, val.v.reel);
            return val;
        }

        case N_PRINT: {
            Valeur val=evaluer(n->u.print.expr);
            if(val.type==TYPE_INT) printf("%d\n", val.v.entier);
            else                   printf("%g\n", val.v.reel);
            return val;
        }

        case N_SI:
            if(to_double(evaluer(n->u.si.cond))) evaluer(n->u.si.alors);
            else if(n->u.si.sinon)               evaluer(n->u.si.sinon);
            return val_int(0);

        case N_TANTQUE: {
            int iter=0;
            while(to_double(evaluer(n->u.tantque.cond))) {
                if(++iter>MAX_ITER){erreur("BoucleInfinie","tantque: trop d'iterations");break;}
                evaluer(n->u.tantque.corps);
                if(retour_actif) break;
            }
            return val_int(0);
        }

        case N_REPETER: {
            int iter=0;
            do {
                if(++iter>MAX_ITER){erreur("BoucleInfinie","repeter: trop d'iterations");break;}
                evaluer(n->u.repeter.corps);
            } while(!retour_actif && !to_double(evaluer(n->u.repeter.cond)));
            return val_int(0);
        }

        case N_BLOC:
            evaluer(n->u.bloc.instr);
            if(!retour_actif) evaluer(n->u.bloc.suite);
            return val_int(0);

        case N_DECL_TAB:
            declarer_tableau(n->u.decl_tab.nom, n->u.decl_tab.taille);
            return val_int(0);

        case N_AFFECT_TAB: {
            int    idx=(int)to_double(evaluer(n->u.affect_tab.index));
            Valeur val=evaluer(n->u.affect_tab.expr);
            affecter_tableau(n->u.affect_tab.nom, idx, val);
            return val;
        }

        case N_ACCES_TAB: {
            int idx=(int)to_double(evaluer(n->u.acces_tab.index));
            return lire_tableau(n->u.acces_tab.nom, idx);
        }

        /* -----------------------------------------------
           DEFINITION DE FONCTION
           On enregistre simplement le nom, params, corps.
           L'exécution se fait à l'appel.
           ----------------------------------------------- */
        case N_DEF_FONC:
            enregistrer_fonction(n->u.def_fonc.nom, n->u.def_fonc.params, n->u.def_fonc.corps);
            return val_int(0);

        /* -----------------------------------------------
           APPEL DE FONCTION
           1. On cherche la définition
           2. On crée un nouveau contexte
           3. On lie les arguments aux paramètres
           4. On exécute le corps
           5. On récupère la valeur de retour
           6. On détruit le contexte local
           ----------------------------------------------- */
        case N_APPEL_FONC: {
            FonctionDef *f = trouver_fonction(n->u.appel_fonc.nom);
            if (!f) {
                char msg[128];
                sprintf(msg, "fonction '%s' non definie", n->u.appel_fonc.nom);
                erreur("Fonction", msg);
                return val_int(0);
            }

            /* Evaluer les arguments AVANT d'entrer dans le contexte */
            Valeur argv[64];
            int    argc = 0;
            Arg   *arg  = n->u.appel_fonc.args;
            while (arg && argc < 64) {
                argv[argc++] = evaluer(arg->expr);
                arg = arg->suivant;
            }

            /* Compter les paramètres */
            int    nparams = 0;
            Param *p = f->params;
            while (p) { nparams++; p = p->suivant; }

            if (argc != nparams) {
                char msg[128];
                sprintf(msg, "fonction '%s' attend %d argument(s), recu %d", n->u.appel_fonc.nom, nparams, argc);
                erreur("Fonction", msg);
                return val_int(0);
            }

            /* Nouveau contexte local */
            entrer_contexte();

            /* Lier paramètres → arguments */
            p = f->params;
            int i = 0;
            while (p) {
                definir_variable(p->nom, argv[i++]);
                p = p->suivant;
            }

            /* Exécuter le corps */
            retour_actif = 0;
            evaluer(f->corps);

            /* Récupérer la valeur de retour */
            Valeur resultat = retour_actif ? retour_valeur : val_int(0);
            retour_actif = 0;

            /* Détruire les variables locales */
            sortir_contexte();

            return resultat;
        }

        /* -----------------------------------------------
           RETOURNER
           Met retour_actif=1 et stocke la valeur.
           L'évaluateur parent arrête dès qu'il voit retour_actif.
           ----------------------------------------------- */
        case N_RETOURNER:
            retour_valeur = evaluer(n->u.retourner.expr);
            retour_actif  = 1;
            return retour_valeur;
    }
    return val_int(0);
}

/* ===========================================================
   RAPPORT FINAL
   =========================================================== */
void afficher_rapport(void) {
    fprintf(stderr, "\n===== Rapport d'execution =====\n");
    if (nb_erreurs==0 && nb_warnings==0)
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
void liberer_params(Param *p) { if(!p) return; liberer_params(p->suivant); free(p->nom); free(p); }
void liberer_args(Arg *a)     { if(!a) return; liberer_args(a->suivant); liberer(a->expr); free(a); }

void liberer(Node *n) {
    if (!n) return;
    switch(n->type) {
        case N_VARIABLE:   free(n->u.nom); break;
        case N_BINOP:      liberer(n->u.binop.gauche); liberer(n->u.binop.droite); break;
        case N_UNOP:       liberer(n->u.unop.operande); break;
        case N_AFFECT:     free(n->u.affect.var); liberer(n->u.affect.expr); break;
        case N_PRINT:      liberer(n->u.print.expr); break;
        case N_SI:         liberer(n->u.si.cond); liberer(n->u.si.alors); liberer(n->u.si.sinon); break;
        case N_TANTQUE:    liberer(n->u.tantque.cond); liberer(n->u.tantque.corps); break;
        case N_REPETER:    liberer(n->u.repeter.corps); liberer(n->u.repeter.cond); break;
        case N_BLOC:       liberer(n->u.bloc.instr); liberer(n->u.bloc.suite); break;
        case N_DECL_TAB:   free(n->u.decl_tab.nom); break;
        case N_AFFECT_TAB: free(n->u.affect_tab.nom); liberer(n->u.affect_tab.index); liberer(n->u.affect_tab.expr); break;
        case N_ACCES_TAB:  free(n->u.acces_tab.nom); liberer(n->u.acces_tab.index); break;
        case N_DEF_FONC:   free(n->u.def_fonc.nom); break; /* params/corps gardés en table */
        case N_APPEL_FONC: free(n->u.appel_fonc.nom); liberer_args(n->u.appel_fonc.args); break;
        case N_RETOURNER:  liberer(n->u.retourner.expr); break;
        default: break;
    }
    free(n);
}
