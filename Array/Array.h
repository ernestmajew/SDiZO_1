#ifndef SDIZO_1_ARRAY_H
#define SDIZO_1_ARRAY_H

#include <string>

using namespace std;


class Array {
public:
    Array();
    ~Array();
    int getSize();
    void print();
    void insertLast(int value);
    void insertFirst(int value);
    void insertAt(int offset, int value);
    void removeAt(int offset);
    void removeFirst();
    void removeLast();
    bool contains(int value);
    int getMidElement();

private:
    bool increaseSize(int);
    int arraySize;
    int *arrayPointer;



};

#endif //SDIZO_1_ARRAY_H
