#include<bits/stdc++.h>
using namespace std;

long long c,t;
long long n,d;
long long a[200005];
long long dp[5001][5001] , dp_[5001][5001];
long long ans = 0;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		ans = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i];
			for(int j = 1;j <= n;j++)
			{
				if(j > i) dp[i][j] = -1 , dp_[i][j] = 0;
				else dp[i][j] = 0 , dp_[i][j] = 0;
			}
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= i;j++)
			{
				if(i == j)
				{
					dp[i][j] = 1 , dp_[i][j] = 1;
					continue;
				}
			}
			for(int j = 1;j < i;j++)
			{
				for(int z = i-1;z >= j;z--)
				{
					if(a[i] - a[z] <= d)
					{
						if(dp_[z][j] <= 0) break;
						if(dp[z][j] + 1 == dp[i][j]) dp_[i][j]+=dp_[z][j];
						else 
						{
							dp_[i][j] = dp_[z][j];
							dp[i][j] = dp[z][j] + 1;
						}
					}
				}
				//cout << dp_[i][j] << " ";
				if(dp_[i][j] == 2) ans++;
			}
			//cout << '\n';
		}
		cout << ans << '\n';
	}
	return 0;
}
