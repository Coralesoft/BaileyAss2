#include <stdio.h>
#include <stdlib.h>
#include "mapping.h"

#define EMPTY_SPACE ' '
#define ROAD '.'
#define CAR '>'
#define PLAYER 'P'
#define GOAL 'G'
#define BORDER '*'

char** loadMapFromFile(const char *filename, int *map_row, int *map_col) {
    int i, j, val;
    FILE *file;
    char **map;

    file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(1);
    }

    fscanf(file, "%d %d", map_row, map_col);

    /* Adjust map rows and columns to include the borders */
    *map_row += 2;
    *map_col += 2;
    

    map = (char **)malloc((*map_row) * sizeof(char *));
    for (i = 0; i < *map_row; i++) {
        map[i] = (char *)malloc((*map_col) * sizeof(char));
    }

    /* Initialize the border */
    for (i = 0; i < *map_row; i++) {
        for (j = 0; j < *map_col; j++) {
            if (i == 0 || i == (*map_row) - 1 || j == 0 || j == (*map_col) - 1) {
                map[i][j] = BORDER;
            } else {
                map[i][j] = EMPTY_SPACE;  /* Set default value */
            }
        }
    }

    
    for (i = 1; i < (*map_row) - 1; i++) {
        for (j = 1; j < (*map_col) - 1; j++) {
            fscanf(file, "%d", &val);
            switch (val) {
                case 0:
                    map[i][j] = EMPTY_SPACE;
                    break;
                case 1:
                    map[i][j] = ROAD;
                    break;
                case 2:
                    map[i][j] = CAR;
                    break;
                case 3:
                    map[i][j] = PLAYER;
                    break;
                case 4:
                    map[i][j] = GOAL;
                    break;
                default:
                    fprintf(stderr, "Invalid value in map file\n");
                    exit(1);
            }
        }
    }

    fclose(file);
    return map;
}

void displayMap(char **map, int map_row, int map_col) 
{
    int i, j;
    for (i = 0; i < map_row; i++) 
    {
        for (j = 0; j < map_col; j++) 
        {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }

    /* Print game controls */
    printf("\npress w to move up\n");
    printf("press s to move down\n");
    printf("press a to move left\n");
    printf("press d to move right\n");
}
