#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int> &parents, int n)
{
    // backtrack from n to 1
    vector<int> arr;
    int curr = n;
    while (curr != 0)
    {
        arr.push_back(curr);
        curr = parents[curr];
    }
    cout<<arr.size()<<endl;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void solve()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int src, dst;
        cin >> src >> dst;
        graph[src].push_back(dst);
        graph[dst].push_back(src);
    }

    vector<int> parents(n + 1, -1); //-2 is not visited, -1 is the root
    parents[1] = 0;
    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int &neighbor : graph[node])
        {
            if (parents[neighbor] == -1)
            {
                parents[neighbor] = node;
                q.push(neighbor);
            }
        }
    }
    if (parents[n] == -1)
        cout << "IMPOSSIBLE" << endl;
    else
        backtrack(parents, n);
}
int main()
{
    solve();
    return 0;
}