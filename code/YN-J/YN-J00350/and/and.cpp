#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Maxn = 2e5 + 10;
int n, m;
ll a[Maxn];

int main() {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	ll maxn = -1;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
		maxn = max(maxn, a[i]);
	}

	sort (a + 1, a + n + 1);

	if (m == 1) {
		cout << a[n];
	} else if (m == 2) {
		ll amax = -1;

		for (int i = 1; i < n; i++) {

			for (int j = i + 1; j <= n; j++) {

				amax = max(amax, a[i] & a[j]);
			}
		}

		cout << amax;
	} else if (m == n) {
		ll ans = a[1];

		for (int i = 2; i <= n; i++)

			ans &= a[i];

		cout << ans;
	} else {
		cout << max(a[(n + 1) / 2] & a[1], a[(n + 1) / 2] & a[n]);
	}

	return 0;
}
