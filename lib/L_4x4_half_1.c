#include "L_4x4_half_1.h"
#include "board.h"
#include "route.h"

BOARD *
L_4x4_half_1(void)
{
    ROUTE *route, *last;
    BOARD *board;

    board = board_create(4, 4);

    route = route_create(0, 0, 0, BIG_L);
    last = route_next(route, 2, 1, SMALL_L); // last is (2, 1)
    last = route_next(last, 3, 0, BIG_L);    // last is (3, 0)
    last = route_next(last, 2, 2, SMALL_L);
    last = route_next(last, 3, 3, BIG_L);
    last = route_next(last, 1, 2, SMALL_L);
    last = route_next(last, 0, 3, BIG_L);
    board_addRoute(board, route);  // ����u��� board1

    return board;
}
