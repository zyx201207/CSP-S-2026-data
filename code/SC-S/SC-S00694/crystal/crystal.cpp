#include <bits/stdc++.h>
using namespace std;
long long n,m; 
long long a[500005];
long long sum[500005];
int dp[500005];
int fir = 1;
int ans = -1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i ++)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1;i <= n;i ++)
	{
		if (a[i] * (i - fir + 1) - (sum[i] - sum[fir - 1]) <= m)
		{
			dp[i] = i - fir + 1;
		}
		else
		{
			while(a[i] * (i - fir + 1) - (sum[i] - sum[fir - 1]) > m)
			{
				fir ++;
			}
			dp[i] = i - fir + 1;
		}
		ans = max(ans,dp[i]);
	}
	cout << ans;
	return 0;
}
//33961573wwh
//14:31   密码依旧没发 
//14:46   O(n)WA做法
//14:52   O(n^2)TLE做法 
//14:56   O(n)??做法 