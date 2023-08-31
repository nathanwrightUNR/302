#include "dynamicArray.h"

template <class T>
DynamicArray<T>::DynamicArray() {
    DynamicArray = new T[maxSize];
    currentSize = 0;
    maxSize = 1;
}

template <class T>
DynamicArray<T>::DynamicArray(T* passedArray, const int current, const int max) {
    currentSize = current;
    maxSize = max;
    dynamicArray = new T[maxSize];

    for (int i = 0; i < currentSize; i++) {
        dynamicArray[i] = passedArray[i];
    }
}

template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray& rhs) {
    currentSize = rhs.currentSize;
    maxSize = rhs.maxSize;

    dynamicArray = new T[rhs.currentSize];
    for (int i = 0; i < currentSize; i++) {
        dynamicArray[i] = rhs.dynamicArray[i];
    }
}

template <class T>
DynamicArray<T>::~DynamicArray() {
    delete[] dynamicArray;
}

template <class T>
void DynamicArray<T>::increaseArraySize() {
    T* temp = new T[maxSize + 1];
    for (int i = 0; i < currentSize; i++) {
        temp[i] = dynamicArray[i];
    }

    delete[] dynamicArray;
    maxSize += 1;

    dynamicArray = new T[maxSize];
    for (int i = 0; i < currentSize; i++) {
        dynamicArray[i] = temp[i];
    }

    delete[] temp;
}

template <class T>
void DynamicArray<T>::addElementToArray(const T& newItem) {
    if (currentSize >= maxSize) {
        increaseArraySize();
    }

    dynamicArray[currentSize] = newItem;
    currentSize++;    
}

template <class T>
void DynamicArray<T>::popElementFromArray() {
    if (currentSize > 0) {
        dynamicArray[currentSize - 1].~T();
        currentSize--;
    }
}

template <class T>
T DynamicArray<T>::getIndexedItem(const int index) const {
    return dynamicArray[index];
}

template <class T>
int DynamicArray<T>::getCurrentSize() const {
    return currentSize;
}

template <class T>
void DynamicArray<T>::deleteArray() {
    delete[] dynamicArray;
    maxSize = 1;
    dynamicArray = new T[maxSize];
    currentSize = 0;    
}