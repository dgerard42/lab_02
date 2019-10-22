/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   06_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/10/11 19:13:00 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/10/21 23:59:38 by dany              _/_/`           `'"`   */
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

void        runTest(int testNum, float result, float expected, float test){
    
    float result = squareroot(test);

    ">>TEST " << testNum << " for sqrt of " << test << ". expected result == " << expected
            << ". actual result == " << result << "." << endl;
    
    return;
}

int         main(){
   
    string name = "squareroot()";
    float result = 0.0;

    result = squareroot(394820.0);
    (result == 628.347046) ? (printResult(0, name, 0, result)) : (printResult(1, name, 0, result));
    result = squareroot(-42.0);
    (result == -1.0) ? (printResult(0, name, 1, result)) : (printResult(1, name, 1, result));
    result = squareroot(numeric_limits<float>::max());
    (result == 1.8446744e+19) ? (printResult(0, name, 2, result)) : (printResult(1, name, 2, result));
    result = squareroot(42);
    (result == 6.4807407) ? (printResult(0, name, 1, result)) : (printResult(1, name, 1, result));
    result = squareroot(121);
    (result == 11.0) ? (printResult(0, name, 1, result)) : (printResult(1, name, 1, result));

    return 0;
}
