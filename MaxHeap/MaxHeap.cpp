#include "MaxHeap.h"
#include <Math.h>

using namespace std;

MaxHeap::MaxHeap() {
    heapSize = 0;
    heapPointer = new int[0];
}

MaxHeap::~MaxHeap() {
    delete[] heapPointer;
}

int MaxHeap::parent(int child) {
    if (child % 2 == 0)
        return (child / 2) - 1;
    else
        return (child / 2);
}

int MaxHeap::left(int parent) {
    return (2 * parent + 1);
}

int MaxHeap::right(int parent) {
    return (2 * parent + 2);
}

//Zamaina zbyt małego klucza z ojcem dopóki nie ma wiekszego klucza nad nim
void MaxHeap::siftUp(int i) {
    if (i == 0)
        return;
    int parentIndex = parent(i);
    if (heapPointer[parentIndex] < heapPointer[i]) {
        int temp = heapPointer[parentIndex];
        heapPointer[parentIndex] = heapPointer[i];
        heapPointer[i] = temp;
        siftUp(parentIndex);
    }
}

//Zamienia zbyt mały klucz z jego największym synem
void MaxHeap::siftDown(int i) {
    int l = left(i);
    int r = right(i);

    if (isLeaf(l)) return;
    int maxIndex = i;
    if (heapPointer[l] > heapPointer[i]) maxIndex = l;
    if (!isLeaf(r) && (heapPointer[r] > heapPointer[maxIndex])) maxIndex = r;
    if (maxIndex != i) {
        int temp = heapPointer[i];
        heapPointer[i] = heapPointer[maxIndex];
        heapPointer[maxIndex] = temp;
        siftDown(maxIndex);
    }
}

void MaxHeap::insert(int key) {
        int *tempHeap = new int[heapSize + 1];
        for (int i = 0; i < heapSize; ++i) {
            tempHeap[i] = heapPointer[i];
        }

        delete[] heapPointer;
        heapPointer = tempHeap;
        heapPointer[heapSize] = key;
        while (heapSize != 0 && heapPointer[parent(heapSize)] < heapPointer[heapSize])
        siftUp(heapSize);
        heapSize++;
}

bool MaxHeap::isLeaf(int i) {
    if (i < heapSize)
        return false;
    return true;
}

void MaxHeap::removeAt(int key)
{
    int r = heapPointer[key];

    heapPointer[key] = heapPointer[heapSize -1];
    heapSize-- ;
    int p = parent(key);
    if(key == 0 || heapPointer[key] < heapPointer[p])
        siftDown(key);
    else
        siftUp(key);
    return;
}

void MaxHeap::removeRoot(){
    removeAt(0);
}

bool MaxHeap::contains(int value) {
    if(heapSize == 0) return false;
    for(int i = 1; i <= heapSize; i++){
        if(value == heapPointer[i]) return true;
    }
    return false;
}

int MaxHeap::getMidElement() {
    return heapPointer[heapSize/2];
}

string MaxHeap::print(){
    int heapHeight = floor(log2(heapSize));
    int actualHeight = 0;
    int bigSpaceSize = 0;
    int smallSpaceSize = 0;
    int bigSpaceCounter = 0;
    int heapIterator = 0;

    string output= "";

    for(;actualHeight<=heapHeight; actualHeight++){
        bigSpaceCounter=pow(2,actualHeight)-1;
        bigSpaceSize = smallSpaceSize;
        smallSpaceSize = pow(2,heapHeight - actualHeight)-1;

        for(int i = 0; i<smallSpaceSize;i++) {
            output += " ";
        }
        do{
            if(heapIterator+1<=heapSize){
                output += to_string(heapPointer[heapIterator++]);
            }else{
                output += " ";
            }
            if(bigSpaceCounter>0){
                for(int i = 0 ; i < bigSpaceSize; i++){
                    output += " ";
                }
            }
        }while(bigSpaceCounter-->0);
        for(int i = 0; i<smallSpaceSize;i++) {
            output += " ";
        }
        output += '\n';
    }
    return output;
}
