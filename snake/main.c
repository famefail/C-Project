#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 25

// TODO 
// create board (done)
// add snake

void mapBoard(int board[ROWS][COLS]);

void drawBoard(int board[ROWS][COLS], int player[2][2]);

void updateCell(int map[11][26], int row, int col, int value);

int timer();

int main(void)
{
    time_t start_time;
    int map[ROWS][COLS];
    int player[2][2];
    int sizeMap = sizeof(map[0]) / sizeof(map[0][0]);
    int count = 0;
    mapBoard(map);
    drawBoard(map, player);
}

void updateCell(int map[11][26], int row, int col, int value)
{
    if (row >= 0 && row < 11 && col >= 0 && col < 26)
        map[row][col] = value;
}

void mapBoard(int board[ROWS][COLS])
{
    for (int i = ROWS; i >= 0; i--)
    {
        for (int j = 1; j <= COLS; j++)
        {
            if (i % 2 == 0)
            {
                int plusNum = j + (i * 10);
                board[i][j - 1] = plusNum;
            }
            else
            {
                int minusNum = (11 - j) + (i * 10);
                board[i][j - 1] = minusNum;
            }
        }
    }
}

void drawBoard(int board[ROWS][COLS], int player[2][2])
{
    printf("=============== SNAKE ==================\n\n");
    for (int i = ROWS; i >= 0; i--)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (i == 0 || i == ROWS || j == COLS - 1 ||  j == 0 )
            {
                printf("#");
                // printf("%3d ", board[i][j]);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("=======================================\n");
}

int timer()
{
    time_t start_time, current_time;
    double elapsed_seconds;

    start_time = time(NULL); // Get current time in seconds since epoch

    // printf("Timer started. Waiting for 5 seconds...\n");

    do
    {
        current_time = time(NULL);
        elapsed_seconds = difftime(current_time, start_time);
    } while (elapsed_seconds < 1.0); // Loop until 5 seconds have passed

    // printf("1 seconds have passed!\n");

    return 0;
}