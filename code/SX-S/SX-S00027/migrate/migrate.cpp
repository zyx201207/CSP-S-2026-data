#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	int a[100000];
	while (t--) {
		int n, d;
		cin >> n >> d;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				int ans = a[j] - a[i];
				if (ans - d <= d) {
					cnt++;
				}
			}
		}
		cout << cnt / n << endl;
	}
	return 0;
}
