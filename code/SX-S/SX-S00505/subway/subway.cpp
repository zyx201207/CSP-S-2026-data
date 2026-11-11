#include <bits/stdc++.h>
using namespace std;
long long w[1005];
long long k[1005];
long long a[1005][1005], t[1005][1005];
long long x[1005], y[1005];
long long s[100011][100011];
long long c, n, m, d, q;

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= 10010; i++) {
		for (int j = 1; j <= 10010; j++) {
			if (i != j) {
				s[i][j] = 1e9;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k[i]; j++) {
			for (int l = 1; l <= k[i]; l++) {
				if (j != l) {
					s[a[i][j]][a[i][l]] = min(t[i][j] + t[i][l], s[a[i][j]][a[i][l]]);
				}
			}
		}
	}

	for (int l = 1; l <= m; l++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				if (i != j) {
					s[i][j] = min(s[i][j], s[i][l] + s[l][j]);
				}
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= q; i++) {
		cout << w[x[i]] + s[x[i]][y[i]] +  w[y[i]] << endl;
	}
	return 0;
}
