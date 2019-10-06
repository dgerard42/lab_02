/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   02_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/10/05 22:11:55 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/10/05 22:50:27 by dany              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

const int LETTERS = 26;
const int UPPERCASE_A = 65;
const int UPPERCASE_Z = 90;
const int LOWERCASE_A = 97;
const int LOWERCASE_Z = 122;
const int VOWEL = 1;
const int CONSONANT = 0;

int         main(){
    string  input = "null";
    int     index = 0;
    int     vowel_count = 0;
    int     consonant_count = 0;
    int     ascii = 0;
    int     alphabet[LETTERS + 1] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,2};


    cout << "Enter a string";
    cin >> input;
    while ( input[index] != '\0'){
        ascii = (int)input[index];
        if ( ascii >= UPPERCASE_A && ascii <= UPPERCASE_Z )
            ascii -= UPPERCASE_A;
        else if ( ascii >= LOWERCASE_A && ascii <= LOWERCASE_Z )
            ascii -= LOWERCASE_Z;
        else
            ascii = LETTERS;
        if ( alphabet[ascii] == VOWEL )
            consonant_count++;
        else if ( alphabet[ascii] == CONSONANT )
            vowel_count++; 
        index++;
    }
    cout << "The word " << input << " contains " << vowel_count << " vowels and " << consonant_count
            << " consonants." << endl;
}
