#ifndef PUISSANCE4_H
    #define PUISSANCE4_H

    #define NB_LIGNES 6 
    #define NB_COLONNES 7 
    #define VIDE 0 

    #define TAILLE_NOM 30 
 
    typedef struct { 
        char nom[TAILLE_NOM]; 
        int jeton; 
    } Joueur; 
    
    typedef struct { 
        int grille[NB_LIGNES][NB_COLONNES]; 
        Joueur joueurs[2]; 
        int joueurCourant; 
        int nombreJetons; 
    } Partie;


    
    void afficherRegles (void);
    // Affiche les regles du jeu Puissance 4

    int colonneValide(int colonne);
    // Verifie que le numéro de colonne est valide (entre 1 et 7)

    int demanderColonne(Partie *partie);
    //Demande une colonne jusqu'à obtenir un numéro valide

    void changerJoueur(Partie *partie);
    // Calcul le num de l'adversaire

    //void jouerPrototype (void);
    // Simule 6 coups sans mémoriser la grille

    //void jouerTour(int grille[][NB_COLONNES], int *joueurCourant, int *nombreCoups);
    // Réalise un tour de la version provisoire

    void initialiserGrille(Partie *partie); 
    // Place la valeur VIDE dans les 42 cases

    void afficherGrille(Partie *partie);
    //Affiche La grille

    int colonneLibre(Partie *partie, int colonne);
    // Vérifie qu'une colonne est libre

    int placerJeton(Partie *partie, int colonne);
    // Place un jeton dans la colonne libre et retourne 1 si oui ou 0 s'il n'y a pas eu de placement

    int alignementHorizontal(Partie *partie, int joueur);
    //Verifie l'alignement horizontal (4 jetons consécutives) pour le joueur
    
    int alignementVertical(Partie *partie, int joueur);
    //Verifie l'alignement vertical (4 jetons consécutives) pour le joueur 
    
    int alignementDiagonal(Partie *partie, int joueur); 
    //Verifie l'alignement diagonal(4 jetons consécutives) pour le joueur choisi
    
    int joueurAGagne(Partie *partie, int joueur);
    // Verifie si le joueur choisi a gagné 

    int grillePleine(Partie *partie);
    // Verifie si la grille est pleine sans parcourir 
    
    Partie *creerPartie(char nomJoueur1[], char nomJoueur2[]);
    //Crée une partie et retourne son pointeur

    void detruirePartie(Partie *partie);
    // Libére l'espace mémoire alloué à la partie 

    void jouerPartie(Partie *partie);
    // Simulation d'une partie de jeu jusqu'à ce que la grille soit pleine ou bien qu'un joueur gagne

#endif 
