#include <iostream>
#include "LinearList.hpp"


int main() {
    // Testando o construtor padrão
    LinearList<int> list1;

    // Testando a inserção de elementos
    list1.pushBack(10);
    list1.pushBack(20);
    list1.pushBack(30);

    std::cout << "List 1 após pushBack(10), pushBack(20), pushBack(30): " << list1 << std::endl;

    // Testando o método de popBack
    list1.popBack();
    std::cout << "List 1 após popBack: " << list1 << std::endl;

    // Testando pushFront e popFront
    list1.pushFront(5);
    std::cout << "List 1 após pushFront(5): " << list1 << std::endl;

    list1.popFront();
    std::cout << "List 1 após popFront: " << list1 << std::endl;

    // Testando inserção em posição específica
    list1.insert(25, 1);
    std::cout << "List 1 após insert(25, 1): " << list1 << std::endl;

    // Testando acesso direto via operador []
    std::cout << "Elementos individuais: " << list1[0] << ", " << list1[1] << std::endl;

    // Testando remoção de posição específica
    list1.remove(1);
    std::cout << "List 1 após remove(1): " << list1 << std::endl;

    // Testando comparação de listas
    LinearList<int> list2;
    list2.pushBack(10);
    list2.pushBack(20);
    
    if (list1 == list2) {
        std::cout << "List 1 é igual à List 2" << std::endl;
    } else {
        std::cout << "List 1 é diferente de List 2" << std::endl;
    }

    // Testando o construtor de intervalo
    LinearList<int> list3(5, 10);
    std::cout << "List 3 (construtor de intervalo [5,10]): " << list3 << std::endl;

    // Testando redimensionamento manual
    list3.reserve(20);
    std::cout << "List 3 após reserve(20): " << list3 << std::endl;

    // Testando o método shrink_to_fit
    list3.shrink_to_fit();
    std::cout << "List 3 após shrink_to_fit(): " << list3 << std::endl;

    return 0;
}
