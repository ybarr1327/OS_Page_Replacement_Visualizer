#include "LRUReplacement.h"

/***************************************
 * Name: PageTable - Constructor
 * Purpose: this function will initialize the map vector to the initial size and values.
 *  int numPages - this corresponds to the number of pages in the page table
 * Output: N/A
 ***************************************/
LRUReplacement::LRUReplacement(int numPages)
{
	map.resize(numPages);//resize to have numPages entries
	for(int i = 0; i<numPages; i++)
	{
		map[i]=NULL;//initialize all initial values to NULL because they dont point to anything
	}
	
}

/***************************************
 * Name: PageTable - newReference()
 * Purpose: this function will process the references and adjust the list accordingly
 *  int pageNum - this corresponds to a pageNum in the page table
 * Output: N/A
 ***************************************/
void LRUReplacement::newReference(int pageNum)
{
	if (map[pageNum]== NULL)// if the page number is not assigned in the list
	{
		addRear(pageNum);//add it to the back
		
		map[pageNum]= Rear; // set the loaction of the map to the rear node
	}
	else
	{
		moveNodeToBack(map[pageNum]);// if the page is already in the DLL, then it just needs to be moved to the top
	}	
	
}

/***************************************
 * Name: PageTable - getVictimPage()
 * Purpose: this function will process Get the page at the front of the list, This page serves as the LRU
 * Output: This outputs the LRU integer that is a page number back to the caller function
 ***************************************/
int LRUReplacement::getVictimPage()
{
	Node * victim = Front;//point to the Front of the list
    int victimPageNum = Front->Elem;
	moveNodeToBack(victim);//move teh front node to the back
	return victimPageNum; //return the page number that was just referenced
}

//Purpose:
//This moves a node from location A to B
//Parameters:
//int A - position where the node that is being moved is at, int B position being moved to 
//Algorithm:
//Output: N/A
void LRUReplacement::moveNodeToBack(Node*& location)
{

    if (Count == 1) // if there is only one item in the list, then the item is technically already at the back so do nothing
    {
        return;
    }

    if (location == Front)//first node
    {
        //adjust pointers so that the first node is at the back and the new first node is now where the second one was
        Node* second= location->Next;
        second->Back=NULL;
        location->Back = Rear;
        location->Next=NULL;
        Rear->Next= location;
        Rear=location;
        Front = second;

    }
	else if (location == Rear) // if the location of the node is in the rear already, the function has nothing else to do
	{
		return;
	}
    else //node somewhere in the middle
    {

        //connect two nodes before and after A
        location->Back->Next = location->Next;
        location->Next->Back = location->Back;
        //set location to the rear
        location->Back = Rear;
        location->Next = NULL;
        //set rear to point to A
        Rear->Next = location;
        //make A new Rear
        Rear = location;


    }
               
   
}
