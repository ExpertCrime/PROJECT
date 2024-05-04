#include <iostream>
#include <limits>

int main() {
    int userInput;

    // Prompt user for input
    std::cout << "Enter an integer with a maximum of four digits: ";

    // Input validation loop
    while (true) {
        // Check if the input is an integer
        if (std::cin >> userInput) {
            // Check if the integer has at most four digits
            if (userInput >= 1000 && userInput <= 9999) {
                break; // Exit the loop if the input is valid
            } else {
                std::cout << "Error: Please enter an integer with a maximum of four digits." << std::endl;
            }
        } else {
            // Clear the input buffer to handle non-integer input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: Please enter a valid integer." << std::endl;
        }

        // Prompt the user to try again
        std::cout << "Enter an integer with a maximum of four digits: ";
    }

    // Display the valid input
    std::cout << "You entered: " << userInput << std::endl;

    return 0;
}
