// Class definition for X_O_Board class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
//#include "../include/BoardGame_Classes.hpp"
#include "BoardGame_Classes.hpp"
using namespace std;

// Set the board
Third_Game::Third_Game(){
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Third_Game::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

// Display the board and the pieces on it
void Third_Game::display_board() {
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool Third_Game::is_winner() {
    if (n_moves == 24 ) {
       for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 3; ++j) {
                if ((board[i][j] == board[i][j+1]) && (board[i][j+1] == board[i][j+2])){
                    if (board[i][j] == 'X')
                    {
                        this->countX++;
                    }
                    else if (board[i][j] == 'O')
                    {
                        this->countO++;
                    }
                }
            }
        }
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 3; ++j) {
                if ((board[j][i] == board[j+1][i]) && (board[j+1][i] == board[j+2][i])){
                    if (board[j][i] == 'X')
                    {
                        this->countX++;
                    }
                    else if (board[j][i] == 'O')
                    {
                        this->countO++;
                    }
                }
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if ((board[i][j] == board[i+1][j+1]) && (board[i+1][j+1] == board[i+2][j+2]))
                {
                    if (board[i][j] == 'X')
                    {
                        this->countX++;
                    }
                    else if (board[i][j] == 'O')
                    {
                        this->countO++;
                    }
                }
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 4; j > 1; --j) {
                if ((board[i][j] == board[i+1][j-1]) && (board[i+1][j-1] == board[i+2][j-2]))
                {
                    if (board[i][j] == 'X')
                    {
                        this->countX++;
                    }
                    else if (board[i][j] == 'O')
                    {
                        this->countO++;
                    }
                }
            }
        }
    }
    return false;
}

// Return true if 9 moves are done and no winner
    bool Third_Game::is_draw() {
        return (n_moves == 24 );
    }

    bool Third_Game::game_is_over() {
        return n_moves >= 24;
    }

