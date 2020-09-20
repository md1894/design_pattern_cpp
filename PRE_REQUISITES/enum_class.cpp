#include<bits/stdc++.h>
using namespace std;

/*
Enum Class
C++11 has introduced enum classes (also called scoped enumerations), 
that makes enumerations both strongly typed and strongly scoped. 
Class enum doesn’t allow implicit conversion to int, 
and also doesn’t compare enumerators from different enumerations.

To define enum class we use class keyword after enum keyword.
Syntax:
// Declaration
enum class EnumName{ Value1, Value2, ... ValueN};
// Initialisation
EnumName ObjectName = EnumName::Value;

Example:
// Declaration
enum class Color{ Red, Green, Blue};
// Initialisation
Color col = Color::Red;
*/

int main(){
    // Declaration
    enum class Color{ Red, Green, Blue};
    enum class Color1{Red, Black};
    // Initialisation
    Color col = Color::Red;
    Color1 col1 = Color1::Black;
    // if(col == Color1::Red){ // compile error for == operator
    //     cout << "type mismatch" << endl;
    // }
    if(col == Color::Red){
        cout << "yes its red" << endl;
    }
    if(col1 == Color1::Red){
        cout << "also red" << endl;
    }
    return 0;
}