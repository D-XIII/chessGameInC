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

initiateBoard : parcours de tableau à deux dimension : complexité quadratique

getPos : parcours de tableau à deux dimension : complexité quadratique

Move : complexité lineaire qui appele des fonctions a complexité quadratique : compléxité quadratique

checkMove : parcours de tableau à deux dimension : complexité quadratique

buildBoard : pour chaque element d'un tableau a  deux dimension on appelle la fonction checkMove qui a ne complexité quadratique : complexité cubique

chosePos : complexité lineaire

checkWin : parcours de tableau à deux dimension : complexité quadratique

main : complexité lineaire qui appele toutes les fonctions du programme --> la complexité la plus haute est cubique : complexité cubique


=== fonction d'IA non implementé ===

countScore : parcours de tableau à deux dimension : complexité quadratique

eval : Pour chaque case d'un tableau on verifie que chaque mouvement vers les autres cases du plateau est possible : complexité cubique