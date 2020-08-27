#include <iostream>
#include <string>
#include <fstream> //voor bestanden in te gebruiken
#include <bits/stdc++.h> //including vectors
#include "gameLogic.h"

namespace WhereIsAscii{
    gameLogic::gameLogic(void){
        
        //opening files
        scoreBoard.open("./files/scoreBoard.txt", std::ios::app);
        if (!scoreBoard){
            std::cerr << "Unable to acces files, scoreboard";
            exit(1);
        }

        //Logon and setup
        std::cout << "Player Name: ";
        std::cin >> playerName;
        std::cout << "From 1 to 8 are valid options" << std::endl << "Dificulty: ";
        std::cin >> dificulty;
        switch (dificulty){
        case 1:
            config[0] = 24;
            config[1] =  3;
            config[2] =  2;
            break;
        case 2:
            config[0] = 24;
            config[1] =  4;
            config[2] =  3;
            break;
        case 3:
            config[0] = 24;
            config[1] =  5;
            config[2] =  4;
            break;
        case 4:
            config[0] = 24;
            config[1] =  6;
            config[2] =  4;
            break;
        case 5:
            config[0] = 48;
            config[1] =  7;
            config[2] =  2;
            break;
        case 6:
            config[0] = 48;
            config[1] =  8;
            config[2] =  3;
            break;
        case 7:
            config[0] = 48;
            config[1] =  9;
            config[2] =  3;
            break;
        case 8:
            config[0] = 48;
            config[1] = 10;
            config[2] =  4;
            break;
        default:
            std::cout << "Enter a valid option!";
            return;
            break;
        }
        // reveal[0] = config[1] +1;
        // reveal[1] = config[1] +1;
        // reveal[2] = config[1] +1;
        // reveal[3] = config[1] +1;

        //genereren van speel veld
        for(unsigned int i = 0; i < (pow(config[1], 2)/2); i++){
            gameBoard.push_back(infill[i]);
        }
        tmp = gameBoard;
        gameBoard.insert(gameBoard.end(), tmp.begin(), tmp.end());
        random_shuffle(gameBoard.begin(), gameBoard.end());

        gaming = true;
        while(gaming){ 
            reveal[0] = config[1] +1;
            reveal[1] = config[1] +1;
            reveal[2] = config[1] +1;
            reveal[3] = config[1] +1;
            //tekenen van matrix
            drawMatrix();
            std::cout << "X:";
            std::cin >> reveal[0];
            std::cout << "Y:";
            std::cin >> reveal[1];
            drawMatrix();
            std::cout << "X:";
            std::cin >> reveal[2];
            std::cout << "Y:";
            std::cin >> reveal[3];
            drawMatrix();
            if(gameBoard.at(reveal[0]*config[2]+reveal[1]) == gameBoard.at(reveal[2]*config[2]+reveal[3])) found.push_back({reveal[0],reveal[1],reveal[2],reveal[3]});
        }
        

        // //game implementatie
        // for(unsigned int i =0; i<(50*dificulty); i++){
        //     srand((unsigned int)time(NULL));
        //     generatedWords = wordList.at(rand() % wordList.size());
        //     startTime = clock();
        //     std::cout << generatedWords << std::endl;
        //     std::cin >> typedWords;
        //     score -= (clock()-startTime);
        //     score -= abs(generatedWords.compare(typedWords));
        // }

        
        


        //Debuging and closing files
        //std::cout << playerName << " " << dificulty << " " << score << std::endl;
        scoreBoard  << playerName << " " << dificulty << " " << score << std::endl;
        scoreBoard.close();
        //std::cout << "all files closed" << std::endl;
    }

    void gameLogic::drawMatrix(void){
                    std::cout << std::endl << " ";
            for(unsigned int k = 0; k < config[1]; k++) std::cout << " " << k << " ";
            std::cout << std::endl;
            for(unsigned int i = 0; i < config[1]; i++){
                std::cout << i;
                for(unsigned int j = 0; j < config[1]; j++){
                    
                    if(reveal[0] == i && reveal[1] == j || reveal[2] == i && reveal[3] ==j) std::cout << " " << gameBoard.at(i*config[2]+j) << " ";
                    else std::cout << " ? "; 
                }
                std::cout << std::endl;
            }
    }
}