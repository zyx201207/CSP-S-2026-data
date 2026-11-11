#include<bits/stdc++.h>
using namespace std;
int a[200002];
long long dp[200002]; //dp[i]:背包容量为i时按位与的最大值? 
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	int ans;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (m == n) //全选 全部进行与运算 
	{
		ans = a[0];
		for (int i = 1; i < n; i++)
			ans &= a[i];
		cout << ans;
		return 0;
	}
	//01背包能不能写一点 我忘了怎么写了 
	sort(a, a + n);
	dp[0] = LLONG_MAX;
	for (int i = 0; i < n; i++)
	{
		for (int j = m; j > 0; j--)
		{
			dp[j] = max(dp[j], dp[j - 1] & a[i]);
		}
	}
	cout << dp[m];
	return 0;
} 
