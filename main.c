#include <stdio.h>
#include "ant.h"
#include "intelligence.h"

int main() {
    extern char steps[500][25];
    extern int num_steps;
    FILE *in, *out;
    if ((in = fopen("map", "r")) == NULL) {
        printf("Cannot open input file.\n");
        return 1;
    }
    out = fopen("steps_taken", "w");
    scan_maze(in);
    set_positions(7, 1);
    while (num_steps <= MAX_STEPS) {
        main_loop();
    }
    printf("Michael's Final Score: %d\n", michaels_deeds());
    for (int i = 0; i < num_steps; i++) {
        fputs(steps[i], out);
    }
    return 0;
}