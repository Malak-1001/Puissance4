**English** | [Français](README.fr.md)

# Connect Four in C

A two-player, command-line **Connect Four** game written in C.
Built as a pair project for the *Introduction to C* course (2nd-year Computer Science, CY Cergy Paris Université).

## Preview

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

## Rules

- The board has 6 rows and 7 columns.
- Players take turns: Player 1 plays `X`, Player 2 plays `O`.
- A token falls to the lowest free cell of the chosen column (numbered 1 to 7).
- The first player to line up **4 tokens** horizontally, vertically or diagonally wins.
- If the board is full with no winner, the game is a draw.
- After a game ends, you can start a new one.

## Requirements

- A C compiler (`gcc`)
- `make` (optional)

## Build and run

With `make` (builds, then launches the game):

```bash
make
```

Or manually:

```bash
gcc -Wall -Wextra -o puissance4 main.c jeu.c grille.c
./puissance4
```

To remove the executable:

```bash
make clean
```

> On Windows, use MinGW/MSYS2 (or WSL); the generated executable is `puissance4.exe`.

## Project structure

| File           | Role |
|----------------|------|
| `main.c`       | Entry point: player names, "play again?" loop |
| `jeu.c`        | Game logic: create/destroy a game, column input, player switching, win detection, main loop |
| `grille.c`     | Board: initialization, display, token placement, line detection, full-board check |
| `puissance4.h` | Constants, structures (`Joueur`, `Partie`) and prototypes |
| `Makefile`     | Build and clean |

## Implementation notes

- The whole game state lives in a `Partie` struct (board, players, current player, token count), allocated with `malloc` (`creerPartie`) and released with `free` (`detruirePartie`).
- Functions work on the game through pointers (`Partie *partie`).
- Win detection: `alignementHorizontal`, `alignementVertical` and `alignementDiagonal` (both directions), combined in `joueurAGagne`.
- Compiles with `-Wall -Wextra` without warnings.

> Identifiers and in-game messages are in French.

## C concepts practiced

2D arrays, pointers, structs, dynamic allocation, I/O (`scanf`/`printf`), separate compilation, header files and Makefiles.

## Possible improvements

- Harden input handling (non-numeric input makes `scanf` loop forever).
- Single-player mode against a simple AI.
- Highlight the 4 winning tokens.
- Configurable board size.

## Authors

- L. Malak Yamina
- K. Sonia

## License
