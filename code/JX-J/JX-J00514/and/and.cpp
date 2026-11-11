#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	vector<int> a(n + 1);
	int mxA = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		mxA = max(mxA, a[i]);
	}
	
	if (n <= 20)
	{
		int ans = 0;
		for (int i = 1LL; i < 1LL << n; i++)
		{
			int res = (1LL << 20) - 1LL;
			int cnt = 0;
			int cur = 1;
			for (int j = i; j; j >>= 1LL)
			{
				if (j & 1LL)
				{
					res &= a[cur];
					cnt++;
				}
				cur++;
			}
			if (cnt == m)
			{
				ans = max(ans, res);
			}
		}
		cout << ans << "\n";
		return 0;
	}
	
	if (m == 1)
	{
		cout << mxA << "\n";
		return 0;
	}
	else if (m == 2)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j) continue;
				ans = max(ans, (a[i] & a[j]));
			}
		}
		cout << ans << "\n";
		return 0;
	}
	else if (m == n)
	{
		int res = (1LL << 20) - 1LL;
		for (int i = 1; i <= n; i++)
		{
			res &= a[i];
		}
		cout << res << "\n";
		return 0;
	}
	
	return 0;
}
