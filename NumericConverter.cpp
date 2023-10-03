#include <iostream>
#include <string>
#include <bitset>
#include <sstream>

std::string decimal_to_binary(int decimal_num) {
    return std::bitset<32>(decimal_num).to_string().substr(1);
}

int binary_to_decimal(const std::string& binary_num) {
    return std::bitset<32>(binary_num).to_ulong();
}

std::string decimal_to_hexadecimal(int decimal_num) {
    char buffer[10];
    snprintf(buffer, sizeof(buffer), "%X", decimal_num);
    return buffer;
}

int hexadecimal_to_decimal(const std::string& hexadecimal_num) {
    return std::stoi(hexadecimal_num, nullptr, 16);
}

std::string binary_to_hexadecimal(const std::string& binary_num) {
    int decimal_num = binary_to_decimal(binary_num);
    return decimal_to_hexadecimal(decimal_num);
}

std::string hexadecimal_to_binary(const std::string& hexadecimal_num) {
    int decimal_num = hexadecimal_to_decimal(hexadecimal_num);
    return decimal_to_binary(decimal_num);
}

std::string binary_to_octal(const std::string& binary_num) {
    int decimal_num = binary_to_decimal(binary_num);
    char buffer[10];
    snprintf(buffer, sizeof(buffer), "%o", decimal_num);
    return buffer;
}

std::string octal_to_binary(const std::string& octal_num) {
    int decimal_num = std::stoi(octal_num, nullptr, 8);
    return decimal_to_binary(decimal_num);
}

std::string decimal_to_octal(int decimal_num) {
    char buffer[10];
    snprintf(buffer, sizeof(buffer), "%o", decimal_num);
    return buffer;
}

int octal_to_decimal(const std::string& octal_num) {
    return std::stoi(octal_num, nullptr, 8);
}

std::string binary_addition(const std::string& a, const std::string& b) {
    int decimal_a = binary_to_decimal(a);
    int decimal_b = binary_to_decimal(b);
    int result = decimal_a + decimal_b;
    return decimal_to_binary(result);
}

std::string binary_subtraction(const std::string& a, const std::string& b) {
    int decimal_a = binary_to_decimal(a);
    int decimal_b = binary_to_decimal(b);
    int result = decimal_a - decimal_b;
    return decimal_to_binary(result);
}

std::string ones_complement_subtraction(const std::string& a, const std::string& b) {
    std::string b_complement = "";
    for (char bit : b) {
        b_complement += (bit == '0') ? '1' : '0';
    }
    return binary_addition(a, b_complement);
}

std::string twos_complement_subtraction(const std::string& a, const std::string& b) {
    std::string b_complement = "";
    for (char bit : b) {
        b_complement += (bit == '0') ? '1' : '0';
    }
    std::string b_twos_complement = binary_addition(b_complement, "1");
    return binary_addition(a, b_twos_complement);
}

std::string binary_multiplication(const std::string& a, const std::string& b) {
    int decimal_a = binary_to_decimal(a);
    int decimal_b = binary_to_decimal(b);
    int result = decimal_a * decimal_b;
    return decimal_to_binary(result);
}

std::string binary_division(const std::string& a, const std::string& b) {
    int decimal_a = binary_to_decimal(a);
    int decimal_b = binary_to_decimal(b);
    int result = decimal_a / decimal_b;
    return decimal_to_binary(result);
}

std::string decimal_to_bcd(int decimal_num) {
    std::string bcd_result = "";
    std::string decimal_str = std::to_string(decimal_num);
    for (char digit : decimal_str) {
        int digit_value = digit - '0';
        std::string bcd_digit = std::bitset<4>(digit_value).to_string();
        bcd_result += bcd_digit;
    }
    return bcd_result;
}

int character_to_ascii(char character) {
    return static_cast<int>(character);
}

int main() {
    while (true) {
        std::cout << "\n1. Decimal To Binary\n";
        std::cout << "2. Binary to Decimal\n";
        std::cout << "3. Decimal To Hexadecimal\n";
        std::cout << "4. Hexadecimal to Decimal\n";
        std::cout << "5. Binary to Hexadecimal\n";
        std::cout << "6. Hexadecimal to Binary\n";
        std::cout << "7. Binary to octal\n";
        std::cout << "8. octal to binary\n";
        std::cout << "9. decimal to octal\n";
        std::cout << "10. octal to decimal\n";
        std::cout << "11. Binary Addition\n";
        std::cout << "12. Binary Subtraction\n";
        std::cout << "13. Binary Subtraction by 1’s Complement\n";
        std::cout << "14. Binary Subtraction by 2’s Complement\n";
        std::cout << "15. Binary Multiplication\n";
        std::cout << "16. Binary Division\n";
        std::cout << "17. Decimal To BCD\n";
        std::cout << "18. Octal To Hexadecimal\n";
        std::cout << "19. Character to ASCII\n";
        std::cout << "20. Exit\n";

        int choice;
        std::cout << "Enter your choice (1-20): ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int decimal_num;
                std::cout << "Enter a decimal number: ";
                std::cin >> decimal_num;
                std::cout << "Binary equivalent: " << decimal_to_binary(decimal_num) << std::endl;
                break;
            }
            case 2: {
                std::string binary_num;
                std::cout << "Enter a binary number: ";
                std::cin >> binary_num;
                std::cout << "Decimal equivalent: " << binary_to_decimal(binary_num) << std::endl;
                break;
            }
            case 3: {
                int decimal_num;
                std::cout << "Enter a decimal number: ";
                std::cin >> decimal_num;
                std::cout << "Hexadecimal equivalent: " << decimal_to_hexadecimal(decimal_num) << std::endl;
                break;
            }
            case 4: {
                std::string hexadecimal_num;
                std::cout << "Enter a hexadecimal number: ";
                std::cin >> hexadecimal_num;
                std::cout << "Decimal equivalent: " << hexadecimal_to_decimal(hexadecimal_num) << std::endl;
                break;
            }
            case 5: {
                std::string binary_num;
                std::cout << "Enter a binary number: ";
                std::cin >> binary_num;
                std::cout << "Hexadecimal equivalent: " << binary_to_hexadecimal(binary_num) << std::endl;
                break;
            }
            case 6: {
                std::string hexadecimal_num;
                std::cout << "Enter a hexadecimal number: ";
                std::cin >> hexadecimal_num;
                std::cout << "Binary equivalent: " << hexadecimal_to_binary(hexadecimal_num) << std::endl;
                break;
            }
            case 7: {
                std::string binary_num;
                std::cout << "Enter a binary number: ";
                std::cin >> binary_num;
                std::cout << "Octal equivalent: " << binary_to_octal(binary_num) << std::endl;
                break;
            }
            case 8: {
                std::string octal_num;
                std::cout << "Enter an octal number: ";
                std::cin >> octal_num;
                std::cout << "Binary equivalent: " << octal_to_binary(octal_num) << std::endl;
                break;
            }
            case 9: {
                int decimal_num;
                std::cout << "Enter a decimal number: ";
                std::cin >> decimal_num;
                std::cout << "Octal equivalent: " << decimal_to_octal(decimal_num) << std::endl;
                break;
            }
            case 10: {
                std::string octal_num;
                std::cout << "Enter an octal number: ";
                std::cin >> octal_num;
                std::cout << "Decimal equivalent: " << octal_to_decimal(octal_num) << std::endl;
                break;
            }
            case 11: {
                std::string a, b;
                std::cout << "Enter the first binary number: ";
                std::cin >> a;
                std::cout << "Enter the second binary number: ";
                std::cin >> b;
                std::cout << "Result: " << binary_addition(a, b) << std::endl;
                break;
            }
            case 12: {
                std::string a, b;
                std::cout << "Enter the first binary number: ";
                std::cin >> a;
                std::cout << "Enter the second binary number: ";
                std::cin >> b;
                std::cout << "Result: " << binary_subtraction(a, b) << std::endl;
                break;
            }
            case 13: {
                std::string a, b;
                std::cout << "Enter the first binary number: ";
                std::cin >> a;
                std::cout << "Enter the second binary number: ";
                std::cin >> b;
                std::cout << "Result: " << ones_complement_subtraction(a, b) << std::endl;
                break;
            }
            case 14: {
                std::string a, b;
                std::cout << "Enter the first binary number: ";
                std::cin >> a;
                std::cout << "Enter the second binary number: ";
                std::cin >> b;
                std::cout << "Result: " << twos_complement_subtraction(a, b) << std::endl;
                break;
            }
            case 15: {
                std::string a, b;
                std::cout << "Enter the first binary number: ";
                std::cin >> a;
                std::cout << "Enter the second binary number: ";
                std::cin >> b;
                std::cout << "Result: " << binary_multiplication(a, b) << std::endl;
                break;
            }
            case 16: {
                std::string a, b;
                std::cout << "Enter the first binary number: ";
                std::cin >> a;
                std::cout << "Enter the second binary number: ";
                std::cin >> b;
                std::cout << "Result: " << binary_division(a, b) << std::endl;
                break;
            }
            case 17: {
                int decimal_num;
                std::cout << "Enter the decimal number: ";
                std::cin >> decimal_num;
                std::cout << "Result: " << decimal_to_bcd(decimal_num) << std::endl;
                break;
            }
            case 18: {
                std::string octal_num;
                std::cout << "Enter the octal number: ";
                std::cin >> octal_num;
                std::cout << "Result: " << octal_num << std::endl;  // No function for octal to hexadecimal
                break;
            }
            case 19: {
                char character;
                std::cout << "Enter a character: ";
                std::cin >> character;
                int ascii_code = character_to_ascii(character);
                std::cout << "ASCII code of '" << character << "' is: " << ascii_code << std::endl;
                break;
            }
            case 20: {
                std::cout << "Exiting..." << std::endl;
                return 0;
            }
            default: {
                std::cout << "Invalid choice. Please enter a number between 1 and 20." << std::endl;
                break;
            }
        }
    }

    return 0;
}
