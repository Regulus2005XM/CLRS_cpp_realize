#include <bits/stdc++.h>
using namespace std;
/**
 * @Name 卷积(convolution)
 * @Input 向量a和b
 * @Output 向量c
 * @Hint 这个函数不使用傅里叶变换，只是普通的卷积计算
 * @Change convolutionC，用于计算复数向量的卷积
 */ 
vector<double> convolution(const vector<double>& a, const vector<double>& b) {
    int n = a.size();
    int m = b.size();
    vector<double> c(n+m-1, 0.0); // 结果向量，初始值为0
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            c[i + j] += a[i] * b[j]; // 卷积计算
        }
    }
    return c; // 返回卷积结果
}

vector<complex<double>> convolutionC(const vector<complex<double>>& a,
 const vector<complex<double>>& b) {
    int n = a.size();
    int m = b.size();
    vector<complex<double>> c(n+m-1, 0.0); // 结果向量，初始值为0
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            c[i + j] += a[i] * b[j]; // 卷积计算
        }
    }
    return c; // 返回卷积结果
}

int main() {
    // 单元测试
    std::vector<double> a = {1, 2, 3};
    std::vector<double> b = {0, 1, 0.5};
    std::vector<double> c = convolution(a, b);
    std::cout << "convolution(a,b) = c: (";
    for (double value : c) {
        std::cout << value << ", ";
    }
    std::cout <<")"<< std::endl;
    return 0;
}