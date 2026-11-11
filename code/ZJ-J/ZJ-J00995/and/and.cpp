#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
ll a[N], maxn;
bool cmp (ll x, ll y) {
	return x > y;
}
int n, m;
void dfs (int step, ll ans, int cnt) {
	if (cnt == 0) ans = a[step];
	if (cnt == m) {
		maxn = max (maxn, ans);
		return;
	}
	if (step > n + 1) return;
	dfs (step + 1, ans & a[step], cnt + 1);
	dfs (step + 1, ans, cnt);
	return;
}
int main () {

	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort (a + 1, a + n + 1, cmp);
	if (n <= 20) {
		dfs (1, 0, 0);
		cout << maxn;
		return 0;
	}
	if (m == 1) {
		cout << a[1];
		return 0;
	}
	if (m == n) {
		ll res = a[1];
		for (int i = 2; i <= n; i++) res = (res & a[i]);
		cout << res;
		return 0;
	}
	if (m == 2) {
		ll cur = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) 
			  cur = max (cur, a[i] & a[j]);
		}
		cout << cur;
		return 0;
	}
	ll ans = a[1];
	for (int i = 2; i <= m; i++)
	  ans = (ans & a[i]);
	cout << ans;
	return 0;
}
