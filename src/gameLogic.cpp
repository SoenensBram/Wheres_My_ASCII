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
        for(unsigned int i = 0; i < config[2]*2; i++) reveal.push_back(config[1]);

        //genereren van speel veld
        for(unsigned int i = 0; i < (pow(config[1], 2)/config[2]); i++) gameBoard.push_back(infill[i]);
        for(unsigned int i = 0; i < (pow(config[1], 2)*2); i++) found.push_back(false);
        tmp = gameBoard;
        for(unsigned int i = 0; i<config[2]; i++) gameBoard.insert(gameBoard.end(), tmp.begin(), tmp.end());
        srand((unsigned int)time(NULL));
        random_shuffle(gameBoard.begin(), gameBoard.end());

        gaming = true;
        while(gaming){ 
            //tekenen van matrix
            for(unsigned int i = 0; i < config[2]; i++){
                drawMatrix();
                std::cout << "X:";
                std::cin >> reveal.at(i);
                std::cout << "Y:";
                std::cin >> reveal.at(i+ config[2]);
            }
            drawMatrix();
            tmp2 = false;
            for(unsigned int i = 1; i < config[2]; i++) tmp2 += gameBoard.at(reveal.at(0)*config[1]+reveal.at(config[2])) == gameBoard.at(reveal.at(i)*config[1]+reveal.at(i+ config[2]));
            if(tmp2) for(unsigned int i = 0; i < config[2]; i++) if(tmp2) found.at(reveal.at(i)*config[1]+reveal.at(i+ config[2]))= true;
            if(tmp2) std::cout << "Match found";
            else std::cout << "Match not found";
            std::cin.get();
            for(unsigned int i = 0; i < config[2]*2; i++)reveal.at(i) = config[1];
        }
        

        // //game implementatie
        // for(unsigned int i =0; i<(50*dificulty); i++){
        //     srand((unsigned int)time(NULL));
        //     generatedWords = wordList.at(rand() % wordList.size());
        //     startTime = clock();gameBoard.insert(gameBoard.end(), tmp.begin(), tmp.end());
        
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
            std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << " ";
            for(unsigned int k = 0; k < config[1]; k++) std::cout << " " << k << " ";
            std::cout << std::endl;
            for(unsigned int i = 0; i < config[1]; i++){
                std::cout << i;
                for(unsigned int j = 0; j < config[1]; j++){
                    bool tmp3 = false;
                    for(unsigned int m = 0; m < config[2]; m++) tmp3 += reveal.at(m) == i && reveal.at(m + config[2]) == j;
                    if(tmp3 || found.at(i*config[1]+j)) std::cout << " " << gameBoard.at(i*config[1]+j) << " ";
                    else std::cout << " ? "; 
                }
                std::cout << std::endl;
            }
    }
}