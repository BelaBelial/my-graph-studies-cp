#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> g[1000];

vector<int> bfs(int start){
    bool visited[1000] = {false};
    vector<int> traversal; //guarda a ordem que cada node foi visitado
    queue<int> q; //guarda os vertices que vao ser processados (em ordem)

    visited[start] = true;
    q.push(start);
    traversal.push_back(start);

    while(!q.empty()){ //enquanto ainda ha vertices para processar
        int v = q.front();
        q.pop();

        //visita todos os vizinhos nao visitados do vertice atual
        for(auto x : g[v]){
            if(visited[x] == false){
                visited[x] = true;
                traversal.push_back(x);
                q.push(x);
            }
        }
    }
    return traversal;
}

int main(){
    cin >> n >> m;
    for(int i =0; i < m; i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    //1 based graph
    vector<int> traversal = bfs(0);
    for(int i = 0; i < traversal.size(); i++){
        cout << traversal[i] << " foi visitado" << endl;
    }

    return 0;
}