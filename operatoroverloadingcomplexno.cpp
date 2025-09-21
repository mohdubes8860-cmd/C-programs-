#include <iostream>
using namespace std;

class Complex {
    float real, imag;

public:
    
    Complex(float r = 0, float i = 0) {
        real = r;
        imag = i;
    }


    Complex operator+(Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(Complex c) {
        return Complex(real - c.real, imag - c.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(4, 5), c2(2, 3);

    Complex sum = c1 + c2;   
    Complex diff = c1 - c2; 

    cout << "First Complex: ";
    c1.display();
    cout << "Second Complex: ";
    c2.display();

    cout << "Addition: ";
    sum.display();

    cout << "Subtraction: ";
    diff.display();

    return 0;
}