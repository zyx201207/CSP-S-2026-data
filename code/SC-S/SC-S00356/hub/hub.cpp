#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18,N=1e6+5;
vector<int> g[N];
void solve1()
{
	int n,k;
	scanf("%lld%lld",&n,&k);
	int m=(n+3)/2;
	for(int i=1;i<=n;i++)
	{
		g[i].clear();
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%lld%lld",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(n==k)
	{
		printf("0\n");
		return;
	}
	if(k>=m)
	{
		printf("1\n");
		return;
	}
	int ans=inf;
	int x=k/2,y=k-x;
	for(int i=1;i<=m;i++)
	{
		int a=i+x-1;
		int b=m-i+1;
		int c=b-y+1;
		ans=min(ans,max((c-a)/2,i-1));
	}
	printf("%lld\n",ans);
}
int n,k;
bool vis[N],v[N];
int dis[N];
void dfs2(int u,int fa)
{
	v[u]=1;
	for(auto v:g[u])
	{
		if(v==fa||vis[v]==0)
		{
			continue;
		}
		dfs2(v,u);
	}
}
void bfs()
{
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		v[i]=0,dis[i]=inf;
		if(vis[i])
		{
			q.push(i);
			v[i]=1;
			dis[i]=0;
		}
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto x:g[u])
		{
			if(!v[x])
			{
				v[x]=1;
				dis[x]=dis[u]+1;
				q.push(x);
			}
		}
	}
}
bool check()
{
	int sumcnt=0;
	for(int i=1;i<=n;i++)
	{
		sumcnt+=vis[i];
	}
	if(sumcnt!=k)
	{
		return 0;
	}
	sumcnt=0;
	for(int i=1;i<=n;i++)
	{
		v[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]==0&&vis[i]==1)
		{
			dfs2(i,0);
			sumcnt++;
		}
	}
	return (sumcnt<=2);
}
int ans;
void dfs(int u)
{
	if(u==n+1)
	{
		if(check())
		{
			bfs();
			int res=0;
			for(int i=1;i<=n;i++)
			{
				res=max(res,dis[i]);
			}
			ans=min(ans,res);
		}
		return;
	}
	vis[u]=1;
	dfs(u+1);
	vis[u]=0;
	dfs(u+1);
}
void solve()
{
	ans=inf;
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		g[i].clear();
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%lld%lld",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	printf("%lld\n",ans);
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	scanf("%lld%lld",&c,&T);
	if(c>=13&&c<=14)
	{
		while(T--)
		{
			solve1();
		}
		return 0;
	}
	while(T--)
	{
		solve();
	}
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
*/