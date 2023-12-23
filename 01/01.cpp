﻿// Домашнее задание к занятию «Умные указатели»
// Задача 1. Клонирование объекта класса

#include <iostream>
#include <vector>
#include <memory>

class tridiagonal_matrix
{
public:
    std::vector<double> m_down;
    std::vector<double> m_upper;
    std::vector<double> m_middle;

    tridiagonal_matrix(
        const std::vector<double>& down,
        const std::vector<double>& upper,
        const std::vector<double>& middle) :
        m_down{ down }, m_upper{ upper }, m_middle{ middle }
    {};
    ~tridiagonal_matrix() { std::cout << this << " destructor called\n"; }

    std::unique_ptr<tridiagonal_matrix> clone()
    {
        auto clone = std::make_unique<tridiagonal_matrix>(m_down, m_upper, m_middle);
        std::cout << "\nfunction clone was called\n";

        return clone;
    };
};

int main()
{
    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };
    auto matrix = std::make_unique<tridiagonal_matrix>(down, upper, middle);
    auto matrix_clone = matrix->clone();
    
    std::cout << "matrix = " << matrix << std::endl;
    std::cout << "matrix_clone = " << matrix_clone.get() << std::endl;

    std::cout << "\n\nHello World!\n\n";
}