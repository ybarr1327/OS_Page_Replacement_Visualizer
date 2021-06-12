#include "DLL.h"

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create DLL.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes

//EMACS HINT:
//  You can copy from a Word document to emacs (contrl-right click)
//  cntr-K cuts and cntr-Y pastes
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++




#include<iostream>
#include"DLL.h" 

// constructor to create a list object
DLL::DLL()
{
    //cout << "... in DLL constructor..." << endl;
    //initialize the attributes to indicate empty list
    Front = NULL;
    Rear = NULL;
    Count = 0;
}

// destructor to destroy all nodes
DLL::~DLL()
{
    el_t deleted;//stores the value of the node being deleted
    //cout << ".... in DLL destructor..." << endl;
    while (!isEmpty()) //until empty delete nodes
    {
        deleteFront(deleted);
    }
}

//PURPOSE:This function checks the pointers and item count of the list to see if empty, if empty return true, otherwise return false;
//PARAMETER: none
//Algorithm: if the front rear and the count are at null and zero, then return true
bool DLL::isEmpty()
{
    
    if (Front == NULL && Rear == NULL && Count == 0)//if empty return true...
        return true;
    else// ... otherwise false
        return false;

} // be sure to check all 3 data members

//PURPOSE:This either displays all items in the list, or if empty, displays [ empty ]
//PARAMETER: none
//Algorithm: using a temporary node*, traverse the list, printing values as it goes.special case if empty, then show empty message.
//output: N/A
void DLL::displayAll()
{
    if (isEmpty()) //special case if empty then display [empty]
    {
        cout << "[ empty ]" << endl;
    }
    else //regular case
    {
        Node* temp = Front;//temporary node to traverse the list,starting at front
        cout << "[";
        int a = 1;
        while (a <= Count)//for every element in the list display the value move to next
        {
            a++;
            cout << " " << temp->Elem;
            temp = temp->Next;
        }
        cout << " ]" << endl;
    }
}  // be sure to display horizontally in [  ] with blanks between elements

//PURPOSE:This either displays all items in the list, or if empty, displays [ empty ]
//PARAMETER: none
//Algorithm: using a temporary node*, traverse the list, printing values as it goes.special case if empty, then show empty message.
//output: N/A
void DLL::displayAllBackwards()
{
    if (isEmpty()) //special case if empty then display [empty]
    {
        cout << "[ empty ]" << endl;
    }
    else //regular case
    {
        Node* temp = Rear;//temporary node to traverse the list,starting at front
        cout << "[";
        int a = 1;
        while (a <= Count)//for every element in the list display the value move to next
        {
            a++;
            cout << " " << temp->Elem;
            temp = temp->Back;
        }
        cout << " ]" << endl;
    }
}  // be sure to display horizontally in [  ] with blanks between elements

//Purpose:
//This adds a new node to the rear of the list
//Parameters
//NewNum-Pass the value of the new node being added
//Algorithm:
//create a new node and add it to the end of the list, the new node next will be pointing to null, special case if list is empty, if so then set the front and rear to point to new node
//output: N/A
void DLL::addRear(el_t NewNum)
{
    
    Node* newNode = new Node;//newNode to create and temporarily store new node
    if (isEmpty())//special case: if empty then set front and rear to new node
    {
        
        Front = newNode;
        
        Rear = newNode;
        
        newNode->Elem = NewNum;	//set value
        newNode->Next = NULL;//set next to null
        newNode->Back = NULL;//set the back to null
        
    }
    else//regular case
    {
        
        newNode->Back = Rear;
        
        Rear->Next = newNode;//set the rear to point to new rear
        Rear = Rear->Next;//move rear to new rear
        Rear->Elem = NewNum;//set the new rear value
        Rear->Next = NULL; //set rear next to null
    }
    Count++;//increase the count 

} // comment the 2 cases

//Purpose:
//This adds a node to the front of the list
//Parameters:
//NewNum-Pass the value of the new node being added
//Algorithm: create a new node and add it to the front of the list, special case if empty, if empty then set front and rear to new node, set value, pointer, and counter of new node  regular case then set the value, set the newnode next to the current front, then set the new front to the new Node
//output: N/A
void DLL::addFront(el_t NewNum)
{
    Node* temp = new Node;//temporary storage of the new node
    if (isEmpty())//special case if empty list
    {
        Front = temp;//set front and rear to temp
        Rear = temp;
        temp->Elem = NewNum;//set value
        temp->Next = NULL; //set next to null
        temp->Back = NULL; //set back to null
        Count++; //increment count
    }
    else //regular case
    {
        temp->Elem = NewNum;//set the value
        temp->Next = Front;//set the temp next to the current front
        temp->Back = NULL;
        Front->Back = temp;
        Front = temp;//set the new front to the temp node
        Count++;//increment counter
    }
} // comment the 2 cases

//Purpose:
//This deletes a node from the front of the list if not empty list
//Parameters:
//OldNum- el_t by reference to store the value in the node being deleted
//Algorithm:
//delete the node pointed to by the front pointer. then change the front to the next node.
//output: N/A
void DLL::deleteFront(el_t& OldNum)
{
    if (isEmpty())//error case. if empty then throw underflow
        throw Underflow();
    else if (Count == 1)//special case: if deleting will make empty
    {
        OldNum = Front->Elem;//store the value of front node
        delete Front;//delete front node
        Front = Rear = NULL; //set front and rear to null
        Count--;//decrement count
    }
    else//regular case
    {
        OldNum = Front->Elem;//store the value of front node
        Node* Second;//create a temp second node to store the second node in the list
        Second = Front->Next;
        delete Front;//delete the first/front node
        Front = Second;//set the new front to the second node
        Front->Back = NULL;
        Count--;//decrement count
    }
} // comment the 3 cases

//Purpose:
//This deletes a node from the rear of the list if not empty list
//Parameters:
//OldNum- pass by reference to store the value in the node being deleted
//Algorithm:
//if error case throw exception
//if special case, set front and rear to null after deleting rear
//if regular case, then get the second to last node, then delete rear, then set the second to last node to the new rear
void DLL::deleteRear(el_t& OldNum)
{
    if (isEmpty())//error case: if empty then throw exception
        throw Underflow();
    else if (Count == 1)//special case: deleting will make empty list
    {
        OldNum = Rear->Elem;//store the value
        delete Rear;//delete the rear
        Front = Rear = NULL;//set front and rear to null
        Count--;//decrement counter
    }
    else//regular case
    {
        OldNum = Rear->Elem;//store the value
        Node* secondToLast = Front;//node to store the second to last node
        while (secondToLast->Next != Rear)//move the node to the second to last one
            secondToLast = secondToLast->Next;
        delete Rear;// delete the rear node
        Rear = secondToLast; //set the rear to the second to last node
        Rear->Next = NULL;
        Count--; //decrement count.
    }

} // comment the 3 cases


/* harder ones follow */

// Utility Function to move a local pointer to the Ith node from the front
//Purpose:
//This is a utility function to move pointer (by reference) to a specified node position
//Parameters:
//J- to what node to move to | temp- the node pointer of the list
//Algorithm:
//moves the node pointer to the jth node by using loop
//IMPORTANT: temp should start at lists front node
//output: N/A
void DLL::moveToFromLeft(int J, Node*& temp)
{ // moves temp J-1 times
    for (int K = 1; K < J; K++)
        temp = temp->Next;
}

// Utility Function to move a local pointer to the Ith node from the rear
//Purpose:
//This is a utility function to move pointer (by reference) to a specified node position
//Parameters:
//J- to what node to move to | temp- the node pointer of the list
//Algorithm:
//moves the node pointer to the jth node by using loop
//IMPORTANT: temp should start at lists rear node
//output: N/A
void DLL::moveToFromRight(int J, Node*& temp)
{
    for (int K = Count; K > J; K--)
        temp = temp->Back;
}

//Purpose:
//this deletes a node at a specified position in the list
//Parameters:
//I:int value which is the position in the list (starting with position 1)
//OldNum: an el_t by reference to store the value in the node being deleted
//Algorithm:
//if error case: throw out of range exception
//if special case at front or at end, then use the already made functions
//if regular case, then get the before Ith node the ith Node and the after ith node. delete the ith node and link the beforeIth node and the afterIth node.
void DLL::deleteIth(int I, el_t& OldNum)
{
    if (I > Count || I < 1)//error case, I out of bounds, so throw exception
        throw OutOfRange();
    else if (I == 1)//special case, I at the front
    {
        deleteFront(OldNum);//use delete front function
    }
    else if (I == Count)//special case I at the end
    {
        deleteRear(OldNum);//use delete rear function
    }
    else//regular case
    {
        Node* temp = Front;//temp node to store the Ith node
        Node* beforeIth = Front;//stores the node before I
        Node* afterIth;//stores the node after I
        moveToFromLeft(I, temp);//mode temp to ith node
        while (beforeIth->Next != temp)//mode beforeIth to node before I/temp
            beforeIth = beforeIth->Next;
        afterIth = temp->Next;//move afterIth to Ith's next
        delete temp;//delete ith node
        beforeIth->Next = afterIth;//link before and after ith nodes
        afterIth->Back = beforeIth;
        Count--;//decrement count
    }
} // use moveToFromLeft to move local pointers. Be sure to comment to which node you are moving them.  



//Purpose:
//This inserts a node at a specified position in the list
//Parameters:
//NewNum- int value which is the position in the list (starting with position 1), and pass an el_t to store the value in the node being inserted
//Algorithm:
//check for proper case
//if error case and index I is out of range throw exception
//if special case either first position or last position then addFront or add Rear
//if regular case then calll move to to get Ith node, also get beforeIth node. then create a new node and insert between the beforeIth and Ith node.
//Output: returns DLL by value
void DLL::insertIth(int I, el_t newNum)
{
    if (I > (Count + 1) || I < 1)//error case, index out of range
        throw OutOfRange();//throw the exception
    else if (I == 1)//if first node then just use the addfront function
    {
        addFront(newNum);
    }
    else if (I == Count + 1)//if at the end of the list, then just use addRead funciton
    {
        addRear(newNum);
    }
    else//regular case
    {
        Node* temp = Front;//temp node to store Ith node
        Node* beforeIth = Front;//temp node to store node just before Ith node
        moveToFromLeft(I, temp);//move temp to ith node
        while (beforeIth->Next != temp)//move beforeIth to the node before node I
            beforeIth = beforeIth->Next;
        Node* newNode = new Node;//create a new node to insert
        newNode->Elem = newNum;//set the element
        beforeIth->Next = newNode;//set before ith next to newnode
        newNode->Next = temp;//set the newNode to the Ith node
        temp->Back = newNode;
        newNode->Back = beforeIth;
        Count++;//increment count
    }

} // use moveToFromLeft to move local pointers. Be sure to comment to which node you are moving them.

//Purpose:Copy Constructor to allow pass by value and return by value of a DLL
//Parameters: Original- copy by reference, usually handled without calling explicitly aka pass by value/return by reference 
//Algorithm:
//initialize this->'s data members then for every node in the original, add a new node to this
//Output: returns a reference to a DLL
DLL::DLL(const DLL& Original)
{
    //  this->'s data members need to be initialized here first
    Front = NULL; Rear = NULL; Count = 0;
    //  this-> object has to be built up by allocating new cells
    //  and copying the values from Original into each cell as we did with 
    //  operator= above. To do this,
    //copy here the(**) lines in Operator Overloading of = but note that it is Original and not OtherOne.

    Node* P;  // local pointer for Original
    P = Original.Front;//set P to original front
    while (P != NULL)  // a loop which repeats until you reach the end of Original. 
    {
        this->addRear(P->Elem);    //P's element is added to this->
        P = P->Next;                         // Go to the next node in original   
    }


    //  Nothing to return because this is a constructor.

} // use my code

//Purpose: Overloading of = (returns a reference to a DLL) to copy a list
//Parameters: OtherOne-the paramter is the original copy, handled as expected by using the equals operator, aka List1=List2
//Algorithm:
//first check if already the same if not then start copying by emptying this list, then for every node in OtherOne, add nodes to this list.
DLL& DLL::operator=(const DLL& OtherOne)
{
    el_t x;//stores the values of deleted values
    // First make sure this-> and OtherOne are not the same object.
    // To do this, compare the pointers to the objects .
    if (&OtherOne != this)  // if not the same
    {
        // this-> object has to be emptied first.
        while (!this->isEmpty())
            this->deleteRear(x);
        // this-> object has to be built up by allocating new cells with OtherOne elements 
        Node* P;  // local pointer for OtherOne
        P = OtherOne.Front;//set P to point to front of OtherOne
        while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
        {
            this->addRear(P->Elem);    //P's element is added to this->
            P = P->Next;    // Go to the next node in OtherOne   
        }
    }// end of if              
    return *this;
    // return the result unconditionally.  Note that the result is returned by reference.

}



