#include <stdio.h>     // Affichage (printf, fprintf)
#include <stdlib.h>    // Allocation mémoire (malloc, free), fonctions aléatoires
#include <time.h>      // Initialisation du générateur aléatoire

#include "map.h"       // Gestion des cartes
#include "loc.h"       // Gestion des localisations et positions
#include "moves.h"     // Déplacements de MARC
#include "randMove.h"  // Génération aléatoire de mouvements
#include "Tree.h"      // Gestion de l'arbre N-aire
#include "queue.h"     // Gestion des files (si nécessaire)


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
    printf("Valeur premier noeud %d\n",Tree.value);


    /* TEST de la fonction isAtBaseStation
    t_localisation loc;
    loc = loc_init(0,0,SOUTH);
    loc = move(loc, F_10);
    printf("Position de MARC : (%d, %d)\n", loc.pos.x, loc.pos.y);


    if (isAtBaseStation(map, loc)) {
        printf("MARC est arrive à la station de base !\n");
    } else {
        printf("MARC n'est pas encore arrive à la station de base.\n");
    }
    */

    /* TEST de la fonction IsOnCrevasse
    t_localisation loc;
    loc = loc_init(0,0,SOUTH);
    loc = move(loc, F_10);
    // Vérifier si MARC est sur une crevasse
    if (IsOnCrevasse(map, loc)) {
        printf("MARC est tombe dans une crevasse a (%d, %d) !\n", loc.pos.x, loc.pos.y);
        exit(1);
    }
    else
        (printf("Marc à survecu au deplacement"));
    */


    return 0;
}
