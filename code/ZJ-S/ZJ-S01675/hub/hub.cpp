#include<bits/stdc++.h>
//#define int long long
#define endl '\n'
using namespace std;
#define rp(i, a) for(int i = 1; i <= a; i++)
#define rd(i, a) for(int i = 0; i < a; i++)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define per(i, a, b) for(int i = b; i >= a; i--)
#define vt vector
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 1e6 + 10;
const int INF = 0x3f3f3f3f;
int c, t, n, k, sel[N], ans, now, vis[N], dep[N], fa[N][31], ne;
vt<int> g[N];
double Rand() {
	return (double)rand() / RAND_MAX;
}
void dfs(int x, int f) {
	vis[x] = 1;
	for(auto to : g[x]) {
		if(to == f || !sel[to]) continue;
		dfs(to, x);
	}
	return ;
}
void dfs3(int x, int f) {
	if(ne) sel[x] = 1, ne--;
	for(auto to : g[x]) {
		if(to != f) dfs3(to, x);
	}
	return ;
}
bool check() {
	int res = 0;
	rp(i, n) vis[i] = 0;
	rp(i, n) {
		if(sel[i] && !vis[i]) {
			dfs(i, i);
			res++;
			if(res > 2) return 0;
		}
	}
	return 1;
}
void dfs2(int x, int f) {
	dep[x] = dep[f] + 1;
	fa[x][0] = f;
	rp(i, 30) {
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	}
	for(auto to : g[x]) {
		if(to == f) continue;
		dfs2(to, x);
	}
	return ;
}
int lca(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	per(i, 0, 30) {
		if(dep[fa[x][i]] >= dep[y]) {
			x = fa[x][i];
		}
	}
	if(x == y) return x;
	per(i, 0, 30) {
		if(fa[x][i] != fa[y][i]) {
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}
int dist(int x, int y) {
	return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}
int calc() {
	if(!check()) return INF;
	int res = 0;
	rp(i, n) {
		if(sel[i]) continue;
		int minn = INF;
		rp(j, n) {
			if(i == j) continue;
			if(!sel[j]) continue;
			minn = min(minn, dist(i, j));
		}
		res = max(minn, res);
	}
	return res;
}
void tui() {
	double t = 100000;
	int bas[n + 1];
	rp(i, n) bas[i] = sel[i];
	while(t > 1e-4) {
		int i = rand() % n + 1;
		int j = rand() % n + 1;
		if(sel[i] == sel[j]) continue;
		if(!check()) continue;
		swap(sel[i], sel[j]);
		int nx = calc();
		int del = nx - now;
		if(nx <= now || exp(-(double)del / t) > Rand()) {
			now = nx;
			ans = min(now, ans);
		} else {
			swap(sel[i], sel[j]);
		}
		t *= 0.97;
	}
	rp(i, n) sel[i] = bas[i];
	return ;
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--) {
		cin >> n >> k;
		rp(i, n) g[i].clear(), sel[i] = 0, dep[i] = 0;
		rp(i, n - 1) {
			int u, v;
			cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs2(1, 1);
		ne = k;
		dfs3(1, 1);
		now = calc();
		ans = now;
		tui();
		tui();
		cout << ans << endl;
	}
	return 0;
}
/*
*/

