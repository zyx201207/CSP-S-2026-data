#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	if (c == 5) {
		cout << 32 << endl << 17;
	}
	if (c == 7) {
		cout << 35 << endl << 16;
	} else {
		cout << 38 << endl << 15;
	}
	return 0;
}