# Rover-Project

Description
Ce projet, réalisé dans le cadre du cours TI301 - Algorithmique et Structures de Données, vise à concevoir un logiciel pour guider le rover MARC (Mars Rover Cartograph) sur Mars. Le rover doit naviguer sur une carte martienne, éviter les obstacles, minimiser les coûts de déplacement, et atteindre une station de base.

Objectifs
Développer un algorithme pour guider MARC vers la station de base.
Gérer les mouvements aléatoires et les contraintes liées aux terrains martiens.
Optimiser le chemin de MARC en minimisant les coûts.
Utiliser des structures de données adaptées (piles, files, arbres N-aires) pour les calculs et la gestion des déplacements.
Caractéristiques Principales
1. Gestion des Localisations
Position et orientation : MARC se déplace sur un espace 2D avec des coordonnées (x, y) et une orientation (NORTH, SOUTH, EAST, WEST).
Fonctions clés :
loc_init(x, y, ori) : Initialise la localisation de MARC.
isValidLocalisation(pos, x_max, y_max) : Vérifie si une position est valide.
2. Carte Martienne
La carte est composée de cases représentant différents types de terrains :
Plaine : Mouvement normal.
Erg : Réduction des déplacements.
Reg : Limite les mouvements dans la phase suivante.
Crevasse : Terminaison du rover.
Fonctions clés :
createMapFromFile(filename) : Crée une carte à partir d'un fichier.
calculateCosts(map) : Calcule les coûts des cases en fonction de la distance et des terrains.
3. Déplacements
MARC peut effectuer les mouvements suivants :
Avancer de 10, 20, ou 30 m.
Reculer de 10 m.
Tourner à gauche, à droite, ou effectuer un demi-tour.
Fonctions clés :
move(loc, move) : Applique un mouvement.
randMove(loc) : Génère un mouvement aléatoire.
4. Structures de Données
Piles : Gèrent les séquences de mouvements.
Files : Optimisent le calcul des coûts.
Arbre N-aire : Modélise les différentes séquences de mouvements pour une phase et trouve le chemin optimal.
5. Optimisation
Construction et exploration d’un arbre N-aire pour choisir les mouvements qui minimisent le coût tout en respectant les contraintes.
