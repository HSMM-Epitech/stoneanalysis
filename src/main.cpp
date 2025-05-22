/*
** EPITECH PROJECT, 2025
** stoneanalysis
** File description:
** main
*/

#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "FileManager/FileManager.hpp"
#include "analyze/analyze.hpp"
#include "cypher/cypher.hpp"
#include "decypher/decypher.hpp"

// void DFT(const std::vector<double>& in, std::vector<std::complex<double>>& out);
// void IDFT(const std::vector<std::complex<double>>& in, std::vector<double>& out);
// void FFT(const std::vector<double>& in, std::vector<std::complex<double>>& out);
// void IFFT(const std::vector<std::complex<double>>& in, std::vector<double>& out);

/*
USAGE
./stone_analysis [--analyze IN_FILE N | --cypher IN_FILE OUT_FILE MESSAGE | --decypher IN_FILE]
IN_FILE An audio file to be analyzed
OUT_FILE Output audio file of the cypher mode
MESSAGE The message to hide in the audio file
N Number of top frequencies to display
*/

bool hasFlag(char **argv, int argc, const std::string &flag) {
    for (int i = 0; i < argc; ++i) {
        if (argv[i] == flag) {
            return true;
        }
    }
    return false;
}

std::string getUsage() {
    return "Usage: ./stone_analysis [--analyze IN_FILE N | --cypher IN_FILE OUT_FILE MESSAGE | --decypher IN_FILE]\n"
           "IN_FILE An audio file to be analyzed\n"
           "OUT_FILE Output audio file of the cypher mode\n"
           "MESSAGE The message to hide in the audio file\n"
           "N Number of top frequencies to display";
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << getUsage() << std::endl;
        return 84;
    }
    if (hasFlag(argv, argc, "--help")) {
        std::cout << getUsage() << std::endl;
        return 0;
    }
    std::string operation = argv[1];
    std::map<std::string, std::function<IOperation *(char **, int)>> operations = {{"--analyze",
                                                                                    [](char **argv, int argc) {
                                                                                        return new Analyze(argv, argc);
                                                                                    }},
                                                                                   {"--cypher",
                                                                                    [](char **argv, int argc) {
                                                                                        return new Cypher(argv, argc);
                                                                                    }},
                                                                                   {"--decypher", [](char **argv, int argc) {
                                                                                        return new Decypher(argv, argc);
                                                                                    }}};
    auto it = operations.find(operation);
    if (it == operations.end()) {
        std::cerr << "Invalid operation: " << operation << std::endl << getUsage() << std::endl;
        return 84;
    }
    IOperation *op = it->second(argv, argc);
    if (!op) {
        std::cerr << "Failed to create operation object." << std::endl << getUsage() << std::endl;
        return 84;
    }
    if (!op->apply()) {
        std::cerr << "Operation failed." << std::endl << getUsage() << std::endl;
        delete op;
        return 84;
    }
    delete op;
    std::cout << "Stone analysis completed successfully." << std::endl;
    return 0;
}