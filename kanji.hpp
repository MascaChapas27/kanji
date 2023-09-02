#ifndef __KANJI_HPP__
#define __KANJI_HPP__

#include <list>
#include <string>

class Kanji{

    private:
        std::string kanjiWriting;
        std::list<std::string> onyomi;
        std::list<std::string> kunyomi;

    public:
        Kanji(std::string imagePath);
        void addOnyomi(std::string reading);
        void addKunyomi(std::string reading);
        std::string getKanji();
        std::list<std::string> getOnyomi();
        std::list<std::string> getKunyomi();

};

#endif // __KANJI_HPP__
