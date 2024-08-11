#include <iostream>
#include <stdexcept>

template <typename T>
class FlexibleMatrix {
  private:
    T** data;
    int rows;
    int cols;

  public:
    FlexibleMatrix(int rows, int cols) : rows(rows), cols(cols) {
        data = new T*[rows]; //Não é necessário parenteses pq não está sendo inicializado com nenhum valor padrão
        for (int i = 0; i < rows; i++) data[i] = new T[cols]();
    }

    ~FlexibleMatrix() {
        for (int i = 0; i < rows; i++) delete[] data[i]; 
        delete[] data; //Necessário por causa do new[] (pra eu não esquecer)
    }

    // Copia o construtor
    FlexibleMatrix(const FlexibleMatrix& other) : rows(other.rows), cols(other.cols) {
        data = new T*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; j++) data[i][j] = other.data[i][j];
        }
    }

    // Atribuição de operador
    FlexibleMatrix& operator=(const FlexibleMatrix& other) {
        if (this == &other) return *this;

        for (int i = 0; i < rows; i++) delete[] data[i];
        
        delete[] data;

        // Alocar nova memória
        rows = other.rows;
        cols = other.cols;
        data = new T*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; j++) data[i][j] = other.data[i][j];
        }

        return *this;  //Retornando a referencia
    }

    // Método para acessar elementos
    T& at(int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[row][col];
    }

    // Método para acessar elementos (const version)
    const T& at(int row, int col) const {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[row][col];
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " | ";
            }
            std::cout << "\n";
        }
    }
    
    bool search(T value) const{
        bool findIt = false;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(data[i][j] == value){
                    findIt = true;
                    i = rows;
                    j = cols;
                }
            }
        }
        return findIt;
    }

    int getRows() const { return rows; }

    int getCols() const { return cols; }
};


