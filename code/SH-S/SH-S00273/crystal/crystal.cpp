#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500010];
ll s(ll l, ll r)
{
	ll sum = 0;
	for (int i = l; i <= r; i ++)
	{
		sum += a[i];
	}
	return sum;
}
int main()
{
	freopen("crystal3.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m, sum = 0;
	cin >> n >> m;
	for (ll i = 1;i <= n; i ++)
	{
		cin >> a[i];
	} 
	sort(a + 1, a + n + 1);
	if (a[1] <= 0)
	{
		ll x = a[1];
		for (ll i = 1; i <= n;i ++)
		{
			a[i] += -1 * x + 1;
		}
	}
	sum = s(1, n);
	sum += m;
	ll ans = -1e8;
	for (ll i = 1; i <= n; i ++)
	{
		ll x = sum / a[i];
		if (x > i)
		{
			if (s(1, i) + m >= a[i] * i)
			{
				ll temp = ans;
				ans = max(temp, i);
			}
		}
		else
		{
			if (s(i - x + 1, i) + m >= a[i] * x)
			{
				cout << x;
				return 0;
			}
		}
	} 
	cout << ans;
	return 0;
} 
