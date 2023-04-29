#include <stdio.h>
#include "lib/route.h"
#include "lib/board.h"

int main()
{
    BOARD *board;
    ROUTE *route, *next;

    board = board_create(10, 10);
    // board_destory(board);
    // �s���u�q (0,0) �}�l
    route = route_create(0, 0, 1);
    // �[�@�ӤU�@�B (1,1)
    next = route_next(route, 1, 1);
    // �[�@�ӤU�@�B (2,2)
    next = route_next(next, 2, 2);
    // �[�@�ӤU�@�B (3,3)
    next = route_next(next, 3, 3);

    // �L�X�Ҧ��B�J
    route_print(route);

    // clean up memory
    route_destory(route);

    return 0;
}
