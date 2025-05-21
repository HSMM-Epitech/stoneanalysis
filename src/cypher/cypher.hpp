/*
** EPITECH PROJECT, 2025
** stoneanalysis
** File description:
** cypher
*/

#ifndef CYPHER_HPP_
#define CYPHER_HPP_

#include <iostream>
#include "../IOperation.hpp"

class Cypher : public IOperation {
    public:
        Cypher() = default;
        ~Cypher() = default;

        bool apply() override { return true; }
};

#endif /* !CYPHER_HPP_ */
