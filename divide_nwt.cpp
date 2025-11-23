#include <bits/stdc++.h>
using namespace std;

// Function to build the divided difference table
void dividedDifferenceTable(vector<double> &x, vector<double> &y, vector<vector<double>> &dd, int n) {
    // Fill the first column with given y values
    for (int i = 0; i < n; i++)
        dd[i][0] = y[i];

    // Creating divided difference table
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            dd[i][j] = (dd[i + 1][j - 1] - dd[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
}

// Function to evaluate the Newton polynomial at value X
double newtonInterpolation(double X, vector<double> &x, vector<vector<double>> &dd, int n) {
    double result = dd[0][0];
    double product = 1;

    for (int i = 1; i < n; i++) {
        product *= (X - x[i - 1]);       // (X - x0)(X - x1)...
        result += product * dd[0][i];    // Add term: product * f[x0, x1, ..., xi]
    }
    return result;
}

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);
    cout << "\nEnter x-values:\n";
    for (int i = 0; i < n; i++) cin >> x[i];

    cout << "Enter y-values:\n";
    for (int i = 0; i < n; i++) cin >> y[i];

    // Create divided difference table
    vector<vector<double>> dd(n, vector<double>(n, 0));
    dividedDifferenceTable(x, y, dd, n);

    // Print divided difference table
    cout << "\nDivided Difference Table:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++)
            cout << setw(12) << dd[i][j] << " ";
        cout << endl;
    }

    // Interpolation input
    double X;
    cout << "\nEnter value of X to interpolate: ";
    cin >> X;

    double result = newtonInterpolation(X, x, dd, n);
    cout << "\nInterpolated value at X = " << X << " is: " << result << endl;

    return 0;
}
