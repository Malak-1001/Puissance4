#include "puissance4.h"
#include <stdio.h>


void initialiserGrille(Partie *partie){
    for (int i = 0; i < NB_LIGNES; i++)
    {
        for (int j = 0; j < NB_COLONNES; j++)
        {
            (*partie).grille[i][j]= VIDE;
        }
    }
    (*partie).nombreJetons = 0; // initialisation du nombre de jetons
}

void afficherGrille(Partie *partie){
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
                if ((*partie).grille[i][j - 1] == 0)
                {
                    printf(" . ");
                }else if ((*partie).grille[i][j - 1] == 1)
                {
                    printf(" X ");
                }else if ((*partie).grille[i][j - 1] == 2){
                    printf(" O ");
                }
            }
        }
        printf("\n");
    }
}


int colonneLibre(Partie *partie, int colonne){
    if((*partie).grille[0][colonne] != 0){
        return 0; // Colonne pas libre
    }else {
        return 1; // Colonne Libre
    }
}


int placerJeton(Partie *partie, int colonne){

    if(! (colonneLibre(partie,colonne))){
        return 0;  // Colonne non libre
    }else {
        for(int i = NB_LIGNES-1; i>=0 ; i-- ){
            if(((*partie).grille[i][colonne]) == 0){
                (*partie).grille[i][colonne] = (*partie).joueurs[(*partie).joueurCourant].jeton;
                (*partie).nombreJetons++;
                return 1; //Jeton placé
            }
        }
    }
    return 0; //Jeton non placé
}


int alignementHorizontal(Partie *partie, int joueur){
    int counter = 0;
    for(int i = 0; i < NB_LIGNES; i++){
        for(int j =0 ; j<NB_COLONNES; j++){
            if((*partie).grille[i][j] == joueur){
                counter++ ;
                if(counter == 4){
                    return 1 ; // Alignement trouvé
                }
            }else{
                if(counter != 0){
                    counter =0; 
                }
            }
        }
        counter = 0 ;
    }
    return 0; // Alignement non trouvé
}

int alignementVertical(Partie *partie, int joueur){
    int counter = 0;
    for(int j =0 ; j<NB_COLONNES; j++){
        for(int i = 0; i < NB_LIGNES ; i++){
            if((*partie).grille[i][j] == joueur){
                counter++ ;
                if(counter == 4){
                    return 1 ; // Alignement trouvé
                }
            }else{
                if(counter != 0){
                    counter =0; 
                }
            }
        }
        counter = 0 ;
    }
    return 0; // Alignement non trouvé
}


int alignementDiagonal(Partie *partie, int joueur){
    
    for(int i = 0; i < NB_LIGNES-3; i++){
        for(int j =0 ; j<NB_COLONNES-3; j++){
            if((*partie).grille[i][j] == joueur && ((*partie).grille[i+1][j+1] == joueur)&&((*partie).grille[i+2][j+2] == joueur)&&((*partie).grille[i+3][j+3] == joueur)){
                return 1;
            }
        }
    }

    for(int i = 0; i < NB_LIGNES-3; i++){
        for(int j = NB_COLONNES-1 ; j > 2; j--){
            if((*partie).grille[i][j] == joueur && ((*partie).grille[i+1][j-1] == joueur)&&((*partie).grille[i+2][j-2] == joueur)&&((*partie).grille[i+3][j-3] == joueur)){
                return 1;
            }
        }
    }

    return 0; // Alignement non trouvé
}

int grillePleine(Partie *partie){
    if((*partie).nombreJetons == NB_LIGNES*NB_COLONNES){
        return 1;
    }else{
        return 0;
    }
}



