#include <bits/stdc++.h>
#define LL long long
#define INF 1e18
using namespace std;

const int N = 510, M = 5e5 + 10;
int cid, n, m, d, q;
LL dis[N][N], ans;
int w[M];
struct node{
	int id, t;
};
vector<node> a[M];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> cid >> n >> m >> d >> q;
	for(int i = 1;i <= m;++ i) cin >> w[i];
	for(int i = 1;i <= n;++ i)
		for(int j = 1;j <= n;++ j) dis[i][j] = INF;
	for(int i = 1;i <= n;++ i){
		int k, nd, t;
		cin >> k;
		while(k--) {
			cin >> nd >> t;
			a[nd].push_back({i, t});
		}
		dis[i][i] = 0;
	}
	
	for(int u = 1;u <= m;++ u){
		for(int i = 0;i < a[u].size();++ i){
			for(int j = 0;j < a[u].size();++ j){
				if(i == j) continue;
				int x = a[u][i].id, y = a[u][j].id;
				dis[x][y] = min(dis[x][y], (LL)a[u][i].t + (LL)a[u][j].t);
				//cout << x << ' ' << y << ' ' << (LL)a[u][i].t + (LL)a[u][j].t << "\n";
			}
		}
	}
	for(int k = 1;k <= n;++ k){
		for(int i = 1;i <= n;++ i){
			for(int j = 1;j <= n;++ j)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
		}
	}
	while(q--) {
		int u, v;
		cin >> u >> v;
		ans = INF;
		for(auto e1 : a[u]) {
			for(auto e2 : a[v]) {
				int x = e1.id, y = e2.id;
			//	cout << "ans:" << x << ' ' << y << ' ' << dis[x][y] << ' ' << e1.t << " " << e2.t << "\n";
				ans = min(ans, dis[x][y] + e1.t + e2.t);
			}
		}
		cout << ans + w[u] + w[v] << "\n";
	}
	return 0;
}