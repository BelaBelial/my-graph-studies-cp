#include <vector>
#include <iostream>
using namespace std;
//representando grafos nao direcionados ponderados usando lista adjacente (vectors)
    //cada aresta tem um valor numerico, e se chama peso 

int main(){

    int n, m; cin >> n >> m; //n = nodes, m = edges
    //nesse grafo, o numero dos nodes vai ser 0-indexed e comecar com 0 mesmo 
    vector<vector<pair<int, int>>> adj(n); //tem um vetor principal, cada index dele tem um vetor tb, e dentro desse vetor do index, eh guardado diferentes pares de numeros, correspondendo: ao node que se conecta no node do index e o peso do edges entre eles.


    //recebendo os valores consecutivos por m linhas: node1, node2, peso do edge entre essas duas nodes 
    for(int i = 0; i < m; i++){
        int u, v, p; //p == peso 
        cin >> u >> v >> p;

        //atribuindo de maneira undirected
        adj[u].push_back(make_pair(v, p)); //como eh vector, tem que usar o push back primeiro, pq eh um vector, de vector de pairs
        adj[v].push_back(make_pair(u, p));
    }

    cout << "weighted and undirected graph in the form of adjacency list:" << endl;
    for(int i = 0; i < n; i++){
        cout << i << " : ";
        for(int j = 0; j < adj[i].size(); j++){
            cout << "(" << adj[i][j].first << "," << adj[i][j].second << ") ";
            //demorou para descobrir exatamente como achar cada par de cada subvetor do main vector mas foi
            //conclui-se que: adj[i][j].first -> i representa o subvector que a gente quer pegar na posicao i do vector main
                //j representa o pair que a gente quer pegar dentro desse subvector
                //e .first/.second representa o primeiro e segundo elemento do par respectivamente
                //com isso temos um grafo weighted representado aq
        }
        cout << endl;
    }
    // cout << adj[0][0].first << endl;
    return 0;
}

/*

4 5
0 1 10
0 2 3
1 2 1
1 3 2
2 3 9

saida = 
weighted and undirected graph in the form of adjacency list:
0 : (1,10) (2,3) 
1 : (0,10) (2,1) (3,2) 
2 : (0,3) (1,1) (3,9) 
3 : (1,2) (2,9)


for(int i = 0; i < n; i++){           // Para cada nó i do grafo
    cout << i << " : ";               // Imprime o número do nó atual
    
    for(int j = 0; j < adj[i].size(); j++){  // Para cada vizinho do nó i
        cout << "(" << adj[i][j].first << "," << adj[i][j].second << ") ";
        // adj[i] -> subvector que contém TODOS os vizinhos do nó i
        // adj[i][j] -> j-ésimo vizinho do nó i (um pair<int, int>)
        // .first -> índice do nó vizinho
        // .second -> peso da aresta entre i e o vizinho
    }
    cout << endl;
}
*/