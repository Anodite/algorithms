// finding bridges offline in O(n+m) using DFS

vector<vector<int>> gr;
vector<int> tin, low, vis;
int t;

void dfs(int u, int p){
        vis[u]=1;
        tin[u]=low[u]=t++;
        for(int v:gr[u]){
                if(v==p) continue;
                if(!vis[v]){
                        dfs(v,u);
                        low[u]=min(low[u],low[v]);
                        if(low[v]>tin[u]){  
                                cout<<u<<' '<<v<<'\n';
                                // bridge found -> back-edge iff low[v]<=tin[u]
                        }
                }else{
                        low[u]=min(low[u],tin[v]);
                }
        }
}

void find_bridges(){
        // init and read graph 
        t=0; 
        gr.resize(n);
        tin.resize(n);
        low.resize(n);
        vis.resize(n);
        // no multiple edges
        for(int i=0; i<n; ++i){
                if(!vis[i]){  // each connected component
                        dfs(i,-1);
                }
        }
}
