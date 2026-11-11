#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 5e5 + 5;
ll n, m;;
ll a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	int flag = 1;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] - a[i - 1] != a[i - 1] - a[i - 2]) {
			flag = 0;
		}
	}
	ll ans = 0;
	if (flag) {
		sort(a + 1, a + 1 + n);
		ll sum = 0;
		ll j = n;
		ll cnt = 0;
		//cout << i << ' ';
		while (sum <= m && j >= 0) {
			sum += a[n] - a[j];
			j--;
			cnt++;
		}
		ans = cnt;
		cout << ans << '\n';
		return 0;
	}


	sort(a + 1, a + 1 + n);
	for (ll i = 1; i <= n; i++) {
		ll sum = 0;
		ll j = i - 1;
		ll cnt = 0;
		//cout << i << ' ';
		while (sum <= m && j >= 0) {
			sum += a[i] - a[j];
			j--;
			cnt++;
		}

		ans = max(cnt, ans);
//		cout << cnt << '\n';
	}
	cout << ans << '\n';
	return 0;
}