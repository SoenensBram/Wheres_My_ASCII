#pragma once
#include <fstream>

namespace WhereIsAscii{
    class Menu{
        public: 
            Menu(void);
        private:
            std::ifstream scoreBoard;
            unsigned int select;
            std::string word;
            unsigned int j = 0;
    };  
};