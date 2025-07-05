#include <iostream>
#include <windows.h> 
using namespace std;

int Yes(int N) {
    SetConsoleOutputCP(CP_UTF8);
    if (N < 10000 || N > 99999) {
        return -1;
    }

    int original = N;
    int reversed = 0;

    while (N > 0) {
        reversed = reversed * 10 + N % 10;
        N /= 10;
    }

    if (original == reversed) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int number;
    cout << "Введите пятизначное число: ";
    cin >> number;

    int result = Yes(number);

    if (result == -1) {
        cout << "Ало, число должно быть пятизначным" << endl;
    } else if (result == 1) {
        cout << "Число - палиндром" << endl;
    } else {
        cout << "Число - не палиндром" << endl;
    }

    return 0;
}