#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans=0,sum[500005],de[500005],delta;
bool sp()
{
    for(int i=1;i<=n;i++)
    {
        if(delta!=a[i]-a[i-1])return 0;
        delta=a[i]-a[i-1];
    }
    return 1;
}
int check(int x)
{
    int resum=0,sumh=0;
    for(int i=1;i<=n;i++)
    {
        de[i]=abs(a[x]-a[i]);
    }
    sort(de+1,de+1+n);
    for(int i=1;i<=n;i++)
    {
        if(resum+de[i]>m)break;
        else
        {
            resum+=de[i];
            sumh++;
        }
    }
    return sumh;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    if(sp())
    {
        ans=0;
        for(int i=1;i<=n;i++)
        {
            if((i+1)*((i-1)/delta+1)/2<=m)ans+=2;
            else if((i+1)*((i-1)/delta+1)/2-i<=m)ans+=1;
        }
        cout<<ans;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            int pl=check(i);
            ans=max(ans,pl);
        }
        cout<<ans;
    }
    return 0;
}
