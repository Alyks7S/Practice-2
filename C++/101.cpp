#include <iostream>
#include <stack>
#include <string>

using namespace std;

int checkParentheses(const string& str) {
    stack<char> s;

    for (char c : str) {
        switch (c) {
            case '(':
            case '[':
            case '{':
                s.push(c);
                break;

            case ')':
                if (s.empty() || s.top() != '(') return 0;
                s.pop();
                break;
            case ']':
                if (s.empty() || s.top() != '[') return 0;
                s.pop();
                break;
            case '}':
                if (s.empty() || s.top() != '{') return 0;
                s.pop();
                break;
        }
    }

    return s.empty() ? 1 : 0;
}

int main() {
    string input;
    cout << "Введите строку: ";
    getline(cin, input);

    int result = checkParentheses(input);
    cout << "Результат: " << result << endl;

    return 0;
}