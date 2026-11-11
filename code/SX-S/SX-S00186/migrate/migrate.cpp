#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {

		int n, d;
		cin >> n >> d;
		int a[n + 3];
		for (int j = 1; j <= n; j++) {
			cin >> a[j];
		}
		int g = abs(a[2] - a[1]);
		if (n < 3 || d <= g) {


			cout << 0 << endl;
			continue;
		}

		//	if (c >= 11 && c <= 12) {
		//	if(a[2]-a[1]==1){
		cout << n - 2 * (d / g) + 1 << endl;
		//	}


		//	}

	}


	return 0;
}
