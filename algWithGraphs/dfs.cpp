#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);
#define faster cin.tie(nullptr);

vector<int> graf[10000];

//esse vetor vai marcar se o vertice foi visitado. cada posicao x representa um vertice x.
vector<bool> marc(10000, false);

void dfs(int u){ //depth first search    
    //essa funcao vai retornar a transversal do grafo (a ordem de passada por cada coisa de acordo com o principio do dfs);

    marc[u] = true;

    //obs: se todos os vertices forem visitados, isso significa que o grafo eh conexo
    cout << u << " foi visitado" << endl;
    for(auto v : graf[u]){
        if(!marc[v]){ //se nao foi visitado, visita
            dfs(v);
        }
    }
    return;
}

int main(){
    fast
    faster

    int n, m;
    cin >> n >> m;
   
    //montando o grafo -> nao direcionao e sem peso
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graf[u].push_back(v);
        graf[v].push_back(u);
    }
    //imprime a traversal do grafo (ordem que cada vertice foi visitado)
    dfs(0);
    
    return 0;
}
