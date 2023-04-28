#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;




// create class for the graph





int main() {

    //make vector to store names and what int values the maps have with them

    int lineCount;
    //vector<pair<string, vector<int>>> SchoolKeys;
    vector<string> SchoolKeysLong;
    //vector<pair<string, vector<int>>> ProfessorKeys;
    vector<string> ProfessorKeysLong;

    vector<string> CourseName;

    map<int, vector<string>> Reviews;


    //"10897"   ---- string
    string ID;
//
//"Ronald Randles" ------string
    string Name;
//
//"University of Florida" -----string
    string University;
//
//"Statistics department"    ------- string
    string Department;
//
//4.5 ----float
    string Quality;
//
//1   ---- int
    string Difficulty;
//
//"AWESOME"    ----string
    string Emotion;
//
//"STA4381"    -----string
    string Course;
//
//"Best stat teacher on campus by far. Classes aren't difficult at all if you put any amount of effort in and Randles is one of the nicest professors you'll ever have."   --string
    string Comment;
//
//0
    string ThumbsUp;
//
// 2
    string ThumbsDown;
//
//"Dec 14th 2011"   ------string
    string Date;



    string file = "RMP_Reviews_Different_Delimiter.txt";
    ifstream fileStream;
    fileStream.open(file);

    if(!(fileStream.is_open())) {
        cout << "File not open or not found." << endl;

    }

    int storageNumber = 0;

    string input;
    getline(fileStream, input);
    while(getline(fileStream, input) && lineCount < 10000) {
        stringstream  inputSliced(input);
        string toSave;

        getline(inputSliced, toSave, '|');
        getline(inputSliced, toSave, '|');
        ID = toSave.substr(1, (toSave.size()-2));
        getline(inputSliced, toSave, '|');
        Name = toSave.substr(1, (toSave.size()-2));;
        getline(inputSliced, toSave, '|');
        University = toSave.substr(1, (toSave.size()-2));;
        getline(inputSliced, toSave, '|');
        Department = toSave.substr(1, (toSave.size()-2));;
        getline(inputSliced, toSave, '|');
        Quality = toSave;
        getline(inputSliced, toSave, '|');
        Difficulty = toSave;
        getline(inputSliced, toSave, '|');
        Emotion = toSave.substr(1, (toSave.size()-2));;
        getline(inputSliced, toSave, '|');
        Course = toSave.substr(1, (toSave.size()-2));;
        getline(inputSliced, toSave, '|');
        Comment = toSave.substr(1, (toSave.size()-2));;
        getline(inputSliced, toSave, '|');
        ThumbsUp = toSave;
        getline(inputSliced, toSave, '|');
        ThumbsDown = toSave;
        getline(inputSliced, toSave, '|');
        Date = toSave.substr(1, (toSave.size()-2));;





//ID Number
//Name
//University
//Department
//Quality
//Difficulty
//Emotion
//Class_Name
//Comment
//Thumbs_Up
//Thumbs_Down
//Review_Date



/*

int NumInputs;
cin>>NumInputs;
cin.ignore();

    string input;



//get number of inputs from user
int Commands = NumInputs;


cout << "Insert Data" << endl;
for (int j = 0; j < NumInputs; j++) {
//while (Commands!= 0) {


//"10897"   ---- string
    string ID;
//
//"Ronald Randles" ------string
    string Name;
//
//"University of Florida" -----string
    string University;
//
//"Statistics department"    ------- string
    string Department;
//
//4.5 ----float
    string Quality;
//
//1   ---- int
    string Difficulty;
//
//"AWESOME"    ----string
    string Emotion;
//
//"STA4381"    -----string
    string Course;
//
//"Best stat teacher on campus by far. Classes aren't difficult at all if you put any amount of effort in and Randles is one of the nicest professors you'll ever have."   --string
    string Comment;
//
//0
    string ThumbsUp;
//
// 2
    string ThumbsDown;
//
//"Dec 14th 2011"   ------string
    string Date;



//from first " to next ", is the id
//from " to " is the name
//from " to " is the university
//from " to " is the department
//after ", next is the float score
//after space, is the difficulty
//from " to " is the emotion
//from " to " is the class
//from " to " is the comment
//after " and space, is the thumbs down
//after space is the thumbs up
//from " to " is the date posted



    string intake;

    int tracker = 0;
    bool IDin, NameIn, UniIn, DepIn = false;
    bool NumInput = false;
    bool QualIn, DiffIn = false;
    bool EmoIn, CourseIn, CommentIn = false;
    bool upThumbIn, downThumbIn = false;
    bool DateIn = false;

    getline(cin, input);
    //cin>>ID;
    //cin>>Name;
   // cin>>University;



    //cout << input.size();
    for (int i = 0; i < input.size(); i++) {

        intake += input[i];
        //cout << intake << endl;
        if (input[i] == '"') {
//do all checks to see whats next

            if (tracker == 2) {
                IDin = true;
            } else if (tracker == 3) {
                IDin = false;
            } else if (tracker == 4) {
                NameIn = true;
            } else if (tracker == 5) {
                NameIn = false;
            } else if (tracker == 6) {
                UniIn = true;
            } else if (tracker == 7) {
                UniIn = false;
            } else if (tracker == 8) {
                DepIn = true;
            } else if (tracker == 9) {
                DepIn = false;
                NumInput = true;
            } else if (tracker == 13) {

                EmoIn = true;

            } else if (tracker == 14) {

                EmoIn = false;

            } else if (tracker == 15) {

                CourseIn = true;

            } else if (tracker == 16) {

                CourseIn = false;

            } else if (tracker == 17) {

                CommentIn = true;

            } else if (tracker == 18) {

                CommentIn = false;
                NumInput = true;
            } else if (tracker == 22) {

                DateIn = true;

            }

            tracker++;
            continue;
        }
        if (input[i] == ' ' && NumInput == true) {

            if (tracker == 10) {
                QualIn = true;
            } else if (tracker == 11) {
                QualIn = false;
                DiffIn = true;
            } else if (tracker == 12) {

                DiffIn = false;
                NumInput = false;

            } else if (tracker == 19) {

                upThumbIn = true;

            } else if (tracker == 20) {

                upThumbIn = false;
                downThumbIn = true;

            } else if (tracker == 21) {

                downThumbIn = false;
                NumInput = false;

            }
            tracker++;
            continue;
        }

//after " of department, set a true to get the score after a space until another space

        if (IDin == true) {

            ID += input[i];

        } else if (NameIn == true) {

            Name += input[i];

        } else if (UniIn == true) {

            University += input[i];

        } else if (DepIn == true) {

            Department += input[i];

        } else if (QualIn == true) {

            Quality += input[i];

        } else if (DiffIn == true) {

            Difficulty += input[i];

        } else if (EmoIn == true) {

            Emotion += input[i];

        } else if (CourseIn == true) {

            Course += input[i];

        } else if (CommentIn == true) {

            Comment += input[i];

        } else if (upThumbIn == true) {

            ThumbsUp += input[i];

        } else if (downThumbIn == true) {

            ThumbsDown += input[i];

        } else if (DateIn == true) {

            Date += input[i];

        }

    }
    */

    //store all information gained

    //Store specifically school/professor to be searched, the rest will be pulled up when found
    /*
    int found = 0;

    for (int k = 0; k < SchoolKeys.size(); k++) {

        if (SchoolKeys.at(k).first == University) {

            SchoolKeys.at(k).second.push_back(j);
            found = 1;
        }

    }

    if (found == 0) {
        //create new vector location
        vector<int> temp;
        temp.push_back(j);
        SchoolKeys.push_back(make_pair(University, temp));

    }

    found = 0;
    */

    SchoolKeysLong.push_back(University);
    ProfessorKeysLong.push_back(Name);
    CourseName.push_back(Course);
    /*
    for (int l = 0; l < ProfessorKeys.size(); l++) {

        if (ProfessorKeys.at(l).first == Name) {

            ProfessorKeys.at(l).second.push_back(j);
            found = 1;

        }
    }


    if (found == 0) {
        //create new vector location
        vector<int> temp2;
        temp2.push_back(j);
        ProfessorKeys.push_back(make_pair(Name, temp2));

    }
*/

    vector<string> temp(12);
    temp.at(0) = ID;
    temp.at(1) = Name;
    temp.at(2) = University;
    temp.at(3) = Department;
    temp.at(4) = Quality;
    temp.at(5) = Difficulty;
    temp.at(6) = Emotion;
    temp.at(7) = Course;
    temp.at(8) = Comment;
    temp.at(9) = ThumbsUp;
    temp.at(10) = ThumbsDown;
    temp.at(11) = Date;

    /*
    cout << endl;
    cout <<ID << endl;
    cout << Name<< endl;
    cout << University<< endl;
    cout << Department <<endl;
    cout << Quality << endl;
    cout << Difficulty << endl;
    cout << Emotion << endl;
    cout << Course << endl;
    cout << Comment << endl;
    cout << ThumbsUp << endl;
    cout << ThumbsDown << endl;
    cout << Date << endl;
*/

    Reviews[storageNumber] = temp;
    //cout << ProfessorKeys.size() << endl;
    //cout << temp.size() << endl;
    //push_back(temp);
    storageNumber++;
    lineCount++;
}

//cout << ProfessorKeys.at(0).first << endl;
//cout << ProfessorKeysLong.at(0) << endl;

cout << "Type in 'Professor', 'University', 'Both', 'Course', or 'UniversityandCourse' after which, type in the full name of what you are searching" << endl;
string searchType;
cin>>searchType;
cin.ignore();

string searching;
//cin>>searching;
    string searchProfessor;
    string UniversitySearch;
    string courseSearch;

    if (searchType == "Course") {
        cout << "Type in the Course Name" << endl;
        getline(cin, courseSearch);


    }

    else if (searchType == "UniversityandCourse") {
        cout << "Type in the University" << endl;
        getline(cin, UniversitySearch);

        cout << "Type in the Course Name" << endl;
        getline(cin, courseSearch);

    }


    else if (searchType == "Both") {
    cout << "Type in the University" << endl;
    getline(cin, UniversitySearch);
    //cin.ignore();

    cout << "Type in the Professor" << endl;
    getline(cin, searchProfessor);


    }

    else if( searchType == "University"){
        cout << "Type in the University" << endl;
        getline(cin, searching);

    }

    else if( searchType == "Professor"){
        cout << "Type in the Professor" << endl;
        getline(cin, searching);

    }

int checkSchool = 0;
int checkProfessor = 0;
int checkCourse = 0;
bool searchFound = true;

vector<int> keyFound;

vector<int> doubleKeys;


if (searchType == "Course") {

    for (int i = 0; i < CourseName.size(); i++) {
        if (CourseName.at(i) == courseSearch) {
            keyFound.push_back(i);
            checkCourse = 1;

        }


    }


    if (checkCourse == 0) {


        cout << "Could not find search." << endl;
    }


}


    if (searchType == "UniversityandCourse") {

        for (int i = 0; i < SchoolKeysLong.size(); i++) {
            if (SchoolKeysLong.at(i) == UniversitySearch) {

                keyFound.push_back(i);
                checkSchool = 1;
            }
        }

        for (int i = 0; i < keyFound.size(); i++) {
            if (CourseName.at(keyFound.at(i)) == courseSearch) {

                doubleKeys.push_back(keyFound.at(i));
                checkCourse = 1;
            }
        }

        if (checkSchool == 0 || checkCourse == 0) {

            cout << "Could not find search." << endl;
            searchFound = false;

        }

    }

        if (searchType == "Both") {

    for (int i = 0; i < SchoolKeysLong.size(); i++) {
        if (SchoolKeysLong.at(i) == UniversitySearch) {

            keyFound.push_back(i);
            checkSchool = 1;
        }
    }

    for (int i = 0; i < keyFound.size(); i++) {
        if (ProfessorKeysLong.at(keyFound.at(i)) == searchProfessor) {

            doubleKeys.push_back(keyFound.at(i));
            checkProfessor = 1;
        }
    }

    if (checkSchool == 0 || checkProfessor == 0 ) {

        cout << "Could not find search." << endl;
        searchFound = false;

    }

}







//map <int, vector<string>> Found;
    //cout<< "test2" << endl;

if (searchType == "Professor") {
searchProfessor = searching;
//cout << searchProfessor << endl;

    /*
    for (int i = 0; i < ProfessorKeys.size(); i++) {
        cout<< "test1" << endl;
        if (ProfessorKeys.at(i).first == searchProfessor) {
            cout<< "test" << endl;
            //iterate through all the vector ints stored, calling each in the map to get the data.
            keyFound.push_back(i);


        }
    }
    */

    for (int i = 0; i < ProfessorKeysLong.size(); i++) {
        if (ProfessorKeysLong.at(i) == searchProfessor) {

            keyFound.push_back(i);
            checkProfessor = 1;
        }
    }

    if (checkProfessor == 0) {

        cout << "Could not find search." << endl;
        searchFound = false;

    }

}




if (searchType == "University") {
UniversitySearch = searching;

    for (int i = 0; i < SchoolKeysLong.size(); i++) {
        if (SchoolKeysLong.at(i) == UniversitySearch) {

            keyFound.push_back(i);

        }


    }

    if (checkSchool == 0) {

        cout << "Could not find search." << endl;
        searchFound = false;

    }
    /*
    for (int i = 0; i < SchoolKeys.size(); i++) {
        if (SchoolKeys.at(i).first == UniversitySearch) {

            //iterate through all the vector ints stored, calling each in the map to get the data.
            keyFound.push_back(i);

        }
    }
    */
}

float AverageQuality = 0;

vector<pair<float, vector<string>>> sortedOutput;

if (searchFound == true) {

    if (searchType == "Both") {

        for (int i = 0; i < doubleKeys.size(); i++) {
            float tempQuality = 0;
            tempQuality = stof(Reviews[doubleKeys.at(i)].at(4));
            vector<string> temporaryStringsTransfer;
            for (auto item: Reviews[doubleKeys.at(i)]) {

                temporaryStringsTransfer.push_back(item);

            }

            AverageQuality += tempQuality;
            sortedOutput.push_back(make_pair(tempQuality, temporaryStringsTransfer));

        }

    }

    else if (searchType == "UniversityandCourse") {

        for (int i = 0; i < doubleKeys.size(); i++) {
            float tempQuality = 0;
            tempQuality = stof(Reviews[doubleKeys.at(i)].at(4));
            vector<string> temporaryStringsTransfer;
            for (auto item: Reviews[doubleKeys.at(i)]) {

                temporaryStringsTransfer.push_back(item);

            }

            AverageQuality += tempQuality;
            sortedOutput.push_back(make_pair(tempQuality, temporaryStringsTransfer));

        }

    }

    else {
        for (int i = 0; i < keyFound.size(); i++) {
            float tempQuality = 0;
            tempQuality = stof(Reviews[keyFound.at(i)].at(4));
            //cout << tempQuality << endl;
            vector<string> temporaryStringsTransfer;
            for (auto item: Reviews[keyFound.at(i)]) {

                temporaryStringsTransfer.push_back(item);

            }
            AverageQuality += tempQuality;
            sortedOutput.push_back(make_pair(tempQuality, temporaryStringsTransfer));


        }

    }
    sort(sortedOutput.begin(), sortedOutput.end());

    float QualityRating = AverageQuality/float(sortedOutput.size());

    cout << endl;
    cout << "Sorted by Quality" << endl;

    if (searchType == "Course") {

        cout << endl;
        //cout << "University: " << UniversitySearch << endl;
        cout << "Course: " << courseSearch << endl;

        for (int r = (sortedOutput.size() - 1); r >= 0; r--) {
            //cout << sortedOutput.at(r).first << endl;
            cout << endl;
            cout << "Professor ID: " << sortedOutput[r].second[0] << endl;
            cout << "Professor Name: " << sortedOutput[r].second[1] << endl;
            cout << "University: " << sortedOutput[r].second[2] << endl;
            cout << "Department: " << sortedOutput[r].second[3] << endl;
            cout << "Quality: " << sortedOutput[r].second[4] << endl;
            cout << "Difficulty: " << sortedOutput[r].second[5] << endl;
            cout << "Emotion: " << sortedOutput[r].second[6] << endl;
            cout << "Class Name: " << sortedOutput[r].second[7] << endl;
            cout << "Comment: " << sortedOutput[r].second[8] << endl;
            cout << "ThumbsUp: " << sortedOutput[r].second[9] << "  ThumbsDown: " << sortedOutput[r].second[10] << endl;
            cout << "Review Date: " << sortedOutput[r].second[11] << endl;
            //cout << endl;

        }

    }


    if (searchType == "Both") {

        cout << endl;
        cout << "University: " << UniversitySearch << "    |    Professor: " << searchProfessor << endl;
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "Average Quality Rating: " << QualityRating << endl;
        cout << "Total Reviews: " << sortedOutput.size() << endl;

        for (int r = (sortedOutput.size() - 1); r >= 0; r--) {
            //cout << sortedOutput.at(r).first << endl;
            cout << endl;
            cout << "Professor ID: " << sortedOutput[r].second[0] << endl;
            //cout << "Professor Name: " << sortedOutput[r].second[1] << endl;
            cout << "Department: " << sortedOutput[r].second[3] << endl;
            cout << "Quality: " << sortedOutput[r].second[4] << endl;
            cout << "Difficulty: " << sortedOutput[r].second[5] << endl;
            cout << "Emotion: " << sortedOutput[r].second[6] << endl;
            cout << "Class Name: " << sortedOutput[r].second[7] << endl;
            cout << "Comment: " << sortedOutput[r].second[8] << endl;
            cout << "ThumbsUp: " << sortedOutput[r].second[9] << "  ThumbsDown: " << sortedOutput[r].second[10] << endl;
            cout << "Review Date: " << sortedOutput[r].second[11] << endl;
            //cout << endl;

        }


    }

    if (searchType == "UniversityandCourse") {

        cout << endl;
        cout << "University: " << UniversitySearch << "    |    Course: " << courseSearch << endl;
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "Average Quality Rating: " << QualityRating << endl;
        cout << "Total Reviews: " << sortedOutput.size() << endl;

        for (int r = (sortedOutput.size() - 1); r >= 0; r--) {
            //cout << sortedOutput.at(r).first << endl;
            cout << endl;
            cout << "Professor ID: " << sortedOutput[r].second[0] << endl;
            cout << "Professor Name: " << sortedOutput[r].second[1] << endl;
            //cout << "Department: " << sortedOutput[r].second[3] << endl;
            cout << "Quality: " << sortedOutput[r].second[4] << endl;
            cout << "Difficulty: " << sortedOutput[r].second[5] << endl;
            cout << "Emotion: " << sortedOutput[r].second[6] << endl;
            cout << "Class Name: " << sortedOutput[r].second[7] << endl;
            cout << "Comment: " << sortedOutput[r].second[8] << endl;
            cout << "ThumbsUp: " << sortedOutput[r].second[9] << "  ThumbsDown: " << sortedOutput[r].second[10] << endl;
            cout << "Review Date: " << sortedOutput[r].second[11] << endl;
            //cout << endl;

        }


    }


    if (searchType == "University") {
        cout << endl;
        cout << "University: " << UniversitySearch << endl;

        for (int r = (sortedOutput.size() - 1); r >= 0; r--) {
            //cout << sortedOutput.at(r).first << endl;
            cout << endl;
            cout << "Professor ID: " << sortedOutput[r].second[0] << endl;
            cout << "Professor Name: " << sortedOutput[r].second[1] << endl;
            cout << "Department: " << sortedOutput[r].second[3] << endl;
            cout << "Quality: " << sortedOutput[r].second[4] << endl;
            cout << "Difficulty: " << sortedOutput[r].second[5] << endl;
            cout << "Emotion: " << sortedOutput[r].second[6] << endl;
            cout << "Class Name: " << sortedOutput[r].second[7] << endl;
            cout << "Comment: " << sortedOutput[r].second[8] << endl;
            cout << "ThumbsUp: " << sortedOutput[r].second[9] << "  ThumbsDown: " << sortedOutput[r].second[10] << endl;
            cout << "Review Date: " << sortedOutput[r].second[11] << endl;
            //cout << endl;

        }
    }







    else if (searchType == "Professor") {


        //cout << sortedOutput.at(r).first << endl;

        cout << endl;
        cout << "Professor: " << searchProfessor << endl;
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "Average Quality Rating: " << QualityRating << endl;
        cout << "Total Reviews: " << sortedOutput.size() << endl;
        //cout << sortedOutput.at(r).first << endl;
        for (int r = (sortedOutput.size() - 1); r >= 0; r--) {
            cout << endl;
            cout << "Professor ID: " << sortedOutput[r].second[0] << endl;
            // cout << "Professor Name: " << sortedOutput[r].second[1] << endl;
            cout << "University: " << sortedOutput[r].second[2] << endl;
            cout << "Department: " << sortedOutput[r].second[3] << endl;
            cout << "Quality: " << sortedOutput[r].second[4] << endl;
            cout << "Difficulty: " << sortedOutput[r].second[5] << endl;
            cout << "Emotion: " << sortedOutput[r].second[6] << endl;
            cout << "Class Name: " << sortedOutput[r].second[7] << endl;
            cout << "Comment: " << sortedOutput[r].second[8] << endl;
            cout << "ThumbsUp: " << sortedOutput[r].second[9] << "  ThumbsDown: " << sortedOutput[r].second[10] << endl;
            cout << "Review Date: " << sortedOutput[r].second[11] << endl;

        }

    }



/*
//for(int r = 0; r < sortedOutput.size(); r++) {




//}


//may need to add sorting algorithm for rankings

//may need to combine both of them
//if so, make vector to store school first, then professor or vise versa and then store keys

    //   for (auto item: Reviews[i]) {


    //  }
*/
}

    return 0;
}
