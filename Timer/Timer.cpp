#include "Timer.h"
#include "../DLL/DLL.h"
#include "../MaxHeap/MaxHeap.h"
#include "../Array/Array.h"
#include <profileapi.h>
#include <iostream>

double PCFreq = 0.0;
LONGLONG CounterStart = 0;

//Funkcje start i get counter zostały zapożyczone od autora: https://gist.github.com/csmoore/d3af490666378272d6ff

Timer::Timer() {
    startCounter();
}

void Timer::startCounter() {
    LARGE_INTEGER li;
    if (!QueryPerformanceFrequency(&li))
        cout << "QueryPerformanceFrequency failed!\n";
    PCFreq = double(li.QuadPart) / 100000000.0;
    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double Timer::getCounter() {
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart - CounterStart) / PCFreq;
}

void Timer::dllInsertFirst(int elementCount, int repeatCount) {
    DLL list;
    double sum = 0;
    srand (time(NULL));
    for(int i = 0; i <elementCount; i++){
        list.insertFirst(rand());
    }

    for(int j = 0; j < repeatCount; j++){
        int x = rand();
        double start = getCounter();
        list.insertFirst(x);
        double end = getCounter();
        double elapsed = end - start;
        sum += elapsed;
        list.removeLast();
    }
    cout <<"Liczba elementow: "<< elementCount <<", liczba powtorzen: "<< repeatCount << ", sredni czas (ns): " << sum / repeatCount << endl;
}

void Timer::dllInsertLast(int elementCount, int repeatCount) {
    DLL list;
    double sum = 0;
    srand (time(NULL));
    for(int i = 0; i <elementCount; i++){
        list.insertFirst(rand());
    }

    for(int j = 0; j < repeatCount; j++){
        int x = rand();
        double start = getCounter();
        list.insertLast(x);
        double end = getCounter();
        double elapsed = end - start;
        sum += elapsed;
        list.removeLast();
    }
    cout <<"Liczba elementow: "<< elementCount <<", liczba powtorzen: "<< repeatCount << ", sredni czas (ns): " << sum / repeatCount<< endl;
}

void Timer::dllInsertMid(int elementCount, int repeatCount) {
    DLL list;
    double sum = 0;
    srand (time(NULL));
    for(int i = 0; i <elementCount; i++){
        list.insertFirst(rand());
    }

    for(int j = 0; j < repeatCount; j++){
        int x = rand();
        double start = getCounter();
        list.insertAt(elementCount/2, x);
        double end = getCounter();
        double elapsed = end - start;
        sum += elapsed;
        list.removeLast();
    }
    cout <<"Liczba elementow: "<< elementCount <<", liczba powtorzen: "<< repeatCount << ", sredni czas (ns): " << sum / repeatCount<< endl;
}

void Timer::dllRemoveFirst(int elementCount, int repeatCount) {
    DLL list;
    double sum = 0;
    srand (time(NULL));
    for(int i = 0; i <elementCount; i++){
        list.insertFirst(rand());
    }

    for(int j = 0; j < repeatCount; j++){
        int x = rand();
        double start = getCounter();
        list.removeFirst();
        double end = getCounter();
        double elapsed = end - start;
        sum += elapsed;
        list.insertFirst(x);
    }
    cout <<"Liczba elementow: "<< elementCount <<", liczba powtorzen: "<< repeatCount << ", sredni czas (ns): " << sum / repeatCount<< endl;
}

void Timer::dllRemoveLast(int elementCount, int repeatCount) {
    DLL list;
    double sum = 0;
    srand (time(NULL));
    for(int i = 0; i <elementCount; i++){
        list.insertFirst(rand());
    }

    for(int j = 0; j < repeatCount; j++){
        int x = rand();
        double start = getCounter();
        list.removeLast();
        double end = getCounter();
        double elapsed = end - start;
        sum += elapsed;
        list.insertLast(x);
    }
    cout <<"Liczba elementow: "<< elementCount <<", liczba powtorzen: "<< repeatCount << ", sredni czas (ns): " << sum / repeatCount<< endl;
}

void Timer::dllRemoveMid(int elementCount, int repeatCount) {
    DLL list;
    double sum = 0;
    srand (time(NULL));
    for(int i = 0; i <elementCount; i++){
        list.insertFirst(rand());
    }

    for(int j = 0; j < repeatCount; j++){
        int x = rand();
        double start = getCounter();
        list.removeAt(elementCount/2);
        double end = getCounter();
        double elapsed = end - start;
        sum += elapsed;
        list.insertLast(x);
    }

    cout <<"Liczba elementow: "<< elementCount <<", liczba powtorzen: "<< repeatCount << ", sredni czas (ns): " << sum / repeatCount<< endl;
}

void Timer::dllSearchMid(int elementCount, int repeatCount) {
    DLL list;
    double sum = 0;
    srand (time(NULL));
    for(int i = 0; i <elementCount; i++){
        list.insertFirst(rand());
    }

    int index = list.getAt(list.getSize()/2);
    for(int j = 0; j < repeatCount; j++){
        int x = rand();
        double start = getCounter();
        list.contains(index);
        double end = getCounter();
        double elapsed = end - start;
        sum += elapsed;
    }

    cout <<"Liczba elementow: "<< elementCount <<", liczba powtorzen: "<< repeatCount << ", sredni czas (ns): " << sum / repeatCount<< endl;
}

void Timer::arrayInsertFirst(int elementCount, int repeatCount) {
    Array array;
    double sum = 0;
    srand (time(NULL));
    for(int i = 0; i <elementCount; i++){
        array.insertFirst(rand());
    }

    for(int j = 0; j < repeatCount; j++){
        int x = rand();
        double start = getCounter();
        array.insertFirst(x);
        double end = getCounter();
        double elapsed = end - start;
        sum += elapsed;
        array.removeFirst();
    }
    cout <<"Liczba elementow: "<< elementCount <<", liczba powtorzen: "<< repeatCount << ", sredni czas (ns): " << sum / repeatCount<< endl;
}

void Timer::arrayInsertMid(int elementCount, int repeatCount) {
    Array array;
    double sum = 0;
    srand (time(NULL));
    for(int i = 0; i <elementCount; i++){
        array.insertFirst(rand());
    }

    for(int j = 0; j < repeatCount; j++){
        int x = rand();
        double start = getCounter();
        array.insertAt(elementCount / 2, x);
        double end = getCounter();
        double elapsed = end - start;
        sum += elapsed;
        array.removeFirst();
    }
    cout <<"Liczba elementow: "<< elementCount <<", liczba powtorzen: "<< repeatCount << ", sredni czas (ns): " << sum / repeatCount<< endl;
}

void Timer::arrayInsertLast(int elementCount, int repeatCount) {
    Array array;
    double sum = 0;
    srand (time(NULL));
    for(int i = 0; i <elementCount; i++){
        array.insertFirst(rand());
    }

    for(int j = 0; j < repeatCount; j++){
        int x = rand();
        double start = getCounter();
        array.insertLast(x);
        double end = getCounter();
        double elapsed = end - start;
        sum += elapsed;
        array.removeFirst();
    }
    cout <<"Liczba elementow: "<< elementCount <<", liczba powtorzen: "<< repeatCount << ", sredni czas (ns): " << sum / repeatCount<< endl;
}

void Timer::arrayRemoveLast(int elementCount, int repeatCount) {
    Array array;
    double sum = 0;
    srand (time(NULL));
    for(int i = 0; i <elementCount; i++){
        array.insertFirst(rand());
    }

    for(int j = 0; j < repeatCount; j++){
        int x = rand();
        double start = getCounter();
        array.removeLast();
        double end = getCounter();
        double elapsed = end - start;
        sum += elapsed;
        array.insertLast(x);
    }
    cout <<"Liczba elementow: "<< elementCount <<", liczba powtorzen: "<< repeatCount << ", sredni czas (ns): " << sum / repeatCount<< endl;
}

void Timer::arrayRemoveMid(int elementCount, int repeatCount) {
    Array array;
    double sum = 0;
    srand (time(NULL));
    for(int i = 0; i <elementCount; i++){
        array.insertFirst(rand());
    }

    for(int j = 0; j < repeatCount; j++){
        int x = rand();
        double start = getCounter();
        array.removeAt(elementCount/2);
        double end = getCounter();
        double elapsed = end - start;
        sum += elapsed;
        array.insertLast(x);
    }
    cout <<"Liczba elementow: "<< elementCount <<", liczba powtorzen: "<< repeatCount << ", sredni czas (ns): " << sum / repeatCount<< endl;
}

void Timer::arrayRemoveFirst(int elementCount, int repeatCount) {
    Array array;
    double sum = 0;
    srand (time(NULL));
    for(int i = 0; i <elementCount; i++){
        array.insertFirst(rand());
    }

    for(int j = 0; j < repeatCount; j++){
        int x = rand();
        double start = getCounter();
        array.removeFirst();
        double end = getCounter();
        double elapsed = end - start;
        sum += elapsed;
        array.insertLast(x);
    }
    cout <<"Liczba elementow: "<< elementCount <<", liczba powtorzen: "<< repeatCount << ", sredni czas (ns): " << sum / repeatCount<< endl;
}

void Timer::arraySearchMid(int elementCount, int repeatCount) {
    Array array;
    double sum = 0;
    srand (time(NULL));
    for(int i = 0; i <elementCount; i++){
        array.insertFirst(rand());
    }

    int x = array.getMidElement();
    for(int j = 0; j < repeatCount; j++){
        double start = getCounter();
        array.contains(x);
        double end = getCounter();
        double elapsed = end - start;
        sum += elapsed;
    }
    cout <<"Liczba elementow: "<< elementCount <<", liczba powtorzen: "<< repeatCount << ", sredni czas (ns): " << sum / repeatCount<< endl;
}

void Timer::heapInsert(int elementCount, int repeatCount) {
    MaxHeap heap;
    double sum = 0;
    srand (time(NULL));
    for(int i = 0; i <elementCount; i++){
        heap.insert(rand());
    }

    for(int j = 0; j < repeatCount; j++){
        int x = rand();
        double start = getCounter();
        heap.insert(x);
        double end = getCounter();
        double elapsed = end - start;
        sum += elapsed;
        heap.removeRoot();
    }
    cout <<"Liczba elementow: "<< elementCount <<", liczba powtorzen: "<< repeatCount << ", sredni czas (ns): " << sum / repeatCount<< endl;
}

void Timer::heapRemoveMid(int elementCount, int repeatCount) {
    MaxHeap heap;
    double sum = 0;
    srand (time(NULL));
    for(int i = 0; i <elementCount; i++){
        heap.insert(rand());
    }

    for(int j = 0; j < repeatCount; j++){
        int x = rand();
        int temp = heap.getMidElement();
        double start = getCounter();
        heap.removeAt(temp);
        double end = getCounter();
        double elapsed = end - start;
        sum += elapsed;
        heap.insert(x);
    }
    cout <<"Liczba elementow: "<< elementCount <<", liczba powtorzen: "<< repeatCount << ", sredni czas (ns): " << sum / repeatCount<< endl;
}

void Timer::heapRemoveRoot(int elementCount, int repeatCount) {
    MaxHeap heap;
    double sum = 0;
    srand (time(NULL));
    for(int i = 0; i <elementCount; i++){
        heap.insert(rand());
    }

    for(int j = 0; j < repeatCount; j++){
        int x = rand();
        double start = getCounter();
        heap.removeRoot();
        double end = getCounter();
        double elapsed = end - start;
        sum += elapsed;
        heap.insert(x);
    }
    cout <<"Liczba elementow: "<< elementCount <<", liczba powtorzen: "<< repeatCount << ", sredni czas (ns): " << sum / repeatCount<< endl;
}

void Timer::heapSearchMid(int elementCount, int repeatCount) {
    MaxHeap heap;
    double sum = 0;
    srand (time(NULL));
    for(int i = 0; i <elementCount; i++){
        heap.insert(rand());
    }

    for(int j = 0; j < repeatCount; j++){
        int x = rand();
        int temp = heap.getMidElement();
        double start = getCounter();
        heap.contains(temp);
        double end = getCounter();
        double elapsed = end - start;
        sum += elapsed;
        heap.insert(x);
    }
    cout <<"Liczba elementow: "<< elementCount <<", liczba powtorzen: "<< repeatCount << ", sredni czas (ns): " << sum / repeatCount<< endl;
}
