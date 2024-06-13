#include <iostream>

int main()
{
    // raise runtime error
    int* p = 0;
    *p = 0;

    std::cout << "これは、main関数です。" << std::endl;

    return 0;
}
