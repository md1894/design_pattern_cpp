#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    std::for_each(
        in(std::cin), in(), std::cout << (_1 * 3) << " " );
}

/*

downloaded the boost library boost_1_74_0.tar.bz2
extracted that file in the directory below

installed boost library in the directory
/usr/local

used following command to compile this file

g++ -I /usr/local/boost_1_74_0/ boost_lib_starter.cpp -o example

*/
