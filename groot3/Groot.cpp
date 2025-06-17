#include <iostream>
#include <cmath>

// Ignore all characters in stdin up to and including
void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * Check if extraction failed and clear stdin if so
 *
 * @return wether the extraction failed
 */
bool clearFailedExtraction() {
    if (!std::cin) {
        std::cin.clear();
        ignoreLine();
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
    return !std::cin.eof() && std::cin.peek() != '\n';
}

/**
 * Get a double number
 *
 * @return the number
 */
double getDouble() {
    double number = 0;
    while (true) {
        std::cout << "Enter a number: ";
        std::cin >> number;
        // clearFailedExtraction() will return true if std::cin.fail() (or simply !std::cin) i.e. if the extraction failed
        if (clearFailedExtraction()) {
            std::cout << "Invalid input. Please try again" << std::endl;
            continue;
        }
        if (hasUnextractedInput()) {
            ignoreLine();
            std::cout << "Invalid input. Please try again" << std::endl;
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
        std::cout << "Number must be non-negative!" << std::endl;
        number = getDouble();
    }

    squareRoot = std::sqrt(number);
    std::cout << "The sqaure root of the number is: " << squareRoot << std::endl;

    return 0;
}