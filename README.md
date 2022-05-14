# ant-maze
ESE 124 Final Project for Spring 2022.

# to anyone that might play around with the code
If you want to make your own

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
./main.exe         # Windows (PowerShell)
main.exe           # Windows (Command Prompt)
```

# alternate compile instructions
```zsh
sh make.sh         # Linux or macOS
./make.bat         # Windows (PowerShell)
make.bat           # Windows (Command Prompt)
```