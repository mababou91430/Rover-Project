//
// Created by mathm on 24/10/2024.
//
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "randMove.h"
#include "loc.h"
#include "moves.h"

t_localisation randMove(t_localisation loc){
//    printf("%d,%d",loc.pos.x,loc.pos.y);
    int MoveRand = rand() % 7;
    printf("line %d MoveRand %d\n", __LINE__, MoveRand);
    switch (MoveRand) {
        case 0:
            printf("line %d\n", __LINE__);
            loc = move(loc,F_10);
            break;
        case 1:
            printf("line %d\n", __LINE__);

            loc = move(loc,F_20);
            break;
        case 2:
            printf("line %d\n", __LINE__);

            loc = move(loc,F_30);
            break;
        case 3:
            printf("line %d\n", __LINE__);

            loc = move(loc,B_10);
            break;
        case 4:
            printf("line %d\n", __LINE__);

            loc = move(loc,T_LEFT);
            break;
        case 5:
            printf("line %d\n", __LINE__);

            loc = move(loc,T_RIGHT);
            break;
        case 6:
            printf("line %d\n", __LINE__);

            loc = move(loc,U_TURN);
            break;
        default:
            break;
    }
//    printf("Après mouvement %d,%d\n",loc.pos.x,loc.pos.y);
    return loc;
}
