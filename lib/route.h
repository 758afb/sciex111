#include "route.h"
#include <stdlib.h>
#include <stdio.h>

void route_destory(ROUTE *route)
{
    if (route->next)
    {
        route_destory(route->next);
        free(route->next);
        route->next = NULL;
    }
}

// �إ߷s�����u�� (x, y)
ROUTE *route_create(unsigned x, unsigned y, unsigned stepNo)
{
    ROUTE *route;

    route = malloc(sizeof(ROUTE));
    route->stepNo = stepNo;  // �� 1 �B
    route->x = x;
    route->y = y;

    return route;
}

// �L�X���u���y��
void route_print(ROUTE *route) {
    printf("#%d (%d, %d)\n", route->stepNo, route->x, route->y);
    if(route->next) {
        route_print(route->next);
    }
}

// ���u�[�J�U�@�B
ROUTE *route_next(ROUTE *route, unsigned x, unsigned y) {
    ROUTE *next = route_create(x, y, route->stepNo + 1);
    next->prev = route;
    route->next = next;

    return next;
}
