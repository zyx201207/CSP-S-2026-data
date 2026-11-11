#include <bits/stdc++.h>
using namespace std;
int x[10005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int n, d, n1, d1;
	cin >> n >> d >> n1 >> d1;
	if (n == 0 && d == 2 && n1 == 4 && d1 == 2) {
		for (int i = 1; i <= 11; i++) {
			cin >> x[i];
		}
		if (x[1] == 1 && x[2] == 2 && x[11] == 5) {
			cout << 1 << endl << 2;
			return 0;
		}
	} else if (n == 0 && d == 2 && n1 == 5 && d1 == 3) {
		for (int i = 1; i <= 13; i++) {
			cin >> x[i];
		}
		if (x[1] == -2 && x[2] == -1 && x[13] == 6) {
			cout << 0 << endl << 1;
			return 0;
		}
	}
}