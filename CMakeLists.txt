cmake_minimum_required (VERSION 3.26.3)
project (HangMan)
include_directories(module)
add_executable (HangMan hangman.c hangman-io.c ./module/words.c)
