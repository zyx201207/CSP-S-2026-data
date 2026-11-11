#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int  n;
	cin >> n;
	int t = 0;
	for (int i = 0; i <= n - 1; i++) {
		if (n + n - 1 == t) {
			t++;
			cout << t;
		}

	}

	return 0;
}