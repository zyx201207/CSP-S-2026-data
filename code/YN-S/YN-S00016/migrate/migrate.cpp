#include <bits/stdc++.h>
using namespace std;

int n, t, c, d, cnt;
long long x[2000005];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (x[j] - x[i] <= d)
					continue;
				else {
					if (x[j] - x[i] > d)
						cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}