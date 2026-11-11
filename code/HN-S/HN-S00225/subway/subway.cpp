#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;
long long dp[510][M],ans;
int w[M],k[510],a[510][M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out ","w",stdout);

	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int l1,l2;
			cin>>l1>>l2;
			a[i][l1]=l2;
		}
	}
	
	while(q--)
	{
		for(int i=1;i<=500;i++)
		{
			for(int j=1;j<=1000;j++)
			{
				dp[i][j]=999999999;
			}
		}
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=n;i++)
		{
			if(a[i][x]>0)
			{
				for(int j=1;j<=m;j++)
				{
					if(a[i][j]>0)
					{
						dp[i][j]=a[i][x]+w[x];
					}
				}
			}
		}
		
		for(int j=1;j<=m;j++)
		{	
			long long mini=999999999;
			for(int i=1;i<=n;i++)
			{
				if(a[i][j]==0)
				{
					continue;
				}
				if(dp[i][j]!=999999999)
				{
				mini=min(mini,dp[i][j]+a[i][j]);
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(a[i][j]==0)
				{
					continue;
				}
				dp[i][j]=min(dp[i][j],mini+a[i][j]);
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			long long mini=999999999;
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]==0)
				{
					continue;
				}
				mini=min(mini,dp[i][j]);
			}
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]==0)
				{
					continue;
				}
				dp[i][j]=mini;
			}
		}
		
		ans=999999999;
		for(int i=1;i<=n;i++)
		{
			ans=min(ans,dp[i][y]+a[i][y]);
		}
		
		cout<< ans+w[y] <<endl;
	}
	
	return 0;	
} 
