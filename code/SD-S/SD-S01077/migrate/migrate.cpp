#include <bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long x[2000010];
long long dp[10010][10010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];
		}
		if(x[n]<=d)
		{
			cout<<"0";
			continue;
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					if(abs(x[j]-x[k])<d)
					{
						dp[j][k]=min(dp[j][k],dp[j-1][k]+1);
					}
				}
			}
			
		}
		cout<<dp[n][d];
	}
	return 0;
}
