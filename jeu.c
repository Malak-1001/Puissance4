#include "puissance4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

void afficherRegles (void){
    printf("------ Regles du Jeu Puissance 4 ------\n ");
    printf("=== PUISSANCE 4 ===\n");
    printf("Alignez quatre jetons horizontalement, verticalement ou en diagonale.\n");
    printf("Les colonnes sont numerotees de 1 a 7. \n");
    printf("\n----------------------------------------\n \n");
}

int colonneValide(int colonne){
    if( (colonne <0) || (colonne >NB_COLONNES-1)){
        return 0;
    }else {
        return 1;
    }
}

int demanderColonne(Partie *partie){
    int n;
    printf("\n %s, choisissez une colonne (1-7) :  ", (*partie).joueurs[(*partie).joueurCourant].nom);
    scanf("%d", &n);

    n = n - 1;

    while( !colonneValide(n)){
        printf("\nCette colonne n'existe pas.");
        printf("\n %s, choisissez une colonne (1-7) :  ", (*partie).joueurs[(*partie).joueurCourant].nom);
        scanf("%d", &n);
        n = n - 1;
    }
    return n;
}

void changerJoueur(Partie *partie) {
    (*partie).joueurCourant = !((*partie).joueurCourant);
}

/*void jouerPrototype (void){
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
        printf("\n La grille est pleine.\n --> Egalite");
    }


    printf("\nNombre de coups joues : %d \n", nombreCoups);
    printf("------ Fin Jeu ------\n ");
}*/

/*void jouerTour(int grille[][NB_COLONNES], int *joueurCourant, int *nombreCoups){
    printf("\nNumero du joueur courant: %d", *joueurCourant);
    int colonne = demanderColonne() + 1;
    printf("Le joueur %d choisit la colonne %d \n", *joueurCourant, colonne);
    
    while(!(placerJeton(grille, colonne,*joueurCourant))){
        printf("\n La colonne %d est pleine!", colonne+1);
        colonne = demanderColonne();
        printf("\n Le joueur %d choisit la colonne %d \n", *joueurCourant, colonne+1);
    }
    *nombreCoups = *nombreCoups + 1;
    
    if(!(grillePleine(grille)) && !(joueurAGagne(grille, *joueurCourant))){
        changerJoueur(joueurCourant);
    }
}*/

int joueurAGagne(Partie *partie, int joueur){
    if((alignementDiagonal(partie, joueur)) || (alignementVertical(partie, joueur)) || (alignementHorizontal(partie, joueur))){
        return 1;
    }else {
        return 0;
    }
}

Partie *creerPartie(char nomJoueur1[], char nomJoueur2[]){
    Partie* partieJeu = malloc(sizeof(Partie));

    if(partieJeu != NULL){
        strcpy((*partieJeu).joueurs[0].nom, nomJoueur1);
        strcpy((*partieJeu).joueurs[1].nom, nomJoueur2);

        (*partieJeu).joueurs[0].jeton = 1;
        (*partieJeu).joueurs[1].jeton = 2;

        (*partieJeu).joueurCourant = 0;

        initialiserGrille(partieJeu);
    }

    return partieJeu;
}

void detruirePartie(Partie *partie){
    free(partie);
    partie = NULL;
}

void jouerPartie(Partie *partie){
    initialiserGrille(partie);


    while(!(grillePleine(partie)) && !(joueurAGagne(partie, (*partie).joueurs[(*partie).joueurCourant].jeton)))
    {
        int colonne = demanderColonne(partie);

        while(!(placerJeton(partie, colonne))){
            printf("\n La colonne %d est pleine!", colonne+1);
            colonne = demanderColonne(partie);
            printf("\n %s a choisit la colonne %d \n", (*partie).joueurs[(*partie).joueurCourant].nom, colonne+1);
        }  

        afficherGrille(partie);

        if(!(grillePleine(partie)) && !(joueurAGagne((partie), (*partie).joueurs[(*partie).joueurCourant].jeton))){
            changerJoueur(partie);
        }
    }

    if((joueurAGagne(partie, (*partie).joueurs[(*partie).joueurCourant].jeton))){
        printf("\n - > %s a gagne !!!", (*partie).joueurs[(*partie).joueurCourant].nom);
    }else if(grillePleine(partie)){
        printf("\n La grille est pleine.\n --> Egalite");
    }


    printf("\n------ Fin Jeu ------\n ");
}