#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
const int limit=1e2+5;

vector<int>adj[limit];
vector<int>transpose[limit];
vector<int> Es(limit),Ef(limit),Ls(limit),Lf(limit) ,ft(limit);
vector<int>for_deg(limit),rev_degree(limit),slack(limit);
vector<int>ans,critical_path;
vector<bool>vis={false};

void forword_topsort(int n){

    queue<pair<int,int>>q;

    for(int i=1;i<=n;i++){

        if(for_deg[i]==0) q.push({i,0});

    }

    while(q.size()>0){

        int cur=q.front().first;
        int st =q.front().second;

        Es[cur]=st;
        Ef[cur]=ft[cur] + st;

        ans.push_back(cur);

        q.pop();

        for(int child: adj[cur]){


            for_deg[child]--;

            if(for_deg[child]==0) q.push({child,Ef[cur]});

        }

    }

}

void back_topsort(int n){

    queue<pair<int,int>>q;

    int Max_fin=0;

    for(int i=1;i<=n;i++){

        if(rev_degree[i]==0) Max_fin=max(Max_fin,Ef[i]);

    }

    for(int i=1;i<=n;i++){

        if(rev_degree[i]==0) q.push({i,Max_fin});
    }

    while(q.size()>0){

        int cur=q.front().first;
        int LF =q.front().second;

        Lf[cur]=min(Lf[cur],LF);
        Ls[cur]=Lf[cur]-ft[cur];

        q.pop();

        for(int child: transpose[cur]){


            rev_degree[child]--;
            Lf[child]=min(Lf[child],Ls[cur]);
            if(rev_degree[child]==0) {
               // cout<< cur  << " "<<child <<" "<< Ls[cur]<<" "  <<Lf[cur]<<endl;
                q.push({child,Ls[cur]});
            }

        }

    }
}

void dfs(int node){

    cout<<node;

    vis[node]=true;

    for(int ch:adj[node]){
       // cout<<node <<" "<<ch<<" "<<slack[ch]<<endl;
        if(slack[ch]==0){
               // cout<<ch<<endl;
               cout<<"-->";
                dfs(ch);
        }
    }
}

int main(){
    fast;

    int n , e;  cin >> n >> e;

    for(int i=1; i<=n; i++) cin >> ft[i];

    for(int i=0;i < e ; i++) {

        int u,v; cin >> u >> v;

        adj[u].push_back(v);
        for_deg[v] ++;

        transpose[v].push_back(u);
        rev_degree[u] ++;
    }

    forword_topsort(n);

    //for(int i=1;i<=n;i++) cout << Es[i] <<" " << Ef[i]  <<endl;


    for(int i=1;i<=n;i++) Lf[i]=1e9;

    back_topsort(n);

//    for(int i=0;i<ans.size();i++){
//
//        if(i+1==(int)ans.size()) cout<<ans[i]<<endl;
//        else cout<<ans[i]<<"-->";
//    }

    for(int i=1;i<=n;i++) slack[i]=Ls[i]-Es[i];

    for(int i=1;i<=n;i++){

        if(slack[i]==0 && vis[i]==false) dfs(i);

    }
    cout<<endl;

    for(int i=1;i<=n;i++) cout << Es[i] <<" " << Ef[i] << " " <<Ls[i] <<" " << Lf[i] <<" "<<slack[i] <<endl;

    //backword_topsort();



    return 0;
}



