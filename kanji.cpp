#include "kanji.hpp"
#include <cstdarg>

Kanji::Kanji(std::string kanjiWriting)
{
    this->kanjiWriting = kanjiWriting;
}

void Kanji::addOnyomi(std::string reading)
{
    onyomi.insert(onyomi.begin(),reading);
}

void Kanji::addKunyomi(std::string reading)
{
    kunyomi.insert(onyomi.begin(),reading);
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
