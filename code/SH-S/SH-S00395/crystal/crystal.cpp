#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[500005], sum[500005];
bool check(ll num)
{
	for (ll i = num; i <= n; i++)
	{
		if (num * a[i] - (sum[i] - sum[i - num]) <= m) return 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (ll i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	ll l = 1, r = n;
	while (l < r)
	{
		ll mid = (l + r + 1) / 2;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l;
} 
