#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int h[N], otto;
int n, k;

struct edge {
	int u, v, ne;
} e[2 * N];

void add(int u, int v) {
	e[otto].u = u;
	e[otto].v = v;
	e[otto].ne = h[u];
	h[u] = otto++;
}
int fa[N], v[N];

int find(int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

bool merge(int x, int y) {
	int fx = find(x),
	    fy = find(y);
	if (fx == fy)
		return false;
	fa[fx] = fy;
	return true;
}

bool check() {
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	int cnt = k;
	for (int i = 0; i < otto; i += 2) {
		if (v[e[i].u] && v[e[i].v]) {
			if (merge(e[i].u, e[i].v)) {
				cnt--;
			}
		}
	}
	return cnt <= 2;
}

int dfs(int u, int ch) {
	if (u > n)
		return 0;
	if (ch == k) {
		if (check() == false)
			return INT_MAX;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (v[i])
				continue;
			int res = 1145141919;
			for (int j = h[i]; j != -1; j = e[i].ne) {
				int to = e[i].v;
				if (v[to])
					continue;
				res = min(res, 1);
			}
			ans = max(ans, res);
		}
		return ans;
	}
	int ans = 1145141919;
	if (ch < k) {
		v[u + 1] = 1;
		ans = dfs(u + 1, ch + 1);
	}
	v[u + 1] = 0;
	return min(ans, dfs(u + 1, ch));
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, T;
	cin >> c >> T;
	while (T--) {
		memset(h, -1, sizeof h);
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			add(u, v);
			add(v, u);
		}
		cout << dfs(0, 0) << '\n';
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