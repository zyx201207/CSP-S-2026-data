#include <bits/stdc++.h>
using namespace std;
int a[2000006];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int nar = a[2] - a[1];
		int x = d / nar; //一次吃几个
		int y = (n - 1) / x; //能完整吃几个
		int z = (n - 1) % x; //剩几个
		if (z == 0) {
			cout << "0" << endl;
		} else {
			cout << y + 1 << endl;
		}
	}
	return 0;
}