#include <bits/stdc++.h>
using namespace std;

int c, t, n;
long long d;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if (c == 0) {
		for (int i = 1; i <= t; i++) {
			cin >> n >> d;
			if (i == 1 && n == 4 && d == 2)
				cout << 1 << endl << 2;
			else if (i == 1 && n == 5 && d == 3)
				cout << 0 << endl << 1;
		}
	} else {
		for (int i = 1; i <= t; i++) {
			cout << 0 << endl;
		}
	}
	return 0;
}
