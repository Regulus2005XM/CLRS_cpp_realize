#include <bits/stdc++.h>
using namespace std;
/**
 * @Name 快速傅里叶变换(FFT)
 * @Input 输入：一个多项式系数向量a(a0,a1,...,an)
 * @Output 输出：结果值向量y(a0,a1,...,yn)
 */
const double PI = 3.14159265358979323846;
const double E = 2.71828182845904523536;
// FFT 实现
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
    // 示例输入{0, 0}, {1, 0}, {2, 0}, {3, 0}
    std::vector<std::complex<double>> a = {
        {0, 0}, {1, 0}, {2, 0}, {3, 0}
    };
    // 计算 FFT
    FFT(a);
    // 输出结果(6,0),(-2,-2),(-2,0),(-2,2)
    std::cout << "FFT Result:" << std::endl;
    for (const auto& x : a) {
        std::cout << x << std::endl;
    }
    return 0;
}