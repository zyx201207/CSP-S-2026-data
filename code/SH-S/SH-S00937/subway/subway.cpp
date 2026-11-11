#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q, w[500005];
int g[1005][1005];
void solve1() {
	for (int i = 1; i <= n + m; i++)
		for (int j = 1; j <= n + m; j++)
			if (i != j) g[i][j] = 1e18;
			else g[i][j] = 0;
	for (int i = 1; i <= n; i++) {
		int K; cin >> K; 
		for (int j = 1; j <= K; j++) {
			int A, T; cin >> A >> T;
			g[A][m + i] = g[m + i][A] = T;
		}
	}
	for (int k = 1; k <= n + m; k++)
		for (int i = 1; i <= n + m; i++)
			for (int j = 1; j <= n + m; j++)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	while (q--) {
		int x, y; cin >> x >> y;
		cout << g[x][y] + w[x] + w[y] << "\n";
	}
} 
void solve2() {
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++)
			if (i != j) g[i][j] = 1e18;
	for (int i = 1; i <= n; i++) {
		int K; cin >> K;
		if (K == 1) continue;
		if (K == 2) {
			int A1, T1, A2, T2;
			cin >> A1 >> T1 >> A2 >> T2;
			g[A1][A2] = g[A2][A1] = T1 + T2;
		}
	}
	for (int k = 1; k <= m; k++)
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= m; j++)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	while (q--) {
		int x, y; cin >> x >> y;
		cout << g[x][y] + w[x] + w[y] << "\n";
	}
}
int ttt[500005], tttt[500005];
void solve3() {
	if (n == 1) {
		int K; cin >> K;
		for (int i = 1; i <= K; i++) {
			int A, T; cin >> A >> T;
			ttt[A] = T;
		}
		while (q--) {
			int x, y; cin >> x >> y;
			cout << ttt[x] + ttt[y] + w[x] + w[y] << "\n";
		}
		return;
	}
	int K; cin >> K;
	for (int i = 1; i <= K; i++) {
		int A, T; cin >> A >> T;
		ttt[A] = T;
	}
	cin >> K;
	for (int i = 1; i <= K; i++) {
		int A, T; cin >> A >> T;
		tttt[A] = T;
	}
	int crss = 1e18;
	for (int i = 1; i <= m; i++) if (ttt[i] && tttt[i]) crss = min(crss, ttt[i] + tttt[i]);
	while (q--) {
		int x, y; cin >> x >> y;
		int ans = 1e18;
		if (ttt[x] && ttt[y]) ans = min(ans, ttt[x] + ttt[y]);
		if (tttt[x] && tttt[y]) ans = min(ans, tttt[x] + tttt[y]);
		if (ttt[x] && tttt[y]) ans = min(ans, ttt[x] + tttt[y] + crss);
		if (tttt[x] && ttt[y]) ans = min(ans, tttt[x] + ttt[y] + crss);
		cout << ans + w[x] + w[y] << "\n";
	}
}
vector<pair<int, int> > G[500005];
int D[500005];
void solve4() {
	for (int i = 1; i <= m + n; i++) G[i].clear(); 
	for (int i = 1; i <= n; i++) {
		int K; cin >> K; 
		for (int j = 1; j <= K; j++) {
			int A, T; cin >> A >> T;
			G[A].push_back({m + i, T});
			G[m + i].push_back({A, T}); 
		}
	}
	while (q--) {
		int x, y; cin >> x >> y;
		for (int i = 1; i <= m + n; i++) D[i] = 1e18;
		D[x] = 0;
		deque<pair<int, int> > dq;
		dq.push_front({0, x});
		while (!dq.empty()) {
			int t = dq.front().first;
			int u = dq.front().second;
			dq.pop_front();
			for (int i = 0; i < G[u].size(); i++) {
				int v = G[u][i].first, w = G[u][i].second;
				if (D[v] > t + w) {
					D[v] = t + w;
					if (w == 0) dq.push_front({D[v], v});
					else dq.push_back({D[v], v});
				}
			}
		}
//		priority_queue<pair<int, int> > dq;
//		dq.push({0, x});
//		while (!dq.empty()) {
//			int t = dq.top().first;
//			int u = dq.top().second;
//			dq.pop();
//			if (t != D[u]) continue;
//			for (int i = 0; i < G[u].size(); i++) {
//				int v = G[u][i].first, w = G[u][i].second;
//				if (D[v] > t + w) {
//					D[v] = t + w;
//					dq.push({D[v], v});
//				}
//			}
//		}
		cout << D[y] + w[x] + w[y] << endl;
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	if (c <= 6) solve1(); 
	if (7 <= c && c <= 11) solve2();
	if (20 <= c && c <= 21) solve3();
	if (12 <= c && c <= 19) solve4();
	return 0;
} 
