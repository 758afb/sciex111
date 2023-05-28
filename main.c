#include <stdio.h>
#include "lib/adam.h"
#include "lib/allen.h"
#include "lib/irene.h"
#include "lib/route.h"
#include "lib/board.h"
#include "lib/board_4kx4k.h"
#include "lib/board_4k2x4k.h"
#include "lib/board_4kx4k2.h"
#include "lib/board_4k2x4k2.h"
#include "lib/board_4kx4k3.h"

int main()
{
    int m = 0, n = 0;
    while(m * n == 0)
    {
        // �j��m, n�n�j��0
        printf("m = ? ");
        scanf("%d",&m);
        printf("n = ? ");
        scanf("%d",&n);

        if(m <= 0 || n <= 0)
        {
            printf("Error \n");
            m = n = 0;
        }
    }

    if(m % 4 == 0 && n % 4 == 0)// 4k x 4k
    {
        BOARD *totalBoard;

        totalBoard = board_4kx4k(n, m);

        board_print(totalBoard);

        board_svg(totalBoard);

        return 0;
    }

    if(m % 4 == 0 && n % 4 == 2)// 4k x 4k2
    {
        BOARD *totalBoard;

        totalBoard = board_4kx4k2(n, m);

        board_print(totalBoard);

        board_svg(totalBoard);

        return 0;
    }

    if(m % 4 == 2 && n % 4 == 0)// 4k2 x 4k
    {
        BOARD *totalBoard;

        totalBoard = board_4k2x4k(n, m);

        board_print(totalBoard);

        board_svg(totalBoard);

        return 0;
    }

    if(m % 4 == 2 && n % 4 == 2)// 4k2 x 4k2
    {
        BOARD *totalBoard;

        totalBoard = board_4k2x4k2(n, m);

        board_print(totalBoard);

        board_svg(totalBoard);

        return 0;
    }

    /*
    if(m % 4 == 0 && n % 4 == 3)// 4k x 4k3
    {
        BOARD *totalBoard;

        totalBoard = board_4kx4k3(n, m);

        board_print(totalBoard);

        board_svg(totalBoard);

        return 0;
    }
    */
    BOARD *totalBoard;
    ROUTE *route, *maxRoute;

    totalBoard = board_create(n, m);
    route = route_create(0, 0, 0, BIG_L);
    board_addRoute(totalBoard, route);

    maxRoute = adam_dfsRoute(totalBoard);

    board_destory(totalBoard);

    totalBoard = board_create(n, m);

    board_addRoute(totalBoard, maxRoute);

    board_svg(totalBoard);

    return 0;
}
