#include <stdio.h>
#include "ant.h"

static int top = 0;
static int queue[QUEUE_SIZE][2];

static int wall_map[EACH_SIDE][EACH_SIDE];
static int deed_map[EACH_SIDE][EACH_SIDE];
static int pher_map[EACH_SIDE][EACH_SIDE];

Ant michael = {
    .current = {0, 0},
    .cached = {0, 0},
    .itch = 0,
    .score = 1
};

void pop(void) {
    top--;
}

void push(int x, int y) {
    queue[top][0] = x;
    queue[top][1] = y;
    top++;
}

void peek(void) {
    michael.cached[0] = queue[top-1][0];
    michael.cached[1] = queue[top-1][1];
}

void move(char dir) {
    
}

int is_open(char dir) {
    return 0;
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

Cell check(int x, int y) {
    Cell cell = {wall_map[x][y], deed_map[x][y], pher_map[x][y]};
    return cell;
}