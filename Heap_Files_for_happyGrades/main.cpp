#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Professor.h"
#include "Review.h"
#include "Heap.h"


int main() {
    //Heap* heap = new Heap();
    //Professor* dummy = new Professor;
    //heap->Insert(dummy, 0);
    //std::cout << "Dummy has been inserted, Name: " << dummy->GetName() << " ID: " << dummy->GetID() << std::endl;

    //Heap* heap = new Heap(365);

    std::cout << "First few reviews: " << std::endl;
    //std::string file = "RMP_Reviews_Different_Delimiter_SHORT.txt";
    std::string file = "RMP_Reviews_Different_Delimiter.txt";
    std::ifstream fileStream;
    fileStream.open(file);

    if(!(fileStream.is_open())) {
        std::cout << "File not open. Check stream/file name & location" << std::endl;
    }

    //unsigned long lineCount = 0;   TODO: re-implement with  && lineCount < 365 later
    std::string tempID = "";
    std::string tempName;
    std::string tempUni;
    std::string tempDept;
    double tempQual;
    int tempDiff;
    std::string tempEmo;
    std::string tempCourse;
    std::string tempComment;
    //std::vector<Review> thisProfRevs;
    std::string prevID = "";
    std::string prevName = "";
    std::string prevUni = "";
    double sumQual = 0.0;
    double sumDiff = 0;
    double sumEmo = 0;
    int revCount = 0;
    std::vector<Professor*> temps;

    std::string input;
    getline(fileStream, input);
    while(getline(fileStream, input)) {
        revCount += 1;

        std::stringstream data(input);
        std::string token;

        getline(data, token, '|');
        getline(data, token, '|');
        tempID = token;
        getline(data, token, '|');
        tempName = token;
        getline(data, token, '|');
        tempUni = token;
        getline(data, token, '|');
        //tempDept = token;
        getline(data, token, '|');
        tempQual = stod(token);
        getline(data, token, '|');
        tempDiff = stod(token);
        getline(data, token, '|');
        tempEmo = token;
        getline(data, token, '|');
        tempCourse = token;
        getline(data, token, '|');
        tempComment = token;


        Review* temp = new Review(tempID, tempName, tempUni, tempQual, tempDiff, tempEmo, tempCourse, tempComment);

        if(tempID == prevID || revCount == 1) {
            sumQual += tempQual;
            sumDiff += tempDiff;
            if(tempEmo.substr(1, tempEmo.size()-2) == "AWESOME") {
                sumEmo += 3;
            }
            else if(tempEmo.substr(1, tempEmo.size()-2) == "AVERAGE") {
                sumEmo += 2;
            }
            else if(tempEmo.substr(1, tempEmo.size()-2) == "AWFUL") {
                sumEmo += 1;
            }
            delete temp;
        }
        if(prevID != tempID && revCount >= 1 && prevID != "") {
            Professor* tempProf = new Professor(prevID, prevName, prevUni, (sumQual/((double)revCount)), (sumDiff/((double)revCount)), (sumEmo/((double)revCount)));
            std::cout << "Next Professor: " << prevID << " " << prevName << " Avg. Quality/Difficulty/Emotion: " << (sumQual/((double)revCount)) << "/" << (sumDiff/((double)revCount)) << "/" << (sumEmo/((double)revCount)) << std::endl;
            std::cout << "Review count: " << revCount << std::endl;
            //heap->Insert((*tempProf), 0);

            /*std::cout << "Current heap (MAX): ";
            for(int i = 0; i < heap->GetHeapSize(); i++) {
                std::cout << heap->GetAllProfs()[i].GetName() << " " << heap->GetAllProfs()[i].GetAvgQuality() << std::endl;
            }*/

            revCount = 0;
            sumQual = 0.0;
            sumDiff = 0.0;
            sumEmo = 0.0;
            delete tempProf;
        }
        prevID = tempID;
        prevName = tempName;
        prevUni = tempUni;

    }
    Professor* tempProf = new Professor(prevID, prevName, prevUni, (sumQual/((double)revCount)), (sumDiff/((double)revCount)), (sumEmo/((double)revCount)));
    std::cout << "Next Professor: " << prevID << " " << prevName << " Avg. Quality/Difficulty/Emotion: " << (sumQual/((double)revCount)) << "/" << (sumDiff/((double)revCount)) << "/" << (sumEmo/((double)revCount)) << std::endl;
    std::cout << "Review count: " << revCount << std::endl;
    temps.push_back(tempProf);
    //heap->Insert(*tempProf, 0);
    delete tempProf;


    return 0;
}
