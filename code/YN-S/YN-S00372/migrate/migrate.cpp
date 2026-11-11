#include <bits/stdc++.h>
using namespace std;
int x[2000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	int c, t;
	cin >> c >> t;
	int n, d;

	while (t) {

		cin >> n >> d;

		for (int j = 1; j <= n; j++) {

			cin >> x[j];
		}

		if (n % 2 == 0)
			cout << 1;
		else
			cout << 0;
		t--;
	}


	return 0;
}