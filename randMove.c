//
// Created by mathm on 24/10/2024.
//
#include <stdlib.h>
#include <time.h>
#include "randMove.h"
#include "loc.h"

t_localisation randMove(t_localisation *loc){

    srand(time(NULL));
    int MoveRand = rand() % 7;
    switch (MoveRand) {
        case 0:
            UP(loc->pos);
            break;
        case 1:
            UP(loc->pos);
            UP(loc->pos);
            break;
        case 2:
            UP(loc->pos);
            UP(loc->pos);
            UP(loc->pos);
            break;
    }

    return *loc;
}
