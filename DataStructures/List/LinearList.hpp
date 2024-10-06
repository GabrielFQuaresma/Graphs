#include "../../Util/Util.hpp"
#include <sstream>
#include <stdexcept>
#

template <typename T>


class LinearList {
  private:
	size_t maxSize;
	size_t size;
	T *data;

	void resize(const size_t newSize) {
		this->maxSize = newSize;
		
		T* newData = new T[maxSize];
		
		for(int i = 0; i < this->size; i++) newData[i] = data[i];

		delete[] data;
		data = newData;
	}

  public:
	LinearList(size_t maxSize = 3) {

		this->maxSize = maxSize;
		this->size = 0;

		data = new T[maxSize];
	}

	LinearList(size_t first, size_t last) {

		this->maxSize = modulus(last - first) + 1;
		this->data = new T[maxSize];

		if (first > last){
			for (size_t i = first; i >= last; i--) pushBack(i);
		}
		else{
			for (size_t i = first; i <= last; i++) pushBack(i);
		}
		
		this->size = maxSize;
	}

	LinearList(const LinearList &other) : maxSize(other.capacity()) {

		this->size = other.getSize();

		this->data = new T[maxSize];

		for (int i = 0; i < size; i++){
			data[i] = other.data[i];
		}
	}

	bool operator!=(const LinearList<T> &other) const {

		if (this->size != other.getSize()) return true;

		for (int i = 0; i < size; i++){
			if (this->data[i] != other.data[i]) return true;
		}

		return false;
	}

	bool operator==(const LinearList<T> &other) const{

		if (this->size != other.getSize()) return false;

		for (int i = 0; i < size; i++){
			if (this->data[i] != other.data[i]) return false;
		}

		return true;
	}

	LinearList<T> &operator=(const LinearList<T> &other) {
		if (this != &other){
			delete[] data;

			return new LinearList(other);
		}

		return *this;
	}

	~LinearList() { delete[] data; }

	bool contains (const T &value) const {

		for (int i = 0; i < size; i++){
			if (data[i] == value) return true;
		}
		return false;
	}

	bool inline isEmpty() const {
		return size == 0;
	} 

	size_t inline capacity() const { return maxSize;} 

	void insert (const T &value, int position) {

		if (position < 0 || position >= maxSize){
			throw std::runtime_error("Error: Invalid position in insertion.");
		} 
		else if (size == maxSize) resize(2 * maxSize);

		for (int i = size - 1; i > position; i--) data[i] = data[i - 1];

		data[position] = value;
		size++;		
	}

	void pushFront (const T &value) {
	
		if (size == maxSize) resize(2 * maxSize);

		for (int i = size - 1; i > 0; i--) data[i] = data[i - 1];
		
		data[0] = value;
		size++;
	}

	void pushBack (const T &value) {

		if (size == maxSize) resize(2 * maxSize);

		data[size++] = value;
	}

	T popFront () {
		if (isEmpty()) throw std::runtime_error("Error: List is Empty.");

		T removed = data[0];

		for(int i = 0; i < size - 1; i++) data[i] = data[i + 1];

		size--;
		return removed;
	}

	T popBack () {
		if (isEmpty()) throw std::runtime_error("Error: List is Empty.");

		T removed = data[--size];
		return removed;
	}
	
	T remove (int position) {
		if (position < 0 || position >= size){
			throw std::runtime_error("Error: Invalid position in insertion.");
		} 
		else if (isEmpty()) throw std::runtime_error("Error: List is Empty.");

		T removed = data[position];
		
		for(int i = position; i < size - 1; i++) data[i] = data[i + 1];
		
		size--;
		return removed;
	}

	T& front () const {
		if (isEmpty()) throw std::runtime_error("Error: List is Empty.");

		return data[0];
	}

	T& back () const {
		if (isEmpty()) throw std::runtime_error("Error: List is Empty.");

		return data[size - 1];
	}

	T& operator[] (size_t index) const{
		
		if (index >= size) {
			throw std::runtime_error("Error: Index out of bounds.");
		}

		return data[index];
	}

	T& operator[] (size_t index){
		
		if (index >= size) {
			throw std::runtime_error("Error: Index out of bounds.");
		}
		
		return data[index];
	}

	void inline shrink_to_fit () { resize(size); }

	size_t inline getSize() const { return this->size; }

	void reserve(size_t newSize) {
		
		if(newSize > size){
			resize(newSize);
		}
	}

	std::string str() const {

		if (isEmpty()) return "∅";

		std::ostringstream oss;

		oss << "{ ";

		for (int i = 0; i < size; i++) {
			oss << data[i];
			if (i < size - 1) oss << ", ";
		}

		oss << " }";

		return oss.str();
	}

	friend std::ostream& operator<<(std::ostream& os, const LinearList<T>& list) {
		os << list.str();
		return os;
	}

};
