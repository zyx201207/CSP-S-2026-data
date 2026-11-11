#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+10;
int c,n,d,a[N];
int dis[N],diss[N][N],ans;
bool vis[N];
vector<int>g[N];
void dij(int st)
{
	priority_queue<pair<int,int>>q;
	for(int i=1;i<=n;i++)
	{
		dis[i]=1e16;
	}
	q.push({0,st});
	dis[st]=0;
	diss[st][0]=1;
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		for(int i=0;i<g[x].size();i++)
		{
			int y=g[x][i];
			if(dis[y]>dis[x]+1)
			{
				dis[y]=dis[x]+1;
				diss[y][dis[y]]=diss[x][dis[x]];
				q.push({-dis[y],y});
			}
			else if(dis[y]==dis[x]+1)
			{
				diss[y][dis[y]]+=diss[x][dis[x]];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(dis[i]==1e16)continue;
		if(diss[i][dis[i]]==2)ans++;
	}
	return;
}
void solve()
{
	cin>>n>>d;
	ans=0;
	bool fl=0;
	for(int i=1;i<=n;i++)
	{
		g[i].clear();
		cin>>a[i];
	}	
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]-a[i]<=d)
			{
				g[i].push_back(j);
				g[j].push_back(i);
			}
			else break;
		}
	}
	for(int i=1;i<=n;i++)dij(i);
	cout<<ans/2<<"\n";
	return;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T=1;
	cin>>c>>T;
	while(T--)solve();
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
