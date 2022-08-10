#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);

const int limit=2e5+5;

int main(){
    fast;
    read;

    int n,job;
    cin>>n;

    int start[n+5],work[n+5],finish[n+5],cum[n+5];

    start[1]=finish[0]=0,job=n;

    for(int i=1;i<=n;i++){
        cin>>work[i];

        start[i]=finish[i-1];
        finish[i]=work[i]+start[i];

    }

    int cumsum=0,flag=0;
    for(int i=1;i<=n;i++){

        cumsum+=work[i];

        cum[i]=cumsum;

        if(cumsum>=60){

            for(int j=i+1;j<=n;j++){
                start[j]+=5;
                finish[j]+=5;
            }
            cumsum=0;
            flag=1;
        }
        cout<<start[i]<<"       "<<work[i]<<"       "<<finish[i]<<"       "<<cum[i]<<"       ";
        if(flag){
            cout<<"Y"<<"       "<<job--<<endl;

        }
        else{
            cout<<"N"<<"       "<<job--<<endl;
        }
        flag=0;

    }
    return 0;
}



