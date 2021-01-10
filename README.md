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

### Complexité

Le projet est décomposé en 2 complexité.
- Complexité quadratique lors du parcours du plateau, qui est un tableau a 2 dimentions (8x8)
- Complexité linéaire pour la pluspart des autres fonctions

-La complexité de l'IA est constante