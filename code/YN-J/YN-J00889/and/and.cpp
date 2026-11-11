#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e5 + 10;
ll n, m;
ll a[N];

bool cmp(ll a, ll b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("and.in", "r", stdin);

	freopen("and.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 30; i >= 0; i--) {
		ll cnt = 0;
		ll cnt_2 = 0;
		for (int j = 1; j <= n; j++) {
			if ((a[j] & 1 << i ) == 1 << i) {
				cnt++;
			}
			if (a[j] != 0)
				cnt_2++;
		}
		if (cnt_2 - cnt < m)
			continue;
		if (cnt >= m) {
			for (int j = 1; j <= n; j++) {
				if ((a[j] & 1 << i ) == 0) {
					cout << a[j] << " ";
					a[j] = 0;
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		//cout << a[i] << " ";
		if (m <= 0)
			break;
		if (a[i] != 0) {
			if (ans == 0)
				ans = a[i];
			else
				ans &= a[i];
			m--;
		}
	}
	cout << ans;
	return 0;
}