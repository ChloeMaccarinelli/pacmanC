#ifndef FANTOME_H_INCLUDED
#define FANTOME_H_INCLUDED
#include "labyrinthe.h"


/// structure de données des fantômes
typedef struct{
    int lin,col;
    char memCase;
    labyrinthe memoire;

}Fantome;

///procédure utilisé pour fantômes

void initFantome(Fantome *F,labyrinthe *l);
void moveFantomeRand(Fantome *f,labyrinthe *l);
void moveFantomeMem(Fantome *f,labyrinthe *l);
void refreshFantomeMem(Fantome *f,labyrinthe l);
bool searchPath(labyrinthe *l,int lin, int col, int cont);



#endif // FANTOME_H_INCLUDED
