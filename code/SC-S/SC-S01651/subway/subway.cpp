#include<bits/stdc++.h>
using namespace std;

int n, m, d, q;

int ans;
vector<int> w;
vector<vector<int>>t;
vector<vector<pair<int, int>>>a;

void dfs(int now, int path, int fa, int ed, int idx) {
	if (now == ed) {
//		cout << now << " " << path << " " << fa << " " << ed << " " << idx << " " << t[idx][ed] + w[ed] << endl;
		ans = min(ans, path + t[idx][ed] + w[ed]);
		return;
	}

	if (path > ans) return;

	for (pair<int, int> i : a[now]) {
		if (i.first == fa) continue;
		int length = 0;

		if (idx == i.second) dfs(i.first, path, now, ed, idx);
		else {
			if (idx == 0) length += w[now];
			else length += t[idx][now];
			length += t[i.second][now];
			dfs(i.first, path + length, now, ed, i.second);
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c;
	cin >> c >> n >> m >> d >> q;
	w.resize(n + 10);
	a.resize(n + 10);
	t.resize(n + 10);

	for (int i = 1; i <= m; ++i) cin >> w[i], t[i].resize(m + 10);
	for (int i = 1; i <= n; ++i) {
		int len;
		cin >> len;
		int last_x;
		for (int j = 1, x; j <= len; ++j) {
			cin >> x >> t[i][x];
			if (j != 1) {
				a[x].push_back({last_x, i});
				a[last_x].push_back({x, i});
			}
			last_x = x;
		}
	}

	while (q--) {
		ans = 0x3f3f3f3f;
		int l, r;
		cin >> l >> r;
//		cout << w[3] << " " << t[2][3] << endl;
		dfs(l, 0, -1, r, 0);

		cout << ans << endl;
	}


	return 0;
}