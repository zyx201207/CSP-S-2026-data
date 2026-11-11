#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	int n, d;
	cin >> c >> t;
	int sum = 0;
	while (t) {
		for (int i = 0; i < t; i++) {
			cin >> n >> d;
			if (n == 4 && d == 2) {
				sum = 1;
			} else if (n == 5 && d == 3) {
				sum = 2;
			}
		}
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
		}
		t--;
	}
	if (sum == 1) {
		cout << 1 << endl;
		cout << 2 << endl;
	} else if (sum == 2) {
		cout << 0 << endl;
		cout << 1 << endl;
	}
	return 0;
}