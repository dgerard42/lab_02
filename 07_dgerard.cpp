/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   07_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/10/13 21:54:00 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/10/16 21:44:20 by dany              _/_/`           `'"`   */
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

*/

void        oddFirst(int arr[], int arraySize){

    int temp = 0;

    for(int index = 0; index < arraySize; index++){
        if (arr[index] % 2 == 1){
            for (int search = 0; search < arraySize; search++){
                if (arr[search] % 2 == 1 && arr[index] <= arr[search]){
                    for (int shift = 0; (shift + index) < arraySize && (shift + search) < arraySize; shift++){
                        temp = arr[search + shift];
                        arr[search + shift] = arr[index + shift];
                        arr[index + shift] = temp;
                    } 
                }else if (arr[search] % 2 == 0){
                    temp = arr[search];
                    arr[search] = arr[index];
                    arr[index] = temp;
                }  
            }
        } 
    }
    return;
}

void        oddFirst(int arr[], int arraySize){

    i       
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

void        testLocalMaxima(){

    return;
} 

*/

void        testOddFirst(){

    string      name = "oddFirst()";
    int         arr00[] = {1,4,6,5,2,7,10,4};
    int         arr01[] = {0, -42, -985495, 1293812983, 00, 333333333};
    int         arr02[] = {0};
    int         arr03[] = {3, 3, 3, 3, 3, 3, 3, 3, 3};
    int         arr04[] = {0,1,2,3,4,5,6,7,8};

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
    //testLocalMaxima();
    //testLongestRun();
    return 0;
}
