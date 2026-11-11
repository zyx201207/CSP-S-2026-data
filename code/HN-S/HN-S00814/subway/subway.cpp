#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10, M = 510;

int c, n, m, d, q, x, y, ans, k[N], w[N], tmp, t[M][N]; 

vector<int> aa[N];

void dfs(int x, int sum) {
	if (x == y) {
		ans = min(ans, sum);
		return ;
	}
	flag[x] = 1;
	for (auto i : aa[x]) {
		if (flag[i] != 1) {
			dfs(i, sum + t[i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> tmp >> t[i][j];
			aa[a[i][j]].push_back(i);
		}
	}
	while (q--) {
		cin >> x >> y;
		ans = w[x] + w[y];
		dfs(x, INT_MAX);
		cout << ans + sum << '\n';
	}
	return 0;
}
