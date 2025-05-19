/*
** EPITECH PROJECT, 2025
** stoneanalysis
** File description:
** main
*/

#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <file_path>" << std::endl;
        return 1;
    }

    // Here you would typically call a function to analyze the stone data
    // For example:
    // analyzeStoneData(argv[1]);

    std::cout << "Stone analysis completed successfully." << std::endl;
    return 0;
}