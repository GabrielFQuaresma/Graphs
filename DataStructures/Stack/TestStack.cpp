#include <iostream>
#include "Stack.cpp" // Inclua o arquivo da pilha

int main() {
    Stack<int> stack;

    // Testando inserções
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Pilha após inserções: ";
    stack.printStack();  // Deve mostrar: 30, 20, 10

    // Testando o topo da pilha
    std::cout << "Topo da pilha: " << stack.top() << std::endl;  // Deve mostrar: 30

    // Testando remoções
    std::cout << "Desempilhando: " << stack.pop() << std::endl;  // Deve mostrar: 30
    std::cout << "Desempilhando: " << stack.pop() << std::endl;  // Deve mostrar: 20

    std::cout << "Pilha após pop(): ";
    stack.printStack();  // Deve mostrar: 10

    // Testando tamanho
    std::cout << "Tamanho da pilha: " << stack.size() << std::endl;  // Deve mostrar: 1

    // Testando se a pilha está vazia
    std::cout << "A pilha está vazia? " << (stack.isEmpty() ? "Sim" : "Não") << std::endl;  // Deve mostrar: Não

    // Testando a pilha vazia
    stack.pop();  // Remove o último elemento

    std::cout << "A pilha está vazia? " << (stack.isEmpty() ? "Sim" : "Não") << std::endl;  // Deve mostrar: Sim

    // Testando erro ao acessar o topo de uma pilha vazia
    try {
        std::cout << "Topo da pilha: " << stack.top() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;  // Deve mostrar erro: Empty Stack.
    }

    return 0;
}
