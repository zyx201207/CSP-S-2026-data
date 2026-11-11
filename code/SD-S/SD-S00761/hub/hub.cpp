#include <bits/stdc++.h>
#define ll long long
#define mid ((l + r) >> 1)
#define lowbit(x) ((x) & -(x))

using namespace std;

constexpr int N = 1005;

int C, T, n, k;
int dep[N], fa[N], d1[N], d2[N];
bool vis1[N], vis2[N], flag[N];

struct Baoli {
	int dis[N];
	bool flag[N];
	
	int edge_cnt;
	int head[N];
	struct Edge {
		int v, nxt;
	} e[N << 1];
	
	void add(int u, int v) {
		e[++edge_cnt].nxt = head[u];
		e[edge_cnt].v = v;
		head[u] = edge_cnt;
	}
	
	void dfs(int u, int fa, int d) {
		if (flag[u]) {
			d = 0;
		}
		dis[u] = min(dis[u], d);
		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].v;
			if (v == fa) continue;
			dfs(v, u, d + 1);
		}
	}
	
	void clear() {
		fill(head + 1, head + n + 1, 0);
		edge_cnt = 0;
	}
	
	void Solve() {
		clear(); // clear
		for (int i = 1; i < n; ++i) {
			int u, v;
			cin >> u >> v;
			add(u, v);
			add(v, u);
		}
		
		int ans = 1e9;
		for (int i = 1; i < n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				fill(flag + 1, flag + n + 1, false);
				flag[i] = flag[j] = true;
				bool qwq = true;
				for (int cur = 1; cur <= k - 2; ++cur) {
					fill(dis + 1, dis + n + 1, 1e9);
					dfs(i, 0, 0);
					dfs(j, 0, 0);
					int u = i;
					for (int p = 1; p <= n; ++p) {
						if (dis[p] > dis[u]) {
							u = p;
						}
					}
					while (dis[u] > 1) {
						for (int i = head[u]; i; i = e[i].nxt) {
							if (dis[e[i].v] == dis[u] - 1) {
								u = e[i].v;
								break;
							}
						}
					}
					flag[u] = true;
					if (u < min(i, j)) {
						qwq = false;
						break;
					}
				}
				if (!qwq) {
					continue;
				}
				fill(dis + 1, dis + n + 1, 1e9);
				dfs(i, 0, 0);
				dfs(j, 0, 0);
				ans = min(ans, *max_element(dis + 1, dis + n + 1));
//				if (*max_element(dis + 1, dis + n + 1) == 17) {
//					cerr << "qwq: " << i << ' ' << j << '\n';
//				}
			}
		}
		
		cout << ans << '\n';
	}
} qwq;

int edge_cnt;
int head[N];
struct Edge {
	int v, nxt;
} e[N << 1];

void add(int u, int v) {
	e[++edge_cnt].nxt = head[u];
	e[edge_cnt].v = v;
	head[u] = edge_cnt;
}

void clear() {
	fill(head + 1, head + n + 1, 0);
	edge_cnt = 0;
}

int dfs(int u, int fa, int w) {
	dep[u] = 1;
	int res = 0;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if (v == fa) continue;
		res += dfs(v, u, w);
		dep[u] = max(dep[u], dep[v] + 1);
		if (res > k) {
			break;
		}
	}
	if (dep[u] > w) {
		++res;
	} else {
		res = 0;
	}
	return res;
}

bool Flag;
void dfs1(int u, int f, int d, int id) {
	if (id == 0) {
		fa[u] = f;
		d1[u] = d;
	} else {
		if (vis1[u]) {
			return;
		}
		d2[u] = d;
		vis2[u] = true;
//		if (u == 2 && Flag == true && id == 1) {
//			cerr << "dfs1: " << vis2[u] << '\n';
//		}
	}
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if (v == f) continue;
		dfs1(v, u, d + 1, id);
	}
}

void dfs2(int u, int fa) {
	vis2[u] = false;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if (v == fa) continue;
		dfs2(v, u);
	}
}

void Solve() {
	clear(); // clear
	cin >> n >> k;
	if (n <= 100 || k <= 2) {
		qwq.Solve();
		return;
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		add(u, v);
		add(v, u);
	}
	
	int k_ = k;
	k = 114514;
	dfs(1, 0, n);
	int dis_ = dep[1];
	k = k_;
	
	int ans = 1e9;
	for (int i = 1; i <= n; ++i) {
		flag[i] = true;
		for (int j = 1; j <= n; ++j) {
			int w = dfs(i, 0, j);
			if (w == 0) {
				++w;
			}
			if (w <= k) {
//				if (j == 1) cerr << "???: " << i << ' ' << j << '\n', exit(0);
				ans = min(ans, j);
				break;
			}
		}
	}
//	cerr << "ans: " << ans << '\n';
	for (int x = 1; x <= n; ++x) {
		for (int y = x + 1; y <= n; ++y) {
			fill(vis1, vis1 + n + 1, false);
			fill(vis2, vis2 + n + 1, false);
			fill(flag, flag + n + 1, false);
			vis1[x] = true;
			Flag = (x == 1 && y == 3);
			dfs1(x, 0, 0, 0);
			dfs1(y, 0, 0, 1);
			dfs2(y, fa[y]);
			int w = 0;
			for (int u = 1; u <= n; ++u) {
				if (vis2[u] == true) {
					flag[u] = true;
					w = max(w, min(d1[u], d2[u]));
				}
			}
			if (w > ans || w > dis_) {
				continue;
			}
			int res = 0;
			for (int i = head[x]; i; i = e[i].nxt) {
				int v = e[i].v;
				if (flag[v] || v == y) {
					int val = dfs(x, v, w);
					if (val == 0) {
						++val;
					}
					res += val;
					break;
				}
			}
			if (res < k) {
				for (int i = head[y]; i; i = e[i].nxt) {
					int v = e[i].v;
					if (flag[v] || v == x) {
						int val = dfs(y, v, w);
						if (val == 0) {
							++val;
						}
						res += val;
						break;
					}
				}
				if (res <= k) {
					ans = min(ans, w);
				}
			}
			
			++w;
			if (w > ans) {
				continue;
			}
			res = 0;
			for (int i = head[x]; i; i = e[i].nxt) {
				int v = e[i].v;
				if (flag[v] || v == y) {
					int val = dfs(x, v, w);
					if (val == 0) {
						++val;
					}
					res += val;
					break;
				}
			}
			if (res < k) {
				for (int i = head[y]; i; i = e[i].nxt) {
					int v = e[i].v;
					if (flag[v] || v == x) {
						int val = dfs(y, v, w);
						if (val == 0) {
							++val;
						}
						res += val;
						break;
					}
				}
				if (res <= k) {
					ans = min(ans, w);
				}
			}
		}
	}
	
	cout << ans << '\n';
	cerr << "qwq\n";
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> C >> T;
	while (T--) {
		Solve();
	}
	
	cerr << "time: " << (double)clock() / CLOCKS_PER_SEC << '\n';
	
	return 0;
}
/*
我已急哭啊，O(n^3) 根本跑不过 3.in/ll
*/
