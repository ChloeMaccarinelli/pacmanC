#ifndef PACMAN_H_INCLUDED
#define PACMAN_H_INCLUDED
#include "labyrinthe.h"
#include <windows.h>
#include <tchar.h>

/// structure de données de pacman
typedef struct{
    int x,y;
    int nbgommes;
    int nbmort,nbvie;
    int point;
    bool mange;
    char **pac;

    /** pour que pacman soit invincible pendant quelques instant */

    int supergommes;
    bool cible;

}pacman;

///procédure utilisé pour pacman

void initPacman(pacman *p,int x,int y,labyrinthe *l);
bool movePacmanTop(pacman *p,labyrinthe *l);
bool movePacmanBottom(pacman *p,labyrinthe *l);
bool movePacmanLeft(pacman *p,labyrinthe *l);
bool movePacmanRight(pacman *p,labyrinthe *l);


/*************************************************************************/
    void moveSuperPacmanTop(pacman *p,labyrinthe *l);
	void moveSuperPacmanBottom(pacman *p,labyrinthe *l);
	void moveSuperPacmanLeft(pacman *p,labyrinthe *l);
	void moveSuperPacmanRight(pacman *p,labyrinthe *l);

#endif // PACMAN_H_INCLUDED
