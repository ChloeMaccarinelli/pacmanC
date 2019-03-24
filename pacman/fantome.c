#include "fantome.h"

/// initialisation des fantômes qui parcours le labyrinthe au hasard

void initFantomeRand(Fantome *f,labyrinthe *l)
{
    srand(time(NULL));

    int i = rand()%(*l).lin, j = rand()%(*l).col;

    while((*l).lab[i][j]!= '*')
    {
        i = rand()%(*l).lin, j = rand()%(*l).col;
    }
    (*f).memCase = (*l).lab[i][j];
    (*f).lin =i;
    (*f).col = j;
    (*l).lab[i][j]='&';
}


/// initialise les fantômes qui mémorisent le labyrinthe

void initFantomeMem(Fantome *F,labyrinthe *l)
{
    srand(time(NULL));
    int i = rand()%(*l).lin, j = rand()%(*l).col;

    while((*l).lab[i][j]!= '*')
    {
        i = rand()%(*l).lin, j = rand()%(*l).col;
    }
    (*F).memCase = (*l).lab[i][j];
    (*F).lin =i;
    (*F).col =j;
    (*l).lab[i][j]='@';
}

/// déplacement des fantômes "au hasard"

void moveFantomeRand(Fantome *f,labyrinthe *l)
{
    int sens,movelin,movecol;
    bool test= false;

    while(!test)
    {
        sens = rand()%4;

        switch(sens)
        {
            case 0: {movecol = (*f).col+1;movelin=(*f).lin;break;}  //droite
            case 1: {movelin = (*f).lin+1;movecol=(*f).col;break;}  //bas
            case 2: {movecol = (*f).col-1;movelin=(*f).lin;break;}  //gauche
            case 3: {movelin = (*f).lin-1;movecol=(*f).col;break;}  //haut
        }

        if((*l).lab[movelin][movecol] != '#')
        {
            test = true;
        }
    }

    if((*l).lab[movelin][movecol] != '&' && (*l).lab[movelin][movecol] != '@')
    {
        switch((*l).lab[movelin][movecol])
        {
            case 'C':
            {
                initFantomeRand(f,l);
                break;
            }

            case '*':
            {
                  if((*f).memCase=='O')
                  {
                    (*l).lab[(*f).lin][(*f).col]=' ';
                    (*f).memCase=(*l).lab[movelin][movecol];
                    (*l).lab[movelin][movecol] = '&';
                  }
                  else
                  {
                    (*l).lab[(*f).lin][(*f).col]=(*f).memCase;
                    (*f).memCase=(*l).lab[movelin][movecol];
                    (*l).lab[movelin][movecol] = '&';
                  }
            break;
            }

            case ' ':
            {
                 if((*f).memCase=='O')
                 {
                        (*l).lab[(*f).lin][(*f).col]=' ';
                        (*f).memCase=(*l).lab[movelin][movecol];
                        (*l).lab[movelin][movecol] = '&';
                  }
                 else
                 {
                        (*l).lab[(*f).lin][(*f).col]=(*f).memCase;
                        (*f).memCase=(*l).lab[movelin][movecol];
                        (*l).lab[movelin][movecol] = '&';
                 }
                break;
            }

      }
    }

    else
    {
        (*f).lin=movelin;(*f).col=movecol;
        (*l).lab[movelin][movecol] = '&';
    }

   // (*l).lab[movelin][movecol] = '&';
}


/// déplacement des fantômes "mémoire"

void moveFantomeMem(Fantome *f,labyrinthe *l)
{
    int sens,movelin,movecol;
    srand(time(NULL));
    bool test= false;
    (*l).lab[(*f).lin][(*f).col]=(*f).memCase;

    while(!test)
    {
        sens = rand()%4;

        switch(sens)
        {
            case 0: movecol = (*f).col+1;movelin=(*f).lin;break;
            case 1: movelin = (*f).lin+1;movecol=(*f).col;break;
            case 2: movecol = (*f).col-1;movelin=(*f).lin;break;
            case 3: movelin = (*f).lin-1;movecol=(*f).col;break;
        }

        if((*f).memoire.lab[movelin][movecol] == ' ')
        {
            test = true;
        }

        else if((*f).memoire.lab[movelin][movecol] != '#' && rand()%5==0)
        {
            test = true;
        }
    }

        (*f).memoire.lab[(*f).lin][(*f).col]='9';

        refreshFantomeMem(f,(*l));

        if((*l).lab[movelin][movecol] != '&' && (*l).lab[movelin][movecol] != '@')
        {
            (*f).memCase=(*l).lab[movelin][movecol];
        }
        (*f).lin=movelin;(*f).col=movecol;
        (*l).lab[movelin][movecol] = '@';
}


void refreshFantomeMem(Fantome *f,labyrinthe l)
{
    int i,j;
    for(i=0;i<l.lin;i++)
    {
            for(j=0;j<l.col;j++)
            {
                switch((*f).memoire.lab[i][j])
                {
                    case '#':break;
                    case ' ':break;
                    default: (*f).memoire.lab[i][j]--;
                }
            }
    }
}



/******   chemin menant à pacman     *********/

bool searchPath(labyrinthe *l,int lin, int col, int cont)
{
    if(getCase(l, lin, col)== 'G' || getCase(l, lin, col)== 'C')
    {
        return(true);
    }

    if((getCase(l, lin, col)=='#') || (getCase(l, lin, col)=='S'))
    {
        return(false);
    }

    if(cont>10)
    {
        return(false);
    }

    setCase(l, lin, col, 'S');

    if(searchPath(l,lin+1,col,cont+1))
    {
        return(true);
    }

    if(searchPath(l,lin-1,col,cont+1))
    {
        return(true);
    }

    if(searchPath(l,lin,col+1,cont+1))
    {
        return(true);
    }

    if(searchPath(l,lin,col-1,cont+1))
    {
        return(true);
    }
    cont=cont-1;
    setCase(l, lin, col, ' ');

    return (false);
}
