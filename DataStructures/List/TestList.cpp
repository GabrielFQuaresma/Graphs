#include "LinkedList.hpp"
#include <iostream>

int main() {
    LinkedList<int> list;

    // Testando inserções
    list.pushFront(10);
    list.pushFront(20);
    list.pushBack(30);
    list.insert(25, 2);

    std::cout << "Lista após inserções: ";
    list.printList();  // Deve mostrar: 20, 10, 25, 30

    // Testando remoções
    list.popFront();
    std::cout << "Lista após popFront(): ";
    list.printList();  // Deve mostrar: 10, 25, 30

    list.popBack();
    std::cout << "Lista após popBack(): ";
    list.printList();  // Deve mostrar: 10, 25

    list.remove(0);
    std::cout << "Lista após remover a posição 0: ";
    list.printList();  // Deve mostrar: 25

    // Testando busca
    bool found = list.search(25);
    std::cout << "O valor 25 está na lista? " << (found ? "Sim" : "Não") << std::endl;

    found = list.search(10);
    std::cout << "O valor 10 está na lista? " << (found ? "Sim" : "Não") << std::endl;

    // Testando tamanho
    std::cout << "Tamanho da lista: " << list.size() << std::endl;  // Deve mostrar: 1

    // Testando se a lista está vazia
    std::cout << "A lista está vazia? " << (list.isEmpty() ? "Sim" : "Não") << std::endl;  // Deve mostrar: Não

    return 0;
}
