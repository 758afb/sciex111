#include <stdlib.h>
#include <stdio.h>
#include "board.h"
#include "route.h"

void board_destory(BOARD *board)
{
    unsigned i;
    if (!board)
    {
        return;
    }

    if (board->route)
    {
        // route_destory(board->route);
    }

    for (i = 0; i < board_length(board); i++)
    {
        if(!board->grids[i]) {
            continue;
        }
        // free(board->grids[i]);
        board->grids[i] = NULL;
    }

    free(board);
    board = NULL;
}

// �إߴѽL
BOARD *
board_create(unsigned sizeX, unsigned sizeY)
{
    BOARD *board;

    board = malloc(sizeof(BOARD));
    board->sizeX = sizeX;
    board->sizeY = sizeY;
    board->grids = malloc(sizeX * sizeY * sizeof(ROUTE*));

    return board;
}

// �ѽL���@������
unsigned
board_length(BOARD *board)
{
    return board->sizeX * board->sizeY;
}
