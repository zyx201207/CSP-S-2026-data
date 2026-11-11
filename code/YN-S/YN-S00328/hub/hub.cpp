#include <bits/stdc++.h>
#define lc (p<<1)
#define rc (lc|1)
#define mid ((l+r)>>1)
using namespace std;
const int N = 1000005;
int c, T, n, k, vis[N];
int siz[N], d2[N], d[N], dfn[N], seg[N], cntd;
int head[N], nex[N << 1], ver[N << 1], tot;
int tr[N << 3], cnt[N << 3], lazy[N << 3];

void calc(int p, int val) {
	cnt[p] += val;
	lazy[p] += val;
}

void push_down(int p) {
	calc(lc, lazy[p]);
	calc(rc, lazy[p]);
	lazy[p] = 0;
}

void pushup(int p) {
	cnt[p] = max(cnt[lc], cnt[rc]);
	tr[p] = (cnt[p] == cnt[lc] ? tr[lc] : tr[rc]);
}

void build(int p, int l, int r) {
	if (l == r) {
		tr[p] = seg[l];
		cnt[p] = d[tr[p]];
	} else {
		build(lc, l, mid);
		build(rc, mid + 1, r);
		pushup(p);
	}
}

void update(int p, int l, int r, int x, int y) {
	if (x <= l && r <= y) {
		calc(p, -1);
	} else {
		push_down(p);
		if (x <= mid)
			update(lc, l, mid, x, y);
		if (y > mid)
			update(rc, mid + 1, r, x, y);
		pushup(p);
	}
}

void init() {
	cntd = 0;
	tot = 1;
	for (int i = 1; i <= n; ++i) {
		head[i] = 0;
		d[i] = 0;
		vis[i] = 0;
	}
}

void addEdge(int u, int v) {
	ver[++tot] = v, nex[tot] = head[u], head[u] = tot;
	ver[++tot] = u, nex[tot] = head[v], head[v] = tot;
}

void get_size(int u, int f) {
	siz[u] = 1;
	for (int i = head[u]; i; i = nex[i]) {
		int v = ver[i];
		if (v != f && !vis[v]) {
			get_size(v, u);
			siz[u] + siz[v];
		}
	}
}

int get_core(int u) {
	get_size(u, 0);
	int half = siz[u] >> 1, find = 0, f = 0;
	while (!find) {
		find = 1;
		for (int i = head[u]; i; i = nex[i]) {
			int v = ver[i];
			if (v != f && !vis[v] && siz[v] > half) {
				find = 0;
				f = u;
				u = v;
				break;
			}
		}
	}
	return u;
}

void count(int u, int f) {
	d2[u] = d[u];
	for (int i = head[u]; i; i = nex[i]) {
		int v = ver[i];
		if (v != f) {
			count(v, u);
			d2[u] = max(d2[u], d2[v]);
		}
	}
}

void dfs(int u) {
	dfn[u] = ++cntd;
	seg[cntd] = u;
	siz[u] = 1;
	for (int i = head[u]; i; i = nex[i]) {
		int v = ver[i];
		if (!dfn[v] && !vis[v]) {
			d[v] = d[i] + 1;
			dfs(v);
			siz[u] += siz[v];
		}
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--) {
		cin >> n >> k;
		init();
		for (int i = 1; i < n; ++i) {
			int u, v;
			cin >> u >> v;
			addEdge(u, v);
		}
		int core1 = get_core(1), core2 = 0, dmax = 0;
		vis[core1] = 1, --k;
		count(core1, 0);
		for (int i = head[core1]; i; i = nex[i]) {
			int v = ver[i];
			if (!core2 || d2[v] > dmax)
				core2 = v, dmax = d2[v];
		}
		core2 = get_core(core2);
		vis[core2] = 1, --k;
		d[core1] = d[core2] = 0;
		dfs(core2);
		dfs(core1);
		build(1, 1, 2 * n);
		while (k--) {
			int u = tr[1];
			update(1, 1, 2 * n, dfn[u], dfn[u] + siz[u] - 1);
		}
		cout << cnt[1] << '\n';
	}
	return 0;
}