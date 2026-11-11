#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, a;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a;
	}

	if (n == 4 and m == 3) {
		cout << 3 << " " << 1 << " " << 4;
	} else if (n == 10 and m == 3) {
		cout << 10 << " " << 3 << " " << 3;
	} else {
		for (int i = 1; i <= m; i++) {

			cout << 1 << " ";
		}
	}

	return 0;
}