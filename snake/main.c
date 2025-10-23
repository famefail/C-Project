#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

#define ROWS 25
#define COLS 25
#define MAX_SIZE 4

// TODO
// create board (done)
// add snake (done)
// add fruit (done)
// random fruit (done)
// update snake to stack structure
// move snake update all stack
// when eat growth up

// issue at peekall

typedef struct
{
    int arr[MAX_SIZE];
    int top;

} Stack;

void mapBoard(int board[ROWS][COLS]);

void drawBoard(int board[ROWS][COLS], int *fruit, Stack *player);

void updateCell(int map[11][26], int row, int col, int value);

void moveSnake(char *input, int *player);

void randomFruit(int *fruit);

void eatingFruit(int *player, int *fruit);

void timer();

void initialize(Stack *stack);

void push(Stack *stack, int value);

bool isEmpty(Stack *stack);

int peek(Stack *stack);

void peekAll(Stack *stack);

int pop(Stack *stack);

int main(void)
{
    srand(time(NULL));
    time_t start_time;
    Stack stack;
    initialize(&stack);
    int player = (rand() % 624) + 10;
    push(&stack, (rand() % 624) + 10);
    push(&stack, (rand() % 624) + 10);
    push(&stack, (rand() % 624) + 10);
    int map[ROWS][COLS];
    // peekAll(&stack);

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
        if (fruit == 0)
            randomFruit(&fruit);
        drawBoard(map, &fruit, &stack);

        timer();
    } while (1);
    printf("=======================================\n");
}

void initialize(Stack *stack)
{
    stack->top = -1;
}

bool isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("stack is Empty");
        return 0;
    }
    return stack->arr[stack->top];
}

void push(Stack *stack, int value)
{
    ++stack->top;
    stack->arr[stack->top] = value;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
        return 0;
    int popped = stack->arr[stack->top];
    stack->top--;
    return popped;
}

void peekAll(Stack *stack)
{
    Stack temp;
    int size = stack->top;
    for (int i = 0; i <= size; i++)
    {
        printf("stack %d\n", stack->arr[stack->top]);
        int popped = pop(stack);
        push(&temp, popped);
    }
    stack = &temp;
}

void eatingFruit(int *player, int *fruit)
{
    if (*player == *fruit)
    {
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

void drawBoard(int board[ROWS][COLS], int *fruit, Stack *player)
{
    Stack temp;
    int size = player->top;

    printf("size %d\n", player->arr[5]);
    for (int i = ROWS; i >= 0; i--)
    {
        for (int j = 0; j < COLS; j++)
        {
            for (int k = 0; k <= size; k++)
            {
                printf("stack %d\n", player->arr[player->top]);

                if (player->arr[player->top] < ROWS + 1 || player->arr[player->top] > 625)
                    return;
                else if (player->arr[player->top] == board[i][j])
                    printf("O");

                else if (*fruit == board[i][j])
                    printf("@");
                // else if (player->arr[player->top] == board[i][j])
                //     printf("O");
                else if (i == 0 || i == ROWS || j == COLS - 1 || j == 0)
                    printf("#");
                else
                    printf(" ");
            }

            int popped = pop(player);
            push(&temp, popped);
            // printf("%3d ", board[i][j]);
        }
        printf("\n");
    }
    player = &temp;

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