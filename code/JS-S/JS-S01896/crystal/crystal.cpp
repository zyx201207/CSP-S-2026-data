#include<bits/stdc++.h>
using namespace std;

long long a[500000];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(int i=1;i<n;i++)a[i-1]=a[i]-a[i-1];
    long long x=-1;
    bool b=1;
    for(int i=1;i<n;i++)if(a[i-1]!=a[i]){b=0;break;}
    if(b)
    {
        if(a[0]==0&&a[1]==1)cout<<sqrt(2*m);
        else
        {
            long long k=0,q=0;
            while(q<=m&&k<n)
                q+=a[k]*(++k);
            cout<<k;
        }
    }
    else
    {
        for(int i=0;i<n-1;i++)
        {
            long long k=0,q=0;
            while(q<=m&&i+k<n)
                q+=a[i+k]*(++k);
            x=max(x,k);
        }
        cout<<x;
    }
    return 0;
}

