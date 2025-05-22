/*
** EPITECH PROJECT, 2025
** stoneanalysis
** File description:
** decypher
*/

#include "decypher.hpp"
#include "../constants.hpp"

Decypher::Decypher(char **argv, int argc) : IOperation(argv, argc) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " --decypher IN_FILE" << std::endl;
        exit(84);
    }
    filePath = argv[2];
    initFreqToChar();
}

void Decypher::initFreqToChar() {
    int frequency = FIRST_FREQUENCY;

    for (char c = 'a'; c <= 'z'; ++c) {
        freqToChar[c] = frequency;
        frequency += FREQUENCY_STEP;
    }
    for (char c = 'A'; c <= 'Z'; ++c) {
        freqToChar[c] = frequency;
        frequency += FREQUENCY_STEP;
    }
    for (char c = '0'; c <= '9'; ++c) {
        freqToChar[c] = frequency;
        frequency += FREQUENCY_STEP;
    }
}