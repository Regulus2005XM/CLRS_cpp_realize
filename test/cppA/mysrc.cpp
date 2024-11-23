#include <bits/stdc++.h>
/**
 * @Date 2024/11/23 20:14
 */
using namespace std;
typedef long long lint;
const double PI = 3.14159265358979323846;

complex<double> func(const vector<int>& ci, int n2, const complex<double>& x) {
    complex<double> res(0, 0);
    for (int k = 0; k < n2; k++) {
        res += static_cast<complex<double>>(ci[k]) * pow(x, k);
    }
    return res;
}

static int readInt() {
    int x = 0;
    int sign = 1;
    char c;
    while (true) {
        c = getchar();
        if (c == '-') {
            sign = -1;
            c = getchar();
            break;
        }
        if (isdigit(c)) break;
    }
    do {
        x = x * 10 + (c - '0');
        c = getchar();
    } while (isdigit(c));
    return x * sign;
}

int main() {
    int n;
    cin >> n;
    int n2 = 1 << n;

    vector<int> ci(n2);
    for (int i = 0; i < n2; i++) {
        ci[i] = readInt();
    }

    double o1 = cos(2 * PI / n2);
    double o2 = sin(2 * PI / n2);
    complex<double> omiga(o1, o2);
    complex<double> z(0.0, 0.0);

    complex<double> currentOmiga(1.0, 0.0);

    for (int k = 0; k < n2; k++) {
        complex<double> tempz = (complex<double>)cos(k) * func(ci, n2, currentOmiga);
        z += tempz;
        currentOmiga *= omiga;
    }
    printf("%.2lf %.2lf\n", z.real(), z.imag());
    return 0;
}