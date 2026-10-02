
#ifndef PUISSANCE4_H
    #define PUISSANCE4_H

    #define NB_LIGNES 6 
    #define NB_COLONNES 7 
    #define VIDE 0 


    
    void afficherRegles (void);
    // Affiche les regles du jeu Puissance 4

    int colonneValide(int colonne);
    // Verifie que le numéro de colonne est valide (entre 1 et 7)

    int demanderColonne(void);
    //Demande une colonne jusqu'à obtenir un numéro valide

    void changerJoueur(int *joueur);
    // Calcul le num de l'adversaire

    void jouerPrototype (void);
    // Simule 6 coups sans mémoriser la grille

    void jouerTour(int *joueurCourant, int *nombreCoups);
    // Réalise un tour de la version provisoire

    void initialiserGrille(int grille[][NB_COLONNES]); 
    // Place la valeur VIDE dans les 42 cases

    void afficherGrille(int grille[][NB_COLONNES]);
    //Affiche La grille

    int colonneLibre(int grille[][NB_COLONNES], int colonne);
    // Vérifie qu'une colonne est libre

    int placerJeton(int grille[][NB_COLONNES], int colonne, int joueur);
    // Place un jeton dans la colonne libre et retourne 1 si oui ou 0 s'il n'y a pas eu de placement

    int alignementHorizontal(int grille[][NB_COLONNES], int joueur);
    //Verifie l'alignement horizontal (4 jetons consécutives) pour le joueur
    
    int alignementVertical(int grille[][NB_COLONNES], int joueur);
    //Verifie l'alignement vertical (4 jetons consécutives) pour le joueur 
    
    int alignementDiagonal(int grille[][NB_COLONNES], int joueur); 
    //Verifie l'alignement diagonal(4 jetons consécutives) pour le joueur choisi
    
    int joueurAGagne(int grille[][NB_COLONNES], int joueur);

#endif 
