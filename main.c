#include <stdio.h>
#include <string.h>

//defining piece data structure
struct piece{
    int team;
    char* class;
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

void move(){
    
}

//draw the board into the console
void buildBoard(){
    printf("    ");
    for (int i = 0; i < 8; i++){
        printf("\033[36m   %c",65+i);
    }

    printf("\033[0m");
    printf("\n");

    for (int i = 0; i < 8; i++){
        printf("\n");
        printf("\033[36m   %i\033[0m",i);

        for (int j = 0; j < 8; j++){
            if (board[i][j].team == 1){
                printf("\033[31m");
            }

            if (board[i][j].team == 2){
                printf("\033[34m");
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
        printf("\033[36m   %i\033[0m",i);
        printf("\n");
    }
    printf("\n    ");
    for (int i = 0; i < 8; i++){
        printf("\033[36m   %c",65+i);
    }

    printf("\033[0m\n");
}
//Main function
int main(){

    initiateBoard();
    buildBoard();

    return 0;
}