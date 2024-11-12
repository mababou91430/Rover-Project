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
    switch (MoveRand) {
        case 0:
            loc = move(loc,F_10);
            break;
        case 1:

            loc = move(loc,F_20);
            break;
        case 2:

            loc = move(loc,F_30);
            break;
        case 3:

            loc = move(loc,B_10);
            break;
        case 4:

            loc = move(loc,T_LEFT);
            break;
        case 5:

            loc = move(loc,T_RIGHT);
            break;
        case 6:

            loc = move(loc,U_TURN);
            break;
        default:
            break;
    }
//    printf("Après mouvement %d,%d\n",loc.pos.x,loc.pos.y);
    return loc;
}
