/*
** EPITECH PROJECT, 2025
** stoneanalysis
** File description:
** IOperation
*/

#ifndef IOPERATION_HPP_
#define IOPERATION_HPP_

class IOperation {
    public:
        IOperation();
        ~IOperation();
        IOperation(const IOperation &other) = default;
        IOperation &operator=(const IOperation &other) = default;

        /*
  ** @brief Apply the operation using the stored attributes.
  ** @return true if the operation was successful, false otherwise.
  ** @note This function should be overridden in derived classes to
  ** implement the specific behavior of the operation.
  */
        bool virtual apply() = 0;

    protected:
    private:
};

#endif /* !IOPERATION_HPP_ */
