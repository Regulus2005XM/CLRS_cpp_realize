#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;

struct Edge {
    int v;
    long long capacity;
    long long flow;
};

struct Graph {
    vector<Edge> adj[101];
    
    void addEdge(int u, int v, long long w) {
        Edge a = {v, w, 0};
        Edge b = {u, 0};
        adj[u].push_back(a);
        adj[v].push_back(b);
    }
    int bfs(int source, int sink, vector<int>& parent) {
        fill(parent.begin(), parent.end(), -1); 
        parent[source] = -2;
        queue<pair<int, long long>> q;
        q.push({source, INF});
        while (!q.empty()) {
            int u = q.front().first;
            long long flow = q.front().second;
            q.pop();

            for (Edge& edge : adj[u]) {
                if (parent[edge.v] == -1 && edge.flow < edge.capacity) {
                    parent[edge.v] = u;
                    long long new_flow = min(flow, edge.capacity - edge.flow);
                    if (edge.v == sink) {
                        return new_flow;
                    }
                    q.push({edge.v, new_flow});
                }
            }
        }
        return 0;
    }
    // Edmonds-Karp
    long long edmondsKarp(int source, int sink) {
        long long totalFlow = 0;
        vector<int> parent(101);
        long long newFlow;
        while ((newFlow = bfs(source, sink, parent)) > 0) {
            totalFlow += newFlow;
            int curr = sink;
            while (curr != source) {
                int prev = parent[curr];
                for (Edge& edge : adj[prev]) {
                    if (edge.v == curr) {
                        edge.flow += newFlow;
                    }
                }
                for (Edge& edge : adj[curr]) {
                    if (edge.v == prev) {
                        edge.flow -= newFlow;
                    }
                }
                curr = prev;
            }
        }
        return totalFlow;
    }
};

int main() {int T;cin >> T;for (int i = 0; i < T; i++) {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        Graph g;
        for (int j = 0; j < m; ++j) {
            int u, v;
            long long w;
            scanf("%d%d%lld", &u, &v, &w);
            g.addEdge(u, v, w);
        }
        long long maxFlow = g.edmondsKarp(s, t);
        cout << maxFlow << endl;
}return 0;}