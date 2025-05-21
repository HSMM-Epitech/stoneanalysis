/*
** EPITECH PROJECT, 2025
** stoneanalysis
** File description:
** main
*/

#include <iostream>
#include <string>
#include <vector>
#include "analyze/analyze.hpp"
#include "cypher/cypher.hpp"
#include "decypher/decypher.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <file_path>" << std::endl;
        return 84;
    }
    std::cout << "Stone analysis completed successfully." << std::endl;
    return 0;
}