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

int lineSum(const deque<string> &curFrame, const int &lineToCheck) {
    auto curLine = &curFrame[lineToCheck];
    int startNumber = -1, endNumber = -1, lineSum = 0;
    for(int i=0; i < curLine->size(); i++) {
        if(isdigit((*curLine)[i])) {
            if (startNumber < 0) {
                startNumber = i;
            }
            endNumber = i;
        }

        if ((startNumber >= 0) && (!isdigit((*curLine)[i]) || (i == curLine->size()-1))) {
            if (isValid(curFrame, startNumber, i)) {
                lineSum += stoi(curLine->substr(startNumber, i - startNumber + (i == curLine->size()-1)));
            }
            startNumber = -1;
            endNumber = -1;
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
            totalSum += lineSum(curFrame, curFrame.size() - 2);
            cout << "Line #" << lineNumber++ << ": " << totalSum << endl;
        }

        if (curFrame.size() >= 3)
            curFrame.pop_front();
    }

    totalSum += lineSum(curFrame, curFrame.size() - 1);

    cout << "Line #" << lineNumber++ << ": " << totalSum << endl;
    cout << "Total Sum: " << totalSum << endl;

    inputFile.close();

    return 0;
}
