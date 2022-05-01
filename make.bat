ECHO "Compiling ant.c"
gcc -c ant.c
ECHO "Compiling main.c"
gcc -c main.c
ECHO "Linking main.c and ant.c into main.exe"
gcc -o main main.c main.c
ECHO "Running main.exe"
./main.exe
