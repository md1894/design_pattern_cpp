#include<bits/stdc++.h>
using namespace std;

enum class Color {red, green, blue};
enum class Size {small, medium, large};

struct Product{
    string name;
    Color color;
    Size size;
};

struct ProductFilter{

    vector<Product*> by_size(vector<Product*>& items, Size size){
        vector<Product*> result;
        for(auto& i: items){
            if(i->size == size){
                result.push_back(i);
            }
        }
        return result;
    }

    /*
    lets say there is a requirement of another filter by_color
    so what you will do you add some code in the same existing class
    which is not recommended as per this principle
    */
    vector<Product*> by_color(vector<Product*>& items, Color color){
        vector<Product*> result;
        for(auto& i: items){
            if(i->color == color){
                result.push_back(i);
            }
        }
        return result;
    }

    vector<Product*> by_color_and_size(vector<Product*>& items, Color color, Size size){
        vector<Product*> result;
        for(auto& i: items){
            if(i->color == color && i->size == size){
                result.push_back(i);
            }
        }
        return result;
    }
};

/*
open close principle::
“Software entities (classes, modules, functions, etc.) 
 should be open for extension, but closed for modification.”
 in the above example we are modifying the existing code as the requirement comes

 to implement the open close principle we will define 2 interfaces
*/

template<typename T> struct Specification{
    virtual bool is_satisfied(T* item) = 0;

    // AndSpecification<T> operator&&(Specification<T>&& other){
    //     return AndSpecification<T>(*this, other);
    // }

};

template<typename T> struct Filter{
    virtual vector<T*> filter(vector<T*> items, Specification<T> &spec) = 0;
};

struct BetterFilter : Filter<Product>{
    vector<Product*> filter(vector<Product*> items, Specification<Product> &spec) override {
        vector<Product*> result;
        for(auto& item: items){
            if(spec.is_satisfied(item)){
                result.push_back(item);
            }
        }
        return result;
    }
};

struct ColorSpecification : Specification <Product>{
    Color color;

    ColorSpecification(Color color):color(color){}

    bool is_satisfied(Product* item) override{
        return item->color == color;
    }
};

struct SizeSpecification : Specification<Product>{
    Size size;
    SizeSpecification(Size size) : size(size){}

    bool is_satisfied(Product* item) override {
        return item->size == size;
    }
};


template<typename T> struct AndSpecification : Specification<T>{
    Specification<T>& first_spec;
    Specification<T>& second_spec;

    AndSpecification(Specification<T>& first_spec, Specification<T>& second_spec):
        first_spec(first_spec), second_spec(second_spec){}

    bool is_satisfied(T* item) override {
        return first_spec.is_satisfied(item) && second_spec.is_satisfied(item);
    }

};

// template <typename T>
// AndSpecification<T> operator&&(Specification<T> &first,
//                                Specification<T> &second) {
//   return {first, second};
// }


int main(){
    Product apple{"apple", Color::green, Size::small};
    Product tree{"tree", Color::green, Size::large};
    Product house{"house", Color::blue, Size::large};

    vector<Product*> items{&apple, &tree, &house};
    ProductFilter pf;

    auto large_things = pf.by_size(items, Size::large);
    for(auto& i: large_things){
        cout << i->name << " is large\n";
    }

    // open close principle starts
    cout << "(Color Filter) Following Open Close Principle" << endl;

    ColorSpecification color_specification(Color::green);
    BetterFilter bf;
    auto green_things = bf.filter(items, color_specification);
    for(auto& i: green_things){
        cout << i->name << " is green\n";
    }

    cout << "(Size Filter) Following Open Close Principle" << endl;
    SizeSpecification size_specification(Size::large);
    large_things = bf.filter(items, size_specification);
    for(auto& i: large_things){
        cout << i->name << " is large\n";
    }

    cout << "(Size & Color Filter) Following Open Close Principle" << endl;
    ColorSpecification green_spec(Color::green);
    SizeSpecification large_spec(Size::large);
    AndSpecification<Product> size_and_color_spec(green_spec, large_spec);
    auto and_items = bf.filter(items, size_and_color_spec);
    for(auto& i: and_items){
        cout << i->name << " is large and green\n";
    }
    // cout << "(Size & Color Filter) Following Open Close Principle (operator)" << endl;
    // auto combined_spec = green_spec & large_spec;
    // and_items = bf.filter(items, combined_spec);
    // for(auto& i: and_items){
    //     cout << i->name << " is large and green\n";
    // }
    return 0;
}





