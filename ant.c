#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ant.h"

static int top = 0;
static int stack[STACK_SIZE][2];
char steps[500][25];
int num_steps = 0;

static int wall_map[EACH_SIDE][EACH_SIDE];
static int deed_map[EACH_SIDE][EACH_SIDE];
static int pher_map[EACH_SIDE][EACH_SIDE];

Ant michael = {
    .current = {0, 0},  // will not be read whatsoever, only for traversal purposes
    .cached = {0, 0},
    .itch = 0,
    .score = 0,
    .num_of_deeds = 0,
    .latest_deed = 0,
    .max_deed = 0
};

void record(char *command) {
    num_steps++;
    strcpy(steps[num_steps-1], command);
}

void pop(void) {
    top--;
}

void push(int x, int y) {
    stack[top][0] = x;
    stack[top][1] = y;
    top++;
}

void peek(void) {
    michael.cached[0] = stack[top-1][0];
    michael.cached[1] = stack[top-1][1];
}

void move(int dir, int spaces) {  // General purpose move function
    switch (dir) {
        case 0:  // Left
            for (int i = 0; i < spaces; i++) {
                michael.current[0]++;
                print_positions(' ');
                printf("%d\n", check(michael.current[0], michael.current[1]).has_wall);
                if (michael.current[0] < 0 || check(michael.current[0], michael.current[1]).has_wall) {
                    michael.current[0]--;
                }
            }
            break;
        case 1:  // Right
            for (int i = 0; i < spaces; i++) {
                michael.current[0]--;
                print_positions(' ');
                printf("%d\n", check(michael.current[0], michael.current[1]).has_wall);
                if (michael.current[0] > 15 || check(michael.current[0], michael.current[1]).has_wall) {
                    michael.current[0]++;
                }
            }
            break;
        case 2:  // Up
            for (int i = 0; i < spaces; i++) {
                michael.current[1]--;
                print_positions(' ');
                printf("%d\n", check(michael.current[0], michael.current[1]).has_wall);
                if (michael.current[1] < 0 || check(michael.current[0], michael.current[1]).has_wall) {
                    michael.current[1]++;
                }
            }
            break;
        case 3:  // Down
            for (int i = 0; i < spaces; i++) {
                michael.current[1]++;
                print_positions(' ');
                printf("%d\n", check(michael.current[0], michael.current[1]).has_wall);
                if (michael.current[1] > 15 || check(michael.current[0], michael.current[1]).has_wall) {
                    michael.current[1]--;
                }
            }
            break;
        default:
            printf("Incorrect parameters for function: move(%d, %d) was called\n", dir, spaces);
            exit(1);
    }

    feel_itch();
}

void clear(void) {
    top = 0;
}

void bold_jump(int dir) {
    put_pheromone(michael.current[0], michael.current[1]);
    move(dir, michael.itch[dir]);
    put_pheromone(michael.current[0], michael.current[1]);
    record("BoldJump\n");
}

void cautious_jump(int dir) {
    put_pheromone(michael.current[0], michael.current[1]);
    move(dir, 1);
    put_pheromone(michael.current[0], michael.current[1]);
    record("CautiousJump\n");
}

/* CANCELLED
void backtrack(void) {

}
*/

/*  CANCELLED
void repeat(void (*funcptr) (void), int times) {

}
*/

/*
int *decode_xy(int num, int dim) {
    int _x = num % dim;
    int _y = num / dim;
    int _c[2] = {_x, _y};
    return _c;
}
*/

/*
int has_wall(int x, int y) {
    return 0;
}

int has_deed(int x, int y) {
    return 0;
}

int has_pher(int x, int y) {
    return 0;
}
*/

void scan_maze(FILE *file) {
    int row = 0, col = 0;
    while (1) {
        int curr;
        if (fscanf(file, "%d", &curr) == EOF) {
            break;
        }
        // printf("%d ", curr);
        if (curr == -1) {
            // printf("wall\n");
            pher_map[row][col] = 0;
            deed_map[row][col] = 0;
            wall_map[row][col] = 1;
        } else if (curr == 0) {
            // printf("empty\n");
            pher_map[row][col] = 0;
            deed_map[row][col] = 0;
            wall_map[row][col] = 0;
        } else if (curr > 0) {
            // printf("deed\n");
            pher_map[row][col] = 0;
            deed_map[row][col] = curr;
            wall_map[row][col] = 0;
        }
        col++;
        if (col > 15) {
            row++;
            col = 0;
            // printf("\n\n");
        }
    }
}

Cell check(int x, int y) {
    Cell cell = (Cell) {wall_map[y][x], deed_map[y][x], pher_map[y][x]};
    return cell;
}

void set_positions(int x, int y) {
    michael.current[0] = x;
    michael.current[1] = y;
}

void print_positions(char end) {
    printf("(%d, %d)%c", michael.current[0], michael.current[1], end);
}

void feel_itch() {
    for (int dir = 0; dir < 4; dir++) {
        int offset = 0;
        int x, y;
        int spaces = 0;
        while (1) {
            offset++;
            if (dir == 0) {  // Scan left
                x = michael.current[0] - offset;
                y = michael.current[1];
            } else if (dir == 1) {  // Scan right
                x = michael.current[0] + offset;
                y = michael.current[1];
            } else if (dir == 2) {  // Scan up
                x = michael.current[0];
                y = michael.current[1] - offset;
            } else if (dir == 3) {  // Scan down
                x = michael.current[0];
                y = michael.current[1] + offset;
            }

            if (check(x, y).has_pher) {
                spaces = 0;
                break;
            }

            if (check(x, y).has_wall) {
                break;
            }

            spaces++;     
        }
        michael.itch[dir] = spaces;
    }
    record("FeelItch\n");
}

void print_itches(char end) {
    printf("{");
    for (int i = 0; i < 4; i++) {
        if (i != 3) {
            printf("%d, ", michael.itch[i]);
        } else {
            printf("%d}%c", michael.itch[i], end);
        }
    }
}

void put_pheromone(int x, int y) {
    pher_map[y][x] = 1;
}

void move_one(int dir) {
    put_pheromone(michael.current[0], michael.current[1]);
    move(dir, 1);
    put_pheromone(michael.current[0], michael.current[1]);
}

int michaels_deeds() {
    return michael.score;
}