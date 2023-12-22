#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
//#include "../include/BoardGame_Classes.hpp"
#include "BoardGame_Classes.hpp"
using namespace std;

// Set the board
Pyramic_x_o :: Pyramic_x_o () {
    n_rows =3;
    n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
    board[0][0]=1;
    board[0][1]=1;
    board[1][0]=1;
    board[0][3]=1;
    board[0][4]=1;
    board[1][4]=1;
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Pyramic_x_o::update_board (int x, int y, char mark){
    // Only update if move is valid
    if ((x >= 0 && x <= 2 && y >= 0 && y <= 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

// Display the board and the pieces on it
void Pyramic_x_o::display_board() {
    cout << "                   |(0,2)"<< setw(2) << board [0][2] << " |\n";
    cout << "-----------------------------------------------\n";
    cout << "          |(1,1)"<< setw(2) << board [1][1] << " |(1,2)" << setw(2) << board [1][2] << " |(1,3)" << setw(2) << board [1][3] << " |\n";
    cout << "-----------------------------------------------\n";
    cout << "| (2,0)" << setw(2) << board [2][0] << " |(2,1)" << setw(2) << board [2][1] << " |(2,2)" << setw(2) << board [2][2] << " |(2,3)" << setw(2) << board [2][3] << " |(2,4)" << setw(2) << board [2][4] << " |\n" ;
    cout << "-----------------------------------------------\n\n";
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool Pyramic_x_o::is_winner() {
    for (int i = 0; i < 3; ++i) {
        if((board[2][i]==board[2][i+1])&&(board[2][i+1]==board[2][i+2]) && board[2][i] != 0)
            return true;
    }
    if ((board[0][2] == board[1][1]) && (board[1][1]== board[2][0]) && board[2][0] != 0)
        return true;
    if ((board[0][2] == board[1][3]) && (board[1][3] == board[2][4]) && board[1][3] != 0)
        return true;
    if ((board[0][2] == board[1][2]) && (board[1][2] == board[2][2]) && board[0][2] != 0)
        return true;
    if ((board[1][1] == board[1][2]) && (board[1][2] == board[1][3]) && board[1][1] != 0)
        return true;
    return false;
}

// Return true if 9 moves are done and no winner
bool Pyramic_x_o::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool Pyramic_x_o::game_is_over () {
    return n_moves >= 9;
}
