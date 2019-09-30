#include <iostream>
#include <string>

using namespace std;

const int INCREASING_STAR_ROWS = 7;

void        print_stars(int rows)
{
    int stars = 1;
    for (int current_row = 0; current_row < (rows * 2); current_row++) //iterate through the rows 
    {
        for (int current_star = 0; current_star < stars; current_star++) //print out stars for current row
            cout << "*";
        cout << endl;
        if (current_row < rows)
            stars *= 2;                            //double stars for next row
        else
            stars /= 2;                            //halve stars for next row
    }
    return;
}

int         main()
{
    print_stars(INCREASING_STAR_ROWS - 1);  //subtracting 1 here to keep the const int STAR_ROWS true while also keeping
    return 0;                               //my for loops 0 indexed
}
