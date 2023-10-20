#include <stdio.h>
#include "player.h"
#include "mapping.h"

/* Helper function to update the player's new position on the map */
void updatePosition(char **map, Player *player, int newRow, int newCol)
{
    /* Place the original content back into the old position */
    map[player->row][player->col] = player->originalCell;

    /* Store the new cell's original content */
    player->originalCell = map[newRow][newCol];

    /* Update player coordinates */
    player->row = newRow;
    player->col = newCol;

    /* Place the player in the new position */
    map[player->row][player->col] = 'P';
}

/* Main function for handling player movements */
void playerMovement(char **map, Player *player, char input, int map_row, int map_col)
{
    /* Placeholder for the cell the player is about to enter */
    char nextCell;

    /* Coordinates for the next move */
    int newRow, newCol;

    /* Switch case for user input */
    switch (input)
    {
    /* Move up */
    case 'w':
        newRow = player->row - 1;
        newCol = player->col;

        /* Check if newRow is within map boundary */
        if (newRow >= 0)
        {
            nextCell = map[newRow][newCol];
            /* If the next cell is empty or a special spot or goal, move */
            if (nextCell == ' ' || nextCell == '.' || nextCell == 'G')
            {
                updatePosition(map, player, newRow, newCol);
            }
        }
        break;

    /* Move down */
    case 's':
        newRow = player->row + 1;
        newCol = player->col;

        /* Check if newRow is within map boundary */
        if (newRow < map_row)
        {
            nextCell = map[newRow][newCol];

            /* If the next cell is empty or a special spot or goal, move */
            if (nextCell == ' ' || nextCell == '.' || nextCell == 'G')
            {
                updatePosition(map, player, newRow, newCol);
            }
        }
        break;

    /* Move left */
    case 'a':
        newRow = player->row;
        newCol = player->col - 1;

        /* Check if newCol is within map boundary */
        if (newCol >= 0)
        {
            nextCell = map[newRow][newCol];

            /* If the next cell is empty or a special spot, move */
            if (nextCell == ' ' || nextCell == '.'|| nextCell == 'G')
            {
                updatePosition(map, player, newRow, newCol);
            }
        }
        break;

    /* Move right */
    case 'd':
        newRow = player->row;
        newCol = player->col + 1;

        /* Check if newCol is within map boundary */
        if (newCol < map_col)
        {
            nextCell = map[newRow][newCol];

            /* If the next cell is empty or a special spot, move */
            if (nextCell == ' ' || nextCell == '.'|| nextCell == 'G')
            {
                updatePosition(map, player, newRow, newCol);
            }
        }
        break;
    }
}
