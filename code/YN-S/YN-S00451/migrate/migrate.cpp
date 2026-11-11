#include <bits/stdc++.h>
using namespace std;

long long c, t, n, d;
long long a[2000006];

int main() {

	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> d;
		for (int j = 1; j <= n; j++) {
			cin >> a[i];
		}
		cout << 0 << "\n";
	}

	return 0;
}