#include "puissance4.h"
#include <stdio.h>

int main(void){
    afficherRegles();
    
    char nom1[20];
    char nom2[20];

    char reponse;

    do
    {
        printf(" Veuillez inserer le nom du Joueur X : ");
        scanf("%19s", nom1);

        printf("\n Veuillez inserer le nom du Joueur O : ");
        scanf("%19s", nom2);

        Partie *Jeu = creerPartie(nom1, nom2);

        jouerPartie(Jeu);

        detruirePartie(Jeu);
       
        printf("\n Voulez vous recommencer la partie ? \n Si Oui, entrez 'o' ou 'O'. Sinon autre.\n");
        scanf(" %c", &reponse);
    } while (reponse == 'o' || reponse =='O');
    
}