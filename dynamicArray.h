#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
using namespace std;

template <class T>
class DynamicArray {
    T* dynamicArray;
    int currentSize;
    int maxSize;
    void increaseArraySize();

    public:
    DynamicArray();
    DynamicArray(T* passedArray, const int current, const int max);
    DynamicArray(const DynamicArray& rhs);
    ~DynamicArray();

    void addElementToArray(const T& newItem);
    void popElementFromArray();
    T getIndexedItem(const int index) const;
    int getCurrentSize() const; 

    void deleteArray();
};

#endif