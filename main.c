#include <stdio.h>
#include "ant.h"

int main() {
    extern Ant michael;
    FILE *in;
    if ((in = fopen("map", "r")) == NULL) {
        printf("Cannot open input file.\n");
        return 1;
    }
    int steps_taken = 0;

    /* Code to check if data structure works */
    push(4, 7);
    peek();
    printf("Coords remembered by peek: (%d, %d)\n", michael.cached[0], michael.cached[1]);
    scan_maze(in);
    printf("%d\n", check(2, 3).has_deed);
    return 0;
}