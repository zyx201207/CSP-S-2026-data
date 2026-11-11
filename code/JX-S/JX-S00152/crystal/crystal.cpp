#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m;
vector<ll> a, sum;

ll get(ll l, ll r)
{
	return a[r] * (r - l + 1) - (sum[r] - sum[l - 1]);
}

ll val(ll i)
{
	int l = 1, r = i;
	while (r - l > 1)
	{
		ll mid = (l + r) >> 1;
		if (get(mid, i) > m) l = mid;
		else if (get(mid, i) <= m) r = mid;
	}
	if (get(l, i) <= m) return (i - l + 1);
	else return (i - r + 1);
}

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	a.resize(n + 1);
	for (ll i = 1; i <= n; i++) cin >> a[i];
	
	sort(a.begin() + 1, a.end());
	sum.assign(n + 2, 0);
	for (ll i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	
	ll mxV = 0;
	for (ll i = 1; i <= n; i++) mxV = max(mxV, val(i));
	cout << mxV << "\n";
	
	return 0;
}
