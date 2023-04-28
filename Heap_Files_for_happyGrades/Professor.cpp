#include "Professor.h"

std::string Professor::GetName() {
    return this->prof_name;
}

std::string Professor::GetID() {
    return this->prof_ID;
}

double Professor::GetAvgQuality() {
    return this->avg_quality;
}
double Professor::GetAvgDifficulty() {
    return this->avg_difficulty;
}
double Professor::GetAvgEmotion() {
    return this->avg_emotion;
}

Professor::Professor() {
    prof_ID = "8888888";
    prof_name = "DUMMY VAR";
    university = "NOT UF";
    avg_quality = -1.00;
    avg_difficulty = -1.00;
    avg_emotion = -1.00;
}

Professor::Professor(std::string id, std::string name, std::string uni, double qual, double diff, double emo) {
    this->prof_ID = id;
    this->prof_name = name;
    this->university = uni;
    this->avg_quality = qual;
    this->avg_difficulty = diff;
    this->avg_emotion = emo;
}

Professor::Professor(const Professor& other) {
    prof_ID = other.prof_ID;
    prof_name = other.prof_name;
    university = other.university;
    avg_quality = other.avg_quality;
    avg_difficulty = other.avg_difficulty;
    avg_emotion = other.avg_emotion;
}