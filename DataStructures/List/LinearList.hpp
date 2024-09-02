#include "../../Util/Util.hpp"

template <typename T>

class LinearList {
  private:
	size_t maxSize;
	size_t size;
	T *data;

  public:
	LinearList(size_t maxSize = 3) {

		this->maxsize = maxSize;
		this->size = 0;

		data = new T[maxSize];
	}

	LinearList(size_t first, size_t last) {

		this->maxSize = modulus(last - first) + 1;
		this->size = maxSize;
		this->data = new T[maxSize];

		if (first > last){
			for (size_t i = first; i >= last; i--) pushBack(i);
		}
		else{
			for (size_t i = first; i <= last; i++) pushBack(i);
		}
	}

	LinearList(const LinearList &other) : maxSize(other.capacity()) {

		this->size = other.size();

		this->data = new T[maxSize];

		for (int i = 0; i < size; i++){
			array[i] = other.data[i];
		}
	}

	bool operator!=(const LinearList<T> &other) const {

		if (this->size != other.size()) return true;

		for (int i = 0; i < size; i++){
			if (this->data[i] != other.data[i]) return true;
		}

		return false;
	}

	bool operator==(const LinearList<T> &other) const{

		if (this->size != other.size()) return false;

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

	~LinearList() { delete[] array; }

	bool contains (const T &value) const {

		for (int i = 0; i < size; i++){
			if (data[i] == value) return true;
		}

		return false
	}

	
};
