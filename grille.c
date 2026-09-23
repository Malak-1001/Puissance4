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
                    printf("+");
                }else{
                    printf("| ");
                }
            }else if(i == NB_LIGNES){
                printf("---");
            }else if ((i== NB_LIGNES+1) && (j != 0 || j != NB_COLONNES))
            {
                printf(" %d ", j);
            }else{
                if (grille[i][j] == 0)
                {
                    printf(" . ");
                }else if (grille[i][j] == 1)
                {
                    printf(" X ");
                }else if (grille[i][j] == 2){
                    printf(" O ");
                }
            }
        }
        printf("\n");
    }
}

