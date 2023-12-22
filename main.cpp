#include <iostream>
#include "BoardGame_Classes.hpp"
using namespace std;
int main() {
    int gamenum;
    re:
    cout << "Enter the number of the XO variation you want to play\n"
            "1- Pyramic\n"
            "2- Four in a row\n"
            "3- 5 X 5\n";
    cin >> gamenum;
    switch (gamenum) {
        case 1:{
            int choice;
            Player* players[2];
            players[0] = new Player (1, 'x');

            cout << "Welcome to FCAI X-O Game. :)\n";
            cout << "Press 1 if you want to play with computer: ";
            cin >> choice;
            if (choice != 1)
                players[1] = new Player (2, 'o');
            else
                //Player pointer points to child
                players[1] = new RandomPlayer ('o', 5);

            GameManager x (new Pyramic_x_o, players);
            x.run();
            system ("pause");
            break;}
        case 2:{
            int choice;
            Player* players[2];
            players[0] = new Player (1, 'x');

            cout << "Welcome to FCAI X-O Game. :)\n";
            cout << "Press 1 if you want to play with computer: ";
            cin >> choice;
            if (choice != 1)
                players[1] = new Player (2, 'o');
            else
                //Player pointer points to child
                players[1] = new RandomPlayer ('o', 7);

            GameManager x (new FourInRow, players);
            x.run();
            system ("pause");
            break;}
        case 3:{
            int choice;
            Player* players[2];
            players[0] = new Player (1, 'x');

            cout << "Welcome to FCAI X-O Game. :)\n";
            cout << "Press 1 if you want to play with computer: ";
            cin >> choice;
            if (choice != 1)
                players[1] = new Player (2, 'o');
            else
                //Player pointer points to child
                players[1] = new RandomPlayer ('o', 5);

            GameManager x (new Third_Game, players);
            x.which_manger= true;
            x.run();
            system ("pause");
            break;}
        default:
            cerr << "Wrong input\n";
            cerr.flush();
            goto re;
    }

}