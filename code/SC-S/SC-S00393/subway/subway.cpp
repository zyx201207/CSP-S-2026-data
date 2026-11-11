#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::max;
using std::min;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
constexpr int MAXN = 510, MAXM = 5e5 + 10, MAXD = 20;
int c, n, m, d, q;
ll dis[MAXN][MAXN]; // 站台之间的 dis
std::vector<std::pair<int, ll> > tingtotai[MAXM];
std::vector<std::pair<int, ll> > taitoting[MAXN];
ll w[MAXM];
void Solve() {
	memset(dis, 0x3f, sizeof dis);
	cin >> c >> n >> m >> d >> q;
	rep(i, 1, m) { cin >> w[i]; tingtotai[i].reserve(d); }
	rep(i, 1, n) {
		int k, a; ll t;
		cin >> k;
		rep(j, 1, k) {
			cin >> a >> t;
			tingtotai[a].push_back({i, t});
			taitoting[i].push_back({a, t});
		}
	}
	rep(i, 1, n) {
		for (auto &pr1 : taitoting[i]) {
			int ting = pr1.first; ll w1 = pr1.second;
			for (auto &pr2 : tingtotai[ting]) {
				int tai = pr2.first; ll w2 = pr2.second;
				if (tai == i) { continue; }
				dis[i][tai] = std::min(dis[i][tai], w1 + w2);
				dis[tai][i] = std::min(dis[tai][i], w1 + w2);
			}
		}
	}
	rep(i, 1, n) dis[i][i] = 0;
	rep(k, 1, n) {
		rep(i, 1, n) {
			if (i == k) { continue; }
			rep(j, 1, n) {
				if (j == i || j == k) { continue; }
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	rep(case_, 1, q) {
		int x, y; cin >> x >> y;
		ll ans = 0x3f3f3f3f3f3f3f3fll;
		for (auto &tai1 : tingtotai[x]) {
			for (auto &tai2 : tingtotai[y]) {
				ll res = dis[tai1.first][tai2.first] + tai1.second + tai2.second;
				ans = std::min(ans, res);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Solve();
	return 0;
}