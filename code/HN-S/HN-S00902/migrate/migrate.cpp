#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],dp[5005][5005],cnt[5005][5005],sum=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	for(int z=1;z<=t;z++)
	{
		sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			for(int j=i;j<=n;j++)
			{
				dp[i][j]=1e18;
			}
		}
		for(int i=1;i<=n;i++)
		{
			dp[i][i]=0;
		}
		for(int p=2;p<=n;p++)
		{
			for(int i=1;i+p-1<=n;i++)
			{
				int j=i+p-1;
				if(a[j]-a[i]<=d)
				{
					dp[i][j]=1;
					cnt[i][j]=1;
				}
				else
				{
					for(int k=i;k<=j;k++)
					{
						if(a[k]-a[k-1]<=d&&a[k+1]-a[k]<=d&&dp[i][k]<=1e17&&dp[k][j]<=1e17)
						{
							if(dp[i][j]==dp[i][k]+dp[k][j])
							{
								cnt[i][j]++;
							}
							if(dp[i][j]>dp[i][k]+dp[k][j])
							{
								dp[i][j]=dp[i][k]+dp[k][j];
								cnt[i][j]=1;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(cnt[i][j]==2)
				{
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
