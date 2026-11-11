#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
bool BE;
int n, d, X[N], l[25][N], r[25][N], sl[25][N], sr[25][N];
bool ED;


namespace Sub {
	void solve() {
		int L = X[2] - X[1];
		int cnt = d / L;
		if (cnt <= 1) {
			cout << 0 << '\n';
			return;
		}
		cout << max(0LL, n - (2 * cnt - 1)) << '\n';
	}
}


void solve() {
	cin >> n >> d;
	int ok = 1;
	for (int i = 1; i <= n; i++) {
		cin >> X[i];
	}
	for (int i = 3; i <= n; i++) {
		if (X[i] - X[i - 1] != X[i - 1] - X[i - 2]) {
			ok = 0;
			break;
		}
	}
	if (ok && n >= 3) {
		Sub::solve();
		return;
	}
	// init l[] r[]
	for (int i = 1; i <= n; i++) {
		l[0][i] = r[0][i] = i;
		for (int k = 1 << 25; k; k >>= 1) {
			if (l[0][i] - k < 1) continue;
			if (X[i] - X[l[0][i] - k] <= d) l[0][i] -= k;
		}
		for (int k = 1 << 25; k; k >>= 1) {
			if (r[0][i] + k > n) continue;
			if (X[r[0][i] + k] - X[i] <= d) r[0][i] += k;
		}
		sl[0][i] = l[0][i];
		sr[0][i] = r[0][i];
	}
	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= n; j++) {
			int nl = l[i - 1][j];
			l[i][j] = l[i - 1][nl];
			sl[i][j] = sl[i - 1][j] + sl[i - 1][nl];
			int nr = r[i - 1][j];
			r[i][j] = r[i - 1][nr];
			sr[i][j] = sr[i - 1][j] + sr[i - 1][nr];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int suml = 0, sumr = 0;
			int now = i;
			for (int k = __lg(j - i + 1); k >= 0; k--) {
				if (r[k][now] < j) {
					sumr += sr[k][now];
					now = r[k][now];
				}
			}
			now = j;
			for (int k = __lg(j - i + 1); k >= 0; k--) {
				if (l[k][now] > i) {
					suml += sl[k][now];
					now = l[k][now];
				}
			}
			if (sumr - suml == 1) {
				ans++;
//				cout << i << ' ' << j << '\n';
//				cout << sumr << ' ' << suml << '\n';
			}
//			if (i == 1 && j == 4) cerr << sumr << ' ' << suml << '\n';
		}
	}
	cout << ans << '\n';
}


void clear() {
	for (int i = 1; i <= n; i++) {
		X[i] = l[0][i] = r[0][i] = 0;
	}
}


signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
//	cerr << ((&ED - &BE) >> 20) << "Mib\n";
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int tid, T;
	cin >> tid >> T;
	while (T--) {
		solve();
		clear();
	}
	return 0;
}
