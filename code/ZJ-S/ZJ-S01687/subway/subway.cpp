#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, l, r) for(int i = l; i <= r; i++)
#define INF 1e18
int c, n, m;
int edge[505][505], dis[505][505];
int d, Q, w[500005], k[505];
int v[500005][25], T[500005][25], vl[500005];
int pos[505], tot;
int eg[1500005], egt[1500005];
signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dis, 0x3f, sizeof dis);
	cin >> c >> n >> m >> d >> Q;
	rep(i, 1, m) cin >> w[i];
	rep(i, 1, n) {
		dis[i][i] = 0;
		cin >> k[i];
		pos[i] = tot;
		rep(j, 1, k[i]) {
			int x, t;
			cin >> x >> t;
			eg[++tot] = x, egt[tot] = t;
			v[x][++vl[x]] = i, T[x][vl[x]] = t;
		}
	}
	rep(i, 1, n) {
		rep(j, 1, k[i]) {
			int x = eg[pos[i] + j];
			rep(l, 1, vl[x]) {
				int V = v[x][l], tm = T[x][l];
				if(V == i) continue;
				dis[i][V] = min(dis[i][V], egt[pos[i] + j] + tm);
			}
		}
	}
	rep(i, 1, n) {
		rep(j, 1, n) {
			if(i == j) continue;
			rep(k, 1, n) {
				if(k == i || k == j) continue;
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while(Q--) {
		int d, r;
		cin >> d >> r;
		int ans = INF;
		rep(i, 1, vl[d]) rep(j, 1, vl[r]) ans = min(ans, dis[v[d][i]][v[r][j]] + T[d][i] + T[r][j]);
		cout << w[d] + w[r] + ans << '\n';
	}
	return 0;
}
