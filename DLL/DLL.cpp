#include "DLL.h"
#include <iostream>
using namespace std;

//Węzeł przechowuje dane oraz wskazniki na poprzedni i nastepny węzeł
DLLNode::DLLNode(int data){
    value = data;
    next = previous = nullptr;
}

//Lista po utworzeniu nie ma elementow. Pierwszy i ostatni element nie istnieją
DLL::DLL() {
    header = tail = nullptr;
    listSize = 0;
}

//Po zakończeniu programu pamięć jest zwalniana poprzez usunięcie każdego węzła
DLL::~DLL() {
        DLLNode *next = header -> next;
        while(header != nullptr) {
            next = header->next;
            delete[](header);
            header = next;
        }
}


void DLL::insertLast(int value) {
    DLLNode* temp = new DLLNode(value);

    //jeśli lista nie ma elementów to ustawiamy pierwszy i ostatni element na nowo dodany
    if (tail == nullptr)
        header = tail = temp;

    //zmieniamy wskaźnik next ogona na nowo utworzony element, a wskaźnik previous nowego elementu na wskaźnik poprzedniego.
    else
    {
        tail->next = temp;
        temp->previous = tail;
        tail = temp;
    }
    listSize++;
}

void DLL::insertFirst(int value) {
    DLLNode* temp = new DLLNode(value);

    //jeśli lista nie ma elementów to ustawiamy pierwszy i ostatni element na nowo dodany
    if (header == nullptr)
        header = tail = temp;

    //ustawiamy nowy węzeł jako header. Do pola next przypisujemy wskaźnik na poprzeni header. Do pola previous starego headera przypisujemy wskaźnik na nowo dodany element.
    else
    {
        header->previous = temp;
        temp->next = header;
        header = temp;
    }
    listSize++;
}

void DLL::insertAt(int index, int value) {
    DLLNode* newNode = new DLLNode(value);
    DLLNode* temp = header;

    //zabezpieczenia przed wyjściem poza zakres
    if(index == 0) {insertFirst(value); return;}
    if(index == listSize + 1) {insertLast(value); return;}
    if (index > listSize || index < 0) return;

    else{
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        //ustawiamy wskazniki nowego węzła na wskaźniki węzłów wcześniej ze sobą sąsiadujących
        newNode->next = temp->next;
        newNode->previous = temp;
        if(temp->next != nullptr){
            temp->next->previous = newNode;
        }
        temp->next = newNode;
        listSize++;
    }
}

void DLL::removeFirst() {
    //jeśli header nie wskazuje na następny element usuwamy go.
    if(header == nullptr) return;
    if(header->next == nullptr) {
        delete(header);
        header = nullptr;
        tail = nullptr;
        //Ustawiamy następny element jako header. Zwalniamy pamięć zajętą przez wskaźnik previous nowego headera. Niszczymy wskaźnik na usuwany węzeł.
    } else if(header != nullptr) {
        header = header->next;
        delete(header->previous);
        header->previous = nullptr;
    }
    listSize--;
}

void DLL::removeLast(){
    //jesli jest tylko 1 lub 0 elementow wykonujemy funkcje removeFirst();
    if(header== nullptr) return;
    if(header->next == nullptr) removeFirst();

    //Ustawiamy poprzedni element jako ogon. Zwalniamy pamięć zajętą przez wskaźnik next nowego ogona. Niszczymy wskaźnik na usuwany węzeł.
    else if(header != nullptr) {
        tail = tail->previous;
        delete(tail->next);
        tail->next = nullptr;
        listSize--;
    }
}

void DLL::removeAt(int index) {
    DLLNode* temp = header;

    //zabezpieczenia przed wyjściem poza zakres
    if(index == 0) {removeFirst(); return;}
    if(index == listSize - 1) {removeLast(); return;}
    if (index > listSize - 1 || index < 0) return;

    else{
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        (temp->previous)->next = temp->next;
        (temp->next)->previous = temp ->previous;
        delete(temp);
        tail->next = nullptr;
        listSize--;
    }
}

bool DLL::contains(int searched) {
    DLLNode* temp = header;
    while (temp != nullptr)
    {
        if(temp->value == searched) return true;
        temp = temp->next;
    }
    return false;
}

void DLL::print() {
    DLLNode* temp = header;
    //Przechodzimy od węzła do węzła, aż do napotkania wskaźnika null w polu next
    while (temp != nullptr)
    {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "null" << endl;
}

int DLL::getAt(int index) {
    DLLNode* temp = header;
    int i = 0;
    while (temp != nullptr)
    {
        if(i == index) return temp->value;
        i++;
        temp = temp->next;
    }
    return 2147483647; //Zwraca maksymalną wartość inta
}

int DLL::getSize() {
    return listSize-1;
}



