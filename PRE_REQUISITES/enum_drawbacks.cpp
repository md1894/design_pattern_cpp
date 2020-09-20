#include<bits/stdc++.h>
using namespace std;

/*
1. no two enums can have same names
    enum gender {MALE, FEMALE};
    enum gender2 {MALE, TRANSGENDER}; --> THROWS ERROR

2. no variable can have name which is declared in some
    enumeration(enum)
    enum gender {male, female};
    int male = 10; --> throws error

3. enums are not type safe
    enum color {RED, GREEN};
    enum size {SMALL, LARGE};
    enum color myColor = RED;
    myColor == SMALL --> gives true
*/

int main(){
    // enum gender {MALE, FEMALE};
    // enum gender2 {MALE, TRANSGENDER}; // compile error
    // enum gender {male, female};
    // int male = 10; // compile error
    enum color {RED, GREEN};
    enum size {SMALL, LARGE};
    enum color myColor = RED;
    if(myColor == SMALL){
        cout << "thats why its unsafe" << endl;
    }
    return 0;
}