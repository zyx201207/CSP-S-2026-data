#include <bits/stdc++.h>

#define int long long 

#define PII pair<int, int>

#define mkp make_pair

using namespace std;

const int N = 1e6 + 10;
const int inf = 1e18;

int n, k;
int dep[N];
int anc[N][21];
vector<int> e[N];
int chosen[N];
int mark[N];

void dfs1(int now, int fa) {
	anc[now][0] = fa;
	dep[now] = dep[fa] + 1;
	for (int i = 1; i <= 20; ++i) {
		anc[now][i] = anc[anc[now][i - 1]][i - 1];
	}
	for (auto k : e[now]) {
		if (k == fa) continue;
		dfs1(k, now);
	}
} 

int lca(int x, int y) {
	if (dep[x] < dep[y]) {
		swap(x, y);
	}
	for (int i = 20; i >= 0; --i) {
		if (dep[anc[x][i]] >= dep[y]) x = anc[x][i];
	}
	if (x == y) return x;
	for (int i = 20; i >= 0; --i) {
		if (anc[x][i] != anc[y][i]) {
			x = anc[x][i];
			y = anc[y][i];
		}
	}
	return anc[x][0];
}

void dfs2(int now) {
	mark[now] = 1;
	for (auto k : e[now]) {
		if (!mark[k] && chosen[k]) {
			dfs2(k);
		}
	}
}

bool checkfound() {
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (chosen[i] == 1 && mark[i] == 0) {
			cnt++;
			dfs2(i);
		}
		if (cnt > 2) return false;
	}
	return true;
}

int getdist() {
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int tmp = inf;
		for (int j = 1; j <= n; ++j) {
			if (chosen[j]) {
				//¿´¿´¾àÀë
				int nowdist = dep[j] + dep[i] - 2 * dep[lca(i, j)];
				tmp = min(tmp, nowdist);
			}
		}
		ans = max(ans, tmp);
	}
	return ans;
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c, T;
	cin >> c >> T;
	while (T--) {
		for (int i = 1; i <= n; ++i) {
			e[i].clear();
			dep[i] = 0;
			for (int j = 0; j <= 20; ++j) {
				anc[i][j] = 0;
			}
		} 
		int res = inf;
		cin >> n >> k;
		for (int i = 1; i < n; ++i) {
			int u, v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u); 
		} 
		dfs1(1, 0);
		for (int mask = 0; mask < (1ll << n); ++mask) {
			if (__builtin_popcount(mask) != k) continue;
			for (int i = 1; i <= n; ++i) {
				chosen[i] = mark[i] = 0;
			}
			for (int i = 1; i <= n; ++i) {
				if (mask >> (i - 1) & 1) {
					chosen[i] = 1;
				}
			}
			if (checkfound() == 0) {
				continue; 
			}
			res = min(res, getdist());
		}
		cout << res << "\n";
	}
	return 0;
}
