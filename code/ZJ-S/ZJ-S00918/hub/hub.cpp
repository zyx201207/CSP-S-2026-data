#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,k,c,ans;
int a[15],dis[15];
bool vis[15];
vector<int>g[N];
void dfs(int x,int fa)
{
	vis[x]=1;
	for(int i=0;i<g[x].size();i++)
	{
		int y=g[x][i];
		if(y==fa)continue;
		if(a[y]==0)continue;
		dfs(y,x);
	}
	return;
}
void dfs2(int x,int fa)
{
	dis[x]=min(dis[fa]+1,dis[x]);
	for(int i=0;i<g[x].size();i++)
	{
		int y=g[x][i];
		if(y==fa)continue;
		dfs2(y,x);
	}
}
void sum(int step)
{
	if(step>n)
	{
		int cnt=0;
		dis[0]=-1;
		for(int i=1;i<=n;i++)
		{
			vis[i]=0,dis[i]=1e16;
			if(a[i])cnt++;
		}
		if(cnt!=k)return;
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])continue;
			if(a[i]==0)continue;
			if(vis[i]==0)
			{
				cnt++;
				dfs(i,0);
			}
		}
		if(cnt>2)return;
		for(int i=1;i<=n;i++)
		{
			if(a[i])dfs2(i,0);
		}
		int num=0;
		for(int i=1;i<=n;i++)
		{
			num=max(num,dis[i]);
		}
		ans=min(num,ans);
		return;
	}
	a[step]=1;
	sum(step+1);
	a[step]=0;
	sum(step+1);
	return;
}
void solve()
{
	cin>>n>>k;
	ans=1e18;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	sum(1);
	cout<<ans<<"\n";
	return;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T=1;
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9

*/
