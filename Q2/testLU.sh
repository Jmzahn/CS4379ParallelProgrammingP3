#!/bin/bash
echo -e "\nTest with 1 proc\n"
./LUOmp 2000 1 > ./testout/LUOmp_2000_01_out
echo -e "\nTest with 2 proc\n"
./LUOmp 2000 2 > ./testout/LUOmp_2000_02_out
echo -e "\nTest with 4 proc\n"
./LUOmp 2000 4 > ./testout/LUOmp_2000_04_out
echo -e "\nTest with 8 proc\n"
./LUOmp 2000 8 > ./testout/LUOmp_2000_08_out