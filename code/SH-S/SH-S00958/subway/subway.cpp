#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=6e5+5;
int c,n,m,d,query;
int inout[maxn];
vector<pair<int,int> > g[maxn];
struct node
{
	int ju;
	int u;
	bool operator<(node another)const
	{
		return ju>another.ju;
	}
};
priority_queue<node> q;
int dis[maxn];
bool vis[maxn];
int xiandis[505][505];

void dijsk(int src)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	while(!q.empty())
	{
		q.pop();
	}
	q.push({0,src});
	dis[src]=0;
	vis[src]=0;
	while(!q.empty())
	{
		int u=q.top().u;
		q.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		for(auto to:g[u])
		{
			int v=to.first;
			int val=to.second;
			if(dis[v]>dis[u]+val)
			{
				dis[v]=dis[u]+val;
				q.push({dis[v],v});
			}
		}
	}
	return;
}
 
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>query;
	for(int i=1;i<=m;i++)
	{
		cin>>inout[i];
	}
	for(int i=1;i<=n;i++)
	{
		int cnt;
		cin>>cnt;
		for(int j=1;j<=cnt;j++)
		{
			int zhan,tim;
			cin>>zhan>>tim;
			g[zhan].push_back({m+i,tim});
			g[m+i].push_back({zhan,tim});
		}
	}
	for(int i=1;i<=n;i++)
	{
		dijsk(m+i);
		for(int j=1;j<=n;j++)
		{
			xiandis[i][j]=dis[m+j];
		}
	}
	while(query-->0)
	{
		int u,v;
		cin>>u>>v;
		int ans=1e18;
		for(auto u_xian:g[u])
		{
			for(auto v_xian:g[v])
			{
				int sum=u_xian.second+v_xian.second+xiandis[u_xian.first-m][v_xian.first-m]+inout[u]+inout[v];
				ans=min(ans,sum);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

