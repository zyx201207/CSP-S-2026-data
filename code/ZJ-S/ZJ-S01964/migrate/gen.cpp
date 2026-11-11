#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define INF_LL 0x3f3f3f3f3f3f3f3f
using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937_64 rd(chrono::steady_clock().now().time_since_epoch().count());

const int N = 2e6 + 5;

const ll V = 1e18;

ll rnd(ll l, ll r) {
	return (rd() % (r - l + 1)) + l;
}

ll a[N];

int main() {
	assert(freopen("migrate.in", "w", stdout));

	cin.tie(0)->sync_with_stdio(0);

	int c = 0, T = 1;
	cout << c << ' ' << T << '\n';
	while (T--) {
		int n = 4000;
		ll k = rnd(0, V);
		cout << n << ' ' << k << '\n';
		for (int i = 1; i <= n; ++i) {
			a[i] = rnd(-V, V);
		}
		sort(a + 1, a + n + 1);
		a[0] = -INF_LL;
		for (int i = 1; i <= n; ++i) {
			while (a[i - 1] >= a[i]) {
				++a[i];
			}
			cout << a[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}