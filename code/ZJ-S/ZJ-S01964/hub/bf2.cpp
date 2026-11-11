#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define INF_LL 0x3f3f3f3f3f3f3f3f
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1e6 + 5;

int n, k;

int a[N], b[N], d[N];

vector<int> vec[N];

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

void del(aux &x, node &y) {
	if (y.tot) {
		x.tot -= y.tot;
		x.sum -= y.len;
		--x.cnt;
	} else {
		int t = y.len + 1;
		if (x.mx[0] == t) {
			x.mx[0] = x.mx[1];
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

int num[N];

void dfs0(int u, int fa) {
	// g[u] = aux();
	for (int v : vec[u]) {
		if (v == fa) {
			continue;
		}
		dfs0(v, u);
		// merge(g[u], f[v]);
	}
	// get(f[u], g[u]);
}

void dfs1(int u, int fa) {
	node fu = f[u];
	aux gu = g[u];
	if (fa) {
		aux gf = g[fa];
		del(gf, f[u]);
		node ff;
		get(ff, gf);

		num[u] += max(ff.tot, 1);
		merge(g[u], ff);
		get(f[u], g[u]);
	}
	for (int v : vec[u]) {
		if (v == fa) {
			continue;
		}
		dfs1(v, u);
	}
	if (fa) {
		f[u] = fu, g[u] = gu;
	}
}

bool check() {
	dfs0(1, 0);
	// for (int i = 2; i <= n; ++i) {
	// 	num[i] = max(f[i].tot, 1);
	// }
	// dfs1(1, 0);
	// for (int i = 2; i <= n; ++i) {
	// 	if (num[i] <= k) {
	// 		return 1;
	// 	}
	// }
	return 0;
}

void solve() {
	cin >> n >> k;
	fill(d + 1, d + n + 1, 0);
	for (int i = 1; i < n; ++i) {
		cin >> a[i] >> b[i];
		++d[a[i]], ++d[b[i]];
	}
	for (int i = 1; i <= n; ++i) {
		vec[i].clear();
		vec[i].reserve(d[i]);
	}
	for (int i = 1; i < n; ++i) {
		vec[a[i]].push_back(b[i]), vec[b[i]].push_back(a[i]);
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
	assert(freopen("hub.out", "w", stdout));

	cin.tie(0)->sync_with_stdio(0);

	int c, T;
	cin >> c >> T;
	while (T--) {
		solve();
	}

	return 0;
}