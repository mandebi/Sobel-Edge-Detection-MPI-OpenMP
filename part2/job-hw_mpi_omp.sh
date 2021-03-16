#!/bin/bash
#SBATCH --account=eel6763
#SBATCH --qos=eel6763
#SBATCH --nodes=1
#SBATCH --ntasks=4
#SBATCH --ntasks-per-node=4
#SBATCH --cpus-per-task=1
#SBATCH --mem-per-cpu=500mb
#SBATCH -t 00:05:00
#SBATCH -o outfile
#SBATCH -e errfile
export OMP_NUM_THREADS=5
srun --mpi=pmix_v3 ./sobel2
