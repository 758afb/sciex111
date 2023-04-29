#ifndef __ROUTE_H__
#define __ROUTE_H__

// �@�Ӹ��u���c
typedef struct ROUTE ROUTE;

struct ROUTE
{
    // �����u�� next ���V�U�@�B�����u, ²�满�N�O�� LinkedList ��Ƶ��c
    ROUTE *next;
    // �����u�� prev ���V�e�@�B�����u, �Ω�L���i�����ɭԩ��e�j�M
    ROUTE *prev;

    // x, y �N��ثe���u�ϥΨ쪺�y��, �n�P�ѽL�y�Шt�t�X�~��o���L�A�ѽL�W���@���a�}
    int x;
    int y;

    // �ĴX�B
    unsigned stepNo;
};

// �M�����u
void route_destory(ROUTE *route);

// �إ߷s�����u�� (x, y)
ROUTE *route_create(unsigned x, unsigned y, unsigned stepNo);

// �L�X���u���y��
void route_print(ROUTE *route);

// ���u�[�J�U�@�B
ROUTE *route_next(ROUTE *route, unsigned x, unsigned y);

#endif
