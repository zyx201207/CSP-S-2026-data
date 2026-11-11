#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n+2];
    for(long long i=0;i<n;i++)
        cin>>a[i];
    long long imax=0;
    if(m==1)
    {
        for(long long i=0;i<n;i++)
            imax=max(imax,a[i]);
    }
    else if(m==2)
    {
        for(long long i=0;i<n-1;i++)
            for(long long j=i+1;j<n-1;j++)
                imax=max(imax,a[i]&a[j]);
    }
    else if(m==n)
    {
        imax=a[0];
        for(long long i=1;i<n;i++)
        {
            imax&=a[i];
        }
    }
    cout<<imax;
    return 0;
}

