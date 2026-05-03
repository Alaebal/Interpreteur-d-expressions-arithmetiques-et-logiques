Interpréteur d'expressions arithmétiques et logiques
 Description

Ce projet est un interpréteur de langage simple développé en langage C, basé sur les outils Flex et Bison.
Il permet d’analyser, construire et exécuter des expressions arithmétiques, logiques, ainsi que des structures de contrôle.

Le projet repose sur une AST (Abstract Syntax Tree) pour représenter et évaluer les programmes.

Concepts utilisés

Analyse lexicale et syntaxique
Grammaires context-free
AST (Abstract Syntax Tree)
Évaluation d’expressions
Gestion mémoire en C
Gestion d’erreurs


Technologies utilisées
Langage C
Flex (analyse lexicale)
Bison (analyse syntaxique)
Structures de données : AST (Abstract Syntax Tree)


Compilation
🔹 Sous Windows
compile.bat

🔹 Compilation manuelle
bison -d interpreteur.y
flex lex.l
gcc -o interpreteur main.c interpreteur.tab.c lex.yy.c ast.c
Architecture du projet
Le programme fonctionne en 3 étapes :

Analyse lexicale (Flex)
→ transforme le code en tokens
Analyse syntaxique (Bison)
→ construit un AST
Évaluation (C)
→ exécute l’AST
