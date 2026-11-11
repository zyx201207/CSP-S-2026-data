#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 2e6+9;
int n,l[N],r[N],f[N],g[N];
ll d,x[N];
void mian()
{
	scanf("%d%lld", &n, &d);
	for (int i = 1; i <= n; ++i) scanf("%lld", &x[i]);
	for (int i = 1; i <= n; ++i)
	{
		l[i] = lower_bound(x + 1, x + n + 1, x[i] - d) - x;
		r[i] = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
	}
	r[0] = 0;
	l[n + 1] = n + 1;
	for (int i = 1; i <= n; ++i)
	{
		f[i] = min(i, l[i + 1]) - l[i];
		if (l[i] < i && r[l[i]] == i) f[i] += f[l[i]];
	}
	for (int i = n; i >= 1; --i)
	{
		g[i] = r[i] - max(i, r[i - 1]);
		if (r[i] > i && l[r[i]] == i) g[i] += g[r[i]];
	}
	ll ans = 0;
	for (int i = 1; i < n; ++i)
	{
		if (l[i + 1] >= i) continue;
		if (r[i] <= i + 1) continue;
		int F = min(i, l[i + 2]) - l[i + 1],G = r[i] - max(r[i - 1], i + 1);
		if (!F || !G) continue;
		if (l[i] == l[i + 1]) F += f[l[i]];
		if (r[i] == r[i + 1]) G += g[r[i]];
		ans += ll(F) * G;
	}
	printf("%lld\n", ans);
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int t;
	scanf("%*d%d", &t);
	while (t--) mian();
	return 0;
}
/*
白鸟白鸟不要回头望
你要替我飞去那地方
一去那地方
那是你我共同故乡
*/