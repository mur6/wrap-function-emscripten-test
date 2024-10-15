#include <iostream>


extern "C" {
    #include "wrap_b.hpp"
}


int main()
{
    // raise runtime error
    // int* p = 0;
    // *p = 0;
    moveme();
    std::cout << "これは、main関数です。" << std::endl;

    return 0;
}
