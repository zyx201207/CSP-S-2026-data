#include <bits/stdc++.h>
using namespace std;
long long const M = 1e3+10;
long long w[M], t[M], q, z, k[M], m;
long long a[M][M], v[M], b[M];

void check() {

}

void dfs(int kl) {
	if (kl == m) {
		check();
		return;
	}
	for (int i = 1; i <= m; i++) {
		if (v[i] == 0) {
			v[i] = 1;
			b[kl] = i;
			dfs(kl + 1);
			v[i] = 0;
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	long long c, n,  d, p;
	cin >> c >> n >> m >> d >> p;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i];
		}
	}
	while (p--) {
		cin >> q >> z;
		v[q] = 1;
		v[z] = 1;
		b[1] = q;
		b[m] = z;
		dfs(2);
	}
	return 0;
}