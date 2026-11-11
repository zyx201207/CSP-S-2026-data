#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
	T s = 0; int st = 1; char c = getchar();
	while(c < '0' || c > '9') (c == '-') && (st = -1), c = getchar();
	while(c >= '0' && c <= '9') s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
	x = s * st;
}
template<typename T, typename... Args> inline void read(T &x, Args &...args){
	read(x), read(args...);
}
template<typename T> inline void write(T x){
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
#define LL long long
#define PII pair<int, int>
#define ull unsigned long long
const int N = 1e6 + 5;
vector<int> e[N];
int mn[21][N], dfn[N], dfncnt, dep[N];
bool vis[N];
void init(int u, int fa){
	dfn[u] = ++dfncnt;
	mn[0][dfn[u]] = fa;
	dep[u] = dep[fa] + 1;
	for(int v : e[u]) if(v != fa){
		init(v, u);
	}
}
inline int MN(int u, int v){
	return dfn[u] < dfn[v] ? u : v;
}
inline int getlca(int u, int v){
	if(u == v) return u;
	if(dfn[u] > dfn[v]) swap(u, v);
	int l = dfn[u] + 1, r = dfn[v], len = __lg(r - l + 1);
	return MN(mn[len][l], mn[len][r - (1 << len) + 1]);
}
inline int getdis(int u, int v){
	return dep[u] + dep[v] - 2 * dep[getlca(u, v)];
}
void dfs(int u){
	vis[u] = 0;
	for(int v : e[u]){
		if(vis[v]) dfs(v);
	}
}
inline void run(){
	int n, m, ans;
	read(n, m);
	ans = n;
	dfncnt = 0;
	for(int i = 1; i <= n; ++i){
		vector<int>().swap(e[i]);
	}
	for(int i = 1; i < n; ++i){
		int u, v;
		read(u, v);
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	dfncnt = 0;
	init(1, 0);
	for(int i = 1; i <= 20; ++i){
		for(int j = 1; j + (1 << i) - 1 <= n; ++j){
			mn[i][j] = MN(mn[i - 1][j], mn[i - 1][j + (1 << i - 1)]);
		}
	}
	for(int i = 0; i < (1 << n); ++i){
		if(__builtin_popcount(i) != m) continue;
		for(int j = 1; j <= n; ++j){
			if(i >> j - 1 & 1) vis[j] = 1;
			else vis[j] = 0;
		}
		int cnt = 0;
		for(int j = 1; j <= n; ++j){
			if(vis[j]){
				++cnt;
				dfs(j);
			}
		}
		if(cnt > 2) continue;
		int res = 0;
		for(int j = 1; j <= n; ++j){
			if(i >> j - 1 & 1) continue;
			int t = n;
			for(int k = 1; k <= n; ++k){
				if(i >> k - 1 & 1){
					t = min(t, getdis(j, k));
				}
			}
			res = max(res, t);
		}
		ans = min(ans, res);
	}
	write(ans), putchar('\n');
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T;
	read(c, T);
	while(T--) run();
	return 0;
}
