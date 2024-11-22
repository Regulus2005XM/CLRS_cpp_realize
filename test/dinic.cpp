#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int s, t;
const int N = 1e5 + 5, M = 1e5 + 5;
struct edge{
	int to;
	int ne; 
	int v;
} ed[M];
int head[N];
int p = 1;
int d[N];
void add(int f, int to, int v) {
	ed[++p].to = to, ed[p].ne = head[f], head[f] = p, ed[p].v = v;     // 正向边，剩余容量为v
	ed[++p].to = f, ed[p].ne = head[to], head[to] = p, ed[p].v = 0;    // 最大流算法中的反向边，初始容量为0
}       
bool bfs() {            // dinic算法每轮先通过bfs进行分层
	for (int i = 0; i <= n; ++i) d[i] = -1; // d[i] 表示节点 i 位于第几层。初值为-1
	queue<int> q;
	q.push (s);
	d[s]=0;
	// fr[s] = head[s];
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = head[x]; i ; i = ed[i].ne) {  // 跳转链表的方式遍历所有边
			int to = ed[i].to;
			if (d[to] == -1 && ed[i].v) {      // 如果to尚未遍历且这条边还有容量，进行遍历
				d[to] = d[x] + 1;
				// fr[to] = head[to];
				q.push(to);
				if (to == t) return 1;
			}
		}
	}
	return 0;
}
const int inf = (1ll << 60);     // 定义一个表示“无穷大”的常量
int dfs(int now, int flow) {        // 当前走到now，之前得到的最大流通量为flow
	if (now == t) return flow;      // 寻找通路的递归边界
    int res = 0;
	for (int i = head[now]; i && res < flow; i = ed[i].ne) {  
		int to = ed[i].to;
		// fr[r] = i;
		if (ed[i].v == 0 || d[to] != d[now] + 1) continue;  // 无剩余容量或不满足分层图中的关系
		int get = dfs (to, min (flow - res, ed[i].v));   // 递归计算这一条边走下去最多能流通多少流量
		if (get == 0) d[to] = -1;       // 如果留不通，标记为-1，下次就不会走了
		ed[i].v -= get;
		ed[i ^ 1].v += get;         // 正边流量减少；反边增加，用于“反悔”操作
		res += get;
	}
	return res;
}
int dinic() {
	int ans = 0;
	int tem = 0;
	while (bfs()) {
		while (tem = dfs (s, inf))     // 初始时流通量记为inf，给后面的搜索足够的“发挥空间”
			ans += tem;
	}
	return ans;
}
int sum;
int T;
void sol() {
    scanf ("%lld %lld %lld %lld", &n, &m, &s, &t);
	p = 1;          // 重置边的计数器
	for (int i = 1; i <= n; ++i) head[i] = 0;  // 重置每个链表的表头
	for (int i = 1, x, y, z; i <= m; ++i) {
        scanf ("%lld %lld %lld", &x, &y, &z);
		add (x, y, z);
	}
	int ans = dinic();
	printf("%lld\n",ans);
}
signed main(){
	scanf ("%lld", &T);
	while (T--) sol();
	return 0;
}