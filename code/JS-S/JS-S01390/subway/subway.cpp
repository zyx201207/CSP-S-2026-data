#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500002];
struct node
{
    int v,t;
};
vector<node>g[500002],p;
int dis[500002];
bool vis[500002];
inline int Dijkstra(int s,int e)
{
    for(int i=1;i<=m;i++) dis[i]=0x3f3f3f3f,vis[i]=false;
    dis[s]=0;
    while(!vis[e])
    {
        int u,le=0x3f3f3f3f;
        for(int i=1;i<=m;i++)
        {
            if(vis[i]) continue;
            if(dis[i]<le) u=i,le=dis[i];
        }
        vis[u]=true;
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i].v;
            if(vis[v]) continue;
            if(dis[u]+g[u][i].t<dis[v]) dis[v]=dis[u]+g[u][i].t;
        }
    }
    return dis[e];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
	    int k;
	    cin>>k;
	    for(int j=1;j<=k;j++)
        {
            int v,t;
            cin>>v>>t;
            p.push_back({v,t});
        }
        for(int j=0;j<p.size();j++)
        {
            for(int k=j+1;k<p.size();k++)
            {
                int u=p[j].v,v=p[k].v,t=p[j].t+p[k].t;
                g[u].push_back({v,t});
                g[v].push_back({u,t});
            }
        }
        p.clear();
	}
	while(q--)
    {
        int s,e;
        cin>>s>>e;
        cout<<Dijkstra(s,e)+w[s]+w[e]<<'\n';
    }
    return 0;
}
