#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include "mapping.h"
#include "player.h"
#include "newsleep.h"
#include "terminal.h"

/* Define macro for clearing screen based on OS */
#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

/* Function to clear terminal screen */
void clearScreen()
{
    system(CLEAR_SCREEN);
}

int main(int argc, char *argv[]) 
{
    int i, j; 
    int map_row, map_col;
    char **map;
    char input;
    Player player;

    /* Check for correct number of arguments */
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    /* Load map from file */
    map = loadMapFromFile(argv[1], &map_row, &map_col);
    if (!map) 
    {
        printf("Error loading map from file.\n");
        return 1;
    }

    /* Initialize player's position */
    for (i = 0; i < map_row; i++) 
    {
        for (j = 0; j < map_col; j++) 
        {
            if (map[i][j] == '3') 
            {
                player.row = i;
                player.col = j;
                player.originalCell = ' '; /* default to empty space */
                map[i][j] = 'P'; /* represent player as 'P' on the map */
                break;
            }
        }
    }

    /* Disable the terminal buffer to get instant input */
    disableBuffer();

    /* Game loop */
    while (1) 
    {
        clearScreen();  /* This will clear the screen each time the loop iterates. */

        /* Display map */
        displayMap(map, map_row, map_col);

        /* Get user input */
        printf("\nYour move: ");
        scanf(" %c", &input);

        /* Update player's position based on input */
        if (input == 'w' || input == 's' || input == 'a' || input == 'd') 
        {
            playerMovement(map, &player, input, map_row, map_col);
            newSleep(0.1); /* Adds a slight delay after each move. */
        }
    }

    /* Enable the terminal buffer again before program termination */
    enableBuffer();

    /* Clean up allocated memory */ 
    for (i = 0; i < map_row; i++) 
    {
        free(map[i]);
    }
    free(map);

    return 0;
}
