#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 1;
int a[500005], ans, n, m, b[500005];
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	int w = -1e18, k = 1e18, f = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		w = max(w, a[i]);
		k = min(k, a[i]);
	}
	int h = a[1] - a[2];
	for (int i = 1; i < n; i++)
		if ((a[i] - a[i + 1]) == h)
			f++;
	if (f == n - 1)
	{
		sort(a + 1, a + n + 1, greater<int>());
		int x = a[1], l = 0, y = 0;
		for (int i = 1; i <= n; i++)
		{
			if (m >= (x - a[i]))
			{
				m -= (x - a[i]);
				y++;
			}
		}
		cout << y;
		return 0;
	}
	sort(a + 1, a + n + 1, greater<int>());
	for (int i = 1; i <= n; i++) b[i] = a[i];
	for (int j = k; j <= w; j++)
	{
		vector<int> cnt(1000005);
		int u = m;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] < j)
			{
				if (u >= abs(j - a[i]))
				{
					u -= (j - a[i]);
					a[i] = j;
				}
			}
		}
		for (int i = 1; i <= n; i++)
			cnt[a[i] + N]++;
		for (int i = 1; i <= n; i++)
			ans = max(ans, cnt[a[i] + N]);
		for (int i = 1; i <= n; i++)
			a[i] = b[i];
	}
	cout << ans;
	return 0;
}
