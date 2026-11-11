// SN-S00351 杨益烜 西安交通大学附属中学 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1000;
const int inf = 1e7;

int c, t, n;
ll d, a[N], b[N][N], cnt[N][N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		scanf("%d%lld", &n, &d);
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if (abs(a[j] - a[i]) <= d) {
					b[i][j] = b[j][i] = 1;
					cnt[i][j] = cnt[j][i] = 1;
				} else {
					b[i][j] = b[j][i] = inf;
					cnt[i][j] = cnt[j][i] = 0;
				}
			}
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if ((b[i][k] + b[k][j]) == b[i][j]) {
						cnt[i][j]++;
					} else if ((b[i][k] + b[k][j]) < b[i][j]) {
						cnt[i][j] = 1;
						b[i][j] = b[i][k] + b[k][j];
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if (cnt[i][j] == 2) {
					ans++;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
