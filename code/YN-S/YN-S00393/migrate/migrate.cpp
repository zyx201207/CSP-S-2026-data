#include <bits/stdc++.h>
using namespace std;
#define ll long long
int c, t, n, d;
const int maxn = 1e6 + 5;
int a[maxn];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;

	while (t--) {
		cin >> n >> d;

		for (int i = 1; i <= n; i++) {

			cin >> a[i];
		}

		int k = a[2] - a[1];


		if (n > k * d) {
			cout << n - d *k * 2 + 1 << "\n";
		} else {
			cout << 0 << "\n";
		}
	}

	return 0;
}


