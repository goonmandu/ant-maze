#include <stdio.h>
#include "ant.h"

int main() {
    extern Ant michael;
    int steps_taken = 0;

    /* Code to check if data structure works */
    push(4, 7);
    peek();
    printf("Coords remembered by peek: (%d, %d)\n", michael.cached[0], michael.cached[1]);
    return 0;
}