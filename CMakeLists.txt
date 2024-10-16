cmake_minimum_required(VERSION 3.10)
project(emscripten-cpp-test)

# set the lang is C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(EMSCRIPTEN)
    # set(CMAKE_EXECUTABLE_SUFFIX .js)
    # add_link_options(-l nodefs.js)
    # add_link_options(-sNODERAWFS)
    add_link_options(-sALLOW_MEMORY_GROWTH)
    add_link_options(-fexceptions)

    add_compile_options(-fexceptions)
    # add_compile_options(-gsource-map)
    add_compile_options(-g)
else()
    set(CMAKE_C_COMPILER "/usr/local/opt/llvm/bin/clang")
    set(CMAKE_CXX_COMPILER "/usr/local/opt/llvm/bin/clang++")
    set(CMAKE_LINKER "/usr/local/opt/lld/bin/lld")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fuse-ld=lld")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=lld")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fuse-ld=lld")
endif()


# Add executable
add_executable(main src/cpp/main.cpp src/cpp/foo.cpp)
# add_link_options("-fuse-ld=lld")
add_link_options("-Wl,--wrap=foo")
# target_link_options(main PRIVATE "LINKER:-fuse-ld=lld")
# target_link_options(main PRIVATE "LINKER:--wrap=moveme")
# target_link_options(main PRIVATE -Wl,--wrap=moveme)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--wrap=foo")
