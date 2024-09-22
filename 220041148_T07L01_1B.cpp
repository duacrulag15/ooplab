#include <iostream>
#include <stack>

using namespace std;


int postFix (string s) {
    stack <int> stk;

    int a, b, result, digit;

    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            digit = s[i] - '0';
            stk.push(digit);
        }
        else {
            b = stk.top();
            stk.pop();
            a = stk.top();
            stk.pop();



            if (s[i] == '+') {
                result = a + b;
            }

            else if (s[i] == '-') {
                result = a - b;
            }

            else if (s[i] == '*') {
                result = a * b;
            }

            else {
                result = a/b;
            }

        }

        stk.push(result);
    }

    return stk.top();
}







int main () {
    string s;
    cin >> s;
    cout << postFix (s);
}