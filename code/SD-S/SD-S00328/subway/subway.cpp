#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500 + 5;
int c, n, m, d, q;
long long w[MAXN];
long long g1[MAXN][MAXN];
int a[(int)5e5 + 5];
long long t[(int)5e5 + 5];
long long f[MAXN][MAXN];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[j] >> t[j];
		}
		for (int j = 1; j <= k; j++) {
			for (int h = 1; h <= k; h++) {
				if (a[j] == a[h]) g1[a[j]][a[h]] = 0;
				else {
					g1[a[j]][a[h]] = t[j] + t[h];
					g1[a[h]][a[j]] = t[j] + t[h];
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			f[i][j] = INT_MAX;
			if (i == j) f[i][j] = 0;
			if (g1[i][j]) f[i][j] = g1[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= m; k++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << w[l] + w[r] + f[l][r] << '\n';
	}
}
