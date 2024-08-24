#include "../Cell/Cell.hpp"
#include <iostream>

template <typename T>

class LinkedList{
  private:
    Cell<T>* first;
    Cell<T>* last;
    int N; //Number of elements that are in the List
    
  public:
    LinkedList() {
        first = last = nullptr;
        N = 0;
    }

    ~LinkedList() {
        Cell<T>* current = first;
        while (current != nullptr) {
            Cell<T>* nextCell = current->next;
            delete current; 
            current = nextCell;
        }
    }

    void pushFront(T value) {
        Cell<T>* newCell = new Cell<T>(value);
        newCell->next = first;
        first = newCell;

        if (N == 0) last = newCell;
        N++;
    }

    void pushBack(T value) {
        Cell<T>* newCell = new Cell<T>(value);
        
        if(last == nullptr) first = last = newCell;
        else{
            last->next = newCell;
            last = newCell;
        }
        N++;
    }

    void insert(T value, int position) {
        if(position < 0 || position > N){
            throw std::runtime_error("Error: Invalid position in insertion.");
        }

        Cell<T>* temp = first;
        Cell<T>* newCell = new Cell<T>(value);
    
        for (int i = 0; i < position - 1; i++) temp = temp->next;
        
        if(position == 0){
            newCell->next = first;
            first = newCell;
        }else{
            newCell->next = temp->next;
            temp->next = newCell;
        }

        if (position == N) last = newCell;
        N++;
    }

    T popFront( ) {
        if(first == nullptr){
            throw std::runtime_error("Error: Empty List.");
        }

        Cell<T>* temp = first;
        T value = first->value;
        first = first->next;
        
        delete temp;
        N--;

        if (first == nullptr) last = first;

        return value;

    }

    T popBack() {
        if(first == nullptr){
            throw std::runtime_error("Error: Empty Queue.");
        }

        T value = last->value;

        if(first == last){
            delete last;
            first = last = nullptr;
        } else{
            Cell<T>* temp = first;
            while(temp->next != last) temp = temp->next;
            temp->next = nullptr;
            delete last;
            last = temp;
        }

        N--;
        return value;
    }

    T front() const{
        if(first == nullptr) throw std::runtime_error("Error: Empty List.");
        return first->value;
    }

    T remove(int position) {
        if(position < 0 || position > N) throw std::runtime_error("Error: Invalid position in remotion.");
        
        if (first == nullptr) throw std::runtime_error("Error: Empty List.");
        
        
        Cell<T>* temp = first;
        T removedValue;

        // Caso especial: remoção do primeiro elemento
        if (position == 0) {
            removedValue = first->value;
            first = first->next;
            delete temp;

            if (first == nullptr) last = nullptr;

        } else{
            // Percorre até a célula anterior à remover
            for (int i = 0; i < position - 1; i++) temp = temp->next;

            Cell<T>* cellToRemove = temp->next;
            removedValue = cellToRemove->value;
            temp->next = cellToRemove->next;

            // Caso especial: remoção do último elemento
            if (cellToRemove == last) last = temp;

            delete cellToRemove;
        }

        N--;
        return removedValue;
    }

    bool search(T value) const {
        if (first == nullptr) throw std::runtime_error("Error: Empty List.");

        Cell<T>* temp = first;
        bool findIt = (temp->value == value); //Está aqui para testar o primeiro termo numa lista com só um elemento
        while(temp->next != nullptr && findIt == false){
            if(temp->value == value) findIt = true;
            temp = temp->next;
        }
        return findIt;
    }

    int size() const { return N; }

    bool isEmpty() const { return N == 0; }

    void print(int position) const {
        Cell<T>* temp = first;
        for(int i = 0; i < position; i++) temp = temp->next;
        
        std::cout << temp->value << "\n"; 
    }

    void printList() const {
        Cell<T>* temp = first;
        for(int i = 0; i < N; i++){
            std::cout << temp->value;
            if(i < N - 1) std::cout << ", ";
            temp = temp->next; 
        }
        
        std::cout << "\n";
        
    }

};