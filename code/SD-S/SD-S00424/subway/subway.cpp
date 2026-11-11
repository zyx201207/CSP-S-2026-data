#include<bits/stdc++.h>
#define int long long 
using namespace std; 
const int maxn = 1e5 + 100; 
const int maxd = 21; 
vector<int> psby[maxn][2]; 
int c, n, m, d, q; 
int w[maxn]; 
int blg[maxn]; 
int T[maxn]; 
bool sn[maxn]; 
struct Edge {
	int to, nxt, val; 
} g[maxn]; 
int h[maxn], cnt = 0; 

inline void add(int u, int v, int w) {
	g[++cnt].to = v; 
	g[cnt].val = w; 
	g[cnt].nxt = h[u]; 
	h[u] = cnt; 
}

signed main() {
	freopen("subway.in", "r", stdin); 
	freopen("subway.out", "w", stdout); 
	ios :: sync_with_stdio(false); cin.tie(0), cout.tie(0); 
	cin >> c >> n >> m >> d >> q; 
	int tmp = 0; 
	if(1) {
		for(int i = 1; i <= m; i++) {
			cin >> w[i]; 
		}
		for(int i = 1; i <= n; i++) {
			int k; cin >> k; 
			int lst = 0; 
			vector<int> sbw; 
			for(int j = 1; j <= k; j++) {
				int a, t; cin >> a >> t; 
				blg[a] = k; 
				T[a] = t; 
			}
		}
		for(int i = 1; i <= m; i++) {
			if(psby[i][0].size() > 1) sn[i] = 1;  
		}
		while(q--) {
			int u, v; cin >> u >> v; 
			cout << w[u] + w[v] + T[u] + T[v] << '\n'; // ÆÆÈç·À¡£¡£¡£¡£¡£ 
		}
	}
	
	
	return 0; 
}


 
 
