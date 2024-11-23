#include <bits/stdc++.h>
using namespace std;
/**
 * @Name 快速傅里叶变换(FFT)
 * @Change 使用了蝴蝶操作，提取公共因子
 * @Input 输入：一个多项式系数向量a(a0,a1,...,an)
 * @Output 输出：结果值系数向量y(a0,a1,...,yn)
 */
const double PI = 3.14159265358979323846;

// FFT 实现
void FFFT(vector<complex<double>>& a) {

    int n = a.size();
    if (n <= 1) return;
    // 分离偶数和奇数
    std::vector<std::complex<double>> a_even(n / 2);
    std::vector<std::complex<double>> a_odd(n / 2);
    for (int i = 0; i < n / 2; ++i) {
        a_even[i] = a[i * 2];
        a_odd[i] = a[i * 2 + 1];
    }
    // 递归计算 FFT
    FFFT(a_even);
    FFFT(a_odd);
    // 组合结果
    for (int k = 0; k < n / 2; ++k) {
        std::complex<double> t = std::polar(1.0, -2 * PI * k / n) * a_odd[k];
        a[k] = a_even[k] + t;
        a[k + n / 2] = a_even[k] - t;
    }
}

int main() {
    // 示例输入
    std::vector<std::complex<double>> a = {
        {0, 0}, {1, 0}, {2, 0}, {3, 0}
    };
    // 计算 FFT
    FFFT(a);
    // 输出结果
    std::cout << "FFT Result:" << std::endl;
    for (const auto& x : a) {
        std::cout << x << std::endl;
    }
    return 0;
}