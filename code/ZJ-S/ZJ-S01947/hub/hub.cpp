#include <bits/stdc++.h>
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define lop(i, a, b) for (int i = (a); i < (b); i++)
#define dwn(i, a, b) for (int i = (a); i >= (b); i--)
#define mp(a, b) make_pair(a, b)
#define pr pair<int, int>
#define fir first
#define sec second
#define iosfst ios::sync_with_stdio(false);cin.tie(0), cout.tie(0)
using namespace std;
const int N = 2e6 + 10;
int C, T, n, k, ans = 1e9, f[N], fa[N], mx;
vector<int> G[N];
int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void merge(int p, int ffa) {
	if (f[p] && f[ffa]) fa[p] = find(ffa);
	lop (i, 0, G[p].size()) {
		int to = G[p][i];
		if (to == ffa) continue;
		merge(to, p);
	}
	return;
} 
bool check() {
	int cnt = 0;
	rep (i, 1, n) fa[i] = i;
	merge(1, 0);
	rep (i, 1, n) if (fa[i] == i && f[i]) cnt++;
	if (cnt <= 2) return true;
	else return false;
}
void dfss(int p, int fa, int cnt) {
	if (f[p]) {
		mx = min(cnt, mx);
		return;
	}
	lop (i, 0, G[p].size()) {
		int to = G[p][i];
		if (to == fa) continue;
		dfss(to, fa, cnt + 1);
	}
	return;
}
int calc() {
	int res = 0;
	rep (i, 1, n) if (!f[i]) mx = 1e9, dfss(i, 0, 0), res = min(res, mx);
	return res;
}
void dfs(int p, int fa, int cnt) {
	if (!check()) return;
	if (cnt == k) {
		ans = min(ans, calc());
		return;
	}
	lop (i, 0, G[p].size()) {
		int to = G[p][i];
		if (to == fa) continue;
		f[p] = 1;
		dfs(to, p, cnt + 1);
		f[p] = 0;
		dfs(to, p, cnt);
	}
	return;
} 
signed main() {
	iosfst;
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> C >> T;
	while (T--) {
		ans = 1e9;
		cin >> n >> k;
		rep (i, 1, n) G[i].clear();
		lop (i, 1, n) {
			int u, v; cin >> u >> v;
			G[u].push_back(v), G[v].push_back(u);
		}
		dfs(1, 0, 0);
		cout << ans <<'\n';
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
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
