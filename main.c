#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "Tree.h"

int main() {
    srand(time(NULL));
    t_map map = createMapFromFile("..\\maps\\example1.map");
    printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%d ", map.soils[i][j]);
        }
        printf("\n");
    }
    // printf the costs, aligned left 5 digits
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%-5d ", map.costs[i][j]);
        }
        printf("\n");
    }
    displayMap(map);
    t_localisation init_loc;
    init_loc = loc_init(0,0,SOUTH);
    t_node Tree = createTree_nr(map,init_loc);
    printf("Valeur premier noeud %d",Tree.value);
    return 0;
}
