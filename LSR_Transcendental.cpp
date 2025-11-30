#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;
    vector<double> x(n), y(n);
    cout << "Enter x values:\n";
    for (int i = 0; i < n; i++) cin >> x[i];
    cout << "Enter y values:\n";
    for (int i = 0; i < n; i++) cin >> y[i];
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    cout << "\ni\t x\t  y\t   ln(y)\t  x*ln(y)\t  x^2\n";
    for (int i = 0; i < n; i++) {
        double Y = log(y[i]);    // ln(y)
        double XY = x[i] * Y;    // x * ln(y)
        double X2 = x[i] * x[i]; // x^2
        // Table print
        cout << i+1 << "\t " << x[i] << "\t  " << y[i]
             << "\t   " << Y << "\t  " << XY
             << "\t   " << X2 << endl;
        // Summations
        sumX += x[i];
        sumY += Y;
        sumXY += XY;
        sumX2 += X2;
    }
    cout << "\nSum X      = " << sumX;
    cout << "\nSum ln(y)  = " << sumY;
    cout << "\nSum X*ln(y)= " << sumXY;
    cout << "\nSum X^2    = " << sumX2 << endl;
    // Regression for A and b:
    double b = (n*sumXY - sumX*sumY) / (n*sumX2 - sumX*sumX);
    double A = (sumY - b*sumX) / n;
    // Original a = e^A
    double a = exp(A);
    cout << "\nRegression (Transcendental) Model:\n";
    cout << "y = " << a << " * e^(" << b << "x)" << endl;
    return 0;
}
