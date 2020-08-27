#pragma once
#include <string>
#include <fstream> //voor bestanden in te gebruiken
#include <bits/stdc++.h> //including vectors

namespace WhereIsAscii{
    class gameLogic{
        public: 
            gameLogic(void);
        private:
            std::string playerName;
            std::string word;
            std::string generatedWords, typedWords;
            clock_t startTime;
            unsigned int dificulty;
            int score = 0;
            std::vector<char> letterList;
            std::ofstream scoreBoard;
    };  
};