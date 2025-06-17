#include<bits/stdc++.h>

using namespace std;

void dfs(int i,int j,vector<int>&dx,vector<int>&dy,vector<vector<char>>&graph,int &m,int &n){
    //mark visited
    graph[i][j]='#';

    for(int move=0;move<4;move++){
        int nx=dx[move]+i;
        int ny=dy[move]+j;

        if(nx>=0 && nx<m && ny>=0 && ny<n && graph[nx][ny]=='.'){
            dfs(nx,ny,dx,dy,graph,m,n);
        }
    }
}
int main(){
    int m,n;
    cin>>m>>n;

    vector<vector<char>>graph(m,vector<char>(n,0));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    int rooms=0;
    vector<int>dx={-1,1,0,0};
    vector<int>dy={0,0,1,-1};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]=='.'){
                dfs(i,j,dx,dy,graph,m,n);
                rooms++;
            }
        }
    }
    cout<<rooms;
}