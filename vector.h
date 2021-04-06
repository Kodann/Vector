#pragma once

#include <iostream>
#include "stdio.h"
#include "stdlib.h"


using namespace std;

struct Point {
	int x;
	int y;
	int z;
}; 

template <typename T> 
class Vector {
private: 
	T *vector;
	size_t size;
	size_t capacity;
public:
	Vector(size_t size, T value);
	Vector(const Vector<T> &o);
	~Vector();
	Vector<T> & operator=(const Vector<T> &o);
	void push_back(T value);
	int size_of();
	T& operator[](int i);
	T& at(int i);
	void insert(size_t i, T& value);
	void erase(size_t i);
	void print(std::ostream &out);
	//template <typename T> friend  std::ostream& operator<<(std::ostream& out, Vector<T> &o);
	//friend std::istream& operator>>(std::istream& in, Vector<T> &o);
};


template<typename T>
inline Vector<T>::Vector(size_t size, T value)
{
	this->capacity = size;
	vector = new T[this->capacity];
	this->size = size;
	for (int i = 0; i < size; i++) {
		vector[i] = value;
	}
}

template<typename T>
inline Vector<T>::Vector(const Vector<T>& o)
{
	this->size = o.size;
	this->capacity = o.size;
	this->vector = new T[this->capacity];
	for (int i = 0; i < this->size; i++) {
		this->vector[i] = o.vector[i];
	}
}

template<typename T>
inline Vector<T>::~Vector()
{
	delete[] vector;
}

template<typename T>
inline Vector<T> & Vector<T>::operator=(const Vector<T>& o)
{
	delete[] this->vector;
	this->size = o.size;
	this->capacity = o.size;
	this->vector = new T[this->capacity];
	for (int i = 0; i < this->size; i++) {
		this->vector[i] = o.vector[i];
	}
	return *this;
}

template<typename T>
inline void Vector<T>::push_back(T value)
{
	if (size + 1 >= capacity) {
		capacity = capacity * 2;
		T *mass = new T[capacity];
		for (int i = 0; i < size; i++) {
			mass[i] = vector[i];
		}
		delete[] vector;
		vector = new T[capacity];
		for (int i = 0; i < size; i++) {
			vector[i] = mass[i];
		}
		delete[] mass;
	}
	vector[size++] = value;
}

template<typename T>
inline int Vector<T>::size_of()
{
	return size;
}

template<typename T>
inline T& Vector<T>::operator[](int i)
{
	return vector[i];
}

template<typename T>
inline T& Vector<T>::at(int i) {
	if (i < 0) {
		throw exception(" меньше 0\n");
	}
	if (i >= this->size) {
		throw exception(" за пределом массива\n");
	} 
	return vector[i];
}

template<typename T>
inline void Vector<T>::insert(size_t i, T& value) {
	if (i > size ) {
		throw exception(" за пределом массива\n");
	}
	if (size + 1 >= capacity) {
		push_back(value);
		for (size_t j = size - 1; j > i; j--) {
			vector[j] = vector[j - 1];
		}
		vector[i] = value;
	}
	else {
		for (size_t j = size; j > i; j--) {
			vector[j] = vector[j - 1];
		}
		vector[i] = value;
		size++;
	}
}

template<typename T>
inline void Vector<T>::erase(size_t i) {
	if (i >= size) {
		throw exception(" за пределом массива\n");
	}
	for (int j = i; j < size - 1; j++) {
		vector[j] = vector[j + 1];
	}
	size--;
}


template<typename T>
inline void Vector<T>::print(std::ostream &out) {
	for (int i = 0; i < size; i++) {
		out << vector[i] << " ";
	}
	out << endl;
}
