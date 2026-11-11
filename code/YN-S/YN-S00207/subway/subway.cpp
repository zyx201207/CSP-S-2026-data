#include <bits/stdc++.h>
using namespace std;
int w[500001];
vector<pair<int, int>>lx[501];
vector<pair<int, int>>z[500001];
int ans[500001];

void dfs(int node, int goal, int step) {
	ans[node] = step;

	if (node == goal) {
		return;
	}

	for (auto i : z[node]) {
		step += i.second;

		for (auto j : lx[i.first]) {
			if (step + j.second < ans[j.first]) {
				dfs(j.first, goal, step + j.second);
			}
		}

		step -= i.second;
	}

	return;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;

	for (int i = 1; i <= m; i++) {

		cin >> w[i];
	}

	for (int i = 1; i <= n; i++) {

		int y;
		cin >> y;

		for (int j = 1; j <= y; j++) {

			int aa, cc;
			cin >> aa >> cc;
			lx[i].push_back({aa, cc});
			z[aa].push_back({i, cc});
		}
	}

	for (int i = 1; i <= q; i++) {

		memset(ans, 0x3f, sizeof ans);
		int x, y;
		cin >> x >> y;
		dfs(x, y, w[x]);
		cout << ans[y] + w[y] << endl;
	}

	return 0;
}