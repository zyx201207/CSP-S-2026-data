#include <bits/stdc++.h>
using namespace std;
int c, t;
int a[200005];
int cnt;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cnt = 0;
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (d == 2) {
			for (int i = 1; i <= n; i++) {
				if (a[i] >= 4) {
					cnt++;
				}
			}
		}
		cout << cnt;
	}
	return 0;
}