//---------------------------------------------------------------------
// Name: Robert Bennethum IV
// Email: rmb6287@psu.edu
// Class: CMPSC 122, Section 3
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
//https://www.geeksforgeeks.org/highest-power-2-less-equal-given-number/ to find how to get the next highest power of 2
//---------------------------------------------------------------------

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class BasicVector
{
private:
	int vector_size;
	int vector_capacity;
	int* data;

	void resize();

public:
	BasicVector() {}; // default constructor does nothing
	BasicVector(int);
	~BasicVector();

	int& at(int);
	int& operator[](int);
	int& front();
	int& back();

	void push_back(int);
	void insert(int, int);
	void pop_back();

	int size();
	int capacity();

	void print();
};

void BasicVector::resize()
{
    int* biggerArray;
    biggerArray = new int (capacity()*2);
    for (int i = 0; i++; i<size()) {
        biggerArray[i] = data[i];
    }
    delete[] data;
    data = biggerArray;
    vector_capacity = capacity()*2;
}

BasicVector::BasicVector(int capacity)
{
    if (capacity<=16) {
        data = new int[16];
        vector_capacity = 16;
    }
    else {
        capacity = log2(capacity);
        capacity = pow(2,capacity);
        capacity *= 2;
        data = new int[capacity];
        vector_capacity = capacity;
    }
    vector_size = 0;
}

BasicVector::~BasicVector()
{
    for (int i = 0; i<size(); i++)
        data[i] = 0;
    delete[] data;
}

int& BasicVector::at(int index)
{
    if (size() <= index)
        exit(1);
    return data[index];
}

int& BasicVector::operator[](int index)
{
    if (size() <= index)
	    exit(1);
    else {
        return data[index];
    }

}

int &BasicVector::front() {
    return data[0];
}

int &BasicVector::back() {
    return data[size()-1];
}

void BasicVector::push_back(int number) {
data[size()] = number;
vector_size += 1;
}

void BasicVector::insert(int index, int number) {
if (size()+1 > capacity())
    resize();
int temp;
for (int i = index; i<size(); i++) {
    temp = data[i];
    data[i+1] = temp;
}
data[index] = number;
vector_size+=1;
}

void BasicVector::pop_back() {
data[size()] = 0;
vector_size -= 1;
}

int BasicVector::size() {
    return vector_size;
}

int BasicVector::capacity() {
    return vector_capacity;
}

void BasicVector::print() {
    cout << "elements(" << size() << "): ";
    for (int i = 0; i<size(); i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

// Add in the rest of the public functions

int main()
{
	int capacity;
	cout << "Enter starting capacity of vector: ";
	cin >> capacity;

	BasicVector vector(capacity);

	// Implement command prompt loop
    cout << "Now accepting commands (quit to exit program):" << endl;
    string command;
    int num, num2;
	while(command != "quit")
	{
		cin >> command;
        if (command == "at") {
            cin >> num;
            cout << vector.at(num) << endl;
        }
        else if (command == "get") {
            cin >> num;
            cout << vector[num] << endl;
        }
        else if (command == "front") {
            cout << vector.front() << endl;
        }
        else if (command == "back") {
            cout << vector.back() << endl;
        }
        else if (command == "insert") {
            cin >> num >> num2;
            vector.insert(num, num2);
        }
        else if (command == "push") {
            cin >> num;
            vector.push_back(num);
        }
        else if (command == "pop") {
            vector.pop_back();
        }
        else if (command == "size") {
            cout << vector.size() << endl;
        }
        else if (command == "capacity") {
            cout << vector.capacity() << endl;
        }
        else if (command == "print") {
            vector.print();
        }
        else {
            cout << "Unknown Command" << endl;
        }
	}

	return 0;
}