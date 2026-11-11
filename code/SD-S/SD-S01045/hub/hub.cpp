#include <bits/stdc++.h>
#define ls v << 1
#define rs v << 1 | 1

using namespace std;

//object:
const int N = 1e3 + 50;
int c, T, n, k, u, v, cur[N], nums[N], col[N], vis[N], dis[N][N];
int dep[N], siz[N], son[N], prt[N];
int top[N], dfn[N], rnk[N], timer;

//data structure:
vector <int> G[N];
struct Node {
	int l, r;
	int sum;
} t[N << 2];
struct Edge {
	int u, v, w;
};
vector <Edge> Edg;

//function:
void push_up (int v) {
	t[v].sum = t[ls].sum + t[rs].sum; 
}

void build (int l, int r, int v) {
	t[v] = {l, r, 0};
	if (l == r) {
		t[v].sum = nums[rnk[l]];
		return;
	}
	int mid = l + r >> 1;
	build (l, mid, ls);
	build (mid + 1, r, rs);
	push_up(v);
}

int query (int ql, int qr, int v) {
	if (ql > t[v].r || qr < t[v].l) return 0;
	if (ql <= t[v].l && t[v].r <= qr) return t[v].sum;
	int mid = t[v].l + t[v].r >> 1, ret = 0;
	ret += query (ql, qr, ls);
	ret += query (ql, qr, rs);
	return ret;
}

int tree_q (int x, int y) {
	int ret = 0;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap (x, y);
		ret += query (dfn[top[x]], dfn[x], 1);
		x = prt[top[x]]; 
	}
	if (dep[x] > dep[y]) swap (x, y);
	ret += query (dfn[x] + 1, dfn[y], 1);
	return ret;
}

void DFS (int u, int fa) {
	col[u] = 0;
	for (int v : G[u]) {
		if (v == fa) continue;
		if (col[v] == 0) continue;
		DFS (v, u);
	}
}

void DFS1 (int u, int fa) {
	siz[u] = 1;
	prt[u] = fa;
	dep[u] = dep[fa] + 1;
	int maxson = -1;
	for (int v : G[u]) {
		if (v == fa) continue;
		DFS1 (v, u);
		siz[u] += siz[v];
		if (maxson < siz[v]) {
			maxson = siz[v];
			son[u] = v;
		}
	}
}
void DFS2 (int u, int tops) {
	dfn[u] = ++ timer;
	rnk[dfn[u]] = u;
	top[u] = tops;
	if (!son[u]) return;
	DFS2 (son[u], tops);
	for (int v : G[u]) {
		if (v == prt[u] || v == son[u]) continue;
		DFS2 (v, v);
	}
}

int main() {
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	cin >> c >> T;
	while (T --) {
		cin >> n >> k;
		memset (dis, 0, sizeof dis);
		memset (nums, 0, sizeof nums);
		memset (col, 0, sizeof col);
		//int dep[N], siz[N], son[N], prt[N];
		//int top[N], dfn[N], rnk[N], timer;
		memset (dep, 0, sizeof dep);
		memset (siz, 0, sizeof siz);
		memset (son, 0, sizeof son);
		memset (prt, 0, sizeof prt);
		memset (top, 0, sizeof top);
		memset (dfn, 0, sizeof dfn);
		memset (rnk, 0, sizeof rnk);
		Edg.clear();
		for (int i = 0; i < N - 5; i ++) {
			G[i].clear();
		}
		for (int i = 1; i <= n - 1; i ++) {
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
			Edg.push_back({u, v, 1});
		}
		for (int i = 0; i < n - 1; i ++) {
			int t = (dep[Edg[i].u] > dep[Edg[i].v] ? Edg[i].u : Edg[i].v);
			nums[t] = 1;
		}
		DFS1 (1, 0);
		DFS2 (1, 1);
		build (1, n, 1);
		
		for (int i = 1; i <= n; i ++) {
			cur[i] = i;
		}
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				dis[i][j] = tree_q(i, j);
			}
		}
//		for (int i = 1; i <= n; i ++) {
//			for (int j = 1; j <= n; j ++) {
//				cout << dis[i][j] << " ";
//			}
//			cout << "\n";
//		}
		int min_tmp = 1e9;
		do {
			vector <int> state;
			for (int i = 1; i <= k; i ++) {
				state.push_back(cur[i]);
				col[cur[i]] = 1;
//				cout << cur[i] << " ";
			}
			int ans = 0;
			for (int i = 1; i <= n; i ++) {
				if (col[i] == 1) {
					ans ++;
					DFS (i, prt[i]);
				}
			}
			if (ans > 2) continue;
			else {
				int maxx = -1e9;
				for (int i = 0; i < state.size(); i ++) {
					for (int j = 0; j < state.size(); j ++) {
						maxx = max (maxx, dis[state[i]][state[j]]);
					}
				}
				min_tmp = min (min_tmp, maxx);
			}
		} while (next_permutation(cur + 1, cur + n + 1));
		cout << min_tmp << "\n";
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
