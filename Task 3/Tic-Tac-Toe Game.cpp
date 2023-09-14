#include<iostream>
#include<stdlib.h>
#define Player1 1
#define Player2 2
using namespace std;

//DISPLAYING BOARD AFTER EACH UPDATE
void displayBoard(char Board[3][3])
{
    cout<<"\n";
    cout<<"\t\t "<<Board[0][0]<<" | "<<Board[0][1]<<" | "<<Board[0][2]<<"\n";
    cout<<"\t\t"<<"---"<<"|"<<"---"<<"|"<<"---"<<"\n";
    cout<<"\t\t "<<Board[1][0]<<" | "<<Board[1][1]<<" | "<<Board[1][2]<<"\n";
    cout<<"\t\t"<<"---"<<"|"<<"---"<<"|"<<"---"<<"\n";
    cout<<"\t\t "<<Board[2][0]<<" | "<<Board[2][1]<<" | "<<Board[2][2]<<"\n";
    cout<<"\n\n";
}

//UPDATING THE TIC-TAC-TOE BOARD
void updateBoard(char Board[3][3], int choice, int turn)
{
    int move[]={0,1,2,3,4,5,6,7,8};
    int row,col;
    //CHOICE-1 AS ARRAY START FROM 0      ->012 345 678
    row = move[choice-1]/3;               //->000 111 222
    col = move[choice-1]%3;               //->012 012 012

    //UPDATING POSITION FOR 'X' IF NOT ALREADY FILLED
    if(turn == Player1 && Board[row][col] != 'X' && Board[row][col] != 'O'){
        Board[row][col] = 'X';
    }

    //UPDATING POSITION FOR 'O' IF NOT ALREADY FILLED
    else if(turn == Player2 && Board[row][col] != 'X' && Board[row][col] != 'O'){
        Board[row][col] = 'O';
    }

     //IF INPUT ALREADY FILLED
    else {
        cout<<"\nBox already filled!!\nPlease choose another cell: ";
        cin>>choice;
        //AGAIN TAKING CHOICE FROM USER AND CALLING UPDATE BOARD FUNCTION AGAIN
        updateBoard(Board,choice,turn);
    }

    displayBoard(Board);
}

//SHOWING INSTRUCTIONS IN THE BEGINING
void showInstructions()
{
    cout<<"\t\tTIC-TAC-TOE GAME\n";
    cout<<"\t\t----------------\n\n";
    cout<<"\tPLAYER-1: [X]\t PLAYER-2: [O]\n\n";
    cout<<">> INSTRUCTIONS: Choose a cell numbered from 1 to 9 as below and play!!\n\n";
    cout<<"\t\t "<<1<<" | "<<2<<" | "<<3<<"\n";
    cout<<"\t\t"<<"---"<<"|"<<"---"<<"|"<<"---"<<"\n";
    cout<<"\t\t "<<4<<" | "<<5<<" | "<<6<<"\n";
    cout<<"\t\t"<<"---"<<"|"<<"---"<<"|"<<"---"<<"\n";
    cout<<"\t\t "<<7<<" | "<<8<<" | "<<9<<"\n";
    cout<<"\n--\t--\t--\t--\t--\t--\t--";
    cout<<"\n\n";
}

//CHECKING IF ANY ROW IS FILLED WITH SAME PLAYER'S MOVE
bool rowCross(char Board[3][3])
{
    for(int row = 0; row < 3; row++){
        if(Board[row][0] != ' ' && Board[row][0] == Board[row][1] && Board[row][1] == Board[row][2])
            return true;
    }
    return false;
}

//CHECKING IF ANY COLUMN IS FILLED WITH SAME PLAYER'S MOVE
bool columnCross(char Board[3][3])
{
    for(int col = 0;col < 3; col++){
        if(Board[0][col] != ' ' && Board[0][col] == Board[1][col] && Board[1][col] == Board[2][col])
            return true;
    }
    return false;
}

//CHECKING IF ANY DIAGONAL IS FILLED WITH SAME PLAYER'S MOVE
bool diagonalCross(char Board[3][3])
{
        if(Board[0][0] != ' ' && Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2])
            return true;

        if(Board[0][2] != ' ' && Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0])
            return true;

        return false;
}

//CHECK ALL THE CONDITIONS OF GAME
bool gameOver(char Board[3][3])
{
    return (rowCross(Board) || columnCross(Board) || diagonalCross(Board));
}

//TIC-TAC-TOE BOARD IS OF 3X3 GRID AND IT CONTAINS TOTAL 9 SPACES
void playTicTacToe(int turn)
{
    char Board[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    int choice;
    //MOVEINDEX WILL TELL ALL THE SPACES ARE FILLED OR NOT
    int moveIndex = 0;

    while(gameOver(Board)==false && moveIndex!=9){
        if(turn == Player1){
            cout<<"\nPLAYER-1: [X] turn\n";
            cout<<"Enter cell number: ";
            cin>>choice;
            updateBoard(Board,choice,turn);
            moveIndex++;
            turn=Player2;
        }
        else if(turn == Player2){
            cout<<"\nPLAYER-2: [O] turn\n";
            cout<<"Enter cell number: ";
            cin>>choice;
            updateBoard(Board,choice,turn);
            moveIndex++;
            turn=Player1;
        }
    }

    //CHECKING FOR DRAW AND IF NOT DRAW THEN DECLARING WINNER
    if(gameOver(Board)==false && moveIndex==9){
        cout<<"It's a DRAW!!\n";
    }

    //TOGGLING THE USER TO DISPLAY ACTUAL WINNER
    else if (turn == Player1){
        turn = Player2;
        cout<<"PLAYER-2 has WON\n";
    }
    else if (turn == Player2){
        turn = Player1;
        cout<<"PLAYER-1 has WON\n";
    }
}

int main()
{
    char confirm;
    do{
        showInstructions();
        playTicTacToe(Player1);

    //IF PLAYERS WANT TO PLAY AGAIN
        cout<<"\nDo you want to continue?..(Y/y or N/n)\nConfirmation: ";
        cin>> confirm;
        cout<<"\n\n";
    }while( confirm == 'Y'|| confirm == 'y');
    cout<<"***********EXITING!!*********\n";
    cout<<"*************END*************\n\n";

    return 0;
}
