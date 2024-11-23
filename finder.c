//
// Created by mathm on 19/11/2024.
//

#include "finder.h"
#include <stdlib.h>

int* pathFinder(t_node Tree){
    int* chemin = (int*) malloc(6*sizeof(int));
    int min0, min1, min2, min3, min4 = 99999;
    for(int i=0; i<9;i++) {
        if(Tree.sons[i]->value<min0){
            min0 = i;
        }
    }
    chemin[1] = min0;
    for(int j=0; j<8;j++) {
        if(Tree.sons[min0]->sons[j]->value<min1){
            min1 = j;
        }
    }
    chemin[2] = min1;
    for(int k=0; k<7;k++) {
        if(Tree.sons[min0]->sons[min1]->sons[k]->value){
            min2 = k;
        }
    }
    chemin[3] = min2;
    for (int l = 0; l < 6; l++) {
        if(Tree.sons[min0]->sons[min1]->sons[min2]->sons[l]->value<min3){
            min3 = l;
        }
    }
    chemin[4] = min3;
    for (int m = 0; m < 5; m++) {
        if(Tree.sons[min0]->sons[min1]->sons[min2]->sons[min3]->sons[m]->value<min4){
            min4 = m;
        }
    }
    chemin[5] = min4;
    chemin[0] = Tree.value;
    return chemin;
}