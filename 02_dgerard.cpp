/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   02_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/10/05 22:11:55 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/10/08 11:32:25 by dany              _/_/`           `'"`   */
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
const int CONSONANT = 0;         //a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,non-letter
const int ALPHABET[LETTERS + 1] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,2};

void        countVowels(string &input, int &vowelCount, int &consonantCount){

    int     index = 0;
    int     ascii = 0;

    while ( input[index] != '\0'){
        ascii = (int)input[index];        //convert each letter to its ascii character
        if ( ascii >= UPPERCASE_A && ascii <= UPPERCASE_Z ) //if the letter is uppercase
            ascii -= UPPERCASE_A;                           //convert to a corresponding number 0-25
        else if ( ascii >= LOWERCASE_A && ascii <= LOWERCASE_Z )//if the letter is lowercase
            ascii -= LOWERCASE_A;                               //convert to corresponding number 0-25
        else
            ascii = LETTERS;                                    //else assign ascii with 2, the designated non character number
        if ( ALPHABET[ascii] == VOWEL )                    //if the letter is a vowel (represented by 1 in alphabet array)
            vowelCount++;                                 //count that vowel
        else if ( ALPHABET[ascii] == CONSONANT )           //else if the letter is a consonant (represented by 0 in alpha array)
            consonantCount++;                             //count that consonant
        index++;
    }
    return;
}

int         main(){

    string  input = "null";
    int     vowelCount = 0;
    int     consonantCount = 0;
   
    cout << "Enter a string:" << endl;
    cin >> input;
    countVowels(input, vowelCount, consonantCount);
    cout << "The word " << input << " contains " << vowelCount << " vowels and " << consonantCount
        << " consonants." << endl;
    return 0;
}
