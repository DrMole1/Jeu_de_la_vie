
#include "jeuvie.h"


//Impl�mentation
//===============================
//NOTE : Ascesseur sous forme get
//BUT : Prendre l'�tat de la cellule
//ENTREE : Le tableau, la ligne et la colonne
//SORTIE : L'�tat de la cellule voulue dans le tableau
//===============================
extern tEtat getEtat(tCellule Tab[NLIGNES][NCOLONNES], const int i, const int j)
{
    tEtat etatTemp;
    etatTemp = Tab[i][j].etat;
    return etatTemp;
}


//Impl�mentation
//===============================
//NOTE : Ascesseur sous forme set
//BUT : Set l'�tat de la cellule par l'�tat voulu
//ENTREE : Le tableau, la ligne, la colonne, et l'�tat voulu
//SORTIE : L'�tat de la cellule voulue dans le tableau
//===============================
extern void setEtat(tCellule Tab[NLIGNES][NCOLONNES], const int i, const int j, const tEtat etatTemp)
{
    Tab[i][j].etat=etatTemp;
}


//Impl�mentation
//===============================
//NOTE : Ascesseur sous forme get
//BUT : Prendre l'�tat de transition de la cellule
//ENTREE : Le tableau, la ligne et la colonne
//SORTIE : L'�tat de transition de la cellule voulue dans le tableau
//===============================
extern tEtatTransition getEtatTrans(tCellule Tab[NLIGNES][NCOLONNES], const int i, const int j)
{
    tEtatTransition etatTemp;
    etatTemp = Tab[i][j].transition;
    return etatTemp;
}


//Impl�mentation
//===============================
//NOTE : Ascesseur sous forme set
//BUT : Set l'�tat de transition de la cellule par l'�tat voulu
//ENTREE : Le tableau, la ligne, la colonne, et l'�tat voulu
//SORTIE : L'�tat de transition de la cellule voulue dans le tableau
//===============================
extern void setEtatTrans(tCellule Tab[NLIGNES][NCOLONNES], const int i, const int j, const tEtatTransition etatTemp)
{
    Tab[i][j].transition=etatTemp;
}


//Impl�mentation
//===============================
//NOTE : Ascesseur sous forme get
//BUT : Prendre le compteur de nombre de cellules autour de la cellule
//ENTREE : Le tableau, la ligne et la colonne
//SORTIE : Le nombre de cellule autour de la cellule voulue dans le tableau
//===============================
extern int getCelluleAutour(tCellule Tab[NLIGNES][NCOLONNES], const int i, const int j)
{
    int nTemp = 0;
    nTemp = Tab[i][j].nCelluleAutour;
    return nTemp;
}


//Impl�mentation
//===============================
//NOTE : Ascesseur sous forme set
//BUT : Prendre le compteur de nombre de cellules autour de la cellule en question
// et l'incr�menter par passage par adresse
//ENTREE : Le tableau, la ligne et la colonne
//SORTIE : Le nombre de cellule autour de la cellule voulue dans le tableau
//===============================
extern void setCelluleAutour(tCellule Tab[NLIGNES][NCOLONNES], const int i, const int j)
{
    Tab[i][j].nCelluleAutour+=1;
}


//Impl�mentation
//===============================
//BUT : Remet � 0 le compteur de cellules autour de la cellule en question
//ENTREE : Le tableau
//SORTIE : Le nombre de cellule autour de toutes les cellules dans le tableau
//===============================
extern void razCelluleAutour(tCellule Tab[NLIGNES][NCOLONNES])
{
    int i = 0, j = 0;
    for (i = 0; i < NLIGNES; i++)
    {
        for (j = 0; j < NCOLONNES; j++)
        {
            Tab[i][j].nCelluleAutour=0;
        }
    }
}


//Impl�mentation
//===============================
//BUT : Initialise l'�tat de toutes les cellules du tableau � MORTE
//ENTREE : Le tableau
//SORTIE : L'�tat des cellules dans le tableau
//===============================
extern void razEtat(tCellule Tab[NLIGNES][NCOLONNES])
{
    int i = 0, j = 0;
    for (i = 0; i < NLIGNES; i++)
    {
        for (j = 0; j < NCOLONNES; j++)
        {
            Tab[i][j].etat=morte;
            Tab[i][j].transition=null;
        }
    }
}


//Impl�mentation
//===============================
//BUT : Initialise l'�tat de transition de toutes les cellules du tableau � MORTE
//ENTREE : Le tableau
//SORTIE : L'�tat de transition des cellules dans le tableau
//===============================
extern void razEtatTrans(tCellule Tab[NLIGNES][NCOLONNES])
{
    int i = 0, j = 0;
    for (i = 0; i < NLIGNES; i++)
    {
        for (j = 0; j < NCOLONNES; j++)
        {
            Tab[i][j].transition=null;
        }
    }
}


//Impl�mentation
//===============================
//BUT : Afficher le tableau du jeu de la vie
//ENTREE : Le tableau
//SORTIE : Le tableau
//===============================
extern void afficherTab(tCellule Tab[NLIGNES][NCOLONNES])
{
    int i = 0, j = 0;
    for (i = 0; i < NLIGNES; i++)
    {
        for (j = 0; j < NCOLONNES; j++)
        {
            if (Tab[i][j].etat==vivante)
                printf(" O");
            else
                printf(" *");
        }
        printf("\n");
    }
}
