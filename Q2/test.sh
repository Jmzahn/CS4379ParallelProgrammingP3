#!/bin/bash
echo -e "\nTest with 1 proc\n"
./gaussOmp 2000 1 > ./testout/gaussOmp_2000_01_out
echo -e "\nTest with 2 proc\n"
./gaussOmp 2000 2 > ./testout/gaussOmp_2000_02_out
echo -e "\nTest with 4 proc\n"
./gaussOmp 2000 4 > ./testout/gaussOmp_2000_04_out
echo -e "\nTest with 8 proc\n"
./gaussOmp 2000 8 > ./testout/gaussOmp_2000_08_out