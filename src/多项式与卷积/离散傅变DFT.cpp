#include <bits/stdc++.h>
using namespace std;
/**
 * @Name 离散傅里叶变换(DFT)
 * @Input 输入：一个多项式系数向量a(a0,a1,...,an)
 * @Output 输出：结果值系数向量y(a0,a1,...,yn)
 */
typedef complex<double> Complex;

// 计算离散傅里叶变换
vector<Complex> DFT(const vector<Complex>& a) {
    int n = a.size();
    vector<Complex> y(n);
    
    for (int k = 0; k < n; ++k) {
        y[k] = 0;
        for (int t = 0; t < n; ++t) {
            double angle = -2 * M_PI * k * t / n; // DFT公式中的角度
            y[k] += a[t] * Complex(cos(angle), sin(angle));
        }
    }
    
    return y;
}

int main() {
    // 示例输入
    vector<Complex> a = {1,1,0,1}; // 输入系数向量

    // 计算DFT
    vector<Complex> y = DFT(a);

    // 输出结果
    
    cout << "DFT结果:\n";
    for (const auto& coeff : y) {
        cout << coeff << endl; // 输出为复数
    }

    return 0;
}