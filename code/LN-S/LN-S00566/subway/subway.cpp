#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int c,n,m,d,qq;
int dis[N],vis[N],ww[N],xx[N],yy[N];
struct Edge
{
    int dis,v;
    bool operator <(Edge a) const { return dis>a.dis; }
};
vector< pair<int,int> > g[N];
void dij(int s)
{
	priority_queue<Edge> q;
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    dis[s]=0;
    q.push({0,s});
    while (!q.empty())
    {
        Edge t=q.top();
        q.pop();
        int x=t.v;
        if (vis[x]) continue;
        vis[x]=1;
        for (auto e : g[x])
        {
            int y=e.first,w=e.second;
            if (dis[y]>dis[x]+w)
            {
                dis[y]=dis[x]+w;
                q.push({dis[y],y});
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin>>c>>n>>m>>d>>qq;
    for (int i=1;i<=m;i++) cin>>ww[i];
    for (int i=1;i<=n;i++)
    {
        int wb;cin>>wb;
        for (int j=1;j<=wb;j++)
        {
            cin>>xx[j]>>yy[j];
            for (int k=1;k!=j;k++)
            {
				int sum=yy[j]+yy[k];
				int uu=xx[j],vv=xx[k];
                g[uu].push_back({vv,sum});
                g[vv].push_back({uu,sum});
            }
        }
    }
    for (int i=1;i<=qq;i++)
    {
        int bb,cc;
        cin>>bb>>cc;
        dij(bb);
        cout<<ww[bb]+ww[cc]+dis[cc]<<"\n";
    }
    return 0;
}
