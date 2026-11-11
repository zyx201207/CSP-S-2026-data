#include <bits/stdc++.h>

#define int long long
// ok fine
using namespace std;
const int N = 2e6 + 6;
// n <= 2e6
int c;
int n, d;
int x[N];
int f[N], g[N];
int r[N], l[N];
int cnt[N];
void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	return ;
}
inline void sub1() { // c >= 1 && c <= 10
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	int j = 1;
	for (int i = 1; i <= n; i++) {
		while (j <= n && x[j] - x[i] <= d) j++;
		r[i] = j - 1;
	}
	j = 1;
	for (int i = 1; i <= n; i++) {
		while (j <= i && x[i] - x[j] > d) j++;
		l[i] = j;
		//cerr << l[i] << ' ' << r[i] << '\n';
	}
	int ans = 0;
	for (int s = n; s >= 1; s--) {
		f[s] = 0;
		g[s] = 1;
		for (int i = s + 1; i <= n; i++) g[i] = f[i] = 0;
		int R = s;
		while (R <= n) {
			if (r[R] == R) break;
			for (int i = R + 1; i <= r[R]; i++) {
				f[i] = f[R] + 1;
			}
			R = r[R];
		}
		for (int i = 0; i <= n; i++) cnt[i] = 0;
		cnt[0]++;
		int j = s;
		for (int i = s + 1; i <= n; i++) {
			if (!f[i]) break;
			// [l[i], i], f[i] - 1 num <= 2
			while (j < l[i]) {
				cnt[f[j]] -= g[j];
				j++;
			}
			if (cnt[f[i] - 1] == 2) ans++;
			g[i] = min(cnt[f[i] - 1], 3ll);
			cnt[f[i]] += g[i];
		}
	}
	cout << ans << '\n';
	return ;
}
inline void sub2() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	if (n == 1) {
		cout << "0\n";
		return ;
	}
	int D = d / (x[2] - x[1]);
	if (D <= 1) {
        cout << "0\n";
        return ;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i + 2 * D - 1 <= n) ans++;
	}
	cout << ans << '\n';
	return ;
}
signed main() {
	// if in submit
		freopen("migrate.in", "r", stdin);
		freopen("migrate.out", "w", stdout);
	// endif
	// if in test
		// freopen("migrate4.in", "r", stdin);
		// freopen("migrate.out", "w", stdout);
	// endif

	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> c >> T;
	while (T--) {
		// solve
		// solve();
		if (c >= 11 && c <= 12) {
			sub2();
		}
		else sub1();
	}
	return 0;
}
/*
1 1
5 2
1 2 3 4 5
*/
