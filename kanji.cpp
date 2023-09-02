#include "kanji.hpp"
#include <cstdarg>

Kanji::Kanji(std::string kanjiWriting)
{
    this->kanjiWriting = kanjiWriting;
    readings = 0;
}

void Kanji::addOnyomi(std::string reading)
{
    onyomi.insert(onyomi.begin(),reading);
    readings++;
}

void Kanji::addKunyomi(std::string reading)
{
    kunyomi.insert(kunyomi.begin(),reading);
    readings++;
}

std::string Kanji::getKanji(){
    return kanjiWriting;
}

std::list<std::string> Kanji::getOnyomi(){
    return onyomi;
}
std::list<std::string> Kanji::getKunyomi(){
    return kunyomi;
}

int Kanji::getReadings()
{
    return readings;
}

bool Kanji::operator==(Kanji another){
    return this->kanjiWriting == another.kanjiWriting;
}
