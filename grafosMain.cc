#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//https://media.geeksforgeeks.org/wp-content/uploads/20240613161501/graph-in-cpp.webp
//grafo exemplo:
/*
         1
        /  \  
5 --- 3     2 --- 6
        \  /
         4 
*/
int main(){
//USANDO MATRIX ADJACENTE: ela eh uma matrix quadrada 2D (2d vector no caso), usada para representar um grafo finito UNDIRECTED 
/*Como criar:
- tem que fazer um vector 2D que seja n+1 por n+1, onde n eh o numero de vertices e todas as posicoes dessa matrix comecam com 0 
- como vamos fazer uma grafo undirected, matrix[i][j] e matrix[j][i] vao ambos serem setados para 1 se tem um edge entre as nodes i e j 
- se fosse directed, teria que setar soh matrx[i][j] para 1 quando temos um edge que conecta a vertice i com a vertice(node) j
- se fosse um weighted graph, a gente podia setar a matrix[i][j] para o peso do edge entre as vertices i e j 
*///https://media.geeksforgeeks.org/wp-content/uploads/20230727130331/Undirected_to_Adjacency_matrix.png
/*
primeira linha = n " " m
proximas m linhas tem a representacao dos edges. obs: n = quantidade de vertices e m = quantidade de edges
ex: input be like
6 6
1 2
1 3
3 4 
3 5
2 4
2 6

video muuuito bom explicando como que funciona a marcacao na matriz. supondo que a gente tenha essas combinacoes de nodes, e o grafo nao eh direto, a gente pode simplesmente marcar na matrix que vai ser inicializada com todos as posicoes == 0. vamo marcando cada combinacao, ent considerando uma matrix com n == 6 (n = nodes), temos que marcar na posicao i da matrix(linha) e na posicao j da matrix(coluna) correspondente as combinacoes que recebemos de entrada. temos que marcar a intersecao do i,j, como que fosse mesmo uma coordenada, ent, por exemplo, nesse exemplo de entrada que eu coloquei acima que corresponde ao grafo que eu tenho, a gente podia fazer o seguinte: considerando a primeira combinacao de nodes, 1, 2, vamos marcar na posicao i=1,j=2 e j=1,i=2, e vamos colocar o numero 1(no caso eu vou colocar asterisco onde tem edge e barra onde n tem p simplificar soh p entender melhor): e o edge 1 2 com esses nodes reprensentados se conectando ficaria da seguinte maneira, pensando que o grafo eh undirected: 
  0  1  2  3  4  5 
0 
1       *      
2    *  
3
4
5

https://youtu.be/3oI-34aPMWM
*/

    //primeiro vou definir n, e m; n = quantas nodes, m = quantos edges
    int n, m; cin >> n >> m;
    int adj[n+1][n+1]; //ele criou uma matrix n+1 / m+1, mas ele tinha falado antes que ia ser n+1/n+1, ele errou sem quere 
    //esse grafo vai ocupar um espaco de n*n, fazendo uma matriz adjacente
    for(int i = 0; i < n; i++){
        int u, v; //cria os pares de nodes que vai receber m(edges) vezes  
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

/*USANDO LISTA ADJACENTE: usa menos espaco na memoria
- basta criar um array de tamanho n+1 (0 - n)
- todo index desse array vai ter um vetor vazio dentro 
- entao, em cada index, pode exmplo, no caso da entrada abaixo, sabemos que o 4 eh conectado com o 2,5,3 entao dentro do vetor da posicao 4 do main vetctor , a gente vai colocar esses 3 numeros
- o mesmo vamos fazer para todos os outros indexes do vetor, colocando os nodes que eles se conectam, no caso do nao direcionado, a gente vai colocar no vector do index i, o j, e no vetor do index j, o i
- o espaco que isso ocupa eh m*2. o dobro dos edges no caso do nao direcionado, pq a conexao entre dois nodes vai ser reciproca e cada edge tem dois nodes, isso eh bem melhor que a matriz, pq tiveram varios espacos nao utilizados preenchidos com 0
considere a entrada: 
5 6
1 2
1 3
3 4
2 4
2 5
4 5
ficaria ass:
vector(n + 1) indexes:
0 
1 - {2, 3}
2 - {1, 4, 5}
3 - {1, 4}
4 - {3, 2, 5}
5 - {2, 4}
*/
    //declara o n e o m, e da cin, como feito acima
    vector<int> vet[n+1]; //pode ser ass colocando as brakets que significa que eh matriz, ou pode ser um vetor de vetor mesmo colocando ()
        //vector<int> adj[n+1] = vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        vet[u].push_back(v); //guardamos no index u, o valor de v, porque ele eh um neighbor e vice versa 
        vet[v].push_back(u);
    }

    /*-------------------------------------------------------------------------*/

    //essas representacoes foram para grafos nao direcionados, mas se fosse direcionado:
    //a complexidade de espaco usada nessa grafo direcionado vai ser a quantidade de edges, ou seja, m 
    //por isso que eh melhor usar lista adjacente e nao matriz adjacente por causa da complexidade de espaco 
    for(int i = 0; i < m; i++){
        int u, v;
        // u ---> v
        cin >> u >> v;
        vet[u].push_back(v); //eh soh o u que tem conexao com o node v, e n o reverso tb 
        // vet[v].push_back(u);
    }

    /*-------------------------------------------------------------------------*/

    //se fosse um grafo weighted, no caso da matriz, a gente podia ao invez de escrever 1 quando tem um edge, escrever o peso do edges, e o valor dele
    //ent adj[u][v] = weight, nao = 1 

    /*-------------------------------------------------------------------------*/

    //para representar isso com uma lista, tem que guardar pares ao inves dos numeros dos nodes adjacentes, entao cada index do vetor principal teria um vetor de pares vazio, ou mesmo um vetor de vetores de 2, com o primeiro numero do par sendo o node e o segundo sendo o peso do edge que conecta os dois
    /* Considerando aquela entrada anterior:
    0 
    1 - {()}
    2 - {()}
    3 - {()}
    4 - {(2, 1), (3, 4), (5, 3)} instead de ter soh o node, agora vai ter o weight, esse peso n ta na entrada porem eh hipotetico para representacao 
    5 - {()}    

    //acho que ficaria ass:
    ex1: vector<vector<pair<int>>>; tem um vetor principal, cada index dele tem um vetor, e nesse vetor do index tem pares
    */

    // https://youtu.be/3oI-34aPMWM -> video salva vidas

    return 0;
}