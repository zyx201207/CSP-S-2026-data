#include <bits/stdc++.h>
#define int int64_t

const int maxn = 512;
const int maxm = 524288;
const int inf = 1ll << 53;

int c, n, m, useless, q;
int w[maxm];
int d[maxn][maxn];
std::vector<
	std::pair<int, int>> toline[maxm];
	
void debug_toline() {
	for (int i = 1; i <= m; i++) {
		std::cerr << "Station #" << i << ";\n";
		for (auto j : toline[i])
			std::cerr << "    " << j.first << " (Cost=" << j.second << ")\n";
	}
}

void debug_dist() {
	std::cerr << "Distance Matrix:\n";
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			std::string str = std::to_string(d[i][j]);
			if (d[i][j] == inf) str = "inf";
			std::cerr << std::fixed << std::setw(3) << str << " \n"[j == n];
		}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	std::cin >> c >> n >> m >> useless >> q;
	for (int i = 1; i <= m; i++) std::cin >> w[i];
	
	int k, a, t;
	for (int i = 1; i <= n; i++) {
		std::cin >> k;
		
		for (int j = 1; j <= k; j++) {
			std::cin >> a >> t;
			toline[a].emplace_back(i, t); 
		}
	}
	
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			d[i][j] = (i != j) * inf;
	
	int xid, xt, yid, yt;
	for (int i = 1; i <= m; i++) 
		for (auto x : toline[i])
			for (auto y : toline[i]) {
				xid = x.first, xt = x.second;
				yid = y.first, yt = y.second;
				d[xid][yid] = std::min(d[xid][yid], xt + yt);
				d[yid][xid] = std::min(d[yid][xid], xt + yt);
			}
		
			
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				d[j][k] = std::min(d[j][i] + d[i][k], d[j][k]);
			
	
	int x, y, pid, qid, pt, qt;
	for (int i = 1; i <= q; i++) {
		std::cin >> x >> y;
		
		int ans = inf;
		for (auto p : toline[x])
			for (auto q : toline[y]) {
				pid = p.first;
				qid = q.first;
				pt = p.second;
				qt = q.second;
				ans = std::min(ans, pt + qt + d[pid][qid]);				
			}
		
		std::cout << ans + w[x] + w[y] << "\n";
	}
	
	return 0;
}
