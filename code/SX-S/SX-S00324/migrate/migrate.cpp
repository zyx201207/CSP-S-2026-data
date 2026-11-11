#include <bits/stdc++.h>
using namespace std;
int x[2000010];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for (;; t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		if (n % 2 == 0) {
			int s = d / 2;
			cout << s << endl;
		} else {
			int s = d;
			cout << s << endl;
		}
	}
	return 0;
}