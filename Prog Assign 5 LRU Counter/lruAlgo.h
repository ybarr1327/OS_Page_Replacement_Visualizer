#pragma once

using namespace std;
#include<vector>
#include<iostream>

struct MappingTool
{
    bool existsInLruAlgo = 0;
    int posInlruAlgo;
};

class lruAlgo
{
private:
    vector<int> LRU;
    vector<MappingTool> mapToLRU;
public:
    lruAlgo(int numPages);
    void updateCount(int pageNumber);
    void printContents();
    int getVictim()
  
};
