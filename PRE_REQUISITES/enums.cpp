#include<bits/stdc++.h>
using namespace std;

// simple enum type
/*
enums are used to just improve the readability of the code
internally they are nothing but some integer values
there are few drawback of this simple enum types
due to which we have to use enum class
*/

int main(){
    enum color {RED, BLUE, GREEN};
    enum color myColor = RED;
    if(myColor == GREEN){
        cout << "Value in myColor is GREEN";
    }else if(myColor == RED){
        cout << "Value in myColor is RED" << endl;
    }
    // RED--> 0, BLUE --> 1, GREEN--> 2
    // array like index values are assigned 
    cout << myColor << endl;

    enum animal {DOG=102, LION, CAT, ELEPHANT=50, HORSE};
    // enum variable
    enum animal myPet = DOG;

    cout << "value in myPet is " << myPet << endl;
    if(myPet == DOG){
        cout << "its a dog" << endl;
    }
    cout << "DOG=" << DOG << endl;
    cout << "LION=" << LION << endl;
    cout << "CAT=" << CAT << endl;
    cout << "ELEPHANT=" << ELEPHANT << endl;
    cout << "HORSE=" << HORSE << endl;
    return 0;
}