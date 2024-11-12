//
// Created by mathm on 24/10/2024.
//
#include "map.h"
#include "loc.h"
#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H

typedef struct Tree_nr{
    int value;
    struct Tree_nr **sons;
    int nbSons;
}t_node;

t_node createTree_nr(t_map map, t_localisation loc_init);

#endif //UNTITLED1_TREE_H
