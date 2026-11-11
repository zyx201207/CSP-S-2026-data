#include <bits/stdc++.h>
using namespace std;
#define int long long

// --------------------------------------------------------------------------- Global variable
const int N = 5e5 + 2, M = 502, Inf = 1e18;
int c, n, m, d, q, k, a, t;
int w[N];

vector<pair<int, int>> pt[N];

vector<pair<int, int>> qy[N];
int ans[N];

int g[M][M];

// --------------------------------------------------------------------------- Input
void Input() {
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i) {
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			cin >> a >> t;
			pt[a].push_back({i, t});
		}
	} 
	
	for (int i = 1; i <= q; ++i) {
		int x, y; cin >> x >> y;
		if (x > y) swap(x, y);
		qy[x].push_back({y, i});
	}
}

// --------------------------------------------------------------------------- Solve
int res[M];
void Deal(int i) {
	for (int j = 1; j <= n; ++j) res[j] = Inf;
	for (int aa = 0; aa < (int)pt[i].size(); ++aa) {
		for (int to = 1; to <= n; ++to) {
			res[to] = min(res[to], g[pt[i][aa].first][to] + pt[i][aa].second);
		}
	}
	
	for (int qs = 0; qs < (int)qy[i].size(); ++qs) {
		int j = qy[i][qs].first, id = qy[i][qs].second;
		ans[id] = Inf;
		for (int bb = 0; bb < (int)pt[j].size(); ++bb) {
			ans[id] = min(ans[id], res[pt[j][bb].first] + pt[j][bb].second);
		}
		ans[id] += w[i] + w[j];
	}
}

void Solve() {
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j) g[i][j] = g[j][i] = Inf;
	
	for (int i = 1; i <= m; ++i) {
		for (int aa = 0; aa < (int)pt[i].size(); ++aa) {
			for (int bb = 0; bb < (int)pt[i].size(); ++bb) {
				if (aa == bb) continue;
				int u = pt[i][aa].first, v = pt[i][bb].first, w = pt[i][aa].second + pt[i][bb].second;
				g[u][v] = min(g[u][v], w);
			}
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	}
	
	for (int i = 1; i <= m; ++i) {
		if (!qy[i].empty()) {
			Deal(i);
		}
	}
}

// --------------------------------------------------------------------------- Output
void Output() {
	for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';
}

// --------------------------------------------------------------------------- Main function
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	Input(); Solve(); Output();
	
	return 0;
}