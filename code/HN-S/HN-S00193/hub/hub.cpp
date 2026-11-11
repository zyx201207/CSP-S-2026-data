#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define N (int)(1e6 + 5)
#define M (int)(1e6 + 5)
#define N1 (int)(1e1 + 5)
#define inf (int)(1e9)
#define mod (int)(1e9 + 7)
#define qwe(i, l, r) for(int i = l; i <= r; i++)
#define ewq(i, r, l) for(int i = r; i >= l; i--)
#define P pair<int, int>
#define MP make_pair
#define fi first
#define se second
using namespace std;
int Case, T = 1;
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
int n, k, u, v, ans;
int dep[N], f[N][21], fa[N1];
bool e[N1][N1];
vector<int> G[N];
void dfs(int u, int fa){
	dep[u] = dep[fa] + 1, f[u][0] = fa;
	qwe(i, 1, 20) f[u][i] = f[f[u][i - 1]][i - 1];
	for(auto v : G[u]) if(v != fa) dfs(v, u);
}
int lca(int u, int v){
	if(dep[u] < dep[v]) swap(u, v);
	ewq(i, 20, 0) if(dep[f[u][i]] >= dep[v]) u = f[u][i];
	if(u == v) return u;
	ewq(i, 20, 0) if(f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
	return f[u][0];
}
int dist(int u, int v){
	int g = lca(u, v);
	return dep[u] + dep[v] - 2 * dep[g];
}
int find(int x){return x == fa[x] ? x : fa[x] = find(fa[x]);}
void merge(int x, int y){
	x = find(x), y = find(y);
	if(x == y) return;
	fa[y] = x;
}
void Solve(){
	n = read(), k = read();
	if(1 <= Case && Case <= 3){
		qwe(i, 1, n){
			vector<int>().swap(G[i]);
			qwe(j, 1, n) e[i][j] = 0;
		}
		qwe(i, 1, n - 1){
			u = read(), v = read();
			G[u].push_back(v), G[v].push_back(u); 
			e[u][v] = e[v][u] = 1;
		}
		dfs(1, 0);
		ans = n;
		qwe(mask, 0, (1 << n) - 1){
			if(__builtin_popcount(mask) != k) continue;
			vector<int> S(0);
			qwe(i, 1, n) fa[i] = i;
			qwe(i, 1, n) if(mask & (1 << (i - 1))) S.push_back(i);
			int siz = S.size();
			qwe(i, 0, siz - 1){
				qwe(j, i + 1, siz - 1){
					int u = S[i], v = S[j];
					if(e[u][v]) merge(u, v);
				}
			}
			int cnt = 0;
			for(auto u : S) if(u == fa[u]) cnt++;
			if(cnt > 2) continue;
			int mxd = 0;
			qwe(i, 1, n){
				int d = n;
				for(auto u : S) d = min(d, dist(i, u));
				mxd = max(mxd, d);
			}
			ans = min(ans, mxd);
		}
		printf("%d\n", ans);
		return;
	}
	
}
int main(){
//	freopen("hub2.in", "r", stdin);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	Case = read(), T = read();
	while(T--) Solve();
	return 0;
} 
/*

Makka pakka :D
*/

