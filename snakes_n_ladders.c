/*
SNAKES ABD LADDERS GAME
Code improved by Ishaan Jain
You can Copy and Learn
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int diceThrow();
void displaychart(int curp, char player[4]);

int main()
{
    srand(time(NULL));
    int dice;
    int player1 = 0, player2 = 0;
    char ch;
    while (1)
    {
        /* code */

        printf("\t SNAKE AND LADDER GAME \n");
    re:
        printf("Enter 1 for User1\n");
        printf("Enter 2 for User2\n");
        printf("Enter 3 to Exit\n");
        scanf(" %c", &ch);
        switch (ch)
        {
        case '1':
        player1:
            system("cls");
            dice = diceThrow();
            printf("The dice throws %d\n", dice);
            player1 = player1 + dice;
            if (player1 <= 100)
            {
                if (player1 == 13)
                {
                    printf("Ladder Touched..You have reached 42\n");
                    displaychart(42, "$P1$"); // ladder
                    player1 = 42;
                }
                else if (player1 == 25)
                {
                    printf("Snake Touched..You have reached 9\n");
                    displaychart(9, "$P1$"); // snake
                    player1 = 9;
                }
                else if (player1 == 60)
                {
                    printf("Ladder Touched..You have reached 83\n");
                    displaychart(83, "$P1$"); // ladder
                    player1 = 83;
                }
                else if (player1 == 65)
                {
                    printf("Snake touched..You have reached 40\n");
                    displaychart(40, "$P1$"); // snake
                    player1 = 40;
                }

                else if (player1 == 70)
                {
                    printf("Ladder Touched..You have reached 93\n");
                    displaychart(93, "$P1$"); // ladder
                    player1 = 93;
                }

                else if (player1 == 99)
                {
                    printf("Snake Touched..You have reached 1\n");
                    displaychart(1, "$P1$"); // snake
                    player1 = 1;
                }
                else
                {
                    displaychart(player1, "$P1$");
                }
                if (dice == 6)
                {
                    printf("YAYYY 6!!!You have got an extra throw!!!\n");
                    getch();
                    goto player1;
                }
            }
            else
            {
                player1 = player1 - dice;
                printf("Player1 have exceed the range \n");
                displaychart(player1, "$P1$");
            }
            printf("Player 2 position is %d\n", player2);
            break;
        case '2':
        player2:
            system("cls");
            dice = diceThrow();
            printf("The dice throws %d\n", dice);
            player2 = player2 + dice;
            if (player2 <= 100)
            {
                if (player2 == 13)
                {
                    printf("Ladder Touched..You have reached 42\n");
                    displaychart(42, "$P2$"); // ladder
                    player2 = 42;
                }

                else if (player2 == 25)
                {
                    printf("Snake Touched..You have reached 9\n");
                    displaychart(9, "$P2$"); // snake
                    player2 = 9;
                }

                else if (player2 == 60)
                {
                    printf("Ladder Touched..You have reached 83\n");
                    displaychart(83, "$P2$"); // ladder
                    player2 = 83;
                }

                else if (player2 == 65)
                {
                    printf("Snake Touched..You have reached 40\n");
                    displaychart(40, "$P2$"); // snake
                    player2 = 40;
                }
                else if (player2 == 70)
                {
                    printf("Ladder Touched..You have reached 93\n");
                    player2 = 93;
                    displaychart(93, "$P2$"); // ladder
                }
                else if (player2 == 99)
                {
                    printf("Snake Touched..You have reached 1\n");
                    displaychart(1, "$P2$"); // snake
                    player2 = 1;
                }
                else
                {
                    displaychart(player2, "$P2$");
                }
                if (dice == 6)
                {
                    printf("YAYYY 6!!!You have got an extra throw!!!\n");
                    getch();
                    goto player2;
                }
            }
            else
            {
                player2 = player2 - dice;
                printf("Player1 have exceed the range \n");
            }
            printf("Player 1 position is %d\n", player1);
            break;
        case '3':
            exit(0);
        default:
            printf("You have entered a wrong char, Please Try again\n");
            goto re;
        }
    }
}

int diceThrow()
{
    int rem;
    rem = (rand() % 6) + 1;
    return rem;
}

void displaychart(int position, char player[4])
{
    if (position == 100)
    {
        printf("Congratulation!!!!Player %s has won.", player);
        exit(0);
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            int checker = (i * 10) + j;
            if (checker == position)
            {
                printf("%s\t", player);
            }
            else
            {
                printf("%3d\t", checker);
            }
        }
        printf("\n");
    }
}
