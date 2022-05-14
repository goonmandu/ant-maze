#define EACH_SIDE 16
#define MAX_STEPS 50
#define STACK_SIZE 100

typedef struct Ant {
    int current[2];  // Michael's current coordinates
    int cached[2];   // Coordinates returned to Michael by calling peek()
    int itch[4];     // Indices 0 - 3 are L R F B. 0 if no itch, nonzero for number of free spaces
    int score;       // Total deed points earned by Michael
    int num_of_deeds;
    int latest_deed;
    int latest_coords[2];
    int max_deed;
    int max_coords[2];
} Ant;

typedef struct Cell {
    int has_wall;
    int has_deed;
    int has_pher;
} Cell;

// Debug: void print_ant(void);
void record(char *);
void pop(void);
void push(int, int);
void peek(void);
void move(int, int);
void clear(void);
void bold_jump(int);
void cautious_jump(int);
void scan_maze(FILE *file);
void set_positions(int, int);
void print_positions(char);
void feel_itch(void);
void print_itches(char);
void put_pheromone(int, int);
void move_one(int);
int michaels_deeds(void);
void log_steps(void);
Cell check(int, int);
// Cancelled: void backtrack(void);
// Cancelled: void repeat(void (*funcptr) (void), int);
// Unused: int *decode_xy(int num, int dim);