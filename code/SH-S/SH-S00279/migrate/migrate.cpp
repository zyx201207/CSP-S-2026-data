#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int ct,t,n,d,x[N],f[N],cnt[N],g[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> ct >> t;
	while (t--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		if (ct >= 11 && ct <= 12 || ct >= 15)
		{
			int ans = 0;
			f[1] = 0; cnt[1] = 1; g[0] = 1;
			int p = 1;
			for (int i = 2; i <= n; i++)
			{
				while (p < i && x[i] - x[p] > d) g[f[p]] -= cnt[p],p++;
				f[i] = f[p] + 1; cnt[i] = g[f[p]]; g[f[i]] += cnt[i];
				ans += (cnt[i] == 2) * (n - i + 1);
			}
			while (p <= n) g[f[p]] -= cnt[p],p++;
			cout << ans << '\n';
			continue;
		}
		if (ct >= 13 && ct <= 14)
		{
			int ans = 0;
			x[0] = -5e18;
			for (int i = 2; i < n - 1; i++)
			{
				int id1 = lower_bound(x + 1,x + n + 1,x[i] - d) - x;
				int id2 = upper_bound(x + 1,x + n + 1,x[i - 1] + d) - x - 1;
				if (x[id2] - x[id1] > d && x[id1] < x[i + 1] - d && x[id2] > x[i - 2] + d) ans++;
			}
			cout << ans << '\n';
			continue;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			// for (int j = 0; j <= n; j++) g[j] = 0;
			f[i] = 0; cnt[i] = 1; g[0] = 1;
			int p = i;
			for (int j = i + 1; j <= n; j++)
			{
				while (p < j && x[j] - x[p] > d) g[f[p]] -= cnt[p],p++;
				f[j] = f[p] + 1; cnt[j] = g[f[p]]; g[f[j]] += cnt[j];
				ans += (cnt[j] == 2);
			}
			while (p <= n) g[f[p]] -= cnt[p],p++;
		}
		cout << ans << '\n';
	}
	return 0;
}
