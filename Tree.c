#include <stdlib.h>
#include <stdio.h>
#include "Tree.h"

t_node createTree_nr(){
    t_node *Tree = malloc(sizeof(t_node));
    Tree->value = 9;
    Tree->sons = malloc(9*sizeof(t_node));

    Tree->value = 9;
    Tree->nbSons = 9;
    Tree->sons = malloc(Tree->nbSons * sizeof(t_node*));

    for(int i=0; i<9;i++){
        Tree->sons[i] = malloc(sizeof(t_node));
        // segfault car tu essayes d'acceder a Tree->sons[i]->sons alors qu'il n'est pas encore malloc
        // Tree->sons[i]->sons = (t_node*)malloc(8*sizeof(t_node));
        Tree->sons[i]->sons = malloc(8 * sizeof(t_node*));
        for(int j=0; j<8;j++){
            Tree->sons[i]->sons[j] = malloc(sizeof(t_node));
            Tree->sons[i]->sons[j]->sons = malloc(7*sizeof(t_node*));
            for(int k=0; k<7;k++){
                Tree->sons[i]->sons[j]->sons[k] = malloc(sizeof(t_node));
                Tree->sons[i]->sons[j]->sons[k]->sons = malloc(6*sizeof(t_node*));
                for (int l = 0; l < 6; l++) {
                    Tree->sons[i]->sons[j]->sons[k]->sons[l] = malloc(sizeof(t_node));
                    Tree->sons[i]->sons[j]->sons[k]->sons[l]->sons = malloc(5*sizeof(t_node*));
                    for (int m = 0; m < 5; m++) {
                        Tree->sons[i]->sons[j]->sons[k]->sons[l]->sons[m] = malloc(sizeof(t_node));
                        Tree->sons[i]->sons[j]->sons[k]->sons[l]->sons[m]->sons = NULL;
                   }
                }
             }
         }
    }
    return *Tree;
}



