# include <bits/stdc++.h>
# define ll long long
# define inf 0x3f3f3f3f3f3f3f3f

using namespace std;

const ll N = 5e5 + 5;
ll n, m, res = -inf, a[N], sum[N];

bool check (ll x, ll y) {
	ll cost = (y - x + 1) * a[y] - (sum[y] - sum[x - 1]);
	if (cost <= m) return 1;
	return 0; 
}

int main () {
	
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i ++) cin >> a[i];
	sort (a + 1, a + n + 1);
	for (ll i = 1; i <= n; i ++) 
		sum[i] = sum[i - 1] + a[i]; 
	for (ll i = 1; i <= n; i ++) {
		ll l = i, r = n, mid, ans;
		while (l <= r) {
			mid = (l + r) / 2;
			if (check (i, mid)) {
				ans = mid;
				l = mid + 1;
			} else r = mid - 1;
		}
		res = max (res, ans - i + 1);
	}
	cout << res;
	
	return 0;
}

/*
题意：在 m 次操作内让尽可能多的 ai 相同 
*/
