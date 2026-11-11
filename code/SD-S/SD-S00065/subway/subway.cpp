#include <iostream>
#include <vector>
#define ll long long
using namespace std;
const ll MAXN1 = 510, MAXN2 = 5e5 + 10, MAXN = 6e5 + 10, INF = 1e18;
ll c, n, m, d, Q;
ll w[MAXN2], res = 0;
struct e{ll v, w;};vector<e> edge[MAXN];
ll dis[MAXN1][MAXN1];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> Q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		ll k, v, w;
		cin >> k;
		while(k--) {
			cin >> v >> w;
			edge[i + m].push_back({v, w});
			edge[v].push_back({i + m, w});
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) {
			if(i == j) dis[i][j] = 0;
			else dis[i][j] = INF;
		}
	for(int i = 1; i <= m; i++) {
		for(e ed1 : edge[i])
			for(e ed2 : edge[i]) {
				int u = ed1.v - m, v = ed2.v - m;
				dis[u][v] = min(dis[u][v], ed1.w + ed2.w);
			}
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while(Q--) {
		int u, v;
		cin >> u >> v;
		res = INF;
		for(e ed1 : edge[u])
			for(e ed2 : edge[v])
				res = min(res, ed1.w + ed2.w + dis[ed1.v - m][ed2.v - m]);
		cout << res + w[u] + w[v] << "\n";
	}
	return 0;
}
