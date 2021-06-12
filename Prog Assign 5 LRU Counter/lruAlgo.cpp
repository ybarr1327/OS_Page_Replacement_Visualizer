#include "lruAlgo.h"


lruAlgo::lruAlgo(int numPages)
{
	LRU.resize(numPages);
	for (int i : LRU)
	{
		i = 0;
	}
}

void lruAlgo::updateCount(int pageNumber)
{
	LRU[pageNumber] += 1;
}

void lruAlgo::printContents()
{
	cout << "-------------------------------" << endl;
	cout << "Reference Counts" << endl;
	cout << "Page #"<<"\t";
	cout << "Count"<<"\t" << endl;
	for (int i=0;i<LRU.size() ;i++ )
	{
		cout << i << "\t" << LRU[i] << endl;
	}
}


