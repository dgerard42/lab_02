#include <iostream>
#include <string>

using namespace std;

const int BOARD_SIZE = 15;
const int X = 1;
const int Y = 0;

string  turn_left(string karelFacing)
{
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

void    display_map(int coords[], char board[][BOARD_SIZE], string direction)
{
    cout << ">>Karel is at x=" << coords[X] << " y=" << coords[Y];
    cout << " and they are facing " << direction << "." << endl;
    cout << "###############" << endl;
    for (int row; row < BOARD_SIZE; row++)
    {
        cout << "#";
        for (int column; column < BOARD_SIZE; column++)
        {
            cout << "";
        }
        cout << "#";
    }
    cout << "###############" << endl;
    return;
}

void    board_init(char board[][BOARD_SIZE], int coords[])
{
    for (int row; row < BOARD_SIZE; row++)
        for (int column; column < BOARD_SIZE; column++)
            board[row][column] = '.';
    board[coords[1]][coords[0]] = 'O';
    cout << ">>Hello, I am Karel v 0.1. Please enter a command: move();,";
    cout << " turnLeft();, or quit" << endl;
}

int     move(int coords[], string direction)
{
    if (direction == "east")
        coords[X]++;
    else if (direction == "west")
        coords[X]--;
    else if (direction == "north")
        coords[Y]++;
    else if (direction == "south")
        coords[Y]--;
    if (coords[X] >= BOARD_SIZE || coords[Y] < 0 || coords[X] >= BOARD_SIZE || coords[Y] < 0)
    {
        cout << ">>ouch. I have crashed. shutting down" << endl;
        return 1;
    }
    return 0;
}

int     main()
{
    int     error = 0;
    int     coords[2] = {0,0};
    char    board[BOARD_SIZE + 1][BOARD_SIZE + 1];
    string  direction = "east";
    string  input = "startup";

    board_init(board);
    while (error == 0)
    {
        cin >> input;
        if (input == "move();")
            error = move(coords[], direction);
        else if (input == "turnLeft();")
            direction = turn_left(direction);
        else if (input == "quit();")
        {
            cout << ">>goodbye friend" << endl;
            break;
        }
        else
        {
            cout << ">>Please enter one of the valid commands, which are as";
            cout << " follows: move();, turnLeft();, quit();" << endl;
        }
        display_map(karelRow, karelColumn, direction);
    }
    return 0;
}
