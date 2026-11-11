#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 10;
int n, k, fa[maxn], dep[maxn], siz[maxn], rt, mx, cmx, mxdep[maxn], cnt, bel[maxn];
vector <int> G[maxn];
struct node {
	int val, id;
}tmp[maxn];
void dfs(int x, int f) {
	siz[x] = 1;
	bool flg = 1;
	for(int y : G[x]) {
		if(y == f) continue;
		dfs(y, x);
		siz[x] += siz[y];
		if(siz[y] > n / 2) flg = 0;
	}
	if(n - siz[x] <= n / 2 && flg) rt = x;
}
void dfs2(int x, int f) {
	siz[x] = 1;
	fa[x] = f;
	dep[x] = dep[f] + 1;
	mxdep[x] = dep[x];
	for(int y : G[x]) {
		if(y == f) continue;
		dfs2(y, x);
		siz[x] += siz[y];
		mxdep[x] = max(mxdep[x], mxdep[y]);
	}
}
void dfs3(int x, int bbb) {
	bel[x] = bbb;
	for(int y : G[x]) {
		if(y == fa[x]) continue;
		dfs3(y, bbb);
	}
}
bool chk1() {
	int tot = 0;
	for(int i = 1; i <= n; i++) {
		if(G[i].size() == 1) tot++;
		if(G[i].size() >= 3) return false;
	}
	if(tot == 2) return true;
}
void solve1() {
	cin >> n >> k;
	//clear
	for(int i = 1; i <= n; i++) G[i].clear(), fa[i] = 0, dep[i] = 0;
	for(int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1, 0);
	dfs2(rt, 0);
//	cout << rt << "\n";
	for(int x : G[rt]) {
		dfs3(x, x);
	}
//	cout << rt << "\n";
//	for(int i = 1; i <= n; i++) cout << dep[i] << " "; cout << "\n";
	int ans = 1e18;
	cnt = 0;
	for(int x : G[rt]) {
		tmp[++cnt] = {mxdep[x], x};
	}
	sort(tmp + 1, tmp + 1 + cnt, [](node x, node y) {
		return x.val > y.val;
	});
	mx = 0, cmx = 0;
	for(int i = 1; i <= cnt; i++) {
		if(tmp[i].val >= mx) mx = tmp[i].val;
		else if(tmp[i].val >= cmx) cmx = tmp[i].val; 
	}
	int tot1 = 0, tot2 = 0;
	for(int i = 1; i <= cnt; i++) {
		if(tmp[i].val == mx) tot1++;
		if(tmp[i].val == cmx) tot2++;
	}
	
	// link special
	if(chk1()) {
		
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(siz[i] < k) continue;
		int add = dep[i] - 1;
		if(mxdep[bel[i]] == mx && tot1 == 1) add += cmx - 1;
		else add += mx - 1;
		ans = min(ans, add);
	}
//	cout << ans << "\n";
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(siz[i] < k || siz[j] < k) continue;
			int p = i, q = j;
			if(dep[i] > dep[j]) swap(p, q);
			int add = dep[p] - 1;
//			cout << p << " " << q << "\n";
			if(p == rt) {
				if(mxdep[bel[q]] == mx && tot1 == 1) {
					add += cmx - 1;
				}
				else add += mx - 1;
				ans = min(ans, add);
				continue;
			}
			if(mxdep[bel[p]] == mx && tot1 <= 2) {
				if(mxdep[bel[q]] == mx) add += cmx - 1;
				else if(mxdep[bel[q]] == cmx && tot2 == 1) {
					if(cnt > 2) add += tmp[3].val - 1;
				}
				else add += cmx - 1;
			}
			else add += mx - 1;
//			if(p == 7 && q == 2) cout << add << "\n";
			ans = min(ans, add);
		}
	}
	cout << ans << "\n";
}
void solve2() {
	cin >> n >> k;
	//clear
	for(int i = 1; i <= n; i++) G[i].clear(), fa[i] = 0, dep[i] = 0;
	for(int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i = 1; i <= n; i++) f[i][0] = i - 1;
	for(int j = 1; j <= k; j++) f[0][j] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			if(j & 1) {
				if(i & 1) f[i][j] = f[i / 2][j / 2] + 1;
				else f[i][j] = max(f[i / 2 - 1][j / 2], f[i / 2][j / 2] + 1);
			}
			else {
				if(i & 1) f[i][j] = f[i / 2][j / 2];
				else f[i][j] = max(f[])
			}
		}
	}
	cout << f[n][k] << "\n";
}
signed main() {
	freopen("hub1.in", "r", stdin);
//	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int c, T;
	cin >> c >> T;
	if(c <= 10) {
		while(T--) solve1();
	}
	if(c == 13 || c == 14) {
		while(T--) solve2();
	}
	return 0;
}
/*
0 1
6 10
1 2
1 3
2 4
2 5
5 6


0 1
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
*/
