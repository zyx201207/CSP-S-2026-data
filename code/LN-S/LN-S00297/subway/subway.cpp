#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<long long,long long>

int c,n,m,d,q;
const int M=5e5+5,N=505;
int w[M];

vector<pair<int,int>> dian[M];
vector<pair<int,int>> g[N+M];

int dis[N+M],vis[N+M];
const int INF=1e18;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);


    cin>>c>>n>>m>>d>>q;
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
            int a,t;
            cin>>a>>t;
            if(dian[a].size()!=0)
            {
                for(auto x:dian[a])
                {
                    g[x.first].push_back({i,t+x.second});
                    g[i].push_back({x.first,t+x.second});
                }
            }
            dian[a].push_back({i,t});
            g[n+a].push_back({i,t+w[a]});
            g[i].push_back({n+a,t+w[a]});
        }
    }

    for(int i=1;i<=n+m;i++)
    {
        dis[i]=INF;
        vis[i]=false;
    }

    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        
        priority_queue<pii,vector<pii>,greater<pii>> q;
        dis[n+x]=0;
        q.push({0,n+x});
        while(!q.empty())
        {
            auto cur=q.top();
            q.pop();
            if(vis[cur.second])
                continue;
            int u=cur.second;
            vis[u]=true;
            for(auto xx:g[u])
            {
                int v=xx.first,w=xx.second;
                if(v<=n||v==n+x||v==n+y)
                {
                    if(dis[u]+w<dis[v])
                    {
                        dis[v]=dis[u]+w;
                        q.push({dis[v],v});
                    }
                }
            }
        }
        cout<<dis[n+y]<<"\n";

        for(int i=1;i<=n;i++)
        {
            dis[i]=INF;
            vis[i]=false;
        }
        dis[n+x]=dis[n+y]=INF;
        vis[n+x]=vis[n+y]=false;

    }


    return 0;
}
/*
    我的想法是通过“交点”给线路之间连边
    对于每一个点记录有多少经过的线路，然后随着输入给这些线路之间连边，边权就是t+t
    还得把站台加进去，站台到线路的边权就是t，站台的编号应该是从n+1开始一直到n+m
    我说的很对，那么现在开始写
    对于每一个q，把站台也得加进去，做一次dijkstra，求最短路，在加上端点的w
*/