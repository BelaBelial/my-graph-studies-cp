class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int start = 0;
        queue<int> q;
        q.push(0);
        
        vector<int> res;
        res.push_back(0);
        
        int visited[adj.size()] = {false};
        visited[start] = true;
        
        while(q.empty() == false){
            int curnode = q.front();
            q.pop();
            for(int neighbour : adj[curnode]){
                if(visited[neighbour] == false){
                    visited[neighbour] = true;
                    q.push(neighbour);
                    res.push_back(neighbour);
                }
            }
        }      
        return res;
    }
};
//https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1