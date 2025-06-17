#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::sqrt;
using std::numeric_limits;
using std::streamsize;

// Ignore all characters in stdin up to and including
void ignoreLine() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * Check if extraction failed and clear stdin if so
 *
 * @return wether the extraction failed
 */
bool clearFailedExtraction() {
    if (!cin) {
        cin.clear();
        return true;
    }

    return false;
}

/**
 * Check whether stdin has unextracted input
 *  
 * @return whether stdin has unextracted input
 */
bool hasUnextractedInput() {
    return !cin.eof() && cin.peek() != '\n';
}

/**
 * Get a double number
 *
 * @return the number
 */
double getDouble() {
    double number = 0;
    while (true) {
        cout << "Enter a number: ";
        cin >> number;
        // clearFailedExtraction() will return true if std::cin.fail() (or simply !std::cin) i.e. if the extraction failed
        if (clearFailedExtraction() || hasUnextractedInput()) {
            ignoreLine();
            cout << "Invalid input. Please try again" << endl;
            continue;
        }

        return number;
    }
}

int main() {
    double number = 0;
    double squareRoot = 0;

    number = getDouble();
    while (number < 0) {
        cout << "Number must be non-negative!" << endl;
        number = getDouble();
    }

    squareRoot = sqrt(number);
    cout << "The sqaure root of the number is: " << squareRoot << endl;

    return 0;
}