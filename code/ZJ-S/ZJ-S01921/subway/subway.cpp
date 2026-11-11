#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,k,x,y,w[100005],aa=1e12;
int g[505][505],dis[505][505];
vector<int>p[500005];
vector<int>a[505],t[505];
vector<int>edge[505];
bool vis[505][505];
void dfs(int now,int e,int dep)
{
	if(now==e)
	{
		aa=min(aa,dep);
		return;
	}
	if(dep>aa) return;
	for(int i:edge[now])
	{
		if(vis[now][i]||vis[i][now]) continue;
		vis[now][i]=1;
		dfs(i,e,dep+g[now][i]);
		vis[now][i]=0;
	}
	return;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(g,1e12,sizeof(g));
	for(int i=1;i<=m;i++) cin>>w[m];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>x>>y;
			a[i].push_back(x);
			t[i][j]=y;
			p[x].push_back(i);
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j:p[i])
		{
			for(int v:p[i])
			{
				if(j==v) continue;
				g[j][v]=min(g[j][v],t[j][i]+t[v][i]);
				g[v][j]=g[j][v];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(g[i][j]!=1e12)
			{
				edge[i].push_back(j);
				edge[j].push_back(i);
			}
		}
	}
	for(int s=1;s<=n;s++)
	{
		for(int e=s+1;e<=n;e++)
		{
			memset(vis,0,sizeof(vis));
			aa=1e12;
			dfs(s,e,0);
			dis[s][e]=aa+w[s]+w[e];
		}
	}
	while(q--)
	{
		cin>>x>>y;
		int ans=1e12;
		for(int i:p[x])
		{
			for(int j:p[y])
			{
				ans=min(ans,dis[i][j]+a[i][x]+a[j][y]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}