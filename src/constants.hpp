/*
** EPITECH PROJECT, 2025
** stoneanalysis
** File description:
** constants
*/

#ifndef CONSTANTS_HPP_
#define CONSTANTS_HPP_

#include <iostream>
#include <string>
#include <vector>

#define FIRST_FREQUENCY 19000;
#define FREQUENCY_STEP 50;

struct WavHeader {
        char riff[4];  // "RIFF"
        uint32_t chunkSize;
        char wave[4];            // "WAVE"
        char fmt[4];             // "fmt "
        uint32_t subchunk1Size;  // 16 for PCM
        uint16_t audioFormat;    // PCM = 1
        uint16_t numChannels;    // Mono = 1
        uint32_t sampleRate;     // 48000
        uint32_t byteRate;
        uint16_t blockAlign;
        uint16_t bitsPerSample;
        char data[4];  // "data"
        uint32_t dataSize;
};

#endif /* !CONSTANTS_HPP_ */
