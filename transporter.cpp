#include "dynamicArray.h"
#include "ITransporter.h"
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Transporter : public ITransporter<T> {
    DynamicArray<T> items;

    public:
        void load(const T& item) override {
            items.addElementToArray(item);
        }
        void unload() override {
            if (!items.isEmpty()) {
                items.popElementFromArray();
            }
        }

        void empty() override {
            items.deleteArray();
        }

        void move() override {
            cout << "Transporter is moving." << std::endl;
        }

        bool isEmpty() override const {
            if (items.currentSize == 0) {
                return true;
            }
        }
        int itemCount() override const {
            return items.currentSize();
        }

        ~ITransporter() {}    
};
