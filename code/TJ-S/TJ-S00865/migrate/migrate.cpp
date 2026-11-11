#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		int x[n + 10];
		int dp[n + 10];
		for(int i = 1; i <= n; i++)
		{
			cin>>x[i];
			dp[i] = 1e8;
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= d; j++)
			{
				dp[i] = min(dp[i],dp[i - j] + 1);
			}
		}
		int s = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(dp[i] == dp[j] && i != j)
				{
					s++;	
				}
			}
		}
		cout<<s<<endl;
	}
	
	return 0;
}
