#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define INF_LL 0x3f3f3f3f3f3f3f3f
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2e6 + 5;

int n;

ll d;

int lt[N], rt[N];

ll x[N];

int mn[N], num[N];

void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
		// cout << x[i] + 1000000000000000000LL << ' ';
	}
	// cout << '\n';

	for (int i = 1, j = 1; i <= n; ++i) {
		while (j < n && x[j + 1] - x[i] <= d) {
			++j;
		}
		rt[i] = j;
	}

	for (int i = n, j = n; i >= 1; --i) {
		while (j > 1 && x[i] - x[j - 1] <= d) {
			--j;
		}
		lt[i] = j;
	}

	int res = 0;
	for (int s = 1; s <= n; ++s) {
		fill(num + 1, num + n + 1, 0);
		fill(mn + 1, mn + n + 1, INF);
		mn[s] = 0, num[s] = 1;
		for (int i = s + 1; i <= n; ++i) {
			for (int j = lt[i]; j < i; ++j) {
				if (mn[i] > mn[j] + 1) {
					mn[i] = mn[j] + 1;
					num[i] = 0;
				}
				if (mn[i] == mn[j] + 1) {
					num[i] = min(3, num[j] + num[i]);
				}
			}
			if (num[i] == 2) {
				++res;
			}
		}
	}

	cout << res << '\n';
}

int main() {
	assert(freopen("migrate.in", "r", stdin));
	assert(freopen("migrate.ans", "w", stdout));

	cin.tie(0)->sync_with_stdio(0);

	int c, T;
	cin >> c >> T;
	while (T--) {
		solve();
	}

	return 0;
}