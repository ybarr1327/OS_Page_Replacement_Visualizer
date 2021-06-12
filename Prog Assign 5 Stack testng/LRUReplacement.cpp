#include "LRUReplacement.h"

LRUReplacement::LRUReplacement(int numPages)
{
	map.resize(numPages);
	for(int i = 0; i<numPages; i++)
	{
		map[i]=NULL;
	}
	
}

void LRUReplacement::newReference(int pageNum)
{
	if (exists.find(pageNum)== exists.end())
	{
		addRear(pageNum);
		
		map[pageNum]= Rear;
        exists[pageNum] = 1;
	}
	else
	{
		moveNodeToBack(map[pageNum]);
	}	
	
}


int LRUReplacement::getVictimPage()
{
	Node * victim = Front;
	moveNodeToBack(victim);
	return victim->Elem;
}

//Purpose:
//This moves a node from location A to B
//Parameters:
//int A - position where the node that is being moved is at, int B position being moved to 
//Algorithm:
//Output: N/A
void LRUReplacement::moveNodeToBack(Node*& location)
{

    if (Count == 1)
    {
        return;
    }

    if (location == Front)//first node
    {
        Node* second= location->Next;
        second->Back=NULL;
        location->Back = Rear;
        location->Next=NULL;
        Rear->Next= location;
        Rear=location;
        Front = second;

    }
	else if (location == Rear)
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
