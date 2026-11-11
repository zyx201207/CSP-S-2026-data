#include<bits/stdc++.h>
using namespace std;
vector<int>mp[15];
int n,dis[15];
bool vis[15],col[15];
void dfs(int now)
{
	if(vis[now]||!col[now])
	{
		return;
	}
	vis[now]=1;
	for(auto v:mp[now])
	{
		dfs(v);
	}
}
void calcans(int now,int pre)
{
	dis[now]=min(dis[now],dis[pre]+1);
	for(auto v:mp[now])
	{
		if(v!=pre)
		{
			calcans(v,now);
		}
	}
}
void solve()
{
	int k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		mp[i].clear();
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	int ans=789113;
	for(int i=0;i<(1<<n);i++)
	{
		if(__builtin_popcount(i)==k)
		{
			int cnt=0;
			for(int j=1;j<=n;j++)
			{
				vis[j]=0;
				dis[j]=1000000007;
				if((i&(1<<(j-1))))
				{
					col[j]=1;
				}
				else
				{
					col[j]=0;
				}
			}
			for(int j=1;j<=n;j++)
			{
				if(col[j]&&!vis[j])
				{
					cnt++;
					dfs(j);
				}
			}
			int tmp=0;
			if(cnt<=2)
			{
				dis[0]=-1;
				for(int j=1;j<=n;j++)
				{
					if(col[j])
					{
						calcans(j,0);
					}
				}
				for(int j=1;j<=n;j++)
				{
					tmp=max(tmp,dis[j]);
				}
				ans=min(ans,tmp);
			}
		}
	}
	cout<<ans<<endl;
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
