#!/bin/bash

python3 stress.py > input.txt 

cat keys | ./test input.txt | python3 check.py



