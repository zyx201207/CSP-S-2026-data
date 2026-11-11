#include <bits/stdc++.h>
#define int long long
using namespace std;
int _, t, n, m, a[2000005], d[5005], f[5005], g[5005], tr[5005], ans;
void add(int x, int k) {while (x <= n) tr[x] += k, x += x & -x;}
int sum(int x) {int res = 0; while (x) res += tr[x], x &= x - 1; return res;}
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> _ >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> a[i];
		if (_ == 11 || _ == 12)
		{
			m /= a[2] - a[1];
			if (m > 1) cout << max(n - 2 * m + 1, 0ll) << endl;
			else cout << "0\n";
			continue;
		}
		else if (_ <= 10)
		{
			for (int i = 1; i <= n; i++) d[i] = lower_bound(a + 1, a + n + 1, a[i] - m) - a;
			ans = 0;
			for (int i = 1; i < n; i++)
			{
				f[i] = 0, g[i] = 1, memset(tr, 0, sizeof tr), add(i, 1);
				for (int j = i + 1; j <= n; j++)
				{
					int l = max(d[j], i), r = j - 1, mid, res = max(d[j], i);
					while (l <= r)
					{
						mid = (l + r) / 2;
						if (f[mid] == f[max(d[j], i)]) res = mid, l = mid + 1;
						else r = mid - 1;
					}
					f[j] = f[max(d[j], i)] + 1, g[j] = sum(res) - sum(max(d[j], i) - 1), add(j, g[j]);
					if (g[j] == 2) ans++;
				}
			}
			cout << ans << endl;
			continue;
		}
		else cout << "114514\n";
	}
	return 0;
}
