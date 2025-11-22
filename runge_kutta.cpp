 #include <bits/stdc++.h>
using namespace std;
double f(double x, double y) {
    return (y*y - x*x)/(x*x + y*y);  // Change this to your required function
}
int main() {
    double x0, y0, h, xn;
    cout << "Enter initial value of x0: ";
    cin >> x0;
    cout << "Enter initial value of y0: ";
    cin >> y0;
    cout << "Enter step size h: ";
    cin >> h;
    cout << "Enter final value xn: ";
    cin >> xn;
    double x = x0;
    double y = y0;
    cout << fixed << setprecision(4);
    //cout << "\n--- Runge Kutta 4th Order Method ---\n";
    cout << "x :\t y :\n";
    while (x < xn) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h/2, y + k1/2);
        double k3 = h * f(x + h/2, y + k2/2);
        double k4 = h * f(x + h, y + k3);
        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6;
        x = x + h;
        cout << x << "\t " << y << endl;
    }
    return 0;
}
