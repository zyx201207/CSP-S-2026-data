#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
const int inf=1e18;
int n,k,dep[N],siz[N],mx[N],dfn[N],low[N],tim;
int dp[4010][4010],cnt[4010];
int dis[4010][4010];

vector<int>G[N];

void dfs2(int u,int fa)
{
	dfn[u]=++tim;
	dep[u]=dep[fa]+1;
	siz[u]=1;
	mx[u]=dep[u];
	dp[u][1]=0;
	for(auto v:G[u])
	{
		if(v==fa)continue;
		dfs2(v,u);
		mx[u]=max(mx[u],mx[v]);
	}
	for(auto v:G[u])
	{
		if(v==fa)continue;
		mx[u]=max(mx[u],mx[v]);
		
		siz[u]+=siz[v];
		for(int x=1;x<=min(k,siz[u]);x++)
		{
			cnt[x]=max(dp[u][x],mx[v]-dep[u]);
			for(int y=1;y<=min(x-1,siz[v]);y++)
			{
				cnt[x]=min(cnt[x],max(dp[u][x-y],dp[v][y]));
			}
		}
		for(int x=1;x<=min(k,siz[u]);x++)
		{
			dp[u][x]=cnt[x];
		}
	}
	low[u]=tim;
}

void dfs1(int u,int fa,int rt) 
{
	for(auto v:G[u])
	{
		if(v==fa)continue;
		dis[rt][v]=dis[rt][u]+1;
		dfs1(v,u,rt);
	}
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)G[i].clear();
	for(int i=1;i<=n;i++)
	{
		dep[i]=0;
		for(int j=0;j<=k;j++)
		{
			dp[i][j]=inf;
		}
	}
	for(int i=1;i<n;i++)
	{
		int u,v;cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
		dfs1(i,0,i);
	}
	int ans=1e18;
	for(int rt=1;rt<=n;rt++)
	{
		if(G[rt].size()==1)continue;
		tim=0;
		dfs2(rt,0);
		for(int x=1;x<n;x++)
		{
			int du=dp[x][k];
			for(int i=1;i<=n;i++)
			{
				if(dfn[i]>=dfn[x]&&dfn[i]<=low[x])continue;
				du=max(du,dis[i][x]);
			}
			ans=min(du,ans);
			for(int y=x+1;y<=n;y++)
			{
				if(dfn[x]>=dfn[y]&&dfn[x]<=low[y])continue;
				if(dfn[y]>=dfn[x]&&dfn[y]<=low[x])continue;
				int cnt=1e18;
				for(int i=1;i<k;i++)
				{
					cnt=min(cnt,max(dp[x][i],dp[y][k-i]));
				}
				for(int i=1;i<=n;i++)
				{
					if(dfn[i]>=dfn[x]&&dfn[i]<=low[x])continue;
					if(dfn[i]>=dfn[y]&&dfn[i]<=low[y])continue;
					cnt=max(cnt,min(dis[x][i],dis[y][i]));
				}
				ans=min(ans,cnt);
			}
		}
	}
	cout<<ans<<"\n";
}

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int C,T;cin>>C>>T;
	while(T--)solve();
	return 0;
}
