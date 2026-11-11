#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[505][50005],dp[505][50005],xl[505][50005];
long long c,n,m,d,q,maxx=0;
void dfs(int w,int z,int s,int l)
{
	s+=b[l][w];
	for(long long i=1;i<=q;i++)
	{
		if(w==z)
		{
			if(s>maxx)
				maxx=s;
			break;
		}
		if(dp[i][w]=-1)
			break;
		if(dp[i][w]!=0)
		{
			dfs(dp[i][w],z,s+b[i][w],i);
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		int h,z=0;
		cin>>h;
		for(long long j=1;j<=h;j++)
		{
			int u,t;
			cin>>u>>t;
			b[i][u]=t;
			dp[i][u]=z;
			z=b[i][u];
		}
		dp[i][z]=-1;
	}
	for(long long i=1;i<=q;i++)
	{
		int u,v;
		cin>>u>>v;
		xl[i][u]=v;
	}
	for(long long i=1;i<=q;i++)
	{
		int j=1;
		while(1)
		{
			if(xl[i][j]>0)
				break;
			else
				j++;
		}
		dfs(j,xl[i][j],a[j],i);
		cout<<maxx<<endl;
	}
	return 0;
}
