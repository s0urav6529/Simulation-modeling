#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int limit=1e2+5;

vector<int>forword[limit],revers[limit];
int for_deg[limit] , rev_deg[limit];
int ft[limit] , es[limit] , ef[limit] , ls[limit] ,lf[limit];
int n , e , u ,v ;

void bfs1(int node){

    queue<pair<int,int>>q;
    q.push({node,-1});

    while(q.size()>0){

        int cur=q.front().first;
        int par=q.front().second;

        q.pop();

        if(cur>0){
            ef[cur] = es[cur]+ft[cur];
        }

        for(int ch:forword[cur]){

            for_deg[ch]--;

            es[ch] = max(es[ch], ef[cur]);

            if(for_deg[ch]==0){

                q.push({ ch , cur});
            }

        }

    }

}

void bfs2(int node){

    queue<pair<int,int>>q;
    q.push({node,-1});

    for(int i=0;i<=node+1;i++) lf[i]=101;

    lf[node] = ef[node];
    ls[node] = ef[node];

    while(q.size()>0){

        int cur= q.front().first;
        int par = q.front().second;

        q.pop();

        if(cur!=(node+1)){
            ls[cur] = lf[cur] - ft[cur];
        }

        for(int ch:revers[cur]){

            rev_deg[ch]--;

            lf[ch] = min(lf[ch] , ls[cur]);

            if(rev_deg[ch]==0){
                q.push({ch,cur});
            }

        }

    }
}

void critical_path(int node){

    for(int ch:forword[node]){

            if(es[ch]-ls[ch] ==0){

                if(ch<=n) cout<<ch<<" ";
                critical_path(ch);

            }
    }

}

int main(){
    fast;


    cin >> n >> e;

    for(int i=0;i<e;i++){
        cin >> u >> v;

        forword[u].push_back(v);

        for_deg[v]++;

        revers[v].push_back(u);

        rev_deg[u]++;
    }

    for(int i=1;i<=n;i++) cin >> ft[i];

    for(int i=1;i<=n;i++){

        if(for_deg[i]==0) {

            forword[0].push_back(i);
            for_deg[i]++;

            revers[i].push_back(0);
            rev_deg[0]++;


        }
    }

    for(int i=1;i<=n;i++){

        if(rev_deg[i]==0) {

            forword[i].push_back(n+1);
            for_deg[n+1]++;

            revers[n+1].push_back(i);
            rev_deg[i]++;

        }
    }

    bfs1(0);

    bfs2(n+1);

    for(int i=0;i<=n+1;i++) {
        cout<<i <<endl;
        cout<< es[i] <<" "<<ef[i] <<endl;
        cout<< ls[i] <<" "<<lf[i] <<endl;
        cout<<endl;
    }
    cout<<"Critical Path is :"<<endl;
    critical_path(0);
    return 0;
}




/*
7 7
1 3
1 4
2 4
3 5
4 6
6 5
6 7

7 9 12 8 6 9 5
*/    
    
