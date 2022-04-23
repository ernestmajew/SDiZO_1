#ifndef SDIZO_1_TIMER_H
#define SDIZO_1_TIMER_H


#include "../DLL/DLL.h"

class Timer {
private:
    double getCounter();
    void startCounter();
public:
    Timer();

    //Doubly linked list
    void dllInsertFirst(int elementCount, int repeatCount);
    void dllInsertMid(int elementCount, int repeatCount);
    void dllInsertLast(int elementCount, int repeatCount);
    void dllRemoveLast(int elementCount, int repeatCount);
    void dllRemoveMid(int elementCount, int repeatCount);
    void dllRemoveFirst(int elementCount, int repeatCount);
    void dllSearchMid(int elementCount, int repeatCount);

    //Array
    void arrayInsertFirst(int elementCount, int repeatCount);
    void arrayInsertMid(int elementCount, int repeatCount);
    void arrayInsertLast(int elementCount, int repeatCount);
    void arrayRemoveLast(int elementCount, int repeatCount);
    void arrayRemoveMid(int elementCount, int repeatCount);
    void arrayRemoveFirst(int elementCount, int repeatCount);
    void arraySearchMid(int elementCount, int repeatCount);

    //Maximum heap
    void heapInsert(int elementCount, int repeatCount);
    void heapRemoveMid(int elementCount, int repeatCount);
    void heapRemoveRoot(int elementCount, int repeatCount);
    void heapSearchMid(int elementCount, int repeatCount);



};


#endif //SDIZO_1_TIMER_H
