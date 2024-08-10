template <typename T>

class Cell
{
  public:

    T value;
    Cell *next;

    Cell() : value(T {}), next(nullptr) {}

    Cell(Cell* next) : value(T {}), next(next) {}

    Cell(T value) : value(value), next(nullptr) {}

    Cell(T value, Cell* next) : value(value), next(next) {}
};