#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "words.h"

const int max_words = 8;
const int min_words = 3;

const char* get_word(int n) {
    srand(time(NULL));   
    int r = (rand() % 10);

    const char** dict[9];
    const char* three[10];
    const char* four[10];
    const char* five[10];
    const char* six[10];
    const char* seven[10];
    const char* eight[10];
    for (int i = 0; i < max_words; ++i) {
        dict[i] = NULL;
    }
    dict[3] = three;
    dict[4] = four;
    dict[5] = five;
    dict[6] = six;
    dict[7] = seven;
    dict[8] = eight;

    three[0] = "big";
    three[1] = "bed";
    three[2] = "cry";
    three[3] = "cow";
    three[4] = "dug";
    three[5] = "dot";
    three[6] = "elf";
    three[7] = "fly";
    three[8] = "get";
    three[9] = "paw";

    four[0] = "come";
    four[1] = "bell";
    four[2] = "play";
    four[3] = "sing";
    four[4] = "game";
    four[5] = "four";
    four[6] = "tree";
    four[7] = "dark";
    four[8] = "moon";
    four[9] = "kick";

    five[0] = "other";
    five[1] = "about";
    five[2] = "which";
    five[3] = "their";
    five[4] = "every";
    five[5] = "lunch";
    five[6] = "cloth";
    five[7] = "stone";
    five[8] = "elite";
    five[9] = "peach";

    six[0] = "cheese";
    six[1] = "accept";
    six[2] = "corner";
    six[3] = "divide";
    six[4] = "hidden";
    six[5] = "layout";
    six[6] = "lesson";
    six[7] = "system";
    six[8] = "people";
    six[9] = "excuse";

    seven[0] = "control";
    seven[1] = "picture";
    seven[2] = "because";
    seven[3] = "country";
    seven[4] = "example";
    seven[5] = "without";
    seven[6] = "advance";
    seven[7] = "benefit";
    seven[8] = "ceiling";
    seven[9] = "network";

    eight[0] = "collapse";
    eight[1] = "commerce";
    eight[2] = "definite";
    eight[3] = "keyboard";
    eight[4] = "moderate";
    eight[5] = "official";
    eight[6] = "remember";
    eight[7] = "quanlity";
    eight[8] = "positive";
    eight[9] = "warranty";

    return dict[n][r];
}