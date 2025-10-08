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
// create push method explan then use with snake/ladder
// 5 add player two (to do)

void printBoard(int board[ROWS][COLS], int player, int shortcut[2][SHORTCUT], int size);

void mapBoard(int board[ROWS][COLS]);

void checkLadderOrSnake(int *player, int shortcut[2][SHORTCUT], int size);

typedef struct Stack
{
    int data[MAX];
    int top;
} Stack;

int main(void)
{
    srand(time(NULL));

    int player = 1;
    int playerTwo = 1;
    int board[ROWS][COLS];
    char choice = 'y';

    mapBoard(board);
    int shortcut[2][SHORTCUT] = {
        {1, 4, 9, 17, 21, 28, 51, 54, 62, 64, 71, 80, 87, 93, 95, 98},
        {38, 14, 31, 7, 42, 84, 67, 34, 19, 60, 91, 100, 24, 73, 75, 79}};
    int shortcutSize = sizeof(shortcut[0]) / sizeof(shortcut[0][0]);
    printBoard(board, player, shortcut, shortcutSize);
    while (player < 100)
    {

        printf("Roll the dice press y : ");
        scanf(" %c", &choice);
        int dice = rand() % 6 + 1;
        printf("your dice is : %i\n", dice);
        player += dice;
        printf("player score is : %i\n", player);
        checkLadderOrSnake(&player, shortcut, shortcutSize);
        printBoard(board, player, shortcut, shortcutSize);
    }
}

void checkLadderOrSnake(int *player, int shortcut[2][SHORTCUT], int size)
{

    for (int i = 0; i < size; i++)
    {
        if (shortcut[0][i] == *player)
        {
            shortcut[0][i] < shortcut[1][i]
                ? printf("player climb ladder at %d to %d\n", shortcut[0][i], shortcut[1][i])
                : printf("player eaten by snake at %d to %d\n", shortcut[0][i], shortcut[1][i]);
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

void printBoard(int board[ROWS][COLS], int player, int shortcut[2][SHORTCUT], int size)
{
    char *snake[30];
    char *ladder[20];
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
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        int start = shortcut[0][i];
        int end = shortcut[1][i];
        if (start < end)
        {
            snake[0] = malloc(15 * sizeof(char));
            int snakeSize = sizeof(snake) / sizeof(snake[0]);
            // printf("ladder %i -> %i\n", start, end);
            sprintf(snake[0], "ladder %d -> %d\n", start, end);
        }
        else
        {
            // printf("snake %i -> %i\n", start, end);
        }
    }

    int snakeSize = sizeof(snake) / sizeof(snake[0]);
    if (snake)
        printf("%s\n", snake[0]);
    printf("=======================================\n");
}

void push(Stack *s,int value)
{
    if (s->top > MAX)
    {
        printf("Stack overflow");
    }
    else
    {
     s->top++;
     s->data[s->top] = value;   
    }
}