#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    
    float day1 = 10.0f;
    float increase = 0.10f;
    
    float day2 = day1 * (1 + increase);
    float day3 = day2 * (1 + increase);
    float day4 = day3 * (1 + increase);
    
    cout << fixed << setprecision(2);
    cout << "Дистанция за 2-й день: " << day2 << " км" << endl;
    cout << "Дистанция за 3-й день: " << day3 << " км" << endl;
    cout << "Дистанция за 4-й день: " << day4 << " км" << endl;
    
    return 0;
}
