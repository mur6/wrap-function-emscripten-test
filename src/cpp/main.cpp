#include <iostream>

extern "C" int foo();
extern "C" int __real_foo();

extern "C"
int __wrap_foo()
{
    std::cout << "Func start wrap foo." << std::endl;
    __real_foo();
    std::cout << "Func wrapped." << std::endl;
    return 0;
}

int main()
{
    foo();
    return 0;
}
