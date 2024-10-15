#include<stdio.h>


extern "C" {

#include "wrap_b.hpp"

#ifdef WRAP
void __wrap_moveme(void) {
    puts("wrap_moveme");

    __real_moveme();
}
#endif


void moveme(void) {
    puts("moveme");
}

}
