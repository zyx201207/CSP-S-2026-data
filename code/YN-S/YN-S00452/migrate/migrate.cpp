#include <bits/stdc++.h>
using namespace std;
long long a[200005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long c, t;
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		int n, d;
		cin >> n >> d;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (d == 1 || d >= 3) {
			cout << 0 << "\n";
		} else {
			sort(a + 1, a + 1 + n);
			cnt = 0;
			bool f = 0, t = 0, b = 0;
			for (int j = 1; j <= n; j++) {
				f = 0;
				t = 0;
				b = 0;
				int atwo = a[j] + 2, aone = a[j] + 1, athree = a[j] + 3;
				for (int k = j ; k <= n; k++) {
					if (a[k] == atwo) {
						f = 1;
					}
					if (a[k] == aone) {
						t = 1;
					}

					if (a[k] == athree) {
						b = 1;
					}
					if (a[k] > athree) {
						break;
					}
				}
				if (f == 1 && t == 1 && b == 1) {
					cnt++;

				}
			}
			cout << cnt << "\n";
		}

	}
	return 0;
}