#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int a[510][500010], w[500010], k[510], t[510][500010], y[100010], x[100010];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
			cin >> a[i][j] >> t[i][j];
	}
	int r = 0, jl1[510], jl2[510], js1, js2, js3;
	while (q--) {
		int sj[1000000];
		fill(sj, sj + 1000000, 0);
		r++;
		js1 = js2 = js3 = 0;
		fill(jl1, jl1 + n, 0);
		fill(jl2, jl2 + n, 0);
		cin >> x[r] >> y[r];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k[i]; j++) {
				if (a[i][j] == x[r]) {
					js1++;
					jl1[js1] = i;
				}
				if (a[i][j] == y[r]) {
					js2++;
					jl2[js2] = i;
				}
			}
		}
		for (int i = 1; i <= js1; i++) {
			for (int j = 1; j <= js2; j++) {
				if (jl1[i] == jl2[j]) {
					sj[js3] = w[x[r]] + t[jl1[i]][x[r]] + t[jl1[i]][y[r]] + w[y[r]];
					js3++;
				}
			}
		}
		int da = sj[0];
		for (int i = 1; i <= js3; i++) {
			if (sj[i] > da)
				da = sj[i];
		}
		cout << da << endl;
	}

	return 0;
}
