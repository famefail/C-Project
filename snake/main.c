#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define ROWS 25
#define COLS 25

// TODO
// create board (done)
// add snake (done)
// add fruit (done)
// random fruit (done)
// when eat growth up

void mapBoard(int board[ROWS][COLS]);

void drawBoard(int board[ROWS][COLS], int *player, int *fruit);

void updateCell(int map[11][26], int row, int col, int value);

void moveSnake(char *input, int *player);

void randomFruit(int *fruit);

void eatingFruit(int *player, int *fruit);

void timer();

struct stack {
    int val;
    
} stack;

int main(void)
{
    srand(time(NULL));
    time_t start_time;
    int map[ROWS][COLS];
    int player = (rand() % 624) + 10;
    int sizeMap = sizeof(map[0]) / sizeof(map[0][0]);
    int count = 0;
    char input = 115;
    int fruit = 0;
    mapBoard(map);
    printf("=============== SNAKE ==================\n\n");
    do
    {
        moveSnake(&input, &player);
        randomFruit(&fruit); 
        eatingFruit(&player, &fruit);
        if(fruit == 0)
            randomFruit(&fruit);
        drawBoard(map, &player, &fruit);
       
        timer();
    } while (1);
    printf("=======================================\n");
}

void eatingFruit(int *player, int *fruit)
{
    if(*player == *fruit){
        *fruit = 0;
        printf("eating\n");
    }
}

void randomFruit(int *fruit)
{
    while ((*fruit % 25 == 1 || *fruit % 25 == 0) && *fruit == 0)
    {
        *fruit = (rand() % 624) + 10;
        printf("loop %i\n", *fruit);
    };
}

void moveSnake(char *input, int *player)
{
    if (_kbhit())
    {
        char temp = _getch();
        *input = temp;
    }

    switch (*input)
    {
    case 100: // d
        *player = *player + 1;
        break;
    case 119: // w
        *player = *player + 25;
        break;
    case 97: // a
        *player = *player - 1;
        break;
    case 115: // s
        *player = *player - 25;
    default:
        break;
    }
}

void updateCell(int map[11][26], int row, int col, int value)
{
    if (row >= 0 && row < 11 && col >= 0 && col < 26)
        map[row][col] = value;
}

void mapBoard(int board[ROWS][COLS])
{
    for (int i = 0; i <= ROWS; i++)
    {
        for (int j = 1; j <= ROWS; j++)
        {
            board[i][j - 1] = j + (i * ROWS);
        }
    }
}

void drawBoard(int board[ROWS][COLS], int *player, int *fruit)
{
    for (int i = ROWS; i >= 0; i--)
    {
        for (int j = 0; j < COLS; j++)
        {  
            if (*player < ROWS + 1 || *player > 625)
                return;
            else if (*fruit == board[i][j])
                printf("@");
            else if (*player == board[i][j])
                printf("O");
            else if (i == 0 || i == ROWS || j == COLS - 1 || j == 0)
                printf("#");
            else
                printf(" ");

            // printf("%3d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void timer()
{
    time_t start_time, current_time;
    double elapsed_seconds;
    start_time = time(NULL);
    do
    {
        current_time = time(NULL);
        elapsed_seconds = difftime(current_time, start_time);
    } while (elapsed_seconds < 0.1);
}