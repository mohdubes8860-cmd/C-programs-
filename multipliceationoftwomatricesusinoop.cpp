#include <iostream>
using namespace std;

// Function to calculate power with default exponent = 2
double power(double base, int exponent = 2) {
    double result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int main() {
    double num;
    int exp;

    cout << "Enter a number: ";
    cin >> num;

    cout << "Enter exponent (or press enter to calculate square): ";
    if (cin.peek() == '\n') { // If user presses enter directly
        cin.clear();
    }

    cout << "\nResult (Square): " << power(num) << endl;

    cout << "Now enter an exponent: ";
    cin >> exp;
    cout << "Result (" << num << "^" << exp << "): " << power(num, exp) << endl;

    return 0;
}