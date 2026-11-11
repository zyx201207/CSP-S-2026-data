#include <bits/stdc++.h>

long long g[505][505];
long long d[505][505];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	
	int c, n, m, _d, q;
	std::cin >> c >> n >> m >> _d >> q;
	std::vector <long long> w(m);
	for(long long& i : w) {
		std::cin >> i;
	}
	std::vector <std::vector <std::pair <int, long long>>> use(m);
	for(int i = 0; i < n; i++) {
		int k;
		std::cin >> k;
		for(int j = 0; j < k; j++) {
			int a; long long t;
			std::cin >> a >> t;
			a--;
			use[a].emplace_back(i, t);
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			g[i][j] = 1000000000000ll;
		}
	}
	for(int i = 0; i < n; i++) {
		g[i][i] = 0ll;
	}
	for(int i = 0; i < m; i++) {
		for(auto e0 : use[i]) {
			for(auto e1 : use[i]) {
				int u = e0.first; long long Tu = e0.second;
				int v = e1.first; long long Tv = e1.second;
				g[u][v] = std::min(g[u][v], Tu + Tv);
				g[v][u] = std::min(g[v][u], Tu + Tv);
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			d[i][j] = g[i][j];
		}
	}
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			if(d[i][k] == 1000000000000ll) {
				continue; 
			}
			for(int j = i; j < n; j++) {
				d[j][i] = d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);	
			}
		}
	}
	for(int i = 0; i < q; i++) {
		int x, y;
		std::cin >> x >> y;
		x--, y--;
		long long ans = 1000000000000ll;
		
		for(auto e0 : use[x]) {
			for(auto e1 : use[y]) {
				int u = e0.first;
				int v = e1.first;
				long long Tu = e0.second;
				long long Tv = e1.second;
				ans = std::min(ans, d[u][v] + Tu + Tv);
			}
		}
		std::cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}