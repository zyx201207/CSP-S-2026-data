#include<bits/stdc++.h>
using namespace std;
int a[(int)2e3 + 5] , dp[(int)2e3 + 5] , cnt[(int)2e3 + 5];
int main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n , m , maxn = -1;
	cin >> n >> m;
	for(int i = 1;i <= n;i = i + 1)
	{
		cin >> a[i];
		maxn = max(maxn , a[i]);
	}
	dp[0] = 0 , dp[1] = maxn;
	for(int i = 2;i <= m;i = i + 1)
	{
		for(int j = 1;j <= n;j = j + 1)
		{
			if(j <= n - m + 1)
			{
				if(dp[i - 1] < dp[i - 1] & a[j])
				{
					dp[i] = dp[i - 1] & a[j];
					cnt[i] = cnt[i] + 1;
				}
				else
				{
					dp[i] = dp[i - 1];
				}
			}
			else
			{
				if(cnt[i] < m)
				{
					dp[i] = dp[i - 1] & a[j];
				}
				else
				{
					if(dp[i - 1] < dp[i - 1] & a[j])
					{
						dp[i] = dp[i - 1] & a[j];
						cnt[i] = cnt[i] + 1;
					}
					else
					{
						dp[i] = dp[i - 1];
					}
				}
			}
		}
	}
	cout << dp[m];
	return 0;
}
