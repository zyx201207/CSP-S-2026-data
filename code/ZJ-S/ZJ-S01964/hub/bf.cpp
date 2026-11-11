#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define INF_LL 0x3f3f3f3f3f3f3f3f
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1e6 + 5;

int n, k;

int a[N], b[N];

int nxt[N << 1], to[N << 1], id[N << 1], hd[N], edc;

void adde(int x, int y, int z) {
	++edc;
	nxt[edc] = hd[x];
	to[edc] = y;
	id[edc] = z;
	hd[x] = edc;
}

int lim;

struct aux {
	int tot, cnt, sum;
	array<int, 2> mx;
	aux() : tot(), cnt(), sum(), mx{} {};
};

struct node {
	int tot, len;
	node() : tot(), len() {}
	node(int tot, int len) : tot(tot), len(len) {}
};

void merge(aux &x, node y) {
	if (y.tot) {
		x.tot += y.tot;
		x.sum += y.len;
		++x.cnt;
	} else {
		int t = y.len + 1;
		if (x.mx[0] < t) {
			x.mx[1] = x.mx[0];
			x.mx[0] = t;
		} else if (x.mx[1] < t) {
			x.mx[1] = y.len;
		}
	}
}

void get(node &x, aux &y) {
	if (y.cnt == 0) {
		if (y.mx[0] == lim) {
			x = node(1, 0);
		} else {
			x = node(0, y.mx[0]);
		}
	} else if (y.cnt == 1) {
		x = node(y.tot, y.sum + 1);
		int det = x.len + y.mx[0] - lim;
		if (det > 0) {
			x.tot += det;
			x.len -= det;
		}
	} else {
		x = node(y.tot + y.sum + 1, 0);
	}
}

node f[N];

aux g[N];

void dfs(int u, int fa) {
	g[u] = aux();
	for (int i = hd[u]; i; i = nxt[i]) {
		int v = to[i];
		if (v == fa) {
			continue;
		}
		dfs(v, u);
		merge(g[u], f[v]);
	}
	get(f[u], g[u]);
}

bool check() {
	int mn = n;
	for (int i = 1; i < n; ++i) {
		dfs(a[i], b[i]);
		dfs(b[i], a[i]);
		if (max(1, f[a[i]].tot) + max(1, f[b[i]].tot) <= k) {
			return 1;
		}
	}
	return 0;
}

void solve() {
	cin >> n >> k;
	fill(hd + 1, hd + n + 1, 0), edc = 0;
	for (int i = 1; i < n; ++i) {
		cin >> a[i] >> b[i];
		adde(a[i], b[i], i), adde(b[i], a[i], i);
	}
	if (n == k) {
		cout << "0\n";
		return ;
	}

	int l = 1, r = n;
	while (l <= r) {
		lim = (l + r) >> 1;
		if (check()) {
			r = lim - 1;
		} else {
			l = lim + 1;
		}
	}
	cout << l << '\n';
}

int main() {
	assert(freopen("hub.in", "r", stdin));
	assert(freopen("hub.ans", "w", stdout));

	cin.tie(0)->sync_with_stdio(0);

	int c, T;
	cin >> c >> T;
	while (T--) {
		solve();
	}

	return 0;
}