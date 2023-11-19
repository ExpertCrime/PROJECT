#include <iostream>
#include <cstdlib> // for atoi function
using namespace std;

int main()
{
    string input;
    while (true)
    {
        cout << "Type 'cls', 'exit', 'clear' to exit " << endl;
        cout << "Enter an integer : ";
        cin >> input;

        if (input == "exit" || input == "cls" || input == "clear")
        {
            cout << "Exiting the program." << endl;
            break;
        }

        // Check if input is a number
        bool isNumber = true;
        for (char digit : input)
        {
            if (!isdigit(digit))
            {
                isNumber = false;
                break;
            }
        }

        // If input is a number, convert to integer and check even or odd
        if (isNumber)
        {
            int number = atoi(input.c_str());
            string result = (number % 2 == 0) ? "even" : "odd";
            cout << "The number is " << result << "." << endl;
        }
        else
        {
            cout << "Only numbers are allowed. Please enter a valid integer." << endl;
        }
    }

    return 0;
}