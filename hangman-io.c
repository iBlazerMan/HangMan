#include <assert.h>
#include <stdio.h>
#include "hangman-io.h"

const int max_strikes = 6;

const char *enter_game_number = 
  "Please enter a valid game number between %d and %d.\n";

const char *invalid_game_number = 
  "Error, %d is not a valid game number.\n\n";

const char *letter_prompt = 
  "Please enter a letter.\n";

const char *not_a_letter = 
  "%c is not a letter.\n\n";

const char *already_guessed_letter = 
  "You have already guessed the letter %c. Please try another letter.\n\n";

const char *not_in_word = 
  "The letter %c is not in the word.\n";

const char *correct_guess =
  "The letter %c is in the word!\n\n";

const char *not_last_guess = 
  "Watch out! You only have %d more guesses left before your man is hung!\n\n";

const char *play_again = 
  "Do you want to play again? (Y for yes, N for no).\n";

const char *invalid_play_again_response = 
  "Error, invalid response.\n\n";

const char *game_over = 
  "Game over. The correct word was %s.\n\n";

const char *congratulations = 
  "You win! The correct word was %s.\n\n";

static char *hangman_ascii[7] = {
"\
0000000000000\n\
0           0\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n",

"\
0000000000000\n\
0           0\n\
0           1\n\
0          1 1\n\
0           1\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n",

"\
0000000000000\n\
0           0\n\
0           1\n\
0          1 1\n\
0           1\n\
0           2\n\
0           2\n\
0           2\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n",

"\
0000000000000\n\
0           0\n\
0           1\n\
0          1 1\n\
0           1\n\
0          32\n\
0         3 2\n\
0        3  2\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n",

"\
0000000000000\n\
0           0\n\
0           1\n\
0          1 1\n\
0           1\n\
0          324\n\
0         3 2 4\n\
0        3  2  4\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n",

"\
0000000000000\n\
0           0\n\
0           1\n\
0          1 1\n\
0           1\n\
0          324\n\
0         3 2 4\n\
0        3  2  4\n\
0          5\n\
0         5\n\
0        5\n\
0       5\n\
0\n\
0\n",

"\
0000000000000\n\
0           0\n\
0           1\n\
0          1 1\n\
0           1\n\
0          324\n\
0         3 2 4\n\
0        3  2  4\n\
0          5 6\n\
0         5   6\n\
0        5     6\n\
0       5       6\n\
0\n\
0\n" };


void print_hangman(int strike) {
  assert(strike >= 0);
  assert(strike <= max_strikes);
  printf("%s", hangman_ascii[strike]);
}
