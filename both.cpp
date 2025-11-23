#include <bits/stdc++.h>
using namespace std;

// Function to calculate factorial
int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

// ---------------- NEWTON FORWARD ----------------
double newtonForward(double x[], double y[], int n, double value) {
    double result = y[0];
    double h = x[1] - x[0];
    double u = (value - x[0]) / h;

    // Forward difference table
    double diff[n][n];
    for (int i = 0; i < n; i++)
        diff[i][0] = y[i];

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
        }
    }

    // Print table
    cout << "\nForward Difference Table:\n";
    cout << "------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << setw(10) << x[i];
        for (int j = 0; j < n - i; j++)
            cout << setw(10) << diff[i][j];
        cout << endl;
    }
    cout << "------------------------------------------\n";

    // Apply forward formula
    for (int i = 1; i < n; i++) {
        double term = diff[0][i];
        for (int j = 0; j < i; j++)
            term *= (u - j);
        term /= factorial(i);
        result += term;
    }

    return result;
}

// ---------------- NEWTON BACKWARD ----------------
double newtonBackward(double x[], double y[], int n, double value) {
    double h = x[1] - x[0];
    double u = (value - x[n-1]) / h;

    // Backward difference table
    double diff[n][n];
    for (int i = 0; i < n; i++)
        diff[i][0] = y[i];

    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            diff[i][j] = diff[i][j-1] - diff[i-1][j-1];
        }
    }

    // Print table
    cout << "\nBackward Difference Table:\n";
    cout << "-------------------------------------------------\n";
    cout << "x\tf(x)\tΔb1\tΔb2\tΔb3\tΔb4\n";

    for (int i = 0; i < n; i++) {
        cout << x[i] << "\t";
        for (int j = 0; j <= i; j++)
            cout << diff[i][j] << "\t";
        cout << endl;
    }
    cout << "-------------------------------------------------\n";

    // Apply backward formula
    double result = y[n-1];
    for (int i = 1; i < n; i++) {
        double term = diff[n-1][i];
        for (int j = 0; j < i; j++)
            term *= (u + j);
        term /= factorial(i);
        result += term;
    }

    return result;
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[n], y[n];
    cout << "Enter x values: ";
    for (int i = 0; i < n; i++) cin >> x[i];

    cout << "Enter y values: ";
    for (int i = 0; i < n; i++) cin >> y[i];

    while (true) {
        int choice;
        cout << "\n=========== MENU ===========\n";
        cout << "1. Newton Forward Interpolation\n";
        cout << "2. Newton Backward Interpolation\n";
        cout << "3. Exit Program\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 3) {
            cout << "Exiting...\n";
            break;
        }

        double value;
        cout << "Enter value to interpolate: ";
        cin >> value;

        if (choice == 1) {
            double ans = newtonForward(x, y, n, value);
            cout << "\nForward Interpolated Value at " << value << " = " << ans << endl;
        }
        else if (choice == 2) {
            double ans = newtonBackward(x, y, n, value);
            cout << "\nBackward Interpolated Value at " << value << " = " << ans << endl;
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
