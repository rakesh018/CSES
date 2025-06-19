#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<bool> &visited, vector<vector<int>> &graph)
{
    // mark visited
    visited[node] = true;

    for (int &neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, visited, graph);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // just count the number of connected components
    // ans is components-1

    vector<bool> visited(n + 1, false);
    int components = 0;
    vector<int> nodes;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            components++;
            dfs(i, visited, graph);
            nodes.push_back(i);
        }
    }
    cout << components - 1 << endl;
    for (int i = 0; i < nodes.size() - 1; i++)
    {
        cout << nodes[i] << " " << nodes[i + 1] << endl;
    }

    return 0;
}