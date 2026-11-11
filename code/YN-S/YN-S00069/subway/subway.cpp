#include <bits/stdc++.h>
using namespace std;
int c, m, d, v, n, w[10000005], a[10000005], k[10000005], t, q, r, x, y;

int main() {
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[m];
		cin >> k[i] >> a[i] >> t;
		cin >> x >> y;
		if (w[m] == k[i])
			q++;
	}
	cout << q << endl;
	return 0;
}