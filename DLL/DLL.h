#ifndef SDIZO_1_DLL_H
#define SDIZO_1_DLL_H

struct DLLNode{
    int value;
    DLLNode* next;
    DLLNode* previous;
    DLLNode(int);
};

class DLL{
public:
    DLL();
    ~DLL();

    void insertFirst(int value);
    void insertLast(int value);
    void insertAt(int index, int value);
    void removeFirst();
    void removeLast();
    void removeAt(int index);
    bool contains(int searched);
    void print();
    int getAt(int index);
    int getSize();

private:
    DLLNode* header;
    DLLNode* tail;
    int listSize;


};
#endif //SDIZO_1_DLL_H
