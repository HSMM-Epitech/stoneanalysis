/*
** EPITECH PROJECT, 2025
** stoneanalysis
** File description:
** analyze
*/

#include "analyze.hpp"

Analyze::Analyze(char **argv, int argc) : IOperation(argv, argc)
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " --analyze IN_FILE N" << std::endl;
        exit(84);
    }
    filePath = argv[2];
    n = std::stoi(argv[3]);
}