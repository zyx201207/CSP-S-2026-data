#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], s[500005], l, r, mid, ans;
bool check(int x)
{
	for (int i = x; i <= n; i++) if (x * a[i] - s[i] + s[i - x] <= m) return 1;
	return 0;
}
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	l = 1, r = n;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}
//Merry Christmas(?
