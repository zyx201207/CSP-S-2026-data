#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F(i, j, k) for (ll i = (j); i <= (k); i++)
#define dF(i, j, k) for (ll i = (j); i >= (k); i--)
#define fi first
#define se second
#define pb push_back
#define _debug(x) cout << (#x) << " --> " << (x) << '\n';

using namespace std;

const int N = 5e5 + 5;
ll a[N], mns[N], pre[N];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n;
	ll m, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	ll res = 0;
	if (n > 5000) {
		ll same = a[2] - a[1], x = a[1];
		ll ans = 0;
		F(i, 1, n) {
			ll y = a[i];
			if ((x + y) * ((y - x) / same + 1) <= 2LL * m) ans = max(ans, i);
		}
		cout << ans + 1;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		ll ans = 0;
		ll sum = 0;
		for (int j = i; j >= 1; j--) {
			sum += a[i] - a[j];
			if (sum > m) break;
			ans++;
		}
		res = max(res, ans);
	}
	
	cout << res;
	
	return 0;
}
/*
5 5
1 2 4 8 9
*/

/*
5 8
-3 -1 2 2 7
*/