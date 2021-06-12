#pragma once 

#include <vector>
#include <iostream>
using namespace std;

// alias el_t : element type definition
typedef int el_t;

//a list node is defined here as a struct Node for now
struct Node
{
    el_t Elem;   // elem is the element stored
    Node* Back; //Back pointer to the previous node
    Node* Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class DLL
{
protected:
    Node* Front;       // pointer to the front node
    Node* Rear;        // pointer to the rear node
    int  Count;        // counter for the number of nodes
public:
    // Exception handling classes 
    class Underflow {};// thrown when the list is empty but a calling function needs an element
    class OutOfRange {};// thrown when the specified Node is out of range
    DLL();     // constructor to create a list object
    ~DLL();     // destructor to destroy all nodes


    //Purpose:
    //This is a utility function to move pointer (by reference) to a specified node position from the left/front
    //Parameters:
    //Node* of the list that needs to be moved
    //output: N/A
    void moveToFromLeft(int, Node*&);
    
    //Purpose:
    //This is a utility function to move pointer (by reference) to a specified node position from the right/rear
    //Parameters:
    //Node* of the list that needs to be moved
    //output: N/A
    void moveToFromRight(int, Node*&);

    //Purpose:
    //This function checks the pointers and item count of the list to see if empty, if empty return true, otherwise return false;
    //Parameters:N/A
    //Output:returns true if count is zero or false if count != 0 
    bool isEmpty();

    //Purpose:
    //This either displays all items in the list, or if empty, displays [ empty ]
    //Paramters:N/A
    //Output:N/A
    void displayAll();

    //Purpose:
    //This either displays all items in the list backwards, or if empty, displays [ empty ]
    //Paramters:N/A
    //Output:N/A
    void displayAllBackwards();

    //Purpose:
    //This adds a node to the front of the list
    //Parameters:
    //Pass the value of the new node being added
    //Output: N/A
    void addFront(el_t);

    //Purpose:
    //This adds a new node to the rear of the list
    //Parameters
    //Pass the value of the new node being added
    //Output: N/A
    void addRear(el_t);

    //Purpose:
    //This deletes a node from the front of the list if not empty list
    //Parameters:
    //Pass an el_t by reference to store the value in the node being deleted
    //Output: N/A
    void deleteFront(el_t&);

    //Purpose:
    //This deletes a node from the rear of the list if not empty list
    //Parameters:
    //Pass an el_t by reference to store the value in the node being deleted
    //Output: N/A
    void deleteRear(el_t&);

    //Purpose:
    //this deletes a node at a specified position in the list
    //Parameters:
    //An int value which is the position in the list (starting with position 1), and pass an el_t by reference to store the value in the node being deleted
    //Output: N/A
    void deleteIth(int, el_t&);  // calls moveToFromLeft

    

    //Purpose:
    //This inserts a node at a specified position in the list
    //Parameters:
    //An int value which is the position in the list (starting with position 1), and pass an el_t to store the value in the node being inserted
    //Output: N/A
    void insertIth(int, el_t);   // calls moveToFromLeft

    //Purpose:Copy Constructor to allow pass by value and return by value of a DLL
    //Parameters: Original copy by reference, usually handled without calling explicitly aka pass by value/return by reference 
    //Output: returns DLL by value
    DLL(const DLL&);

    //Purpose: Overloading of = (returns a reference to a DLL) to copy a list
    //Parameters: the paramter is the original copy, handled as expected by using the equals operator, aka List1=List2
    //Output: returns a reference to a DLL) to copy a list
    DLL& operator=(const DLL&);
};


