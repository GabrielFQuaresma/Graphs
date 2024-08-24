#include "../List/LinkedList.hpp"
template <typename T>

class Queue {
private:
    LinkedList<T> list; 

public:
    Queue() = default;

    void enqueue(T value) {
        list.pushBack(value);
    }

    T dequeue() {
        if (isEmpty()) throw std::runtime_error("Error: Empty Queue.");
        return list.popFront();
    }

    bool search (T value) const {
        if (isEmpty()) throw std::runtime_error("Error: Empty Queue.");
        return list.search(value);
    }

    int size() const {
        return list.size();
    }

    bool isEmpty() const {
        return size() == 0;
    }

    void printQueue() const { list.printList(); }
};