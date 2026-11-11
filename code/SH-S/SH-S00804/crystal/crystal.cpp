#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 500010;
ll n, m, ret, a[N], sum[N];
void solve()
{
	scanf("%lld%lld", &n, &m);
	for (ll i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (ll i = 1; i <= n; i++) sum[i] = sum[i-1]+a[i];
	for (ll i = 1; i <= n; i++)
	{
		ll l = 1, r = i-1, best = i;
		while (l <= r)
		{
			ll mid = (l + r) >> 1;
			if (a[i]*(i-mid)-(sum[i-1]-sum[mid-1]) <= m) r = mid-1, best = mid;
			else l = mid+1; 
		}
		ret = max(ret, i-best+1);
	}
	printf("%lld\n", ret);
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll T = 1;
	while (T--) solve();
	return 0;
}
