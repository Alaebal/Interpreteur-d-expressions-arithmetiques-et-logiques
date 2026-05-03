@echo off
echo === Compilation finale de l'interpreteur ===

win_bison -d interpreteur.y
if errorlevel 1 ( echo ERREUR: win_bison a echoue & pause & exit /b 1 )

win_flex lex.l
if errorlevel 1 ( echo ERREUR: win_flex a echoue & pause & exit /b 1 )

gcc -Wall -g -std=gnu99 -o interpreteur.exe main.c ast.c interpreteur.tab.c lex.yy.c
if errorlevel 1 ( echo ERREUR: gcc a echoue & pause & exit /b 1 )

echo.
echo === Compilation reussie ! ===
echo Utilisation :
echo   interpreteur.exe test_final.txt
echo.
pause
