#!/bin/bash

BUILD_DIR=build

build() {
    echo "BUILD_DIR: $BUILD_DIR"
    cmake -B $BUILD_DIR -G "Unix Makefiles" -S .
    cmake --build $BUILD_DIR
}

test() {
    echo "BUILD_DIR: $BUILD_DIR"
    cd $BUILD_DIR || exit
    ./main
}

test_em() {
    echo "BUILD_DIR: $BUILD_DIR"
    cd $BUILD_DIR || exit
    node modules/ilab-zozomat-sdk-management/ilab-zozomat-sdk-management-test.js
}

# exec_main() {
#     BUILD_DIR=build
#     echo "BUILD_DIR: $BUILD_DIR"
#     ./${BUILD_DIR}/main
# }

# switch by the first argument
case $1 in
    "clean")
        clean
        ;;
    "build")
        build
        ;;
    "test")
        test
        ;;
    "exec_main")
        exec_main
        ;;
    "make_em")
        make_em
        ;;
    "test_em")
        test_em
        ;;
    *)
        echo "Usage: $0 {clean|make_binary|test_binary|make_em|test_em}"
        exit 1
        ;;
esac
