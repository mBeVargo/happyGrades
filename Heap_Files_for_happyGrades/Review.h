#pragma once

#include <string>

class Review {
private:
    std::string prof_ID;
    std::string prof_name;
    std::string university;
    double quality;
    int difficulty;
    std::string emotion;
    std::string course;
    std::string comment;
public:
    //getters prob??
    std::string GetName();
    std::string GetID();
    std::string GetUni();
    double GetQuality();
    int GetDifficulty();
    std::string GetEmotion();
    std::string GetComment();

    Review();

    Review(std::string id, std::string name, std::string uni, double quality, int difficulty, std::string emotion, std::string course, std::string comment) {
        this->prof_ID = id;
        this->prof_name = name;
        this->university = uni;
        this->quality = quality;
        this->difficulty = difficulty;
        this->emotion = emotion;
        this->course = course;
        this->comment = comment;
    }

    Review(const Review& other) {
        prof_ID = other.prof_ID;
        prof_name = other.prof_name;
        university = other.university;
        quality = other.quality;
        difficulty = other.difficulty;
        emotion = other.emotion;
        course = other.course;
        comment = other.comment;
    }
};
