#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int s = 0, f = 1;
	signed c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -f;
	for(; isdigit(c); c = getchar()) s = (s * 10) + (c ^ 48);
	return s * f;
}
void write(int x){
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar('0' + x % 10);
}
const int N = 1e6 + 10, inf = 1e9;
int C, T, n, k, dis[N], fa[N], f[N];
int U, V, mx_len, tu;
bool vis[N];
vector<int> g[N], t[N];
queue<int> q;
int getf(int u){
	return u == fa[u] ? u : fa[u] = getf(fa[u]);
}
void dfs(int u, int fath, int d){
	if(d > mx_len)
		mx_len = d, tu = u;
	f[u] = fath;
	for(int v : g[u]){
		if(v == fath || v == -1) continue;
		dfs(v, u, d + 1);
	}
}
int find(int X, int &U, int &V){
	mx_len = tu = 0, dfs(X, 0, 0);
	U = tu;
	mx_len = tu = 0, dfs(U, 0, 0);
	V = tu;
	return mx_len;
}
void solve(){
	n = read(), k = read();
	for(int i = 1; i <= n; ++ i) t[i].clear(), g[i].clear(), dis[i] = inf, vis[i] = 0;
	for(int i = 1, u, v; i < n; ++ i){
		u = read(), v = read();
		g[u].push_back(v), g[v].push_back(u);
	}
	if(C == 13 || C == 14){
		int m = (n - 1) >> 1;
		if(k == n) puts("0");
		else if(k >= m) puts("1");
		else if(k == 1) write((m + 2) >> 1), puts("");
		else{
			m = (m + 3) >> 1, k = (k + 1) >> 1;
//			cout << m << " " << k << "\n";
			write((m + 1 - k) >> 1);
			puts("");
		}
		return;
	}
	int len = find(1, U, V), x = V;
	len >>= 1; for(; len --; x = f[x]);
	for(int i = 0; i < g[x].size(); ++ i)
		if(g[x][i] == f[x]) g[x][i] = -1;
	for(int i = 0; i < g[f[x]].size(); ++ i)
		if(g[f[x]][i] == x) g[f[x]][i] = -1;
	for(int i = 1; i <= n; ++ i){
		if(g[i].size() == 1 || (g[i].size() == 2 && (g[i][0] == -1 || g[i][1] == -1))){
			dis[i] = 0, vis[i] = 1;
			q.push(i);
		}
	}
	for(int u; q.size();){
		u = q.front(), q.pop();
		t[dis[u]].push_back(u);
		for(int v : g[u]){
			if(vis[v] || v == -1) continue;
			vis[v] = 1, dis[v] = dis[u] + 1;
			q.push(v);
		}
	}
//	for(int i = 1; i <= n; ++ i) cout << dis[i] << " ";
//	cout << "\n";
	for(int i = 1; i <= n; ++ i) fa[i] = i, vis[i] = i;
	int ans = n, cnt = 0, sz_cnt = 0;
	for(int i = n, fu, fv; i >= 1; -- i){
		for(int u : t[i]){
			++ cnt, ++ sz_cnt;
			vis[u] = 1;
			for(int v : g[u]){
				if(v == -1 || !vis[v]) continue;
				fu = getf(u), fv = getf(v);
				if(fu == fv) continue;
				-- sz_cnt;
			}
		}
		if(cnt <= k && sz_cnt <= 2) ans = min(ans, i);
	}
	write(ans), puts("");
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	C = read(), T = read();
	for(; T --;)
		solve();
	return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5

0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/