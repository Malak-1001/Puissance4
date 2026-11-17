[English](README.md) | **Français**

# Puissance 4 en C

Jeu de **Puissance 4** en ligne de commande, pour deux joueurs, écrit en C.

## Aperçu

```
|  .  .  .  .  .  .  . |
|  .  .  .  .  .  .  . |
|  .  .  .  .  .  .  . |
|  .  .  .  .  .  .  . |
|  .  .  .  .  .  .  . |
|  .  O  .  X  .  .  . |
+ ---------------------+
|  1  2  3  4  5  6  7 |
```

## Règles

- La grille compte 6 lignes et 7 colonnes.
- Les joueurs jouent à tour de rôle : le Joueur 1 joue `X`, le Joueur 2 joue `O`.
- Le jeton tombe tout en bas de la colonne choisie (numérotée de 1 à 7).
- Le premier joueur à aligner **4 jetons** horizontalement, verticalement ou en diagonale gagne.
- Si la grille est pleine sans vainqueur, la partie est nulle.
- À la fin d'une partie, il est possible d'en relancer une nouvelle.

## Prérequis

- Un compilateur C (`gcc`)
- `make` (optionnel)

## Compilation et exécution

Avec `make` (compile puis lance le jeu) :

```bash
make
```

Ou manuellement :

```bash
gcc -Wall -Wextra -o puissance4 main.c jeu.c grille.c
./puissance4
```

Pour supprimer l'exécutable :

```bash
make clean
```

> Sous Windows, utilisez MinGW/MSYS2 (ou WSL) ; l'exécutable généré s'appelle `puissance4.exe`.

## Structure du projet

| Fichier        | Rôle |
|----------------|------|
| `main.c`       | Point d'entrée : saisie des noms, boucle « rejouer ? » |
| `jeu.c`        | Logique de partie : création/destruction, saisie de la colonne, changement de joueur, détection de victoire, boucle principale |
| `grille.c`     | Grille : initialisation, affichage, placement des jetons, détection des alignements, grille pleine |
| `puissance4.h` | Constantes, structures (`Joueur`, `Partie`) et prototypes |
| `Makefile`     | Compilation et nettoyage |

## Détails d'implémentation

- Toute la partie est regroupée dans une structure `Partie` (grille, joueurs, joueur courant, nombre de jetons), allouée dynamiquement avec `malloc` (`creerPartie`) et libérée avec `free` (`detruirePartie`).
- Les fonctions manipulent la partie via des pointeurs (`Partie *partie`).
- Détection de victoire : `alignementHorizontal`, `alignementVertical` et `alignementDiagonal` (deux sens), regroupées dans `joueurAGagne`.
- Compilation avec `-Wall -Wextra`, sans avertissement.

## Notions de C mises en pratique

Tableaux 2D, pointeurs, structures, allocation dynamique, entrées/sorties (`scanf`/`printf`), compilation séparée, en-têtes et Makefile.

## Pistes d'amélioration

- Sécuriser la saisie (une entrée non numérique fait boucler `scanf`).
- Mode contre l'ordinateur (IA simple).
- Surbrillance des 4 jetons gagnants.
- Taille de grille configurable.

## Auteurs

- L. Malak Yamina
- K. Sonia

Tous les droits sont reservés.
