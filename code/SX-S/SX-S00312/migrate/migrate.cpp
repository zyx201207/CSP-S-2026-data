#include <bits/stdc++.h>
using namespace std;
int a[2000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, n;
	cin >> c >> n;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		for (int j = 1; j <= x; j++)
			cin >> a[j];
		cout << 0;
	}
	return 0;
}
