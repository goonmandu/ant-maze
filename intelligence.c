//need a function that checks if there are points found in a given move
//need a dedicated move function that takes direction into account
//need 2 value holders for the greatest and least values found 
//when a point is found it should be moved into a teporary holding spot for comparison 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "intelligence.h"
#include "ant.h"

extern Ant michael;

int decision() {
    record("Decision\n");
    srand(time(NULL));
    int dir;
    /*
    printf("enter the point value of the newest point\n");
    scanf("%d", & michael.latest_deed); 

    printf("enter the point value of the greatest found \n");
    scanf("%d", & michael.max_deed); 

    printf("enter the x value of the new point\n");
    scanf("%d", & michael.latest_coords[0]);

    printf("enter the y value of new point\n");
    scanf("%d", & michael.latest_coords[1]);

    printf("enter the x  value of the greatest point\n");
    scanf("%d", & michael.max_coords[0]);

    printf("enter the y value of the greatest point\n");
    scanf("%d", & michael.max_coords[1]);
    */

    //debug
    printf("array elements points 1\n");
    printf("%d, %d, %d.\n", michael.latest_deed, michael.latest_coords[0], michael.latest_coords[1]);
    printf("array elements points 2\n");
    printf("%d, %d, %d.\n", michael.max_deed, michael.max_coords[0], michael.max_coords[1]);
    //debug

    int cand[2];
    if (abs(michael.latest_coords[0] - michael.max_coords[0]) == abs(michael.latest_coords[1] - michael.max_coords[1])) {
        if (michael.latest_coords[0] - michael.max_coords[0] > 0) {
            cand[0] = 0;
        } else {
            cand[0] = 1;
        }
        if (michael.latest_coords[1] - michael.max_coords[1] > 0) {
            cand[1] = 3;
        } else {
            cand[1] = 2;
        }
        return cand[rand() % 2];
    }


    if (michael.latest_deed > michael.max_deed) {
        printf("\nhigher points found!\n");
        if (abs(michael.latest_coords[0] - michael.max_coords[0]) > (abs(michael.latest_coords[1] - michael.max_coords[1]))) {

            if (michael.latest_coords[0] < michael.max_coords[0]) {
                dir = 0;
                printf("Moving left. Greater points can be found in %d's direction. Moving in the positive x direction.", michael.latest_deed);
            } else if (michael.latest_coords[0] > michael.max_coords[0]) {
                dir = 1;
                printf("Moving right. Greater points can be found in %d's direction. Moving in the positive x direction.", michael.latest_deed);
            }

        } else if ((abs(michael.latest_coords[1] - michael.max_coords[1]) > (abs(michael.latest_coords[0] - michael.max_coords[0])))) {
            if (michael.latest_coords[1] > michael.max_coords[1]) {
                dir = 3;
                printf("Moving down. Greater points can be found in %d's direction. Moving in the positive y direction.", michael.latest_deed);
            } else if (michael.latest_coords[1] < michael.max_coords[1]) {
                dir = 2;
                printf("Moving up. Greater points can be found in %d's direction. Moving in the negative y direction.", michael.latest_deed);
            }

        }

        michael.max_deed = michael.latest_deed;
        michael.max_coords[0] = michael.latest_coords[0];
        michael.max_coords[1] = michael.latest_coords[1];
    } else if (michael.latest_deed < michael.max_deed) { //go towards greteer
        printf("\nlower points found!, continue in past path.\n");
        if (abs(michael.latest_coords[0] - michael.max_coords[0]) > (abs(michael.latest_coords[1] - michael.max_coords[1]))) {

            if (michael.latest_coords[0] < michael.max_coords[0]) {
                dir = 1;
                printf("Moving right. Greater points can be found in %d's direction. Moving in the positive x direction.", michael.max_deed);
            } else if (michael.latest_coords[0] > michael.max_coords[0]) {
                dir = 0;
                printf("Moving left. Greater points can be found in %d's direction. Moving in the positive x direction.", michael.max_deed);
            }

        } else if ((abs(michael.latest_coords[1] - michael.max_coords[1]) > (abs(michael.latest_coords[0] - michael.max_coords[0])))) {
            if (michael.latest_coords[1] > michael.max_coords[1]) {
                dir = 3;
                printf("Moving down. Greater points can be found in %d's direction. Moving in the neagtive y direction.", michael.max_deed);
            } else if (michael.latest_coords[1] < michael.max_coords[1]) {
                dir = 2;
                printf("Moving up. Greater points can be found in %d's direction. Moving in the posotive y direction.", michael.max_deed);
            }

        }

    } else {
        printf("same point values were found.");
        return -1;
    }
    return dir;
}

void main_loop() {
    srand(time(NULL));
    put_pheromone(michael.current[0], michael.current[1]);

    int points = check(michael.current[0], michael.current[1]).has_deed;
    int direction;
	michael.score += points;

    if (michael.num_of_deeds > 1) {
        michael.latest_coords[0] = michael.current[0];
        michael.latest_coords[1] = michael.current[1];
        michael.latest_deed = points;
        direction = decision();
    } else if (points == 1) {
        michael.max_coords[0] = michael.current[0];
        michael.max_coords[1] = michael.current[1];
        michael.max_deed = points;
    }
    
//move randomly
 	int randomnumber;
    bold_jump(direction);

//check for itch, and bold jump if so
    randomnumber = rand() % 4;
    cautious_jump(randomnumber);
	
// amnesia chance
    int nukeitall = rand() % 1000000;
    if (nukeitall == 69420) {
        printf("Michael did an oopsie.\n");
        clear();
    }
}