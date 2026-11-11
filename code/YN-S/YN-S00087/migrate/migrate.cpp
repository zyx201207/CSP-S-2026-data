#include <bits/stdc++.h>
using namespace std;
int a[20000005];
int b, c;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> b >> c;
	int x = c;
	while (x != 0) {
		int m, n = 0;

		cin >> m >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (n == 0) {
			cout << "0";
		}
		if (n == 2) {
			cout << m / n;
		}
		x--;
	}
}
