#include <iostream>
#include "FlexibleMatrix.hpp" 

int main() {
    // Criando uma matriz 3x3 de inteiros
    FlexibleMatrix<int> matrix(3, 3);

    // Atribuindo valores à matriz
    matrix.at(0, 0) = 1;
    matrix.at(0, 1) = 2;
    matrix.at(0, 2) = 3;
    matrix.at(1, 0) = 4;
    matrix.at(1, 1) = 5;
    matrix.at(1, 2) = 6;
    matrix.at(2, 0) = 7;
    matrix.at(2, 1) = 8;
    matrix.at(2, 2) = 9;

    // Imprimindo a matriz
    std::cout << "Matrix:" << std::endl;
    matrix.print();

    // Testando o método de busca
    int searchValue = 5;
    bool found = matrix.search(searchValue);
    std::cout << "\nSearch for value " << searchValue << ": " << (found ? "Found" : "Not Found") << std::endl;

    // Testando o construtor de cópia
    FlexibleMatrix<int> copiedMatrix = matrix;
    std::cout << "\nCopied Matrix:" << std::endl;
    copiedMatrix.print();

    // Modificando a matriz original e verificando se a cópia não foi afetada
    matrix.at(0, 0) = 10;
    std::cout << "\nModified Original Matrix:" << std::endl;
    matrix.print();
    std::cout << "\nUnchanged Copied Matrix:" << std::endl;
    copiedMatrix.print();

    // Testando o operador de atribuição
    FlexibleMatrix<int> assignedMatrix(3, 3);
    assignedMatrix = matrix;
    std::cout << "\nAssigned Matrix:" << std::endl;
    assignedMatrix.print();

    // Verificando o acesso fora dos limites
    try {
        int value = matrix.at(3, 3); // Acessando uma posição fora dos limites
    } catch (const std::out_of_range& e) {
        std::cout << "\nException caught: " << e.what() << std::endl;
    }

    return 0;
}
