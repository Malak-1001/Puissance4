#include "puissance4.h"
#include <stdio.h>

int main(void){
    /*afficherRegles();
    jouerPrototype();*/

    int grille[NB_LIGNES][NB_COLONNES];

    initialiserGrille(grille);

    afficherGrille(grille);

    for (int i =0 ; i<6 ; i++){
        placerJeton(grille, 2, 1);
    }
    
    afficherGrille(grille);

    if(!(placerJeton(grille, 2, 1))){
        printf("\n Il n'y a pas eu de placement  -> la colonne n'est pas libre");
    }

    return 0;
}