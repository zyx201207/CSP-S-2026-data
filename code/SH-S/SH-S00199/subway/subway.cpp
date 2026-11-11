#include <bits/stdc++.h>
#define ll long long
#define ull long long
using namespace std;

const int maxM = 5e5 + 10, maxN = 510;
int c, n, m, d, q, tot, k[maxN];
ll w[maxM], dis[maxN + maxM], ans[maxM];
struct Edge{
	int to;
	ll val;
	bool operator < (const Edge &others) const {return val > others.val;}
};
vector<Edge> G[maxM + maxN];
priority_queue<Edge> heap;
vector<int> used;
struct Query{int to, id;};
vector<Query> Q[maxM];

inline int id(int pos) {return m + pos;}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		if (k[i] == 1) continue;
		else if (k[i] == 2) {
			int v1, v2;
			ll w1, w2;
			cin >> v1 >> w1 >> v2 >> w2;
			G[v1].push_back({v2, w1 + w2});
			G[v2].push_back({v1, w1 + w2}); 
		} else {
			for (int j = 1; j <= k[i]; j++) {
				int to;
				ll val;
				cin >> to >> val;
				G[to].push_back({id(i), val});
				G[id(i)].push_back({to, val});
			}
		}
	}
	while (q--) {
		int xr, yr;
		tot++;
		cin >> xr >> yr;
		used.push_back(xr);
		Q[xr].push_back({yr, tot});
	}
	for (int xr : used) {
		memset(dis, 0x3f, sizeof(dis));
		dis[xr] = 0;
		heap.push({xr, 0});
		while (!heap.empty()) {
			Edge cur = heap.top();
			heap.pop();
			int u = cur.to;
			if (dis[u] != cur.val) continue;
			for (const Edge &edge : G[u]) {
				int v = edge.to;
				ll w = edge.val;
				if (dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					heap.push({v, dis[v]});
				}
			}
		}
		for (const Query &tes : Q[xr]) {
			int yr = tes.to, id = tes.id;
			ans[id] = dis[yr] + w[xr] + w[yr];
		}
	}
	for (int i = 1; i <= tot; i++) cout << ans[i] << '\n';
	return 0;
}
/*
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxM = 5e5 + 10, maxN = 510, maxTot = maxN + maxM, maxLog = 25;
int c, n, m, d, q, cnt, tot;
int k[maxN], f[maxN], siz[maxTot], fa[maxTot][maxLog], depth[maxTot];
ll w[maxM], dis[maxTot];
struct Edge{
	int from, to;
	ll val;
	bool operator < (const Edge &others) const {return val < others.val;}
};
vector<Edge> edges;
struct Node{
	int to;
	ll val;
};
vector<Node> tree[maxN];

inline int id(int line) {return line + m;}
inline int find(int id) {
	if (f[id] == id) return id;
	else return f[id] = find(f[id]);
}
inline void merge(int u, int v) {
	if (siz[u] < siz[v]) swap(u, v);
	f[v] = u;
	siz[u] += siz[v];
}
void dfs(int u, int father) {
	fa[u][0] = father;
	depth[u] = depth[father] + 1;
	for (int j = 1; j < maxLog; j++) fa[u][j] = fa[fa[u][j - 1]][j - 1];
	for (const Node &temp : tree[u]) {
		int v = temp.to;
		ll w = temp.val;
		if (v == father) continue;
		dis[v] = dis[u] + w;
		dfs(v, u);
	} 
}
int lca(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);
	for (int j = maxLog - 1; j >= 0; j--) if (depth[fa[u][j]] >= depth[v]) u = fa[u][j];
	if (u == v) return v;
	for (int j = maxLog - 1; j >= 0; j--) {
		if (fa[u][j] != fa[v][j]) {
			u = fa[u][j];
			v = fa[v][j];
		}
	} 
	return fa[u][0];
}
ll getMinDistance(int u, int v) {
	int l = lca(u, v);
	return dis[u] + dis[v] - 2 * dis[l];
}

int main() {
	freopen("subway1.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	tot = n + m;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			int to;
			ll val;
			cin >> to >> val;
			edges.push_back({id(i), to, val});
		}
	}
	sort(edges.begin(), edges.end());
	for (int i = 1; i <= tot; i++) {
		siz[i] = 1;
		f[i] = i;
	}
	for (const Edge &edge : edges) {
		int u = find(edge.from), v = find(edge.to);
		ll w = edge.val;
		if (u == v) continue;
		merge(u, v);
		cnt++;
		tree[u].push_back({v, w});
		tree[v].push_back({u, w}); 
		if (cnt == tot - 1) break;
	}
	dfs(1, 0);
	while (q--) {
		int xr, yr;
		cin >> xr >> yr;
		cout << getMinDistance(xr, yr) + w[xr] + w[yr] << '\n';
	}
	return 0; 
}*/
