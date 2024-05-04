#include <iostream>
#include <cmath>

void printSquareRoot(int n) {
    // Find the integer part of the square root
    int integerPart = sqrt(n);
    
    // Find the non-perfect square part
    int nonPerfectPart = n - integerPart * integerPart;
    
    // Print the result
    if (integerPart != 0) {
        std::cout << integerPart;
        if (nonPerfectPart != 0) {
            std::cout << "√" << nonPerfectPart;
        }
    } else {
        std::cout << nonPerfectPart;
    }
}

void printCubeRoot(int n) {
    // Find the integer part of the cube root
    int integerPart = cbrt(n);
    
    // Find the non-perfect cube part
    int nonPerfectPart = n - integerPart * integerPart * integerPart;
    
    // Print the result
    if (integerPart != 0) {
        std::cout << integerPart;
        if (nonPerfectPart != 0) {
            std::cout << "√" << nonPerfectPart;
        }
    } else {
        std::cout << nonPerfectPart;
    }
}

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    
    std::cout << "Square root in the form of a√b: ";
    printSquareRoot(number);
    std::cout << std::endl;
    
    std::cout << "Cube root in the form of a√b: ";
    printCubeRoot(number);
    std::cout << std::endl;
    
    return 0;
}