#include <bits/stdc++.h>
using namespace std;
/**
 * @Name 霍纳法则(horner)
 * @Input 输入：一个多项式(实数)系数向量a(a0,a1,...,an)和值x0
 * @Output 输出：结果值result
 * @Change hornerC是考虑复数域的霍纳法则
 */

double horner(const vector<double>& a, double x0) {
    double result = 0.0;
    int n = a.size()-1;
    for (int i = n; i >= 0; --i) {
        result = result * x0 + a[i];
    }
    return result;
}

complex<double> hornerC(const vector<complex<double>>& a, complex<double> x0) {
    complex<double> result = 0.0;
    int n = a.size()-1;
    for (int i = n; i >= 0; --i) {
        result = result * x0 + a[i];
    }
    return result;
}

int main() {
    vector<double> a; // 用于存储多项式系数
    string line; // 用于存储整行输入
    // 读取一整行输入，从a0到an
    getline(cin, line);
    // 使用 stringstream 处理这行输入
    istringstream iss(line);
    double ai;
    while (iss >> ai) {
        a.push_back(ai); // 将读取的系数添加到向量中
    }
    // 清除输入流中的\n
    // std::cin.clear();
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // 输入值x0
    double x0;
    cin >> x0;
    // 计算多项式在x0处的值
    double result = horner(a, x0);
    // 输出结果
    cout << "A(" << x0 << ") = " << result << endl;
    return 0;
}