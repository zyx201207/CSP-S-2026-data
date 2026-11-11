#include <bits/stdc++.h>
#define ll long long
//#define debug(x) cout << #x << ' ' << x << '\n'; 
using namespace std;
int main() {
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<int>w(m + 1);
	for (int i = 1;i <= m;i++) {
		cin >> w[i];
	}
	vector<vector<array<ll, 2>>>ve(n + m + 1);
	for (int i = 1;i <= n;i++) {
		int k;
		cin >> k;
		for (int j = 1;j <= k;j++) {
			ll tmpa, tmpt;
			cin >> tmpa >> tmpt;
			ve[m + i].push_back({tmpa, tmpt});
			ve[tmpa].push_back({m + i, tmpt});
		}
	}
	//1~m m个地铁站
	//m+1~n+m n个线路 
	vector<vector<ll>>dis(n + 1, vector<ll>(n + 1, 1e18));
	for (int i = 1;i <= n;i++) {
		dis[i][i] = 0;
	}
	for (int i = 1;i <= m;i++) {
		int sz = ve[i].size();
		for (int j = 0;j < sz;j++) {
			for (int k = j + 1;k < sz;k++) {
				int u = ve[i][j][0] - m;
				int v = ve[i][k][0] - m;
				dis[u][v] = min(dis[u][v], ve[i][j][1] + ve[i][k][1]);
				dis[v][u] = min(dis[v][u], ve[i][j][1] + ve[i][k][1]);
			}
		}
	}
	for (int k = 1;k <= n;k++) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				if(dis[i][k] + dis[k][j] < dis[i][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
//	for (int i = 1;i <= n;i++) {
//		for (int j = 1;j <= n;j++) {
//			debug(i);
//			debug(j);
//			debug(dis[i][j]);
//		}
//	}
	for (int i = 1;i <= q;i++) {
		int u, v;
		cin >> u >> v;
		ll minn = 1e18;
		for (auto uu : ve[u]) {
			for (auto vv : ve[v]){
				minn = min(minn, uu[1] + vv[1] + dis[uu[0] - m][vv[0] - m]);
//				debug(uu[0] - m);
//				debug(vv[0] - m);
//				debug(minn);
			}
		}
		cout << 1ll * minn + w[u] + w[v] << '\n';
	}
	return 0;
} 
