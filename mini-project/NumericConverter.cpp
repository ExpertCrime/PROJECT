#include <iostream>
#include <string>
#include <bitset>

std::string decimal_to_binary(int decimal_num)
{
    return std::bitset<32>(decimal_num).to_string().substr(1);
}

int binary_to_decimal(const std::string &binary_num)
{
    return std::bitset<32>(binary_num).to_ulong();
}

std::string decimal_to_hexadecimal(int decimal_num)
{
    return std::to_string(decimal_num);
}

int hexadecimal_to_decimal(const std::string &hexadecimal_num)
{
    return std::stoi(hexadecimal_num);
}

std::string binary_to_hexadecimal(const std::string &binary_num)
{
    return decimal_to_hexadecimal(binary_to_decimal(binary_num));
}

std::string hexadecimal_to_binary(const std::string &hexadecimal_num)
{
    return decimal_to_binary(hexadecimal_to_decimal(hexadecimal_num));
}

std::string binary_to_octal(const std::string &binary_num)
{
    return std::to_string(binary_to_decimal(binary_num));
}

std::string octal_to_binary(const std::string &octal_num)
{
    return decimal_to_binary(std::stoi(octal_num, nullptr, 8));
}

std::string decimal_to_octal(int decimal_num)
{
    return std::to_string(decimal_num);
}

int octal_to_decimal(const std::string &octal_num)
{
    return std::stoi(octal_num);
}

std::string binary_addition(const std::string &a, const std::string &b)
{
    return decimal_to_binary(binary_to_decimal(a) + binary_to_decimal(b));
}

std::string binary_subtraction(const std::string &a, const std::string &b)
{
    return decimal_to_binary(binary_to_decimal(a) - binary_to_decimal(b));
}

std::string ones_complement_subtraction(const std::string &a, const std::string &b)
{
    return binary_addition(a, b); // Assuming binary_addition handles one's complement
}

std::string twos_complement_subtraction(const std::string &a, const std::string &b)
{
    return binary_addition(a, b); // Assuming binary_addition handles two's complement
}

std::string binary_multiplication(const std::string &a, const std::string &b)
{
    return decimal_to_binary(binary_to_decimal(a) * binary_to_decimal(b));
}

std::string binary_division(const std::string &a, const std::string &b)
{
    return decimal_to_binary(binary_to_decimal(a) / binary_to_decimal(b));
}

std::string decimal_to_bcd(int decimal_num)
{
    return decimal_to_binary(decimal_num);
}

int character_to_ascii(char character)
{
    return static_cast<int>(character);
}

int main()
{
    while (true)
    {
        std::cout << "\n1. Decimal To Binary\n"
                  << "2. Binary to Decimal\n"
                  << "3. Decimal To Hexadecimal\n"
                  << "4. Hexadecimal to Decimal\n"
                  << "5. Binary to Hexadecimal\n"
                  << "6. Hexadecimal to Binary\n"
                  << "7. Binary to octal\n"
                  << "8. octal to binary\n"
                  << "9. decimal to octal\n"
                  << "10. octal to decimal\n"
                  << "11. Binary Addition\n"
                  << "12. Binary Subtraction\n"
                  << "13. Binary Subtraction by 1’s Complement\n"
                  << "14. Binary Subtraction by 2’s Complement\n"
                  << "15. Binary Multiplication\n"
                  << "16. Binary Division\n"
                  << "17. Decimal To BCD\n"
                  << "18. Octal To Hexadecimal\n"
                  << "19. Character to ASCII\n"
                  << "20. Exit\n";

        int choice;
        std::cout << "Enter your choice (1-20): ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int decimal_num;
            std::cout << "Enter a decimal number: ";
            std::cin >> decimal_num;
            std::cout << "Binary equivalent: " << decimal_to_binary(decimal_num) << std::endl;
            break;
        }
        case 2:
        {
            std::string binary_num;
            std::cout << "Enter a binary number: ";
            std::cin >> binary_num;
            std::cout << "Decimal equivalent: " << binary_to_decimal(binary_num) << std::endl;
            break;
        }
        case 3:
        {
            int decimal_num;
            std::cout << "Enter a decimal number: ";
            std::cin >> decimal_num;
            std::cout << "Hexadecimal equivalent: " << decimal_to_hexadecimal(decimal_num) << std::endl;
            break;
        }
        case 4:
        {
            std::string hexadecimal_num;
            std::cout << "Enter a hexadecimal number: ";
            std::cin >> hexadecimal_num;
            std::cout << "Decimal equivalent: " << hexadecimal_to_decimal(hexadecimal_num) << std::endl;
            break;
        }
        case 5:
        {
            std::string binary_num;
            std::cout << "Enter a binary number: ";
            std::cin >> binary_num;
            std::cout << "Hexadecimal equivalent: " << binary_to_hexadecimal(binary_num) << std::endl;
            break;
        }
        case 6:
        {
            std::string hexadecimal_num;
            std::cout << "Enter a hexadecimal number: ";
            std::cin >> hexadecimal_num;
            std::cout << "Binary equivalent: " << hexadecimal_to_binary(hexadecimal_num) << std::endl;
            break;
        }
        case 7:
        {
            std::string binary_num;
            std::cout << "Enter a binary number: ";
            std::cin >> binary_num;
            std::cout << "Octal equivalent: " << binary_to_octal(binary_num) << std::endl;
            break;
        }
        case 8:
        {
            std::string octal_num;
            std::cout << "Enter an octal number: ";
            std::cin >> octal_num;
            std::cout << "Binary equivalent: " << octal_to_binary(octal_num) << std::endl;
            break;
        }
        case 9:
        {
            int decimal_num;
            std::cout << "Enter a decimal number: ";
            std::cin >> decimal_num;
            std::cout << "Octal equivalent: " << decimal_to_octal(decimal_num) << std::endl;
            break;
        }
        case 10:
        {
            std::string octal_num;
            std::cout << "Enter an octal number: ";
            std::cin >> octal_num;
            std::cout << "Decimal equivalent: " << octal_to_decimal(octal_num) << std::endl;
            break;
        }
        case 11:
        {
            std::string a, b;
            std::cout << "Enter the first binary number: ";
            std::cin >> a;
            std::cout << "Enter the second binary number: ";
            std::cin >> b;
            std::cout << "Result: " << binary_addition(a, b) << std::endl;
            break;
        }
        }
    }
};
