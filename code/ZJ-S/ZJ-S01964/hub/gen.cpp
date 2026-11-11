#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define INF_LL 0x3f3f3f3f3f3f3f3f
using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937_64 rd(chrono::steady_clock().now().time_since_epoch().count());

ll rnd(ll l, ll r) {
	return (rd() % (r - l + 1)) + l;
}

const int N = 1e6 + 5;

int main() {
	assert(freopen("hub.in", "w", stdout));

	cin.tie(0)->sync_with_stdio(0);

	int c = 0, T = 10;
	cout << c << ' ' << T << '\n';
	while (T--) {
		int n = 10, k = rnd(2, n);
		cout << n << ' ' << k << '\n';
		for (int i = 1; i < n; ++i) {
			cout << rnd(1, i) << ' ' << i + 1 << '\n';
		}
		cout << '\n';
	}

	return 0;
}