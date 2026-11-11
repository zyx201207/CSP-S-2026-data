#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define N (int)(5e2 + 5)
#define M (int)(5e5 + 5)
#define inf (int)(1e9)
#define mod (int)(1e9 + 7)
#define qwe(i, l, r) for(int i = l; i <= r; i++)
#define ewq(i, r, l) for(int i = r; i >= l; i--)
#define P pair<int, int>
#define MP make_pair
#define fi first
#define se second
using namespace std;
int T = 1, Case;
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || '9' < ch){
		f = (ch == '-') ? -f : f;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
int n, m, d, q;
int w[M];
ll e[N][N];
vector<P> G[M];
void Solve(){
	n = read(), m = read(), d = read(), q = read();
	qwe(i, 1, m) w[i] = read();
	qwe(i, 1, n){
		int k = read();
		while(k--){
			int v = read(), w = read();
			G[v].push_back(MP(i, w));
		}
	}
	memset(e, 0x3f, sizeof(e));
	qwe(i, 1, m){
		int siz = G[i].size();
		qwe(r1, 0, siz - 1){
			qwe(r2, r1 + 1, siz - 1){
				int u = G[i][r1].fi, w1 = G[i][r1].se, v = G[i][r2].fi, w2 = G[i][r2].se;
				e[u][v] = e[v][u] = min(e[u][v], (ll)(w1 + w2));
			}
		}
	}
	qwe(i, 1, n) e[i][i] = 0;
	qwe(k, 1, n){
		qwe(i, 1, n)
			qwe(j, 1, n) e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
	}
	while(q--){
		int x = read(), y = read();
		ll ans = 0x3f3f3f3f3f3f3f3f;
		for(auto e1 : G[x]){
			for(auto e2 : G[y]){
				int u = e1.fi, w1 = e1.se, v = e2.fi, w2 = e2.se;
				ans = min(ans, e[u][v] + w1 + w2);
			}
		}
		printf("%lld\n", ans + w[x] + w[y]);
	}
}
int main(){
//	freopen("subway7.in", "r", stdin);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	T = read();
	Case = read();
	while(T--) Solve();
	return 0;
} 
/*

Makka pakka :D
*/

