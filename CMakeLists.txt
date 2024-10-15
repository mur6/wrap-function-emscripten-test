cmake_minimum_required(VERSION 3.10)
project(emscripten-cpp-test)

include(CMakePrintHelpers)
cmake_print_variables(EMSCRIPTEN)

if(EMSCRIPTEN)
    # set(CMAKE_EXECUTABLE_SUFFIX .js)
    # add_link_options(-l nodefs.js)
    # add_link_options(-sNODERAWFS)
    add_link_options(-sALLOW_MEMORY_GROWTH)
    add_link_options(-fexceptions)

    add_compile_options(-fexceptions)
    # add_compile_options(-gsource-map)
    add_compile_options(-g)
endif()

# Add executable
add_executable(main main.cpp)
add_link_options("-fuse-ld=lld")
add_link_options("-Wl,--wrap=cv_imread")
