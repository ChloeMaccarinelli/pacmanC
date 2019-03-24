#include "fantome.h"
#include"pacman.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <tchar.h>
#include <locale.h>

/** procédure de test **/

void initfantometest(Fantome *f,labyrinthe *l,int i,int j){
    srand(time(NULL));
    (*f).memCase = (*l).lab[i][j];
    (*f).lin =i, (*f).col = j;
}

void testmoverand(labyrinthe *l,pacman *p,Fantome *f){
    srand(time(NULL));
    int lin=(*f).lin;
    int col=(*f).col;
    int i=(*f).lin;
    int j=(*f).col;
    int move;
    bool droite=false;
    bool gauche=false;
    bool haut=false;
    bool bas=false;
    bool test=false;

    while(!test){
        move=rand()%4;
        switch(move){
            case 0:{lin--;break;}  /*va en haut*/
            case 1:{lin++;break;}  /*va en bas*/
            case 2:{col--;break;}  /*va a gauche*/
            case 3:{col++;break;}  /*va a droite*/
        }
        if((*l).lab[lin][col]!='#'){
            test=true;
            (*f).lin=lin;
            (*f).col=col;
            switch(move){
                case 0:{haut=true;break;}
                case 1:{bas=true;break;}
                case 2:{gauche=true;break;}
                case 3:{droite=true;break;}
            }
        }
    }
    switch((*l).lab[lin][col]){
        case '+':{
            (*p).nbvie--;
            initPacman(p,1,1,l);
            (*l).lab[i][j]=(*f).memCase;
            (*f).memCase=' ';
            (*l).lab[lin][col]='&';
            break;
        }


        case '@':{break;}
        case '*':{
            if(haut==true){
                (*l).lab[i][j]=(*f).memCase;(*f).memCase=(*l).lab[lin][col];(*l).lab[lin][col]='&';break;
            }
            else{
                if(bas==true){
                    (*l).lab[i][j]=(*f).memCase;(*f).memCase=(*l).lab[lin][col];(*l).lab[lin][col]='&';break;
                }
                else{
                    if(gauche==true){
                        (*l).lab[i][j]=(*f).memCase;(*f).memCase=(*l).lab[lin][col];(*l).lab[lin][col]='&';break;
                    }
                    else{
                        if(droite==true){
                            (*l).lab[i][j]=(*f).memCase;(*f).memCase=(*l).lab[lin][col];(*l).lab[lin][col]='&';break;
                        }
                    }
                }
            }

        }
        case ' ':{
            if(haut==true){
                (*l).lab[i][j]=(*f).memCase;(*f).memCase=(*l).lab[lin][col];(*l).lab[lin][col]='&';break;
            }
            else{
                if(bas==true){
                    (*l).lab[i][j]=(*f).memCase;(*f).memCase=(*l).lab[lin][col];(*l).lab[lin][col]='&';break;
                }
                else{
                    if(gauche==true){
                        (*l).lab[i][j]=(*f).memCase;(*f).memCase=(*l).lab[lin][col];(*l).lab[lin][col]='&';break;
                    }
                    else{
                        if(droite==true){
                            (*l).lab[i][j]=(*f).memCase;(*f).memCase=(*l).lab[lin][col];(*l).lab[lin][col]='&';break;
                        }
                    }
                }
            }
        }
    }
}

/*****  demande le nom du joueur en mode caché (chiffre uniqument)   *****/

int motdepasse()
{
    int c;
    int n=0;
    do
    {
        c=getch();
        if (c>='0' && c<='9')
        {
            n*=5;
            n+=(c-'0');
            printf("*");
        }
    }
    while(c!=0x0D);
    printf("\n");
    return n;
}
/****************************************************************
                *placement du curseur*/
void gotoxy(int x, int y)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cor;
	cor.X = x;
	cor.Y =y;
	SetConsoleCursorPosition(h, cor);
}
/****************************************************************
    *procédure pour gérer la couleur du texte et du fond*/
void textcolor(int color)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, color);
}


/*********** creation du menu *************/

int menu()
{
int choixMenu;

textcolor(14);
    printf("\n \n ");
    printf (" ######      #      #######   #       #     #     #       #       ################  \n");
    printf ("#      #    #  #    #         # #   # #    # #    ##      #     ###############     \n");
    printf ("#      #   #    #   #         #  # #  #   #   #   # #     #   #########  ###        \n");
    printf ("# #####   #      #  #         #   #   #  #     #  #  #    # ############	         \n");
    printf ("#         ########  #         #       #  #######  #   #   # ########## 	         \n");
    printf ("#         #      #  #         #       #  #     #  #    #  # ##########  	         \n");
    printf ("#         #      #  #         #       #  #     #  #     # #  ########### 	         \n");
    printf ("#         #      #  #         #       #  #     #  #      ##    #############	     \n");
    printf ("#         #      #  #######   #       #  #     #  #       #      ###############    \n");
    printf("\n\n") ;

        system("PAUSE");
        if (system("CLS")) system("clear");

textcolor(414);

    printf("-------------------------------------PACMAN-------------------------------------\n\n");

textcolor(14);

   printf("choisissez votre niveau:\n    1.facile\n    2.moyen\n    3.difficile\n", choixMenu);
    scanf("\n\n\n\n\n\n\n\n\n\n%d", &choixMenu);
    return choixMenu; /* c'est ici qu'on retourne une valeur*/

}


int main()

{
    setlocale (LC_ALL,"");/// procédure permettant d'affiché les accents

    /** boîtes de dialogues **/

    MessageBeep(MB_ICONINFORMATION);//genere un son

    int res,type =MB_ICONINFORMATION;


    res = MessageBox(NULL,_T("Prêt pour de nouvelles aventures\n             :) allons-y"),_T("PACMAN"),type);
    //printf("Code de retour : %d\n",res);


    res = MessageBox(NULL,_T("Voici les règles du jeu:\n\n-> déplacer Pac-Man a l intérieur du labyrinthe\n\n-> lui faire manger toutes les pac-gommes qui s y trouvent\n\n-> éviter d'être touché par des fantômes\n"),_T("PACMAN"),type);
   // printf("Code de retour : %d\n",res);

    MessageBeep(MB_ICONWARNING);


    int a,b =MB_ICONWARNING;
     a = MessageBox(NULL,_T("Les déplacements sont:\nO(haut)\nK(gauche)\nL(bas)\nM(droite)\nq pour quitter\n"),_T("PACMAN"),b);

/// mot de passe

    int mdp;
    printf("choisissez un mot de passe:(chiffre uniquement)\n");

    mdp=motdepasse();

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    system("PAUSE");
    if (system("CLS")) system("clear");


/********************************************************************************/

    labyrinthe l;
    pacman p;
    Fantome f,f2,f3;
    int arret=1;
    char direction;

     switch (menu())
    {
        case 1:
        {

        /** affichage **/
        printf("\n\n\n\n");
        gotoxy(20,10);
        textcolor(11);
        printf("VOUS AVEZ CHOISI LE NIVEAU FACILE!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        system("PAUSE");
        if (system("CLS")) system("clear");

        gotoxy(30,10);
        textcolor(11);
        printf("BONJOUR %d BONNE CHANCE :)\n\n\n\n\n\n\n\n\n\n\n", mdp);
        system("PAUSE");
        if (system("CLS")) system("clear");
        gotoxy(35,10);
        textcolor(11);
        puts("NIVEAU 1");
        textcolor(15);
        getch();


/********************************* code pacman *******************************************/



    createFileLab("lab2",&l);

    printScreen(&l);

    initPacman(&p,1,1,&l);



    initfantometest(&f,&l,3,16);
    initfantometest(&f2,&l,3,17);
   // initFantomeRand(&f,&l);
   // initFantomeRand(&f2,&l);

    printScreen(&l);


     while(l.nbGomme>p.nbgommes && p.nbvie!=p.nbmort && arret!=0)
    {



            switch (getch())
            {
                case 'q' :
                     {
                            arret=0;

                            gotoxy(35,10);
                            textcolor(11);
                            puts("INTERRUPTION\n\n\n\n\n\n\n\n\n\n\n\n\n");
                            system("PAUSE");
                            if (system("CLS")) system("clear");
                            break;

                     }

                case 'o' :
                    {
                            movePacmanTop(&p,&l);

                            //moveFantomeRand(&f,&l);
                            testmoverand(&l,&p,&f);
                            testmoverand(&l,&p,&f2);


                            break;
                    }

                case 'k' :
                    {

                           movePacmanLeft(&p,&l);
                           // moveFantomeRand(&f,&l);
                           testmoverand(&l,&p,&f);
                           testmoverand(&l,&p,&f2);


                           break;
                    }


                case 'l' :
                    {

                            movePacmanBottom(&p,&l);

                            //moveFantomeRand(&f,&l);
                            testmoverand(&l,&p,&f);
                            testmoverand(&l,&p,&f2);


                           break;
                    }


                case 'm' :
                    {


                            movePacmanRight(&p,&l);
                            //moveFantomeRand(&f,&l);
                            testmoverand(&l,&p,&f);
                            testmoverand(&l,&p,&f2);


                            break;
                    }

            }

                  printScreen(&l);

            printf("pacgommes totales:%d\nvie:%d\npacgommes:%d\n",l.nbGomme,p.nbvie,p.nbgommes);

    }


    if (l.nbGomme==p.nbgommes)
        {
            gotoxy(35,10);
            textcolor(14);
            printf("GAGNE\n");

        }
    else
        {
            if(p.nbvie<=p.nbmort)
            {
                gotoxy(35,10);
                textcolor(14);
                printf("PERDU\n");
            }
        }

    return 0;


    break;
    }




    case 2:
    {
        /** affichage **/

        gotoxy(20,10);
        textcolor(10);
        printf("VOUS AVEZ CHOISI LE NIVEAU MOYEN!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        system("PAUSE");
        if (system("CLS")) system("clear");

        gotoxy(30,10);
        textcolor(10);
        printf("BONJOUR %d BONNE CHANCE :)\n\n\n\n\n\n\n\n\n\n\n", mdp);
        system("PAUSE");
        if (system("CLS")) system("clear");
        gotoxy(35,10);
        textcolor(10);
        puts("NIVEAU 2");

    /** code pacman **/

     getch();


    createFileLab("lab2",&l);

    printScreen(&l);

    initPacman(&p,1,1,&l);

    initFantomeMem(&f,&l);
    initFantomeMem(&f2,&l);

    printScreen(&l);
    copieLab(l,&(f2.memoire.lab));
    copieLab(l,&(f.memoire.lab));

    while(l.nbGomme>p.nbgommes && p.nbvie!=p.nbmort && arret!=0)
    {
        direction=getch();
        while(l.nbGomme>p.nbgommes && p.nbvie!=p.nbmort && arret!=0 && !kbhit())
        {
            switch (direction)
            {
                case 'q' :
                     {
                         arret=0;

                            gotoxy(35,10);
                            textcolor(10);
                            puts("INTERRUPTION\n\n\n\n\n\n\n\n\n\n\n\n\n");
                            system("PAUSE");
                            if (system("CLS")) system("clear");
                            break;
           }

                case 'o' :
                    {
                        movePacmanTop(&p,&l);

                          moveFantomeMem(&f2,&l);
                          moveFantomeMem(&f,&l);
                            break;}
                case 'k' :
                    {
                          movePacmanLeft(&p,&l);

                           moveFantomeMem(&f2,&l);
                           moveFantomeMem(&f,&l);

                            break;
                    }

                case 'l' :
                    {
                        movePacmanBottom(&p,&l);

                            moveFantomeMem(&f2,&l);
                            moveFantomeMem(&f,&l);

                            break;
                    }

                case 'm' :
                    {
                         movePacmanRight(&p,&l);

                            moveFantomeMem(&f2,&l);
                            moveFantomeMem(&f,&l);

                            break;
                    }


            }




            printScreen(&l);
            printf("pacgommes totales:%d\nvie:%d\npacgommes:%d\n",l.nbGomme,p.nbvie,p.nbgommes);

        }
    }

    if (l.nbGomme==p.nbgommes)
        {
            gotoxy(35,10);
            textcolor(14);
            printf("GAGNE\n");
        }
    else
        {
            if(p.nbvie<=p.nbmort)
            {
                gotoxy(35,10);
                textcolor(14);
                printf("PERDU\n");
            }
        }

    return 0;

        break;
    }




    case 3:
        {
            /** affichage **/

        gotoxy(20,10);
        textcolor(12);
        printf("VOUS AVEZ CHOISI LE NIVEAU DIFFICILE!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        system("PAUSE");
        if (system("CLS")) system("clear");

        gotoxy(30,10);
        textcolor(12);
        printf("BONJOUR %d BONNE CHANCE :)\n\n\n\n\n\n\n\n\n\n\n", mdp);
        system("PAUSE");
        if (system("CLS")) system("clear");
        gotoxy(35,10);
        textcolor(12);
        puts("NIVEAU 3");

        /** code pacman **/

         getch();

    createFileLab("lab",&l);
    printScreen(&l);
    initPacman(&p,1,1,&l);


    initFantomeRand(&f,&l);
    initFantomeRand(&f3,&l);
    initFantomeMem(&f2,&l);

    printScreen(&l);
    copieLab(l,&(f2.memoire.lab));

    while(l.nbGomme>p.nbgommes && p.nbvie!=p.nbmort && arret!=0)
    {

        direction=getch();
        while(l.nbGomme>p.nbgommes && p.nbvie!=p.nbmort && arret!=0 && !kbhit())
        {
            switch (direction)
            {
                case 'q' :
                     {
                         arret=0;

                            gotoxy(35,10);
                            textcolor(12);
                            puts("INTERRUPTION\n\n\n\n\n\n\n\n\n\n\n\n\n");
                            system("PAUSE");
                            if (system("CLS")) system("clear");

                            break;

                     }

                case 'o' :
                    {
                            movePacmanTop(&p,&l);

                             // moveFantomeRand(&f,&l);
                             testmoverand(&l,&p,&f);
                             testmoverand(&l,&p,&f3);


                            moveFantomeMem(&f2,&l);

                            break;}
                case 'k' :
                    {
                            movePacmanLeft(&p,&l);

                             // moveFantomeRand(&f,&l);
                             testmoverand(&l,&p,&f);
                             testmoverand(&l,&p,&f3);


                            moveFantomeMem(&f2,&l);

                            break;
                    }

                case 'l' :
                    {
                             movePacmanBottom(&p,&l);

                             //moveFantomeRand(&f,&l);
                             testmoverand(&l,&p,&f);
                             testmoverand(&l,&p,&f3);


                            moveFantomeMem(&f2,&l);

                            break;
                    }

                case 'm' :
                    {
                           movePacmanRight(&p,&l);

                            //moveFantomeRand(&f,&l);
                            testmoverand(&l,&p,&f);
                             testmoverand(&l,&p,&f3);


                            moveFantomeMem(&f2,&l);

                            break;
                    }
            }


            printScreen(&l);
            printf("pacgommes totales:%d\nvie:%d\npacgommes:%d\n",l.nbGomme,p.nbvie,p.nbgommes);

     }
    }
    if (l.nbGomme==p.nbgommes)
        {
            gotoxy(35,10);
            textcolor(14);
            printf("GAGNE\n");
        }
    else
        {
            if(p.nbvie<=p.nbmort)
            {
                gotoxy(35,10);
                textcolor(14);
                printf("PERDU\n");
            }
        }

    return 0;



        break;
        }

getch();
        system("PAUSE");
        if (system("CLS")) system("clear");
    }


}


