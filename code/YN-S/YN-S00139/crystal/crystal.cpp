#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[500005], d[500005], sum[500005], ans = 0;

int main() {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	d[n] = 0;

	for (ll i = 1; i <= n; i++)

		cin >> a[i];

	sort (a + 1, a + n + 1);

	d[1] = 0;

	for (ll i = 1; i <= n; i++) {

		d[i] = a[i] - a[i - 1];
		sum[i] = sum[i - 1] + d[i];
	}

	for (ll i = n; i >= 1; i--) {

		for (ll k = i - 1; k >= 1; k--) {

			if (sum[i] - sum[k] <= m) {
				ans = max (ans, i - k + (k == 1));
			} else {
				break; // jian zhi
			}
		}
	}

	cout << ans;
	return 0;
}