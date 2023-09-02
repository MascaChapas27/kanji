#include "reading.hpp"
#include <iostream>

Reading::Reading(std::string r){
    reading = r;
    guessed = false;
}

bool Reading::isGuessed()
{
    return guessed;
}

bool Reading::checkReading(std::string r)
{
    return reading == r;
}

void Reading::setGuessed()
{
    guessed = true;
}

std::string Reading::getReading()
{
    return reading;
}
