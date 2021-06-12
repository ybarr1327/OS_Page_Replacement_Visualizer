#pragma once

#include<vector>

// Remember to add comments to your code

// A page table entry
class PageEntry
{
public:
	// Physical frame number for a given page
	int frame_num = 0;
	// valid bit represents whether a page is in the physical memory
	bool valid = false;
	// dirty bit represents whether a page is changed
	bool dirty = false;

	
};


/**
 * \brief A page table is like an array of page entries. The size of the page table should equal to the number of pages in logical memory
 */
class PageTable
{
	// TODO: Add your implementation of the page table here
private:
	std::vector<PageEntry> pt; //the page table is implemented as a vector of PageEntry objects
	
public:
	PageTable(int size);
	void addNewEntry(int pageNumber, int frameNum);
	bool getValidBit(int pageNumber);
	int getFrameNum(int pageNumber);
	void replace(int pageNumber,int frameNum, int pageBeingReplaced);
};
