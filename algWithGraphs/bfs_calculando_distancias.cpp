#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> g[1000];

//Performando BFS e construindo um vetor de distancia de cada um dos vertices a um vertice inicial (vertice 1);
//A ideia eh basicamente calcular em que nivel cada vertice se encontra, tendo como base o nivel 0 sendo o nivel do vertice inicial (1);

vector<int> bfs_calculando_distancia(int start){
    queue<int> fila_de_processamento;
    fila_de_processamento.push(start);

    vector<int> distancias(n+1, -1);
    distancias[start] = 0;

    bool visitados[n+1] = {false};
    visitados[start] = true;

    while(fila_de_processamento.empty() == false){
        int node_atual = fila_de_processamento.front();
        fila_de_processamento.pop();

        for(int vizinho : g[node_atual]){
            if(visitados[vizinho] == false){
                fila_de_processamento.push(vizinho);
                visitados[vizinho] = true;

                //o calculo da distanica eh sempre a distancia do node atual do start + 1, porque o vizinho em que estamos esta a um vertice a mais de distancia do node atual, ja que ele eh vizinho do node atual
                distancias[vizinho] = distancias[node_atual] + 1;
            }
        }
    }
    return distancias;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    //1 based graph
    vector<int> distancias = bfs_calculando_distancia(1);

    for(int i =1; i < distancias.size(); i++){
        if(i == 1){
            cout << i << " eh o vertice inicial! Distancia = " << distancias[i] << endl;
        }
        else{
            cout << "Distancia do vertice " << i << " do vertice inicial eh " << distancias[i] << endl;
        }
    }


/*
Exemplo de input:
5 4
1 2
1 3
3 4
3 5

distancias = 0, 1, 1, 2, 2
*/
    return 0;
}