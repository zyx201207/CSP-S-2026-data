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

int val[N];

void work(int *res) {
	for (int i = n; i >= 1; --i) {
		val[i] = 0;
		if (rt[i] == i || rt[i - 1] == rt[i]) { continue; }
		val[i] += val[rt[i]] + rt[i] - max(i, rt[i - 1]);
		// cout << i << "===" << val[i] << '\n';
	}
	for (int i = 1, l = 1, r = 1; i < n; ++i) {
		l = r;
		while (r <= n && lt[r] <= i) { ++r; }
		if (l == r) {
			res[i] = 0;
			continue;
		}
		res[i] = max(0, min(r - 1, rt[i]) - max(l, i + 2) + 1);
		if (rt[i] == rt[i + 1] && l <= rt[i] && rt[i] < r) {
			res[i] += val[rt[i]];
		}
	}
}

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

	// for (int i = 1; i <= n; ++i) {
	// 	cout << rt[i] << ' ' << lt[i] << '\n';
	// }

	static int r1[N], r2[N];
	work(r1);
	for (int i = 1; i <= n; ++i) {
		swap(lt[i], rt[i]);
		lt[i] = n - lt[i] + 1;
		rt[i] = n - rt[i] + 1;
	}
	reverse(lt + 1, lt + n + 1);
	reverse(rt + 1, rt + n + 1);
	work(r2);

	ll res = 0;
	for (int i = 1; i < n; ++i) {
		// cout << i << ' ' << r1[i] << ' ' << r2[n - i] << '\n';
		res += 1LL * r1[i] * r2[n - i];
	}
	cout << res << '\n';
}

int main() {
	assert(freopen("migrate.in", "r", stdin));
	assert(freopen("migrate.out", "w", stdout));

	cin.tie(0)->sync_with_stdio(0);

	int c, T;
	cin >> c >> T;
	while (T--) {
		solve();
	}

	return 0;
}