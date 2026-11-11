#include<bits/stdc++.h>
using namespace std;
const int maxn=500001,maxm=300001;
int n,m,a[maxn],nxt[maxm],cnt[maxm],fa[maxm];
long long ans[maxm],sum[maxm];
bool vis[maxm],add[maxm];
void dfs(int u)
{
    // cout<<u<<'\n';
    ans[u]++;
    if(nxt[u])
        dfs(nxt[u]);
}
void dfs2(int u)
{
    sum[u]=sum[nxt[u]]+cnt[u];
    if(fa[u])
        dfs2(fa[u]);
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=5000)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++) nxt[j]=0;
            for(int j=i;j<n;j++)
                nxt[a[j]]=a[j+1];
            nxt[a[n]]=0;
            dfs(a[i]);
        }
        for(int i=1;i<=m;i++) cout<<ans[i]<<" "; cout<<'\n';
        return 0;
    }
    cnt[a[n]]=1;
    vis[a[n]]=1;
    for(int i=n;i>1;i--)
    {
        if(!vis[a[i-1]])
        {
            nxt[a[i]]=a[i-1];
            fa[a[i-1]]=a[i];
            cnt[a[i-1]]=1;
            vis[a[i-1]]=1;
        }
        else
        {
            cnt[a[i-1]]++;
        }
    }
    for(int i=1;i<=m;i++)
        if(!nxt[a[i]])
            dfs2(a[i]);
    for(int i=1;i<=m;i++)
        cout<<sum[i]<<" ";
    cout<<'\n';
    return 0;
}
/*

*/