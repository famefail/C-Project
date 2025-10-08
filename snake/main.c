#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define SHORTCUT 16
// TODO
// 1 create board (done)
// 2 add player in board (done)
// 3 add toss system (done)
// 4 add snake and ladder (done)
// 5 add player two (to do)

void printBoard(int board[ROWS][COLS], int player);

void mapBoard(int board[ROWS][COLS]);

void checkLadderOrSnake(int *player, int snake[2][SHORTCUT]);

int main(void)
{
    srand(time(NULL));

    int player = 1;
    int board[ROWS][COLS];
    char choice = 'y';

    mapBoard(board);
    int snake[2][SHORTCUT] = {
        {1, 4, 9, 17, 21, 28, 51, 54, 62, 64, 71, 80, 87, 93, 95, 98},
        {38, 14, 31, 7, 42, 84, 67, 34, 19, 60, 91, 100, 24, 73, 75, 79}};
    printBoard(board, player);
    while (player < 100)
    {

        printf("Roll the dice press y : ");
        scanf(" %c", &choice);
        int dice = rand() % 6 + 1;
        printf("your dice is : %i\n", dice);
        player += dice;
        printf("player score is : %i\n", player);
        checkLadderOrSnake(&player, snake);
        printBoard(board, player);
    }
}

void checkLadderOrSnake(int *player, int snake[2][SHORTCUT])
{
    int size = sizeof(snake[0]) / sizeof(snake[0][0]);
    for (int i = 0; i < size; i++)
    {
        if (snake[0][i] == *player)
        {
            snake[0][i] < snake[1][i]
                ? printf("player climb ladder at %d to %d\n", snake[0][i], snake[1][i])
                : printf("player eaten by snake at %d to %d\n", snake[0][i], snake[1][i]);
            *player = snake[1][i];
            return;
        }
    }
}

void mapBoard(int board[ROWS][COLS])
{
    for (int i = 9; i >= 0; i--)
    {
        for (int j = 1; j <= 10; j++)
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

void printBoard(int board[ROWS][COLS], int player)
{
    printf("============SNAKE & LADDER ============\n");
    for (int i = 9; i >= 0; i--)
    {
        for (int j = 0; j < 10; j++)
        {
            if (player == board[i][j])
            {
                printf(" P1 ");
            }
            else
            {
                printf("%3d ", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("=======================================\n");
}
