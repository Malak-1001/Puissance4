#include "puissance4.h"
#include <stdio.h>

void afficherRegles (void){
    printf("------ Debut Regles ------\n ");
    printf("=== PUISSANCE 4 ===\n");
    printf("Alignez quatre jetons horizontalement, verticalement ou en diagonale.\n");
    printf("Les colonnes sont numerotees de 1 a 7. \n");
    printf("------ Fin Regles ------\n \n");
}

int colonneValide(int colonne){
    if( (colonne <1) | (colonne >7)){
        return 0;
    }else {
        return 1;
    }
}

int demanderColonne(void){
    int n;
    printf("\nChoisissez une colonne (1-7) :  ");
    scanf("%d", &n);

    while( !colonneValide(n)){
        printf("Numero colonne insere invalide. \n Veuillez inserer un autre: ");
        scanf("%d", &n);
    }

    return n;
}

int changerJoueur(int joueur) {
    if(joueur == 1 ){
        return 2;
    }else {
        return 1;
    }
}

void jouerPrototype (void){
    int joueurCourant = 1;
     printf("------ Debut Jeu ------\n ");

    for (int i = 0; i < 7; i++)
    {
        printf("\nTour du joueur %d ", joueurCourant);

        printf("\nLe joueur %d choisit la colonne %d", joueurCourant, demanderColonne());
        joueurCourant = changerJoueur(joueurCourant);
        
    }
    printf("------ Fin Jeu ------\n ");
}