#include "labyrinthe.h"

/// création du labyrinthe vide

int createEmptyLab( labyrinthe *l, int lin, int col)
{
    int i,j;

        if(lin>0 && col>0)
        {
            (*l).col = col;
            (*l).lin = lin;
            (*l).lab = malloc(lin*sizeof(char*));

            for(i=0;i<lin;i++)
            {
                (*l).lab[i] = malloc(col * sizeof(char));

                for(j=0;j<col;j++)
                {
                   (*l).lab[i][j]=' ';
                }
            }
        return 1;
        }
    else
    {
        return 0;
    }
}


void setCase(labyrinthe * l, int lin, int col, char state)
{
    (*l).lab[lin][col] = state;
}

char getCase(labyrinthe * l, int lin, int col)
{
    return((*l).lab[lin][col]);
}


/// création du labyrinthe à partir du fichier

int createFileLab(char * filename, labyrinthe * l)
{
    int i=0,j,lin,col;

    (*l).nbGomme=0;
    FILE* fichier =NULL;
    char chaine[TAILLE_MAX]="";

    sprintf(chaine,"Labyrinthes/%s.txt",filename);
    fichier = fopen(chaine,"r");
    if(fichier == NULL)
        {
        return -1;
        }

    else
    {
        fscanf(fichier,"%d %d",&lin,&col);
        createEmptyLab(l,lin,col);
        fgets(chaine,TAILLE_MAX,fichier);

        while(fgets(chaine,TAILLE_MAX,fichier)!= NULL && i<(*l).lin)
        {
                for(j=0;j<(*l).col;j++)
                {
                    switch(chaine[j])
                    {

                        case '#':{(*l).lab[i][j]=chaine[j];break;}

                        case ' ':{(*l).lab[i][j]='*';(*l).nbGomme++;break;}

                        case 'C':{(*l).lab[i][j]=chaine[j];break;}

                        case 'G':{(*l).lab[i][j]=chaine[j];break;}

                        case '+':{(*l).lab[i][j]=chaine[j];break;}
                    }

                }

                i++;
        }

        (*l).nbGomme--;
    }
    return 0;
    fclose(fichier);
}


/// affiche le labyrinthe

void printScreen(labyrinthe * l)
{

    Sleep(100);
    if (system("CLS")) system("clear");

    int i,j;

    for(i=0;i<(*l).lin;i++)
    {
        for(j=0;j<(*l).col;j++)
        {

             switch((*l).lab[i][j])// on traite chaque cas pour la couleur notament
                    {
                        case '&':
                            {   textcolor(12);

                                printf("%c",(*l).lab[i][j]);break;
                            }
                        case '@':
                            {   textcolor(12);

                                printf("%c",(*l).lab[i][j]);break;
                            }

                        case '#':
                            {   textcolor(16);

                                printf("%c",(*l).lab[i][j]);break;
                            }

                         case '*':
                            {
                                textcolor(15);

                                printf("%c",(*l).lab[i][j]);break;
                            }

                        case ' ':
                            {   textcolor(1);

                                printf("%c",(*l).lab[i][j]);break;
                            }


                        case 'C':
                            {
                                textcolor(14);

                                printf("%c",(*l).lab[i][j]);break;
                            }



                        case 'G':
                            {   textcolor(14);

                                printf("%c",(*l).lab[i][j]);break;
                            }

                        case '+':
                            {
                                textcolor(12);

                                printf("%c",(*l).lab[i][j]);break;
                            }
                    }


            textcolor(15,0);


        }
        printf("\n");
    }
    printf("\n");

}


///libère l'espace aloué pour le labyrinthe

void freeLab(labyrinthe *l)
{
    int i;

    for(i=0; i < (*l).lin; i++)
    {
        free( (*l).lab[i] );
        free( (*l).lab );
    }

}


/// copie du labyrinthe

void copieLab(labyrinthe l1,labyrinthe *l2)
{
    int i,j;
    createEmptyLab(l2,l1.lin,l1.col);
    for(i=0;i<l1.lin;i++)
    {
        for(j=0;j<l1.col;j++)
        {
            if(l1.lab[i][j]=='#')
            {
                (*l2).lab[i][j]=l1.lab[i][j];
            }
            else
            {
                (*l2).lab[i][j]=' ';
            }
        }
    }
}
