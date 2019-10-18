/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   07_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/10/13 21:54:00 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/10/17 23:49:58 by dany              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

const int LEN_00 = 8;
const int LEN_01 = 6;
const int LEN_02 = 1;
const int LEN_03 = 3;
const int LEN_04 = 9;

/*
int         longestRun(int arr[], int arraySize){
    
    int     longestRun = 0;
    int     runValue = 0;
    
    for (int index = 0; index < arraySize; index++){
        
    }
    return longestRun;
}
*/

int         localMaxima(int arr[], int maxima[], int size){
    
    int     globalMax = INT_MIN;
    int     maximaIndex = 0;

    for (int index = 0; index < size; index++){
        if (((index - 1 < 0) || ((index - 1 >= 0) && (arr[index] > arr[index - 1]))) &&
            ((index + 1 >= size) || ((index + 1 < size) && (arr[index] > arr[index + 1])))){
                maxima[maximaIndex] = index;
                maximaIndex++;
        } if (arr[index] > INT_MIN) {
            globalMax = arr[index];
        }
    }
    return globalMax;
}

void        oddFirst(int arr[], int arraySize){

    int search = 0;
    int temp = 0;

    for (int index = 0; index < arraySize - 1; index++){
        search = index;
        while (arr[search] % 2 == 0 && search < arraySize - 1){
            search++;
        } if (arr[search] % 2 == 0) {
            index = arraySize;
        } else {
            temp = arr[search];
            arr[search] = arr[index];
            arr[index] = temp; 
        }
    }    
    return;           
}

void        reverse(int arr[], int arraySize){
    
    int     temp = 0;

    for(int index = 0; index < (arraySize / 2); index++){
        temp = arr[index];
        arr[index] = arr[(arraySize - 1) - index];
        arr[(arraySize - 1) - index] = temp; 
    }
}

int         search(int arr[], int n, int val, bool left){

    int index = (left == true) ? 0 : n - 1;

    while ((left == true) ? (index < n) : (index >= 0)){
        if (arr[index] == val)
            return index;
        (left == 1) ? (index++) : (index--);
    }
    return -1;
}

// TEST FUNCTIONS

void        printArray(int arr[], int arraySize){

    for (int index = 0; index < arraySize; index++){
        cout << arr[index] << " ";
    }
    cout << endl;
    return;
}

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
*/

void        testLocalMaxima(){
   
    string      name = "localMaxima()";
    int         arr00[] = {1,4,6,5,2,7,10,4};
    int         res00[] = {0,0,0,0,0,0,0,0};
    int         arr01[] = {0, -42, -985495, 1293812983, 00, 333333333};
    int         res01[] = {0, 0, 0, 0, 0, 0};
    int         arr02[] = {0};
    int         res02[] = {0};
    int         arr03[] = {3, 3, 3, 3, 3, 3, 3, 3, 3};
    int         res03[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int         arr04[] = {0,1,2,3,4,5,6,7,8};
    int         res04[] = {0,0,0,0,0,0,0,0,0};
    
    cout << "__________ " << name << " __________" << endl;
    cout << "_____ARRAY 00_____" << endl;
    printArray(arr00, LEN_00);
    localMaxima(arr00, res00, LEN_00);
    printArray(res00, LEN_00);    
    cout << "_____ARRAY 01_____" << endl;
    printArray(arr01, LEN_01);
    localMaxima(arr01, res01, LEN_01);
    printArray(res01, LEN_01);    
    cout << "_____ARRAY 02_____" << endl;
    printArray(arr02, LEN_02);
    localMaxima(arr02, res02, LEN_02);
    printArray(res02, LEN_02);   
    cout << "_____ARRAY 03_____" << endl;
    printArray(arr03, LEN_03);
    localMaxima(arr03, res03, LEN_03);
    printArray(res03, LEN_03);
    cout << "_____ARRAY 04_____" << endl;
    printArray(arr04, LEN_04);
    localMaxima(arr04, res04, LEN_04);
    printArray(res04, LEN_04);

    return;
} 

void        testOddFirst(){

    string      name = "oddFirst()";
    int         arr00[] = {1,4,6,5,2,7,10,4};
    int         arr01[] = {0, -42, -985495, 1293812983, 00, 333333333};
    int         arr02[] = {0};
    int         arr03[] = {3, 3, 3, 3, 3, 3, 3, 3, 3};
    int         arr04[] = {0,1,2,3,4,5,6,7,8};

    cout << "__________ " << name << " __________" << endl;
    cout << "_____ARRAY 00_____" << endl;
    printArray(arr00, 8);
    oddFirst(arr00, 8);
    printArray(arr00, 8);    
    cout << "_____ARRAY 01_____" << endl;
    printArray(arr01, 6);
    oddFirst(arr01, 6);
    printArray(arr01, 6);    
    cout << "_____ARRAY 02_____" << endl;
    printArray(arr02, 1);
    oddFirst(arr02, 1);
    printArray(arr02, 1);   
    cout << "_____ARRAY 03_____" << endl;
    printArray(arr03, 9);
    oddFirst(arr03, 9);
    printArray(arr03, 9);
    cout << "_____ARRAY 05_____" << endl;
    printArray(arr04, 9);
    oddFirst(arr04, 9);
    printArray(arr04, 9);

    return;
}

void        testReverse(){
    
    string      name = "reverse()";
    int         arr00[] = {1,4,6,5,2,7,10,4};
    int         arr01[] = {0, -42, -985495, 1293812983, 00, 333333333};
    int         arr02[] = {0};
    int         arr03[] = {3, 3, 3, 3, 3, 3, 3, 3, 3};
    int         arr04[] = {0,1,2,3,4,5,6,7,8};
    
    cout << "__________ " << name << " __________" << endl;
    cout << "_____ARRAY 00_____" << endl;
    printArray(arr00, 8);
    reverse(arr00, 8);
    printArray(arr00, 8);    
    cout << "_____ARRAY 01_____" << endl;
    printArray(arr01, 6);
    reverse(arr01, 6);
    printArray(arr01, 6);    
    cout << "_____ARRAY 02_____" << endl;
    printArray(arr02, 1);
    reverse(arr02, 1);
    printArray(arr02, 1);   
    cout << "_____ARRAY 03_____" << endl;
    printArray(arr03, 9);
    reverse(arr03, 9);
    printArray(arr03, 9);
    cout << "_____ARRAY 05_____" << endl;
    printArray(arr04, 9);
    reverse(arr04, 9);
    printArray(arr04, 9);

    return;
} 

void        testSearch(){

    string      name = "search()";
    int         arr00[] = {1,4,6,5,2,7,10,4};
    int         arr01[] = {0, -42, -985495, 1293812983, 00, 333333333};
    int         arr02[] = {0};
    int         arr03[] = {3, 3, 3, 3, 3, 3, 3, 3, 3};

    (search(arr00, 7, 6, true) == 2) ? printResult(0, name, 0) : printResult(1, name, 0);
    (search(arr00, 7, 6, false) == 2) ? printResult(0, name, 1) : printResult(1, name, 1);
    (search(arr00, 8, 8, true) == -1) ? printResult(0, name, 2) : printResult(1, name, 2);
    (search(arr00, 2, 5, true) == -1) ? printResult(0, name, 3) : printResult(1, name, 3);
    (search(arr00, 8, 4, true) == 1) ? printResult(0, name, 4) : printResult(1, name, 4);
    (search(arr00, 8, 4, false) == 7) ? printResult(0, name, 5) : printResult(1, name, 5);
    (search(arr01, 6, -42, false) == 1) ? printResult(0, name, 6) : printResult(1, name, 6);
    (search(arr01, 5, 1293812983, false) == 3) ? printResult(0, name, 7) : printResult(1, name, 7);
    (search(arr02, 1, 0, true) == 0) ? printResult(0, name, 8) : printResult(1, name, 8);
    (search(arr02, 1, 0, false) == 0) ? printResult(0, name, 9) : printResult(1, name, 9);
    (search(arr03, 9, 3, true) == 0) ? printResult(0, name, 10) : printResult(1, name, 10);
    (search(arr03, 9, 3, false) == 8) ? printResult(0, name, 11) : printResult(1, name, 11);
    (search(arr03, 6, 3, false) == 5) ? printResult(0, name, 12) : printResult(1, name, 12);

    return;
}

int         main(){
    
    testSearch();
    testReverse();
    testOddFirst();
    testLocalMaxima();
    //testLongestRun();
    return 0;
}
