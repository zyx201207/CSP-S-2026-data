#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define REP(i, r, l) for (int i = (r); i >= (l); --i)
using namespace std;

typedef long long ll;

int c, n, m, d, q;
int w[500010];
int k;
int a;
int t;
int x, y;
ll ndis[510][510];
int tdis[500010][510]; // size
ll ans;

vector<vector<int> > h;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	memset(ndis, -1, sizeof(ndis));
	h.resize(m + 1);
	rep(i, 1, m) {
		cin >> w[i];
	}
	rep(i, 1, n) {
		cin >> k;
		rep(j, 1, k) {
			cin >> a >> t;
			tdis[a][i] = t;
			h[a].emplace_back(i);
		}
	}
	rep(i, 1, m) {
		if (h[i].size() >= 2) {
			for (auto itx = h[i].begin(); itx != h[i].end(); ++itx) {
				for (auto ity = itx + 1; ity != h[i].end(); ++ity) {
					if (ndis[*itx][*ity] == -1) {
						ndis[*itx][*ity] = ndis[*ity][*itx] = tdis[i][*itx] + tdis[i][*ity];
					} else {
						ndis[*ity][*ity] = ndis[*ity][*itx] = min(ndis[*itx][*ity], 1LL * tdis[i][*itx] + 1LL * tdis[i][*ity]);
					}
				}
			}
		}
	} // line to line
	rep(K, 1, n) {
		rep(i, 1, n) {
			if (i == K) continue;
			rep(j, 1, n) {
				if (j == K || j == i) continue;
				if (ndis[i][K] != -1 && ndis[K][j] != -1) {
					if (ndis[i][j] == -1) {
						ndis[i][j] = ndis[i][K] + ndis[K][j];
					} else {
						ndis[i][j] = min(ndis[i][j], ndis[i][K] + ndis[K][j]);
					}
				}
			}
		}
	} // floyd
	rep(i, 1, n) {
		ndis[i][i] = 0;
	}
	rep(i, 1, q) {
		cin >> x >> y;
		ans = LLONG_MAX;
		for (auto st : h[x]) {
			for (auto en : h[y]) {
				if (ndis[st][en] != -1) {
					ans = min(ans, ndis[st][en] + 1LL * tdis[x][st] + 1LL * tdis[y][en]);
				}
			}
		}
		ans += w[x] + w[y];
		cout << ans << '\n';
	}
	return 0;
}
