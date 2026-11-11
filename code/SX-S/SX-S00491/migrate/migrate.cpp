#include <bits/stdc++.h>
#define ll long long
#define mp make_pair()
using namespace std;
long long x[1000002];

int main() {
	int c, t, i, j, k, n, d, ans, cnt;
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (c = 0; c < t; c++) {
		//cout << "t";
		ans = 0;
		cin >> n >> d;
		for (i = 0; i < n; i++) {
			cin >> x[i];
		}
		sort(x, x + n);
		for (i = 0; i + 3 < n; i++) {
			for (j = i + 3; j < n; j++) {
				cnt = 0;
				for (k = i + 1; k + 1 <= j; k++) {
					if (x[k] - x[i] <= d and x[j] - x[k] <= d) {
						cnt++;
					}
				}
				if (cnt == 2)
					ans++;
			}
		}

		cout << ans << endl;
	}
	return 0;
}