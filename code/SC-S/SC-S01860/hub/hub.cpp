#include <bits/stdc++.h>

#define ll long long
#define str string
#define db double

using namespace std;

constexpr int MAXN = 1e5 + 5;

int c, t, n, k, ans, dep[MAXN], lca[MAXN][20];
vector<int> grh[MAXN];
bitset<MAXN> cho;
vector<int> use;

void Dfs(int now) {
	cho[now] = 1;
	for (const auto& v : grh[now])
		if (!cho[v]) {
			dep[v] = dep[now] + 1;
			lca[v][0] = now;
			for (int i = 1; i <= 18; ++i)
				lca[v][i] = lca[lca[v][i - 1]][i - 1];
			Dfs(v);
		}
	cho[now] = 0;
}

int Lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);

	int cnt = dep[x] - dep[y];
	for (int i = 18; i >= 0; i--)
		if ((1 << i) <= cnt) {
			cnt -= (1 << i);
			x = lca[x][i];
		}

	if (x == y) return x;

	for (int i = 18; i >= 0; i--)
		if (lca[x][i] != lca[y][i]) {
			x = lca[x][i], y = lca[y][i];
		}

	return lca[x][0];
}

int work() {
	int ret = 0;

	for (int i = 1; i <= n; ++i) {
		if (cho[i]) continue;

		int fnd = 1e9;
		for (const auto& v : use) {
			fnd = min(fnd, dep[i] + dep[v] - 2 * dep[Lca(i, v)]);
		}

		ret = max(ret, fnd);
	}

	return ret;
}

void dfs(int now, int cnt) {
	if ((int)use.size() + (n - now + 1) < k) return;
	if (now == n + 1) {
		if ((int)use.size() == k) {
			int fnd = work();
			ans = min(ans, fnd);
		}
		return;
	}

	bool fnd = false;
	for (const auto& v : grh[now])
		if (cho[v]) {
			fnd = true;
			break;
		}

	if (fnd && (int)use.size() < k) {
		cho[now] = 1, use.emplace_back(now);
		dfs(now + 1, cnt);
		cho[now] = 0, use.pop_back();
	} else if (!fnd && (int)use.size() < k && cnt < 2) {
		cho[now] = 1, use.emplace_back(now);
		dfs(now + 1, cnt + 1);
		cho[now] = 0, use.pop_back();
	}
	dfs(now + 1, cnt);
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> c >> t;
	while (t--) {
		fill(grh, grh + MAXN, vector<int>());
		memset(dep, 0, sizeof dep);
		memset(lca, 0, sizeof lca);
		ans = 1e9;

		cin >> n >> k;
		for (int i = 1, u, v; i < n; ++i) {
			cin >> u >> v;
			grh[u].emplace_back(v);
			grh[v].emplace_back(u);
		}

		Dfs(1), dfs(1, 0);
		
		cout << ans << '\n';
	}

	return 0;
}