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
./Q1/testAll.sh

echo "\nTest Q2\n"
./Q2/testAll.sh