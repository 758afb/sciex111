#include <stdio.h>
#include "lib/route.h"
#include "lib/board.h"
#include "lib/board_4kx4k.h"
#include "lib/board_4k2x4k.h"
#include "lib/board_4kx4k2.h"
#include "lib/board_4k2x4k2.h"

int main()
{
    int m = 0, n = 0;
    while(m * n == 0)
    {
        // �j��m, n�n�j��0
        printf("�п�Jm(��)�G");
        scanf("%d",&m);
        printf("�п�Jn(�e)�G");
        scanf("%d",&n);

        if(m <= 0 || n <= 0)
        {
            printf("(m, n)�ݬ�����\n");
            m = n = 0;
        }
    }

    if(m % 4 == 0 && n % 4 == 0)// 4k x 4k
    {
        BOARD *totalBoard;

        totalBoard = board_4kx4k(m, n);

        board_print(totalBoard);

        board_svg(totalBoard);
    }

    if(m % 4 == 0 && n % 4 == 2)// 4k x 4k2
    {
        BOARD *totalBoard;

        //totalBoard = board_4kx4k2(m, n);

        board_print(totalBoard);

        board_svg(totalBoard);
    }

    if(m % 4 == 2 && n % 4 == 0)// 4k2 x 4k
    {
        BOARD *totalBoard;

        //totalBoard = board_4k2x4k(m, n);

        board_print(totalBoard);

        board_svg(totalBoard);
    }

    if(m % 4 == 2 && n % 4 == 2)// 4k2 x 4k2
    {
        BOARD *totalBoard;

        //totalBoard = board_4k2x4k2(m, n);

        board_print(totalBoard);

        board_svg(totalBoard);
    }

    /*
    if(m % 4 == 2 && n % 4 == 1)// (4k+2) x (4k+1)
    {
        BOARD *totalboard;

        totalboard = board_4k2x4k1(m, n);

        board_print(totalboard);
    }
    */

    return 0;
}
