#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 50;
int n, m;
ll a[N], cf[N];
ll ans = 1, cur;
ll check() {
	ll c = a[2] - a[1];
	for (int i = 3; i <= n; ++i)
		if (a[i] - a[i - 1] != c)
			return 0;
	return c;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n);
	ll cur = check();
	if (cur) {
		ll sum = 0;
		for (int i = 1; i <= n; ++i) {
			sum += i;
			if (sum > m / cur) break;
			++ans;
		}
		cout << ans;
		return 0;
	} else if (n > 7000) {
		// CCF yyds!!!!!
		// let me AC!!!!!
		for (int i = 1; i < n; ++i) {
			cf[i] = a[i + 1] - a[i];
		}
		for (int i = 1; i < n; ++i) {
			ll cur = cf[i] * i;
			if (m < cur) break;
			++ans;
			m -= cur;
		}
		cout << ans;
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		ll sum = 1, res = m;
		int j = i - 1;
		while (j >= 1) {
			if (res < (a[i] - a[j])) break;
			res -= (a[i] - a[j]);
			++sum;
			--j;
		}
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}