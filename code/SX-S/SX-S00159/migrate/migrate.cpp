#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		vector<int> x(n + 5, 0);
		int a[305][305];
		memset(a, 0x3f, sizeof a);
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
			if (x[i] - x[i - 1] <= d) {
				a[i][i - 1] = x[i] - x[i - 1];
				a[i - 1][i] = x[i] - x[i - 1];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					if (i == k || j == k || i == j)
						continue;
					if (a[i][k] + a[k][j] < a[i][j])
						a[i][j] = a[i][k] + a[k][j];
				}
			}
		}
		int sum = 0;
		for (int u = 1; u <= n / 2; u++) {
			for (int v = n / 2; v <= n; v++) {
				if (u == v || a[u][v] == 0x3f3f3f3f || a[v][u] == 0x3f3f3f3f)
					continue;
				for (int i = 1; i <= n / 2; i++) {
					if (v == i || u == i || a[v][i] == 0x3f3f3f3f || a[u][i] == 0x3f3f3f3f)
						continue;
					for (int j = n / 2; j <= n; j++) {
						if (v == j || u == j || i == j || a[v][j] == 0x3f3f3f3f || a[u][j] == 0x3f3f3f3f)
							continue;
						if (a[i][u] + a[i][v] == a[j][u] + a[j][v] && a[j][u] + a[j][v] == a[u][v]) {
							sum++;
						}

					}
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
//priority_queue
//Oct31==Dec25 有趣的密码
//检查RECE 检查数据量 检查耗时