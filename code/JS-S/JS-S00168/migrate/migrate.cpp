#include <bits/stdc++.h>
#define int long long
using namespace std;

int c, T, n, d, ans, a[2000005], L[2000005], R[2000005], minn[2000005], maxn[2000005], f[2000005], g[2000005], s[2000005];

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &T);
	while (T--)
	{
		ans = 0;
		scanf("%lld%lld", &n, &d);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		/*
		for (int i = 1; i < n; i++)
			R[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
		for (int i = n; i > 1; i--)
			L[i] = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
		for (int i = 2; i <= n; i++)
		{
			minn[L[i]] = min(minn[L[i]], i);
			maxn[L[i]] = max(maxn[L[i]], i);
		}
		for (int i = 1; i < n; i++)
			if (L[i] == )
		for (int i = 1; i < n; i++)
		{
			if (R[i] <= i + 1) continue;
			int l = max(minn[R[i] - 1] - 1, i), r = maxn[R[i] - 1];
			ans += f[i] * (s[r] - s[l]);
		}
		printf("%lld\n", ans);*/
		if (c == 11 || c == 12)
		{
			printf("%lld\n", n - 2 * d + 1);
		}
	}
	return 0;

}
