#include <bits/stdc++.h>
using namespace std;
int t;
int ans;
int n,k;
int dis[111][111];
vector<int>g[111];
bool vis[111];
void dfs(int u)
{
	vis[u]=1;
	for (auto v:g[u])
	{
		if (!vis[v])
		{
			dfs(v);
		}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>t>>t;
	while (t--)
	{
		cin>>n>>k;
		memset(dis,0x3f,sizeof(dis));
		for (int i=1;i<=n;i++)
		{
			dis[i][i]=0;
			g[i].clear();
		}
		for (int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			dis[u][v]=1;
			dis[v][u]=1;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		// for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) for (int k=1;k<=n;k++) dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
		ans=1e9;
		for (int i=0;i<(1<<n);i++)
		{
			if (__builtin_popcount(i)!=k)
			{
				continue;
			}
			memset(vis,0,sizeof(vis));
			int tot=0;
			for (int j=1;j<=n;j++)
			{
				if ((i&(1<<j-1))&&(!vis[j]))
				{
					tot++;
					dfs(j);
				}
			}
			// cout<<i<<" "<<tot<<endl;
			if (tot>2)
			{
				continue;
			}
			int du=0;
			for (int j=1;j<=n;j++)
			{
				int aaa=1e9;
				for (int l=1;l<=n;l++)
				{
					if ((i&(1<<l-1)))
					{
						aaa=min(aaa,dis[j][l]);
					}
				}
				du=max(du,aaa);
				// cout<<"::"<<j<<" "<<aaa<<endl;
			}
			ans=min(ans,du);
			// if (du==1) cout<<"sadhjkdashijadshaHKDSHAKSDH";
		}
		cout<<ans<<endl;
	}
	return 0;
}