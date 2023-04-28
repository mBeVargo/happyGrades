#include "Heap.h"
#include <iostream>

Heap::Heap(int size) {
    this->heapSize = size;
    int lastIndex = 1;
}


Professor* Heap::GetAllProfs() {
    return allProfs;
}

void Heap::SetHeapSize(int size) {
    heapSize = size;
}

int Heap::GetHeapSize() {
    return heapSize;
}

void Heap::Insert(Professor prof, int method) {
    allProfs[lastIndex] = prof;
    int parentInd = (lastIndex - 1) / 2;
    Professor parent = (allProfs)[parentInd];
    if(method == 0) { //0 for quality - this is a MAX heap
        while(true) {
            if(prof.GetAvgQuality() > parent.GetAvgQuality()) {
                allProfs[lastIndex] = parent;
                allProfs[parentInd] = prof;
            }
            else {
                break;
            }
        }
    }
    else if(method == 1) { //1 for Difficulty - this is a MIN heap
        /*allProfs[lastIndex] = *prof;
        int parentInd = (lastIndex - 1 - 1) / 2;
        Professor* parent = (*allProfs)[parentInd];*/
        while(true) {
            if(prof.GetAvgQuality() > parent.GetAvgQuality()) {
                allProfs[lastIndex] = parent;
                allProfs[parentInd] = prof;
            }
            else {
                break;
            }
        }
    }
    else if(method == 2) { //2 for Emotion - this is a MAX heap
        while(true) {
            if(prof.GetAvgQuality() > parent.GetAvgQuality()) {
                allProfs[lastIndex] = parent;
                allProfs[parentInd] = prof;
            }
            else {
                break;
            }
        }
    }
    lastIndex += 1;
}

Professor* Heap::FindByName(std::string name) {
    for(int i = 0; i < heapSize; i++) {
        if(allProfs[i].GetName() == name) {
            return &allProfs[i];
        }
    }
    std::cout << "Professor not found, please check your spelling or try a different name." << std::endl;
    return &allProfs[0];
}

Professor* Heap::FindByID(std::string id) {
    for(int i = 0; i < heapSize; i++) {
        if(allProfs[i].GetID() == id) {
            return &allProfs[i];
        }
    }
    std::cout << "Professor not found, please check your numbers or try a different ID." << std::endl;
    return &allProfs[0];
}