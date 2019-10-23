/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   06_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/10/11 19:13:00 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/10/22 12:35:37 by dany              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include <math.h>

using namespace std;
void        angryGoose(){

    cout << "squareroots of negative numbers are not real and cannot be calculated"
        << " by this program. also, negative numbers make the goose angry. try again"
       << " with a positive number next time." << endl; 
    cout << "                                                        _...--." << endl;
    cout << "                                        _____......----'     .'" << endl;
    cout << "                                  _..-''                   .'" << endl;
    cout << "                                .'                       ./" << endl;
    cout << "                        _.--._.'                       .' |" << endl;
    cout << "                     .-'                           .-.'  /" << endl;
    cout << "                   .'   _.-.                     .  \\   '" << endl;
    cout << "                 .'  .'   .'    _    .-.        / `./  :" << endl;
    cout << "               .'  .'   .'  .--' `.  |  \\  |`. |     .'" << endl;
    cout << "            _.'  .'   .' `.'       `-'   \\ / |.'   .'" << endl;
    cout << "         _.'  .-'   .'     `-.            `      .'" << endl;
    cout << "       .'   .'    .'          `-.._ _ _ _ .-.    :" << endl;
    cout << "      /    /o _.-'     HONK      .--'   .'   \\   |" << endl;
    cout << "    .'-.__..-'                  /..    .`    / .'" << endl;
    cout << "  .'   . '                       /.'/.'     /  |" << endl;
    cout << " `---'                                   _.'   '" << endl;
    cout << "                                       /.'    .'" << endl;
    cout << "                                        /.'/.'" << endl;

    return;
}

float       squareroot(float number){
    
    float   nextGuess = 1.0;
    float   lastGuess = 0.0;
    
    if (number < 0){
        angryGoose();
        return -1;
    } else if (number == 0){
        return 0;       
    } while (nextGuess * nextGuess != number && abs(nextGuess - lastGuess) >= 0.00001){
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
    runTest(5, 0, 0);

    return 0;
}
