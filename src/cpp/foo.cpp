#include <iostream>

extern "C" int foo()
{
    std::cout << "Func foo." << std::endl;
    return 0;
}
