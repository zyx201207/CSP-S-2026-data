#include<bits/stdc++.h>
#define endl '\n'
#define MSOD

using namespace std;
using ll = long long;

const int N = 1e1 + 5;

int n, k, U, V, t;
int dep[N], dfn[N], f[N][10];
vector<int> T[N];

int cmp(int u, int v) {
	return (dep[u] < dep[v] ? u : v);
}

void dfs(int u, int fa) {
	f[u][0] = fa, dep[u] = dep[fa] + 1;
	for(auto v : T[u]) {
		if(v == fa) continue;
		dfs(v, u);
	}
	return;
}

int lca(int u, int v) {
	if(dep[u] > dep[v]) swap(u, v);
	for(int i = 9 ; i >= 0 ; i --) if(f[v][i] && dep[f[v][i]] >= dep[u]) v = f[v][i];
	if(u == v) return u;
	for(int i = 9 ; i >= 0 ; i --) if(f[v][i] && f[u][i] && f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
	return f[u][0];
}

int dis(int u, int v) {
	return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

bool ok[N];

void col(int u, int fa) {
	ok[u] = false;
	for(auto v : T[u]) if(v != fa && ok[v]) col(v, u);
	return;
}

void TEST() {
	cin>>n>>k;
	memset(f, 0, sizeof f);
	for(int i = 1 ; i <= n ; i ++) T[i].clear();
	for(int i = 1 ; i < n ; i ++) {
		int u, v;
		cin>>u>>v;
		T[u].push_back(v), T[v].push_back(u); 
	}
	dfs(1, 0);
	for(int j = 1 ; 1 << j <= n ; j ++) for(int i = 1 ; i <= n ; i ++) f[i][j] = f[f[i][j - 1]][j - 1];
	vector<int> msk;
	int ans1 = 2e9;
	for(int S = 0 ; S < (1 << n) ; S ++) {
		if(__builtin_popcount(S) != k) continue;
		fill(ok + 1, ok + n + 1, false);
		for(int i = 1 ; i <= n ; i ++) if((S >> i - 1) & 1) ok[i] = true;
		int ans = 0;
		for(int i = 1 ; i <= n ; i ++) {
			if(ok[i]) continue;
			int mn = 2e9;
			for(int j = 1 ; j <= n ; j ++) {
				if(!ok[i] && ok[j]) mn = min(mn, dis(i, j));
			}
			ans = max(ans, mn);
		}
		int cnt = 0;
		for(int i = 1 ; i <= n ; i ++) {
			if(ok[i]) {
				col(i, 0);
				cnt ++;
			}
		}
		if(cnt >= 3) continue;
		ans1 = min(ans1, ans);
	}
	cout<<ans1<<endl;
	return;
}

signed main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int TC = 1;
#ifdef MSOD
	cin>>TC>>TC;
#endif
	while(TC --) TEST();
	return 0;
}
