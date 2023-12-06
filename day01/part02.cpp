#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

int main() {
    ifstream inputFile("day01.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    string line;
    int totalSum = 0, i = 1;
    map<string, string> textToDigit = {
        {"one", "1"},
        {"two", "2"},
        {"three", "3"},
        {"four", "4"},
        {"five", "5"},
        {"six", "6"},
        {"seven", "7"},
        {"eight", "8"},
        {"nine", "9"},
    };

    while (getline(inputFile, line)) {
        string lineNumber;
        int lastStrPos = 0;
        for (int i = 0; i<line.size(); i++) {
            string curSpelledCandidate = line.substr(lastStrPos, i-lastStrPos + 1);
            for(const auto& [key, value] : textToDigit ) {
                if(curSpelledCandidate.find(key) != string::npos){
                    lineNumber += value;
                    lastStrPos = i;
                    break;
                }
            }

            if ((lastStrPos != (i + 1)) && (isdigit(line[i]))) {
                lineNumber += line[i];
                lastStrPos = i;
            }
        }

        cout << "Line #" << i++ << ": " << lineNumber;
        switch (lineNumber.size()) {
            case 1:
                lineNumber += lineNumber;
                break;
            case 2:
                break;
            default:
                lineNumber = std::string(1, lineNumber.front()) + std::string(1, lineNumber.back());
        }
        cout << " - " << lineNumber << endl;

        totalSum += stoi(lineNumber);

    }
    cout << "Total Sum: " << totalSum << endl;

    inputFile.close();

    return 0;
}
