#include <bits/stdc++.h>
using namespace std;
// Function to calculate factorial
int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}
// Newton Backward Interpolation Function
double newtonBackward(double x[], double y[], int n, double value) {
    double h = x[1] - x[0];         // Step size (assumed equal interval)
    double u = (value - x[n-1]) / h;
    // Building Backward Difference Table
    double diff[n][n];
    for (int i = 0; i < n; i++)
        diff[i][0] = y[i];

    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            diff[i][j] = diff[i][j-1] - diff[i-1][j-1];
        }
    }
    // Apply Newton Backward Formula
    double result = y[n-1];     // Start with y_n
    for (int i = 1; i < n; i++) {
        double term = diff[n-1][i];
        // u(u+1)(u+2)...
        for (int j = 0; j < i; j++)
            term *= (u + j);
        term /= factorial(i);
        result += term;
    }
    return result;
}
int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;
    double x[n], y[n];
    cout << "Enter x values: ";
    for (int i = 0; i < n; i++) cin >> x[i];
    cout << "Enter y values: ";
    for (int i = 0; i < n; i++) cin >> y[i];
    double value;
    cout << "Enter the value to interpolate: ";
    cin >> value;
    double ans = newtonBackward(x, y, n, value);
    cout << "Interpolated value at " << value << " is: " << ans << endl;
    return 0;
}
