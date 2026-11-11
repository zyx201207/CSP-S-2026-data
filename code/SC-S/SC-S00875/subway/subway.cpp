#include <bits/stdc++.h>
#define ll long long
#define rep(i, j, k) for(int i=j;i<=k;i++)
#define Suika 0
using namespace std;
const int N = 500 + 10, M = 5e5 + 10;
int c, n, m, d, q;
ll w[M];
ll dis[N][N];
vector<pair<int, ll>> lk[M];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(Suika);
	cin.tie(Suika);cout.tie(Suika);
	cin >> c >> n >> m >> d >> q;
	rep(i, 1, m) cin >> w[i];
	rep(i, 1, n) {
		int k; cin >> k;
		rep(j, 1, k) {
			int u; ll v; cin >> u >> v;
		//	cout << u << " " << v << "\n";
			lk[u].push_back({i, v});
		}
	}
	rep(i, 1, n) rep(j, 1, n) {
		if (i == j) dis[i][j] = 0;
		else dis[i][j] = 1e18;
	}
/*	rep(i, 1, m) {
		cout << i << ": \n";
		for (auto v : lk[i]) {
			int y = v.first; ll vy = v.second;
			cout << y << " " << vy << "\n";
		}
	}*/
	rep(i, 1, m) {
	//	cout << "\n";
		for (auto u : lk[i]) {
			for (auto v : lk[i]) {
				int x = u.first; ll vx = u.second;
				int y = v.first; ll vy = v.second;
			//	cout << x << " " << y << " " << vx + vy << "\n";
				dis[x][y] = dis[y][x] = min(dis[x][y], vx + vy);
			}
		}
	}
	rep(k, 1, n) {
		rep(i, 1, n) {
			rep(j, 1, n) {
				if (i == j) continue;
				if (dis[i][k] + dis[k][j] < dis[i][j]) dis[i][j] = dis[i][k] + dis[k][j];
			}
		}
	}
/*	rep(i, 1, n) {
		rep(j, 1, n) {
			cout << dis[i][j] << " ";
		}
		cout << "\n";
	}*/
	while (q--) {
		int u, v; cin >> u >> v;
		ll ans = 1e18;
		for (auto i : lk[u]) {
			for (auto j : lk[v]) {
				int x = i.first; ll vx = i.second;
				int y = j.first; ll vy = j.second;
				ans = min(ans, dis[x][y] + w[u] + w[v] + vx + vy);
			}
		}
		cout << ans << "\n";
	}
	return Suika;
}
/*
0 37202
8361 72 9
3142 55 100
3263 17 2
4325 100 46 6 7
1 6
2 3
*/