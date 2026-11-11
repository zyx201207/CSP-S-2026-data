#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	i64 m;
	cin >> n >> m;
	vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin() + 1, a.end());
	vector<i64> sum(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	int ans;
	for (int l = 1, r = 1; r <= n; r++)
	{
		if (l == r) continue;
		while (l <= r && 1ll * (r - l + 1) * a[r] - (sum[r] - sum[l - 1]) > m)
		{
			l++;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans << endl;
	return 0;
}
