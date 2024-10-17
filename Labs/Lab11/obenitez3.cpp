#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(vector<int>* G, bool* seen, vector<int>& f, int v, int& t){
    seen[v] = true;
    for(int i = 0; i < G[v].size(); i++){
        int u = G[v][i];
        if(!seen[u]){
            DFS(G, seen, f, u, t);
        }
    }
    f[v] = t++;
}

void DFS2(vector<int>* GT, bool* seen, vector<int>& scc, int v){
    seen[v] = true;
    scc.push_back(v);
    for(int i = 0; i < GT[v].size(); i++){
        int u = GT[v][i];
        if(!seen[u]){
            DFS2(GT, seen, scc, u);
        }
    }
}

int main(){

    int V; // no. of vertices
    int E; // no. of edges
    cin>>V;
    cin>>E;

    vector<int>* G = new vector<int>[V];
    for(int i = 0; i < E; i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
    }

    vector<int>* GT = new vector<int>[V];
    for(int i = 0; i < V; i++){
        for(int j = 0; j < G[i].size(); j++){
            int u = i;
            int v = G[i][j];
            GT[v].push_back(u);
        }
    }

    bool* seen = new bool[V];
    vector<int> f(V);
    int t = 0;
    for(int i = 0; i < V; i++){
        seen[i] = false;
    }
    for(int i = 0; i < V; i++){
        if(!seen[i]){
            DFS(G, seen, f, i, t);
        }
    }
     //              0  1  2  3  4
//   // argsort f = [3, 9, 4, 2, 5]
//   // sort:  [2, 3, 4, 5, 9]
//   // asort: [3, 0, 2, 4, 1]
//   // modify sorting, you can built-in function to do argsort
// af = argsort(f);

    vector<int> af(V);
    for(int i = 0; i < V; i++){
        af[i] = i;
    }
    sort(af.begin(), af.end(), [&](int a, int b){ return f[a] > f[b]; });

    for(int i = 0; i < V; i++){
        seen[i] = false;
    }
    vector<int> res(V);
    for(int i = 0; i < V; i++){
        int v = af[i];
        if(!seen[v]){
            vector<int> scc;
            DFS2(GT, seen, scc, v);
            int sccid = *min_element(scc.begin(), scc.end());
            for(int u : scc){
                res[u] = sccid;
            }
        }
    }

    for(int i = 0; i < V; i++){
        cout<<res[i]<<endl;
    }

    return 0;
}
