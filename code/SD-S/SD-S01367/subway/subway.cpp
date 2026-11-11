#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500005];
vector<int> pass[500005];
vector<int> tim[500005];
int dis[505][505];
int ans[505][505];
bool vis[505];
void digis(int st)
{
	for(int i=1;i<=n;i++) ans[st][i]=1e18;
	ans[st][st]=0;
	for(int i=1;i<=n;i++)
	{
		int now=0,val=1e18;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]) continue;
			if(val>ans[st][j])
			{
				val=ans[st][j];
				now=j;
			}
		}
		vis[now]=1;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]) continue;
			ans[st][j]=min(ans[st][j],ans[st][now]+dis[now][j]);
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			pass[a].push_back(i);
			tim[a].push_back(t);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(pass[i].size()<2) continue;
		for(int j=0;j<pass[i].size();j++)
		{
			for(int t=0;t<pass[i].size();t++)
			{
				if(j==t) continue;
				dis[pass[i][j]][pass[i][t]]=min(dis[pass[i][j]][pass[i][t]],tim[i][j]+tim[i][t]);
				dis[pass[i][t]][pass[i][j]]=min(dis[pass[i][t]][pass[i][j]],tim[i][j]+tim[i][t]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int i=1;i<=n;i++) vis[i]=0;
		digis(i);
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans1=1e18;
		for(int i=0;i<pass[x].size();i++)
		{
			for(int j=0;j<pass[y].size();j++)
			{
				ans1=min(ans1,tim[x][i]+tim[y][j]+ans[pass[x][i]][pass[y][j]]);
			}
		}
		cout<<ans1+w[x]+w[y]<<"\n";
	}
	return 0;
}
