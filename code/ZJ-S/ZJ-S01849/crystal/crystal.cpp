#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;

int n;
ll m;
ll a[N];
ll pre[N];

inline bool check(ll x)
{
	ll res = 5e17 + 5;
	for (int l = 1; l <= n - x + 1; l++)
	{
		int r = l + x - 1;
		res = min(res, a[r] * (r - l + 1) - (pre[r] - pre[l - 1]));
	}
	return res <= m;
}

inline ll z_bs()
{
	ll l = 1, r = n, mid = (l + r + 1) >> 1;
	while (l < r)
	{
		if (check(mid)) l = mid;
		else r = mid - 1;
		mid = (l + r + 1) >> 1;
	}
	return l;
}

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d %lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	printf("%lld\n", z_bs());
	return 0;
}

