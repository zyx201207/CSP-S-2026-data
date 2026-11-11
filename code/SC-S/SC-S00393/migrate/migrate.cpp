#include <bits/stdc++.h>
using std::cin; using std::cout;
using std::max; using std::min;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
constexpr int MAXN = 2e6 + 10;
int n; ll d;
ll x[2000010];
ll dis[5010][5010], way[5010][5010];
void Solve() {
	cin >> n >> d;
	rep(i, 1, n) { cin >> x[i]; }
	rep (i, 1, n) {
		rep (j, i + 1, n) {
			if (x[j] - x[i] <= d) {
				dis[i][j] = 1;
				way[i][j] = 1;
				continue;
			}
			else {
				dis[i][j] = 0x3f3f3f3f3f3f3f3fll;
				way[i][j] = 0;
			}
		}
	}
	for (int k = n; k >= 1; --k) {
		for (int i = k - 1; i >= 1; --i) {
			for (int j = k + 1; j <= n; ++j) {
				if (x[j] - x[i] <= d) {
					dis[i][j] = 1;
					way[i][j] = 1;
					continue;
				}
				if (dis[i][j] > dis[i][k] + dis[k][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
					way[i][j] = way[i][k] * way[k][j];
//					cout << i << ' ' << j << ' ' << dis[i][j] << ' ' << way[i][j] << '\n';
				}
				else if (dis[i][j] == dis[i][k] + dis[k][j]) {
					way[i][j] += way[i][k] * way[k][j];
//					cout << i << ' ' << j << ' ' << dis[i][j] << ' ' << way[i][j] << '\n';
				}
			}
		}
	}
	ll ans = 0;
	rep (i, 1, n) {
		rep (j, i + 1, n) {
			if (way[i][j] == 2) {
				++ans;
			}
		}
	}
	cout << ans << '\n';
}
void Case1() {
	cin >> n >> d;
	rep(i, 1, n) { cin >> x[i]; }
//	cout << n << ' ' << d << ' ' << x[2] - x[1] << '\n';
	if (x[2] - x[1] >= d) {
		cout << 0 << '\n';
		return;
	}
	else {
		ll tmp = (d / (x[2] - x[1]));
		cout << max((n - tmp * 2 + 1), 0ll) << '\n';
	}
}
void Clear() {

}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int c, t; cin >> c >> t;
	while (t--) {
		if (c == 11 || c == 12) { Case1(); }
		else { Solve(); Clear(); }

	}

	return 0;
}