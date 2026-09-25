#include "puissance4.h"
#include <stdio.h>


void initialiserGrille(int grille[][NB_COLONNES]){
    for (int i = 0; i < NB_LIGNES; i++)
    {
        for (int j = 0; j < NB_COLONNES; j++)
        {
            grille[i][j]= VIDE;
        }
    }
    
}

void afficherGrille(int grille[][NB_COLONNES]){
printf("\n");
    for (int i = 0; i < NB_LIGNES + 2; i++)
    {
        for (int j = 0; j < NB_COLONNES + 2; j++)
        {
            if(j == 0 || j == NB_COLONNES + 1){
                if(i == NB_LIGNES){
                    printf("+ ");
                }else{
                    printf("| ");
                }
            }else if(i == NB_LIGNES){
                printf("---");
            }else if ((i== NB_LIGNES+1) && (j != 0 || j != NB_COLONNES))
            {
                printf(" %d ", j);
            }else{
                // Before : if (grille[i][j] == 0)
                // Y avait un petit décalage avec l'index j qui causait problème
                // Quand j== NB_COLONNES on accédait à une case mémoire non défini
                // C'est pour cela qu'on arrive pas à afficher correctement 
                if (grille[i][j - 1] == 0)
                {
                    printf(" . ");
                }else if (grille[i][j - 1] == 1)
                {
                    printf(" X ");
                }else if (grille[i][j - 1] == 2){
                    printf(" O ");
                }
            }
        }
        printf("\n");
    }
}

