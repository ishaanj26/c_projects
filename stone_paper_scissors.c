/*
STONE PAPER AND SCISSORS GAME
Code improved by Ishaan Jain
You can Copy and Learn
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to implement the game
int score = 0, c_score = 0;
int game(char you, char computer)
{
	// If both the user and computer has chosen the same char
	if (you == computer)
		return -1;

	// If user's choice is stone and
	// computer's choice is paper
	else if (you == 's' && computer == 'p')
		return 0;

	// If user's choice is paper and
	// computer's choice is stone
	else if (you == 'p' && computer == 's')
		return 1;

	// If user's choice is stone and
	// computer's choice is scissor
	else if (you == 's' && computer == 'z')
		return 1;

	// If user's choice is scissor and
	// computer's choice is stone
	else if (you == 'z' && computer == 's')
		return 0;

	// If user's choice is paper and
	// computer's choice is scissor
	else if (you == 'p' && computer == 'z')
		return 0;

	// If user's choice is scissor and
	// computer's choice is paper
	else if (you == 'z' && computer == 'p')
		return 1;
	else
	{
		printf("Invalid Input\n");
		return 8;
	}
}
void start()
{
	system("cls");
	// input from the user
	int random_number, result;
	char user, computer;
	srand(time(0));
	random_number = rand() % 100;
	if (random_number < 33)
		// s is denoting Stone
		computer = 's';

	else if (random_number > 33 && random_number < 66)

		// p is denoting Paper
		computer = 'p';

	// z is denoting Scissor
	else
		computer = 'z';

	printf("Enter s for STONE, p for PAPER and z for SCISSOR\n");

	// input from the user
	scanf(" %c", &user);
	system("cls");
	printf("Computer chose %c\n", computer);
	// Function Call to play the game
	result = game(user, computer);

	if (result == 8)
	{
		return;
	}
	if (result == -1)
	{
		printf("Game Draw!\n");
		printf("\nYour score is %d\n\n", score);

	}
	else if (result == 1)
	{
		score += 1;
		printf("\nWow! You have won the game!\n");
		printf("\nYour score is %d\n", score);
		printf("Computer score is %d\n\n", c_score);
	}
	else
	{
		c_score += 1;
		printf("\nOh! You have lost the game!\n");
		printf("\nYour score is %d\n", score);
		printf("Computer score is %d\n\n", c_score);
	}
}

int main()
{
	while (1)
	{
		int input;
		printf("Enter 1 to start the game\nEnter 2 to restart the game \nEnter 3 to show the scores\nEnter 4 to quit the game\n");
		scanf("%d", &input);
		if (input == 1)
		{
			start();
		}
		else if (input == 2)
		{
			score = 0;
			c_score = 0;
			start();
		}
		else if (input == 3)
		{
			system("cls");
			printf("\nYour score is %d\n", score);
			printf("Computer score is %d\n\n", c_score);
		}
		else if (input == 4)
		{
			break;
		}
		else
		{
			printf("\nInvalid Input");
		}
	}
	return 0;
}
