#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long c,n,m,d,q,w[N],dis[505][505],vis[505],dis2[505][505];
vector<pair<long long,long long>> edges[N],g[505];
priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1,k;i<=n;i++)
    {
        cin>>k;
        for(int j=1,a,t;j<=k;j++)
        {
            cin>>a>>t;
            edges[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        dis[i][j]=1e16;
    }
    for(int i=1;i<=m;i++)
    {
        int len=edges[i].size();
        for(int j=0;j<len;j++)
        {
            for(int k=j+1;k<len;k++)
            dis[edges[i][j].first][edges[i][k].first]=dis[edges[i][k].first][edges[i][j].first]=min(dis[edges[i][j].first][edges[i][k].first],edges[i][j].second+edges[i][k].second);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if((i!=j)&&(dis[i][j]<1e16))
            g[i].push_back({j,dis[i][j]});
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        dis2[i][j]=1e16;
    }
    for(int i=1;i<=n;i++)
    {
        while(pq.size()) pq.pop();
        for(int j=1;j<=n;j++) vis[j]=false;
        pq.push({0,i});
        dis2[i][i]=0;
        while(pq.size())
        {
            int u=pq.top().second;
            long long cost=pq.top().first;
            pq.pop();
            if(vis[u]) continue;
            vis[u]=true;
            int len=g[u].size();
            for(int j=0;j<len;j++)
            {
                int v=g[u][j].first,w=g[u][j].second;
                if(dis2[i][v]>(w+cost))
                {
                    dis2[i][v]=w+cost;
                    pq.push({dis2[i][v],v});
                }
            }
        }
    }
    while(q--)
    {
        int s,t;
        cin>>s>>t;
        int len1=edges[s].size(),len2=edges[t].size();
        long long ans=1e16;
        for(int i=0;i<len1;i++)
        {
            for(int j=0;j<len2;j++)
            {
                int x=edges[s][i].first,y=edges[t][j].first;
                ans=min(ans,dis2[x][y]+edges[s][i].second+edges[t][j].second+w[s]+w[t]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
