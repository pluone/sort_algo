cmake_minimum_required(VERSION 3.23)
project(algo C)

set(CMAKE_C_STANDARD 11)

#add_executable(algo
#        mergesort.c
#        quick_sort.c
#        radix_sort.c
#        selection_sort.c
#        shell_sort.c)

add_executable(algo
#        radix_sort.c
        radix_sort_big.c
#        selection_sort_big.c
#        mergesort.c
#        mergesort_big.c
#        quick_sort.c
#        quick_sort_big.c
#        shell_sort.c
#        shell_sort_big.c
        common.c)