/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   05_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/10/03 10:46:44 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/10/10 22:22:26 by dany              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

const int   NUM_COUNTERS = 10;
const float RANGE_LIMITS[NUM_COUNTERS] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
const int   MAX_HEIGHT = 50;

void        makeGraph(int counters[], string graph[]){

    int hashtags = 0;

    for (int row = NUM_COUNTERS - 1; row > 0; row--){
        cout << counters[row] << "HERE";
        hashtags = (counters[row] % 50);
        cout << hashtags << " here";
        graph[hashtags + 1][row] = '_';
        while (hashtags > 0) {
            graph[hashtags][row] = '#';
            hashtags--;
        }
    }
    return;
}

void        makeGraph(int counters[]

void        graphManage(string graph[], string command){
    
    for (int row = 0; row < MAX_HEIGHT; row++){
        for (int column = 0; column < NUM_COUNTERS; column++){
            if (command == "init")
                graph[row][column] = '.';
            else if (command == "print")
                cout << graph[row][column];
            }
        if (command == "print")
            cout << endl;
    }
    return;
}

void        createRandoms(int counters[]){
    
    int     randomNum = 0;
    float   randomDec = 0;
    
    srand (time(nullptr));
    for (int index = 0; index < 10000; index++){
        randomNum = rand() % 10000;
        randomDec = (float)randomNum / 10000;
        cout << randomDec << endl;
        randomNum %= 10;
        counters[randomNum]++;
    }
    return;
}

int         main(){
    
    int     counters[NUM_COUNTERS] = {0,0,0,0,0,0,0,0,0,0};
    string  graph[MAX_HEIGHT + 1];

    createRandoms(counters);
    graphManage(graph, "init");
    makeGraph(counters, graph);
    graphManage(graph, "print");
    return 0;
}
