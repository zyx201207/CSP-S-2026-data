#include <bits/stdc++.h>
#include <cassert>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 1e6 + 5;

mt19937_64 rnd(chrono::steady_clock().now().time_since_epoch().count());

int main() {
	assert(freopen("hub.in", "w", stdout));
	cin.tie(nullptr) -> sync_with_stdio(false);
	int c = 0, T = 10000;
	cout << c << " " << T << "\n";
	while (T--) {
		int n = rnd() % 10 + 2;
		// int n = 4000;
		int m = rnd() % (n - 1) + 2;
		cout << n << " " << m << "\n";
		for (int i = 2; i <= n; ++i) {
			cout << rnd() % (i - 1) + 1 << " " << i << "\n";
			// cout << i - 1 << " " << i << "\n";
		}
	}
	return 0;
}
