#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500100],d[500100],d1[500100],mi=999999999999999999,t=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n-1;i++)
    {
        d[i]=a[i+1]-a[i];
        mi=min(mi,d[i]);
    }
    if(mi<=m)
    {
        t++;
    }
    else
    {
        cout<<1;
        return 0;
    }
    mi=999999999999999999;
    for(int i=1;i<=n-2;i++)
    {
        d1[i]=d[i+1]*2+d[i];
        mi=min(mi,d1[i]);
    }
    if(mi<=m)
    {
        t++;
    }
    else
    {
        cout<<2;
        return 0;
    }
    for(int i=4;i<=n;i++)
    {
        mi=999999999999999999;
        for(int j=1;j<=n-t;j++)
        {
            d1[j]+=d[j+t-1]*t;
            mi=min(mi,d1[j]);
        }
        if(mi<=m)
        {
            t++;
        }
        else
        {
            break;
        }
    }
    cout<<t;
    return 0;
}
