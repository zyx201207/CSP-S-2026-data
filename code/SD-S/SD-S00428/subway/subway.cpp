#include <bits/stdc++.h>
#define int long long
#define pb push_back 
using namespace std;

//#define LOCAL
#define SIZE (1 << 20)

#ifndef LOCAL
	char in[SIZE], *p1, *p2;
	#define getchar() (p1 == p2 && (p2 = (p1 = in) + fread(in, 1, SIZE, stdin)), p1 == p2 ? EOF : *p1 ++)
#endif

int read(){
	int x = 0, f = 1, ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	} while(ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	} return x * f;
}

const int N = 5e2 + 10;
const int M = 1e6 + 10;
int c, n, m, d, q;
int w[M], eg[N][N];
vector<pair<int, int> > e[M];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	c = read(), n = read(), m = read(), d = read(), q = read();
	for(int i = 1; i <= m; ++ i)
		w[i] = read();
	for(int i = 1; i <= n; ++ i){
		int k = read();
		for(int j = 1, u, w; j <= k; ++ j){
			u = read(), w = read();
			e[u].pb({i, w});
		}
	} memset(eg, 0x3f, sizeof eg);
	for(int i = 1; i <= n; ++ i)
		eg[i][i] = 0;
	for(int i = 1; i <= m; ++ i){
		int x = e[i].size();
		for(int j = 0; j < x; ++ j){
			for(int k = 0; k < x; ++ k){
				int u = e[i][j].first, v = e[i][k].first;
				eg[u][v] = eg[v][u] = min(eg[u][v], e[i][j].second + e[i][k].second);
			}
		}
	} for(int k = 1; k <= n; ++ k)
		for(int i = 1; i <= n; ++ i)
			for(int j = 1; j <= n; ++ j)
				eg[i][j] = min(eg[i][j], eg[i][k] + eg[k][j]);
	while(q --){
		int x = read(), y = read();
		int ans = (1ll << 60);
		for(int i = 0; i < (int)(e[x].size()); ++ i)
			for(int j = 0; j < (int)(e[y].size()); ++ j){
				ans = min(ans, e[x][i].second + e[y][j].second + eg[e[x][i].first][e[y][j].first]);
			}
		cout << ans + w[x] + w[y] << "\n";
	}
	
	return 0;
}

