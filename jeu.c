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

void changerJoueur(int *joueur) {
    if( *joueur == 1 ){
        *joueur = 2;
    }else {
        *joueur = 1;
    }
}

void jouerPrototype (void){
    int joueurCourant = 1;
    int nombreCoups = 0;

    printf("------ Debut Jeu ------\n ");

    while(nombreCoups < 6)
    {
        jouerTour(&joueurCourant, &nombreCoups); 
    }

    printf("\nNombre de coups joues : %d \n", nombreCoups);
    printf("------ Fin Jeu ------\n ");
}

void jouerTour(int *joueurCourant, int *nombreCoups){
    printf("\nNumero du joueur courant: %d", *joueurCourant);
    printf("Le joueur %d choisit la colonne %d \n", *joueurCourant, demanderColonne());
    
    *nombreCoups = *nombreCoups + 1;
    
    changerJoueur(joueurCourant);
}