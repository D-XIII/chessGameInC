# chessGameInC

### Credits

`Hugo Benard`
`Hugo Lebreton`
`Julien Anquetil`

### Idée initiale

- Possibilité de choisir 2 mode:
    - 2 joueurs: 1v1 classique
    - 1 joueur: Contre une IA

###### Problème rencontré

Lors de la création de l'IA, (énormément de boucle), nous avons rencontrer un problème Segfault, que nous avons pas réussi a résoudre en C.

### Projet actuel

Mode 1v1 uniquement.
Chaque joueur doit, à chaque tour, choisir le pion qu'il veut bouger (exemple: B,2), puis la position vers laquelle le pion va bouger (exemple: B,4).
La partie se fini lorsqu'un des rois est mort.

Le plateau est représenté par un tableau de 8 cases par 8 cases indiquant une structure de type piece. Une case vide est une strucure piece ayant une classe NULL.

Une boucle de la fonction main gère les tours des joueurs.
A chaque tour, le joueur se voit demandé le pion qu'il veut deplacer puis la destination de ce pion. Si la position est éronée (exemple : roi qui gouge de plus d'un case hors roque) le joueur se voit de nouveau demandé la position du pion et sa destination.

La foncion checkMove est appelée apres que le joueur precise la destination du pion séléctionné et verifie si le type de piece précisé peut effectuer une action demandée.
Elle est egalement appelée dans le code en C lors de la visualisation du plateau afin de colorer les mouvements possibles des pions que les joueurs selectionnent. 

La fonction getPos permet de retrouver la position d'une piece sur l'échiquier
### Complexité

Le projet est décomposé en 2 complexité.
- Complexité quadratique lors du parcours du plateau, qui est un tableau a 2 dimentions (8x8)
- Complexité linéaire pour la pluspart des autres fonctions

-La complexité de l'IA est constante