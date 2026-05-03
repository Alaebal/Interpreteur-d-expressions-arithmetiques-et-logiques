#define _GNU_SOURCE
#include <stdio.h>
#include "ast.h"

extern int yyparse(void);
extern FILE *yyin;

int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            fprintf(stderr, "[ERREUR] Impossible d'ouvrir '%s'\n", argv[1]);
            return 1;
        }
    } else {
        yyin = stdin;
    }

    printf("=== Interpreteur du mini-langage ===\n");
    if (argc > 1) printf("Fichier : %s\n\n", argv[1]);
    else          printf("Entrez vos instructions (Ctrl+Z pour quitter) :\n\n");

    yyparse();

    if (yyin != stdin) fclose(yyin);
    return (nb_erreurs > 0) ? 1 : 0;
}
