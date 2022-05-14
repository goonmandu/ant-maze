# ant-maze
ESE 124 Final Project for Spring 2022.  
This repository is archived as of 12:41 AM, May 14 2022 EDT.

# to anyone that might play around with the code
The map is stored in the file called `map`.

If you want to make your own maze, the following need to be done:  
1. Maze size is 16 x 16. If you want to have a bigger maze, you need to change the `MAX_SIDE` definition to match that of your own.  
2. Walls are encoded as `-1`.  
3. Deeds are encoded as the point values they hold. (ex. a deed with a point value of 4 would simply be encoded as `4`)  
4. Empty spaces are encoded as `0`.  
5. Spaces are separated by whitespaces.

A sample 5 x 5 maze would look like this:  
```
-1 -1 -1 -1 -1
-1  0 -1  2 -1
-1  1 -1  1 -1
-1  0  0  1 -1
-1 -1 -1 -1 -1
```

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
