#include <bits/stdc++.h>
using namespace std;
int d[1000000];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long a, s;
	cin >> a >> s;
	for (int i = 1; i <= a; i++) {
		cin >> d[i];
	}
	long  long f = 0;
	for (int i = 2; i < a; i++) {
		if (d[i] - d[i - 1] == d[i + 1] - d[i]) {
			f++;
		}
	}
	if (f == a - 2) {
		cout << 1;
	} else {
		if (a % 2 == 0) {
			cout << ((a / 2 - 1)*a / 2) / 2;
		} else {
			cout << ((a / 2) * (a / 2)) / 2;
		}
	}
	return 0;
}

