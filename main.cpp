// Remember to add comments to your code
#include <ctime>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include "pagetable.h"
#include <vector>
#include <chrono>
#include "LRUReplacement.h"



using namespace std;

/***************************************
 * Name: isPowerOfTwo
 * Purpose: Check if an integer is power of 2
 * Input: int x - integer value to check
 * Output: Returns true if it is a power of two, false if not
 ***************************************/
bool isPowerOfTwo(unsigned int x)
{
	/* First x in the below expression is for the case when x is 0 */
	return x && (!(x & (x - 1)));
}

int main(int argc, char* argv[]) {

	srand(time(NULL));//this seeds the random values

	//Print basic information about the program
	std::cout << "=================================================================" << std::endl;
	std::cout << "CS 433 Programming assignment 5" << std::endl;
	std::cout << "Author: Gabriel Ybarra and Ryan Lochrane" << std::endl;
	std::cout << "Date: 12/1/2020" << std::endl;
	std::cout << "Course: CS433 (Operating Systems)" << std::endl;
	std::cout << "Description : Program to simulate different page replacement algorithms" << std::endl;
	std::cout << "=================================================================\n" << std::endl;

	if (argc < 3) {
		// user does not enter enough parameters
		std::cout << "You have entered too few parameters to run the program.  You must enter" << std::endl
			<< "two command-line arguments:" << std::endl
			<< " - page size (in bytes): between 256 and 8192, inclusive" << std::endl
			<< " - physical memory size (in megabytes): between 4 and 64, inclusive" << std::endl;
		exit(1);
	}
	
	// Page size and Physical memory size 
	// Their values should be read from command-line arguments, and always a power of 2
	unsigned int page_size = atoi(argv[1]);
	if(!isPowerOfTwo(page_size))
	{
		std::cout << "You have entered an invalid parameter for page size (bytes)" << std::endl
			<< "  (must be an power of 2 between 256 and 8192, inclusive)." << std::endl;
		return 1;
	}
	unsigned int phys_mem_size = atoi(argv[2]) << 20; // convert from MB to bytes
	if(!isPowerOfTwo(phys_mem_size))
	{
		std::cout << "You have entered an invalid parameter for physical memory size (MB)" << std::endl
			<< "  (must be an even integer between 4 and 64, inclusive)." << std::endl;
		return 1;
	}

	// calculate number of pages and frames;
	int logic_mem_bits = 27;		// 27-bit logical memory (128 MB logical memory assumed by the assignment)
	int phys_mem_bits = std::log2(phys_mem_size);		// Num of bits for physical memory addresses, calculated from physical memory size, e.g. 24 bits for 16 MB memory
	int page_offset_bits = std::log2(page_size);				// Num of bits for page offset, calculated from page size, e.g. 12 bits for 4096 byte page
	// Number of pages in logical memory = 2^(logic_mem_bits - page_bit)
	int num_pages = 1 << (logic_mem_bits - page_offset_bits);
	// Number of free frames in physical memory = 2^(phys_mem_bits - page_offset_bits)
	int num_frames = 1 << (phys_mem_bits - page_offset_bits);
	
	std::cout << "Page size = " << page_size << " bytes" << std::endl;
	std::cout << "Physical Memory size = " << phys_mem_size << " bytes" << std::endl;
	std::cout << "Number of pages = " << num_pages << std::endl; 
	std::cout << "Number of physical frames = " << num_frames << std::endl;

	int numberOfReferences; //this keeps track of the number of references that the program processes
	int numberOfPageFaults; //this keeps track of the number of page faults that happen in the program
	int numberOfReplacements; //this keeps track of the number of replacements that happen in the program

	// Test 1: Read and simulate the small list of logical addresses from the input file "small_refs.txt"
	//IMPORTANT NOTE:
	//Test 1 assumes there are no page replacements and that the frames are assigned numerically. The program is designed to accomodate these.
	std::cout <<"\n================================Test 1==================================================\n";
	// TODO: Add your code here for test 1 that prints out logical page #, frame # and whether page fault for each logical address
	
	int logicalMemReferenceT1; //this stores the memory references from the file
	int pageNumberT1; //this is the page number that correlates to the memory reference 
	int frameNumAssignT1=0; //this keeps track of the frame numbers that are going to be assigned
	bool pageFaultT1; //this is a flag that is set to true if there is a page fault
	
	//initializes the statistics for test 1.
	numberOfReferences=0;
	numberOfPageFaults=0;
	numberOfReplacements=0;

	PageTable ptTest1(num_pages); //creates the page table of size num_pages

	// open the input file
    std::ifstream infileT1("small_refs.txt");
    if(!infileT1)//if the input could not be opened, then close program
    {
      cerr<<"Input file could not be opened"<<endl;
      exit(1);
    }
    while(infileT1>>logicalMemReferenceT1)  //read from the file into logicalMemReferenceT1
    {
		numberOfReferences+=1;

		//calculate page number
		pageNumberT1 = logicalMemReferenceT1/page_size;
		
		//get the valid bit of this page number and set the flag to signify if there was a page fault.
		if(ptTest1.getValidBit(pageNumberT1))//if valid bit is 1 then there is no page fault
			pageFaultT1=0;
		else //if valid bit is zero there is a page fault
			pageFaultT1=1;
		
		if(pageFaultT1)//if there was a page fault then add the page entry to the table
		{
			numberOfPageFaults+=1;
			//the page is set to valid in the table with the frameNumAssignT1 value. this value is assigned numerically and every time one is assigned the counter is increased for the next one
			ptTest1.addNewEntry(pageNumberT1,frameNumAssignT1);
			frameNumAssignT1+=1;			
		}

		//print out the statistics of the memory reference
		std::cout<<"Logical Address: "<<logicalMemReferenceT1<<", \t";
		std::cout<<"Page Number: "<<pageNumberT1<<", \t";
		std::cout<<"Frame Number = "<<ptTest1.getFrameNum(pageNumberT1)<<", \t";
		std::cout<<"Is Page Fault? ";
		std::cout<<pageFaultT1;
		std::cout<<endl;		
	}

	//print the overall stats of all the references.
	std::cout << "Number of references:   \t"<<numberOfReferences<<endl;
	std::cout << "Number of page faults:  \t"<<numberOfPageFaults<<endl;
	std::cout << "Number of replacements: \t"<<numberOfReplacements<<endl;

	infileT1.close();

	// Test 2: Read and simulate the large list of logical addresses from the input file "large_refs.txt"
	std::cout <<"\n================================Test 2==================================================\n";

	//start, end, time elapsed keep track of the timing for each of the replacement algorithms
	//the chrono library tools are used to keep track of the time
	chrono::time_point<chrono::system_clock> start,end;
	chrono::duration<double> timeElapsed;

	int logicalMemReferenceT2;//this stores the logical memory reference from the file
	int pageNumberT2; //this stores the page number corresponding to the mem reference
	bool pageFaultT2; //this is a flag to signify if there is a page fault
	int frameNumAssignT2; //this stores the frame number that is assigned for the first pages before replacement happens
	int victimFrame; //this stores the victim frame number that is going to taken from the page being replaced and assigned to the new page
	int locationOfFrameBeingReplaced; //this stores the page that is being replaced
	vector<int> memoryReferencesT2; //this stores the references from the file into this vector so that the file does not have to be read from multiple times
	
	
	//this section reads references from the file and stores them into the memoryReferencesT2 vector
	std::ifstream infileT2("large_refs.txt");
    if(!infileT2)//if the input could not be opened, then close program
    {
      cerr<<"Input file could not be opened"<<endl;
      exit(1);
    }
    while(infileT2>>logicalMemReferenceT2)  
    {
		memoryReferencesT2.push_back(logicalMemReferenceT2);
	}

	infileT2.close();

	std::cout<<"Total Number of references: "<<memoryReferencesT2.size()<<endl;
	std::cout << "****************Simulate FIFO replacement****************************" << std::endl;
	// TODO: Add your code to calculate number of page faults using FIFO replacement algorithm	
	// TODO: print the statistics and run-time
	
	start = chrono::system_clock::now();//first store the current starting time of the FIFO replacement

	victimFrame=0;//initialize the victime frame, this value will be replaced later by the logic of the FIFO replacement

	PageTable ptFIFO(num_pages); //creates a page table for the FIFO replacement of size num_pages
	vector<int> frameListFIFO(num_frames);//this is a map that stores where each frame is located in the page table, this is needed for fast translation to know where in the page table to replace the page that is holding the frame
	

	//initialize frame assign to zero to start off because frames are assigned numerically
	frameNumAssignT2=0;
	//initialize stats
	numberOfPageFaults=0;
	numberOfReplacements=0;
	
	//for each memory reference
	for(int i = 0; i< memoryReferencesT2.size();i++)
	{
		//calculate the page number
		pageNumberT2 = memoryReferencesT2[i]/page_size;

		//determine if there was a page fault, determined by the valid bit 
		if(ptFIFO.getValidBit(pageNumberT2))//if valid bit is 1 then there is no page fault
			pageFaultT2=0;
		else //if valid bit is zero there is a page fault
			pageFaultT2=1;
		
		if(pageFaultT2)//if there was a page fault...
		{
			numberOfPageFaults+=1;
			if(frameNumAssignT2<num_frames)//... if there are still free frames to assign
			{
				//this updates the map of the frame to store where in the page table it is assigned to
				frameListFIFO[frameNumAssignT2] = pageNumberT2;
				//assigns the frame to the page entry
				ptFIFO.addNewEntry(pageNumberT2,frameNumAssignT2);
				frameNumAssignT2+=1;//update the frame number to be assigned for the next one
			}
			else //... if all frames are currently assigned, there needs to be a replacement
			{
				numberOfReplacements+=1;

				//first we store the location in the page table where the victime frame is assigned to
				locationOfFrameBeingReplaced = frameListFIFO[victimFrame]; 
				//then we store the location of this frame to the new page
				frameListFIFO[victimFrame] = pageNumberT2;
				
				//repace the frame from the old page (locationOfFrameBeingReplaced) to the new page (pageNumberT2)
				ptFIFO.replace (pageNumberT2 , victimFrame,locationOfFrameBeingReplaced);
				
				//because we assign frames initially numerically, we can also keep track of the victim frames numerically by keeping a count variable that adds numerically with circular addition
				victimFrame = (victimFrame+1)%num_frames;
			}
			
		}

	}

	//print out the statistics
	std::cout << "Number of references:   \t"<<memoryReferencesT2.size()<<endl;
	std::cout << "Number of page faults:  \t"<<numberOfPageFaults<<endl;
	std::cout << "Number of replacements: \t"<<numberOfReplacements<<endl;

	end = chrono::system_clock::now();//store the finish time of the replacement
	timeElapsed = end-start;//get the total time elapsed by getting the difference of end and start
	//print out how long the replacement algorithm took
	std::cout<<"Elapsed Time: "<<timeElapsed.count()<<" seconds"<<endl;

	std::cout << "****************Simulate Random replacement****************************" << std::endl;
	// TODO: Add your code to calculate number of page faults using Random replacement algorithm
	// TODO: print the statistics and run-time

	start = chrono::system_clock::now(); //record the starting time of the random replacement algorithm

	victimFrame=0; //initializes the victim frame 

	PageTable ptRand(num_pages); //initializes the page table for random replacement of size num_pages
	vector<int> frameListRand(num_frames);//map that stores where the frames are assigned in the page table

	//initialize frame number assginment to zero because we initally assign frames numerically
	frameNumAssignT2=0;
	//initialize stats
	numberOfPageFaults=0;
	numberOfReplacements=0;
	
	//for all the memory references...
	for(int i = 0; i< memoryReferencesT2.size();i++)
	{
		pageNumberT2 = memoryReferencesT2[i]/page_size;//calculate the page number

		//determine if there was a page fault 
		if(ptRand.getValidBit(pageNumberT2))//if valid bit is 1 then there is no page fault
			pageFaultT2=0;
		else //if valid bit is zero there is a page fault
			pageFaultT2=1;
		
		if(pageFaultT2)//if there is a page fault
		{
			numberOfPageFaults+=1;
			if(frameNumAssignT2<num_frames)//if there are still free frames to assign
			{
				//first store where the frame is assigned in the page table
				frameListRand[frameNumAssignT2] = pageNumberT2;
				//assign the frame number to the page number
				ptRand.addNewEntry(pageNumberT2,frameNumAssignT2);
				frameNumAssignT2+=1;//frames are assigned numerically at first so a count variable is used and incremented after it is assigned
			}
			else
			{
				victimFrame=rand()%num_frames;//get a victim frame randomly
				
				numberOfReplacements+=1;
				//store where the victim frame is in the page table
				locationOfFrameBeingReplaced = frameListRand[victimFrame]; 
				//store where the frame will now be stored in the new page 
				frameListRand[victimFrame] = pageNumberT2;
				//replace the frame number from the old page to the new page
				ptRand.replace (pageNumberT2 , victimFrame,locationOfFrameBeingReplaced);
				
			}
			
		}

	}

	//print out the stats
	std::cout << "Number of references:   \t"<<memoryReferencesT2.size()<<endl;
	std::cout << "Number of page faults:  \t"<<numberOfPageFaults<<endl;
	std::cout << "Number of replacements: \t"<<numberOfReplacements<<endl;

	end = chrono::system_clock::now();//get the end time
	timeElapsed = end-start;//calculate the duration and print out the time.
	std::cout<<"Elapsed Time: "<<timeElapsed.count()<<" seconds"<<endl;


	std::cout << "****************Simulate LRU replacement****************************" << std::endl;
	// TODO: Add your code to calculate number of page faults using LRU replacement algorithm
	// TODO: print the statistics and run-time

	//IMPORTANT: 
	//	this implemtation of LRU uses the counter implementation which has a slow runtime speed because of the linear search needed
	//	the program does compile and work correctly, just the time it takes to complete can be relatively long compared to the other two replacement algorithms. In our testing with 
	//	a page size of 8192 and physical mem size of 64, the LRU finishes in less than 15 seconds however if there is alot of page replacements, then the runtime takes much longer

	start = chrono::system_clock::now(); //store the start time of the replacement

	victimFrame=0;//initialize the victim frame corresponding to the frame of the victim page
	frameNumAssignT2=0; // stores the intial frame to be assigned
	int victimPage; // store the page number of the victim

	//initializes the stats
	numberOfPageFaults=0;
	numberOfReplacements=0;
	
	PageTable ptLRU(num_pages);//create a page table for LRU
	LRUReplacement replacement(num_pages);

	int testCount = 0;

	//for each memory reference ...
	for(int i = 0; i< memoryReferencesT2.size();i++)
	{
		//calculate the page number
		pageNumberT2 = memoryReferencesT2[i]/page_size; 
		
		replacement.newReference(pageNumberT2);

		//determine if there was a page fault 
		if(ptLRU.getValidBit(pageNumberT2))//if valid bit is 1 then there is no page fault
			pageFaultT2=0;
		else //if valid bit is zero there is a page fault
			pageFaultT2=1;

		if(pageFaultT2) //if there was a page fault
		{
			numberOfPageFaults+=1;

			if(frameNumAssignT2<num_frames) //if there is still free frames assign a free frame numerically
			{	
				ptLRU.addNewEntry(pageNumberT2,frameNumAssignT2);
				frameNumAssignT2+=1;		
			}
			else //if there needs to be a replacement
			{	
				numberOfReplacements+=1;
				victimPage = replacement.getVictimPage();
				victimFrame = ptLRU.getFrameNum(victimPage);

				// //this assigns the victim frame from the old page pos to the new page pageNumberT2.
				ptLRU.replace(pageNumberT2,victimFrame,victimPage);


			}
		}
		
		

	}

	// cout<<testCount<<endl;

	//print stats for memory
	std::cout << "Number of references:   \t"<<memoryReferencesT2.size()<<endl;
	std::cout << "Number of page faults:  \t"<<numberOfPageFaults<<endl;
	std::cout << "Number of replacements: \t"<<numberOfReplacements<<endl;

	//calculate and print the timing stat
	end = chrono::system_clock::now();
	timeElapsed = end-start;
	std::cout<<"Elapsed Time: "<<timeElapsed.count()<<" seconds"<<endl;
}

