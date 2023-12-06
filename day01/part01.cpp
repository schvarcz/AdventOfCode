#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    ifstream inputFile("day01.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    string line;
    int totalSum = 0, i = 1;
    while (getline(inputFile, line)) {
        string lineNumber;
        for (char c : line) {
            if (isdigit(c)) {
                lineNumber += c;
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
