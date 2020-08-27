#pragma once
#include <string>
#include <fstream> //voor bestanden in te gebruiken
#include <bits/stdc++.h> //including vectors

namespace WhereIsAscii{
    class gameLogic{
        public: 
            gameLogic(void);
        private:
            void drawMatrix(void);
            bool gaming = false;
            std::string playerName;
            clock_t startTime;
            unsigned int dificulty;
            int score = 0;
            std::vector<char> gameBoard;
            std::vector<char> tmp;
            std::vector<int[4]> found;
            unsigned int reveal[4];
            std::ofstream scoreBoard;
            unsigned int config[3];
            char infill[50] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRTSUVW";
    };  
};