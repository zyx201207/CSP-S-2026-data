#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, jiao1, jiao2;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	string w, v, guo, xian, huan, qi, zhi;
	cin >> c >> n >> m >> d >> q;

	for (int i = 1; i <= m; i++) {

		w[i] = i;
		int x;
		cin >> x;
		v[i] = x;
	}

	for (int i = 1; i <= n; i++) {

		int x;
		cin >> x;
		guo[i] = x;

		for (int j = 1; j <= guo[i]; j ++) {

			int a, s;
			cin >> a >> s;
			xian[(i - 1)*guo[i] + j] = a;
			huan[(i - 1)*guo[i] + j] = s;
		}
	}

	for (int i = 1; i <= q; i++) {

		int x, y;
		cin >> x >> y;
		qi[i] = x;
		zhi[i] = y;
	}

	for (int i = 1; i <= xian.length() / n; i++) {

		for (int j = xian.length() / n + 1; j <= xian.length(); j++) {

			if (xian[i] == xian[j]) {
				jiao1 = xian[i];
				jiao2 = xian[j];
			}
		}
	}

	for (int i = 1; i <= q; i++) {

		int r;
		r = v[w[qi[i]]] + huan[qi[i]];

		if (qi[i] + 1 != zhi[i]) {
			r += huan[jiao1]  + huan[jiao2] + huan[zhi[i]] + v[w[zhi[i]]];
			cout << r << "\n";
		} else {
			r += huan[zhi[i]] + v[w[zhi[i]]];
			cout << r << "\n";
		}
	}

	return 0;
}
