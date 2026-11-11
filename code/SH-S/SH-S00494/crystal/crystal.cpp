#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 5e5 + 5;

int n, m, a[MAXN], s[MAXN];

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		s[i] = a[i] - a[i - 1];
	s[1] = 0;
	int l = 1, r = 1, x = m, cnt = 1, ans = 1;
	while (l < n && r < n && l <= r)
	{
		while (r < n && x - (r - l + 1) * s[r + 1] >= 0)
		{
			r++;
			x -= (r - l) * s[r];
			ans = max(ans, ++cnt);
//			cerr << "r++: " << l << " " << r << " " << x << " " << cnt << " " << ans << endl;
		}
		if (r == n) break;
//		cerr << "Mid: " << l << " " << r << " " << x << " " << cnt << " " << ans << endl;
		if ((r - l + 1) * s[r + 1] > m) break;
		while (l < n && x < (r - l + 1) * s[r + 1])
		{
			l++, cnt--, x = min(m, x + a[r] - a[l - 1]);
//			cerr << "l++: " << l << " " << r << " " << x << " " << cnt << " " << ans << endl;
		}
		if (x < (r - l + 1) * s[r + 1]) break;
	}
	cout << ans << "\n";
	return 0;
}
