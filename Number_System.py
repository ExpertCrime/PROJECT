def decimal_to_binary(decimal_num):
    return bin(decimal_num)[2:]

def binary_to_decimal(binary_num):
    return int(binary_num, 2)

def decimal_to_hexadecimal(decimal_num):
    return hex(decimal_num)[2:].upper()

def hexadecimal_to_decimal(hexadecimal_num):
    return int(hexadecimal_num, 16)

def binary_to_hexadecimal(binary_num):
    decimal_num = binary_to_decimal(binary_num)
    return decimal_to_hexadecimal(decimal_num)

def hexadecimal_to_binary(hexadecimal_num):
    decimal_num = hexadecimal_to_decimal(hexadecimal_num)
    return decimal_to_binary(decimal_num)

def binary_to_octal(binary_num):
    decimal_num = binary_to_decimal(binary_num)
    return oct(decimal_num)[2:]

def octal_to_binary(octal_num):
    decimal_num = int(octal_num, 8)
    return decimal_to_binary(decimal_num)

def decimal_to_octal(decimal_num):
    return oct(decimal_num)[2:]

def octal_to_decimal(octal_num):
    return int(octal_num, 8)

def hexadecimal_to_octal(hexadecimal_num):
    decimal_num = hexadecimal_to_decimal(hexadecimal_num)
    return decimal_to_octal(decimal_num)

def octal_to_hexadecimal(octal_num):
    decimal_num = octal_to_decimal(octal_num)
    return decimal_to_hexadecimal(decimal_num)

def binary_addition(a, b):
    return bin(int(a, 2) + int(b, 2))[2:]

def binary_subtraction(a, b):
    return bin(int(a, 2) - int(b, 2))[2:]

def ones_complement_subtraction(a, b):
    b_complement = ''.join('1' if bit == '0' else '0' for bit in b)
    return binary_addition(a, b_complement)

def twos_complement_subtraction(a, b):
    b_complement = ''.join('1' if bit == '0' else '0' for bit in b)
    b_twos_complement = binary_addition(b_complement, '1')
    return binary_addition(a, b_twos_complement)

def binary_multiplication(a, b):
    return bin(int(a, 2) * int(b, 2))[2:]

def binary_division(a, b):
    return bin(int(a, 2) // int(b, 2))[2:]

def decimal_to_bcd(decimal_num):
    bcd_result = ''
    for digit in str(decimal_num):
        bcd_digit = bin(int(digit))[2:].zfill(4)
        bcd_result += bcd_digit
    return bcd_result

def hexadecimal_to_octal(hex_num):
    decimal_num = int(hex_num, 16)
    octal_num = oct(decimal_num)[2:]
    return octal_num

def octal_to_hexadecimal(octal_num):
    decimal_num = int(octal_num, 8)
    hex_num = hex(decimal_num)[2:]
    return hex_num

def character_to_ascii(character):
    return ord(character)

def repeat():
    while True:
        print("\n1. Decimal To Binary")
        print("2. Binary to Decimal")
        print("3. Decimal To Hexadecimal")
        print("4. Hexadecimal to Decimal")
        print("5. Binary to Hexadecimal")
        print("6. Hexadecimal to Binary")
        print("7. Binary to octal")
        print("8. octal to binary")
        print("9. decimal to octal")
        print("10. octal to decimal")
        print("11. hexadecimal to octal")
        print("12. octal to hexadecimal")
        print("13. Binary Addition")
        print("14. Binary Subtraction")
        print("15. Binary Subtraction by 1’s Complement")
        print("16. Binary Subtraction by 2’s Complement")
        print("17. Binary Multiplication")
        print("18. Binary Division")
        print("19. Decimal To BCD")
        print("20. Hexadecimal To Octal")
        print("21. Octal To Hexadecimal")
        print("22. Character to ASCII")
        print("23. Exit")

        choice = int(input("Enter your choice (1-23): "))

        if choice == 1:
            decimal_num = int(input("Enter a decimal number: "))
            print("Binary equivalent:", decimal_to_binary(decimal_num))
        elif choice == 2:
            binary_num = input("Enter a binary number: ")
            print("Decimal equivalent:", binary_to_decimal(binary_num))
        elif choice == 3:
            decimal_num = int(input("Enter a decimal number: "))
            print("Hexadecimal equivalent:", decimal_to_hexadecimal(decimal_num))
        elif choice == 4:
            hexadecimal_num = input("Enter a hexadecimal number: ")
            print("Decimal equivalent:", hexadecimal_to_decimal(hexadecimal_num))
        elif choice == 5:
            binary_num = input("Enter a binary number: ")
            print("Hexadecimal equivalent:", binary_to_hexadecimal(binary_num))
        elif choice == 6:
            hexadecimal_num = input("Enter a hexadecimal number: ")
            print("Binary equivalent:", hexadecimal_to_binary(hexadecimal_num))
        elif choice == 7:
            binary_num = input("Enter a binary number: ")
            print("Octal equivalent:", binary_to_octal(binary_num))
        elif choice == 8:
            octal_num = input("Enter an octal number: ")
            print("Binary equivalent:", octal_to_binary(octal_num))
        elif choice == 9:
            decimal_num = int(input("Enter a decimal number: "))
            print("Octal equivalent:", decimal_to_octal(decimal_num))
        elif choice == 10:
            octal_num = input("Enter an octal number: ")
            print("Decimal equivalent:", octal_to_decimal(octal_num))
        elif choice == 11:
            hexadecimal_num = input("Enter a hexadecimal number: ")
            print("Octal equivalent:", hexadecimal_to_octal(hexadecimal_num))
        elif choice == 12:
            octal_num = input("Enter an octal number: ")
            print("Hexadecimal equivalent:", octal_to_hexadecimal(octal_num))
        elif choice == 13:
            a = input("Enter the first binary number: ")
            b = input("Enter the second binary number: ")
            print("Result:", binary_addition(a, b))
        elif choice == 14:
            a = input("Enter the first binary number: ")
            b = input("Enter the second binary number: ")
            print("Result:", binary_subtraction(a, b))
        elif choice == 15:
            a = input("Enter the first binary number: ")
            b = input("Enter the second binary number: ")
            print("Result:", ones_complement_subtraction(a, b))
        elif choice == 16:
            a = input("Enter the first binary number: ")
            b = input("Enter the second binary number: ")
            print("Result:", twos_complement_subtraction(a, b))
        elif choice == 17:
            a = input("Enter the first binary number: ")
            b = input("Enter the second binary number: ")
            print("Result:", binary_multiplication(a, b))
        elif choice == 18:
            a = input("Enter the first binary number: ")
            b = input("Enter the second binary number: ")
            print("Result:", binary_division(a, b))
        elif choice == 19:
            decimal_num = int(input("Enter the decimal number: "))
            print("Result:", decimal_to_bcd(decimal_num))
        elif choice == 20:
            hex_num = input("Enter the hexadecimal number: ")
            print("Result:", hexadecimal_to_octal(hex_num))
        elif choice == 21:
            octal_num = input("Enter the octal number: ")
            print("Result:", octal_to_hexadecimal(octal_num))
        elif choice == 22:
            character = input("Enter a character: ")
            ascii_code = character_to_ascii(character)
            print(f"ASCII code of '{character}' is: {ascii_code}")  
        elif choice == 23:
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please enter a number between 1 and 23.")

if __name__ == "__main__":
    repeat()
