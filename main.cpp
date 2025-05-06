#include <iostream>
#include "Vector_Iterator.h"


int main()
{
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    for(int i = 0; i < vec.get_Size(); ++i ){
        std::cout<<vec[i];
    }
    Vector<int>::const_iter it;
    it = vec.cbegin();
    std::cout << *it;

    for(const auto& x:vec){
        std::cout<<x;
    }
}