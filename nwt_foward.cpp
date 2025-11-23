#include <bits/stdc++.h>
using namespace std;

// Function to calculate factorial
int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

// Function to calculate Newton's Forward Interpolation
double newtonForward(double x[], double y[], int n, double value) {
    double result = y[0];
    double u = (value - x[0]) / (x[1] - x[0]); // Step size assumed uniform

    // Compute forward difference table
    double diff[n][n];
    for (int i = 0; i < n; i++)
        diff[i][0] = y[i];

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
        }
    }

    // 🔹 PRINT DIFFERENCE TABLE
    cout << "\nForward Difference Table:\n";
    cout << "------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << setw(10) << x[i]; // Print x value
        for (int j = 0; j < n - i; j++) {
            cout << setw(10) << diff[i][j];
        }
        cout << endl;
    }
    cout << "------------------------------------------\n\n";

    // Apply Newton's Forward formula
    for (int i = 1; i < n; i++) {
        double term = diff[0][i];
        for (int j = 0; j < i; j++)
            term *= (u - j);

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

    double result = newtonForward(x, y, n, value);
    cout << "\nInterpolated value at " << value << " is: " << result << endl;

    return 0;
}
