#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//defining piece data structure
struct piece{
    int team;
    char* class;
    int posX;
    int posY;
};
typedef struct piece piece;

//piece constructor
piece construct(int team, char* class){
    piece newPiece;
    newPiece.class=class;
    newPiece.team=team;
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

    // for (int x = 0; x < 8; x++)
    // {
    //     for (int y = 0; y < 8; y++)
    //     {
    //         board[x][y].posX = x+1;
    //         board[x][y].posY = 8-y;
    //         printf("%d %d; ", board[x][y].posX, board[x][y].posY);
    //     }
        
    // }

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

int checkPiece(int x, int y){
    int temp = 1;
    if (board[x][y].team==0){
        temp = 0;
    }
}

int checkMove(piece*  piece, int x, int y){
    int *pos = getPos(piece);
    int posX = pos[0];
    int posY = pos[1];
    int possible = 0;
    
    if (piece->class == "pawn")
    {
        int orientation = -1^piece->team;
        
    }
    

    if (piece->class == "bishop"){

        if (abs(posX-x) == abs(posY-y)){
            possible = 1;

            int checkX = posX;
            int checkY = posY; 
            while (checkX != x && possible == 1){

                if (posX<x){checkX++;}
                else{checkX--;}
                if (posY<y){checkY++;}
                else{checkY--;}

                int *tab = getPos(&board[checkX][checkY]);
                
                if (board[checkX][checkY].team != 0){
                    possible = 0;
                }
            }
        }
    }

    if (piece->team == board[x][y].team)
    {
        possible = 0;
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
            if (checkMove(piece, i, j))
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

void move(int player) {
    int posX,posY;
    if (player == 1){
        printf("\033[31m");
    }
    else{
        printf("\033[34m");
    }
    printf("Joueur %d\033[0m : Entrer la position du pion que vous voulez bouger (ex: A,1): ", player);

    piece* laPiece = choosePos();
    
    for (int x = 0; x < 8; x++)
    {
        for (int y = 0; y < 8; y++)
        {
            if (laPiece == &board[x][y])
            {
                int posX = x ;
                int posY = y ;
            }
            
        }
        
    }

    printf("Vous avez choisi le pion %s!\n", laPiece->class);
    printf("%d => %d\n", player, laPiece->team);
    if (laPiece->team == player) {
        printf("c'est votre pion\n");
    }
    else
    {
        printf("Ce n'est pas votre pion\n");
    }
    if (player == 1){
        printf("\033[31m");
    }
    else{
        printf("\033[34m");
    }
    printf("Joueur %d\033[0m : Vers quelle position voulez vous bouger cette piece ? (ex: A,1): ", player);
    buildBoard(laPiece);
    piece* target = choosePos();
    target->class = laPiece->class;
    target->team = laPiece->team;
    laPiece->class = NULL;
    laPiece->team = 0;
}

//Main function
int main(){
    piece *voidPiece;

    initiateBoard();
    buildBoard(voidPiece);

    int i = 0;
    while(1) {
        move((i%2)+1);
        i++;
        buildBoard(voidPiece);
    }

    return 0;
}