/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   06_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/10/11 19:13:00 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/10/22 00:08:17 by dany              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include <math.h>

using namespace std;

float       squareroot(float number){
    
    float   nextGuess = 1.0;
    float   lastGuess = 0.0;
    
    if (number < 0)
        return -1;
    while (nextGuess * nextGuess != number && abs(nextGuess - lastGuess) >= 0.00001){
        lastGuess = nextGuess;
        nextGuess = 0.5 * (lastGuess + (number/lastGuess));
    }
    return nextGuess;
}

void        runTest(int testNum, float input, float expected){
    
    float result = squareroot(input);

    cout <<">>TEST " << testNum << " for sqrt of " << input << ". expected result == "
            << expected << ". actual result == " << result << "." << endl;
    
    return;
}

int         main(){
   
    float result = 0.0;


    runTest(0, 394820.0, 628.347046); 
    runTest(1, -42, -1);
    runTest(2, numeric_limits<float>::max(), 1.8446744e+19);
    runTest(3, 42, 6.4807407);
    runTest(4, 121, 11);

    return 0;
}
