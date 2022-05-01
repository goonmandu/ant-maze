# ant-maze
ESE 124 Final Project for Spring 2022.

# compile instructions
```zsh
cd /path-to-dir/  # Linux or macOS
cd \path-to-dir\  # Windows
```
then,
```zsh
gcc -c ant.c
gcc -c main.c
gcc -o main main.c ant.c
```
finally,
```zsh
./main             # Linux or macOS
./main.exe         # Windows
