#include <iostream>
#include <cmath>
using namespace std;
double f(double x) {
    return sqrt(x); // ∫ x dx
}
int main() {
    double a, b, h, integral;
    int n;
    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;
    cout << "Enter number of subintervals (n, multiple of 3): ";
    cin >> n;
    if (n % 3 != 0) {
        cout << "Error: Number of subintervals must be a multiple of 3." << endl;
        return 1;
    }
    h = (b - a) / n;
    integral = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 3 == 0)
            integral += 2 * f(x);
        else
            integral += 3 * f(x);
    }
    integral *= (3 * h / 8);
    cout << "Approximate integral using Simpson's 3/8 Rule: " << integral << endl;
    return 0;
}
