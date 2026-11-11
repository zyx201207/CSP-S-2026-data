#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll N = 2000010;
ll c, n, d, id[N], p[N], sd[N], sum[N]; pll dp[N];
void brute1()
{
	for (ll i = 1; i <= n; i++)
	{
		ll pos = lower_bound(p + 1, p + i, p[i]-d) - p;
		if (pos >= i) id[i] = 0;
		else id[i] = pos;
	}
	ll ret = 0;
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= n; j++) dp[j] = {0, 0}, sum[j] = 0;
		sum[0] = 1;
		for (ll j = i+1; j <= n; j++)
		{
			if (!id[j]) break;
			ll tmp = max(id[j], i), d = dp[tmp].first+1;
			ll ttt = min(3LL, sum[d-1]-dp[tmp].second);
			dp[j] = {d, sum[d]}, sd[j] = ttt, sum[d] += ttt;
		}
		for (ll j = i+1; j <= n; j++)
		{
			if (!id[j]) break;
			if (sd[j] == 2) ret++;
		}
	}
	printf("%lld\n", ret);
}
void brute2()
{
	ll pos = lower_bound(p + 1, p + n, p[n]-d) - p;
	if (pos >= n-1) return puts("0"), void();
	ll tmp = n-pos;
	printf("%lld\n", max(0LL, n-tmp*2+1));
}
void solve()
{
	scanf("%lld%lld", &n, &d);
	for (ll i = 1; i <= n; i++) scanf("%lld", &p[i]);
	if (n <= 5000) brute1();
	else if (c == 11 || c == 12) brute2();
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ll T; scanf("%lld%lld", &c, &T);
	while (T--) solve();
	return 0;
}
