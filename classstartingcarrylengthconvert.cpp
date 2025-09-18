#include <iostream>
#include <cstring>
using namespace std;

class String {
    char str[100];
public:
    String() { strcpy(str, ""); }
    String(const char s[]) { strcpy(str, s); }

    // Overload + for concatenation
    String operator+(String s) {
        String temp;
        strcpy(temp.str, str);
        strcat(temp.str, s.str);
        return temp;
    }

    // Overload = for copy
    String operator=(String s) {
        strcpy(str, s.str);
        return *this;
    }

    // Overload <= for comparison
    bool operator<=(String s) {
        return strcmp(str, s.str) <= 0;
    }

    // Length function
    int length() {
        return strlen(str);
    }

    // To lowercase
    void tolower() {
        for (int i = 0; str[i] != '\0'; i++)
            if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 32;
    }

    // To uppercase
    void toupper() {
        for (int i = 0; str[i] != '\0'; i++)
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] -= 32;
    }

    // Display
    void display() {
        cout << str;
    }
};

int main() {
    String s1("MALIK"), s2("BOOKS"), s3;
    
    cout << "Concatenation: ";
    s3 = s1 + s2;
    s3.display();
    cout << endl;

    cout << "Copy: ";
    s3 = s1;
    s3.display();
    cout << endl;

    cout << "Comparison (s1 <= s2): " << (s1 <= s2) << endl;

    cout << "Length of s1: " << s1.length() << endl;

    cout << "Lowercase of s1: ";
    s1.tolower();
    s1.display();
    cout << endl;

    cout << "Uppercase of s2: ";
    s2.toupper();
    s2.display();
    cout << endl;

    return 0;
}