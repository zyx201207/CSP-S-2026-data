#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,p;
int w[200005];
int a[200005],t[200005];
int e[15005][15005];
int st,ed;
int ans;
int vis[200005];
int dist[200005];
void dfs(int x)
{
    for(int i=1;i<=m;i++)
    {
        if(e[x][i]+dist[x]<dist[i])
        {
            dist[i]=e[x][i]+dist[x];
            dfs(i);
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a[j]>>t[j];
        }
        for(int j=1;j<=m;j++)
        {
            for(int k=1;k<=m;k++)
            {
                e[a[j]][a[k]]=t[j]+t[k];
            }
        }
    }
    for(int i=1;i<=p;i++)
    {
        memset(vis,0,sizeof(vis));
        memset(dist,INT_MAX,sizeof(dist));
        ans=INT_MAX;
        cin>>st>>ed;
        for(int i=1;i<=n;i++)
        {
            if(e[st][i]!=0)
                dist[i]=e[st][i];
        }
        dist[st]=0;
        dfs(st);
        cout<<dist[ed]+w[st]+w[ed];
    }
}
