#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[2000010];
int dp[5010][5010],v[5010][5010];
int n;
void floyd()
{
	for(int i=2;i<n;i++)
	{
		for(int j=1;j<n-1;j++)
		{
			for(int k=3;k<=n;k++)
			{
				if(dp[j][i]!=0x3f3f3f3f && dp[i][k]!=0x3f3f3f3f && k>i && i>j)
				{
					if(dp[j][k]==dp[j][i]+dp[i][k])
					{
						v[j][k]++;
					}
					else if(dp[j][k]>dp[j][i]+dp[i][k])
					{
						v[j][k]=0;
						dp[j][k]=dp[j][i]+dp[i][k];
					}
				}
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		ll d;
		int ans=0;
		cin>>n>>d;
		memset(dp,0x3f,sizeof(dp));
		memset(v,0,sizeof(v));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
				{
					dp[i][j]=1;
				}
			}
		}
		floyd();
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(v[i][j]==1)
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
