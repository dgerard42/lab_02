/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   07_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/10/13 21:54:00 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/10/13 23:29:18 by dany              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

/*
   
int         longestRun(int arr[], int arraySize){
    
    int     longestRun = 0;

    return longestRun;
}

int         localMaxima(int arr[], int maxima[], int size){
    
    int     globalMax = 0;

    return globalMax;
}

void        oddFirst(int arr[], int arraySize){
    
}

void        reverse(int arr[], int arraySize){

}

*/

int         search(int arr[], int n, int val, bool left){

    int index = (left == true) ? 0 : n;

    while ((left == true) ? (index < n) : (index > 0)){
        if (arr[index] == val)
            return index;
        (left == 1) ? (index++) : (index--);
    }
    return -1;
}

// TEST FUNCTIONS

void        printResult(int error, string name, int testNum){
    
    if (error == 1)
        cout << name << " has !!_FAILED_!! test " << testNum << endl;
    else if (error == 0)
        cout << name << " has ___PASSED___ test " << testNum << endl;
    return;
}

/*

void        testLongestRun(){
    
    return;
}

void        testLocalMaxima(){

    return;
} 

void        testOddFirst(){

    return;
}

void        testReverse(){
    
    return;
} 

*/

void        testSearch(){

    string      name = "search()";
    int         arr00[] = {1,4,6,5,2,7,10,4};
//    int       arr01[] = {0};

    (search(arr00, 7, 6, true) == 2) ? printResult(0, name, 0) : printResult(1, name, 0);
    (search(arr00, 7, 6, false) == 2) ? printResult(0, name, 1) : printResult(1, name, 1);

    return;
}

int         main(){
    
    testSearch();
    //testReverse();
    //testOddFirst();
    //testLocalMaxima();
    //testLongestRun();
    return 0;
}
