/*
** EPITECH PROJECT, 2025
** stoneanalysis
** File description:
** cypher
*/

#ifndef CYPHER_HPP_
#define CYPHER_HPP_

#include "../IOperation.hpp"

class Cypher : public IOperation {
    public:
        Cypher() = default;
        Cypher(char **argv, int argc);
        ~Cypher() override = default;

        bool apply() override { return true; }

    private:
        std::string filePath;
        std::string outFilePath;
        std::string message;
        std::vector<int16_t> samples;
        WavHeader header;
};

#endif /* !CYPHER_HPP_ */
