#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int m, n, k, q, t, cnt = 0;
	cin >> m >> n >> k >> q >> t;
	for (int v = 1; v <= m; v++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++ ) {
				for (int r = 1; r <= q; r++) {
					cnt++;
				}
			}
		}
	}
	q = cnt++;
	cout << q << endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}