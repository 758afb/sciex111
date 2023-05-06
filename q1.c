#include <stdio.h>
#include "lib/route.h"
#include "lib/board.h"
#include "lib/L_4x4_half_1.h"
#include "lib/LL_4x4_half_1.h"

int main()
{
    BOARD *board1, *board2, *board3, *board;
    ROUTE *route, *last;

    // �b���~1
    // board_destory(board);

    //4x4_L_half_1
    printf("�j���}�l��4x4�b���~1\n");
    board1 = L_4x4_half_1();
    board_svg(board1);
    board_print(board1);


    printf("�p���}�l��4x4�b���~2\n");
    board2 = LL_4x4_half_1();
    board_print(board2);

    printf("�p���}�l��4x4�����~\n");
    board3 = board_create(4, 4);
    route = route_create(2, 0, 1, SMALL_L);
    last = route_next(route, 3, 1, BIG_L);  // last is (3, 1)
    last = route_next(last, 2, 3, SMALL_L); // last is (2, 3)
    last = route_next(last, 3, 2, BIG_L);
    last = route_next(last, 1, 3, SMALL_L);
    last = route_next(last, 0, 2, BIG_L);
    last = route_next(last, 1, 0, SMALL_L);
    last = route_next(last, 0, 1, BIG_L);
    last = route_next(last, 2, 2, SMALL_L);
    last = route_next(last, 3, 3, BIG_L);
    last = route_next(last, 1, 2, SMALL_L);
    last = route_next(last, 0, 3, BIG_L);
    last = route_next(last, 1, 1, SMALL_L);
    last = route_next(last, 0, 0, BIG_L);
    last = route_next(last, 2, 1, SMALL_L);
    last = route_next(last, 3, 0, BIG_L);
    board_addRoute(board3, route);  // ����u��� board3
    board_print(board3);

    // �� 3 �� board ���_��
    route = board_mergeRoute(board1, board2, 0, board1->sizeM);
    board = board_create(4, 4*2);
    board_addRoute(board, route);   // ����u��� board

    route = board_mergeRoute(board, board3, 0, board->sizeM);
    // ���ƨϥ� board ���Ыe�� destory board ����O����
    board_destory(board);

    board = board_create(4*10, 4*3*10);   // ���ƨϥ� board
    board_addRoute(board, route);   // ����u��� board

    printf("�X��3��board\n");
    board_svg(board);

    // �ιL�����г��n destory
    route_destory(board->route);
    board_destory(board);
    board_destory(board1);
    board_destory(board2);
    board_destory(board3);

    return 0;
}
