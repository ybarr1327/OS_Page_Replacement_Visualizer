#include "pagetable.h"

#include <iostream>

using namespace std;

/***************************************
 * Name: PageTable - constructor
 * Purpose: This function resizes the page table vector to be the size of the number of pages that was calculated by the main
 * Input: int size - this is the number of pages that is calculated by the main function
 * Output: N/A
 ***************************************/
PageTable::PageTable(int size)
{
    pt.resize(size);
}

/***************************************
 * Name: PageTable - addNewEntry
 * Purpose: This function will add a new entry to the page table by setting the valid bit to one and assigning the frame number to a specific page entry.
 * Input: 
 *  int pageNumber- this is the page number that corresponds with the memory reference. at this page Entry in the page table is where this new entry is added
 *  int frameNumber- this is the frame number that is going to be assigned to the page number entry in the page table
 * Output: N/A
 ***************************************/
void PageTable::addNewEntry(int pageNumber, int frameNum)
{
    pt[pageNumber].valid=true;
    pt[pageNumber].frame_num = frameNum;
}

/***************************************
 * Name: PageTable - getValidBit
 * Purpose: This function looks at the page table and returns the valid bit of a specific page number entry
 * Input: int pageNumber- this is the page entry in the page table.
 * Output: Returns the valid bit of the page entry as a bool value 
 ***************************************/
bool PageTable::getValidBit(int pageNumber)
{
    return pt[pageNumber].valid;
}

/***************************************
 * Name: PageTable - getFrameNum
 * Purpose: This function looks at the page table and returns the frame number of the page number passed to the function
 * Input: int pageNumber- this is a page entry in the page table.
 * Output: Returns the integer frame number corresponding to the page number in the page table.
 ***************************************/
int PageTable::getFrameNum(int pageNumber)
{
    return pt[pageNumber].frame_num;
}

/***************************************
 * Name: PageTable - replace
 * Purpose: this function will make a new page entry valid with a new frame number. this page is replacing another page entry that is currently valid with the passed frame number, so that one needs to be set to invalid because it is going to be replaced.
 * Input: 
 *  int pageNumber - this corresponds to a page entry in the page table
 *  int frameNumber - this is a frame that is going to be reassigned from pageBeingReplaced to pageNumber entries in the page table.
 *  int pageBeingReplaced - this is the page entry that will be replaced its frame number is also sent to this function and it will be reassigned
 * Output: N/A
 ***************************************/
void PageTable::replace(int pageNumber, int frameNumber,int pageBeingReplaced)
{
    //the pageNumber entry in the page table is set to the passed frame number and the valid bit is set to true
    pt[pageNumber].frame_num = frameNumber;
    pt[pageNumber].valid = true;
    //this is the page being replaced, to signify its replacement its valid bit is set to false
    pt[pageBeingReplaced].valid = false;
}



