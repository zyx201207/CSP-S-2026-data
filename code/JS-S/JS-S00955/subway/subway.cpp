#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500005],dp[505][505];
vector<pair<int,int>> g[500005];
int read()
{
	int f=0,x=0;char c=getchar();
	while(c<48||c>57){if(c=='-')f=1;c=getchar();}
	while(c>=48&&c<=57) x=(x<<3)+(x<<1)+(c&15),c=getchar();
	return (f==1?-x:x);
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j) dp[i][j]=1e16;
	for(int i=1;i<=n;i++)
	{
		int k=read();
		for(int j=1;j<=k;j++)
		{
			int a=read(),t=read();
			g[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++)
	{
		int s=g[i].size()-1;
		for(int j=0;j<=s;j++)
			for(int k=j+1;k<=s;k++)
			{
				int x=g[i][j].first,w1=g[i][j].second;
				int y=g[i][k].first,w2=g[i][k].second;
				dp[x][y]=min(dp[x][y],w1+w2);
				dp[y][x]=min(dp[y][x],w1+w2);
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	while(q--)
	{
		int x=read(),y=read(),ans=1e18;
		int s1=g[x].size()-1,s2=g[y].size()-1;
		for(int i=0;i<=s1;i++)
			for(int j=0;j<=s2;j++)
			{
				int xx=g[x][i].first,w1=g[x][i].second;
				int yy=g[y][j].first,w2=g[y][j].second;
				ans=min(ans,dp[xx][yy]+w1+w2);
			}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
