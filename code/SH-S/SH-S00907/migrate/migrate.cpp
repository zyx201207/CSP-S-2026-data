#include <bits/stdc++.h>
using namespace std;

int f[1005][1005];

int c,t,n,d;

int x[505];

bool flag[505][505];

int cnt[505][505];

int ans;

int main() {
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cnt[i][j] = 0;
				flag[i][j] = false;
				if (i == j) {
					continue;
				}
				f[i][j] = 1e9+5;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					continue;
				}
				if (abs(x[i] - x[j] > d)) break;
				f[i][j] = min(f[i][j],abs(x[i] - x[j]));
			}
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (f[i][k] + f[k][j] > d) {
						continue;
					}
					f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
				}
			}
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (f[i][k] + f[k][j] == f[i][j] && i != j) {
						if (f[i][k] + f[k][j] > d || f[i][j] == 1e9+5) {
							continue;
						}
						cnt[i][j]++;
						cnt[j][i]++;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (cnt[i][j] == 2) {
					ans++;
				}
				cout << cnt[i][j] << " ";
			}
			cout << endl;
		}
		cout << ans << endl;
	}
	return 0;
}
