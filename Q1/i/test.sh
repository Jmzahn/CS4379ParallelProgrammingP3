#!/bin/bash
echo -e "\nTest with 1 proc\n"
./MMProduct 1000 1 > ./testout/MMProduct_1000_01_out
echo -e "\nTest with 2 proc\n"
./MMProduct 1000 2 > ./testout/MMProduct_1000_02_out
echo -e "\nTest with 4 proc\n"
./MMProduct 1000 4 > ./testout/MMProduct_1000_04_out
echo -e "\nTest with 8 proc\n"
./MMProduct 1000 8 > ./testout/MMProduct_1000_08_out