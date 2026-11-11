#include <bits/stdc++.h>
using namespace std;

void fileIO(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

using pii = pair<int, int>;

const int N = 1e6 + 10;

bool vis[N];
int dp[N], d[N];
int testCase, n, k;
vector<int> g[N];

int solve(const vector<pii> &e) {
	for(int i = 1; i <= n; i ++) g[i].clear();
	fill(vis + 1, vis + n + 1, false);
	fill(dp + 1, dp + n + 1, 0);
	
	for(auto p : e) {
		if(!p.first) continue;
		g[p.first].push_back(p.second);
		g[p.second].push_back(p.first);
	}
	
	queue<int> q;
	for(int i = 1; i <= n; i ++) {
		d[i] = g[i].size();
		if(g[i].size() == 1) {
			q.push(i);
			vis[i] = true;
		}
	}
	
	int c = n, ret = 0;
	while(q.size() && c > k) {
		auto u = q.front();
		q.pop();
		if(d[u] == 0) continue;
		ret = max(ret, ++dp[u]);
		c --;
		for(int v : g[u]) {
			dp[v] = max(dp[v], dp[u]);
			if(--d[v] == 1) {
				vis[v] = true;
				q.push(v);
			}
		}
	}
	return ret;
}

int brute() {
	vector<pii> e(n - 1);
	for(int i = 0; i < n - 1; i ++) cin >> e[i].first >> e[i].second;
	int ans = n;
	pii p = {0, 0};
	for(int i = 0; i < n - 1; i ++) {
		swap(p, e[i]);
		ans = min(ans, solve(e));
		//cout << "erase " << p.first << "---" <<p.second << ": " << solve(e) << "\n";
		swap(p, e[i]);
	}
	return ans;
}

int sz[N];
int ms, eid;
void dfs(const vector<pii> &e, int u, int f) {
	sz[u] = 1;
	for(auto id : g[u]) {
		if(id == f) continue;
		int v = e[id].first ^ e[id].second ^ u;
		dfs(e, v, id);
		sz[u] += sz[v];
	}
	if(sz[u] <= n / 2 && sz[u] > ms) {
		ms = sz[u];
		eid = f;
	}
}

int dep[N], fa[N];
void dfs1(const vector<pii> &e, int u, int f) {
	fa[u] = f;
	for(auto id : g[u]) {
		if(id == f) continue;
		int v = e[id].first ^ e[id].second ^ u;
		dep[v] = dep[u] + 1;
		dfs1(e, v, id);
	}
}

int solve() {
	cin >> n >> k;
	if(testCase <= 14 && n <= 5000) return brute();
	if(n <= 500) return brute();
	
	vector<pii> e(n - 1);
	for(int i = 0; i < n - 1; i ++) {
		cin >> e[i].first >> e[i].second;
		g[e[i].first].push_back(i);
		g[e[i].second].push_back(i);
	}
	
	ms = 0;
	dfs(e, 1, -1);
	pii p = {0, 0};
	swap(p, e[eid]);
	int ans = solve(e);
	swap(p, e[eid]);
	
	for(int i = 1; i <= n; i ++) g[i].clear();
	
	for(int i = 0; i < n - 1; i ++) {
		g[e[i].first].push_back(i);
		g[e[i].second].push_back(i);
	}
	
	dep[1] = 0;
	dfs1(e, 1, -1);
	
	int r = max_element(dep, dep + n + 1) - dep;
	dep[r] = 0;
	dfs1(e, r, -1);
	
	int u = max_element(dep, dep + n + 1) - dep, x = dep[u] / 2;
	while(x --) {
		u = e[fa[u]].first ^ e[fa[u]].second ^ u;
	}
	
	swap(p, e[fa[u]]);
	ans = min(ans, solve(e));
	
	for(int i = 1; i <= n; i ++) g[i].clear(); 
	return ans; 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	fileIO("hub");
	
	int T;
	cin >> testCase >> T;
	while(T --)
		cout << solve() << "\n";
}


