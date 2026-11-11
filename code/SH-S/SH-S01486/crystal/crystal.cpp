#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 500009;
ll n, m, a[N], w[N], s[N];
ll Wright (ll Wij, ll i, ll j) { return Wij - (s[j - 1] - s[i - 1]) + (j - i) * w[j]; }

bool OK (ll len) 
{
	ll l = 1, r = len;
	ll tmpW = 0;
	for (ll i = l;i < r;i++) tmpW += (i + 1 - l) * w[i];
	if (tmpW <= m) return 1;
	while (r <= n)
	{
		ll Wij = tmpW;
		tmpW = Wright(Wij, l, r);
		if (tmpW <= m) return 1;
		++l, ++r;
	}
	return 0;
}

int main ()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (ll i = 1;i <= n;i++) scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	for (ll i = 1;i < n;i++) w[i] = a[i + 1] - a[i], s[i] = s[i - 1] + w[i];
	ll l = 1, r = n, mid = (1 + n) / 2;
	ll ans = -1;
	while (l <= r)
	{
		if (OK(mid))
		{
			ans = mid;
			l = mid + 1;
			mid = (l + r) / 2;
		}
		else
		{
			r = mid - 1;
			mid = (l + r) / 2;
		}
	}
	if (ans == 1) printf("0");
	else printf("%lld", ans);
	return 0;
}

