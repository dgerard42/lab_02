/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   05_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/10/03 10:46:44 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/10/08 13:35:19 by dany              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

const int   NUM_COUNTERS = 10;
const float RANGE_LIMITS[NUM_COUNTERS] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};

void        printGraph(int counters[]){
   
    

    for (int index = 0; index < NUM_COUNTERS; index++){
        cout << counters[index] << endl; 
    }
    return;
}

void        create_randoms(int counters[]){
    
    int     random_num = 0;
    float   random_dec = 0;
    
    srand (time(NULL));
    for (int index = 0; index < 10000; index++){
        random_num = rand() % 10000;
        random_dec = (float)random_num / 10000;
        cout << random_dec << endl;
        random_num %= 10;
        counters[random_num]++;
    }
    return;
}

int         main(){
    
    int     counters[10] = {0,0,0,0,0,0,0,0,0,0};

    create_randoms(counters);
    print_graph(counters);
    return 0;
}
