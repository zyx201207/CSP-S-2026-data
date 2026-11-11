#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a.begin() + 1, a.end());
	vector<int> sum(n + 1, 0);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int l = 1, r = i, res = 0;
		while (l <= r)
		{
			int mid = l + r >> 1;
			if ((i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m)
			{
				res = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		ans = max(ans, i - res + 1);
	}
	cout << ans; 
	return 0;
}
