#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to convert Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

// Function to convert Kelvin to Celsius
double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

// Function to convert Fahrenheit to Kelvin
double fahrenheitToKelvin(double fahrenheit) {
    return celsiusToKelvin(fahrenheitToCelsius(fahrenheit));
}

// Function to convert Kelvin to Fahrenheit
double kelvinToFahrenheit(double kelvin) {
    return celsiusToFahrenheit(kelvinToCelsius(kelvin));
}

// Function to handle the conversion based on input and output scales
double convertTemperature(double value, string fromScale, string toScale) {
    // Convert scales to lowercase for uniformity
    for (char &c : fromScale) {
        c = tolower(c);
    }
    for (char &c : toScale) {
        c = tolower(c);
    }

    if (fromScale == toScale) {
        return value;
    }

    if (fromScale == "celsius") {
        if (toScale == "fahrenheit") {
            return celsiusToFahrenheit(value);
        } else if (toScale == "kelvin") {
            return celsiusToKelvin(value);
        }
    } else if (fromScale == "fahrenheit") {
        if (toScale == "celsius") {
            return fahrenheitToCelsius(value);
        } else if (toScale == "kelvin") {
            return fahrenheitToKelvin(value);
        }
    } else if (fromScale == "kelvin") {
        if (toScale == "celsius") {
            return kelvinToCelsius(value);
        } else if (toScale == "fahrenheit") {
            return kelvinToFahrenheit(value);
        }
    } else {
        cout << "Invalid temperature scale provided." << endl;
        return value; 
    }
    
    return value;
}

int main() {
    double value;
    string fromScale, toScale;

    cout << "Enter the temperature value: ";
    cin >> value;

    cout << "Enter the scale to convert from (Celsius, Fahrenheit, Kelvin): ";
    cin >> fromScale;

    cout << "Enter the scale to convert to (Celsius, Fahrenheit, Kelvin): ";
    cin >> toScale;

    // Check for valid scales
    if (fromScale != "Celsius" && fromScale != "Fahrenheit" && fromScale != "Kelvin" &&
        fromScale != "celsius" && fromScale != "fahrenheit" && fromScale != "kelvin") {
        cout << "Invalid from-scale. Valid scales are 'Celsius', 'Fahrenheit', and 'Kelvin'." << endl;
        return 1;
    }

    if (toScale != "Celsius" && toScale != "Fahrenheit" && toScale != "Kelvin" &&
        toScale != "celsius" && toScale != "fahrenheit" && toScale != "kelvin") {
        cout << "Invalid to-scale. Valid scales are 'Celsius', 'Fahrenheit', and 'Kelvin'." << endl;
        return 1;
    }

    double convertedValue = convertTemperature(value, fromScale, toScale);
    cout << value << " " << fromScale << " is " << convertedValue << " " << toScale << endl;

    return 0;
}
