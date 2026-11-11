#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;

namespace Yukari {
const int N = 510;
const int M = 5e5 + 10;
const ll INF = 1e18;
int typ, n, m, D, Q, W[M];
vector<pair<int, int> > sta[M];

ll dist[N][N];

void Main() {
	cin >> typ >> n >> m >> D >> Q;
	for (int i = 1; i <= m; i ++) cin >> W[i];
	for (int i = 1; i <= n; i ++) {
		int len; cin >> len;
		for (int j = 1, a, b; j <= len; j ++)
			cin >> a >> b, sta[a].push_back({i, b});
	}
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++)
		dist[i][j] = (i == j ? 0 : INF);
	for (int i = 1; i <= m; i ++) {
		for (pair<int, int> x : sta[i]) for (pair<int, int> y : sta[i])
			dist[x.first][y.first] = min(dist[x.first][y.first], (ll)(x.second + y.second));
	}
	
	for (int k = 1; k <= n; k ++) for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++)
		dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	
	int u, v;
	while (Q --) {
		cin >> u >> v; ll ans = INF;
		for (pair<int, int> x : sta[u]) for (pair<int, int> y : sta[v])
			ans = min(ans, x.second + y.second + dist[x.first][y.first]);
		cout << ans + W[u] + W[v] << "\n";
	}
	return ;
}

}

int main() {
	freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);	
	Yukari::Main();
	return 0;
}