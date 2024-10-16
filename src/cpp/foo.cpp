#include <iostream>
#ifdef __cplusplus
extern "C"
{
#endif

int foo()
{
    std::cout << "Func foo." << std::endl;
    return 0;
}

extern int __real_foo();

int __wrap_foo()
{
    std::cout << "Func start wrap foo." << std::endl;
    __real_foo();
    std::cout << "Func wrapped." << std::endl;
    return 0;
}

#ifdef __cplusplus
}
#endif
