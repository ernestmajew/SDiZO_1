#include "MaxHeap.h"
#include <Math.h>
#include <iostream>

using namespace std;

MaxHeap::MaxHeap() {
    heapSize = 0;
    heapPointer = new int[0];
}

MaxHeap::~MaxHeap() {
    delete[] heapPointer;
}

// Zwraca pozycje ojca
int MaxHeap::parent(int child) {
    if (child % 2 == 0)
        return (child / 2) - 1;
    else
        return (child / 2);
}

// Zwraca pozycje lewego syna
int MaxHeap::left(int parent) {
    return (2 * parent + 1);
}

// Zwraca pozycje prawego syna
int MaxHeap::right(int parent) {
    return (2 * parent + 2);
}

//Zamaina zbyt małego klucza z ojcem dopóki nie ma wiekszego klucza nad nim
void MaxHeap::siftUp(int i) {
    // Warunek stopu
    if (i == 0)
        return;
    int parentIndex = parent(i);

    //Jeśli syn jest większy od rodzica zamieniamy klucze miejscami
    if (heapPointer[parentIndex] < heapPointer[i]) {
        int temp = heapPointer[parentIndex];
        heapPointer[parentIndex] = heapPointer[i];
        heapPointer[i] = temp;

        //Rekurencyjne wywołanie funkcji na ojcu
        siftUp(parentIndex);
    }
}

//Zamienia zbyt mały klucz z jego największym synem
void MaxHeap::siftDown(int i) {
    int l = left(i);
    int r = right(i);

    //Warunek stopu - dotarcie do samego dołu
    if (isLeaf(l)) return;
    int maxIndex = i;
    // Lewy syn większy - max = l
    if (heapPointer[l] > heapPointer[i]) maxIndex = l;

    // Jeśli prawy syn nie jest ostatnim elementem kopca oraz jest większy niż lewy syn i ojciec - max = r //
    if (!isLeaf(r) && (heapPointer[r] > heapPointer[maxIndex])) maxIndex = r;

    // Zamiana z większym synem jeżeli istnieje
    if (maxIndex != i) {
        int temp = heapPointer[i];
        heapPointer[i] = heapPointer[maxIndex];
        heapPointer[maxIndex] = temp;
        // Rekurencyjne wywołanie na większym synu
        siftDown(maxIndex);
    }
}

void MaxHeap::insert(int key) {
        //Zaalokowanie większej ilości pamięci
        int *tempHeap = new int[heapSize + 1];
        for (int i = 0; i < heapSize; ++i) {
            tempHeap[i] = heapPointer[i];
        }
        delete[] heapPointer;
        heapPointer = tempHeap;
        // Wstawienie klucza na ostanie miejsce
        heapPointer[heapSize] = key;

        // Przywracanie własności kopca jeżeli ojciec nowego klucza jest większy i kopiec posiada elementy
        while (heapSize != 0 && heapPointer[parent(heapSize)] < heapPointer[heapSize])
        siftUp(heapSize);
        heapSize++;
}

// Zwraca true jeśli klucz jest ostatnim elementem kopca
bool MaxHeap::isLeaf(int i) {
    if (i < heapSize)
        return false;
    return true;
}

void MaxHeap::removeAt(int key)
{
    // Zakrycie elementu przez następny
    heapPointer[key] = heapPointer[heapSize -1];
    heapSize-- ;
    int p = parent(key);

    // Jeśli ojciec jest większy sprawdź czy niżej nie ma mniejszych elementów
    if(key == 0 || heapPointer[key] < heapPointer[p])
        siftDown(key);
    // Jeśli ojciec jest mniejszy przywracaj własność w górę
    else
        siftUp(key);

    //Zwalniamy pamięć
    if(heapSize > 0) {
    int *tempTable = new int[heapSize - 1];
    for (int i = 0; i < heapSize; ++i) {
    tempTable[i] = heapPointer[i];
    }
    delete[] heapPointer;
    heapPointer = tempTable;
    return;
    }
}

void MaxHeap::removeRoot(){
    removeAt(0);
}

// Sprawdzenie iteracyjne
bool MaxHeap::contains(int value) {
    if(heapSize == 0) return false;
    for(int i = 1; i <= heapSize; i++){
        if(value == heapPointer[i]) return true;
    }
    return false;
}


// Funkcja stworzona na potrzeby testów
int MaxHeap::getMidElement() {
    return heapPointer[heapSize/2];
}

static int pow2i(int a) {
    int r = 1;
    while (a--) {
        r *= 2;
    }
    return r;
}



void MaxHeap::printHeap(const int *heapPointer, int heapSize)
{
    int longest_digits = 0;
    int tree_depth = 0;

    int index = 0;
    int depth = 0;
    for (int i = 0; i < heapSize; ++i) {
        if (heapPointer[i] != -1) {
            const int len = snprintf(NULL, 0, "%d", heapPointer[i]);
            if (longest_digits < len) {
                longest_digits = len;
            }
        }
        if (index == 0) {
            tree_depth++;
            index = pow2i(depth++);
        }
        index--;
    }

    index = 0;
    depth = 0;
    const int additional_offset = 3;
    int max_width = pow2i(tree_depth) * (longest_digits + additional_offset);
    for (int i = 0; i < heapSize; ++i) {
        const bool first = index == 0;
        if (first) {
            index = pow2i(depth);
            depth++;
        }
        const int count_elems = pow2i(depth);
        const int chunk = max_width / count_elems;
        const int width = chunk + (first ? -chunk/2 : 0);
        const int pre_spaces = width - longest_digits;

        printf("%*s", pre_spaces, "");
        printf("%*d", longest_digits, heapPointer[i]);

        if (index == 1) {
            printf("\n");
        }
        index--;
    }
}

void MaxHeap::printHeap(){
    printHeap(heapPointer, heapSize);
}

