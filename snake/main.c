#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 25

// TODO
// create board (done)
// add snake

void mapBoard(int board[ROWS][COLS]);

void drawBoard(int board[ROWS][COLS], int *player);

void updateCell(int map[11][26], int row, int col, int value);

void timer();

int main(void)
{
    time_t start_time;
    int map[ROWS][COLS];
    int player = 33;
    int sizeMap = sizeof(map[0]) / sizeof(map[0][0]);
    int count = 0;
    mapBoard(map);
    printf("=============== SNAKE ==================\n\n");
    while (1)
    {
        char input = 119;
        switch (input)
        {
        case 100: // d
            player++;
            break;
        case 119: // w
            player = player + 25;
            break;
        case 97: // a
            player--;
            break;
        case 115: // s
            player = 25 - player;
        default:
            break;
        }

        drawBoard(map, &player);

        timer();
    }
    printf("=======================================\n");
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
            board[i][j - 1] = j + (i * ROWS); // 1 + 0 * 10 = 2
        }
    }
}

void drawBoard(int board[ROWS][COLS], int *player)
{
    for (int i = ROWS; i >= 0; i--)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (*player < ROWS + 1 || *player > 625)
                return;
            else if (*player == board[i][j])
                printf("O");
            else if (i == 0 || i == ROWS || j == COLS - 1 || j == 0)
                printf("#");
            // printf("%3d ", board[i][j]);
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