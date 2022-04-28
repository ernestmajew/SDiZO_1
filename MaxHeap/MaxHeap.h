#include <string>

class MaxHeap
{
    int *heapPointer;
    int heapSize;
    int parent(int i);
    int left(int i);
    int right(int i);
    bool isLeaf(int i);
    void siftUp(int i);
    void siftDown(int i);

public:
    MaxHeap();
    ~MaxHeap();
    void insert(int key);
    void removeAt(int index);
    void removeRoot();
    bool contains(int value);
    int getMidElement();
    void printHeap();
    void printHeap(const int *heapPointer, int heapSize);
};