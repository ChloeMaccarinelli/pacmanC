#include "pacman.h"




/// initialise pacman

void initPacman(pacman *p,int x,int y,labyrinthe *l)
{
   int i,j;

    if(x>0 && y>0)
    {
        (*p).x = x;
        (*p).y = y;
        (*p).pac = malloc((*l).lin*sizeof(char*));//alloue  la memoire pour pacman

        for(i=0;i<(*l).lin;i++)
        {
            (*p).pac[i] = malloc((*l).col * sizeof(char));

            for(j=0;j<(*l).col;j++)
            {
                (*p).pac[i][j]=' ';
            }
        }
    }

    (*l).lab[x][y]='G';// on initialise la forme de pacman ici G
    (*p).nbvie=1;
    (*p).nbmort=0;
    (*p).nbgommes=0;//nombre de pacgommes mangées
}


/// procédure pour que pacman puisse etre invulnérable aux fantômes




void moveSuperPacmanTop(pacman *p,labyrinthe *l){

    int i=(*p).x;
    int j=(*p).y;
    switch ((*l).lab[i-1][j]){

        case '+':{(*p).x--;(*l).lab[i][j]=' ';(*l).lab[i-1][j]='C';(*p).supergommes=20;break;}
        case '#':{(*l).lab[i][j]='C';(*p).supergommes++;break;}
        case '*':{ MessageBeep(MB_APPLMODAL);(*p).x--;(*p).nbgommes++;(*l).lab[i][j]=' ';(*l).lab[i-1][j]='C';(*p).point++;break;}
        case ' ':{(*p).x--;(*l).lab[i][j]=' ';(*l).lab[i-1][j]='C';break;}
        case '&':{(*p).point=(*p).point+10;(*p).x--;(*l).lab[i][j]=' ';(*l).lab[i-1][j]='C';(*p).mange=true;(*p).cible='&';break;}
        case '@':{(*p).point=(*p).point+10;(*p).x--;(*l).lab[i][j]=' ';(*l).lab[i-1][j]='C';(*p).mange=true;(*p).cible='@';break;}
    }
}

void moveSuperPacmanBottom(pacman *p,labyrinthe *l){

    int i=(*p).x;
    int j=(*p).y;
    switch ((*l).lab[i+1][j]){
        case '+':{(*p).x++;(*l).lab[i][j]=' ';(*l).lab[i+1][j]='C';(*p).supergommes=20;break;}
        case '#':{(*l).lab[i][j]='C';(*p).supergommes++;break;}
        case '*':{ MessageBeep(MB_APPLMODAL);(*p).x++;(*p).nbgommes++;(*l).lab[i][j]=' ';(*l).lab[i+1][j]='C';(*p).point++;break;}
        case ' ':{(*p).x++;(*l).lab[i][j]=' ';(*l).lab[i+1][j]='C';break;}
        case '&':{(*p).point=(*p).point+10;(*p).x++;(*l).lab[i][j]=' ';(*l).lab[i+1][j]='C';(*p).mange=true;(*p).cible='&';break;}
        case '@':{(*p).point=(*p).point+10;(*p).x++;(*l).lab[i][j]=' ';(*l).lab[i+1][j]='C';(*p).mange=true;(*p).cible='@';break;}
    }
}

void moveSuperPacmanLeft(pacman *p,labyrinthe *l){

    int i=(*p).x;
    int j=(*p).y;
    switch ((*l).lab[i][j-1]){
        case '+':{(*p).y--;(*l).lab[i][j]=' ';(*l).lab[i][j-1]='C';(*p).supergommes=20;break;}
        case '#':{(*l).lab[i][j]='C';(*p).supergommes++;break;}
        case '*':{ MessageBeep(MB_APPLMODAL);(*p).y--;(*p).nbgommes++;(*l).lab[i][j]=' ';(*l).lab[i][j-1]='C';(*p).point++;break;}
        case ' ':{(*p).y--;(*l).lab[i][j]=' ';(*l).lab[i][j-1]='C';break;}
        case '&':{(*p).point=(*p).point+10;(*p).y--;(*l).lab[i][j]=' ';(*l).lab[i][j-1]='C';(*p).mange=true;(*p).cible='&';break;}
        case '@':{(*p).point=(*p).point+10;(*p).y--;(*l).lab[i][j]=' ';(*l).lab[i][j-1]='C';(*p).mange=true;(*p).cible='@';break;}
    }
}

void moveSuperPacmanRight(pacman *p,labyrinthe *l){

    int i=(*p).x;
    int j=(*p).y;
    switch ((*l).lab[i][j+1]){
        case '+':{(*p).y++;(*l).lab[i][j]=' ';(*l).lab[i][j+1]='C';(*p).supergommes=20;break;}
        case '#':{(*l).lab[i][j]='G';(*p).supergommes++;break;}
        case '*':{ MessageBeep(MB_APPLMODAL);(*p).y++;(*p).nbgommes++;(*l).lab[i][j]=' ';(*l).lab[i][j+1]='C';(*p).point++;break;}
        case ' ':{(*p).y++;(*l).lab[i][j]=' ';(*l).lab[i][j+1]='C';break;}
        case '&':{(*p).point=(*p).point+10;(*p).y++;(*l).lab[i][j]=' ';(*l).lab[i][j+1]='C';(*p).mange=true;(*p).cible='&';break;}
        case '@':{(*p).point=(*p).point+10;(*p).y++;(*l).lab[i][j]=' ';(*l).lab[i][j+1]='C';(*p).mange=true;(*p).cible='@';break;}
    }
}


/* problème avec super pacman :
Pacman reste invulnérable uniquement sur la superpacgomme sauf qu'il se reinitialise */




/// déplacement de pacman vers le haut

bool movePacmanTop(pacman *p,labyrinthe *l)
{

    int i=(*p).x;
    int j=(*p).y;

    switch ((*l).lab[i-1][j])
    {
        case '#':
            {
                (*l).lab[i][j]='G';break;
            }//si mur

        case '*':
            {
                 MessageBeep(MB_APPLMODAL);
                (*p).x--;(*p).nbgommes++;(*l).lab[i][j]=' ';(*l).lab[i-1][j]='G';(*p).point++;break;
            }//si pacgommes

        case ' ':
            {
                (*p).x--;(*l).lab[i][j]=' ';(*l).lab[i-1][j]='G';break;
            } //si case vide

       case '+':
            {//(*p).x--;(*l).lab[i][j]=' ';(*l).lab[i-1][j]='C';return true;break;(*p).x--;(*l).lab[i][j]=' ';(*l).lab[i-1][j]='C';break;
                moveSuperPacmanTop(p,l);
            }//si superpacgommes

       case '&':
           {
               (*p).nbvie--;initPacman(p,1,1,l);break;
            }// si fantôme

        case '@':
            {
                (*p).nbvie--;initPacman(p,1,1,l);break;
            }// si fantôme
    }
}



///déplacement de pacman vers le bas

bool movePacmanBottom(pacman *p,labyrinthe *l)
{
    int i=(*p).x;
    int j=(*p).y;

    switch ((*l).lab[i+1][j])
    {
        case '#':
            {
                (*l).lab[i][j]='G';break;
            }

        case '*':
            {
                 MessageBeep(MB_APPLMODAL);
                (*p).x++;(*p).nbgommes++;(*l).lab[i][j]=' ';(*l).lab[i+1][j]='G';(*p).point++;break;
            }

        case ' ':
            {
                (*p).x++;(*l).lab[i][j]=' ';(*l).lab[i+1][j]='G';break;
            }
       case '+':
           {
      //  (*p).x++;(*l).lab[i][j]=' ';(*l).lab[i+1][j]='C';return true;break;(*p).x++;(*l).lab[i][j]=' ';(*l).lab[i+1][j]='C';break;
            moveSuperPacmanBottom(p,l);
           }

        case '&':
            {
                (*p).nbvie--;initPacman(p,1,1,l);break;
            }

        case '@':
            {
                (*p).nbvie--;initPacman(p,1,1,l);break;
            }
    }
}



///déplacement de pacman vers la gauche

bool movePacmanLeft(pacman *p,labyrinthe *l)
{

    int i=(*p).x;
    int j=(*p).y;

    switch ((*l).lab[i][j-1])
    {
        case '#':
            {
                (*l).lab[i][j]='G';break ;
            }

        case '*':
            {
                 MessageBeep(MB_APPLMODAL);
                (*p).y--;(*p).nbgommes++;(*l).lab[i][j]=' ';(*l).lab[i][j-1]='G';(*p).point++;break;
            }

        case ' ':
            {
                (*p).y--;(*l).lab[i][j]=' ';(*l).lab[i][j-1]='G';break;
            }

        case '+':
            {
      // (*p).y--;(*l).lab[i][j]=' ';(*l).lab[i][j-1]='C';return true;break;(*p).y--;(*l).lab[i][j]=' ';(*l).lab[i][j-1]='C';break;
                moveSuperPacmanLeft(p,l);
            }

        case '&':
            {
                (*p).nbvie--;initPacman(p,1,1,l);break;
            }

        case '@':
            {
                (*p).nbvie--;initPacman(p,1,1,l);break;
            }
    }
}



///déplacement de pacman vers la droite

bool movePacmanRight(pacman *p,labyrinthe *l)
{


    int i=(*p).x;
    int j=(*p).y;

    switch ((*l).lab[i][j+1])
    {
        case '#':
            {
                (*l).lab[i][j]='G';break;
            }

        case '*':
            {
                 MessageBeep(MB_APPLMODAL);
                (*p).y++;(*p).nbgommes++;(*l).lab[i][j]=' ';(*l).lab[i][j+1]='G';(*p).point++;break;
            }
        case ' ':
            {
                (*p).y++;(*l).lab[i][j]=' ';(*l).lab[i][j+1]='G';break;
            }

        case '+':
            {
         //  (*p).y++;(*l).lab[i][j]=' ';(*l).lab[i][j+1]='C';return true;break;(*p).y++;(*l).lab[i][j]=' ';(*l).lab[i][j+1]='C';break;
                    moveSuperPacmanRight(p,l);
            }


        case '&':
            {
                (*p).nbvie--;initPacman(p,1,1,l);break;
            }

        case '@':
            {
                (*p).nbvie--;initPacman(p,1,1,l);break;
            }
    }
}














