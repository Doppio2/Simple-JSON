#!/bin/sh

# x - Print all commands in script.
# e - stop script running when error.
set -xe

# main.cpp - main file for leetcode

CFlags="-Wall -Wextra -ggdb -O0 -Wno-sign-compare -Wno-unused-variable -Wno-unused-function"
SourceFiles="test.c"

# Create folder "build", if not exists. Change it later.
mkdir -p ../build

clang $CFlags $SourceFiles -o ../build/test
