#include <stdio.h>
#include "lib/route.h"
#include "lib/board.h"
#include "lib/board_4kx4k.h"

int main_2()
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

    if(m % 4 == 0 && n % 4 == 0)
    {
        BOARD *totalBoard;

        totalBoard = board_4kx4k(n, m);

        board_svg(totalBoard);
    }

    return 0;
}
