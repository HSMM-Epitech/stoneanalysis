/*
** EPITECH PROJECT, 2025
** stoneanalysis
** File description:
** decypher
*/

#ifndef DECYPHER_HPP_
#define DECYPHER_HPP_

#include <iostream>
#include "../IOperation.hpp"

class Decypher : public IOperation {
    public:
        Decypher() = default;
        ~Decypher() = default;

        bool apply() override { return true; }
};

#endif /* !DECYPHER_HPP_ */
