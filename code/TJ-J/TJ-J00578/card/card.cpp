#include <bits/stdc++.h>
using namespace std;

int a[500005];
int ans[300005];
int last[300005];
vector <int> dp[500005];
int nums[500005];

int main()
{
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n / 2; i++)
		swap(a[i], a[n - i + 1]);
	for (int i = 0; i <= m; i++) last[i] = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
	{
		if (last[a[i]] != 0x3f3f3f3f)
		{
			dp[i] = dp[last[a[i]]];
			nums[last[a[i]]]++;
		}
		else
		{
			dp[i] = dp[i - 1];
			if (last[a[i - 1]] != i - 1) dp[i - 1].clear();
			dp[i].push_back(a[i]);
			last[a[i]] = i;
			nums[i] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (nums[i]== 0) continue;
		for (int j = 0; j < dp[i].size(); j++)
		{
			ans[dp[i][j]] += nums[i];
		}
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0;
} 
