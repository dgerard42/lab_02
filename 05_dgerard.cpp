/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   05_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/10/03 10:46:44 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/10/15 10:57:56 by dany              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

const int   NUM_COUNTERS = 10;
const float RANGE_LIMITS[NUM_COUNTERS] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
const int   MAX_HEIGHT = 50;


void        makeGraph(int counters[], string graph[]){

    int     hashtags = 0;
    int     index = 0;

    for (int row = 2; row < (NUM_COUNTERS * 5); row += 5){ //iterating through all of the positions where I want to put columns
        hashtags = (counters[index] / MAX_HEIGHT);         //turn counters into their relative values
        graph[(MAX_HEIGHT - hashtags) - 1][row] = '_';      //place a '_' at the top of every bar
        cout << "hashtags vs. counters == " << hashtags << " vs. " << counters[index] << endl;
        while (hashtags > 0) {                              //for each hashmark needed to make the bar
            graph[MAX_HEIGHT - hashtags][row] = '#';        //place # in the center of the bar
            graph[MAX_HEIGHT - hashtags][row - 1] = '|';    //place | on either side of the bar
            graph[MAX_HEIGHT - hashtags][row + 1] = '|';
            hashtags--;
        }
        index++;
    }
    return;
}

void        graphManage(string graph[], string command){
    
    for (int row = 0; row < MAX_HEIGHT; row++){
            if (command == "init")
                graph[row] = "..................................................";
            else if (command == "print")
                cout << graph[row];
        if (command == "print")
            cout << endl;
    }
    return;
}

void        createRandoms(int counters[]){
    
    int     randomNum = 0;
    float   randomDec = 0;
    
    srand (time(nullptr));
    for (int index = 0; index < 10000; index++){ //for each random number which must be generated
        randomNum = rand() % 10000;              //generate a number between 0 & 10000
        randomDec = (float)randomNum / 10000;   //convert that number to a decimal between 0 & 1
        cout << randomDec << endl;              
        randomNum %= 10;                        //take the whole number version of that decimal and make it a number between 0 and 9
        counters[randomNum]++;                  //go the counter at that index and add one
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
