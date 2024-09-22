#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> stack;
    int max_size;

public:
    Stack(int max_size) {
        this->max_size = max_size;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Overflow" << endl;
        } else {
            stack.push_back(value);
            print_stack();
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
        } else {
            stack.pop_back();
            print_stack();
        }
    }

    bool isEmpty() {
        return stack.empty();
    }

    bool isFull() {
        return stack.size() == max_size;
    }

    void size() {
        cout << stack.size() << endl;
    }

    void top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << stack.back() << endl;
        }
    }

    void print_stack() {
        if (stack.empty()) {
            cout << "Stack is empty" << endl;
        } else {
            for (int i = 0; i < stack.size(); i++) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int N;
    cin >> N;  

    Stack st(N);  

    int command, value;

    while (true) {
        cin >> command;

        if (command == -1) break;  

        switch (command) {
            case 1: 
                cin >> value;
                st.push(value);
                break;
            case 2: 
                st.pop();
                break;
            case 3: 
                cout << (st.isEmpty() ? "True" : "False") << endl;
                break;
            case 4: 
                cout << (st.isFull() ? "True" : "False") << endl;
                break;
            case 5: 
                st.size();
                break;
            case 6: 
                st.top();
                break;
        }
    }

    return 0;
}

