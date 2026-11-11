#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500010];

long long f[1510][1510], lin[1510][1510]; //f[i][j]表示从i到j的最短路
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n + m; i++) {
		for (int j = 1; j <= n + m; j++) {
			f[i][j] = lin[i][j] = 1e17;
		}
		f[i][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int t, a;
			cin >> t >> a;
			lin[i][t] = a;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				f[i][j] = min(f[i][j], lin[k][i] + lin[k][j]); //直接去的
			}
		}
	}
	for (int k = 1; k <= m; k++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]); //间接到的
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		int st, et;
		cin >> st >> et;
		cout << f[st][et] + w[st] + w[et] << "\n";
	}
	return 0;
}
//真的是最短路
