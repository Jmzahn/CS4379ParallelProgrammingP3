import numpy as np
import matplotlib.pyplot as plt


threads = np.array([1, 2, 4, 8, 16, 32])
gauss_OMP_Dynamic = np.array([7279.08, 3825.69, 2028.75, 1142.32, 672.767, 383.215])
LU_OMP = np.array([7677.61, 6756.57, 4867.35, 2827.44, 1672.5, 923.548])
index = np.arange(len(threads))
 

SU_gauss_OMP_Dynamic = np.array([gauss_OMP_Dynamic[0]/time for time in gauss_OMP_Dynamic])
SU_LU_OMP = np.array([LU_OMP[0]/time for time in LU_OMP])

plt.figure()
plt.plot(index, gauss_OMP_Dynamic, 'r--', label='Gauss')
plt.plot(index, LU_OMP, 'b--', label='LU Decomp')
plt.ylabel('Time ms')
plt.xlabel('Threads')
plt.xticks(index, threads)
plt.title('Time in ms vs Number of Threads')
plt.legend(loc='upper left')

plt.figure()
plt.plot(index, SU_gauss_OMP_Dynamic, 'r--', label='Gauss')
plt.plot(index, SU_LU_OMP, 'b--', label='LU Decomp')
plt.ylabel('Speed Up')
plt.xlabel('Threads')
plt.xticks(index, threads)
plt.title('Speed Up vs Number of Threads')
plt.legend(loc='upper left')

plt.show()