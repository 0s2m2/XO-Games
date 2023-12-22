#include <iostream>
#include <iomanip>
#include"BoardGame_Classes.hpp"
using namespace std;
FourInRow::FourInRow() {
    n_rows = 6;
    n_cols = 7;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
bool FourInRow::update_board (int x, int y, char mark){
    int j=5;
    if (!( y < 0 || y > 6)) {
        while(board[j][y]!=0 && j>0){
            j--;
        }
        if(j==0 && board[j][y]!=0){
            cout << "This column is FULL\n";
            return false;
        }
        else{
            board[j][y] = toupper(mark);
            n_moves++;
            return true;}
    }
    else
        return false;
}

void FourInRow::display_board() {
    for (int i = 0; i < 6; ++i) {
        cout << "\n| ";
        for (int j = 0; j < 7; ++j) {
            cout << "(" << i << "," << j << ")";
            cout << "  " << board [i][j] << " |";
        }
        cout << "\n------------------------------------------------------------------------";
    }
    cout << endl;
}


bool FourInRow::is_winner(){
    return (chk_rows() or chk_columns() or chk_diags());
}
bool FourInRow::game_is_over(){
    return n_moves >= 42;
}
bool FourInRow::is_draw(){
    return (n_moves == 42 && !is_winner());
}

bool FourInRow::chk_rows() { // Utility function to assess rows winning conditions.
    for (int i : {0,1,2,3,4,5}) {
        for (int j :{0,1,2,3}) {
            if(board[i][j]=='X' || board[i][j]=='O'){
                if (board[i][j] == board[i][j + 1] &&
                    board[i][j] == board[i][j + 2] &&
                    board[i][j] == board[i][j + 3]) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool FourInRow::chk_columns() { // Utility function to assess columns winning conditions.
    for (int i : {0,1,2}) {
        for (int j : {0,1,2,3,4,5,6}) {
            if (board[i][j] == 'X' || board[i][j] == 'O') {
                if (board[i][j] == board[i + 1][j] &&
                    board[i][j] == board[i + 2][j] &&
                    board[i][j] == board[i + 3][j]) {
                    return true;
                }
            }
        }
    }
    return false;
}


bool FourInRow::chk_diags() { // Utility function to assess diagonal winning conditions.
    for (int i : {0,1,2}) {
        for (int j: {0, 1, 2, 3}) {
            if (board[i][j] == 'X' || board[i][j] == 'O') {
                if (board[i][j] == board[i + 1][j + 1] &&
                    board[i][j] == board[i + 2][j + 2] &&
                    board[i][j] == board[i + 3][j + 3])
                    return true;
            }

            if (board[i][j+3] == 'X' || board[i][j+3] == 'O') {  // Examine diagonals from the right to the left.
                if (board[i][j + 3] == board[i + 1][j + 2] &&
                    board[i][j + 3] == board[i + 2][j + 1] &&
                    board[i][j + 3] == board[i + 3][j])
                    return true;
            }
        }
    }

    return false;
}
