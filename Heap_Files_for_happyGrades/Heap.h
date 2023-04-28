#pragma once

#include <vector>
#include "Professor.h"



class Heap {
private:
    int heapSize;
    Professor* allProfs = new Professor[365];
    int lastIndex;
public:
    Professor* GetAllProfs();
    void SetHeapSize(int size);
    int GetHeapSize();
    void Insert(Professor prof, int method);
    Professor* FindByName(std::string name);
    Professor* FindByID(std::string id);

    Heap(int size);
    Heap();
};

