#include <bits/stdc++.h>
using namespace std;

long long dp1[100010][100010];

int c,t;
long long x[2000005],ans;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin>>c>>t;

	while(t--)
	{
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}

		//dp[i][j]=k从i到j有k个方法
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=d;j++)
			{
				dp1[x[i]+5005][x[i+j]+5005]++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=d;j++)
			{
			    //cout<<dp[i][j];
				if(dp1[i+5005][j+5005]==2)
				{
					ans++;
				}
			}
			//cout<<endl;
		}
		cout<<ans+1<<endl;
	}

	return 0;
}
