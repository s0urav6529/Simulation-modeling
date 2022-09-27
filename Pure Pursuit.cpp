#include<bits/stdc++.h>
#include<cstdlib>
#include<ctime>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const int limit=1e2+5;

double bx[limit] , by[limit] , fx[limit] ,fy[limit];
double vf;

int main(){

    fast;
    srand(time(0));

    int n = 1+rand()%20;

    cout<<"Boomber path"<<endl;
    for(int i=0;i<n;i++){
        bx[i] = rand()%100;
    }

    for(int i=0;i<n;i++){
        by[i] = rand()%100;
    }
    for(int i=0;i<n;i++) cout<<"("<<bx[i]<<","<<by[i]<<")"<<" ";
    cout<<endl<<endl;

    cout<<"Fighter initial path"<<endl;
    fx[0] = rand() % 50;
    fy[0] = rand() % 50;

    cout<<"("<<fx[0]<<","<<fy[0]<<")"<<endl;

    cout<<endl<<"Fighter velocity"<<endl;
    vf = 1 + ( rand() % 100);
    cout<<vf<<endl<<endl;



    for(int i=0;i<n;i++){

        double dis = sqrt((bx[i]-fx[i]) * (bx[i]-fx[i])  + (by[i]-fy[i]) * (by[i]-fy[i]));

        if(dis<=15.0){
            cout<<"Target caught at "<<i+1<<" minutues & "<<dis <<" distance "<<endl;
            return 0;
        }

        fx[i+1] = fx[i] + (vf * (bx[i] - fx[i]) / dis);
        fy[i+1] = fy[i] + (vf * (by[i] - fy[i]) / dis);

    }
    cout<<"Target escaped !" <<endl;


    return 0;
}



