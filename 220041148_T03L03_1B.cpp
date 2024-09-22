#include <iostream>
using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    int hours() const {
        return hour;
    }

    int minutes() const {
        return minute;
    }

    int seconds() const {
        return second;
    }

    void reset(int h, int m, int s) {
        if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60) {
            hour = h;
            minute = m;
            second = s;
        } else {
            cout << "Invalid time input." << endl;
        }
    }

    void advance(int h, int m, int s) {
        second += s;
        minute += second / 60;
        second %= 60;

        minute += m;
        hour += minute / 60;
        minute %= 60;

        hour += h;
        hour %= 24;
    }

    void print() const {
        cout << (hour < 10 ? "0" : "") << hour << ":"
             << (minute < 10 ? "0" : "") << minute << ":"
             << (second < 10 ? "0" : "") << second << endl;
    }
};
