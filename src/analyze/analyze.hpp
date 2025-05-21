/*
** EPITECH PROJECT, 2025
** stoneanalysis
** File description:
** analyze
*/

#ifndef ANALYZE_HPP_
#define ANALYZE_HPP_

#include "../IOperation.hpp"

class Analyze : public IOperation {
    public:
        Analyze() = default;
        Analyze(char **argv, int argc);
        ~Analyze() override = default;

        bool apply() override { return true; }
    private:
        std::string filePath;
        int n;
        std::vector<int16_t> samples;
        WavHeader header;
};

#endif /* !ANALYZE_HPP_ */
