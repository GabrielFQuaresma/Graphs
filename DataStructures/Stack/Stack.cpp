#include "../List/LinkedList.cpp"
template <typename T>

class Stack {
private:
    LinkedList<T> list;

public:
    Stack() = default;

    void push(T value) {
        list.pushFront(value);
    }

    T pop() {
        if (isEmpty()) throw std::runtime_error("Error: Empty Stack.");
        return list.popFront();
    }

    T top() const {
        if (isEmpty()) throw std::runtime_error("Error: Empty Stack.");
        return list.front(); 
    }

    int size() const {
        return list.size();
    }

    bool isEmpty() const {
        return list.isEmpty();
    }

    void printStack() const { list.printList(); }

};
