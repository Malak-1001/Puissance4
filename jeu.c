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
    if( (colonne <0) | (colonne >NB_COLONNES-1)){
        return 0;
    }else {
        return 1;
    }
}

int demanderColonne(void){
    int n;
    printf("\nChoisissez une colonne (1-7) :  ");
    scanf("%d", &n);

    n = n - 1;

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

    int grille[NB_LIGNES][NB_COLONNES];

    initialiserGrille(grille);

    afficherGrille(grille);

    printf("------ Debut Jeu ------\n ");

    while(!(grillePleine(grille)) && !(joueurAGagne(grille, joueurCourant)))
    {
        jouerTour(grille, &joueurCourant, &nombreCoups); 
        afficherGrille(grille);
    }

    if((joueurAGagne(grille, joueurCourant))){
        printf("\n Joueur %d a gagne !", joueurCourant);
    }

    if(grillePleine(grille)){
        printf("\n La grille est pleine.");
    }


    printf("\nNombre de coups joues : %d \n", nombreCoups);
    printf("------ Fin Jeu ------\n ");
}

void jouerTour(int grille[][NB_COLONNES], int *joueurCourant, int *nombreCoups){
    printf("\nNumero du joueur courant: %d", *joueurCourant);
    int colonne = demanderColonne() + 1;
    printf("Le joueur %d choisit la colonne %d \n", *joueurCourant, colonne);
    
    while(!(placerJeton(grille, colonne,*joueurCourant))){
        printf("\n La colonne %d est pleine!");
        colonne = demanderColonne();
        printf("\n Le joueur %d choisit la colonne %d \n", *joueurCourant, colonne+1);
    }
    *nombreCoups = *nombreCoups + 1;
    
    if(!(grillePleine(grille)) && !(joueurAGagne(grille, *joueurCourant))){
        changerJoueur(joueurCourant);
    }
    
}

int joueurAGagne(int grille[][NB_COLONNES], int joueur){
    if((alignementDiagonal(grille, joueur)) || (alignementVertical(grille, joueur)) || (alignementHorizontal(grille, joueur))){
        return 1;
    }else {
        return 0;
    }
    
}