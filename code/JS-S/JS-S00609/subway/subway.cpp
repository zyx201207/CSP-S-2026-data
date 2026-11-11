#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int MAXN=6e5+10;
const int MAXD=1e3+10;
const int MAXL=5e2+10;
int c,n,m,d,Q;
int w[MAXN];
int a[MAXN];
int t[MAXN];
int k[MAXN];
vector<pair<int,int> > g[MAXN];
int x,y;
int sum;
int dis[MAXD][MAXD];
int T;
bool flag=true;
int dist[MAXN];
int f[MAXL][MAXL];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
void dijkstra(int start)
{
    dis[start][start]=0;
    q.push({dis[start][start],start});
    while(!q.empty())
    {
        pair<int,int> u=q.top();
        q.pop();
        if(dis[start][u.second]!=u.first)
        {
            continue;
        }
        else
        {
            for(int i=1;i<=g[u.second].size();i++)
            {
                if(u.first+g[u.second][i-1].second<dis[start][g[u.second][i-1].first])
                {
                    dis[start][g[u.second][i-1].first]=u.first+g[u.second][i-1].second;
                    q.push({dis[start][g[u.second][i-1].first],g[u.second][i-1].first});
                    // cout<<u.second<<' '<<g[u.second][i-1].first<<' '<<dis[start][g[u.second][i-1].first]<<'\n';
                }
            }
        }
    }
}
void dijkstra2(int start)
{
    dist[start]=0;
    q.push({dist[start],start});
    while(!q.empty())
    {
        pair<int,int> u=q.top();
        q.pop();
        if(dist[u.second]!=u.first)
        {
            continue;
        }
        else
        {
            for(int i=1;i<=g[u.second].size();i++)
            {
                if(u.first+g[u.second][i-1].second<dist[g[u.second][i-1].first])
                {
                    dist[g[u.second][i-1].first]=u.first+g[u.second][i-1].second;
                    q.push({dist[g[u.second][i-1].first],g[u.second][i-1].first});
                }
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>Q;
    sum=0;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        sum+=k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[j]>>t[j];
            if(T==0)
            {
                T=t[j];
            }
            else if(t[j]!=T)
            {
                flag=false;
            }
            // cout<<i+m<<','<<a[j]<<','<<t[j]<<'\n';
            g[a[j]].push_back({i+m,t[j]});
            g[i+m].push_back({a[j],t[j]});
        }
    }
    // cout<<flag<<'\n';
    if((sum<=2000&&m<=2000)||(c<=11&&c!=0))
    {
        for(int i=1;i<=m+n;i++)
        {
            for(int j=1;j<=n+m;j++)
            {
                dis[i][j]=INF;
            }
        }
        for(int i=1;i<=m;i++)
        {
            dijkstra(i);
        }
        dijkstra(1);
        for(int i=1;i<=Q;i++)
        {
            cin>>x>>y;
            cout<<dis[x][y]+w[x]+w[y]<<'\n';
            // cout<<'\n';
        }
    }
    else if(flag||(12<=c&&c<=19))
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                f[i][j]=INF;
            }
        }
        for(int i=1;i<=n;i++)
        {
            f[i][i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            for(int x=1;x<=g[i].size();x++)
            {
                for(int y=1;y<=g[i].size();y++)
                {
                    f[g[i][x-1].first-m][g[i][y-1].first-m]=min(f[g[i][x-1].first-m][g[i][y-1].first-m],1ll);
                    f[g[i][y-1].first-m][g[i][x-1].first-m]=min(f[g[i][y-1].first-m][g[i][x-1].first-m],1ll);
                }
            }
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                    f[j][i]=min(f[j][i],f[k][i]+f[j][k]);
                }
            }
        }
        // for(int i=1;i<=n;i++)
        // {
        //     for(int j=1;j<=n;j++)
        //     {
        //         cout<<f[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }
        int ans;
        for(int i=1;i<=Q;i++)
        {
            cin>>x>>y;
            ans=INF;
            for(int i=1;i<=g[x].size();i++)
            {
                for(int j=1;j<=g[y].size();j++)
                {
                    ans=min(ans,f[g[x][i-1].first-m][g[y][j-1].first-m]);
                }
            }
            cout<<2*ans*T+2*T+w[x]+w[y]<<'\n';
        }
    }
    else
    {
        for(int i=1;i<=Q;i++)
        {
            cin>>x>>y;
            for(int i=1;i<=m+n;i++)
            {
                dist[i]=INF;
            }
            dijkstra2(x);
            cout<<w[x]+w[y]+dist[y]<<'\n';
        }
    }
    return 0;
}