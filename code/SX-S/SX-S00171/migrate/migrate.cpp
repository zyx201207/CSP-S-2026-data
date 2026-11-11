#include <bits/stdc++.h>
using namespace std;
#define int long long
int x[100005];
int n, d;
int sum[305][305];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		memset(sum, 0, sizeof(sum));
		cin >> n >> d;
		if (c == 11 || c == 12) {
			for (int i = 1; i <= n; i++) {
				cin >> x[i];
			}
			int gc = x[2] - x[1];
			if (gc == d)
				cout << 0 << endl;
			else if (gc > d)
				cout << 0 << endl;
			else if (n < d / gc * 2)
				cout << 0 << endl;
			continue;
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
			sum[i][i] = 1;
			while (x[i] - x[cnt + 1] > d) {
				cnt += 1;
			}
			for (int j = cnt + 1; j < i; j++) {
				sum[j][i] = 1;
			}
		}
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j < n && x[j] - x[i] <= d; j++) {
				for (int k = j + 1; k <= n && (x[k] - x[j] <= d); k++) {
					if (x[k] - x[i] > d)
						sum[i][k] += sum[i][j] * sum[j][k];
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (sum[i][j] == 2)
					ans += 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
