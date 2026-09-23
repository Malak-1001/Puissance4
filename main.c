#include "puissance4.h"
#include <stdio.h>

int main(void){
    /*afficherRegles();
    jouerPrototype();*/
    int grille[NB_LIGNES][NB_COLONNES];
    initialiserGrille(grille);
    for (int i = 0; i < NB_LIGNES; i++)
    {
        for (int j = 0; j < NB_COLONNES; j++)
        {
            printf(" %d ", grille[i][j]);
        }
        printf(" \n ");
    }
    
    afficherGrille(grille);

    return 0;
}