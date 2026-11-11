#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
long long c, n, m, d, q, k;
int a[100000], w[100000], t[100000], x, y;

int main() {
//	freopen("subway.in", "r", stdin);
//	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[j] >> t[j];
		}
	}
	while (q--) {
		cin >> x >> y;
		cout << " " << '\n';
	}
	return 0;
}