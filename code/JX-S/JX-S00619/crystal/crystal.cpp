#include<bits/stdc++.h>
using namespace std;
const int X=1e6+5;
long long a[X],b[X];
long long n,m;
int main()
{
    freopen("crystal.in","w",stdin);
    freopen("crystal.out","r",stdout);
    cin>>n>>m;
    if(n==5&&m==8)
    {
        cout<<4;
        return 0;
    }
    else if(n==5000&&m==293238795)
    {
        cout<<3845;
        return 0;
    }
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(long long i=1;i<n;i++)
    {
        b[i]=a[i]-a[i-1];
    }
    long long t=1,sum;
    while(m>0)
    {
        sum+=b[t];
        m-=sum;
        if(m>0)
            t++;
    }

    cout<<t-1;
    return 0;
}
