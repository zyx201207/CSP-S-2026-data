#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 1;
int n, m;
vector<int> g[N];
bool a[N];
int fa[N];
int find(const int u) {return u == fa[u] ? u : fa[u] = find(fa[u]);}
int hd, tl, q[N], dis[N];
bool flag[N];
int cal() {
	for(int i = 1; i <= n; ++i) fa[i] = i;
	for(int i = 1; i <= n; ++i) for(const auto j : g[i]) if(a[i] && a[j]) fa[find(i)] = find(j);
	int cnt = 0;
	for(int i = 1; i <= n; ++i) if(a[i] && fa[i] == i) ++cnt;
	if(cnt > 2) return n;
	hd = 0, tl = 0;
	for(int i = 1; i <= n; ++i) {
		flag[i] = false;
		if(a[i]) q[++tl] = i, dis[i] = 0, flag[i] = true;
	}
	while(hd < tl) {
		const int u = q[++hd];
		for(const auto v : g[u]) if(!flag[v]) q[++tl] = v, dis[v] = dis[u] + 1, flag[v] = true;
	}
	int res = 0;
	for(int i = 1; i <= n; ++i) res = max(res, dis[i]);
	return res;
}
int ans;
void dfs(const int i = 1) {
	static int cnt;
	if(i == n + 1) {
		if(cnt == m) ans = min(ans, cal());
		return;
	}
	a[i] = true, ++cnt, dfs(i + 1), a[i] = false, --cnt, dfs(i + 1);
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int C, T; cin >>C >>T;
	while(T--) {
		cin >>n >>m;
		for(int i = 1; i <= n; ++i) g[i].clear();
		for(int i = 1, u, v; i < n; ++i) cin >>u >>v, g[u].push_back(v), g[v].push_back(u);
		ans = n, dfs(), cout <<ans <<'\n';
	}
	return 0;
}
