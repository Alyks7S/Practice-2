#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void compareFiles(const string& file1, const string& file2, const string& outputFile) {
    ifstream f1(file1), f2(file2);
    ofstream g(outputFile);

    if (!f1.is_open() || !f2.is_open() || !g.is_open()) {
        cerr << "Ошибка открытия файлов!" << endl;
        return;
    }

    vector<string> words1, words2;
    string word;

    while (f1 >> word) {
        words1.push_back(word);
    }

    while (f2 >> word) {
        words2.push_back(word);
    }

    size_t minLen = min(words1.size(), words2.size());

    for (size_t i = 0; i < minLen; ++i) {
        if (words1[i] != words2[i]) {
            g << "\"" << words1[i] << "\", \"" << words2[i] << "\"" << endl;
        }
    }

    if (words1.size() > words2.size()) {
        for (size_t i = minLen; i < words1.size(); ++i) {
            g << "\"" << words1[i] << "\", \"\"" << endl;
        }
    } else if (words2.size() > words1.size()) {
        for (size_t i = minLen; i < words2.size(); ++i) {
            g << "\"\", \"" << words2[i] << "\"" << endl;
        }
    }

    cout << "Сравнение завершено. Результат записан в " << outputFile << endl;
}

int main() {
    compareFiles("F1.txt", "F2.txt", "G.txt");
    return 0;
}