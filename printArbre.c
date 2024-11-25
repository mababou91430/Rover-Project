#include "printArbre.h"
#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>

void printTree(t_node * Tree) {
    printf("[Root | %d ] -> ",Tree->value);
    for(int i=0; i<9;i++){
        printf("[ %d | %d ] -> ",i,Tree->sons[i]->value);
        for(int j=0; j<8;j++){

            for(int k=0; k<7;k++){

                for (int l = 0; l < 6; l++) {

                    for (int m = 0; m < 5; m++) {













                    }
                }
            }
        }
    }
}
