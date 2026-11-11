#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(x, y, z) for(ll x = y; x <= z; x++)
const ll INF = 0x3f3f3f3f3f3f3f3f, N = 5e5 + 10;
ll n, m;
ll a[N];

ll ans = -INF;
ll qs[N];
signed main()
{
	freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	f(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	f(i, 1, n) qs[i] = qs[i - 1] + a[i];
	f(i, 1, n)
	{
		ll l = 1, r = i, mid;
		while(l <= r)
		{
			mid = (l + r) / 2;
			ll nu = i - mid + 1;
			if(nu * a[i] - (qs[i] - qs[mid - 1]) <= m)
			{
				ans = max(ans, nu);
				r = mid - 1;
			}
			else l = mid + 1;
		}
	}
	cout << ans << endl;
	return 0;
}
/*
5 5
1 2 4 8 9


5 8
-3 -1 2 2 7

*/
