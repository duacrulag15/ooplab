#include <iostream>
#include <string>
using namespace std;

class Temperature {
private:
    double value;
    string unit;

public:
    void assign(double tempValue, const string& tempUnit) {
        if (tempUnit != "Celsius" && tempUnit != "Fahrenheit" && tempUnit != "Kelvin") {
            cout << "Invalid unit! Only Celsius, Fahrenheit, and Kelvin are allowed." << endl;
            return;
        }
        
        if (tempUnit == "Kelvin" && tempValue < 0) {
            cout << "Temperature cannot be below absolute zero (0 Kelvin)." << endl;
            return;
        } 
        else if (tempUnit == "Celsius" && tempValue < -273.15) {
            cout << "Temperature cannot be below absolute zero (-273.15 Celsius)." << endl;
            return;
        } 
        else if (tempUnit == "Fahrenheit" && tempValue < -459.67) {
            cout << "Temperature cannot be below absolute zero (-459.67 Fahrenheit)." << endl;
            return;
        }

        value = tempValue;
        unit = tempUnit;
    }

    double convert(const string& targetUnit) const {
        if (unit == targetUnit) {
            return value;
        }

        double convertedValue = value;

        if (unit == "Celsius") {
            if (targetUnit == "Fahrenheit") {
                convertedValue = (value * 9.0/5.0) + 32;
            } else if (targetUnit == "Kelvin") {
                convertedValue = value + 273.15;
            }
        } 
        else if (unit == "Fahrenheit") {
            if (targetUnit == "Celsius") {
                convertedValue = (value - 32) * 5.0/9.0;
            } else if (targetUnit == "Kelvin") {
                convertedValue = (value - 32) * 5.0/9.0 + 273.15;
            }
        } 
        else if (unit == "Kelvin") {
            if (targetUnit == "Celsius") {
                convertedValue = value - 273.15;
            } else if (targetUnit == "Fahrenheit") {
                convertedValue = (value - 273.15) * 9.0/5.0 + 32;
            }
        }

        return convertedValue;
    }

    void print() const {
        cout << "The temperature is " << value << " " << unit << "." << endl;
    }
};
