#!/bin/sh
#$ -V
#$ -cwd
#$ -S /bin/bash
#$ -N OMP_job
#$ -o $JOB_NAME.o$JOB_ID
#$ -e $JOB_NAME.e$JOB_ID
#$ -q omni
#$ -pe sm 36
#$ -l h_vmem=5.3G
#$ -l h_rt=00:10:00
#$ -P quanah

module load gnu7 

echo "\nTest Q1\n"

echo -e "\nTest i\n"

echo -e "\nTest with 1 proc\n"
./Q1/i/MMProduct 2000 1 > ./Q1/i/testout/MMProduct_2000_01_quanah
echo -e "\nTest with 2 proc\n"
./Q1/i/MMProduct 2000 2 > ./Q1/i/testout/MMProduct_2000_02_quanah
echo -e "\nTest with 4 proc\n"
./Q1/i/MMProduct 2000 4 > ./Q1/i/testout/MMProduct_2000_04_quanah
echo -e "\nTest with 8 proc\n"
./Q1/i/MMProduct 2000 8 > ./Q1/i/testout/MMProduct_2000_08_quanah
echo -e "\nTest with 16 proc\n"
./Q1/i/MMProduct 2000 16 > ./Q1/i/testout/MMProduct_2000_16_quanah
echo -e "\nTest with 32 proc\n"
./Q1/i/MMProduct 2000 32 > ./Q1/i/testout/MMProduct_2000_32_quanah

echo -e "\nTest ii\n"

echo -e "\nTest with 1 proc\n"
./Q1/ii/MMProduct 2000 1 > ./Q1/ii/testout/MMProduct_2000_01_quanah
echo -e "\nTest with 2 proc\n"
./Q1/ii/MMProduct 2000 2 > ./Q1/ii/testout/MMProduct_2000_02_quanah
echo -e "\nTest with 4 proc\n"
./Q1/ii/MMProduct 2000 4 > ./Q1/ii/testout/MMProduct_2000_04_quanah
echo -e "\nTest with 8 proc\n"
./Q1/ii/MMProduct 2000 8 > ./Q1/ii/testout/MMProduct_2000_08_quanah
echo -e "\nTest with 16 proc\n"
./Q1/ii/MMProduct 2000 16 > ./Q1/ii/testout/MMProduct_2000_16_quanah
echo -e "\nTest with 32 proc\n"
./Q1/ii/MMProduct 2000 32 > ./Q1/ii/testout/MMProduct_2000_32_quanah

echo -e "\nTest iii\n"

echo -e "\nTest with 1 proc\n"
./Q1/iii/MMProduct 2000 1 > ./Q1/iii/testout/MMProduct_2000_01_quanah
echo -e "\nTest with 2 proc\n"
./Q1/iii/MMProduct 2000 2 > ./Q1/iii/testout/MMProduct_2000_02_quanah
echo -e "\nTest with 4 proc\n"
./Q1/iii/MMProduct 2000 4 > ./Q1/iii/testout/MMProduct_2000_04_quanah
echo -e "\nTest with 8 proc\n"
./Q1/iii/MMProduct 2000 8 > ./Q1/iii/testout/MMProduct_2000_08_quanah
echo -e "\nTest with 16 proc\n"
./Q1/iii/MMProduct 2000 16 > ./Q1/iii/testout/MMProduct_2000_16_quanah
echo -e "\nTest with 32 proc\n"
./Q1/iii/MMProduct 2000 32 > ./Q1/iii/testout/MMProduct_2000_32_quanah


echo "\nTest Q2\n"

echo -e "\nTest gauss\n"

echo -e "\nTest with 1 proc\n"
./Q2/gaussOmp 2000 1 > ./Q2/testout/gaussOmp_2000_01_quanah
echo -e "\nTest with 2 proc\n"
./Q2/gaussOmp 2000 2 > ./Q2/testout/gaussOmp_2000_02_quanah
echo -e "\nTest with 4 proc\n"
./Q2/gaussOmp 2000 4 > ./Q2/testout/gaussOmp_2000_04_quanah
echo -e "\nTest with 8 proc\n"
./Q2/gaussOmp 2000 8 > ./Q2/testout/gaussOmp_2000_08_quanah
echo -e "\nTest with 16 proc\n"
./Q2/gaussOmp 2000 16 > ./Q2/testout/gaussOmp_2000_16_quanah
echo -e "\nTest with 32 proc\n"
./Q2/gaussOmp 2000 32 > ./Q2/testout/gaussOmp_2000_32_quanah

echo -e "\nTest LU\n"

echo -e "\nTest with 1 proc\n"
./Q2/LUOmp 2000 1 > ./Q2/testout/LUOmp_2000_01_quanah
echo -e "\nTest with 2 proc\n"
./Q2/LUOmp 2000 2 > ./Q2/testout/LUOmp_2000_02_quanah
echo -e "\nTest with 4 proc\n"
./Q2/LUOmp 2000 4 > ./Q2/testout/LUOmp_2000_04_quanah
echo -e "\nTest with 8 proc\n"
./Q2/LUOmp 2000 8 > ./Q2/testout/LUOmp_2000_08_quanah
echo -e "\nTest with 16 proc\n"
./Q2/LUOmp 2000 16 > ./Q2/testout/LUOmp_2000_16_quanah
echo -e "\nTest with 32 proc\n"
./Q2/LUOmp 2000 32 > ./Q2/testout/LUOmp_2000_32_quanah
