#include<bits/stdc++.h>
using namespace std;
vector<int>g[100005];
int dp[10005][25];
int dis[10005];
int n,k;
void dfs(int u,int fa)
{
	dp[u][0]=fa;
	dis[u]=dis[fa]+1;
	for(auto e:g[u])
	{
		if(e!=fa)
		{
			dfs(e,u);
		}
	}
	return ;
}
void init()
{
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=20;++j)
		{
			dp[i][j]=dp[dp[i][j-1]][j-1];
		}
	}
	return ;
}
int lca(int x,int y)
{
	for(int i=20;i>=0;--i)
	{
		if(dis[dp[x][i]]>=dis[y])
		{
			x=dp[x][i];
		}
	}
	for(int i=20;i>=0;--i)
	{
		if(dis[dp[y][i]]>=dis[x])
		{
			y=dp[y][i];
		}
	}
	if(x==y)
	{
		return x;
	}
	for(int i=20;i>=0;--i)
	{
		if(dp[x][i]!=dp[y][i])
		{
			x=dp[x][i];
			y=dp[y][i];
		}
	}
	return dp[x][0];
}
int minn=INT_MAX;
int box[10005];
int vis[10005];
bool check()
{
	for(int i=1;i<=k;++i)
	{
		vis[box[i]]=1;
	}
	int cnt=0;
	for(int i=1;i<=k;++i)
	{
		if(!vis[dp[box[i]][0]])
		{
			cnt++;
		}
	}
	for(int i=1;i<=n;++i)
	{
		vis[i]=0;
	}
	return cnt<=2;
}
void to(int cal,int cnt)
{
	if(cnt>k)
	{
		if(!check())
		{
			return ;
		}
		int maxx=INT_MIN;
		for(int i=1;i<=n;++i)
		{
			int mini=INT_MAX;
			for(int j=1;j<=k;++j)
			{
				mini=min(mini,dis[i]+dis[box[j]]-2*dis[lca(i,box[j])]);
			}
			maxx=max(maxx,mini);
		}
		minn=min(minn,maxx);
		return ;
	}
	if(cal>n)
	{
		return ;
	}
	box[cnt]=cal;
	to(cal+1,cnt+1);
	box[cnt]=0;
	to(cal+1,cnt);
	return ;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;++i)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		minn=INT_MAX;
		dfs(1,0);
		init();
		to(1,1);
		cout<<minn<<'\n';
		for(int i=1;i<=n;++i)
		{
			g[i].clear();
		}
		for(int i=0;i<=n;++i)
		{
			for(int j=1;j<=20;++j)
			{
				dp[i][j]=0;
			}
		}
	}
	return 0;
}
