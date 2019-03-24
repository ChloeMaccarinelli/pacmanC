#ifndef FANTOME_H_INCLUDED
#define FANTOME_H_INCLUDED
#include "labyrinthe.h"


/// structure de donn�es des fant�mes
typedef struct{
    int lin,col;
    char memCase;
    labyrinthe memoire;

}Fantome;

///proc�dure utilis� pour fant�mes

void initFantome(Fantome *F,labyrinthe *l);
void moveFantomeRand(Fantome *f,labyrinthe *l);
void moveFantomeMem(Fantome *f,labyrinthe *l);
void refreshFantomeMem(Fantome *f,labyrinthe l);
bool searchPath(labyrinthe *l,int lin, int col, int cont);



#endif // FANTOME_H_INCLUDED
