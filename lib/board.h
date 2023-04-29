#ifndef __BOARD_H__
#define __BOARD_H__

#include "route.h"

// �@�ӴѽL���c
typedef struct BOARD BOARD;

struct BOARD
{
    // �`�@�� sizeX * sizeY �Ӯ�l
    int sizeX;
    int sizeY;
    // for cord(x, y), n for index of grid[n], n = x + y*(sizeX)

    ROUTE *route;   // ����: ���V���b�i�椤���u
    ROUTE **grids;  // ���а}�C: �C�Ӱ}�C�������Ы��V�ѽL���@���a�}
                    // **grids[n] �i�H�Ψ��ˬd�Y�@�Ӯ�l�O���O�w�Q���L, �w�Q���L�|���V�@�Ӹ��u
};

// �M���ѽL�M���u
void board_destory(BOARD *board);

// �إߤ@�� sizeX * sizeY ���ѽL
BOARD * board_create(unsigned sizeX, unsigned sizeY);

// ���o�ѽL���@������, ���y��(x, y)����l, �L���@���a�} = x + y*sizeX
unsigned board_length(BOARD *board);
#endif
