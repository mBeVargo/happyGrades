#pragma once

#include <string>

class Professor {
private:
    std::string prof_ID;
    std::string prof_name;
    std::string university;
    double avg_quality;
    double avg_difficulty;
    double avg_emotion;
public:
    Professor();

    Professor(std::string id, std::string name, std::string uni, double qual, double diff, double emo);

    Professor(const Professor& other);

    std::string GetName();
    std::string GetID();
    double GetAvgQuality();
    double GetAvgDifficulty();
    double GetAvgEmotion();
};
