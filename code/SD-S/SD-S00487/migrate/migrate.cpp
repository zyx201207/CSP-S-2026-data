#include<bits/stdc++.h>
#define MX 1000
using namespace std;
long long x[MX + 10],a[MX + 10][MX + 10];
unsigned long long dp[MX + 10][MX + 10];
int main()
{
 freopen("migrate.in","r",stdin);
 freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int c,T,i,j,k;
	cin >> c >> T;
	while(T--)
	{
		long long ans = 0;
		long long n,d;
		cin >> n >> d;
		for (i = 1;i <= n;i++)
		{
			for (j = 1;j <= n;j++)
			{
				dp[i][j] = LLONG_MAX;
				a[i][j] = 0;
			}
		}
		for (i = 1;i <= n;i++)
		{
			cin >> x[i];
		}
		for (i = 1;i < n;i++)
		{
			if (x[i] + d >= x[i + 1])
			{
				dp[i][i + 1] = 1;
				a[i][i + 1] = 1;
			}
		}
		for (int len = 3;len <= n;len++)//跳跃的区间长度 
		{
			for (i = 1;i + len - 1 <= n;i++)
			{
				long long j = i + len - 1,cnt1 = 0,cnt2 = 0;
				for (k = i + 1;k < j;k++)
				{
					dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
					if (x[i] + d >= x[j])
					{
						dp[i][j] = 1;
						a[i][j] = 1;
					}
				}
				for (k = i + 1;k < j;k++)
				{
					if (dp[i][j] != LLONG_MAX && dp[i][j] == dp[i][k] + dp[k][j])
					{
						if (a[i][k] * a[k][j] == 2)
						{
							cnt1++;
						}
						if (a[i][k] * a[k][j] == 1)
						{
							cnt2++;
						}
					}
				}
				if (cnt2 == 1 && cnt2 < 1)
				{
					a[i][j] = 1;
				}
				if ((cnt2 == 2 && cnt1 < 1) || (cnt1 == 1 && cnt2 < 1))
				{
					a[i][j] = 2;
					ans++;
				}
			}
		}
		cout << ans << endl; 
		for (i = 1;i <= n;i++)
		{
			for (j = 1;j <= n;j++)
			{
				dp[i][j] = LLONG_MAX;
			}
		}
	}
	return 0;
}
/*
O(n^3) 
不留不油亮油亮,区间DP妈的跟它爆了！！！
*/







