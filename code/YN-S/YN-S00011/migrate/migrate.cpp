//by.pcx
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, m, x;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			cin >> x;
		cout << m << "\n";
	}
	return 0;
}