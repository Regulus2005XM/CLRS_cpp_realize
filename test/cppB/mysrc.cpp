#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
const int MAXN = 404;
int a[MAXN], p[MAXN], b[MAXN], q[MAXN];
bool graph[MAXN][MAXN];
int match_left[MAXN];
int match_right[MAXN];
bool visited[MAXN];

int n;
bool dfs(int u) {
    for (int v = 0; v < n; ++v) {
        if (graph[u][v] && !visited[v]) {
            visited[v] = true;
            if (match_right[v] == -1 || dfs(match_right[v])) {
                match_left[u] = v;
                match_right[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d",&p[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d",&b[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d",&q[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i] >= q[j] && b[j] >= p[i]) {
                graph[i][j] = true;
            } else {
                graph[i][j] = false;
            }
        }
    }
    fill(match_left, match_left + n, -1);
    fill(match_right, match_right + n, -1);
    int match_count = 0;
    for (int u = 0; u < n; ++u) {
        fill(visited, visited + n, false);
        if (dfs(u)) {
            match_count++;
        }
    }
    cout << match_count << endl;
    return 0;
}