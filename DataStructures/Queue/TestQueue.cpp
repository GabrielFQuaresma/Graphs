#include <iostream>
#include "Queue.hpp" // Inclua o arquivo de implementação da fila

int main() {
    // Cria uma fila de inteiros
    Queue<int> queue;

    // Teste do método isEmpty (deve retornar true)
    std::cout << "Fila vazia: " << (queue.isEmpty() ? "Sim" : "Não") << std::endl;

    // Enfileira alguns elementos
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    // Teste do método size (deve retornar 3)
    std::cout << "Tamanho da fila: " << queue.size() << std::endl;

    // Testa o método search (deve retornar true para 20 e false para 40)
    std::cout << "Elemento 20 na fila: " << (queue.search(20) ? "Sim" : "Não") << std::endl;
    std::cout << "Elemento 40 na fila: " << (queue.search(40) ? "Sim" : "Não") << std::endl;

    // Desenfileira e imprime os elementos
    std::cout << "Desenfileirando: " << queue.dequeue() << std::endl; // Deve retornar 10
    std::cout << "Desenfileirando: " << queue.dequeue() << std::endl; // Deve retornar 20

    // Teste do método size após desenfileirar (deve retornar 1)
    std::cout << "Tamanho da fila: " << queue.size() << std::endl;

    // Testa o método isEmpty novamente (deve retornar false)
    std::cout << "Fila vazia: " << (queue.isEmpty() ? "Sim" : "Não") << std::endl;

    // Desenfileira o último elemento
    std::cout << "Desenfileirando: " << queue.dequeue() << std::endl; // Deve retornar 30

    // Testa o método isEmpty após desenfileirar todos os elementos (deve retornar true)
    std::cout << "Fila vazia: " << (queue.isEmpty() ? "Sim" : "Não") << std::endl;

    // Tentativa de desenfileirar de uma fila vazia (deve lançar uma exceção)
    try {
        queue.dequeue();
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    return 0;
}
