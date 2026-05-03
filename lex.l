%{
#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "interpreteur.tab.h"
%}

%option noyywrap
%option yylineno

%%

[ \t\n\r]        { }

"si"             { return SI; }
"alors"          { return ALORS; }
"sinon"          { return SINON; }
"fin"            { return FIN; }
"print"          { return AFFICHER; }
"tantque"        { return TANTQUE; }
"repeter"        { return REPETER; }
"jusqua"         { return JUSQUA; }
"fonction"       { return FONCTION; }
"faire"          { return FAIRE; }
"retourner"      { return RETOURNER; }

"+"              { return PLUS; }
"-"              { return MOINS; }
"*"              { return FOIS; }
"/"              { return DIVISE; }

"=="             { return EGAL; }
"!="             { return DIFF; }
"<="             { return INFEG; }
">="             { return SUPEG; }
"<"              { return INF; }
">"              { return SUP; }

"&&"             { return ET; }
"||"             { return OU; }
"!"              { return NON; }

"="              { return AFFECTATION; }
";"              { return FIN_INSTRUCTION; }
"("              { return OUVRE_PARENTHESE; }
")"              { return FERME_PARENTHESE; }
"["              { return OUVRE_CROCHET; }
"]"              { return FERME_CROCHET; }
","              { return VIRGULE; }

[0-9]+"."[0-9]+ {
    yylval.reel = atof(yytext);
    return NOMBRE_REEL;
}

[0-9]+ {
    yylval.entier = atoi(yytext);
    return NOMBRE;
}

[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.chaine = strdup(yytext);
    return VARIABLE;
}

. {
    fprintf(stderr, "[ERREUR] Caractere non reconnu ligne %d : '%s'\n", yylineno, yytext);
}

%%
