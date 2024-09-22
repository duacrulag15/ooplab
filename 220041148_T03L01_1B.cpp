#include <iostream>
#include <stack>
#include <vector>

using namespace std;


void check (vector <int> v) {
    int targetIndex = 0;

    stack <int> stk;



    for (int i = 1; i <= v[v.size() - 1]; i++) {
        stk.push(i);
        cout << "Push" << endl;

        if (i != v[targetIndex]) {
            stk.pop();
            cout << "Pop" << endl;
        }

        else {
            targetIndex = targetIndex + 1;
        }
    }

}





int main () {

    vector <int> v;

    int el;

    while (1) {
        cin >> el;
        if (el == -1) {
            break;
        }
        v.push_back(el);
    }

    check(v);



}