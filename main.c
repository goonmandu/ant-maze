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
    scan_maze(in);

    /* Code to check if data structure works */
    /*
    push(4, 7);
    peek();
    printf("Coords remembered by peek: (%d, %d)\n", michael.cached[0], michael.cached[1]);
    printf("%d\n", check(2, 3).has_deed);
    */
    set_positions(7, 0);
    move(3, 10);
    print_positions('\n');
    // printf("deed: %d\n", check(7, 5).has_deed);
    return 0;
}