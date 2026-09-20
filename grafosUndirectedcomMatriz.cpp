#include <iostream>
using namespace std;

int main(){
    //recebendo uma entrada para grafo undirected sem weight
    //entrada = primeira linha(n e m). proximas m linhas sao as combinacoes de nodes
    int n, m;
    cin >> n >> m;
    
    int mat[n][n] = {0}; //inicializada com zeros em todas as posicoes (pode dar erro)
    //eu podia ter inicializado ela com tamanho n+1*n+1 mas acontece que deu um erro
    //ele acaba imprimindo lixo de memoria em varias posicoes da primeira linha
    //no caso a primeira linha ta sendo adicional anyway
    //no geral, a declaracao com n+1*n+1 serve mais para o caso onde a indexacao eh de 1 a n, nao de 1 a n-1 

    for(int i = 0; i < m; i++){ //itera m vezes, ou seja, a quantidade de edges que tem 
        int u, v;
        cin >> u >> v;

        //undirected
        mat[u][v] = 1;
        mat[v][u] = 1;
    }

    cout << "grafo com matriz adjacente: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// 4 5
// 0 1
// 0 2
// 1 2
// 1 3
// 2 3
/*
saida =
grafo com matriz adjacente: 
0 1 1 0 
1 0 1 1 
1 1 0 1 
0 1 1 0
*/