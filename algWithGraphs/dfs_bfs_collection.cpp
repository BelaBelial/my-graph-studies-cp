#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> g[1000];

int distancias[1000];
int vis[1000] = {false};
vector<int> dfss;
vector<int> bfss;

void dfs(int start){
    vis[start] = true;
    dfss.push_back(start);
    for(int i : g[start]){
        if(vis[i] == false){
            dfs(i);
        }
    }
    return;
}

void bfs(int start){
    memset(distancias, -1, sizeof(distancias));

    bfss.push_back(start);
    queue<int> q;
    bool visited[n+1] = {false};

    distancias[start] = 0;
    q.push(start);
    visited[start] = true;

    while(q.empty() == false){
        int v = q.front();
        q.pop();
        for(int i : g[v]){
            if(visited[i] == false){
                visited[i] = true;
                q.push(i);
                bfss.push_back(i);
                distancias[i] = distancias[v] + 1;
            }
        }
    }
    return;
}

int main()
{
    
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    bfs(1);
    dfs(1);

    cout << "distancias: bfs" << endl;
    for(int i =1; i <= n; i++){
        cout << distancias[i] << " ";
    }cout<< endl;
    
    cout << "dfs traversal" << endl;
    for(int i = 0; i < dfss.size(); i++){
        cout << dfss[i] << " ";
    }cout << endl;
    
    cout << "bfs traversal" << endl;
    for(int i =0; i < bfss.size(); i++){
        cout << bfss[i] << " ";
    }cout << endl;

    return 0;
}
