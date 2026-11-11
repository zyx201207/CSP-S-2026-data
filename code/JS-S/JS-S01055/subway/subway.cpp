#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;

template<typename T> void check(const T&(*func)(const T&, const T&), T& a, const T& b){ a = func(a, b); }
template<typename T> bool getbit(T x, i32 b){ return (x >> b) & 1; }

void solve(){
	i32 c, n, m, d, q;
	std::cin >> c >> n >> m >> d >> q;
	std::vector<i32> w(m); for(auto& x : w){ std::cin >> x; }
	std::vector<std::vector<std::pair<i32, i32> > > adj(m);
	for(i32 u = 0; u < n; u++){
		i32 k;
		std::cin >> k;
		for(i32 i = 0; i < k; i++){
			i32 v, x;
			std::cin >> v >> x;
			--v;
			adj[v].push_back({u, x});
		}
	}

	const i64 inf = 1e18;
	std::array<std::array<i64, 500>, 500> dist;
	for(i32 i = 0; i < n; i++){ dist[i].fill(inf); dist[i][i] = 0; }
	for(i32 i = 0; i < m; i++){
		for(auto [u, w0] : adj[i]){
			for(auto [v, w1] : adj[i]){
				check(std::min, dist[u][v], (i64)w0 + w1);
			}
		}
	}
	for(i32 k = 0; k < n; k++){
		for(i32 u = 0; u < n; u++){
			for(i32 v = 0; v < n; v++){
				check(std::min, dist[u][v], dist[u][k] + dist[k][v]);
			}
		}
	}
	for(i32 i = 0; i < q; i++){
		i32 x, y;
		std::cin >> x >> y;
		--x, --y;
		i64 ans = inf;
		for(auto [u, w0] : adj[x]){
			for(auto [v, w1] : adj[y]){
				assert(u < 500 and v < 500);
				check(std::min, ans, dist[u][v] + w0 + w1);
			}
		}
		assert(x < m and y < m);
		ans += w[x] + w[y];
		std::cout << ans << "\n";
	}
}

void open_file(std::string file){
  freopen((file + ".in").c_str(), "r", stdin);
  freopen((file + ".out").c_str(), "w", stdout);
}

int main(){
	open_file("subway");

	std::ios::sync_with_stdio(0); std::cin.tie(0);

	i32 T = 1;
	// std::cin >> T;
  for(i32 i = 0; i < T; i++){ solve(); }

	return 0;
}