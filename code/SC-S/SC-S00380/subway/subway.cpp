#include<bits/stdc++.h>
#define int int64_t
using String = std::string;
constexpr int N = 505;
constexpr int M = 5e5 + 5;
constexpr int Q = 1e5 + 5; 
constexpr int inf = 0x3f3f3f3f;

int c, n, m, d, q, x, y;
int w[M], t[N][M];
int dis[N][N];
int dp[N];
bool vis[N];
std::vector<int> g[N];
std::vector<int> go[M];
std::priority_queue<std::pair<int, int>> p;

void dij() {
	while(!p.empty()) {
		int u = p.top().second; p.pop();
//		std::cout << u << ' ';
		if(vis[u]) continue;
		vis[u] = true;
		for(int v = 1; v <= n; v++) {
			if(vis[v]) continue;
			if(dp[v] > dp[u] + dis[u][v]) {
				dp[v] = dp[u] + dis[u][v];
				p.emplace(-dp[v], v);
			}
		}
	}
//	std::cout << '\n';
}

int solve() {
	std::fill(dp, dp + N, inf);
	std::fill(vis, vis + N, false);
	for(int i : go[x]) {
		dp[i] = t[i][x];
		p.emplace(-t[i][x], i);
	}
	dij();
	int res = inf;
	for(int i : go[y]) {
		res = std::min(res, dp[i] + t[i][y]);
	}
	return res;
}

int32_t main() {
//	freopen("subway\\subway2.in", "r", stdin);
//	freopen("my.out", "w", stdout);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	std::cin.tie(nullptr) -> sync_with_stdio(false);
	std::fill(dis[0], dis[0] + N * N, inf);
	std::fill(t[0], t[0] + N * M, inf);
	
	std::cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		std::cin >> w[i];
	}
	for(int i = 1, k, b, c; i <= n; i++) {
		std::cin >> k;
		while(k--) {
			std::cin >> b >> c;
			g[i].push_back(b);
			go[b].push_back(i);
			t[i][b] = c;
		}
		std::sort(g[i].begin(), g[i].end());
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < i; j++) {
			for(auto l = g[i].begin(), r = g[j].begin(); l != g[i].end() && r != g[j].end(); ) {
				if((*l) < (*r)) l++;
				else if((*l) > (*r)) r++;
				else {
					dis[i][j] = dis[j][i] = std::min(dis[i][j], t[i][*l] + t[j][*r]);
					l++;
					r++;
				}
			}
		}
	}
	
//	for(int i = 1; i <= n; i++) {
//		std::cout << i << ": ";
//		for(int j = 1; j <= n; j++) {
//			if(dis[i][j] != inf) {
//				std::cout << j << ' ';
//			}
//		}
//		std::cout << '\n';
//	}
//	std::cout << '\n';
	
	for(int i = 1; i <= q; i++) {
		std::cin >> x >> y;
//		solve();
		std::cout << solve() + w[x] + w[y] << '\n';
	}
	return 0;
}