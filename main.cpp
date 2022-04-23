#include <iostream>
#include <fstream>
#include "Timer/Timer.h"
#include "MaxHeap/MaxHeap.h"
#include "DLL/DLL.h"
#include "Array/Array.h"

using namespace std;

void testAll();
void testArray();
void testDLL();
void testHeap();
void heapMenu(MaxHeap heap);
void listMenu(DLL dll);
void arrayMenu(Array array);
void fileMenu();
string filepathAsk();
void startMenu();
void testMenu();
void structMenu();

int main() {
    startMenu();
    return 0;
}

void testAll() {
    testArray();
    testDLL();
    testHeap();
}

void startMenu(){
    system("cls");
    cout<<"[Menu startowe]\n\nWybierz opcje:\n[1] Testy automatyczne.\n[2] Testy reczne\n[3] Wczytaj i wyswietl strukture z pliku\n[4] Zakoncz program\n";
    int choice = 0;
    do{
        cin>>choice;
    }while(choice != 1 && choice != 2 && choice != 3 && choice != 4);

    switch(choice){
        case 1: testMenu();
        case 2: structMenu();
        case 3: fileMenu();
        case 4: return;
    }
}

void structMenu(){
    system("cls");
    cout<<"[Menu struktur]\n\nWybierz strukture:\n[1] Lista dwukierunkowa.\n[2] Tablica dynamiczna\n[3] Kopiec binarny\n[4] Powrot do poprzedniego menu\n";
    int choice = 0;
    do{
        cin>>choice;
    }while(choice != 1 && choice != 2 && choice != 3 && choice != 4);

    switch(choice){
        case 1: {DLL list; listMenu(list); structMenu();}
        case 2: {Array array; arrayMenu(array); structMenu();}
        case 3: {MaxHeap heap; heapMenu(heap); structMenu();}
        case 4: startMenu();
    }
}

void fileMenu(){
    system("cls");
    cout<<"[Wczytywanie z pliku]\n\nWybierz strukture:\n[1] Lista dwukierunkowa.\n[2] Tablica dynamiczna\n[3] Kopiec binarny\n[4] Powrot do poprzedniego menu\n";
    int choice = 0;
    do{
        cin>>choice;
    }while(choice != 1 && choice != 2 && choice != 3 && choice != 4);

    switch(choice){
        case 1: {
            DLL list;
            ifstream file;
            file.open(filepathAsk());
            if(!file){cout<<"Nie ma takiego pliku..."; fileMenu();}
            else{
                int elementCount;
                int value;
                file >> elementCount;
                for(int i = 0; i < elementCount; i++) {
                    file >> value;
                    list.insertLast(value);
                }
                list.print();
                system("pause");
            }
        }
        case 2: {
            Array array;
            ifstream file;
            file.open(filepathAsk());
            if(!file){cout<<"Nie ma takiego pliku..."; fileMenu();}
            else{
                int elementCount;
                int value;
                file >> elementCount;
                for(int i = 0; i < elementCount; i++) {
                    file >> value;
                    array.insertLast(value);
                }
                array.print();
                system("pause");
            }
        }
        case 3: {
            MaxHeap heap;
            ifstream file;
            file.open(filepathAsk());
            if(!file){cout<<"Nie ma takiego pliku..."; fileMenu();}
            else{
                int elementCount;
                int value;
                file >> elementCount;
                for(int i = 0; i < elementCount; i++) {
                    file >> value;
                    heap.insert(value);
                }
                cout<<heap.print();
                system("pause");
            }
        }
        case 4: startMenu();
    }
}

void testMenu(){
    system("cls");
    cout<<"[Menu testu]\n\nWybierz opcje:\n[1] Test listy.\n[2] Test tablicy\n[3] Test kopca\n[4] Wszystkie testy\n[5] Poprzednie menu\n";
    int choice = 0;
    do{
        cin>>choice;
    }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);

    switch(choice){
        case 1:{system("cls");

            testDLL();
            system("pause");
        }
        case 2:{
            system("cls");
            testArray();
            system("pause");
        }
        case 3:{
            system("cls");
            testHeap();
            system("pause");
        }
        case 4:{
            system("cls");
            testAll();
            system("pause");
        }
        case 5: startMenu();
    }
}

void heapMenu(MaxHeap heap){
    system("cls");
    cout<<heap.print();
    string botMenu = "\n\nWybierz opcje:\n[1] Dodaj klucz (value), [2] Usun klucz (index), [3] Usun korzen ()\n"
                     "[4] Sprawdz czy zaiwiera (value), [5] Poprzednie menu ()\n";
    cout<< botMenu;
    int choice = 0, value = 0, index = 0;
    do{
        cin>>choice;
    }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);

    switch(choice){
        case 1: {
            cin>>value;
            heap.insert(value);
            heapMenu(heap);
        }
        case 2: {
            cin>>index;
            heap.removeAt(index);
            heapMenu(heap);
        }
        case 3: {
            heap.removeRoot();
            heapMenu(heap);
        }
        case 4: {
            cin>>value;
            cout<<"0 - nie zawiera\n1 - zawiera\n"<<heap.contains(value)<<"\n\nNaciśnij enter aby kontynuowac...";
            system("pause");
            heapMenu(heap);
        }
        case 5: {
            structMenu();
        }
    }
}

void listMenu(DLL dll){
    system("cls");
    dll.print();
    string botMenu = "\n\nWybierz opcje:\n[1] Dodaj na poczatku (value), [2] Dodaj na koncu (value), [3] Dodaj w wybranym miejscu (index, value)\n"
                     "[4] Usun na początku (), [5] Usun na koncu (), [6] Usun w wybranym miejscu (index)\n[7]Sprawdz czy zaiwiera (value), [8] Poprzednie menu ()\n";
    cout<< botMenu;
    int choice = 0, value = 0, index = 0;
    do{
        cin>>choice;
    }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8);

    switch(choice){
        case 1: {
            cin>>value;
            dll.insertFirst(value);
            listMenu(dll);
        }
        case 2: {
            cin>>value;
            dll.insertLast(value);
            listMenu(dll);
        }
        case 3: {
            cin>>index;
            cin>>value;
            dll.insertAt(index, value);
            listMenu(dll);
        }
        case 4: {
            dll.removeFirst();
            listMenu(dll);
        }
        case 5: {
            dll.removeLast();
            listMenu(dll);
        }
        case 6: {
            cin>>index;
            dll.removeAt(index);
            listMenu(dll);
        }
        case 7: {
            cin>>value;
            cout<<"0 - nie zawiera\n1 - zawiera\n"<<dll.contains(value)<<"\n\nNacisnij enter aby kontynuowac...";
            system("pause");
            listMenu(dll);
        }
        case 8: {
            structMenu();
        }
    }
}


void arrayMenu(Array array){
    system("cls");
    array.print();
    string botMenu = "\n\nWybierz opcje:\n[1] Dodaj na poczatku (value), [2] Dodaj na koncu (value), [3] Dodaj w wybranym miejscu (index, value)\n"
                     "[4] Usun na poczatku (), [5] Usun na koncu (), [6] Usun w wybranym miejscu (index) [7] Sprawdz czy zawiera (value), \n[8] Poprzednie menu ()";
    cout<< botMenu;
    int choice = 0, value = 0, index = 0;
    do{
        cin>>choice;
    }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8);

    switch(choice){
        case 1: {
            cin>>value;
            array.insertFirst(value);
            arrayMenu(array);
        }
        case 2: {
            cin>>value;
            array.insertLast(value);
            arrayMenu(array);
        }
        case 3: {
            cin>>index;
            cin>>value;
            array.insertAt(index, value);
            arrayMenu(array);
        }
        case 4: {
            array.removeFirst();
            arrayMenu(array);
        }
        case 5: {
            array.removeLast();
            arrayMenu(array);
        }
        case 6: {
            cin>>index;
            array.removeAt(index);
            arrayMenu(array);
        }
        case 7: {
            cin>>value;
            cout<<"0 - nie zawiera\n1 - zawiera\n"<<array.contains(value)<<"\n\nNacisnij enter aby kontynuowac...";
            system("pause");
            arrayMenu(array);
        }
        case 8: {
            structMenu();
        }
    }
}

string filepathAsk(){
    string filepath;
    system("cls");
    cout<<"[Wczytywanie z pliku]\n\nPodaj sciezke do pliku:"<<endl;
    cin>>filepath;
    return filepath;
}

void testArray(){
    Timer timer;
    cout <<"Tablica - dodawanie elementu na poczatku"<<endl;
    timer.arrayInsertFirst(500, 1000);   
    timer.arrayInsertFirst(1000, 1000);  
    timer.arrayInsertFirst(5000, 1000);  
    timer.arrayInsertFirst(10000, 1000); 
    timer.arrayInsertFirst(25000, 1000); 
    timer.arrayInsertFirst(50000, 1000); 

    cout <<"Tablica - dodawanie elementu w srodku"<<endl;
    timer.arrayInsertMid(500, 1000);
    timer.arrayInsertMid(1000, 1000);
    timer.arrayInsertMid(5000, 1000);
    timer.arrayInsertMid(10000, 1000);
    timer.arrayInsertMid(25000, 1000);
    timer.arrayInsertMid(50000, 1000);

    cout <<"Tablica - dodawanie elementu na koncu"<<endl;
    timer.arrayInsertLast(500, 1000);
    timer.arrayInsertLast(1000, 1000);
    timer.arrayInsertLast(5000, 1000);
    timer.arrayInsertLast(10000, 1000);
    timer.arrayInsertLast(25000, 1000);
    timer.arrayInsertLast(50000, 1000);

    cout <<"Tablica - usuwanie elementu na poczatku"<<endl;
    timer.arrayRemoveLast(500, 1000);
    timer.arrayRemoveLast(1000, 1000);
    timer.arrayRemoveLast(5000, 1000);
    timer.arrayRemoveLast(10000, 1000);
    timer.arrayRemoveLast(25000, 1000);
    timer.arrayRemoveLast(50000, 1000);

    cout <<"Tablica - usuwanie elementu w srodku"<<endl;
    timer.arrayRemoveMid(500, 1000);
    timer.arrayRemoveMid(1000, 1000);
    timer.arrayRemoveMid(5000, 1000);
    timer.arrayRemoveMid(10000, 1000);
    timer.arrayRemoveMid(25000, 1000);
    timer.arrayRemoveMid(50000, 1000);

    cout <<"Tablica - usuwanie elementu na koncu"<<endl;
    timer.arrayRemoveFirst(500, 1000);
    timer.arrayRemoveFirst(1000, 1000);
    timer.arrayRemoveFirst(5000, 1000);
    timer.arrayRemoveFirst(10000, 1000);
    timer.arrayRemoveFirst(25000, 1000);
    timer.arrayRemoveFirst(50000, 1000);

    cout <<"Tablica - wyszukiwanie środkowego elementu"<<endl;
    timer.arraySearchMid(500, 1000);
    timer.arraySearchMid(1000, 1000);
    timer.arraySearchMid(5000, 1000);
    timer.arraySearchMid(10000, 1000);
    timer.arraySearchMid(25000, 1000);
    timer.arraySearchMid(50000, 1000);
}

void testDLL(){
    Timer timer;
    cout <<"Lista - dodawanie elementu na poczatku"<<endl;
    timer.dllInsertFirst(500, 1000);
    timer.dllInsertFirst(1000, 1000);
    timer.dllInsertFirst(5000, 1000);
    timer.dllInsertFirst(10000, 1000);
    timer.dllInsertFirst(25000, 1000);
    timer.dllInsertFirst(50000, 1000);

    cout <<"Lista - dodawanie elementu w srodku"<<endl;
    timer.dllInsertMid(500, 1000);
    timer.dllInsertMid(1000, 1000);
    timer.dllInsertMid(5000, 1000);
    timer.dllInsertMid(10000, 1000);
    timer.dllInsertMid(25000, 1000);
    timer.dllInsertMid(50000, 1000);

    cout <<"Lista - dodawanie elementu na koncu"<<endl;
    timer.dllInsertLast(500, 1000);
    timer.dllInsertLast(1000, 1000);
    timer.dllInsertLast(5000, 1000);
    timer.dllInsertLast(10000, 1000);
    timer.dllInsertLast(25000, 1000);
    timer.dllInsertLast(50000, 1000);

    cout <<"Lista - usuwanie elementu na poczatku"<<endl;
    timer.dllRemoveFirst(500, 1000);
    timer.dllRemoveFirst(1000, 1000);
    timer.dllRemoveFirst(5000, 1000);
    timer.dllRemoveFirst(10000, 1000);
    timer.dllRemoveFirst(25000, 1000);
    timer.dllRemoveFirst(50000, 1000);

    cout <<"Lista - usuwanie elementu w srodku"<<endl;
    timer.dllRemoveMid(500, 1000);
    timer.dllRemoveMid(1000, 1000);
    timer.dllRemoveMid(5000, 1000);
    timer.dllRemoveMid(10000, 1000);
    timer.dllRemoveMid(25000, 1000);
    timer.dllRemoveMid(50000, 1000);

    cout <<"Lista - usuwanie elementu na koncu"<<endl;
    timer.dllRemoveLast(500, 1000);
    timer.dllRemoveLast(1000, 1000);
    timer.dllRemoveLast(5000, 1000);
    timer.dllRemoveLast(10000, 1000);
    timer.dllRemoveLast(25000, 1000);
    timer.dllRemoveLast(50000, 1000);

    cout <<"Lista - wyszukiwanie elementu w srodku"<<endl;
    timer.dllSearchMid(500, 1000);
    timer.dllSearchMid(1000, 1000);
    timer.dllSearchMid(5000, 1000);
    timer.dllSearchMid(10000, 1000);
    timer.dllSearchMid(25000, 1000);
    timer.dllSearchMid(50000, 1000);
}

void testHeap(){
    Timer timer;
    cout<<"Kopiec - dodawanie elementu"<<endl;
    timer.heapInsert(500, 1000);
    timer.heapInsert(1000, 1000);
    timer.heapInsert(5000, 1000);
    timer.heapInsert(10000, 1000);
    timer.heapInsert(25000, 1000);
    timer.heapInsert(50000, 1000);

    cout<<"Kopiec - usuwanie elementu ze srodka"<<endl;
    timer.heapRemoveMid(500, 1000);
    timer.heapRemoveMid(1000, 1000);
    timer.heapRemoveMid(5000, 1000);
    timer.heapRemoveMid(10000, 1000);
    timer.heapRemoveMid(25000, 1000);
    timer.heapRemoveMid(50000, 1000);

    cout<<"Kopiec - usuwanie korzenia"<<endl;
    timer.heapRemoveRoot(500, 1000);
    timer.heapRemoveRoot(1000, 1000);
    timer.heapRemoveRoot(5000, 1000);
    timer.heapRemoveRoot(10000, 1000);
    timer.heapRemoveRoot(25000, 1000);
    timer.heapRemoveRoot(50000, 1000);

    cout<<"Kopiec - wyszukiwanie"<<endl;
    timer.heapSearchMid(500, 1000);
    timer.heapSearchMid(1000, 1000);
    timer.heapSearchMid(5000, 1000);
    timer.heapSearchMid(10000, 1000);
    timer.heapSearchMid(25000, 1000);
    timer.heapSearchMid(50000, 1000);
}