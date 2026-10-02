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


int colonneLibre(int grille[][NB_COLONNES], int colonne){
    if(grille[0][colonne - 1] != 0){
        return 0; // Colonne pas libre
    }else {
        return 1; // Colonne Libre
    }
}


int placerJeton(int grille[][NB_COLONNES], int colonne, int joueur){

    if(! (colonneLibre(grille,colonne))){
        return 0;  //,Colonne non libre
    }else {
        for(int i = NB_LIGNES-1; i>=0 ; i-- ){
            if((grille[i][colonne-1]) == 0){
                grille[i][colonne-1] = joueur;
                return 1;
            }
        }
    }
    return 0;
}


int alignementHorizontal(int grille[][NB_COLONNES], int joueur){
    int counter = 0;
    for(int i = 0; i < NB_LIGNES; i++){
        for(int j =0 ; j<NB_COLONNES; j++){
            if(grille[i][j] == joueur){
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
    }
    return 0; // Alignement non trouvé
}

int alignementVertical(int grille[][NB_COLONNES], int joueur){
    int counter = 0;
    for(int j =0 ; j<NB_COLONNES; j++){
        for(int i = 0; i < NB_LIGNES ; i++){
            if(grille[i][j] == joueur){
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
    }
    return 0; // Alignement non trouvé
}


int alignementDiagonal(int grille[][NB_COLONNES], int joueur){
    
    for(int i = 0; i < NB_LIGNES-2; i++){
        for(int j =0 ; j<NB_COLONNES-3; j++){
            if(grille[i][j] == joueur && (grille[i+1][j+1] == joueur)&&(grille[i+2][j+2] == joueur)&&(grille[i+3][j+3] == joueur)){
                return 1;
            }
        }
    }

    for(int i = 0; i < NB_LIGNES-3; i++){
        for(int j = NB_COLONNES-1 ; j > 2; j--){
            if(grille[i][j] == joueur && (grille[i+1][j-1] == joueur)&&(grille[i+2][j-2] == joueur)&&(grille[i+3][j-3] == joueur)){
                return 1;
            }
        }
    }

    return 0; // Alignement non trouvé
}

int grillePleine(int grille[][NB_COLONNES]){
    for(int i=0 ; i< NB_COLONNES; i++){
        if(colonneLibre(grille,i)){
            return 0; // Présence d'une colonne libre donc la grille n'est pas pleine  
        }
    }
    return 1; // La grille est pleine
}



