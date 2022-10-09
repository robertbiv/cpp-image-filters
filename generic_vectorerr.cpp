//---------------------------------------------------------------------
// Name: Michael Melusky
// Email: mcm297@psu.edu
// Class: CMPSC 122, Section 2
// Program 3.2
// Due Date: March 19 2020, 11:59 PM
//
// Description: This program implements a basic integer vector
// and provides the user with an interactive prompting system
// to issue commands over an instance of our BasicVector class.
//
// Acknowledgements:
// 1. Please use this portion of the banner comment to list
// any resources or individuals you consulted on the creation
// of this program.
//---------------------------------------------------------------------
//fix operator
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

template<class T>
class BasicVector
{
private:
	int vector_size;
	int vector_capacity;
	T* data;

    void resize();

public:
    BasicVector() {}; // default constructor does nothing
    BasicVector(int);
    ~BasicVector();

    T& at(int);
    int& operator[](T);
    T& front();
    T& back();

    int push_back(T);
    void insert(int, T);
    void pop_back();

    int size();
    int capacity();

    void print();
};
template<class T>
void BasicVector<T>::resize()
{
    T *biggerArray;
    biggerArray = new T[capacity()*2];
    for (int i = 0; i++; i<size()) {
        biggerArray[i] = data[i];
    }
    delete[] data;
    data = biggerArray;
    vector_capacity = capacity()*2;
}

template<class T>
BasicVector<T>::BasicVector(int capacity)
{
    if (capacity<=16) {
        data = new T[16];
        vector_capacity = 16;
    }
    else {
        capacity = log2(capacity);
        capacity = pow(2,capacity);
        capacity *= 2;
        data = new T[capacity];
        vector_capacity = capacity;
    }
    vector_size = 0;
}

template<class T>
BasicVector<T>::~BasicVector()
{
    delete[] data;
}

template<class T>
T& BasicVector<T>::at(int index)
{
    if (size() <= index)
        exit(1);
    return data[index];
}

template<class T>
int &BasicVector<T>::operator[](T theNum)
{
    for (int i = 0; i < size(); i++)
        if (at(i) == theNum)
            return i;
    exit(1);
}

template<class T>
T &BasicVector<T>::front() {
    return data[0];
}

template<class T>
T &BasicVector<T>::back() {
    return data[size()-1];
}

template<class T>
int BasicVector<T>::push_back(T stuff) {
    data[size()] = stuff;
    vector_size += 1;
    return size();
}

template<class T>
void BasicVector<T>::insert(int index, T number) {
    if (size()+1 > capacity())
        resize();
    T temp;
    for (int i = index; i<size(); i++) {
        temp = data[i];
        data[i+1] = temp;
    }
    data[index] = number;
    vector_size+=1;
}

template<class T>
void BasicVector<T>::pop_back() {
    data[size()];
    vector_size -= 1;
}

template<class T>
int BasicVector<T>::size() {
    return vector_size;
}

template<class T>
int BasicVector<T>::capacity() {
    return vector_capacity;
}

template<class T>
void BasicVector<T>::print() {
    cout << "elements(" << size() << "): ";
    for (int i = 0; i<size(); i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

// Add in the rest of the public functions
//template<class T>
//void commandLoop(T, int);
int main()
{
    int num;
    cout << "Specify what data type to store in vector:" << endl;
    cout << "     1) int\n     2) float\n     3) double\n     4) string\n     5) bool" << endl;
    cin >> num;
    string data_type;
    switch (num) {
        case 1:
            data_type = "int";
            break;
        case 2:
            data_type = "float";
            break;
        case 3:
            data_type = "double";
            break;
        case 4:
            data_type = "string";
            break;
        case 5:
            data_type = "bool";
            break;
    }

    int capacity;
    cout << "Enter starting capacity of " << data_type << " vector: ";
    cin >> capacity;

    if (num == 1) {
        auto vector = new BasicVector<int>(capacity);
        cout << "Now accepting commands (quit to exit program):" << endl;
        string command;
        int num1;
        while(command != "quit")
        {
            cin >> command;
            if (command == "at") {
                cin >> num1;
                cout << vector->at(num1) << endl;
            }
            else if (command == "get") {
                cin >> num1;
                cout << &vector[num1] << endl;
            }
            else if (command == "front") {
                cout << vector->front() << endl;
            }
            else if (command == "back") {
                cout << vector->back() << endl;
            }
            else if (command == "insert") {
                cin >> num1;
                int num2;
                cin >> num2;
                vector->insert(num1, num2);
            }
            else if (command == "push") {
                int var2;
                cin >> var2;
                vector->push_back(var2);
            }
            else if (command == "pop") {
                vector->pop_back();
            }
            else if (command == "size") {
                cout << vector->size() << endl;
            }
            else if (command == "capacity") {
                cout << vector->capacity() << endl;
            }
            else if (command == "print") {
                vector->print();
            }
            else if (command == "quit") {
                exit(1);
            }
            else {
                cout << "Unknown Command" << endl;
            }
        }
    }
    else if (num == 2) {
        auto vector = new BasicVector<float>(capacity);//fix
        //commandLoop(vector, num);
        cout << "Now accepting commands (quit to exit program):" << endl;
        string command;
        int num1;
        while(command != "quit")
        {
            cin >> command;
            if (command == "at") {
                cin >> num1;
                cout << vector->at(num1) << endl;
            }
//            else if (command == "get") {
//                cin >> num1;
//                cout << vector->operator[](num1) << endl;
//            }
            else if (command == "front") {
                cout << vector->front() << endl;
            }
            else if (command == "back") {
                cout << vector->back() << endl;
            }
            else if (command == "insert") {
                cin >> num1;
                float num2;
                cin >> num2;
                vector->insert(num1, num2);
            }
            else if (command == "push") {
                float var2;
                cin >> var2;
                vector->push_back(var2);
            }
            else if (command == "pop") {
                vector->pop_back();
            }
            else if (command == "size") {
                cout << vector->size() << endl;
            }
            else if (command == "capacity") {
                cout << vector->capacity() << endl;
            }
            else if (command == "print") {
                vector->print();
            }
            else if (command == "quit") {
                exit(1);
            }
            else {
                cout << "Unknown Command" << endl;
            }
        }
    }
    else if (num == 3) {
        auto vector = new BasicVector<double>(capacity);
        cout << "Now accepting commands (quit to exit program):" << endl;
        string command;
        int num1;
        while(command != "quit")
        {
            cin >> command;
            if (command == "at") {
                cin >> num1;
                cout << vector->at(num1) << endl;
            }
            else if (command == "get") {
                double double1;
                cin >> double1;
                cout << &vector[double1] << endl;
            }
            else if (command == "front") {
                cout << vector->front() << endl;
            }
            else if (command == "back") {
                cout << vector->back() << endl;
            }
            else if (command == "insert") {
                cin >> num1;
                double num2;
                cin >> num2;
                vector->insert(num1, num2);
            }
            else if (command == "push") {
                double var2;
                cin >> var2;
                vector->push_back(var2);
            }
            else if (command == "pop") {
                vector->pop_back();
            }
            else if (command == "size") {
                cout << vector->size() << endl;
            }
            else if (command == "capacity") {
                cout << vector->capacity() << endl;
            }
            else if (command == "print") {
                vector->print();
            }
            else if (command == "quit") {
                exit(1);
            }
            else {
                cout << "Unknown Command" << endl;
            }
        }
    }
    else if (num == 4) {
        auto vector = new BasicVector<string>(capacity);
        //commandLoop(vector, num);
        cout << "Now accepting commands (quit to exit program):" << endl;
        string command;
        int num1;
        while(command != "quit")
        {
            cin >> command;
            if (command == "at") {
                cin >> num1;
                cout << vector->at(num1) << endl;
            }
           // else if (command == "get") {
           //     string string1;
           //     cin >> string1;
           //     cout << &vector[string1] << endl;
            //}
            else if (command == "front") {
                cout << vector->front() << endl;
            }
            else if (command == "back") {
                cout << vector->back() << endl;
            }
            else if (command == "insert") {
                cin >> num1;
                string num2;
                cin >> num2;
                vector->insert(num1, num2);
            }
            else if (command == "push") {
                string var2;
                cin >> var2;
                vector->push_back(var2);
            }
            else if (command == "pop") {
                vector->pop_back();
            }
            else if (command == "size") {
                cout << vector->size() << endl;
            }
            else if (command == "capacity") {
                cout << vector->capacity() << endl;
            }
            else if (command == "print") {
                vector->print();
            }
            else if (command == "quit") {
                exit(1);
            }
            else {
                cout << "Unknown Command" << endl;
            }
        }
    }
    else if (num == 5) {
        auto vector = new BasicVector<bool>(capacity);
        //commandLoop(vector, num);
        cout << "Now accepting commands (quit to exit program):" << endl;
        string command;
        int num1;
        while(command != "quit")
        {
            cin >> command;
            if (command == "at") {
                cin >> num1;
                cout << vector->at(num1) << endl;
            }
            else if (command == "get") {
                bool bool1;
                cin >> bool1;
                cout << &vector[bool1] << endl;
            }
            else if (command == "front") {
                cout << vector->front() << endl;
            }
            else if (command == "back") {
                cout << vector->back() << endl;
            }
            else if (command == "insert") {
                cin >> num1;
                bool num2;
                cin >> num2;
                vector->insert(num1, num2);
            }
            else if (command == "push") {
                bool var2;
                cin >> var2;
                vector->push_back(var2);
            }
            else if (command == "pop") {
                vector->pop_back();
            }
            else if (command == "size") {
                cout << vector->size() << endl;
            }
            else if (command == "capacity") {
                cout << vector->capacity() << endl;
            }
            else if (command == "print") {
                vector->print();
            }
            else if (command == "quit") {
                exit(1);
            }
            else {
                cout << "Unknown Command" << endl;
            }
        }
    }
    return 0;
}