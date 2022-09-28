#include<bits/stdc++.h>
using namespace std;
#define ll long long int

#define rn 300
#define alpha 0.05
#define chitest 42.557 //x^2 value of 0.05,(30-1)
#define z_value 1.96

ll y_1[rn]={13};
ll y_2[rn]={29};
ll x[rn]={};
ll m_1 = 2147483563, m_2 = 2147483399, a_1 = 40014, a_2 = 40692;
double r[rn];

ll LCG(int i){
    y_1[i+1] = (a_1*y_1[i])%m_1;
    y_2[i+1] = (a_2*y_2[i])%m_2;

    x[i] = (y_1[i] - y_2[i]) % (m_1-1);

    return x[i];
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
            if(r[j] > lower_limit && r[j] <= upper_limit){
                arr[i]++; //observe random numbers
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
    ll xi;
    double num;

    xi = LCG(0);
    if(xi>0)        num = xi/(float)m_1;
    else if(xi<0)   num = (xi/(float)m_1)+1;
    else            num = (m_1-1)/(float)m_1;
    r[0] = num;
    //cout<<1<<"\t"<<r[0]<<endl;

    for(int i = 1; i<=rn; i++){
        xi = LCG(i);
        if(xi>0)        num = xi/(float)m_1;
        else if(xi<0)   num = (xi/(float)m_1)+1;
        else            num = (m_1-1)/(float)m_1;
        r[i] = num;
        //cout<<i<<"\t"<<r[i]<<endl;
        //if(r[0] == r[i]) break;
    }

    cout<<"test"<<endl;

    cout<<"Chi Square Test:"<<endl;
    ChiSquareTest();
    cout<<"\nCo-relation Test:"<<endl;
    CorelationTest();

    return 0;
}
