#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 10;
int n, m, a[N], sum[N]; 

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		int l = 1, r = i - 1, res = i;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if ((i - mid) * a[i] <= sum[i - 1] - sum[mid - 1] + m)
			{
				res = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		ans = max(ans, i - res + 1);
	}
	cout << ans << '\n';
	return 0;
}
