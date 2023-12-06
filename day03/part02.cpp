#include <iostream>
#include <fstream>
#include <sstream>
#include <deque>
#include <algorithm>

using namespace std;

bool isValid(const deque<string> &lines, int startNumber, int endNumber) {
    startNumber = max(startNumber-1, 0);

    for (int i = 0; i<lines.size(); i++) {
        for(int j = startNumber; j<min(endNumber+1, static_cast<int>(lines[i].size())); j++) {
            if (!isdigit(lines[i][j]) && (lines[i][j] != '.')) {
                return true;
            }
        }
    }

    return false;
}

vector<int> findAdjacentNumbers(const deque<string> &curFrame, const int &lineToCheck, const int& gearPos) {
    return vector<int>();
}

int lineGearSum(const deque<string> &curFrame, const int &lineToCheck) {
    auto curLine = &curFrame[lineToCheck];
    int startNumber = -1, endNumber = -1, lineSum = 0;
    for(int i=0; i < curLine->size(); i++) {
        if(curLine->at(i)  == '*') {
            auto numbers = findAdjacentNumbers(curFrame, lineToCheck, i);
            if (numbers.size() == 2) {
                lineSum += numbers[0]*numbers[1];
            }
        }
    }
    return lineSum;
}

int main() {
    ifstream inputFile("day03.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    string line;
    int totalSum = 0, lineNumber = 1;
    deque<string> curFrame;

    while (getline(inputFile, line)) {
        curFrame.push_back(line);

        if (curFrame.size() > 1) {
            totalSum += lineGearSum(curFrame, curFrame.size() - 2);
            cout << "Line #" << lineNumber++ << ": " << totalSum << endl;
        }

        if (curFrame.size() >= 3)
            curFrame.pop_front();
    }

    totalSum += lineGearSum(curFrame, curFrame.size() - 1);

    cout << "Line #" << lineNumber++ << ": " << totalSum << endl;
    cout << "Total Sum: " << totalSum << endl;

    inputFile.close();

    return 0;
}
