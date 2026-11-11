#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q;
long long w[500005], a[500005][500005], t[500005][500050];
long long x, y, k[500050], f = 0, s = 0;

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		scanf("%lld", &w[i]);
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		f += k[i];
		for (int j = 1; j <= k[i]; j++) {
			scanf("%lld%lld", &a[i][j], &t[i][j]);
		}
	}

	for (int i = 1; i <= q; i++) {
		cin >> x >> y;
		s += w[x];
		for (int o = 1; o <= f; o++) {
			for (int j = 1; j <= n; j++) {
				for (int p = 1; p <= k[j]; p++) {
					if (a[i][j] == x) {
						f += t[i][j];
						x++;
					}
				}
			}
		}
		s += w[y];
		cout << s << endl;
	}
	return 0;
}
