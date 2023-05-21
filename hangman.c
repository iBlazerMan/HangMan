#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "words.h"
#include "hangman-io.h"

void hangman(void);

// array_add (a, c) adds the char c to the first null element in the array
// requires: a is not NULL
// effect: mutates a
// time: O(n)
void array_add(char* a, char c) {
    for (int i = 0; ; ++i) {
        if (a[i] == 0) {
            a[i] = c;
            break;
        }
    }
}

// check_exist (a, c) checks if the given char exist in the string
// requires: a is not NULL
// time: O(n) 
bool check_exist(const char* a, char c) {
    assert(a);
    for(int i = 0; ; ++i) {
        if (a[i] == c){
            return true;
        } else if(a[i] == 0) {
            return false;
        }
    }
}

// conclude (stat, a) is a helper function for hangman that returns the result of the game played
// effect: reads input
//         produces output
// requires: a is a valid pointer
// time: O(n)
void conclude(int stat, const char* a) {
    assert(a);
    char inp = '0';
    if (stat == 0) {
        printf(game_over, a);
    } else if (stat == 1) {
        printf(congratulations, a);
    }
    
    while(1) {
        printf("%s", play_again);
        scanf(" %c", &inp);
        if (inp == 'Y' || inp == 'y') {
            hangman();
            break;
        } else if (inp != 'Y' && inp != 'y' && inp != 'N' && inp != 'n') {
        printf("%s", invalid_play_again_response);
        continue;
        }
        break;
    }
}

// hangman() takes input and plays the game hangman
// effect: reads input
//         produces output
// time: O(n^2)
void hangman (void) {
    printf(enter_game_number, min_words, max_words);
    int n = 0;
    scanf(" %d", &n);
    if (n > max_words || n < min_words) {
        printf(invalid_game_number, n);
        hangman();
    } else {
        char w[9] = {};
        char disp[9] = {};
        char guessed[26] = {};
        int len = strlen(get_word(n));
        int strikes = 0;
        char inp = '0';
        strcpy(w, get_word(n));
        for (int i = 0; i < len; ++i) {
            if (w[i] == ' ') {
                disp[i] = ' ';
            } else {
                disp[i] = '*';
            }  
        }
        disp[len] = '\0';
        for (int i = 0; i < 26; ++i) {
            guessed[i] = 0;
        }
        
        print_hangman(strikes);
        while (1) {
            printf("%s", letter_prompt);
            printf("%s\n", disp);
            scanf(" %c", &inp);
            if (!(inp >= 'a' && inp <= 'z') && !(inp >= 'A' && inp <= 'Z')) {
                printf(not_a_letter, inp);
                continue;
            } 
            if (inp >= 'A' && inp <= 'Z') {
                inp = inp - 'A' + 'a';
            } 
            if (check_exist(guessed, inp)) {
                printf(already_guessed_letter, inp);
                continue;
            } 
            if (check_exist(w, inp)) {
                printf(correct_guess, inp);
                for(int i = 0; i < len; ++i) {
                    if (w[i] == inp) {
                        disp[i] = inp;
                    }
                }
                if (strcmp(w, disp) == 0) {
                    conclude(1, w);
                    break;
                }
                array_add(guessed, inp);
            } else if (!check_exist(w, inp)) {
                strikes++;
                array_add(guessed, inp);
                print_hangman(strikes);
                printf (not_in_word, inp);
                if (strikes == max_strikes) {
                    conclude(0, w);
                    break;
                }
                printf(not_last_guess, (max_strikes - strikes));
            }
        }
    }
}

int main(void) {
  hangman();
}
