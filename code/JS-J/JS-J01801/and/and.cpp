#include <bits/stdc++.h>
using namespace std;
long long n,m,a[2005],vis[2005],maxn=0;
void dfs(int x,long long ans)
{
    if(x==m+1)
    {
        maxn=max(maxn,ans);
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            if(x==1)dfs(2,a[i]);
            else dfs(x+1,(ans&a[i]));
            vis[i]=0;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<=20)
    {
        dfs(1,0);
        cout<<maxn;

    }
    else if(m==1)
    {
        sort(a+1,a+1+n);
        cout<<a[n];
    }
    else if(m==n)
    {
        long long ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans=(ans&a[i]);
        }
        cout<<ans;
    }
    return 0;
}
