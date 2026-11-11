#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, a, b) for(int i = (a); i <= (b); i ++)
#define DOW(i, a, b) for(int i = (a); i >= (b); i --)
#define pii pair<int, int>
#define fi first
#define se second
#define poly vector<int>
#define polyp vector<pii>
#define pb emplace_back
const int N = 5e5 + 5, inf = 1e9;
int n, k, vis[N];
poly e[N];
int D(int S, int i, int fa) {
	if(S >> (i - 1) & 1) return 0;
	int ans = inf;
	for(auto v : e[i]) 
		if(v != fa) ans = min(ans, D(S, v, i) + 1);
	return ans;
}
int calc(int S) {
//	cerr << S << "wqw\n";
	int ans = 0;
	REP(i, 1, n) ans = max(ans, D(S, i, 0));
	return ans;
}
void dfs(int S, int u) {
	for(auto v : e[u]) 
		if(!vis[v] && (S >> (v - 1) & 1)) 
			vis[v] = 1, dfs(S, v);
}
bool check(int S) {
	int s = 0;
	REP(i, 1, n) vis[i] = 0;
	REP(i, 1, n) if(!vis[i] && (S >> (i - 1) & 1)) dfs(S, i), s ++;
	if(s > 2) return false;
	return true;
}
void Solve() {
	cin >> n >> k;
	REP(i, 1, n) e[i].clear();
	REP(i, 2, n) {
		int u, v;
		cin >> u >> v;
		e[u].pb(v);
		e[v].pb(u);
	}
	int ans = 1e9;
	REP(i, 0, (1 << n) - 1) {
		if(__builtin_popcount(i) != k) continue;
		if(!check(i)) continue;
//		cerr << i << '\n';
		ans = min(ans, calc(i));
//		cerr << i << '\n';
	}
	cout << ans << '\n';
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int c, T = 1;
	cin >> c >> T;
	while(T --) {
		Solve();
	}
	return 0;
}
