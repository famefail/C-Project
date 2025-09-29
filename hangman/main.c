#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

// TODO: Replay game (done)
// store user score (doing)
void playingHangman(int round, char player[10], char answer[10]);

int main(void)
{
    srand(time(NULL));
    char player[10] = "";
    char start[1];
    int round = 0;
    char score[3];
    int mode = 0;
    char **words = NULL;
    char *volcab[3][50] =
        {{"cat", "dog", "sun", "hat", "book", "fish", "tree", "ball", "star", "cake",
          "pen", "cup", "car", "milk", "bird", "frog", "lion", "tiger", "bear", "duck",
          "ship", "moon", "shoe", "hand", "nose", "rain", "kite", "ring", "king", "queen",
          "apple", "pear", "grape", "peach", "corn", "rice", "sand", "rock", "gold", "milk",
          "desk", "door", "wall", "bed", "lamp", "flag", "bell", "dog", "egg", "jam"},
         {"Balance", "Journey", "Lantern", "Miracle", "Kingdom",
          "Ancient", "Pirate", "Thunder", "Castle", "Forest",
          "Garden", "Monster", "Rocket", "Hunter", "Escape",
          "Dragon", "Winter", "Summer", "Artist", "Circus",
          "Shadow", "Guitar", "Leader", "Prison", "Danger",
          "Puzzle", "Jungle", "Island", "Travel", "Farmer",
          "Bridge", "Sword", "Helmet", "Rocket", "Secret",
          "Spirit", "Market", "Leader", "Tunnel", "Wizard",
          "Bottle", "Palace", "Vision", "Desert", "Object",
          "Candle", "System", "Doctor", "River", "Tunnel"},
         {"Abyss", "Zephyr", "Mystify", "Cryptic", "Jigsaw",
          "Exodus", "Quorum", "Vortex", "Phantom", "Zombie",
          "Glyph", "Oblique", "Voyager", "Wraith", "Tundra",
          "Gizmo", "Quasar", "Epoch", "Hydra", "Oracle",
          "Shrine", "Mythical", "Enigma", "Jaguar", "Xyloid",
          "Cobra", "Sphinx", "Bazaar", "Fjord", "Quartz",
          "Mimicry", "Ivory", "Obscure", "Pyramid", "Zealous",
          "Whisper", "Jinxed", "Voodoo", "Knives", "Mosaic",
          "Exile", "Riddle", "Sorcery", "Talisman", "Cipher",
          "Falcon", "Pharaoh", "Labyrinth", "Gargoyle", "Specter"}};

    FILE *fptr;
    fptr = fopen("score.txt", "w");

    if (fptr != NULL)
    {
        printf("success\n");
        fputs("30", fptr);
        fclose(fptr);

        fptr = fopen("score.txt", "r");
        fgets(score, 5, fptr);
        printf("score : %d\n", atoi(score));
        fclose(fptr);
    }
    else
    {
        printf("NOT OPEN\n");
    }

    do
    {
        do
        {
            printf("Please select mode \n1)Easy \n2)Medium \n3) Hard\n-1) Exit \n");
            scanf("%i", &mode);
            if (mode == -1)
                return 1;
        } while (mode > 3 || mode < 1);

        words = volcab[mode - 1];

        int random = rand() % 50;
        char answer[10];
        strcpy(answer, words[random]);

        printf("%s \n", answer); // for debug

        playingHangman(round, player, answer);
        printf("replay (y/n) :");
        scanf("%s", &start);

    } while (strcmp(start, "y") == 0);
};

void playingHangman(int round, char player[10], char answer[10])
{
    while (round < 5)
    {

        char resultFromPlayer[20];

        printf("Guess Word : ");
        scanf("%s", player);

        if (strcasecmp(player, answer) == 0)
        {
            printf("You WON the answer is %s\n", answer);
            break;
        }

        for (int i = 0; i < strlen(answer); i++)
        {
            if (player[i] < 96)
            {
                player[i] += 32;
            }
            if (answer[i] < 96)
            {
                answer[i] += 32;
            }

            resultFromPlayer[i] = player[i] == answer[i] ? player[i] : '_';
        }

        printf("result : %s\n", resultFromPlayer);

        if (round == 4)
            printf("You LOOSE the answer is %s\n", answer);
        round++;
    }
}