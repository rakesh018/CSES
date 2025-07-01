#include <bits/stdc++.h>
using namespace std;

bool bfs(int start, vector<vector<int>>& graph, vector<int>& color) {
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (color[neighbor] == -1) {
                color[neighbor] = 1 - color[node];
                q.push(neighbor);
            } else if (color[neighbor] == color[node]) {
                // Found same color on both sides of an edge
                return false;
            }
        }
    }

    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> color(n + 1, -1); // -1 means unvisited

    for (int i = 1; i <= n; ++i) {
        if (color[i] == -1) {
            if (!bfs(i, graph, color)) {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }

    // Output coloring (0-based → 1-based)
    for (int i = 1; i <= n; ++i) {
        cout << color[i] + 1 << " ";
    }
    cout << endl;
}

int main() {
    solve();
}
