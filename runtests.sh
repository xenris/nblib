#!/bin/sh

set -e

function clean {
    rm -f test_exe
}

trap clean EXIT

cd test/

cflags="-Werror -Wall -fmax-errors=3 -std=c++17"
includes="-I ../src/"
libs="-lgtest -lgtest_main"

if [ "$#" -eq 0 ]
then
    declare -a tests=($(find . -name "test_*.cpp" | sed 's:./test_\(.*\)\.cpp:\1:'))
else
    declare -a tests=("$@")
fi

for test in "${tests[@]}"
do
    echo "###### $test #######"

    g++ $includes $cflags $libs "test_${test}.cpp" -o test_exe

    ./test_exe
done
