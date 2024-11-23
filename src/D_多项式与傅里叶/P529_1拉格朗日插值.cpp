#include <iostream>
#include <vector>

using namespace std;

// 拉格朗日插值函数,chatgpt自动生成，未经过校验
double lagrangeInterpolation(const vector<double>& x, const vector<double>& y, double target) {
    int n = x.size();
    double result = 0.0;

    for (int i = 0; i < n; ++i) {
        double term = y[i]; // 先将当前 y_i 赋给 term
        
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                term *= (target - x[j]) / (x[i] - x[j]); // 计算 L_i(x)
            }
        }
        result += term; // 累加所有的 term
    }

    return result; // 返回插值结果
}

int main() {
    // 示例数据点
    vector<double> x = {1.0, 2.0, 3.0}; // x0, x1, x2
    vector<double> y = {1.0, 4.0, 9.0}; // y0 = f(1), y1 = f(2), y2 = f(3)

    // 目标点 (要插值的点)
    double target = 2.5;

    // 计算插值
    double result = lagrangeInterpolation(x, y, target);

    // 输出结果
    cout << "Interpolated value at x = " << target << " is: " << result << endl;

    return 0;
}