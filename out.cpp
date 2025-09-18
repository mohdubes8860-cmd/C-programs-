#include <iostream>
using namespace std; // MOHD UBES

class Complex {
    float real, imag;

public:
    // 1. Default constructor
    Complex() {
        real = 0;
        imag = 0;
    }

    // 2. Single parameter constructor
    Complex(float val) {
        real = val;
        imag = val;
    }

    // 3. Two parameter constructor
    Complex(float r, float i) {
        real = r;
        imag = i;
    }

    // Function to add two complex numbers
    Complex add(Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    // Function to display complex number
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1;           // Default constructor
    Complex c2(5);        // Single parameter constructor
    Complex c3(3, 4);     // Two parameter constructor

    cout << "First Complex Number: ";
    c1.display();
    cout << "Second Complex Number: ";
    c2.display();
    cout << "Third Complex Number: ";
    c3.display();

    // Add c2 and c3
    Complex sum = c2.add(c3);
    cout << "Sum of Second and Third: ";
    sum.display();

    return 0;
}
