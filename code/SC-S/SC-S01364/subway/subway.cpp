#include <bits/stdc++.h> 
#define ll long long 
#define rep(i, j, k) for (int i = j; i <= k; i++) 
#define dow(i, j, k) for (int i = j; i >= k; i--) 
#define pb push_back 
#define pil std::pair < int, ll > 
#define fir first 
#define sec second 

const int N = 505, M = 5e5 + 5; 
const ll inf = 1e18; 

int ID, n, m, d, q; 
ll w[M]; 
std::vector < pil > g[M]; 
ll f[N][N]; 
std::unordered_map < int, ll > w2[N]; 

signed main() {
	freopen("subway.in", "r", stdin); 
	freopen("subway.out", "w", stdout); 
	
//	std::cout << (1ll * 500 * 500 * 500 + 20 * 20 * 500000 + 100000 * 20 * 20) / 2e8; 
	memset(f, 127, sizeof f); 
	
	scanf("%d%d%d%d%d", &ID, &n, &m, &d, &q); 
	rep(i, 1, m) scanf("%lld", w + i); 
	rep(i, 1, n) {
		int l, a; ll b; 
		scanf("%d", &l); 
		rep(j, 1, l) {
			scanf("%d%lld", &a, &b); 
			g[a].pb({i, b}); w2[i][a] = b; 
		}
	}
	
	rep(i, 1, n) f[i][i] = 0; 
	rep(i, 1, m) {
		for (auto u : g[i]) {
			for (auto v : g[i]) {
				f[u.fir][v.fir] = std::min(f[u.fir][v.fir], u.sec + v.sec); 
//				printf("i:%d %d %d %lld\n", i, u.fir, v.fir, f[u.fir][v.fir]); 
			}
		}
	}
	rep(k, 1, n) {
		rep(i, 1, n) {
			if (f[i][k] < inf) {
				rep(j, 1, n) {
					if (f[k][j] < inf) 
						f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]); 
				}
			}
		}
	}
//	rep(i, 1, n) {
//		rep(j, 1, n) printf(" %lld", f[i][j]); 
//		putchar('\n'); 
//	}
//	rep(i, 1, n) rep(j, 1, n) printf("u:%d v:%d dis:%lld\n", i, j, f[i][j]); 
	
	while (q--) {
		int x, y; scanf("%d%d", &x, &y); 
		ll ans = inf; 
		for(auto u : g[x]) for(auto v : g[y]) ans = std::min(ans, f[u.fir][v.fir] + w2[u.fir][x] + w2[v.fir][y]); 
		printf("%lld\n", w[x] + ans + w[y]); 
	}
	
	return 0; 
}