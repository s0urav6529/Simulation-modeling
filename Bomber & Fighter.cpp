#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);

const int limit=2e5+5;

int main(){
    fast;
    read;


    ///Bomber path

    float xb[6],yb[6],xf[6],yf[6];
    for(int i=1;i<=5;i++){

        cin>>xb[i]>>yb[i];
    }

    ///Fighter Initial path

    cin>>xf[1]>>yf[1];

    ///Fighter Speed
    float vf,dis;
    cin>>vf;

    for(int i=1;i<=5;i++){

        dis=sqrt(pow((xb[i]-xf[i]),2)+pow((yb[i]-yf[i]),2));

        if(dis<10){

            cout<<"Caught at "<<i<<" mins and  "<<dis<<"Kms"<<endl;
            return 0;

        }

        xf[i+1]=xf[i]+(vf*((xb[i]-xf[i])/dis));
        yf[i+1]=yf[i]+(vf*((yb[i]-yf[i])/dis));

    }

    cout<<"Target Escaped"<<endl;

    return 0;
}

