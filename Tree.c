#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Tree.h"
#include "randMove.h"
#include "map.h"
#include "loc.h"

t_node createTree_nr(t_map map, t_localisation loc_init){
    srand(time(NULL));
    t_node *Tree = malloc(sizeof(t_node));
    Tree->sons = malloc(9*sizeof(t_node));
    Tree->value = map.costs[loc_init.pos.x][loc_init.pos.y];
    Tree->nbSons = 9;
    Tree->sons = malloc(Tree->nbSons * sizeof(t_node*));
    t_localisation temp;
    t_localisation temp1;
    t_localisation temp2;
    t_localisation temp3;
    t_localisation temp4;
    for(int i=0; i<9;i++){
        Tree->sons[i] = malloc(sizeof(t_node));
        temp = randMove(loc_init);
        while (!isValidLocalisation(temp.pos,7,6)){
            temp = randMove(loc_init);
        }
        Tree->sons[i]->value = map.costs[temp.pos.x][temp.pos.y];
        Tree->sons[i]->sons = malloc(8 * sizeof(t_node*));
        for(int j=0; j<8;j++){
            Tree->sons[i]->sons[j] = malloc(sizeof(t_node));
            temp1 = randMove(temp);
            while (!isValidLocalisation(temp1.pos,7,6)){
                temp1 = randMove(temp);
            }
            Tree->sons[i]->sons[j]->value = map.costs[temp1.pos.x][temp1.pos.y];
            Tree->sons[i]->sons[j]->sons = malloc(7*sizeof(t_node*));
            for(int k=0; k<7;k++){
                Tree->sons[i]->sons[j]->sons[k] = malloc(sizeof(t_node));
                temp2 = randMove(temp1);
                while(!isValidLocalisation(temp2.pos,7,6)){
                    temp2 = randMove(temp1);
                }
                Tree->sons[i]->sons[j]->sons[k]->value = map.costs[temp2.pos.x][temp2.pos.y];
                Tree->sons[i]->sons[j]->sons[k]->sons = malloc(6*sizeof(t_node*));
                for (int l = 0; l < 6; l++) {
                    Tree->sons[i]->sons[j]->sons[k]->sons[l] = malloc(sizeof(t_node));
                    temp3 = randMove(temp2);
                    while(!isValidLocalisation(temp3.pos,7,6)){
                        temp3 = randMove(temp2);
                    }
                    Tree->sons[i]->sons[j]->sons[k]->sons[l]->value = map.costs[temp3.pos.x][temp3.pos.y];
                    Tree->sons[i]->sons[j]->sons[k]->sons[l]->sons = malloc(5*sizeof(t_node*));
                    for (int m = 0; m < 5; m++) {
                        Tree->sons[i]->sons[j]->sons[k]->sons[l]->sons[m] = malloc(sizeof(t_node));
                        temp4 = randMove(temp3);
                        while(!isValidLocalisation(temp4.pos,7,6)){
                            temp4 = randMove(temp3);
                        }
                        Tree->sons[i]->sons[j]->sons[k]->sons[l]->sons[m]->value = map.costs[temp4.pos.x][temp4.pos.y];
                        Tree->sons[i]->sons[j]->sons[k]->sons[l]->sons[m]->sons = NULL;
                   }
                }
             }
         }
    }
    return *Tree;
}



