#include <iostream>

// Ignore all characters in stdin up to and including
void ignoreLine();

/**
 * Check if extraction failed and clear stdin if so

 * @return wether the extraction failed
 */
bool clearFailedExtraction();

/**
 * Get a double number

 * @return the number
 */
double getDouble();

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool clearFailedExtraction()
{
    if (!std::cin)
    {
        std::cin.clear();
        ignoreLine();
        return true;
    }

    return false;
}

double getDouble()
{
    double number = 0;
    while (true)
    {
        std::cout << "Enter a number: ";
        std::cin >> number;

        if (clearFailedExtraction())
        {
            std::cout << "Invalid input. Please try again\n";
            continue;
        }

        return number;
    }
}

int main()
{
    double number = 0;
    double squareRoot = 0;

    number = getDouble();
    while (number < 0)
    {
        std::cout << "Number must be non-negative!\n";
        number = getDouble();
    }

    squareRoot = std::sqrt(number);
    std::cout << "The sqaure root of the number is: " << squareRoot << std::endl;

    return 0;
}