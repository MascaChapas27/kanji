#include "kanji.hpp"
#include <vector>
#include "reading.hpp"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <bits/stdc++.h>

int main(){

    srand(time(NULL));

    std::vector<Kanji> kanjis;

    std::ifstream f("kanjis.txt");

    std::string line;
    getline(f, line);

    while(line != "＃"){

        Kanji k(line);

        getline(f, line);
        while(line != "")
        {
            k.addOnyomi(line);
            getline(f, line);
        }

        getline(f, line);
        while(line != "ーーーー")
        {
            k.addKunyomi(line);
            getline(f, line);
        }

        kanjis.push_back(k);
        getline(f, line);
    }

    while(kanjis.size()>0){
        int index = rand()%kanjis.size();
        Kanji k = kanjis[index];
        kanjis.erase(find(kanjis.begin(),kanjis.end(),k));

        std::string kanjiWriting = k.getKanji();

        std::list<Reading> onyomi;
        for(std::string s : k.getOnyomi()){
            onyomi.insert(onyomi.begin(),Reading(s));
        }

        std::list<Reading> kunyomi;
        for(std::string s : k.getKunyomi()){
            kunyomi.insert(kunyomi.begin(),Reading(s));
        }

        int guessed = 0;

        do {
            system("clear");
            std::cout << "Kanji: " << k.getKanji() << std::endl << std::endl;
            std::cout << "Onyomi: " << std::endl;
            for(Reading r : onyomi){
                if(r.isGuessed()) std::cout << r.getReading() << std::endl;
                else std::cout << "---" << std::endl;
            }

            std::cout << std::endl << "Kunyomi: " << std::endl;
            for(Reading r : kunyomi){
                if(r.isGuessed()) std::cout << r.getReading() << std::endl;
                else std::cout << "---" << std::endl;
            }

            std::cout << std::endl;

            std::string answer;
            getline(std::cin,answer);

            if(answer == "") break;

            for(Reading &r : onyomi){
                if(r.checkReading(answer)){
                    r.setGuessed();
                    guessed++;
                }
            }

            for(Reading &r : kunyomi){
                if(r.checkReading(answer)){
                    r.setGuessed();
                    guessed++;
                }
            }

        } while(guessed != k.getReadings());
        system("clear");

    }
}
