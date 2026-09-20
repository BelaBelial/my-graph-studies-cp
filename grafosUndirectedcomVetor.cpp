#include <bits/stdc++.h>
using namespace std;

int main(){
    //grafo undirected com listas adjacentes
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n); //indices de 0 a n-1
    //temos um vetor que guarda todas as n nodes (no caso as nodes sao os indexes 0 - n-1)
    //em cada uma dessas posicoes, essas indexes tem um vetor dentro
    //nesse vetor vao ser guardadas as outras nodes que se conectam com a node do index do main vector

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;

        //undirected
        adj[u].push_back(v); //na posicao da node u, tem uma conexao com v
        adj[v].push_back(u); //na posicao da node v, tem uma conexao com u

        //se fosse directed seria ass: 
        /*
        adj[u].push_back(v); //na posicao da node u, tem uma conexao com v
        // adj[v].push_back(u); //na posicao da node v, nao tem uma conexao com u        
        */

    }

    //imprimindo o resultado final
    //primeiro da cout no i, que no caso eh a node
    //depois da cout no vector que ta na pos i
    cout << "lista adjacente para representar grafos: " << endl;
    for(int i = 0; i < n; i++){
        cout << i << ": ";
        for(int j = 0; j < adj[i].size(); j++){ //esse inner loop aq itera pelo tamanho do vector na pos adj[i] do main vector 
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
/*exemplo de entrada com node que podem comecar em 0 */
// 4 5
// 0 1
// 0 2
// 1 2
// 1 3
// 2 3
/*
saida = 
lista adjacente para representar grafos nao direcionados: 
0: 1 2 
1: 0 2 3 
2: 0 1 3 
3: 1 2 
*/