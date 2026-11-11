#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
ll n, m;
ll a[maxn];
ll mj[maxn];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	bool flag = true;
	ll cz;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 2) {
			cz = a[i] - a[i - 1];
		} else if (i > 2) {
			if (cz != (a[i] - a[i - 1]))
				flag = false;
		}
	}
	if (flag) {
		mj[1] = 1;
		ll i = 1;
		while (m >= cz * mj[i]) {
			m -= (cz * mj[i]);
			mj[i + 1] += (mj[i] + 1);
			i++;
		}
		cout << mj[i];
		return 0;
	}
	sort(a + 1, a + n + 1);
	ll ans = 0;
	for (ll i = n; i >= 2; i++) {
		ll m1 = m, cnt = 1;
		ll j = i - 1;
		while (m1 >= (a[i] - a[j])) {
			m1 -= (a[i] - a[j]);
			j--;
			cnt++;
			if (j == 0)
				break;
		}
		ans = max(ans, cnt);
		if (ans == n) {
			cout << n;
			return 0;
		}
	}
	cout << ans;
	return 0;
}