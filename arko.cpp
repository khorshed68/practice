#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5;
    vector <double> zs = {1, 2, 3, 4, 5};
    vector <double> ys = {3, 4.5, 7.8, 10.2, 14.5};

    double z = 6;

    // y = pz^q
    double sum1z = 0, sum1y = 0, sumlnz = 0, sumlny = 0;
    for (int i = 0; i < n; i++) {
        zs[i] = log(zs[i]);
        sum1z += zs[i];
        sumlnz += (zs[i] * zs[i]);

        ys[i] = log(ys[i]);
        sum1y += ys[i];
        sumlny += (ys[i] * zs[i]);
    }

    double b, a;

    b = ((n * sumlny) - (sum1z * sum1y)) / ((n * sumlnz) - (sum1z * sum1z));
    a = (sum1y - (b * sum1z)) / n;
    a = exp(a);

    double ans = a * pow(z, b);

    cout << ans << endl;

    cout << "y = " << a << " * 6^" << b << " = " << ans << endl;
}
