#include <stdio.h>
#include "ant.h"

static int top = 0;
static int stack[STACK_SIZE][2];

static int wall_map[EACH_SIDE][EACH_SIDE];
static int deed_map[EACH_SIDE][EACH_SIDE];
static int pher_map[EACH_SIDE][EACH_SIDE];

Ant michael = {
    .current = {0, 0},
    .cached = {0, 0},
    .itch = 0,
    .score = 0
};

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

void move(int dir) {
    // Move Michael according to michael.itch[dir]
    for (int i = 0; i < 4; i++) {
        michael.itch[i] = 0;
    }
}

void is_open(int dir) {  // 0L 1R 2F 3B
    int free_spaces = 0;
    // Checks for number of free spaces in given direction, with a for loop or while loop
    michael.itch[dir] = free_spaces;
}

void clear(void) {
    top = 0;
}

void bold_jump(void) {

}

void cautious_jump(void) {

}

void backtrack(void) {

}

void repeat(void (*funcptr) (void), int times) {

}

/*
int *decode_xy(int num, int dim) {
    int _x = num % dim;
    int _y = num / dim;
    int _c[2] = {_x, _y};
    return _c;
}
*/

int has_wall(int x, int y) {
    return 0;
}

int has_deed(int x, int y) {
    return 0;
}

int has_pher(int x, int y) {
    return 0;
}

void scan_maze(FILE *file) {
    int row = 0, col = 0;
    while (1) {
        int curr;
        if (fscanf(file, "%d", &curr) == EOF) {
            break;
        }
        // printf("%d ", curr);
        if (curr == -1) {
            printf("wall\n");
            pher_map[row][col] = 0;
            deed_map[row][col] = 0;
            wall_map[row][col] = 1;
        } else if (curr == 0) {
            printf("empty\n");
            pher_map[row][col] = 0;
            deed_map[row][col] = 0;
            wall_map[row][col] = 0;
        } else if (curr > 0) {
            printf("deed\n");
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