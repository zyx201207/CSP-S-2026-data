//17:23 
#include <bits/stdc++.h>
using namespace std;
#define int long long

namespace Sci {
	const int N = 2e4;
	int c, n, m, d, q;
	int w[500005];
	struct Edge {
		int u, v, w;
	};
	Edge h[500005]; int tot;
	//int g[505][500005];
	int dis[502][502], dix[502][500005];
	void floyd() {
		for(int i = 1; i <= n + m; i++) 
			dis[i][i] = 0;
			/*
		for(int i = 1; i <= n+m; i++) {
			for(Edge v : g) {
				dis[i][v.u] = dis[v.u][i] = min(dis[i][v.u], dis[i][v.v] + v.w);
				dis[i][v.v] = dis[v.v][i] = min(dis[i][v.v], dis[i][v.u]+v.w);
			}
		}
		for(int i = 1; i <= n + m; i++) {
			for(Edge v : g[i])
			for(int j = 1; j <= n + m; j++) {
				dis[i][j] =dis[j][i] = min(dis[i][j], dis[j][v.v] + v.w);
				dis[j][v.v] = dis[v.v][j] = min(dis[j][v.v], dis[i][j] + v.w);
			}
		}
		*/
	}
	void qud() {
		cin >> c >> n >> m >> d >> q;
		for(int i = 1; i <= m; i++) cin >> w[i];
		memset(dis, 0x3f, sizeof dis);
		memset(dix, 0x3f, sizeof dix);
		for(int i = 1; i <= n; i++) {
			int k; cin >> k;
			dis[i][i] = 0;
			for(int j = 1; j <= k; j++) {
				int x, y; cin >> x >> y;
				h[++tot] = {i, x, y};
				dix[i][x] = y;
				//g.push_back({x, m+i, y});
				//dis[m+i][x] = dis[x][m+i] = y;
			}
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= tot ;j++) {
				Edge v = h[j];
				dis[i][v.u] = dis[v.u][i] = min(dis[i][v.u], dix[i][v.v] + v.w);
				dix[i][v.v] = min(dix[i][v.v], dis[i][v.u]+v.w);
			}
		}
		for(int i = 1; i <= q; i++) {
			int x, y; cin >>x >> y;
			int minn = 1e18;
			for(int j = 1; j <= n; j++)
				minn = min(minn, dix[j][x] + dix[j][y]);
			cout << minn + w[x] + w[y] << '\n';
		}
		/*
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++)
				cout << dix[i][j] << " ";
			cout << '\n';
		}
		*/
		/*
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				for(auto x : g[i]) {
					for(auto y : g[j]) {
						if(vis[x.v] && vis[y.v]) {
							if(ans[x.v][y.v] == 0) ans[x.v][y.v] = ans[y.v][x.v] = 1e9;
							ans[x.v][y.v] = ans[y.v][x.v] = min(ans[x.v][y.v], dis[i][j] + len[i][x.v] + len[j][y.v]); 
						}
					}
				}
			}
		}
		*/
		//floyd();
		/*
		for(int i = 1; i <= 10; i++) {
			for(int j = 1; j<= 10; j++)
				cout << dis[i][j] << " ";
			cout << '\n';
		}
		for(int i = 1; i <= q; i++) {
			cin >> x >> y;
			//cout << w[x] + w[y] + dis[x][y] << '\n';
		}
		*/
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	Sci::qud();
	return 0;
}
