#include <iostream>
using namespace std;

int main() {

    char repeat;
    
    do {
        int N1, N2, m, n;
        
        cout << "Введите начало диапазона (N1): ";
        cin >> N1;
        cout << "Введите конец диапазона (N2): ";
        cin >> N2;
        cout << "Введите число m (кратность): ";
        cin >> m;
        cout << "Введите число n (не кратность): ";
        cin >> n;
        
        if (m == 0) {
            cout << "Ошибка: m не может быть равно 0!" << endl;
            continue;
        }
        
        if (N1 > N2) {
            cout << "Ошибка: N1 должно быть меньше или равно N2!" << endl;
            continue;
        }
        
        cout << "Числа в диапазоне [" << N1 << ", " << N2 
             << "], кратные " << m << " и не кратные " << n << ":" << endl;
        
        bool found = false;
        
        for (int i = N1; i <= N2; ++i) {
            if (i % m == 0 && (n == 0 || i % n != 0)) {
                cout << i << " ";
                found = true;
            }
        }
        
        if (!found) {
            cout << "Таких чисел нет в заданном диапазоне.";
        }
        
        cout << endl;
        
        cout << "Хотите выполнить еще один поиск? (y/n): ";
        cin >> repeat;
        
    } while (repeat == 'y' || repeat == 'Y');
    
    cout << "Программа завершена." << endl;
    return 0;
}
