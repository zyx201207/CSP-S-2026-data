#include<bits/stdc++.h>
using namespace std;
constexpr long long MAXN=510,MAXM=5e5+10,MAXQ=1e5,INF=1e18;
long long dis[MAXN][MAXN];
long long w[MAXM];
vector<pair<int,int>>g[MAXM];
template<typename T>
void chkmin(T&a,T b)
{
    a=min(a,b);
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dis[i][j]=INF;
        }
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=0;j<k;j++)
        {
            int a,t;
            cin>>a>>t;
            g[a].emplace_back(i,t);
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<g[i].size();j++)
        {
            for(int k=j+1;k<g[i].size();k++)
            {
                chkmin(dis[g[i][j].first][g[i][k].first],1ll*g[i][j].second+g[i][k].second);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            chkmin(dis[i][j],dis[j][i]);
            chkmin(dis[j][i],dis[i][j]);
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                chkmin(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        long long ans=INF;
        for(int j=0;j<g[x].size();j++)
        {
            for(int k=0;k<g[y].size();k++)
            {
                chkmin(ans,dis[g[x][j].first][g[y][k].first]+g[x][j].second+g[y][k].second);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
}