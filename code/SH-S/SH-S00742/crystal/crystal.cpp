#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, ans;
ll x[500005];
ll s[500005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++)
		cin >> x[i];
	sort(x + 1, x + n + 1);
	for(ll i = 1; i <= n; i++)
		s[i] = s[i - 1] + x[i];
	for(ll i = 1; i <= n; i++)
	{
		ll l = 1, r = i, mid, p;
		while(l <= r)
		{
			mid = (l + r) / 2;
			if(x[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m)
				r = mid - 1, p = mid;
			else
				l = mid + 1;
		}
		ans = max(ans, i - p + 1);
	}
	cout << ans;
	return 0;
}

