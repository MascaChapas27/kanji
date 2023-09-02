#ifndef __READING_HPP__
#define __READING_HPP__

#include <string>

class Reading
{
    private:
        std::string reading;
        bool guessed;
    public:
        Reading(std::string r);
        bool isGuessed();
        bool checkReading(std::string r);
        void setGuessed();
        std::string getReading();
};

#endif
