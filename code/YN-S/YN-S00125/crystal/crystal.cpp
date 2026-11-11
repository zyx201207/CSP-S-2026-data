#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5 * 1e5 + 10;
ll n, m, a[N], ans = 1;

ll op(ll f, ll b[]) {
	ll cnt = 1;
	ll s = a[f];
	ll use = m;
	for (int i = f - 1; i >= 1; i--) {
		if (use >= s - b[i]) {
			use -= (s - b[i]);
			cnt++;
		} else {
			return cnt;
		}
	}
	return cnt;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = n; i >= ans; i--) {
		ll cnt = op(i, a);
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}