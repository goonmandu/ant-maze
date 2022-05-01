#!/bin/zsh

gcc -c ant.c
gcc -c main.c
gcc -o main ant.c main.c
./main
