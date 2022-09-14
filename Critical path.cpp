#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
const int limit=1e2+5;

vector<int>adj[limit];
vector<int>transpose[limit];
vector<int> Es(limit),Ef(limit),Ls(limit),Lf(limit) ,ft(limit);
vector<int>deg(limit),t_degree(limit);

int main(){
    fast;

    int n , e;  cin >> n >> e;
    for(int i=0; i < n; i++) cin >> ft[i];
    for(int i=0;i < e ; i++) {

        int u,v; cin >> u >> v;

        adj[u].push_back(v);
        deg[v] ++;

        transpose[v].push_back(u);
        t_degree[u] ++;
    }

    //for(int i=1;i<=n;i++) cout<< deg[i] <<endl;


    return 0;
}



