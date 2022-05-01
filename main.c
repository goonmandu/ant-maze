#include <stdio.h>
#include "ant.h"

int main() {
    // TESTING GIT PUSH ORIGIN MAIN
    extern Ant michael;
    push(4, 7);
    peek();
    printf("Coords remembered by peek: (%d, %d)\n", michael.cached[0], michael.cached[1]);
    return 0;
}