#include<bits/stdc++.h>
using namespace std;

#define m 512
#define rn 300 //random numbers
#define alpha 0.05
#define chitest 42.557 //x^2 value of 0.05,(30-1)
#define z_value 1.96   //value of z(alpha/2) from z table
float r[m];

void LCG(int a, int c, int x0){
    int x[m], n = 300, flag = 0;
    x[0] = x0;

    //calculation of cycle, this will generate 512 random numbers
    /*
    for(int i = 1; i <= 1000; i++){
        cout<<i<<"\t"<<x[i-1]<<endl;
        x[i] = (a*x[i-1]+c)%m;

        for(int j = 0; j < i; j++){
            if(x[j] == x[i]) flag = 1;
        }
        if(flag == 1) break;
    }
    */

    //generating 300 random numbers
    for(int i = 1; i <= rn; i++){
        r[i-1] = x[i-1]/(float)m;
        cout<<i<<"\t"<<r[i-1]<<endl;
        x[i] = (a*x[i-1]+c)%m;
        for(int j = 0; j < i; j++){
            if(r[j+1] == r[0]) flag = 1;
        }
        if(flag == 1) break;
    }
}

void ChiSquareTest(){
    int n, expected;
    cout<<"enter the number of intervals: ";
    cin>>n;
    float interval, lower_limit = 0.0, upper_limit, square_sum = 0;
    interval = 1.0/n;
    expected = rn/n;
    //cout<<"Expected = "<<expected<<endl;
    int arr[n];

    for(int i = 0; i < n; i++){
        arr[i] = 0;
        upper_limit = lower_limit + interval;
        for(int j = 0; j < rn; j++){
            if(r[j] >= lower_limit && r[j] <= upper_limit){
                arr[i]++;
            }
        }
        lower_limit = upper_limit;
        square_sum += ((arr[i]-expected)*(arr[i]-expected)) / (float)expected;
    }
    cout<<"\nValue of Chi Square = "<<square_sum<<endl;
    cout<<"Value of Chi Test = "<<chitest<<endl;
    if(square_sum < chitest) cout<<"\nAccepted, \nsince, "<<square_sum<<" <= "<<chitest<<endl;
    else cout<<"\nNot Accepted, \nsince, "<<square_sum<<" not <= "<<chitest<<endl;
}

void CorelationTest(){
    int i, interval, M;
    float rho_cap = 0.0, sigma, sum_of_every_ith_value = 0.0, z0;
    cout<<"Enter the value of i = ";     //from which random number test will begin
    cin>>i;
    cout<<"Enter the value of interval = ";    //interval of testing numbers
    cin>>interval;
    M = ((rn-i)/interval)-1;    //M is the largest value such that i+(M+1)*interval <= rn
    //cout<<M<<endl;

    for(int j = i-1; j <= rn; j+=interval){
        sum_of_every_ith_value += r[j] * r[j+interval];
    }

    rho_cap = (sum_of_every_ith_value/(M+1))-0.25;
    //cout<<"rho_cap = "<<rho_cap<<endl;
    sigma = sqrt((13*M)+7)/(12*(M+1));

    z0 = rho_cap / sigma;

    if((z0 >= (-1 * z_value)) && (z0 <= z_value))    cout<<"\nthe hypothesis is not rejected\nsince, z0 = "<<z0<<" is lies between "<<-1*z_value<<" and "<<z_value<<endl;
    else cout<<"\nthe hypothesis is rejected\nsince, z0 = "<<z0<<" is not lies between "<<-1*z_value<<" and "<<z_value<<endl;
}

int main()
{
    int seed = 1, a = 13, c = 17;

    LCG(a,c,seed);
    cout<<"Chi Square Test:"<<endl;
    ChiSquareTest();
    cout<<"\nCo-relation Test:"<<endl;
    CorelationTest();


    return 0;
}
