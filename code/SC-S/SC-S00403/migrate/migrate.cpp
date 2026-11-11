#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 2e6 + 7, MAXM = 3003;
int c, T;
int n, cnt[MAXN], dis[MAXM][MAXM];
LL ans = 0;
LL f[MAXM][MAXM];
LL pos[MAXN], d;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	if (c == 11 ||  c == 12) {
		while (T--) {
			cin >> n >> d; 
			for (int i = 1; i <= n; i++) cin >> pos[i];
			if (n <= 3) {
				cout << 0 << endl;
				continue;
			}
			LL len = pos[2] - pos[1]; 
			LL maxstep = d / len;
			if (maxstep <= 1) {
				cout << 0 << endl;
				continue;
			}
			cout << n + 1 -(maxstep *1ll * 2) << endl;
		}
		return 0;
	}
	while (T--) {
		cin >> n >> d;
		ans = 0;
		for (int i = 1; i <= n; i++) cin >> pos[i];
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++) {
				dis[i][j] = 1e9, f[i][j] = 0; 
				if (pos[j] - pos[i] <= d) {
					f[i][j] = 1, dis[i][j] = 1;
				}
			}
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) {
				for (int k = i; k <= j; k++) {
					if (dis[i][k] + dis[k][j] == dis[i][j]) {
						f[i][j] += f[i][k] * f[k][j];
					}else if (dis[i][k] + dis[k][j] < dis[i][j]) {
						dis[i][j] = dis[i][k] + dis[k][j];
						f[i][j] = f[i][k] * f[k][j];
					}
				}
				if (f[i][j] == 2) ans++;
			}
		cout << ans << endl;
	}
	return 0;
}