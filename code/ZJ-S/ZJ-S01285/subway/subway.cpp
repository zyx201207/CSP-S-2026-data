#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=6e5+5,inf=1e15;
int c,n,m,d,q,w[maxn],dis[505][505],mp[505][505];
bool vis[505];
struct edge
{
	int v,val;
};
vector<edge>ed[maxn],ve[maxn];
struct node
{
	int v,val;
	bool operator < (node b)const
	{
		return val>b.val;
	} 
};
void dij(int s)
{
	for(int i=1;i<=n;i++)
	{
		dis[s][i]=inf;
		vis[i]=0;
	}
	dis[s][s]=0;
	priority_queue<node>qu;
	node now={s,0};
	qu.push(now);
	while(!qu.empty())
	{
		node p=qu.top();
		qu.pop();
		if(vis[p.v])continue;
		vis[p.v]=1;
		for(int i=0;i<ed[p.v].size();i++)
		{
			int nxt=ed[p.v][i].v,nw=ed[p.v][i].val+dis[s][p.v];
			if(nw<dis[s][nxt])
			{
				dis[s][nxt]=nw;
				node p2={nxt,nw};
				qu.push(p2);
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int to,val;
			cin>>to>>val;
			ve[to].push_back({i,val});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)mp[i][j]=inf;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<ve[i].size();j++)
		{
			for(int kk=j+1;kk<ve[i].size();kk++)
			{
				int x=ve[i][j].v,y=ve[i][kk].v,nw=ve[i][j].val+ve[i][kk].val;
				mp[x][y]=mp[y][x]=min(mp[x][y],nw);
			}
		}
	}for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(mp[i][j]==inf)continue;
			ed[i].push_back({j,mp[i][j]});
			ed[j].push_back({i,mp[i][j]});
		}
	}
	for(int i=1;i<=n;i++)dij(i);
	while(q--)
	{
		int x,y,ans=inf;
		cin>>x>>y;
		for(int i=0;i<ve[x].size();i++)
		{
			if(ve[x][i].val+w[x]+w[y]>ans)continue;
			for(int j=0;j<ve[y].size();j++)ans=min(ans,dis[ve[x][i].v][ve[y][j].v]+w[x]+w[y]+ve[x][i].val+ve[y][j].val);
		}
		cout<<ans<<'\n';
	}
	return 0; 
} 
