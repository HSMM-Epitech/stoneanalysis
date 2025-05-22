/*
** EPITECH PROJECT, 2025
** stoneanalysis
** File description:
** FileManager
*/

#ifndef FILEMANAGER_HPP_
#define FILEMANAGER_HPP_

#include <iostream>
#include <string>
#include <vector>
#include "../constants.hpp"

class FileManager {
    public:
        FileManager();
        ~FileManager();
        void loadFile(const std::string &filepath);
        void saveFile(const std::string &filepath);
        std::vector<int16_t> &getSamples() { return samples; }
        const WavHeader &getHeader() const { return header; }

    protected:
    private:
        std::vector<int16_t> samples;
        WavHeader header;
};

#endif /* !FILEMANAGER_HPP_ */
