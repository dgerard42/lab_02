/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   04_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/10/03 10:30:36 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/10/03 11:02:35 by dany              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

const int BOARD_SIZE = 15;
const int X = 1;
const int Y = 0;

string  turnLeft(string karelFacing){
    
    if (karelFacing == "east")
        return "north";
    else if (karelFacing == "north")
        return "west";
    else if (karelFacing == "west")
        return "south";
    else if (karelFacing == "south")
        return "east";
    return "error";
}

void    displayMap(int coords[], char board[][BOARD_SIZE], string direction){
    
    cout << ">>Karel is at x=" << coords[X] << " y=" << coords[Y];
    cout << " and they are facing " << direction << "." << endl;
    cout << "#################" << endl;
    for (int row = BOARD_SIZE - 1; row >= 0; row--){
        cout << "#";
        for (int column = 0; column < BOARD_SIZE; column++){
            if (column == coords[X] && row == coords[Y] && board[row][column] == 'X')
                cout << '@';
            else if (column == coords[X] && row == coords[Y])
                cout << 'O';
            else
                cout << board[row][column];
        }
        cout << "#" << endl;
    }
    cout << "#################" << endl;
    return;
}

void    boardInit(char board[][BOARD_SIZE]){
    
    for (int row = 0; row < BOARD_SIZE; row++){
        for (int column = 0; column < BOARD_SIZE; column++){
            board[row][column] = '.';
        }
    }
    return;
}

int     move(int coords[], string direction){
    
    if (direction == "east")
        coords[X]++;
    else if (direction == "west")
        coords[X]--;
    else if (direction == "north")
        coords[Y]++;
    else if (direction == "south")
        coords[Y]--;
    if (coords[X] >= BOARD_SIZE || coords[Y] < 0 || coords[X] >= BOARD_SIZE || coords[Y] < 0){
        cout << ">>ouch. I have crashed. shutting down" << endl;
        return 1;
    }
    return 0;
}

void     cycleKarel(int coords[], char board[][BOARD_SIZE]){
    
    int     error = 0;
    string  direction = "east";
    string  input = "startup";

    while (error == 0){
        cin >> input;
        if (input == "move();")
            error = move(coords, direction);
        else if (input == "turnLeft();")
            direction = turnLeft(direction);
        else if (input == "putBeeper();")
            board[coords[Y]][coords[X]] = 'X';
        else if (input == "pickBeeper();")
            board[coords[Y]][coords[X]] = '.';
        else if (input == "quit();"){
            cout << ">>goodbye friend" << endl;
            break;
        }
        else {
            cout << ">>Please enter one of the valid commands, which are as";
            cout << " follows: move();, turnLeft();, quit();" << endl;
        }
        displayMap(coords, board, direction);
    }
    return; 
}


int     main()
{
    int     coords[2] = {0,0};
    char    board[BOARD_SIZE][BOARD_SIZE];
    
    boardInit(board);
    cout << ">>Hello, I am Karel v 0.1. Please enter a command: move();,";
    cout << " turnLeft();, or quit();" << endl;
    cycleKarel(coords, board);
    return 0;
}
