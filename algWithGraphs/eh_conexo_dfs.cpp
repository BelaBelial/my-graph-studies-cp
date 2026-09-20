#include <bits/stdc++.h>
using namespace std;

//Verificando se um grafico eh conexo usando dfs
//Um grafo conexo eh um grafo que a partir de um ponto de partida (vertice) vc pode chegar em qualquer outro vertice.

int n, m;
vector<int> g[10000];
bool marc[10000] = {false};

void dfs(int u){
    marc[u] = true;
    for(auto x : g[u]){
        if(marc[x] == false){
            dfs(x);
        }
    }
    return;
}

bool eh_conexo(){
    //Se a partir do ponto de partida inicial (1) nem todos os vertices foram visitados, entao o grafo nao eh conexo

    dfs(1); //supondo que eh um grafo 1-based
    for(int i = 1; i <= n; i++){
        if(marc[i] == false){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if(eh_conexo() == true) cout << "eh conexo" << endl;
    else cout << "nao eh conexo" << endl;

    return 0;
}
