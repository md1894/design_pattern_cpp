#include<bits/stdc++.h>
using namespace std;

struct demo{
    int a;
    int b;
    /// i can create constructor in structure cpp
    /// a(A) means , member a is initialised with A
    /// known as initializer list
    demo(int A, int B):a(A),b(B){
        cout << "constructor called" << endl;
    }
    /// it can also have a destructor 
    ~demo(){
        cout<<"destructor called" << endl;
    }
};

int main(){
    struct demo d(10,20);
    cout << d.a << ":" << d.b << endl;
    return 0;
}