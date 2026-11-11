#include <bits/stdc++.h>
#define i64 long long
#define rep(i, l, r) for (i64 i = l; i <= r; ++i)
#define per(i, r, l) for (i64 i = r; i >= l; --i)
using namespace std;
const i64 N = 505, M = 5e5 + 5;
i64 c, n, m, d, q, w[M], f[N][N];
vector<pair<i64, i64> > v[N], fv[M];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	rep(i, 1, m) cin >> w[i];
	rep(i, 1, n) {
		i64 k;
		cin >> k;
		rep(j, 1, k) {
			i64 a, t;
			cin >> a >> t;
			v[i].push_back({a, t});
			fv[a].push_back({i, t});
		}
	}
	memset(f, 0x3f, sizeof f);
	rep(i, 1, n) f[i][i] = 0;
	rep(x, 1, n) {
		for (auto it1 : v[x]) {
			i64 z = it1.first, w1 = it1.second;
			for (auto it2 : fv[z]) {
				i64 y = it2.first, w2 = it2.second;
				f[x][y] = min(f[x][y], w1 + w2);
			}
		}
	}
	rep(k, 1, n) {
		rep(i, 1, n) {
			if (i == k) continue;
			rep(j, 1, n) {
				if (j != k && j != i && f[i][j] > f[i][k] + f[k][j]) {
					f[i][j] = f[i][k] + f[k][j];
				}
			}
		}
	}
	rep(t, 1, q) {
		i64 x, y, ans = 4e18;
		cin >> x >> y;
		for (auto i : fv[x]) {
			for (auto j : fv[y]) {
				ans = min(ans, w[x] + i.second + f[i.first][j.first] + j.second + w[y]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

