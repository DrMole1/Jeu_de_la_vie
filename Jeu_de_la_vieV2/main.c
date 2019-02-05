#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "jeuvie.h"
#include "figure.h"
#include "sauvegarde.h"


//Impl�mentation
//===============================
//BUT : Reproduire le jeu de la vie de Jhon Conway selon les r�gles pr�-�tablies
//REGLES :
//  - une cellule na�t dans une case vide voisine d'exactement trois cellules
//  - une cellule ayant z�ro ou une voisine vivante meurt (d'isolement...), de m�me qu'une cellule poss�dant quatre voisines ou plus (surpopulation...) ;
//  - une cellule avec deux ou trois voisines survit � la prochaine g�n�ration.
//ENTREE : L'environnement
//SORTIE : L'environnement
//===============================
int main()
{
    //D�claration et initialisation des variables
    tCellule Tab[NLIGNES][NCOLONNES];
    int nTemps = 0, i = 0, j = 0, nSaisie = 0, nCellulesVivantes = 0, nCellulesMortes = 0;
    tBool EnProgression = false;
    FILE * pFile=NULL;

    //RAZ du tableau pour un d�but de partie
    razCelluleAutour(Tab);
    razEtat(Tab);

    //mise en place des cellules vivantes par l'utilisateur
    do{
        printf("Saisir 1 pour la figure du planeur\n");
        printf("Saisir 2 pour la figure du grenouille\n");
        printf("Saisir 3 pour une figure al�atoire\n");
        scanf("%d",&nSaisie);

        switch(nSaisie)
        {
            case UN : planeur(Tab,&nCellulesVivantes); break;
            case DEUX : grenouille(Tab,&nCellulesVivantes); break;
            case TROIS : figure(Tab,&nCellulesVivantes); break;
            default : printf("Mauvaise saisie\n"); break;
        }

    }while(nSaisie<UN && nSaisie>TROIS);

    //afficher le tableau
    printf("Votre tableau de base.\n");
    afficherTab(Tab);
    system("pause");



    //d�roulement de la boucle principale
    do{
        system("cls");
        EnProgression=false;
        nTemps++;

        //passer les cellules en NAISSANTE ou MOURRANTE
        for (i = ZERO; i < NLIGNES; i++)
        {
            for (j = ZERO; j < NCOLONNES; j++)
            {
                //si la cellule se trouve au c�t� extreme gauche du tableau
                if (j==ZERO)
                {
                    if (getEtat(Tab,i,j+1)==vivante)
                            setCelluleAutour(Tab,i,j);
                    if (i!=NLIGNES-1)
                    {
                        if (getEtat(Tab,i+1,j+1)==vivante)
                            setCelluleAutour(Tab,i,j);
                        if (getEtat(Tab,i+1,j)==vivante)
                            setCelluleAutour(Tab,i,j);
                    }
                    else if (i!=ZERO)
                    {
                        if (getEtat(Tab,i-1,j)==vivante)
                            setCelluleAutour(Tab,i,j);
                        if (getEtat(Tab,i-1,j+1)==vivante)
                            setCelluleAutour(Tab,i,j);
                    }
                }
                //si la cellule se trouve au c�t� extreme droite du tableau
                else if (j==NCOLONNES-1)
                {
                    if (getEtat(Tab,i,j-1)==vivante)
                        setCelluleAutour(Tab,i,j);
                    if (i!=NLIGNES)
                    {
                        if (getEtat(Tab,i+1,j)==vivante)
                            setCelluleAutour(Tab,i,j);
                        if (getEtat(Tab,i+1,j-1)==vivante)
                            setCelluleAutour(Tab,i,j);
                    }
                    else if (i!=ZERO)
                    {
                        if (getEtat(Tab,i-1,j-1)==vivante)
                            setCelluleAutour(Tab,i,j);
                        if (getEtat(Tab,i-1,j)==vivante)
                            setCelluleAutour(Tab,i,j);
                    }
                }
                //si la cellule se trouve au c�t� extreme haut du tableau
                else if (i==ZERO)
                {
                    if (getEtat(Tab,i,j+1)==vivante)
                        setCelluleAutour(Tab,i,j);
                    if (getEtat(Tab,i+1,j+1)==vivante)
                        setCelluleAutour(Tab,i,j);
                    if (getEtat(Tab,i+1,j)==vivante)
                        setCelluleAutour(Tab,i,j);
                    if (getEtat(Tab,i+1,j-1)==vivante)
                        setCelluleAutour(Tab,i,j);
                    if (getEtat(Tab,i,j-1)==vivante)
                        setCelluleAutour(Tab,i,j);
                }
                //si la cellule se trouve au c�t� extreme bas du tableau
                else if (i==NLIGNES-1)
                {
                    if (getEtat(Tab,i,j-1)==vivante)
                        setCelluleAutour(Tab,i,j);
                    if (getEtat(Tab,i-1,j-1)==vivante)
                        setCelluleAutour(Tab,i,j);
                    if (getEtat(Tab,i-1,j)==vivante)
                        setCelluleAutour(Tab,i,j);
                    if (getEtat(Tab,i-1,j+1)==vivante)
                        setCelluleAutour(Tab,i,j);
                    if (getEtat(Tab,i,j+1)==vivante)
                        setCelluleAutour(Tab,i,j);
                }
                else
                {
                    if (getEtat(Tab,i,j+1)==vivante)
                        setCelluleAutour(Tab,i,j);
                    if (getEtat(Tab,i+1,j+1)==vivante)
                        setCelluleAutour(Tab,i,j);
                    if (getEtat(Tab,i+1,j)==vivante)
                        setCelluleAutour(Tab,i,j);
                    if (getEtat(Tab,i+1,j-1)==vivante)
                        setCelluleAutour(Tab,i,j);
                    if (getEtat(Tab,i,j-1)==vivante)
                        setCelluleAutour(Tab,i,j);
                    if (getEtat(Tab,i-1,j-1)==vivante)
                        setCelluleAutour(Tab,i,j);
                    if (getEtat(Tab,i-1,j)==vivante)
                        setCelluleAutour(Tab,i,j);
                    if (getEtat(Tab,i-1,j+1)==vivante)
                        setCelluleAutour(Tab,i,j);
                }



                //on set l'�tat de transition de la cellule
                if (getEtat(Tab,i,j)==vivante && getCelluleAutour(Tab,i,j)<MINMORT)
                {
                    setEtatTrans(Tab,i,j,mourrante);
                }
                else if (getEtat(Tab,i,j)==morte && getCelluleAutour(Tab,i,j)==MAXMORT)
                {
                    setEtatTrans(Tab,i,j,naissante);
                }
                else if (getEtat(Tab,i,j)==vivante && getCelluleAutour(Tab,i,j)>MAXMORT)
                {
                    setEtatTrans(Tab,i,j,mourrante);
                }
            }
        }
        razCelluleAutour(Tab); //on remet � 0 les compteurs des cellules autour

        //passer les cellules en MORTE ou VIVANTE d'apr�s leur �tat de transition
        for (i = ZERO; i < NLIGNES; i++)
        {
            for (j = ZERO; j < NCOLONNES; j++)
            {
                if (getEtatTrans(Tab,i,j)==mourrante)
                {
                    setEtat(Tab,i,j,morte);
                    nCellulesVivantes--;
                    EnProgression=true;
                }
                else if (getEtatTrans(Tab,i,j)==naissante)
                {
                    setEtat(Tab,i,j,vivante);
                    nCellulesVivantes++;
                    EnProgression=true;
                }
            }
        }

        razEtatTrans(Tab);
        //afficher le tableau
        afficherTab(Tab);
        Sleep(320); //petite pause avant de progresser � la slide suivante (merci Nathan)
    }while(EnProgression==true);


    //affichage du r�sultat
    printf("Le temps de generation : %d\n",nTemps);
    printf("Le nombre de cellules vivantes : %d\n",nCellulesVivantes);
    nCellulesMortes = (NLIGNES*NCOLONNES)-nCellulesVivantes;
    printf("Le nombre de cellules mortes : %d\n",nCellulesMortes);

    //sauvegarder le r�sultat dans le fichier
    EcrireFichier(pFile,nTemps,nCellulesVivantes,nCellulesMortes);



    return 0;
}

