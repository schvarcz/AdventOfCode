#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

bool isValid(map<string,int> observedNBalls, map<string,int> informedNBalls) {
    for(const auto&[key, minValue] : informedNBalls) {
        auto it = observedNBalls.find(key);
        if ((it == observedNBalls.end()) || (it->second > minValue)) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream inputFile("day02.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    string line;
    int totalSum = 0, i = 1;

    map<string,int> informedNBalls = {
        {"green", 13},
        {"blue", 14},
        {"red", 12},
    };
    while (getline(inputFile, line)) {

        string gameNumber, gameset, game;
        string balls, nBalls, color;

        istringstream lineStream(line);
        getline(lineStream, gameNumber, ':');
        getline(lineStream, gameset, ':');

        istringstream gameNumberStream(gameNumber);
        getline(gameNumberStream, gameNumber, ' '); // It is the Game word, it should be replaced by the next line
        getline(gameNumberStream, gameNumber, ' ');

        map<string,int> gameMaxScores ={
            {"green", 0},
            {"blue", 0},
            {"red", 0},
        };

        istringstream gameSetStream(gameset);
        while(getline(gameSetStream, game, ';')) {

            istringstream gameStream(game);
            while(getline(gameStream, balls, ',')) {
                istringstream ballsStream(balls);
                getline(ballsStream, nBalls, ' '); // Removes the first white space
                getline(ballsStream, nBalls, ' ');
                getline(ballsStream, color, ' ');

                gameMaxScores[color] = max(gameMaxScores[color], stoi(nBalls));
            }   
        }
        if (isValid(gameMaxScores, informedNBalls)) {
            totalSum += stoi(gameNumber);
        }
        cout << "Line #" << i++ << ": " ;
        for( const auto& [key,value] : gameMaxScores) {
            cout << value << " " << key << ", ";
        }
        cout << endl;
    }
    cout << "Total Sum: " << totalSum << endl;

    inputFile.close();

    return 0;
}
