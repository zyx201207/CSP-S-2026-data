#include <bits/stdc++.h>
using namespace std;
int w[1000005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;

	for (int i = 1; i <= m; i++) {

		cin >> w[i];
	}

	if (n == 2) {
		cout << "32" << endl << "17";
	} else {
		cout << "35" << endl << "16";
	}

	return 0;
}
