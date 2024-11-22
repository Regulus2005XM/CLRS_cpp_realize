/**
 * @Author Regulus
 * @Date 2024/11/23
 * @Dis 存储图的邻接矩阵
 * @Param (lint vN 点数默认从1开始,
 *         lint eN 边数/数据组数,
 *         bool isQuan 是否带权，若"无权"则不接受第三个参数,设置为0和1
 *         bool isDirect 是否有向，若"无向"则会同时填充对角线对称处的格子)
 * @Return vector<vN, vector<vN, int>>的一个邻接矩阵
 * @Hint 由于邻接矩阵的性质，其能存储自环，但不能存储重边，此处遇到重边会+=
 *       即无权图可以显示条数，带权图会扩宽这条边/弧
 */
#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
const int INF = 0x7f7f7f7f;

vector<vector<int>> adMatrix(lint vN, lint eN, 
bool isQuan, bool isDirect){
    if(isQuan){
        //带权图填充INF
        vector<vector<int>> adm(vN, vector<int>(vN, INF));
        //主对角线设置为0
        for (lint i = 0; i < vN; ++i) {
            adm[i][i] = 0;
        }
        //每行读入三个数
        if(isDirect){
            for (lint i = 0; i < eN; ++i) {
                lint a, b, c;
                cin >> a >> b >> c;
                if(adm[a-1][b-1]==INF){
                    adm[a-1][b-1] = 0;
                }
                adm[a-1][b-1] += c;
            }
        }else{//无向则双重填充
            for (lint i = 0; i < eN; ++i) {
                lint a, b, c;
                cin >> a >> b >> c;
                if(adm[a-1][b-1]==INF){
                    adm[a-1][b-1] = 0;
                }
                if(adm[b-1][a-1]==INF){
                    adm[b-1][a-1] = 0;
                }
                adm[a-1][b-1] += c;
                adm[b-1][a-1] += c;
            }
        }
    }else{
        //无权图填充0
        vector<vector<int>> adm(vN, vector<int>(vN, 0));
        //每行读入两个数
        if(isDirect){
            for (lint i = 0; i < eN; ++i) {
                lint a, b;
                cin >> a >> b;
                adm[a-1][b-1] += 1;
            }
        }else{//无向则双重填充
            for (lint i = 0; i < eN; ++i) {
                lint a, b;
                cin >> a >> b;
                adm[a-1][b-1] += 1;
                adm[b-1][a-1] += 1;
            }
        }
    }
}

int main() {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;cin >> T;for (int i = 0; i < T; i++) {
    //主函数

}return 0;}