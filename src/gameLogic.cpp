#include <iostream>
#include <string>
#include <fstream> //voor bestanden in te gebruiken
#include <bits/stdc++.h> //including vectors
#include "gameLogic.h"

namespace WhereIsAscii{
    gameLogic::gameLogic(void){
        
        //Logon and setup
        std::cout << "Player Name: ";
        std::cin >> playerName;
        std::cout << "1 (easy), 2 (normal) and 3 (hard) are valid options" << std::endl << "Dificulty: ";
        std::cin >> dificulty;
        switch (dificulty){
        case 1:
            wordData.open("./files/wordsEasy.txt");
            break;
        case 2:
            wordData.open("./files/wordsNormal.txt");
            break;
        case 3:
            wordData.open("./files/wordsHard.txt");
            break;
        default:
            std::cout << "Enter a valid option!";
            break;
        }

        //opening files
        scoreBoard.open("./files/scoreBoard.txt", std::ios::app);
        if (!scoreBoard){
            std::cerr << "Unable to acces files, scoreboard";
            exit(1);
        }

        if (!wordData){
            std::cerr << "Unable to acces files, Word data";
            exit(1);
        }

        //Data ingest
        while(wordData >> word){
            wordList.push_back(word);
        }

        //game implementatie
        for(unsigned int i =0; i<(50*dificulty); i++){
            srand((unsigned int)time(NULL));
            generatedWords = wordList.at(rand() % wordList.size());
            startTime = clock();
            std::cout << generatedWords << std::endl;
            std::cin >> typedWords;
            score -= (clock()-startTime);
            score -= abs(generatedWords.compare(typedWords));
        }

        
        


        //Debuging and closing files
        //std::cout << playerName << " " << dificulty << " " << score << std::endl;
        scoreBoard  << playerName << " " << dificulty << " " << score << std::endl;
        scoreBoard.close();
        wordData.close();
        //std::cout << "all files closed" << std::endl;
    }
}