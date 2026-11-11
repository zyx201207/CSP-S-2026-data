#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],mid,t[500005],las;
bool f,g;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    f=1;
    cin>>n>>m;
    cin>>a[1];
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
        if(a[i-1]!=a[i])
        {
            f=false;
        }
        if(a[i]-a[i-1]!=las&&i>=3)
        {
            g=0;
        }
        las=a[i]-a[i-1];
        mid+=a[i];
    }
    if(f)
    {
        cout<<n;
        return 0;
    }
    if(g)
    {
        cout<<floor(m/las)+1;
        return 0;
    }
    mid/=n;
    for(int i=1;i<=n;i++)
    {
        t[i]=abs(a[i]-mid);
    }
    sort(t+1,t+n+1);
    for(int i=1;i<=n;i++)
    {
        t[i]=t[i-1]+t[i];
    }
    long long use=0;
    long long l=1,r=n,ans=0;
    while(l<=r)
    {
        long long h=(l+r)/2;
        if(t[h]<=m)
        {
            ans=h;
            l=h+1;
        }
        else{
            r=h-1;
        }
    }
    cout<<ans;
}
