#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

// Gaussian elimination to solve linear system
vector<double> gaussianElimination(vector<vector<double>> a, int n) {
    for (int i = 0; i < n; i++) {
        // Partial pivoting
        for (int k = i + 1; k < n; k++)
            if (abs(a[k][i]) > abs(a[i][i]))
                swap(a[i], a[k]);

        for (int k = i + 1; k < n; k++) {
            double t = a[k][i] / a[i][i];
            for (int j = i; j <= n; j++)
                a[k][j] -= t * a[i][j];
        }
    }

    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++)
            x[i] -= a[i][j] * x[j];
        x[i] /= a[i][i];
    }
    return x;
}

int main() {
    int n, m;
    cout << "Enter number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);
    cout << "Enter x values:\n";
    for (int i = 0; i < n; i++) cin >> x[i];
    cout << "Enter y values:\n";
    for (int i = 0; i < n; i++) cin >> y[i];

    cout << "Enter degree of polynomial (m): ";
    cin >> m;

    // Compute sums for normal equations
    vector<double> X(2 * m + 1, 0);
    for (int i = 0; i < 2 * m + 1; i++)
        for (int j = 0; j < n; j++)
            X[i] += pow(x[j], i);

    // Create augmented matrix
    vector<vector<double>> B(m + 1, vector<double>(m + 2, 0));
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++)
            B[i][j] = X[i + j];

        for (int j = 0; j < n; j++)
            B[i][m + 1] += pow(x[j], i) * y[j];
    }

    // Solve coefficients
    vector<double> a = gaussianElimination(B, m + 1);

    // Prepare sum vector for table columns
    vector<double> sumCols(m + 3, 0); // 0: sum_x, 1: sum_y, 2..m+1: sum x^i, last: sum y_pred

    // Print table header
    cout << "\n i\t x\t y\t";
    for (int j = 1; j <= m; j++)
        cout << "x^" << j << "\t";
    cout << "y_pred\n";

    // Print each row and compute column sums
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << x[i] << "\t" << y[i] << "\t";

        sumCols[0] += x[i];
        sumCols[1] += y[i];

        double y_pred = a[0];
        for (int j = 1; j <= m; j++) {
            double x_pow = pow(x[i], j);
            cout << x_pow << "\t";
            y_pred += a[j] * x_pow;
            sumCols[j + 1] += x_pow;
        }
        cout << y_pred << endl;
        sumCols[m + 2] += y_pred;
    }

    // Print summation row
    cout << "sum\t" << sumCols[0] << "\t" << sumCols[1] << "\t";
    for (int j = 2; j <= m + 1; j++)
        cout << sumCols[j] << "\t";
    cout << sumCols[m + 2] << endl;

    // Print polynomial equation
    cout << "\nPolynomial Regression Equation:\ny = ";
    for (int i = 0; i <= m; i++) {
        cout << fixed << setprecision(4) << a[i];
        if (i > 0) cout << "x^" << i;
        if (i != m) cout << " + ";
    }
    cout << endl;

    return 0;
}
