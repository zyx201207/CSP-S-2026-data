#include <iostream>
#include <random>
#include <cstring>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>
#define popcount __builtin_popcount
#define stop_sync do { ios::sync_with_stdio(false); cin.tie(nullptr); } while (0)
#define fileio(s) do { freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout); } while (0)
#define rep(i, a, b) for (int i = (int) (a); i <= (int) (b); i++)
#define repl(i, a, b) for (int i = (int) (a); i < (int) (b); i++)
#define repe(it, coll) for (nocpy it : coll)
#define per(i, a, b) for (int i = (int) (a); i >= (int) (b); i--)
#define nocpy const auto &
#define endl '\n'
#define all(iter) (iter).begin(), (iter).end()
#define pred(it, expr) [&] (nocpy it) { return (expr); }
#define comp(lhs, rhs, expr) [&] (nocpy lhs, nocpy rhs) { return (expr); }
#define update_v(v, expr, func) (v) = func((v), (expr))
#define zeroize(v) memset(v, 0x00, sizeof(v))
#define invalidate_max(v) memset(v, 0x3f, sizeof(v))

using namespace std;

constexpr int MAXN =  2e6 + 10;

int n, k;
vector<int> edges[MAXN];

void add_edge(int u, int v) {
	edges[u].push_back(v);
	edges[v].push_back(u);
}


void break_edge(int u, int v) {
	edges[u].erase(find_if(all(edges[u]), pred(it, it == v)));
	edges[v].erase(find_if(all(edges[v]), pred(it, it == u)));
}

void delete_vertex(int u) {
	vector<int> neighbors = edges[u];
	repe(neighbor, neighbors) break_edge(u, neighbor);
}

int depth[MAXN], master[MAXN], max_depth[MAXN];

void dfs_initialize() {
	zeroize(depth), zeroize(master);
}

void dfs(int u) {
	max_depth[u] = depth[u];
	repe(v, edges[u]) if (v != master[u]) {
		depth[v] = depth[u] + 1;
		master[v] = u;
		dfs(v);
		update_v(max_depth[u], max_depth[v] + 1, std::max);
	}
}

void input() {
	cin >> n >> k;
	rep(i, 1, n) edges[i].clear();
	rep(i, 1, n - 1) { int u, v; cin >> u >> v; add_edge(u, v); }
}


pair<int, int> break_center() {
	dfs_initialize(); dfs(1);
	int u = max_element(depth + 1, depth + n + 1) - depth;
	dfs_initialize(); dfs(u);
	int v = max_element(depth + 1, depth + n + 1) - depth;
	int diameter = depth[v], center = v, prev = -1;
	while (depth[center] > diameter / 2) center = master[center];
	break_edge(prev, center);
	return {prev, center};
}

int find_center(int r) {
	dfs_initialize(); dfs(r);
	int u = max_element(depth + 1, depth + n + 1) - depth;
	dfs_initialize(); dfs(u);
	int v = max_element(depth + 1, depth + n + 1) - depth;
	int diameter = depth[v], center = v;
	while (depth[center] > diameter / 2) center = master[center];
	return center;
}

bool vis[MAXN];
int u, v; 
int greedy() {
	priority_queue<pair<int /* dist */, int /* idx */>> q;
	q.push({max_depth[u] - depth[u], u}), q.push({max_depth[v] - depth[v], v});
	while (!q.empty() && k > 0) {
		k--;
		nocpy top = q.top(); q.pop();
		vis[top.second] = true;
		for (int nxt : edges[top.second]) { if (!vis[nxt]) q.push({max_depth[nxt] - depth[nxt], nxt}); };
	}
	return q.empty() ? 0 : q.top().first;
}


void work() {
	input();
	tie(u, v) = break_center();
	int u_center = find_center(u), v_center = find_center(v);
	dfs(u), dfs(v);
	zeroize(vis);
	cout << greedy() << endl;
}


int main() {
	fileio("hub");
	stop_sync;
	int c, t; cin >> c >> t;
	while (t--) work();
	return 0;
}
