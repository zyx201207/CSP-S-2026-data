#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],a[505][500005],b[505][500005],asizen[505],ans=LONG_LONG_MAX;
bool vis[505];
bool sp()
{
    for(int i=1;i<=n;i++)if(asizen[i]!=2)return 0;
    return 1;
}
void dfs(int x,int y,int step)
{
    if(x==y)
    {
        ans=min(ans,step);
        return ;
    }
    queue<pair<int,int>>q;
    for(int i=1;i<=n;i++)for(int j=1;j<=asizen[i];j++)if(a[i][j]==x)q.push({a[i][n-j+1],i});
    while(q.empty())
    {
        int u=q.front().first;
        int step2=step+b[q.front().second][x];
        vis[q.front().second]=1;
        dfs(u,y,step2+b[q.front().second][u]);
        vis[q.front().second]=0;
        q.pop();
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>asizen[i];
        for(int j=1;j<=asizen[i];i++)cin>>a[i][j]>>b[i][j];
    }
    if(sp())
    {
        while(q--)
        {
            int x,y;
            ans=0;
            memset(vis,0,sizeof(vis));
            cin>>x>>y;
            dfs(x,y,0);
            cout<<ans+w[x]+w[y];
        }
    }
    else
    {
        while(q--)
        {
            int x,y;
            ans=0;
            memset(vis,0,sizeof(vis));
            cin>>x>>y;
            dfs(x,y,0);
            cout<<ans+w[x]+w[y];
        }
    }
    return 0;
}
