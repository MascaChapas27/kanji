#include "kanji.hpp"
#include <vector>

int main(){

    std::vector<Kanji> kanjis;

    Kanji uno("一");
    uno.addOnyomi("イチ");
    uno.addOnyomi("イツ");
    uno.addKunyomi("ひと");
    kanjis.push_back(uno);

    while(true){
        Kanji k = kanjis[0];
        std::string kanjiWriting = k.getKanji();


    }
}
