/*
HANGMAN GAME
Code improved by Ishaan Jain
You can Copy and Learn
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void shape(int numLives)
{
    if (numLives == 5)
    {
        printf("\n");
        printf("   _____\n");
        printf("  |     |\n");
        printf("  |     O\n");
        printf("  |\n");
        printf("  |\n");
        printf("  |\n");
        printf("  |\n");
    }
    if (numLives == 4)
    {
        printf("\n");
        printf("   _____  \n");
        printf("  |     | \n");
        printf("  |     O \n");
        printf("  |     | \n");
        printf("  |\n");
        printf("  |\n");
        printf("  |\n");
    }
    if (numLives == 3)
    {
        printf("\n");
        printf("   _____  \n");
        printf("  |     | \n");
        printf("  |     O \n");
        printf("  |    /| \n");
        printf("  |\n");
        printf("  |\n");
        printf("  |\n");
    }
    if (numLives == 2)
    {
        printf("\n");
        printf("   _____   \n");
        printf("  |     |  \n");
        printf("  |     O  \n");
        printf("  |    /|\\ \n");
        printf("  |        \n");
        printf("  |\n");
        printf("  |\n");
    }
    if (numLives == 1)
    {
        printf("\n");
        printf("   _____\n");
        printf("  |     |\n");
        printf("  |     O\n");
        printf("  |    /|\\ \n");
        printf("  |    /  \n");
        printf("  |\n");
        printf("  |\n");
    }
    if (numLives == 0)
    {
        printf("\n");
        printf("   _____\n");
        printf("  |     |\n");
        printf("  |     O\n");
        printf("  |    /|\\ \n");
        printf("  |    / \\ \n");
        printf("  |\n");
        printf("  |\n");
    }
}

int main()
{
    srand(time(NULL)); // to get different random value after each run
    char guessWords[][16] = {"green", "yellow", "purple", "windows", "linux", "apple"};
    int randomIndex = rand() % 6;
    int numLives = 5;
    int numCorrect = 0;
    int oldCorrect = 0;

    int lengthofWord = strlen(guessWords[randomIndex]);
    //
    char letterGuessed[8] = {'_', '_', '_', '_', '_', '_', '_', '_'};

    int quit = 0;

    char guess[16];
    char letterEntered[16];
    int number = 0;
    // game loop
    while (numCorrect < lengthofWord)
    {
        shape(numLives);
        printf("Guess a letter: ");
        fgets(guess, 16, stdin);
        system("cls");
        if (strncmp(guess, "quit", 4) == 0)
        {
            quit = 1;
            break;
        }
        letterEntered[number] = guess[0]; // to take the first letter of input
        printf("Letter entered: \n");
        for (int i = 0; i <= number; i++)
        {
            printf("%c\t", letterEntered[i]);
        }
        printf("\n");
        oldCorrect = numCorrect;

        for (int i = 0; i < lengthofWord; i++)
        {

            if (letterGuessed[i] != '_') // will see if the letter in the word is _ means char found
            {
                continue;
            }
            if (letterEntered[number] == guessWords[randomIndex][i])
            {

                letterGuessed[i] = letterEntered[number];
                numCorrect++;
            }
        }
        printf("\n\t\t");
        for (int i = 0; i < lengthofWord; i++)
        {
            printf("%c", letterGuessed[i]);
        }
        printf("\n");

        if (oldCorrect == numCorrect)
        {
            numLives--;
            printf("Sorry!!!Wrong Guess\n");
            if (numLives == 0)
            {
                system("cls");
                printf("Number of Guesses are over\n");
                break;
            }
        }
        else
        {
            printf("It is a correct guess!!\n");
        }

        number++;
    }

    if (quit == 1)
    {
        printf("The user quit early");
    }
    else if (numLives == 0)
    {

        shape(numLives);
        printf("Sorry, you lose, the word was: <~~~%s~~~>\n", guessWords[randomIndex]);
    }
    else
    {
        shape(numLives);
        printf("You have won!!!!\n");
    }
    return 0;
}