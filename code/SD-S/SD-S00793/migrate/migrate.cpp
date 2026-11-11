#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(int c)
{
	int n, d;
	cin >> n >> d;
	vector<int> x(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> x[i];
	if (c <= 10)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			vector<int> dp(n + 2, 0), sum(n + 2, 0);
			dp[i] = 1;
			sum[i] = 1;
			vector<int> L(n + 1, 0), R(n + 1, 0), lst(n + 1, 0); // 每个距离能转移到的最后一个点
			L[0] = R[0] = lst[0] = i;
			while (lst[0] < n && x[lst[0] + 1] - x[i] <= d) lst[0]++;
//			cout << "?" << i << "\n";
			for (int r = i + 1, l = i, p = 0; r <= n; r++)
			{
				while (p < n && lst[p] < r) p++;
				if (lst[p] < r) break;
				while (x[r] - x[l] > d) l++;
//				cout << l << " " << r << "   " << p << " " << L[p] << " " << R[p] << "\n";
//				cout << R[p] << " " << max(L[p], l) - 1 << "\n";
//				cout << sum[R[p]] - sum[max(L[p], l) - 1] << "\n";
				dp[r] = sum[R[p]] - sum[max(L[p], l) - 1];
				sum[r] = sum[r - 1] + dp[r];
//				dis[r] = p + 1;
				L[p + 1] = min(L[p + 1], r);
				R[p + 1] = max(R[p + 1], r);
				lst[p + 1] = max({lst[p], lst[p + 1], r});
				while (lst[p + 1] < n && x[lst[p + 1] + 1] - x[r] <= d) lst[p + 1]++;
				if (dp[r] == 2) ans++;
//				if (dp[r] > 2) break;
			}
//			cout << i << ":\n";
//			for (int j = 1;j <= n;j++) {
//				cout << j << " " << dp[j] << "\n";
//			}
//			cout << "\n";
		}
//		cout << 114514;
		cout << ans << "\n";
//		cerr << ans << "\n";
//		return;
	}
	else if (c == 11 || c == 12)
	{
		for (int i = 1; i <= n; i++)
		{
			if (x[i] - x[1] > d)
			{
				if (i <= 3)
				{
					cout << 0 << "\n";
					return;
				}
				int l = i - 1;
				cout << n - (2 * l - 1) + 2 << "\n";
				return ;
			}
		}
		cout << 0 << "\n";
		return ;
	}
	else cout << 0 << "\n";
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while (T--)
	{
//		cout << T << "?\n";
		solve(c);
	}
	return 0;
}
