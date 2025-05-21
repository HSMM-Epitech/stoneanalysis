/*
** EPITECH PROJECT, 2025
** stoneanalysis
** File description:
** cypher
*/

#include "cypher.hpp"

Cypher::Cypher(char **argv, int argc) : IOperation(argv, argc)
{
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " --cypher IN_FILE OUT_FILE MESSAGE" << std::endl;
        exit(84);
    }
    filePath = argv[2];
    outFilePath = argv[3];
    message = argv[4];
}