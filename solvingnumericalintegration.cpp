#include <iostream>
#include <cmath>
using namespace std;

// Define the function f(x)
double f(double x) {
    return 1 / (1 + x * x);
}

int main() {
    double a, b; // limits
    int n;       // number of intervals

    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;
    cout << "Enter number of intervals (n): ";
    cin >> n;

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    // Apply trapezoidal rule
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += 2 * f(x);
    }

    double result = (h / 2) * sum;

    cout << "Approximate value of integral = " << result << endl;

    return 0;
}
