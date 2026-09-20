# Meus Estudos Prolongados de Grafos para Programacao Competitiva 
- Um grafo eh uma estrutura de dados nao linear usada para representar relacoes entre varios objetos 
- Eh uma colecao de verticies e de arestas -> vetex and edge
- Da pra implememntar de muitas formas mas eh usado matrizes adjacentes ou listas com ponteiros e estruturas
- Da pra inserir coisas, e deletar coisas, usando alguns algoritmos classicos, tipo o Dijkstra 
- A gente pode definir um grafo como um conjunto de vertices(nodes) que conectam outros vertices por meio do que eh conhecido como arestas(edges)
- A diferenca do grafo e da arvore eh que o grafo pode ter varias conexos em cada node, mas a arvore soh pode ter uma ou duas, eh algo assim
- Portanto componentes de um grafo: 
        Vertices (nodes): componentes que checam os fatos que estao sendo mostrados na rede de conexos, vamos dizer assim
        Arestas (edges/links): eh o que junta as nodes

- Temos tipos de grafos:
    - Direto(DIRECTED): os nodes tem uma direcao, e significa que se um deles eh conectado a outro, o outro n eh necessariamenta naturalmente conectado a ele. Ent se o A conecta-se ao B, n significa que o B conecta-se ao A, a nao ser que a gnt coloque uma conexao extra. No geral as conexoes nao sao naturalmente mutuas.
    - Indireto(UNDIRECTED): os nodes n tem uma direcao especifica pra irem, e tem aquela reciprocidade/mutualismo entre os nodes que se conectam. Se A eh conectado no B, o B tb eh conectado no A.
    - Weighted: os edges tem 'pesos' ou 'custos' que sao necessarios pra se mover nele 
    - Unweighted: os edges nao tem nenhum peso ou todos os edges tem o mesmo peso

- Tem muitas formas de representar eles e estas formas vao estar nos arquivos .cc/.cpp onde eu farei codigos sobre matrizes e outros tipos de implementacao possiveis para grafos e tudo mais. Mas citandos as formas mais famosas de representacao, temos:
    - Adjacency Matrix Graph Representation: two-dimensional matrix used with graphs. It is more efficient that the adjacency list representation when the graph is dense and we need quick access frequently.
    - Adjacency List Graph Representation: concept where we use array of linked list in order to represent vertices of a graph. Each element denotes a vertex and the linked list present at the same index contains all the vertices that are directly connected to the vertex represented by the given element.

- Alguns algoritimos: BFS, DFS, Dijkstra, Prim, Tarjan e Kruskal

## Trilha Basica para Grafos:
- O que eh um grafo
    - o que eh um vertice
    - o que eh uma aresta
    - graus de um vertice (degree, indegree, outdegree)
    - pesos de um grafo
    - tipos de um grafo
- Representacoes (matriz adjacencia e lista de adjacencia com peso e sem peso)
- O que sao componentes conectados
- O que eh um grafo conexo
- O que eh "a graph traversal"
- BFS e DFS
- Dijkstra

### Fontes importantes:
[GeeksForGeeks PAGE](https://www-geeksforgeeks-org.translate.goog/c/implementation-of-graph-in-c/?_x_tr_sl=en&_x_tr_tl=pt&_x_tr_hl=pt&_x_tr_pto=sge)
[GeeksForGeeks PAGE on C++](https://www.geeksforgeeks.org/cpp/implementation-of-graph-in-cpp/)
[Reducible on DFS](https://youtu.be/PMMc4VsIacU?si=6ZQeX9i9W7Gqc0NB)
[Reducible on BFS](https://youtu.be/xlVX7dXLS64?si=q92UuA1TUz4QeBBz)
[Take u Forward Intro](https://youtu.be/M3_pLsDdeuU?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn)
[Take u Forward Representation](https://www.youtube.com/watch?v=3oI-34aPMWM&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=2&pp=iAQB)
[Take u Forward Connected Components](https://www.youtube.com/watch?v=lea-Wl_uWXY&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=4&pp=iAQB)
[Take u Forward BFS](https://www.youtube.com/watch?v=-tgVpUgsQ5k&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=5&pp=iAQB)
[Take u Forward DFS](https://www.youtube.com/watch?v=Qzf1a--rhp8&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=6&pp=iAQB)