#pragma once

#include<vector>
#include "DLL.h"
#include <unordered_map>

class LRUReplacement: public DLL
{
private:
	DLL LRU;
	vector<Node*> map;
	unordered_map<int, bool> exists;

public:
	LRUReplacement(int numPages);
	void newReference(int pageNum);
	
	int getVictimPage();
    void moveNodeToBack(Node*&);

	
};