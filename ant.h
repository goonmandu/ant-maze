#define EACH_SIDE 16
#define MAX_STEPS 20
#define STACK_SIZE 100

typedef struct Ant {
    int current[2];  // Michael's current coordinates
    int cached[2];   // Coordinates returned to Michael by calling peek()
    int itch[4];     // Indices 0 - 3 are L R F B. 0 if no itch, nonzero for number of free spaces
    int score;       // Total deed points earned by Michael
    int num_of_deeds;
} Ant;

typedef struct Cell {
    int has_wall;
    int has_deed;
    int has_pher;
} Cell;

// Debug: void print_ant(void);
void pop(void);
void push(int x, int y);
void peek(void);
void move(int dir);
void is_open(int dir);
void clear(void);
void bold_jump(void);
void cautious_jump(void);
void backtrack(void);
void repeat(void (*funcptr) (void), int times);
// Unused: int *decode_xy(int num, int dim);  
int has_wall(int x, int y);
int has_deed(int x, int y);
int has_pher(int x, int y);
Cell check(int x, int y);  // check(4, 6).has_deed