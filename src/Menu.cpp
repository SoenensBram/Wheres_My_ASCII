#include <iostream>
#include "gameLogic.h"
#include "Menu.h"
#include <fstream> //voor bestanden in te gebruiken

namespace WhereIsAscii{
    Menu::Menu(void){
        //Welcom screen
        std::cout << "Welcome To WordBlaster" << std::endl <<"0. To Quit" << std::endl << "1. ScoreBoard" << std::endl << "2. Wordblaster" << std::endl;
        std::cin >> select;

        std::ifstream scoreBoard;
        scoreBoard.open("./files/scoreBoard.txt", std::ios::app);
            if (!scoreBoard){
                std::cerr << "Unable to acces files, scoreboard";
                exit(0);
            }

        switch (select){
            case 1:
                std::cout << "Name    Dif   Score" << std::endl;
                while(scoreBoard >> word){
                    j++;
                    std::cout << word;
                    if(j==3){
                        std::cout << std::endl;
                        j = 0;
                    }else std::cout << "    ";
                };
                std::cout << std::endl;
                break;
            case 2:
                new gameLogic;
                break;
            default:
                exit(1);
                break;
            }
        scoreBoard.close();
    }
}