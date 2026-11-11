//SN-S00347 王欣甜 西安市铁一中学
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3fLL
using namespace std;
const int maxn = 5e2 + 5;
const int maxm = 5e5 + 5;
int c, n, m, d, q;
int w[maxm];
vector <pair <int, int> > a[maxm];
vector <pair <int, int> > vc[maxn];
ll dis[maxn][maxn];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)cin >> w[i];
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++) {
			int id, t;
			cin >> id >> t;
			a[id].push_back({i, t});
		}
	}
	for(int i = 1; i <= m; i++) {
		for(auto p : a[i]) {
			for(auto pp : a[i]) {
				int u = p.first, v = pp.first;
				if(u == v)continue;
				vc[u].push_back({v, p.second + pp.second});
				vc[v].push_back({u, p.second + pp.second});
			}
		}
	}
	for(int i = 0; i < maxn; i++) {
		for(int j = 0; j  < maxn; j++) {
			dis[i][j] = inf;
		}
	}
	for(int u = 1; u <= n; u++) {
		dis[u][u] = 0;
		for(auto p : vc[u]) {
			int v = p.first;
			ll t = p.second;
			dis[u][v] = dis[v][u] = min(dis[u][v], t);
		}
	}
	for(int u = 1; u <= n; u++) {
		for(int v = 1; v <= n; v++) {
			for(int k = 1; k <= n; k++) {
				dis[v][u] = dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);
			}
		}
	}
	while(q--) {
		int x, y;
		cin >> x >> y;
		ll ans = inf;
		for(auto p : a[x]) {
			for(auto pp : a[y]) {
				int u = p.first, v = pp.first;
				ans = min(ans, dis[u][v] + p.second + pp.second);
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}
}
