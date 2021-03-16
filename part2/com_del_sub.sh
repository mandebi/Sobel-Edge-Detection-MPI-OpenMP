#!/bin/bash

echo "Script that compiles C sources, delete result files, and submit the job ..."

./compile.sh 
./delete_resultFiles.sh 
./submit_job.sh
