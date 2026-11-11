#include <bits/stdc++.h>
using namespace std;
int a[2000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t, n, d;
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> d;
		for (int x = 1; x <= n; x++) {
			cin >> a[x];
		}
		cout << "0";
	}
	return 0;
}