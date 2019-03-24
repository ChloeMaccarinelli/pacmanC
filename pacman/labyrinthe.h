#ifndef LABYRINTHE_H_INCLUDED
#define LABYRINTHE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#define TAILLE_MAX 100

/// structure de données du labyrinthe

typedef struct{
    char** lab;
    int lin;
    int col;
    int nbGomme;
}labyrinthe;

/// procédures utilisées pour le labyrinthe

int createEmptyLab(labyrinthe *l, int lin, int col);
void freeLab(labyrinthe *l);
int createFileLab(char *filename,labyrinthe *l);
void printScreen(labyrinthe *l);
void copieLab(labyrinthe l1,labyrinthe *l2);
void setCase(labyrinthe * l, int lin, int col, char state);
char getCase(labyrinthe * l, int lin, int col);
#endif // LABYRINTHE_H_INCLUDED
