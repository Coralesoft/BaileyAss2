/* player.h */

#ifndef PLAYER_H
#define PLAYER_H

/* Player structure */
typedef struct 
{
    int row;
    int col;
    char originalCell;
} Player;

void updatePosition(char **map, Player *player, int newRow, int newCol);
void playerMovement(char **map, Player *player, char input, int map_row, int map_col);

#endif
