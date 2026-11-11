#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k[505],a,t;
int x,y;
//以上是题目中的变量
vector< pair<int,int> >st[500005];//用于记录哪些线经过该站以及从该站站厅到线路的时间 
vector< pair<int,int> >g[505];//用于记录该线与哪些线是联通的，并记录其转线时间 
long long dp[505][505]; 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d%d",&a,&t);
			st[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]=1e18;
	for(int i=1;i<=m;i++)
	{
		for(int j1=0;j1<st[i].size();j1++)
		{
			for(int j2=j1+1;j2<st[i].size();j2++)
			{
				int minn=min(st[i][j2].first,st[i][j1].first),maxn=max(st[i][j2].first,st[i][j1].first);
				dp[minn][maxn]=min(dp[minn][maxn],1ll*(st[i][j2].second+st[i][j1].second));
				dp[maxn][minn]=min(dp[minn][maxn],1ll*(st[i][j2].second+st[i][j1].second));
			}
		}
	}
for(int kk=1;kk<=n;kk++)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=min(dp[i][j],dp[i][kk]+dp[kk][j]);
		}
	}
}
	for(int i=1;i<=q;i++)
	{	
		scanf("%d%d",&x,&y);
		long long ans=1e18;
		for(int j=0;j<st[x].size();j++)for(int j1=0;j1<st[y].size();j1++)ans=min(ans,dp[st[x][j].first][st[y][j1].first]+w[x]+w[y]+st[x][j].second+st[y][j1].second);
		printf("%lld\n",ans);
	}
	return 0;
}
