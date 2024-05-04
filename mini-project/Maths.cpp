#include <iostream>
#include <cmath>
int main(){

    int num;
    std::cout << "1. Square\n" "2. Cube\n" "3. Square Root\n" "4. Cube Root\n";
    std::cout << "\nEnter an option: ";
    std::cin >> num;
    std::cout << std::endl;
    
    int num2;
    std::cout << "Enter an number: ";
    std::cin >> num2; 
    
    if (num == 1)
    {
        std::cout << "The square of this number is: " << pow(num2, 2);
    }

    else if (num == 2)
    {
        std::cout << "The cube of this number is: " << pow(num2, 3);
    }
    
    else if (num == 3)
    {
        std::cout << "The Square root of this number is: " << sqrt(num2);
    }

    else if (num == 4)
    {
        std::cout << "The Cube root of this programe: " << pow(num2, 1.0/3);
    }
        
    else
        std::cout << "Invalid Input";
}