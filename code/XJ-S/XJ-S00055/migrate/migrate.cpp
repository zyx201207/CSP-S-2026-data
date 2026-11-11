#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, x[2000005], dis[2000005], dp[2000005];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>c>>t;
	while(t--)
	{
		long long cnt=0;
		memset(dp, 0, sizeof(dp));
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<=d+1;i++)
		{
			dis[i]=1;
			dp[i]=1;
		}
		for(int i=d+2;i<=n;i++)
		{
			dis[i]=dis[i-d]+1;
			dp[i]=dis[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(dp[i]==2)
			{
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
