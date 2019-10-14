/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   03_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/10/11 19:29:29 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/10/13 21:04:23 by dany              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

int        fibonacci(int sequencePosition){
    
    int sequenceValue = (sequencePosition == 0) ? 0 : 1;
    int index = 0;
    int previousValue = 0;

    while (index < sequencePosition - 1){
        sequenceValue = sequenceValue + previousValue;
        previousValue = sequenceValue - previousValue;
        index++;
    }
    if (sequencePosition < 0)
        sequenceValue = -1;
    return sequenceValue;
}

int         main(){
    
    int     sequencePosition = 0;
    int     sequenceValue = 0;
    
    cout << "enter a position in the fibonacci sequence to recieve a value:" <<
        endl;
    cin >> sequencePosition;
    sequenceValue = fibonacci(sequencePosition);
    if (sequenceValue == -1)
        cout << "error. invalid input. input must be positive." << endl;
    else {
        cout << "the number which is at " << sequencePosition << " in the fibbonacci" <<
        " sequence is " << sequenceValue << endl;
    }
    return 0;    
}
