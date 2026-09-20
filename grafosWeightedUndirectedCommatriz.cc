#include <bits/stdc++.h>
#include <cstring> //necessario para memset se eu n tivesse o bits 
using namespace std;
//grafo undirected e ponderado usando matriz, complexidade/espaco = o(n*n)
//esse codigo tb contem info sobre o metodo memset() que eh original do c
int main(){

    int n, m; cin >> n >> m;
    int adj[n][n]; //index das nodes do grafo comeca em 0

    //memset sendo usado, ele serve para preencher um bloco de memoria com um valor de byte constante e especifico 
    //sintax = void* memset(void* dest, int value, size_t count);
        //ponteiro ou endereco para a estrutura a ser preenchida, elemento a preencher a estrutura, numero de bytes a ser preenchido na memoria
    memset(adj, 0, sizeof(adj));


    for(int i =0; i < m; i++){
        int u, v, p; cin >> u >> v >> p;

        //directed e weighted setando na matriz
        adj[u][v] = p;
        adj[v][u] = p;
    }

    cout << "undirected and weighted graph represented by adjacency matrix: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
entrada = 
4 5
0 1 10
0 2 3
1 2 1
1 3 2
2 3 9

saida = 
undirected and weighted graph represented by adjacency matrix:
0 10 3 0 
10 0 1 2 
3 1 0 9 
0 2 9 0
*/