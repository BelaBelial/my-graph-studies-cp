#include <bits/stdc++.h>
using namespace std;

int main(){
    //grafo direcionado com indexes 1-n , com matriz adjacente
    int n, m; 
    cin >> n >> m;

    int adj[n+1][n+1]; 
    //todas as posicoes comecam em 0 , tive que inicializar explicitamente para n dar erro
    //dava para inicializar com memset tb, que diminui a complexidade do codigo 
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < n+1; j++){
            adj[i][j] = 0; //comeca tudo com 0 para evitar erros que podem ser causados por inicializar de outras formas
        }
    }

    for(int i = 0; i < m; i++){
        int a, b; //nodes que se conecta
        cin >> a >> b;

        //directed
        adj[a][b] = 1;
    }

    for(int i=0; i < n + 1; i++){
        for(int j =0; j < n+1; j++){
            cout << adj[i][j] << " ";
        }cout << endl;
    }

    return 0;
}
/*
6 6
1 2
1 3
3 4 
3 5
2 4
2 6

saida =
obs: lembrando que eu to imprimindo os indices 0 - n, que quer dizer que eu n comecei a imprimir na linha 1 e coluna 1, mas sim da linha 0, coluna 0
0 0 0 0 0 0 0 
0 0 1 1 0 0 0 
0 0 0 0 1 0 1 
0 0 0 0 1 1 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
*/