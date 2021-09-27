/*
Author: Pietro Piva Vieira
Purpose: This program is a little game about guessing numbers
Date: 27/09/2021 (day/month/year)

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main()
{
  time_t t;
  srand((unsigned)time(&t));

  int randomNumber = rand() % 21;
  int numberOfTries = 5;
  int playerGuess;

  printf("This is a guessing game.\n");
  printf("I have chosen a number between 0 and 20 which you must guess.\n");

  while (numberOfTries != 0) 
  {
    printf("You have %d tries left.\n", numberOfTries);
    printf("Enter a guess: ");
    scanf("%d", &playerGuess);

    _Bool isGuessOutOfRange = ((playerGuess < 0) || (playerGuess > 20));
    if (isGuessOutOfRange)
    {
      printf("The value is only between 0 and 20!\n");
      continue;
    }

    _Bool isGuessTooHigh = ((playerGuess != randomNumber) && (playerGuess > randomNumber));
    _Bool isGuessTooLow = ((playerGuess != randomNumber) && (playerGuess < randomNumber));
    if (isGuessTooLow)
    {
      printf("Sorry, %d is wrong, My number is greater than that.\n", playerGuess);
      numberOfTries--;
    } else if (isGuessTooHigh) {
      printf("Sorry, %d is wrong, My number is less than that.\n", playerGuess);
      numberOfTries--;
    }

    _Bool isOutOfTries = (numberOfTries == 0);
    if (isOutOfTries)
    {
      printf("Too bad, you runned out of tries :P\n");
      printf("The number was %d", randomNumber);
      break;
    }

    _Bool isGuessRight = (playerGuess == randomNumber);
    if (isGuessRight)
    {
      printf("Congratulations! You guessed it!");
      break;
    }
  }

  return 0;
}