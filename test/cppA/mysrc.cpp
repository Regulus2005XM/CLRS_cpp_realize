#include <bits/stdc++.h>
/**
 * @Date 2024/11/23 20:14
 */
using namespace std;
typedef long long lint;
const double PI = 3.14159265358979323846;

void FFT(vector<complex<double>>& a) {
    // 长度过小直接返回
    int n = a.size();
    if (n <= 1) return;
    // 计算根Omiga
    complex<double> omiga_n(cos(2*PI/n), sin(2*PI/n));//omiga_n = e^{2PIi/n}
    complex<double> omiga(1.0,0.0); 
    // 折半系数向量a，分出奇偶
    vector<complex<double>> a_even(n / 2);//A0=(a0,a2,...,an-2)
    vector<complex<double>> a_odd(n / 2);//A1=(a1,a3,...,an-1)
    for (int i = 0; i < n / 2; ++i) {
        a_even[i] = a[i * 2];
        a_odd[i] = a[i * 2 + 1];
    }
    // 递归计算
    FFT(a_even);
    FFT(a_odd);
    // 组合两个y
    for (int k = 0; k < n / 2; ++k) {
        complex<double> t = polar(1.0, 2 * PI * k / n) * a_odd[k];
        a[k] = a_even[k] + t;
        a[k + n / 2] = a_even[k] - t;
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    int n2= 1 << n;
    vector<complex<double>> a;
    for(int i = 0; i < n2; i++){
        int tem;
        cin >> tem;
        a.push_back(tem);
    }
    FFT(a);
    complex<double> z(0.0,0.0);
    for(int i = 0; i < n2; i++){
        z += a[i]*cos(i);
    }
    printf("%.2lf %.2lf\n", z.real(), z.imag());
    return 0;
}