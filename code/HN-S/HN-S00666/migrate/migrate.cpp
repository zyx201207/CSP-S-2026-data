#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
int n,d;
int x[N],cnt[N],dis[N];
bool f[N][N],V[N][N];
bool vis[N];
struct node
{
	int x,w;
	bool operator < (const node&tmp) const
	{
		return tmp.w<w;
	}
};
vector<node> g[N];
void dij(int s)
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=1e18;
		vis[i]=0;
		cnt[i]=0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			V[i][j]=V[j][i]=0;
	dis[s]=0;
	priority_queue<node> q;
	q.push({s,dis[s]});
	while(!q.empty())
	{
		int x=q.top().x;
		q.pop();
		if(vis[x])
			continue;
		vis[x]=true;
		for(int i=0;i<g[x].size();i++)
		{
			int y=g[x][i].x,w=g[x][i].w;
			if(dis[x]+w==dis[y])
			{
				if(V[x][y]==0&&V[y][x]==0)
				{
					cnt[y]++;
				}
				V[y][x]=1;
				V[x][y]=1;
			}
			if(dis[x]+w<dis[y])
			{
				dis[y]=dis[x]+w;
				cnt[y]=1;
				q.push({y,dis[y]});
			}
		}
	}
}
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		g[i].clear();
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=f[j][i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(x[j]-x[i]<=d)
			{
				g[i].push_back({j,1});
				g[j].push_back({i,1});
				f[i][j]=1;
				f[j][i]=1;
			}
			else
				break;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		dij(i);
		for(int j=i+1;j<=n;j++)
		{
			if(cnt[j]==2&&!f[i][j])
			{
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
		solve();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

