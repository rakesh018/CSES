#include <bits/stdc++.h>
using namespace std;

pair<int, int> getIndices(char ch)
{
    if (ch == 'L')
    {
        return {0, 1};
    }
    else if (ch == 'R')
    {
        return {0, -1};
    }
    else if (ch == 'U')
    {
        return {1, 0};
    }
    else
    {
        return {-1, 0};
    }
}
int main()
{
    int n, m;

    cin >> m >> n;
    bool flag = false;
    vector<vector<char>> graph(m, vector<char>(n));
    int sx, sy, tx, ty;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 'A')
            {
                sx = i;
                sy = j;
            }
            if (graph[i][j] == 'B')
            {
                tx = i;
                ty = j;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({sx, sy});
    vector<int> dx = {-1, 1, 0, 0}; // left right down up
    vector<int> dy = {0, 0, 1, -1};
    map<int, char> mp;
    mp[0] = 'U';
    mp[1] = 'D';
    mp[2] = 'R';
    mp[3] = 'L';
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        // cout<<x<<" "<<y<<endl;
        q.pop();
        if (x == tx && y == ty)
        {
            flag = true;
            break;
        }
        for (int move = 0; move < 4; move++)
        {
            int nx = x + dx[move];
            int ny = y + dy[move];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && (graph[nx][ny] == '.' || graph[nx][ny] == 'B'))
            {
                char movement = mp[move];
                q.push({nx, ny});
                graph[nx][ny] = movement;
            }
        }
    }

    if (flag)
    {
        cout<<"YES"<<endl;
        vector<char> ans;
        int tempx = tx, tempy = ty;

        while (1)
        {
            ans.push_back(graph[tempx][tempy]);
            pair<int, int> p = getIndices(graph[tempx][tempy]);
            tempx += p.first;
            tempy += p.second;
            if (tempx == sx && tempy == sy)
                break;
        }
        cout<<ans.size()<<endl;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i];
        }
        cout << endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}