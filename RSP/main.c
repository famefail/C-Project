#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int playing(int player, int bot);

int main(void)
{
    int player;
    printf("0=rock 1=scissor 2=paper -1 =Exit\n");
    do
    {

        if (player == -1)
        {
            printf("End game\n");
            break;
        }

        printf("choose your hand : ");
        scanf("%i", &player);
        int bot = rand() % 3;

        printf("bot : %i \n", bot);
        printf("player : %i \n", player);

        playing(player, bot);

    } while (1);
}

int playing(int player, int bot)
{
    if (player == bot)
        printf("draw\n");
    else if ((player % 3) + 1 == bot)
        printf("loses\n");
    else
        printf("win\n");
}