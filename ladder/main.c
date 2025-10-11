#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define SHORTCUT 16
#define MAX 30
// TODO
// 1 create board (done)
// 2 add player in board (done)
// 3 add toss system (done)
// 4 add shortcut and ladder (done)
// 5 add player two (to do)

void printBoard(int board[ROWS][COLS], int player[2], int shortcut[2][SHORTCUT], int size);

void mapBoard(int board[ROWS][COLS]);

void checkLadderOrSnake(int *player, int shortcut[2][SHORTCUT], int size);

int main(void)
{
    srand(time(NULL));

    int player[2] = {1, 1};
    int board[ROWS][COLS];
    char choice = 'y';
    mapBoard(board);
    int shortcut[2][SHORTCUT] = {
        {1, 4, 9, 17, 21, 28, 51, 54, 62, 64, 71, 80, 87, 93, 95, 98},
        {38, 14, 31, 7, 42, 84, 67, 34, 19, 60, 91, 100, 24, 73, 75, 79}};
    int shortcutSize = sizeof(shortcut[0]) / sizeof(shortcut[0][0]);
    printBoard(board, player, shortcut, shortcutSize);
    do
    {

        for (int i = 0; i < 2; i++)
        {
            printf("Roll the dice player%i press y : ", i + 1);
            scanf(" %c", &choice);
            int dice = rand() % 6 + 1;
            printf("your dice is : %i\n", dice);
            player[i] += dice;
            printf("Player%i score is : %i\n", i + 1, player[i]);
            checkLadderOrSnake(&player[i], shortcut, shortcutSize);
            printBoard(board, player, shortcut, shortcutSize);
            if (player[i] >= 100)
            {
                printf("Player%i is WON!\n Thank you for play.\n", i);
                return 0;
            }
        }
    } while (choice == 121);
}

void checkLadderOrSnake(int *player, int shortcut[2][SHORTCUT], int size)
{

    for (int i = 0; i < size; i++)
    {
        if (shortcut[0][i] == *player)
        {
            shortcut[0][i] < shortcut[1][i]
                ? printf("Player climb ladder at %d to %d\n", shortcut[0][i], shortcut[1][i])
                : printf("Player eaten by snake at %d to %d\n", shortcut[0][i], shortcut[1][i]);
            *player = shortcut[1][i];
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

void printBoard(int board[ROWS][COLS], int player[2], int shortcut[2][SHORTCUT], int size)
{
    printf("============SNAKE & LADDER ============\n");
    for (int i = 9; i >= 0; i--)
    {
        for (int j = 0; j < 10; j++)
        {
            if (player[0] == board[i][j] && player[1] == board[i][j])
            {
                printf(" P1/P2");
            }
            else if (player[1] == board[i][j])
            {
                printf(" P2 ");
            }
            else if (player[0] == board[i][j])
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
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        int start = shortcut[0][i];
        int end = shortcut[1][i];
        if (start < end)
        {
            printf("ladder %i -> %i\n", start, end);
        }
        else
        {
            printf("snake %i -> %i\n", start, end);
        }
    }

    printf("=======================================\n");
}