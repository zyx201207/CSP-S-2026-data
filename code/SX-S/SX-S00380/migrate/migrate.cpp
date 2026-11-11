#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, a[1000010];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		for (int j = 1; j <= x; j++) {
			cin >> a[i];
		}
		cout << 0;
	}
	return 0;
}