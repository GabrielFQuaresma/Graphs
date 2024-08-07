#include "Cell.cpp"

template <typename T>

class LinkedList{
    private:
        Cell* first;
        Cell* last;
        int N; //Number of elements that are in the List
    
    public:
        LinkedList(){
            first = last = nullptr;
            N = 0;
        }

        void pushFront(T value){
            Cell* newCell = new Cell(value);
            newCell->next = first;
            first = newCell;

            if (N == 0) last = newCell;
        }

        void pushBack(T value){
            Cell* newCell = new Cell(value);
            last->next = newCell;
            last = newCell;

            if(N == 0) first = newCell;
        }

        void insert(T value, int position){
            if(position < 0 || position > N){
                throw "Error: Invalid position in Insertion.";
            }

            for (int i = 0; i < N; i++){
                int N 
            }
        }
    
        int size(){return N;}



};