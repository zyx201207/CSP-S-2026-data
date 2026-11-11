#include <bits/stdc++.h>
using namespace std;
int c, t;
int n, d;
const int N = 2e6 + 10;
int x[N];
int cnt[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> d;
		for (int j = 1; j <= n; j++) {
			cin >> x[j];
			if (x[j] > 0) {
				cnt[i]++;
			}
		}

	}
	for (int i = 1; i <= t; i++) {
		if (cnt[i] % 2 != 0) {
			cout << cnt[i] / 2 << endl;
		} else {
			cout << cnt[i] / 2 - 1 << endl;
		}
	}



	return 0;
}
