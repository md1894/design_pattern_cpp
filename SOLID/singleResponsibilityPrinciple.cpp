#include<boost/lexical_cast.hpp>
#include<fstream>
#include<bits/stdc++.h>
using namespace boost;
using namespace std;
// g++ -I /usr/local/boost_1_74_0/ singleResponsibilityPrinciple.cpp -o SRP

/*
ideally Journal class will have a primary responsibility of 
maintaining the entries
this is what , single responsibility principle is
*/

struct Journal{
    string title;
    vector<string> entries;
    Journal(const string& title):title(title){}

    void add_entry(const string& entry){
        static int count = 1;
        entries.push_back(lexical_cast<string>(count++) + " : " + entry);
    }

    /*
    now i added a new concern , persistance logic
    if there are many more classes like journal , like 10 different classes
    and in near future if i want to change the database/persistance logic
    so i have to update the save function in all the classes
    which is not a good practice

    so to prevent this phenomenon, we have to implement
    ********** separation of concerns **************
    */
    void save(const string& filename){
        fstream ofs(filename);
        for(auto i: entries)
            ofs << i << endl;
    }
};

// separation of concern ***** GOOD PRACTICE *****
struct PersistanceManager{
    // if i want to change persistance logic
    // i will only update this
    static void save(const string& filename, const struct Journal& j){
        fstream ofs(filename);
        for(auto i: j.entries)
            ofs << i << endl;
    }
};

void test(const struct Journal& journal){
    cout << journal.title << endl;
    for(auto i : journal.entries){
        cout << i << endl;
    }
}

int main(){
    struct Journal journal("mehul's diary");
    journal.add_entry("cpp");
    journal.add_entry("java");
    journal.add_entry("python");
    journal.add_entry("javascript");
    test(journal);
    // not a good practice to implement save/persistance logic in same class
    // journal.save("myFile.txt");

    // this is good practice
    PersistanceManager::save("myFile1.txt", journal);
    return 0;
}