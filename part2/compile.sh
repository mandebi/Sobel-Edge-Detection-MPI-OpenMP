#!/bin/bash

echo "Compiling ..."
mpicc -qopenmp sobel2.c -o sobel2
