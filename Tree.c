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

    for(int i=0; i<9;i++){
        Tree->sons[i] = malloc(sizeof(t_node));
        loc_init = randMove(loc_init);
        if(isValidLocalisation(loc_init.pos,7,6)){
            Tree->sons[i]->value = map.costs[loc_init.pos.x][loc_init.pos.y];
        }
        else{
            printf("%d,%d\n",loc_init.pos.x,loc_init.pos.y);
           printf("Position non valide\n");
        }
        Tree->sons[i]->sons = malloc(8 * sizeof(t_node*));
        for(int j=0; j<8;j++){
            Tree->sons[i]->sons[j] = malloc(sizeof(t_node));
            randMove(loc_init);
            if(isValidLocalisation(loc_init.pos,7,6)){
                Tree->sons[i]->sons[j]->value = map.costs[loc_init.pos.x][loc_init.pos.y];
            }
//            else{
//                printf("Position non valide");
//            }
            Tree->sons[i]->sons[j]->sons = malloc(7*sizeof(t_node*));
            for(int k=0; k<7;k++){
                Tree->sons[i]->sons[j]->sons[k] = malloc(sizeof(t_node));
                //randMove(loc_init);
                if(isValidLocalisation(loc_init.pos,7,6)){
                    Tree->sons[i]->sons[j]->sons[k]->value = map.costs[loc_init.pos.x][loc_init.pos.y];
                }
//                else{
//                    printf("Position non valide");
//                }
                Tree->sons[i]->sons[j]->sons[k]->sons = malloc(6*sizeof(t_node*));
                for (int l = 0; l < 6; l++) {
                    Tree->sons[i]->sons[j]->sons[k]->sons[l] = malloc(sizeof(t_node));
                    //randMove(loc_init);
                    if(isValidLocalisation(loc_init.pos,7,6)){
                        Tree->sons[i]->sons[j]->sons[k]->sons[l]->value = map.costs[loc_init.pos.x][loc_init.pos.y];
                    }
//                    else {
//                        printf("%d,%d\n",loc_init.pos.x,loc_init.pos.y);
//                        printf("Position non valide\n");
//                    }
                    Tree->sons[i]->sons[j]->sons[k]->sons[l]->sons = malloc(5*sizeof(t_node*));
                    for (int m = 0; m < 5; m++) {
                        Tree->sons[i]->sons[j]->sons[k]->sons[l]->sons[m] = malloc(sizeof(t_node));
                        //randMove(loc_init);
                        if(isValidLocalisation(loc_init.pos,7,6)){
                            Tree->sons[i]->sons[j]->sons[k]->sons[l]->sons[m]->value = map.costs[loc_init.pos.x][loc_init.pos.y];
                        }
//                        else{
//                            printf("Position non valide");
//                        }
                        Tree->sons[i]->sons[j]->sons[k]->sons[l]->sons[m]->sons = NULL;
                   }
                }
             }
         }
    }
    return *Tree;
}



