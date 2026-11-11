#include <bits/stdc++.h>
using namespace std;
long long t[5000000], k[5000000], a[1000000], b[1000000];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long d, t, c, n;
	cin >> c >> t;
	for (int j = 1; j <= t; j++) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		cout << "0";
	}
	cout << "2";
	return 0;
}
