#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
ifstream fin("hub.in");
ofstream fout("hub.out");
constexpr int MAXN = 1e6 + 5;
constexpr int INF = 1e9;
vector<int> G[MAXN];
pair<int, int> ll[MAXN], ss[MAXN];
int out[MAXN];
void init(int u, int p) {
	ll[u] = {0, u};
	for (int v : G[u]) {
		if (v == p) continue;
		init(v, u);
		if (ss[v].first + 1 > ll[u].first) {
			ss[u] = ll[u];
			ll[u] = {ss[v].first + 1, v};
		} 
		if (ll[v].first + 1 > ll[u].first) {
			ss[u] = ll[u];
			ll[u] = {ll[v].first + 1, v};
		}
	}
	return ;
}
void init2(int u, int p) {
	if (out[p] != -1) out[u] = out[p] + 1; 
	if (ll[p].second != u) out[u] = max(out[u], ll[p].first + 1);
	else out[u] = max(out[u], ss[p].first + 1);
	for (int v : G[u]) {
		if (v == p) continue;
		init2(v, u);
	}
	return ;
}
int dp[MAXN][8];
void dfs(int u, int p) {
	
	
	
	return ;
}
bool check(int val, int k, int n) {
	for (int u = 1; u <= n; ++u) fill(dp[u], dp[u] + 5, INF);
	dfs(1, 0);
	int ans = INF;
	for (int u = 1; u <= n; ++u) ans = min({ans, dp[u][0], dp[u][1], dp[u][2]});
	return (ans <= k);
}
int main() {
	int c, t;
	fin >> c >> t;
	while (t--) {
		int n, k;
		fin >> n >> k;
		for (int u = 1; u <= n; ++u) G[u].clear();
		for (int i = 1; i < n; ++i) {
			int u, v;
			fin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
			ll[u] = {-1, -1};
			ss[u] = {-1, -1};
			out[u] = -1;
		}
		fout << 2 << '\n';
	}
	return 0;
}
