#include <iostream>

extern int foo();
extern int __real_foo();

int __wrap_foo()
{
    std::cout << "Func statrt wrap foo." << std::endl;
    __real_foo();
    std::cout << "Func wrapped." << std::endl;
    return 0;
}

int main()
{
    foo();
    return 0;
}
