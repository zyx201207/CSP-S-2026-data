#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int v,w;
};
bool operator < (const node &x,const node &y)
{
	return x.w>y.w;
}
bool operator > (const node &x,const node &y)
{
	return x.w<y.w;
}
int w[500005],a[505][1005],t[505][1005],k[500005];
int dis[1005005];
bool vis[1005005];
vector<int> G[20005];
vector<node> g[1005005];
void dij(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	priority_queue<node> q;
	q.push({s,0});
	while(q.size())
	{
		node j=q.top();
		q.pop();
		int x=j.v;
		if(vis[x])continue;
		vis[x]=1;
		for(node i:g[x])
		{
			int y=i.v,w=i.w;
			if(dis[y]<=dis[x]+w)continue;
			dis[y]=dis[x]+w;
			if(!vis[y])
			{
				q.push({y,dis[y]});
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++)
	{
		cin>>w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin>>k[i];
		for(int j = 1;j <= k[i];j++)
		{
			int T;
			cin>>a[i][j]>>T;
			G[a[i][j]].push_back(i);
			t[i][a[i][j]]=T;
		}
	}	
	for(int i = 1;i <= n;i++)//地铁线路内部 
	{
		for(int j = 1;j <= k[i];j++)
		{
			for(int l=j+1;l <= k[i];l++)
			{
				g[i*(m+1)+a[i][j]].push_back({i*(m+1)+a[i][l],0});
				g[i*(m+1)+a[i][l]].push_back({i*(m+1)+a[i][j],0});
			}
		}
	}
	for(int i=1;i <= m;i++)//站内换乘 
	{
		for(int j = 0;j < G[i].size();j++)
		{
			for(int l=j+1;l<G[i].size();l++)
			{
				g[G[i][j]*(m+1)+i].push_back({G[i][l]*(m+1)+i,t[G[i][l]][i]+t[G[i][j]][i]});
				g[G[i][l]*(m+1)+i].push_back({G[i][j]*(m+1)+i,t[G[i][l]][i]+t[G[i][j]][i]});
			}
		}
	}
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			g[i].push_back({j*(m+1)+i,t[j][i]});
			g[j*(m+1)+i].push_back({i,t[j][i]});
		}
	}
	for(int i = 1;i <= q;i++)
	{
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<endl;
	}
	return 0;
}
