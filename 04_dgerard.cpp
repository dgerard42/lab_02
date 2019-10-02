#include <iostream>
#include <string>

using namespace std;

const int BOARD_SIZE = 15;
const int X = 1;
const int Y = 0;

void    put_beeper(char board[][BOARD_SIZE], int coords[])
{
    board[coords[Y]][coords[X]] = 'X';
}

void    pick_beeper(char board[][BOARD_SIZE], int coords[])
{
    board[coordsY][coords[X] = '.';
}

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
    cout << "#################" << endl;
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        cout << "#";
        for (int column = 0; column < BOARD_SIZE; column++)
        {
            if (column == coords[X] && row == coords[Y])
                cout << 'O';
            else
                cout << board[row][column];
        }
        cout << "#" << endl;
    }
    cout << "#################" << endl;
    return;
}

void    board_init(char board[][BOARD_SIZE])
{
    for (int row = 0; row < BOARD_SIZE; row++){
        for (int column = 0; column < BOARD_SIZE; column++){
            board[row][column] = '.';
        }
    }
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

int     cylce_karel()
{
    int error = 0;

    while (error == 0)
    {
        cin >> input;
        if (input == "move();")
            error = move(coords, direction);
        else if (input == "turnLeft();")
            direction = turn_left(direction);
        else if (input == )
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
        display_map(coords, board, direction);
    }
    return 0; 
}


int     main()
{
    int     coords[2] = {0,0};
    char    board[BOARD_SIZE][BOARD_SIZE];
    string  direction = "east";
    string  input = "startup";
    
    board_init(board);
    cout << ">>Hello, I am Karel v 0.1. Please enter a command: move();,";
    cout << " turnLeft();, or quit();" << endl;
    cylce_karel(coords, board);
    return 0;
}
