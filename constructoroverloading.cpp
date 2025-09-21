#include <iostream>
using namespace std;

class Rectangle {
    int length, breadth;

public:
    
    Rectangle() {
        length = 5;
        breadth = 3;
    }

  
    Rectangle(int l, int b) {
        length = l;
        breadth = b;
    }

  
    void area() {
        cout << "Area = " << (length * breadth) << endl;
    }
};

int main() {
    Rectangle r1;          
    Rectangle r2(10, 7); 

    r1.area();
    r2.area();

    return 0;
}