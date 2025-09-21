#include <iostream>
using namespace std;

class Book {
    string title;
    float price;

public:
    void input() {
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter price: ";
        cin >> price;
    }

    void display() {
        cout << "Title: " << title << ", Price: " << price << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of books: ";
    cin >> n;

    Book* b = new Book[n];

    for (int i = 0; i < n; i++) {
        cout << "\nBook " << i + 1 << " details:\n";
        b[i].input();
    }

    cout << "\n--- Book Details ---\n";
    for (int i = 0; i < n; i++) {
        b[i].display();
    }

    delete[] b;  
    return 0;
}