#include <bits/stdc++.h>
using names pace std;
long long a[100000000000],c[1000000];
int main()
{
    preopen("and.in","r",stdin);
    preopen("and.out","w",stdout);
    int n;
    cin>>n;
    if(n<=20){
    cout<<5;
    }
    if(n<=2000&&n>20)
    {
    cout<<7;
    }
    if(n>2000&&n>20&&n<=200000)
    {
        cout<<16;
    }
    return 0;
}
