# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 500010;
ll n, m;
ll a[N], sum[N];

bool check(ll k)
{
	for (int i = k; i <= n; i++)
	{
		if (a[i] * k - (sum[i] - sum[i - k]) <= m) return true;
	}
	return false;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	sum[0] = 0;
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	ll l, r, ans;
	l = 1, r = n, ans = 1;
	while (l <= r)
	{
		ll mid;
		mid = (l + r) >> 1;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%lld\n", ans);
	return 0;
}//100pts
