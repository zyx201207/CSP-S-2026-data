#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, m, res, a[N], sum[N];
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (register int i = 1;i <= n; ++ i)
	{
		cin >> a[i];
		a[i] += (1000000000000);
	}
	sort (a + 1, a + n + 1);
	for (register int i = 1;i <= n; ++ i)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	for (register int i = 1;i <= n; ++ i)
	{
		if (i == 1) {res = 1; continue;}
		int l = 1, r = i, ans = 0;
		while (l <= r)
		{
			int mid = l + r >> 1;
			if ((a[i] * (i - mid + 1)) - (sum[i] - sum[mid - 1]) <= m) r = mid - 1, ans = mid;
			else l = mid + 1;
		}
		//cout << ans << " ";
		if (ans > 0) res = max(res, i - ans + 1);
	}
	cout << res << "\n";
	return 0;
}//Oct31==Dec25?
