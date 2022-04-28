#include "Array.h"
#include <iostream>

using namespace std;

Array::Array() {
    arraySize = 0;
    arrayPointer = new int[arraySize];
}

Array::~Array() {
    delete[] arrayPointer;
}

int Array::getSize(){
    return arraySize;
}

bool Array::increaseSize(int offsetAt) {
    //Kopiujemy starą tablice do nowej o jeden większej
    int *tempTable = new int[arraySize + 1];
    for (int i = 0; i < arraySize; ++i) {
        //Pomijamy jedno pole zgodnie z zadanym odchyleniem
        if(i>=offsetAt){tempTable[i + 1] = arrayPointer[i];}
        else{tempTable[i] = arrayPointer[i];}
    }
    //Usuwamy poprzednią tablice
    delete[] arrayPointer;
    arrayPointer = tempTable;
    arraySize++;
    return true;
    }

void Array::removeAt(int offset) {
    if(arraySize > 0) {
        //Kopiujemy tablice do nowej tablicy mniejszej o 1. Pomijamy jeden z indeksów przy kopiowaniu
        int *tempTable = new int[arraySize - 1];
        for (int i = 0; i < arraySize; ++i) {
            if (i >= offset) { tempTable[i] = arrayPointer[i + 1]; }
            else { tempTable[i] = arrayPointer[i]; }
        }
        delete[] arrayPointer;
        arrayPointer = tempTable;
        arraySize--;
        return;
    }
    return;
}

//Iteracyjne wypisanie tablicy
void Array::print() {
    cout << "\n";
    for (int i = 0; i < arraySize; i++) {
        cout << arrayPointer[i];
        cout << " ";
    }
}

//Przy dodawaniu tworzymy nową tablice większą o 1.
void Array::insertAt(int offset, int value) {
    if (offset < 0 || offset > arraySize) {return;}
    else {
        // Wpisujemy nową wartość w pominięty przy powiększaniu tablicy indeks
        increaseSize(offset);
        arrayPointer[offset] = value;
    }
}

void Array::insertLast(int value) {
    insertAt(arraySize, value);
}

void Array::insertFirst(int value) {
    insertAt(0, value);
}

void Array::removeFirst() {
    removeAt(0);
}

void Array::removeLast() {
    removeAt(arraySize);
}

bool Array::contains(int value){
    for(int i = 0; i < arraySize; i++){
        if(arrayPointer[i] == value) return true;
    }
    return false;
}

int Array::getMidElement(){
    return arrayPointer[arraySize/2];
}



