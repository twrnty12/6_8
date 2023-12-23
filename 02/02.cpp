// Домашнее задание к занятию «Умные указатели»
// # Задача 2. Устранение пересечения

#include <iostream>
#include <vector>
#include <memory>

class node
{
public:
    int m_value;
    //std::shared_ptr<node> parent; // меняем std::shared_ptr на std::weak_ptr
    std::weak_ptr<node> parent; // меняем std::shared_ptr на std::weak_ptr
    node(int value) : m_value{ value } { std::cout << this << " constructor called\n"; };
    ~node() { std::cout << this << " destructor called\n"; }
};

int main()
{
    {
        auto node1 = std::make_shared<node>(1); // создание указателя node1 на объект 1 класса node
        auto node2 = std::make_shared<node>(2); // создание указателя node2 на объект 2 класса node

       

        node1->parent = node2;
        node2->parent = node1;

        
    }

    return 0;
}