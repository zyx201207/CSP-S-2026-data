#include <bits/stdc++.h>
using namespace std;
int x[2000005];

int main() {
	FILE *fin, fout;
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c, t, n, d;
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		int ans = 0;
		cin >> n >> d;
		int sum = 0;
		if (n % 2 == 0) {
			if (n > 4) {
				cout << (n - 3) * 2 << "\n";
			} else if (n == 4)
				cout << 1;
		} else
			cout << 0 << "\n";
	}
	return 0;
}