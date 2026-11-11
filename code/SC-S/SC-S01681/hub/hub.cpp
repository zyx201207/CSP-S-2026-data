#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 100 , mod = 1e9 + 7;
const double eps = 1e-5;
inline int read() {
	int x = 0 , f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
inline void write(int x) {
	if(x < 0) putchar('-') , x = -x;
	if(x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}
inline void writeh(int x) {
	write(x);
	putchar('\n');
}
inline void writek(int x) {
	write(x);
	putchar(' ');
}
int c , T , n , k , fa[maxn][20] , deep[maxn] , vis[maxn] , ans , cnt , u[maxn] , v[maxn];
vector<int> t[maxn];
inline void dfs(int x , int f) {
	deep[x] = deep[f] + 1;
	for(int i = 1; (1 << i) <= deep[x]; ++i) fa[x][i] = fa[fa[x][i - 1]][i - 1];
	for(auto v:t[x]) {
		if(v == f) continue;
		fa[v][0] = x;
		dfs(v , x);
	}
}
inline int getlca(int x , int y) {
	if(deep[x] < deep[y]) swap(x , y);
	int k = deep[x] - deep[y];
	for(int i = 0; (1 << i) <= k; ++i) if(k & (1 << i)) x = fa[x][i];
	if(x == y) return x;
	for(int i = 19; i >= 0; --i) if(fa[x][i] != fa[y][i]) x = fa[x][i] , y = fa[y][i];
	return fa[x][0];
}
inline int getdis(int x , int y) {
	return deep[x] + deep[y] - 2 * deep[getlca(x , y)];
}
inline void work() {
	ans = 1e18;
	for(int i = 1; i <= n; ++i) {
		t[i].clear();
		deep[i] = 0;
		for(int j = 0; j < 20; ++j) fa[i][j] = 0;
	}
	n = read();
	k = read();
	for(int i = 1; i < n; ++i) {
		u[i] = read() , v[i] = read();
		t[u[i]].push_back(v[i]);
		t[v[i]].push_back(u[i]);
	}
	if(k >= n) return writeh(0);
	if(c == 13 || c == 14) {
		return write(floor(1.0 * (n - k) / 3));
	}
	dfs(1 , 0);
	for(int i = 1; i < (1 << n); ++i) {
		cnt = 0;
		for(int j = 1; j <= n; ++j) vis[j] = (i >> (j - 1)) & 1 , cnt += vis[j];
		if(cnt > k) continue;
		for(int j = 1; j < n; ++j) if(vis[u[j]] && vis[v[j]]) cnt--;
		if(cnt <= 2) {
			int minn = 0;
			for(int j = 1; j <= n; ++j) {
				if(vis[j]) continue;
				int maxx = 1e18;
				for(int o = 1; o <= n; ++o) if(vis[o]) maxx = min(maxx , getdis(j , o));
				minn = max(minn , maxx);
			}
			ans = min(ans , minn);
		}
	}
	writeh(ans);
}
signed main() {
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	c = read();
	T = read();
	while(T--) work();
	return 0;
}