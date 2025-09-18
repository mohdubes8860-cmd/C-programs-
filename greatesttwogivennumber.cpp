#include <iostream>
using namespace std;

class B; // Forward declaration

class A {
    int num1;
public:
    void setData(int x) {
        num1 = x;
    }
    friend void findGreatest(A, B); // Friend function
};

class B {
    int num2;
public:
    void setData(int y) {
        num2 = y;
    }
    friend void findGreatest(A, B); // Friend function
};

// Friend function definition
void findGreatest(A a, B b) {
    if (a.num1 > b.num2)
        cout << "Greatest number is: " << a.num1 << endl;
    else if (b.num2 > a.num1)
        cout << "Greatest number is: " << b.num2 << endl;
    else
        cout << "Both numbers are equal." << endl;
}

int main() {
    A obj1;
    B obj2;

    int x, y;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;

    obj1.setData(x);
    obj2.setData(y);

    findGreatest(obj1, obj2);

    return 0;
}