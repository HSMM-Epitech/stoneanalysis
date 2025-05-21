/*
** EPITECH PROJECT, 2025
** stoneanalysis
** File description:
** analyze
*/

#ifndef ANALYZE_HPP_
#define ANALYZE_HPP_

#include <iostream>
#include "../IOperation.hpp"

class Analyze : public IOperation {
    public:
        Analyze() = default;
        ~Analyze() = default;

        bool apply() override { return true; }
};

#endif /* !ANALYZE_HPP_ */
