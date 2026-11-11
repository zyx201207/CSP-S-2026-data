#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,v[500005];
struct node
{
	long long v,w;
};
vector<node>e[500005];
long long dp[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&v[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		int u,w2;
		for(int j=1;j<=k;j++)
		{
			scanf("%d%d",&u,&w2); 
			node o;
			o.v=i;
			o.w=w2;
			e[u].push_back(o);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			dp[i][j]=1e18;
	}
	for(int i=1;i<=m;i++)
	{
		for(auto v:e[i])
		{
			for(auto u:e[i])
			{
				if(u.v==v.v)
					dp[v.v][u.v]=0;
				else dp[v.v][u.v]=min(dp[v.v][u.v],v.w+u.w);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	int l,r;
	while(q--)
	{
		long long ans=1e18;
		scanf("%d%d",&l,&r);
		for(auto v:e[l])
		{
			for(auto u:e[r])
			{
				ans=min(ans,dp[v.v][u.v]+v.w+u.w);
			}
		}
		ans=ans+v[l]+v[r];
		printf("%lld\n",ans);
	}
	return 0;
} 
