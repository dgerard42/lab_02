/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   06_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/10/11 19:13:00 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/10/11 19:21:32 by dany              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

int     sqrt(int number){
    
    float trying = number;

    cout << (int)trying << endl;
    return 0;
}

int     main(){
    
    int inputNumber;

    cout << "enter a number and ill calc the square root:" << endl;
    cin >> inputNumber;
    sqrt(inputNumber);
    return 0;
}
