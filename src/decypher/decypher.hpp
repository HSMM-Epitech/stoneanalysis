/*
** EPITECH PROJECT, 2025
** stoneanalysis
** File description:
** decypher
*/

#ifndef DECYPHER_HPP_
#define DECYPHER_HPP_

#include "../IOperation.hpp"
#include <unordered_map>

class Decypher : public IOperation {
    public:
        Decypher() = default;
        Decypher(char **argv, int argc);
        ~Decypher() override = default;

        bool apply() override { return true; }
    private:
        std::string filePath;
        std::vector<int16_t> samples;
        WavHeader header;
        std::unordered_map<double, char> freqToChar;
        std::string message;

        void initFreqToChar();
};

#endif /* !DECYPHER_HPP_ */
