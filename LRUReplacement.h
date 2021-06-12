#pragma once

#include<vector>
#include "DLL.h"
#include <unordered_map>

class LRUReplacement: public DLL
{
private:
	DLL LRU; //This stores the doubly linked list that stores pages when they are referenced
	vector<Node*> map; // this is a vector that maps the page to a spot in the LRU DLL.
public:
	LRUReplacement(int numPages);
	void newReference(int pageNum);
	
	int getVictimPage();
    void moveNodeToBack(Node*&);
};