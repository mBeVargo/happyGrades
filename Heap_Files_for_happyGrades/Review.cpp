#include "Review.h"

std::string Review::GetName() {
    return prof_name;
}

std::string Review::GetID() {
    return prof_ID;
}

std::string Review::GetUni() {
    return university;
}

double Review::GetQuality() {
    return quality;
}

int Review::GetDifficulty() {
    return difficulty;
}

std::string Review::GetEmotion() {
    return emotion;
}

std::string Review::GetComment() {
    return comment;
}