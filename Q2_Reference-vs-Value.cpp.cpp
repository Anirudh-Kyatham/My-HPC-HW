/*  Nick Sweeting 2013/10/09
    References vs Values in C++
    MIT License
    Takes input and removes puctuation and spaces, using two different methods.
    It is referred from: https://github.com/pirate/Cpp-Data-Structures/
*/

#include <stdlib.h>
#include <iostream>
using namespace std;

// returns true if input character q is puctuation, else false
bool ispunctuation(char q) {
    // complete the functions here ...
    char punct[31] = ".!-_? <>,$#@=+*&^$!;:'()[]{}|`";
    for(char &ch : punct){
        if(ch == q){
            return true;
        }
    }
    return false;
}

char* modifyAndCopy(char *raw_input) {
    // complete the functions here ...
    char *chararr = new char[80];
    for(int i = 0, q = 0 ; i < 80; ++i){
        if(!ispunctuation(raw_input[i])){
            chararr[q++] = raw_input[i];
        }
    }
    return chararr;
}

char* modifyInPlace(char *raw_input) {
    // complete the functions here ...
    int  q = 0;
    for(int i = 0 ; i < 80; ++i){
        if(!ispunctuation(raw_input[i])){
            raw_input[q++] = raw_input[i];
        }
    }
    /*
    for (; q < 80; q++){
        raw_input[q] = '\0';
    }
    */
    return raw_input;
}

int main() {
    // user input
    char raw_input[80] = {0};
    cout << "Please input something with punctuation in it: ";
    cin.getline(raw_input,80);

    cout << "Modify and Copy: " << endl;
    cout << "Original: " << raw_input << endl;
    cout << "Modified: " << modifyAndCopy(raw_input) << endl << endl;

    cout << "Modify in Place: " << endl;
    cout << "Original: " << raw_input << endl;
    cout << "Modified: " << modifyInPlace(raw_input) << endl;
}