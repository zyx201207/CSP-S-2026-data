#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200003];
ll maxn=-1;
bool vis[2003];
void dfs(int len,int u,ll sum)
{
    sum=sum&a[u];
    if(sum<maxn)return ;
    if(len==m)
    {
        maxn=max(maxn,sum);
        return ;
    }
    vis[u]=1;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        dfs(len+1,i,sum);
        continue;
    }
    return ;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==m)
    {
        ll sum=a[1];
        for(int i=2;i<=n;i++)
        {
            sum=sum&a[i];
        }
        return 0;
    }
    else if(m==1)
    {
        ll maxn=-1;
        for(int i=1;i<=n;i++)
            maxn=max(maxn,a[i]);
        cout<<maxn;
        return 0;
    }
    else if(n<=3000)
    {
        for(int i=1;i<=n;i++)
        {
            dfs(1,i,a[i]);
        }
        cout<<maxn;
        return 0;
    }
    else
    {
        sort(a+1,a+n+1);
        cout<<a[m];
        return 0;
    }
    return 0;
}
