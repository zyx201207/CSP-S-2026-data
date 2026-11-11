#include<bits/stdc++.h>
using namespace std;

long long a[200000];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=0;i<n;i++)cin>>a[i];
    if(m==1)
    {
        long long x=-1;
        for(long long i=0;i<n;i++)x=max(x,a[i]);
        cout<<x;
    }
    else if(n==m)
    {
        long long x=a[0];
        for(long long i=1;i<n;i++)x&=a[i];
        cout<<x;
    }
    else{
        sort(a,a+n);
        cout<<a[n-m];
    }
    return 0;
}

