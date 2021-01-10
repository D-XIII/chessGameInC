#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//defining piece data structure
struct piece{
    int team;
    char* class;
    int posX;
    int posY;
    int plays;
    int pawnTrail;
    int teamTrail;
};
typedef struct piece piece;

//piece constructor
piece construct(int team, char* class){
    piece newPiece;
    newPiece.class=class;
    newPiece.team=team;
    newPiece.plays= 0;
    newPiece.pawnTrail = 0;
    newPiece.teamTrail = 0;
    return newPiece;
}
// defining game board
piece board[8][8];

//building the pieces and place them on the board
void initiateBoard(){
    for (int i = 0; i < 8; i++){//build pawn for blue and red team
    
        board[1][i]=construct(1,"pawn");
        board[6][i]=construct(2,"pawn");

    }

    //build rook for red team
    board[0][0]=construct(1,"rook");
    board[0][7]=construct(1,"rook");

    //build rook for blue team
    board[7][0]=construct(2,"rook");
    board[7][7]=construct(2,"rook");

    //build knight for red team
    board[0][1]=construct(1,"knight");
    board[0][6]=construct(1,"knight");
    
    //build knight for blue team
    board[7][1]=construct(2,"knight");
    board[7][6]=construct(2,"knight");

    //build bishop for red team
    board[0][2]=construct(1,"bishop");
    board[0][5]=construct(1,"bishop");

    //build bishop for blue team
    board[7][2]=construct(2,"bishop");
    board[7][5]=construct(2,"bishop");

    //build queen for red team
    board[0][3]=construct(1,"queen");

    //build queen for blue team
    board[7][3]=construct(2,"queen");
    
    //build king for red team
    board[0][4]=construct(1,"king");

    //build king for blue team
    board[7][4]=construct(2,"king");
}

int* getPos(piece* piece){
    static int temp[2];
    temp[0] = -1;
    temp[1] = -1;
    for (int x = 0; x < 8; x++){
        for (int y = 0; y < 8; y++){ 
            if (piece == &board[x][y]){
                temp[0] = x;
                temp[1] = y;
                return temp;
            }
        } 
    }
}

int checkMove(piece*  piece, int x, int y){

    int *pos = getPos(piece);
    int posX = pos[0];
    int posY = pos[1];
    int possible = 0;
    
    if (piece->class == "pawn")
    {
        int orientation;
        if (piece->team == 1){orientation = -1;}
        else{orientation = 1;}
        
        if((posX == x+1*orientation) && (posY == y) && board[x][y].team == 0){
            possible = 1;
        }

        if(posX == 3.5+2.5*orientation && posX == x+2*orientation && posY == y){
            possible = 1;
        }

        if(abs(posY-y) == 1 && posX == x +1*orientation && (board[x][y].team != 0 && board[x][y].teamTrail != piece->team && board[x][y].pawnTrail == 1)){
            possible = 1;
        }

    }
    
    if (piece->class == "bishop" || piece->class == "queen" && possible == 0){

        if (abs(posX-x) == abs(posY-y)){
            possible = 1;

            int checkX = posX;
            int checkY = posY; 
            while ((checkX != x || checkY != y) && possible == 1){

                if (posX<x){checkX++;}
                else{checkX--;}
                if (posY<y){checkY++;}
                else{checkY--;}

                int *tab = getPos(&board[checkX][checkY]);
                
                if (board[checkX][checkY].team != 0){
                    possible = 0;
                }
                if (&board[checkX][checkY] == &board[x][y] ){
                    possible = 1;
                }
            }
        }
    }

    if(piece->class == "rook" || piece->class == "queen" && possible == 0){
        if (posX == x && posY != y || posX != x && posY == y){

            possible = 1;

            int checkX = posX;
            int checkY = posY; 
            while ((checkX != x || checkY != y) && possible == 1 ){

                if (posX<x){checkX++;}
                if (posX>x){checkX--;}
                
                if (posY<y){checkY++;}
                if (posY>y){checkY--;}
                

                int *tab = getPos(&board[checkX][checkY]);
                
                if (board[checkX][checkY].team != 0 ){
                    possible = 0;
                }
                if (&board[checkX][checkY] == &board[x][y] ){
                    possible = 1;
                }
            }
        }
    }

    if (piece->class == "knight")
    {
        if ((abs(posX - x) == 1 && abs(posY - y) == 2) || (abs(posX - x) == 2 && abs(posY - y) == 1))
        {
            possible = 1;
        }
        
    }
    
    if (piece->class == "king")
    {
        if ((abs(posX - x) == 1 || posX == x) && (abs(posY - y) == 1 || posY == y))
        {
            possible = 1;
        }
        
    }

    if (piece->team == board[x][y].team)
    {
        possible = 0;
    }
    
    if (piece->class == "king" && piece->plays == 0 && board[x][y].plays == 0 && board[x][y].class == "rook" && board[x][y].team == piece->team){
        if (posX == x && posY != y || posX != x && posY == y){

            possible = 1;

            int checkX = posX;
            int checkY = posY; 

            while (checkY != y && possible == 1){
                if (posY<y){checkY++;}
                if (posY>y){checkY--;}

                if ( board[checkX][checkY].class != "rook" && board[checkX][checkY].team != 0){
                    possible = 0;
                }

                if (&board[checkX][checkY] == &board[x][y] && board[checkX][checkY].team == piece->team){
                    possible = 1;
                }
            }
        }
    }

    return possible;

}

//draw the board into the console
void buildBoard(piece* piece){
    printf("\n    ");
    for (int i = 0; i < 8; i++){
        printf("\033[36m   %c",65+i);
    }

    printf("\033[0m");
    printf("\n");

    for (int i = 0; i < 8; i++){
        printf("\n");
        printf("\033[36m   %i\033[0m",8-i);

        for (int j = 0; j < 8; j++){
            if (board[i][j].team == 1){
                printf("\033[31m");
            }

            if (board[i][j].team == 2){
                printf("\033[34m");
            }

            if (piece != NULL && checkMove(piece, i, j))
            {
                printf("\033[32m");

            }
            
            if (board[i][j].class == "pawn"){
                printf("   P");
            }
            if (board[i][j].class == "rook"){
                printf("   R");
            }
            if (board[i][j].class == "knight"){
                printf("   N");
            }
            if (board[i][j].class == "bishop"){
                printf("   B");
            }
            if (board[i][j].class == "queen"){
                printf("   Q");
            }
            if (board[i][j].class == "king"){
                printf("   K");
            }
            if (board[i][j].class == NULL){
                printf("   X");
            }
            printf("\033[0m");
        }
        printf("\033[36m   %i\033[0m",8-i);
        printf("\n");
    }
    printf("\n    ");
    for (int i = 0; i < 8; i++){
        printf("\033[36m   %c",65+i);
    }

    printf("\033[0m\n");
}

piece* choosePos(){
    char pos[3];
    scanf("%s", &pos);
    char *ptr = strtok(pos, ",");
    int x, y, temp, j = 0;

    while (ptr != NULL) {
        temp = (int)*ptr;
        if (temp >= 97) { temp -= 32; } // a => A
        if (temp >= 65) { temp -= 65; } // A => 0
        if (temp >= 49) { temp -= 49; } // 1 => 0

        if (j == 0) {
            y = temp;
        } else if (j == 1) {
            x = temp;
            x=7-x;
        }

        ptr = strtok(NULL, ",");
        j++;
    }

    return &board[x][y];
}

int countScore(piece board[][8]){

    int score = 0;

    for (int x = 0; x < 8; x++)
    {
        for (int y = 0; y < 8; y++)
        {
            int value = 0;
            if (board[x][y].class == "king")
            {
                value= 900;
            }
            if (board[x][y].class == "queen")
            {
                value= 90;
            }
            if (board[x][y].class == "rook")
            {
                value= 50;
            }
            if (board[x][y].class == "bishop")
            {
                value= 30;
            }
            if (board[x][y].class == "knight")
            {
                value= 30;
            }
            if (board[x][y].class == "pawn")
            {
                value= 10;
            }
            
            if (board[x][y].team == 2)
            {
                score += value;
            }
            else
            {
                score -= value;
            }
            
        }
        
    }

    return score;

}

char * eval(int depth){

    char* moves[8][8];

    for (int x = 0; x < 8; x++)
    {
        for (int y = 0; y < 8; y++)
        {
            if (board[x][y].team == 2)
            {
                for (int z = 0; z < 8; z++)
                {
                    for (int w = 0; w < 8; w++)
                    {
                        char* pieceMoves[8][8];

                        piece copieBoard[8][8];

                        for (int x = 0; x < 8; x++)
                        {
                            for (int y = 0; y < 8; y++)
                            {
                                copieBoard[x][y] = board[x][y];
                                if (checkMove(&board[x][y],z,w) == 1)
                                {   piece laPiece = copieBoard[x][y];
                                    piece target = copieBoard[z][w];

                                    target.class = laPiece.class;
                                    target.team = laPiece.team;
                                    target.plays = laPiece.plays;
                                    laPiece.class = NULL;
                                    laPiece.team = 0;
                                    
                                    // sprintf(countScore(copieBoard),"%d ", moves[x][y]);  
                                    // printf("%s",moves[x][y]);                      
                                } 
                            }
                        }

                        for (int i = 0; i < 8; i++)
                        {
                            for (int j = 0; j < 8; j++)
                            {
                                if (pieceMoves[i][j] > moves[x][y]){
                                    moves[x][y] = pieceMoves[z][w];
                                }
                            }
                        }

                    }
                }
            }
        }
    }
}

void move(int player, int gamemode) {

    piece* laPiece;
    piece* target;

    do
    {
        buildBoard(NULL);

        if (player == 1){
            printf("\033[31m");
        }
        else{
            printf("\033[34m");
        }
        printf("Joueur %d\033[0m : Entrer la position du pion que vous voulez bouger (ex: A,1): ", player);
        
        laPiece = choosePos();
        printf("Vous avez choisi le pion %s!\n", laPiece->class);
        if (laPiece->team != player) {
            printf("Ce n'est pas votre pion!\n");
        }
        
        buildBoard(laPiece);


        if (player == 1){
            printf("\033[31m");
        }
        else{
            printf("\033[34m");
        }
        printf("Joueur %d\033[0m : Vers quelle position voulez vous bouger cette piece ? (ex: A,1): ", player);
        target = choosePos();
        if(!checkMove(laPiece, getPos(target)[0], getPos(target)[1])) {
            printf("Cette position n'est pas valide!\n");
        }

    } while (laPiece->team != player || !checkMove(laPiece, getPos(target)[0], getPos(target)[1]));

    buildBoard(laPiece);

    if (laPiece->class == "pawn" && abs(getPos(target)[0]-getPos(laPiece)[0]) == 2){
        piece trailedPiece = board[(getPos(laPiece)[0]+getPos(target)[0])/2][(getPos(laPiece)[1])];
        trailedPiece.pawnTrail = 1;
        trailedPiece.teamTrail = laPiece->team;
    }

    if (laPiece->class == "pawn" && abs(getPos(target)[0]-getPos(laPiece)[0]) == 2){
        board[(getPos(laPiece)[0]+getPos(target)[0])/2][(getPos(laPiece)[1])].pawnTrail = 1;
    }

    if(target->pawnTrail == 1 && target->team != laPiece->team){

        piece empty = board[getPos(laPiece)[0]][(getPos(target)[1])];
        board[getPos(laPiece)[0]][(getPos(target)[1])].class = NULL;
        board[getPos(laPiece)[0]][(getPos(target)[1])].team = 0;
        board[getPos(laPiece)[0]][(getPos(target)[1])].pawnTrail = 0;
    }


    target->class = laPiece->class;
    target->team = laPiece->team;
    laPiece->plays ++;
    target->plays = laPiece->plays;
    laPiece->class = NULL;
    laPiece->team = 0;

    if(target->class == "pawn" && (getPos(target)[0] == 0 || getPos(target)[0] == 7)){

        char class;
        printf("votre pion a atteint la derniere rangee, choisissez sa nouvelle classe\nreine:\t\tq\nfou:\t\tb\ntour:\t\tr\ncavalier:\tn\nVotre choix:");
        scanf(" %c",&class);
        
        switch (class)
        {
        case 'q':
            target->class = "queen";
            break;
        case 'r':
            target->class = "rook";
            break;
        case 'b':
            target->class = "bishop";
            break;
        case 'n':
            target->class = "knight";
            break;
        default:
            break;
        }

    }
}

int checkWin(){

    int winOne = 1;
    int winTwo = 1;
    for (int x = 0; x < 8; x++)
    {
        for (int y = 0; y < 8; y++)
        {
            if (board[x][y].class == "king")
            {
                if(board[x][y].team == 1){
                    winTwo = 0;
                }
                if (board[x][y].team == 2)
                {
                    winOne = 0;
                }
            }
        }
    }

    if (winOne == 1)
    {
        return 1;
    }
    if (winTwo == 1)
    {
        return 2;
    }
    return 0;
    
    
}
//Main function
int main(){
    int gamemode = 2 ;
    // printf("Choisissez le mode de jeu:\n1 Joueur:\t1\n2 Joueurs:\t2\n");
    // scanf("%d",&gamemode);

    initiateBoard();

    int win = 0;

    int i = 0;
    while(win == 0) {
        move((i%2)+1,gamemode);
        i++;
        win = checkWin();
    }

    printf("Bravo au joueur %d, il remporte la partie!",win);

    return 0;
}