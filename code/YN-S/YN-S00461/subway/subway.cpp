#include <bits/stdc++.h>
using namespace std;
#define int long long
int w[500005];
int t[505][500005];
int x[500005], y[500005];
int c, n, m, d, q;

int h[4] = {0, 1, 0, -1};

int l[4] = {1, 0, -1, 0};
int min1 = INT_MAX;

void dfs(int n, int x1, int y1, int sum) {
	if (x1 == x[n] && y1 == y[n]) {
		if (sum < min1) {
			min1 = sum;
		}
	} else {
		for (int i = 0; i < 4; i++) {
			int nx = x1 + h[i], ny = y1 + l[i];
			if (nx >= 1 && nx <= n + 2 && ny >= 1 && ny <= m && t[nx][ny] != 0) {
				dfs(n, nx, ny, sum + t[x1][y1]);
			}
			dfs(n, nx, ny, sum);
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 2; i <= n + 1; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a;
			cin >> a >> t[i][a];
		}
	}
	for (int i = 1; i <= m; i++) {
		t[1][i] = t[n + 1][i];
		t[n + 2][i] = t[2][i];
	}
	for (int i = 1; i < q; i++) {
		cin >> x[i] >> y[i];
		dfs(i, 1, 1, 0);
		cout << min1 << "\n";
	}
	return 0;
}